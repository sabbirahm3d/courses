figure;
subplot(211);
fft_w1 = fft(a(t + tau3/2 - beta, tau1));
fft_w1 = fftshift(fft_w1);

fft_w2 = fft(heaviside(t));
fft_w2 = fftshift(fft_w2);

fft_w3 = fft(a(t - tau3/2 - beta, tau2));
fft_w3 = fftshift(fft_w3);

plot(t, dt*abs(fft_w1.*fft_w2 - fft_w3.*fft_w2));
xlim([-0.1 0.1])

fft_w0 = fft(w(t, tau1, tau2, tau3));
fft_w0 = fftshift(fft_w0);

subplot(212)
plot(t2, abs(fft_w0));
xlim([-0.1 0.1])


