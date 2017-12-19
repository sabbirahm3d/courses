function dtftify(x, x_n, x2, x2_n, title1, title2, title3)

    dt = 0.001;
    t = -4.096: dt : 4.096;
    n = -4.096: 0.05 : 4.096;
    f = -10:0.1:10;

    dtft = @(x, t, f) (dt*exp(-1j * (f'-5) * t)*x');

    figure;
    subplot(3,1,1);
    stem(n, x2_n);
    hold on;
    plot(t, x2);
    title(title1, 'Interpreter', 'latex', 'FontSize', 12);
    xlabel('Time');
    ylabel('Amplitude');
    hold off;
    ylim([0 1.25]);

    subplot(3,1,2);
    plot(f, abs(dtft(x_n, n, f)));
    title(title2, 'Interpreter', 'latex', 'FontSize', 12);
    xlabel('Frequency');
    ylabel('Magnitude');

    subplot(3,1,3);
    plot(f, angle(dtft(x_n, n, f)));
    title(title3, 'Interpreter', 'latex', 'FontSize', 12);
    xlabel('Frequency');
    ylabel('Phase');


end