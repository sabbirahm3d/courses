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

    x = @(t, f) (exp(2j*pi*f*t).*u(t));
    
    figure;
    for index = 1 : numel(f) / 2

        subplot(['41' num2str(index)]);
        y = dt*abs(conv(x(t, f(index)), h));

        transient = t(h ~= 0);

        plot(t2, y);
        title(['Frequency: ' num2str(f(index))])
        if xlimit
            xlim([transient(end) 10])
            ylim([0 0.25])
        end
    end

    figure;
    for index = numel(f) / 2 + 1 : numel(f)
        subplot(['41' num2str(index - 4)]);
        y = dt*abs(conv(x(t, freq(index)), h));

        transient = t(h ~= 0);

        plot(t2, y);
        title(['Frequency: ' num2str(f(index))])
        if xlimit
            xlim([transient(end) 10])
            ylim([0 0.25])
        end
    end
        
end
