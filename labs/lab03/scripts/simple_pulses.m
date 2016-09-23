u = @(t) (t >= 0);  % unit step
pulse = @(t, T) (u(t)) - (u(t-T));  % pulse

t = 0: 0.01: 5;

x = pulse(t, 1);
h = pulse(t, 1);
n = t(end);

y_n = zeros(length(x));

for index = 1 : 0.01: x(end)
    y_n(index) = y_n(index) + (pulse(n-index, 1) * pulse(index, 1));
end;

plot(t, y_n);
