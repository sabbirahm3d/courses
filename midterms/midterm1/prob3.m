dt = 0.01;
t = -5:dt:5;
t2 = -10:dt:10;

u = @(t) (t > 0);
p = @(t, T) (u(t) - u(t-T));

b3 = @(t) (p(t, 1) + p(t-1, 1) - p(t-2, 1));

figure;
r = dt*conv(b3(t), b3(-t));
disp(length(t2))
subplot(311);
plot(t2,b3(t2));
subplot(312);
plot(t2,b3(-t2));
subplot(313);
plot(t2,r);
