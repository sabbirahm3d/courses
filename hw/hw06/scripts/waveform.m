f1 = 1;
f2 = 3;
dt = 0.01;
delta_t = 0.125;
t = 0:delta_t:0.875;


x = 4*cos(2*pi*t) - 3*sin(2*pi*f2*t+pi/4);
length(x)
figure;
plot(t, x)

figure;
hold on;
stem(x(1:8));
plot(x(1:8));
hold off;

x(1:8)