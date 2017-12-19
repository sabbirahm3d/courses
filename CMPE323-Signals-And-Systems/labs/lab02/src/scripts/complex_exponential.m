% typo: e^(j*omega*t-/+theta) -> e^(j*(omega-/+theta))

omega = 100;
t = -10:(1/2):10;

figure;
exp_func = exp(1j*omega*t);
plot(t, exp_func, '-r');
str = '$$\mathrm{e}^{j\omega t}$$';
title(str, 'Interpreter', 'latex', 'FontSize', 20)

figure;
subplot(211);
exp_func = exp(1j*omega*t+2*pi);
plot(t, exp_func, '-r');
str = '$$\mathrm{e}^{j\omega t + 2\pi}$$';
title(str, 'Interpreter', 'latex', 'FontSize', 20);
ylabel('Units');
legend('Phase shift')

subplot(212);
exp_func = exp(1j*omega*(t+(2*pi)/(1j*omega)));
plot(t, exp_func, '-b');
str = '$$\mathrm{e}^{j\omega (t + \frac{2\pi}{j\omega})}$$';
title(str, 'Interpreter', 'latex', 'FontSize', 20);
ylabel('Units');
legend('Time delay')
xlabel('Time (s)');

