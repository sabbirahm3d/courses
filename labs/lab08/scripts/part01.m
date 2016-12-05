settings;

% FFT
plot_fft(p1(t), theory_p1(f), 'p_{1}', '$$\tau sinc(f\tau)$$');
plot_fft(p2(t), theory_p2(f), 'p_{2}', '$$e^{-j\pi f\tau} \tau sinc(f\tau)$$');
plot_fft(p3(t), theory_p3(f), 'p_{3}', '$$e^{j\pi f\tau} \tau sinc(f\tau)$$');

% FFT with Complex Modulation
plot_fft(c(t).*p1(t), theory_x1(f), 'x_{1}', '$$\tau sinc((f-f_{c})\tau)$$');
plot_fft(c(t).*p2(t), theory_x2(f), 'x_{2}', '$$e^{-j\pi (f-f_c)\tau} \tau sinc((f-f_{c})\tau)$$');
plot_fft(c(t).*p3(t), theory_x3(f), 'x_{3}', '$$e^{j\pi (f-f_c)\tau} \tau sinc((f-f_{c})\tau)$$');

% FFT with Cosine Modulation
plot_fft(m(t).*p1(t), theory_w1(f), 'w_{1}',...
    '$$\frac{1}{2}\tau (sinc((f-f_{c})\tau) + sinc((f+f_{c})\tau))$$');

plot_fft(m(t).*p2(t), theory_w2(f), 'w_{2}',...
    '$$\frac{1}{2}\tau e^{-j\pi (f-f_c)\tau} (sinc((f-f_{c})\tau) + sinc((f+f_{c})\tau))$$');

plot_fft(m(t).*p3(t), theory_w3(f), 'w_{3}',...
    '$$\frac{1}{2}\tau e^{j\pi (f-f_c)\tau} (sinc((f-f_{c})\tau) + sinc((f+f_{c})\tau))$$');
