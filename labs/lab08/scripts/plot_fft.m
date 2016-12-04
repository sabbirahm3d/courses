function plot_fft(func_array, theory, func_str, theory_str)

    dt = 1/1000;
    t=[-4096:4095]*dt; % an array with 2^M points, but starting at M=-4096
    NFFT = length(t);
    trecord = NFFT*dt;
    fresolution = 1/trecord; % the resolution is 1/(measurement time)
    df = fresolution; %...which is also the frequency resolution
    funshifted=[0:NFFT-1]*df; % FFTs go from 0 to (N-1)df
    f = [-NFFT/2: NFFT/2-1]*df;  % centered version
    tau = 1;

    P1 = fft(func_array)*dt; % multiply by dt to scale to be an integral

    figure;
    subplot(3,1,1);
    plot(funshifted, abs(P1), f, abs(theory), 'r:','LineWidth',2);
    ylabel('Magnitude');
    xlim([0 1000]);
    legend_str = legend(['$$abs(fft(', func_str, '(t)))$$'], theory_str);
    set(legend_str, 'Interpreter', 'latex', 'FontSize', 12)
    grid on;

    subplot(3,1,2);
    P1 = fftshift(P1); % use fftshift to reorder
    plot(f,abs(P1),f,abs(theory),'r:','LineWidth',2); % use the shifted version
    ylabel('Magnitude');
    xlim([-10 10]);
    legend_str = legend(['$$abs(fft(', func_str, '(t)))$$'], theory_str);
    set(legend_str, 'Interpreter', 'latex', 'FontSize', 12)
    grid on;

    subplot(3,1,3);
    % remove erroneous phase shift due to first sample not at t=0
    P1adj = exp(1j*2*pi*min(t)*f).*P1;

    plot(f,angle(P1adj)/pi, f, angle(theory)/pi, 'r:', 'LineWidth', 2);
    ylabel('Phase');
    xlabel('Frequency in Hz');
    legend_str = legend(['$$angle(fft(', func_str, '(t)))$$'], theory_str);
    set(legend_str, 'Interpreter', 'latex', 'FontSize', 12)
    xlim([-10, 10]);
    grid on;

end