% import global variables    
clear;
settings_2;

nyquist_rate = 10*2*f2;
f_sample = 5*f_c;
dt = 1/f_sample;
t = [-25000:24999]*dt; % an array with 2^M points, but starting at M=-4096
n_ft = length(t);
t_rec = n_ft*dt; % total measurement time
f_res = 1/t_rec; % the resolution is 1/(measurement time)
df = f_res; %...which is also the frequency resolution

f = [-n_ft/2: n_ft/2-1]*df;  % centered version

figure;

fft_d = fft(x(t))*dt;
fft_d = fftshift(fft_d);

subplot(2,2,[1,2]);
plot(t, x(t));
ylabel('$$x(t) = d(t)cos(2\pi f_{c}t)$$', 'interpreter', 'latex', ...
    'fontsize', 16);
xlabel('Time (s)');

subplot(223);
plot(f, abs(fft_d), 'r-', 'linewidth', 2);
xlim([-102e3 -98e3]);
ylabel('Magnitude of X(f)');
xlabel('Frequency (Hz)');

subplot(224);
plot(f, abs(fft_d), 'r-', 'linewidth', 2);
xlim([98e3 102e3]);
ylabel('Magnitude of X(f)');
xlabel('Frequency (Hz)');


figure;

fft_d = fft(x(t))*dt;
fft_d = fftshift(fft_d);

subplot(2,2,[1,2]);
plot(t, x(t));
ylabel('$$x(t) = d(t)cos(2\pi f_{c}t)$$', 'interpreter', 'latex', ...
    'fontsize', 16);
xlabel('Time (s)');

subplot(223);
plot(f, angle(fft_d), 'r-', 'linewidth', 2);
xlim([-102e3 -98e3]);
ylabel('Phase of X(f)');
xlabel('Frequency (Hz)');

subplot(224);
plot(f, angle(fft_d), 'r-', 'linewidth', 2);
xlim([98e3 102e3]);
ylabel('Phase of X(f)');
xlabel('Frequency (Hz)');
