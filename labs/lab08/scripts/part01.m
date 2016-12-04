plot_fft(p1(t), theory_p1(f), 'p_{1}', '$$\tau sinc(f\tau)$$');
% plot_fft(p2(t), theory_p2(f), 'p_{2}', '$$e^{-j\pi f\tau} \tau sinc(f\tau)$$');
% plot_fft(p3(t), theory_p3(f), 'p_{3}', '$$e^{j\pi f\tau} \tau sinc(f\tau)$$');

plot_fft(c(t).*p1(t), theory_p1(f), 'x_{1}', '$$\tau sinc(f\tau)$$');
