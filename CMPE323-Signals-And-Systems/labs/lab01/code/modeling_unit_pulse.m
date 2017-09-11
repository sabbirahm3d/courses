% 3.2.1

t = -1:(1/10):4;
T = 1;

u = @(t) (t >= 0);  % unit step
pulse = @(t, T) (u(t)) - (u(t-T));  % pulse
first_non_zero = @(t, p) (t(find(p, 1)));  % first non-zero sample

p = pulse(t, T);
plotify(p, t, T, first_non_zero(t, p), 'Unit Pulse: p(t) = u(t) - u(t - T)');

p = pulse(t - 0.5, T);
plotify(p, t, T, first_non_zero(t, p), 'p(t - 0.5)');

p = pulse(t - 0.1, T);
plotify(p, t, T, first_non_zero(t, p), 'p(t - 0.1)');

p = pulse(t - 0.0525, T);
plotify(p, t, T, first_non_zero(t, p), 'p(t - 0.0525)');

p = pulse(t - 0.113, T);
plotify(p, t, T, first_non_zero(t, p), 'p(t - 0.113)');
