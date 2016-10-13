dt = 1/1000;
t = -1 : dt : 10;
t2 = -2 : dt : 20;
% hardcoded
t3 = -1 : dt : 10.249;
freq = [0 1 4 6.5 7.5 8.5 11.5 19.5];

u = @(t) (t >= 0);
pulse = @(t, T) (u(t) - u(t - T));
x = @(t, f) (exp(2j*pi*f*t).*u(t));
h = pulse(t, 0.25);

% ghetto_plot(x, dt, t, t2, freq, h, 0)
% ghetto_plot(x, dt, t, t2, freq, h, 1)
% 
% h = h(h ~= 0);
% ghetto_plot(x, dt, t, t3, freq, h, 1)

h2 = @(t) (h.*exp(15j*pi*t));
plot(abs(conv(x(t, 11.5), h2(t))))
% ghetto_plot(x, dt, t, t2, freq, h2, 0)
