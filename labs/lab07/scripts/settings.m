dt = 0.001;
t = -4.096: dt : 4.096;
tau = 1;

f = [-10: 0.1: 10]';

u = @(t) (t > 0);
p = @(t) (u(t) - u(t-tau));

p1 = p(t + tau/2);
p2 = p(t);
p3 = p(t + tau);
