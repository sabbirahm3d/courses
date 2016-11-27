dt = 0.001;
t = -4.096: dt : 4.096;
tau = 1;

f = -10:0.1:10;
f_c = 5;

u = @(t) (t > 0);
p = @(t) (u(t) - u(t-tau));

p1 = @(t) (p(t + tau/2));
p2 = @(t) (p(t));
p3 = @(t) (p(t + tau));

test = @(t) (1 + 0.25*sin(180*pi*t)+0.15*sin(300*pi*t)+0.4*sin(2040*pi*t));