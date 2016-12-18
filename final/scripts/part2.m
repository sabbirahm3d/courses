% import global variables    
settings_2;

% plot_fft(d(t3), theory_d(f), 'p_{1}', '$$\tau sinc(f\tau)$$');
% plot_fft(c(t3).*d(t), theory_d(f), 'p_{1}', '$$\tau sinc(f\tau)$$');

figure;
plot(t0, d(t0), 'r-')
title(...
    '$$d(t)=A(1 + a_{1}cos(2\pi f_{1}t+\phi_{1}) + a_{2}cos(2\pi f_{2}t+\phi_{2}))$$',...
    'interpreter', 'latex', 'fontsize', 16);
ylabel('Amplitude');
xlabel('Time (s)');

figure;

fft_d = fft(c(t3).*d(t3))*dt;
fft_d = fftshift(fft_d);

subplot(211);
plot(f, abs(fft_d));
xlim([-5 5])

subplot(212);
plot(f, angle(fft_d));
xlim([-5 5])
