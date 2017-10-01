dt = 0.01;
t = -5:dt:5;
t2 = 0:dt:20;
t3 = 0:dt:10;
r1 = 1000;
r2 = 1000;
c = 250e-6;
x = r1*r2*c;

bs = [-r1];
as = [x r1];

[r,p,k] = residue(bs, as);

u = @(t) (t > 0);
d = @(t) (~t);
p = @(t, T) (u(t) - u(t-T));
b3 = @(t) (p(t, 1) + p(t-1, 1) - p(t-2, 1));

y = @(t) (-1*(1-exp(-4*t)));

h1 = @(t) (1-exp(-4*t));
h2 = @(t) (4*exp(-4*t));

figure;
plot(t3, y(t3))
title('Unit-step Response');
ylabel('Units');
xlabel('Time (s)');

figure;
plot(t3, h2(t3))
title('Unit-impulse Response');
ylabel('Units');
xlabel('Time (s)');

figure;
plot(t2, dt*conv(y(t), b3(t)));
title('$$Response\ to\ b_{3}(t)=p(t, 1) + p(t-1, 1) - p(t-2, 1)$$', 'Interpreter', 'latex', 'FontSize', 14);
ylabel('Units');
xlabel('Time (s)');
