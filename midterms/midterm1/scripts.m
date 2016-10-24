t = -5:0.01:5;

u = @(t) (t >= 0);
x = @(t) (u(t+2)-2*u(t)+u(t-1));
z = @(t) (x(2*t-1));
y = @(t) (t.*(u(t+1)-u(t-2)));

figure;

subplot(411);
plot(t, x(t));

subplot(412);
plot(t, z(t));

subplot(413);
plot(diff(x(t))./diff(t));

subplot(414);
plot(t, y(t));

figure;

subplot(411);
plot(diff(y(t))./diff(t));

subplot(412);
plot(t, z(t));

subplot(413);
plot(diff(x(t))./diff(t));

subplot(414);
plot(t, y(t));
