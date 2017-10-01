% import global variables    
clear;
settings_2;

nyquist_rate = 10*2*f2;
f_sample = 100000;
dt = 1/f_sample;
t = [-5000:4999]*dt; % an array with 2^M points, but starting at M=-4096
n_ft = length(t);
t_rec = n_ft*dt; % total measurement time
f_res = 1/t_rec; % the resolution is 1/(measurement time)
df = f_res; %...which is also the frequency resolution

f = [-n_ft/2: n_ft/2-1]*df;  % centered version

figure;

fft_d = fft(d(t))*dt;
fft_d = fftshift(fft_d);

subplot(211);
plot(f, abs(fft_d), 'r-', 'linewidth', 2);
xlim([-200 200]);
title(['Frequency resolution: ', num2str(f_res), ' Hz'],...
    'fontsize', 16)
ylabel('Magnitude of D(f)');

subplot(212);
ph_adj = exp(2j*pi*min(t)*f).*fft_d; % adjust for first sample not at t=0
plot(f, angle(ph_adj)/pi, 'b-', 'linewidth', 2);
xlim([-200 200]);
ylabel('Phase of D(f)');

xlabel('Frequency (Hz)');
