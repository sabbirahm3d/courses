settings_2;
% Nyquist rate is 300, sample rate is 3000
dt = 1/(10*300);
t0 = -0.05:dt:0.05;

figure;
plot(t0, d(t0), 'r-')
title(...
    '$$d(t)=A(1 + a_{1}cos(2\pi f_{1}t+\phi_{1}) + a_{2}cos(2\pi f_{2}t+\phi_{2}))$$',...
    'interpreter', 'latex', 'fontsize', 16);
ylabel('Amplitude');
xlabel('Time (s)');
