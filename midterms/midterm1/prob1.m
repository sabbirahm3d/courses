t = -5:0.01:5;

u = @(t) (t > 0);  % unit step
d = @(t) (dirac(t));  % unit impulse (dirac)
d1 = @(t) (~t);  % unit impulse (modified)

x = @(t) (u(t+2)-2*u(t)+u(t-1));  % 1.1
z = @(t) (x(2*t-1));  % 1.2
dx = @(t) (d1(t+2)-2*d1(t)+d1(t-1));  % 1.3
y = @(t) (t.*(u(t+1)-u(t-2)));  % 1.4

dy = @(t) (t.*(d(t+1)-d(t-2))-u(t-2)+u(t+1));  % 1.5
w = @(t) ((t+2).*u(t+2)-2*t.*u(t)+(t-1).*u(t-1));  % 1.6
r = @(t, a) (exp(-a.*t).*u(t+2));  % 1.7
s = @(t, a) (r(2-t, a));  % 1.8

figure;

% 1.1
subplot(411);
plot(t, x(t), 'LineWidth', 2);
title('$$x(t)=u(t+2)-2u(t)+u(t-1)$$', 'Interpreter', 'latex', 'FontSize', 14);

% 1.2
subplot(412);
plot(t, z(t), 'LineWidth', 2);
title('$$z(t)=x(2t-1)$$', 'Interpreter', 'latex', 'FontSize', 14);

% 1.3
subplot(413);
plot(t, dx(t), 'LineWidth', 2);
title('$$\frac{dx}{dt}$$', 'Interpreter', 'latex', 'FontSize', 14);

% 1.4
subplot(414);
plot(t, y(t), 'LineWidth', 2);
title('$$y(t)=t(u(t+1)-u(t-2))$$', 'Interpreter', 'latex', 'FontSize', 14);

xlabel('Time (s)');

figure;

% 1.5
subplot(411);
plot(t, dy(t), 'LineWidth', 2);
title('$$\frac{dy}{dt}$$', 'Interpreter', 'latex', 'FontSize', 14);

% 1.6
subplot(412);
plot(t, w(t), 'LineWidth', 2);
title('$$w(t)=\int_{-\infty}^{t} x(\tau)d\tau$$', 'Interpreter', 'latex', 'FontSize', 14);

% 1.7
subplot(413);
plot(t, r(t, 2), 'LineWidth', 2);
title('$$r(t)=\mathrm{e}^{-\alpha t}u(t+2)$$', 'Interpreter', 'latex', 'FontSize', 14);

% 1.8
subplot(414);
plot(t, s(t, 2), 'LineWidth', 2);
title('$$s(t)=r(2-t)$$', 'Interpreter', 'latex', 'FontSize', 14);

xlabel('Time (s)');
