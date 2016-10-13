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

% raw convolution
% ghetto_plot(x, dt, t, t2, freq, h, 0)
% 
% % cut off convolution tail
% ghetto_plot(x, dt, t, t2, freq, h, 1)
% 
% % non-zero elements of h
% ghetto_plot(x, dt, t, t3, freq, h(h ~= 0), 1)
% 
% % 3.2 a less simple filter
% h2 = @(t) (h.*exp(15j*pi*t));
% ghetto_plot(x, dt, t, t2, freq, h2(t), 1)

response(x, dt, t, t2, freq, h, 0)
