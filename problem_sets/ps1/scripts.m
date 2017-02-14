lambda = 1;
x = -2*lambda:0.001:0*lambda;
A = 1;
beta = 2*pi;

y1 = @(x, omega_t) (A * cos(omega_t - beta*x));
y2 = @(x, omega_t) (A * cos(omega_t + beta*x));
ys = @(x, omega_t) (y1(x, omega_t) + y2(x, omega_t));

figure;
hold on;
p1 = plot(x, y1(x, pi/4));
p2 = plot(x, y2(x, pi/4));
p3 = plot(x, ys(x, pi/4));
xlabel('x');
ylabel('$$\omega t = \frac{\pi}{4}$$', 'interpreter', 'latex', 'fontsize', 15);
legend([p1; p2; p3], 'y_1(x, t)', 'y_2(x, t)', 'y_s(x, t)');
hold off;

figure;
hold on;
p4 = plot(x, y1(x, pi/2));
p5 = plot(x, y2(x, pi/2));
p6 = plot(x, ys(x, pi/2));
xlabel('x');
ylabel('$$\omega t = \frac{\pi}{2}$$', 'interpreter', 'latex', 'fontsize', 15);
legend([p4; p5; p6], 'y_1(x, t)', 'y_2(x, t)', 'y_s(x, t)');
hold off;

diary log.txt;
z1 = 3 - 5j;
log(z1)

z2 = 3 - 4j;
exp(z2)

z3 = 3 * exp(1j*pi/6);
exp(z3)
diary off;