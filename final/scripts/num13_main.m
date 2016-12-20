figure;

% plot a unit circle to envelope the poles
th = 0:pi/50:2*pi;
xunit = cos(th);
yunit = sin(th);
h1 = plot(xunit, yunit);
hold on;
h2 = plot(s, 'rx', 'linewidth', 2);

xlim([-1.5 1.5]);
ylim([-1.5 1.5]);
title('Pole-Zero Plot of H(s)')
ylabel('$$\frac{im(s)}{\omega_c}$$', 'interpreter', 'latex');
xlabel('$$\frac{re(s)}{\omega_c}$$', 'interpreter', 'latex');
legend(h2, {'Poles'});

b = [1 (2.6193+1.903i) (1.602+4.985i) -(1.620-4.987i) -(2.623-1.906) - 1.002];
a = [0 0 0 0 0 w_cn];

% http://stackoverflow.com/questions/28978671/matlab-quickie-how-to-plot-markers-on-a-freqs-plot

w = logspace(-3,5); % Frequency vector

%// New code
h = freqs(b,a,w); %// Output of freqs
mag = 20*log10(abs(h)); %// Magnitude in dB
pha = (180/pi)*angle(h); %// Phase in degrees

% %// Declare points
% wpt = [600, 7500];
% mpt = [20, -71];

%// Plot the magnitude as well as markers
figure;
subplot(2,1,1);
semilogx(w, -mag, 'linewidth', 2);
ylim([-20 0])
xlabel('Frequency');
ylabel('Magnitude (dB)');
grid;

%// Plot phase
subplot(2,1,2);
semilogx(w, pha, 'color', [0 0.6 0], 'linewidth', 2);
xlabel('Frequency');
ylabel('Phase (Degrees)');
grid;