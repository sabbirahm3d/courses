dt = 0.01;
t = -5:dt:5;
t2 = -10:dt:10;

u = @(t) (t > 0);
p = @(t, T) (u(t) - u(t-T));

b3 = @(t) (p(t, 1) + p(t-1, 1) - p(t-2, 1));

figure;
plot(t, b3(t), 'LineWidth', 2);
title('$$b_{3}(t)=p(t, 1) + p(t-1, 1) - p(t-2, 1)$$', 'Interpreter', 'latex', 'FontSize', 14);
ylabel('Units');
xlabel('Time (s)');

figure;
r = dt*conv(b3(t), b3(-t));
plot(t2, r, 'LineWidth', 2);
title('$$r_{b_{3}b_{3}}(\tau)=\int_{-\infty}^{\infty}b_{3}(\tau)b_{3}(t+\tau)d\tau$$',...
    'Interpreter', 'latex', 'FontSize', 14);
ylabel('Units');
xlabel('Time (s)');
