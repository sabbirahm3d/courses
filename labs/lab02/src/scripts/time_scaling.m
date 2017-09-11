% typo: e^(j*omega*t-/+theta) -> e^(j*(omega-/+theta))

omega = 10;
a = 0.1;
omega_N = omega*a;
t = -10:(1/10):10;

figure;
subplot(211);
exp_func = exp(1j*omega*a*t);
plot(t, exp_func, '-r');
str = '$$\mathrm{e}^{j\omega at}$$';
title(str, 'Interpreter', 'latex', 'FontSize', 20);
ylabel('Units');
legend('Time scale expansion')

subplot(212);
exp_func = exp(1j*omega_N*t);
plot(t, exp_func, '-b');
str = '$$\mathrm{e}^{j\omega_N t}$$';
new_freq = 'New frequency $$\omega_N = a\omega$$';
title(str, 'Interpreter', 'latex', 'FontSize', 20);
ylabel('Units');
plot_legend = legend(new_freq);
set(plot_legend, 'Interpreter', 'latex');
xlabel('Time (s)');

