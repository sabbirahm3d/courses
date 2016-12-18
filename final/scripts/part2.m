% import global variables    
clear;
settings_2;

nyquist_rate = 10*2*f2;
fsa = 100000;
dt = 1/fsa;
t3 = [-5000:4999]*dt; % an array with 2^M points, but starting at M=-4096
NFFT = length(t3)
trecord = NFFT*dt; % total measurement time
fresolution = 1/trecord % the resolution is 1/(measurement time)
df = fresolution; %...which is also the frequency resolution

funshifted= [0:NFFT-1]*df; % FFTs go from 0 to (N-1)df
f = [-NFFT/2: NFFT/2-1]*df;  % centered version

figure;
plot(t3, d(t3));
xlim([-0.1 0.1])
figure;

fft_d = fft(c(t3).*d(t3))*dt;
fft_d = fftshift(fft_d);

subplot(211);
plot(f, abs(fft_d), 'r-', 'linewidth', 2);
xlim([-200 200]);
title(['Frequency resolution: ', num2str(fresolution), ' Hz'],...
    'fontsize', 16)
ylabel('Magnitude of D(f)');

subplot(212);
ph_adj = exp(2j*pi*min(t3)*f).*fft_d; % adjust for first sample not at t=0
plot(f, angle(ph_adj)/pi, 'b-', 'linewidth', 2);
xlim([-200 200]);
ylabel('Phase of D(f)');

xlabel('Frequency (Hz)');
