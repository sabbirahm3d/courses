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
legend([h2], {'Poles'});

% w = logspace(-1,2);
% figure;
% freqs(b,a,w);
