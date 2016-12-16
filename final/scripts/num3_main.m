dt = 0.001;
t = -5:0.001:5;
t2 = -10:0.001:10;
tau = 1;

tau1 = 1;
tau2 = 2;
tau3 = 3;

u = @(t) (t >= 0);
p = @(t, tau) (u(t) - u(t-tau));
a = @(t, tau) (1/tau*(u(t+tau/2) - u(t-tau/2)));

x_tick_str = cell(1, 2*tau3 + 1);
y_tick_str = cell(1, 6);

y_tick_str{1} = 0;
y_tick_str{3} = '1/\tau_1';

% y1(t)
figure;
subplot(211);
plot(t, a(t + tau3/2, tau1), 'LineWidth', 2);

xlim([-tau3 tau3]);
ylim([0 3*tau1/4+1]);
ylabel('$$a(t+\frac{\tau_{3}}{2}; \tau_{1})$$', ...
    'Interpreter', 'latex', 'FontSize', 16);

x_tick_str{2} = '-\tau_1/2-\tau_3/2';
x_tick_str{3} = '\tau_1/2-\tau_3/2';

set(gca, 'xTickLabel', x_tick_str, 'yTickLabel', y_tick_str);

subplot(212);
y1 = dt*conv(a(t + tau3/2, tau1), heaviside(t));
plot(t2, y1, 'LineWidth', 2);
xlim([-tau3 tau3]);
ylim([0 3*tau1/4+1]);
y_tick_str{3} = '1';
set(gca, 'xTickLabel', x_tick_str, 'yTickLabel', y_tick_str);

ylabel('$$conv(a(t+\frac{\tau_{3}}{2}; \tau_{1}), u(t)))$$', ...
    'Interpreter', 'latex', 'FontSize', 16);
xlabel('Time (s)');

% y2(t)
figure;
subplot(211);
plot(t, a(t - tau3/2, tau2), 'LineWidth', 2);

x_tick_str = cell(1, 11);

x_tick_str{6} = '-\tau_2/2+\tau_3/2';
x_tick_str{10} = '\tau_2/2+\tau_3/2';

y_tick_str{2} = '1/\tau_1';
y_tick_str{3} = '';

xlim([-tau3+1 tau3]);
ylim([0 1.5]);
ylabel('$$a(t+\frac{\tau_{3}}{2}; \tau_{2})$$', ...
    'Interpreter', 'latex', 'FontSize', 16);

set(gca, 'xTickLabel', x_tick_str, 'yTickLabel', y_tick_str);

subplot(212);
y2 = dt*conv(a(t - tau3/2, tau2), heaviside(t));
plot(t2, y2, 'LineWidth', 2);
xlim([-tau3+1 tau3]);
ylim([0 1.5]);

y_tick_str{2} = '';
y_tick_str{3} = '1';

set(gca, 'xTickLabel', x_tick_str, 'yTickLabel', y_tick_str);

ylabel('$$conv(a(t+\frac{\tau_{3}}{2}; \tau_{2}), u(t)))$$', ...
    'Interpreter', 'latex', 'FontSize', 16);
xlabel('Time (s)');

