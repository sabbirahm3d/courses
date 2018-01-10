u = @(t) (t >= 0);
pulse = @(t, T) (u(t)) - (u(t-T));  % pulse

b =[0.0860, 0, -0.1721, 0, 0.0860];
a =[1.0000, -1.5690, 1.7660, -1.1262, 0.5655];
t = 0:0.05:2;

m = 2;
n = 3;

x = @(t) (2*t);
y = filter(b, a, x(t));

% testing linearity

exp_1 = pulse(m*y, 1);
exp_2 = pulse(n*y, 1);
exp_3 = pulse(m*y+n*y, 1);

figure;
subplot(211)
plot(t, exp_1+exp_2);
title('pulse(m*y(t)) + pulse(n*y(t))');

subplot(212)
plot(t, exp_3);
title('pulse(m*y(t) + n*y(t))');
xlabel('Time (s)')

% testing time invariance

exp_1 = pulse(m*y, 1);
exp_2 = pulse(n*y, 1);
exp_3 = pulse(m*y+n*y, 1);

figure;
subplot(211)
plot(t, exp_1+exp_2);
title('pulse(m*y(t)) + pulse(n*y(t))');

subplot(212)
plot(t, exp_3);
title('pulse(m*y(t) + n*y(t))');
xlabel('Time (s)')

