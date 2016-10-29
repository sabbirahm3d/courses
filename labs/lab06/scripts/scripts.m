dt = 1/10000;
t = 0 : dt : 10;
T = 4;

u = @(t) (t > 0);
p = @(t, T) (u(t) - u(t-T));

x = zeros(1, 7*length(t));

for kn = 1:7
    k = kn -4;
    x(kn) = p(t+0.5 - k*t, 1);
end

plot(sum(x), 'LineWidth', 2)