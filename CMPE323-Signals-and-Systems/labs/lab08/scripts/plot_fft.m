function plot_fft(func_array, theory, func_str, theory_str)

    % import global variables    
    settings;

    fft_func = fft(func_array)*dt; % multiply by dt to scale to be an integral

    figure;
    subplot(3,1,1);
    plot(funshifted, abs(fft_func), f, abs(theory), 'r:','LineWidth',2);
    ylabel('Magnitude');
    xlim([0 1000]);
    legend_str = legend(['$$abs(FFT(', func_str, '(t)))$$'], theory_str);
    set(legend_str, 'Interpreter', 'latex', 'FontSize', 12)
    grid on;

    subplot(3,1,2);
    fft_func = fftshift(fft_func); % use fftshift to reorder
    plot(f,abs(fft_func),f,abs(theory),'r:','LineWidth',2); % use the shifted version
    ylabel('Magnitude');
    xlim([-10 10]);
    legend_str = legend(['$$abs(FFT(', func_str, '(t)))$$'], theory_str);
    set(legend_str, 'Interpreter', 'latex', 'FontSize', 12)
    grid on;

    subplot(3,1,3);
    % remove erroneous phase shift due to first sample not at t=0
    P1adj = exp(1j*2*pi*min(t)*f).*fft_func;

    plot(f,angle(P1adj)/pi, f, angle(theory)/pi, 'r:', 'LineWidth', 2);
    ylabel('Phase');
    legend_str = legend(['$$angle(FFT(', func_str, '(t)))$$'], theory_str);
    set(legend_str, 'Interpreter', 'latex', 'FontSize', 12)
    xlim([-10, 10]);
    grid on;
    xlabel('Frequency (Hz)');

end