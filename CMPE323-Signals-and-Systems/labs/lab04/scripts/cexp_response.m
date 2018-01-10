function response = cexp_response(h,t,f,ifploton)
    % function response = cexp_response(h,t,f,ifploton)
    %  This function plots the response of an LTI system described by impulse
    % response h sampled at the times in t, at the frequencies given in f.
    %
    % Calling parameters
    %  (1 x N) array of impulse response.
    %  (1 x N) array of sample times in seconds
    %  (1 x M) array of evaluation frequencies in Hz
    %  Note M is not necessarily equal to N
    %  ifploton = 1 for plots, 0 otherwise
    %    ifploton = 1 will plot the magnitude and phase of the response at the
    %    response frequencies (in Hz)
    %
    % Returned parameters
    %  response (1 x M) array of complex outputs representing the steady state output at each 
    %   of the M frequencies.

    % existing conditions for the convolution response
    dt = 1/1000;  % for scaling the responses
    u = @(t) (t >= 0);  % unit step
    x = @(t, f) (exp(2j*pi*f*t).*u(t));  % exponential input
    
    response = zeros(1, length(f));  % (1 x M) array of output responses
    
    % iterate through the array of frequencies
    for index = 1 : numel(f)

        y = conv(x(t, f(index)), h);

        mag = dt*abs(y);  % magnitude of convolution

        % strip out all the zero values leaving only the transient and
        % steady state
        steady_state = mag(mag > 0);

        r = mode(steady_state);  % real value of steady state
        index_steady = find(mag == r, 1);  % index of steady state value

        phase = dt*angle(y);  % phase angle of convolution
        theta = phase(index_steady);  % phase angle of steady state

        % complex response of steady state
        response(index) = r.*exp(1j*theta);

    end

    if ifploton
        figure;

        subplot(211);
        plot(f, abs(response), '-r');
        title('Magnitude of responses');

        subplot(212);
        plot(f, angle(response));
        title('Phase angle of responses');
        
        xlabel('Frequency (Hz)');
    end
    
end
