t = -5:0.01:5;

u = @(t) (t > 0);
p = @(t, T) (u(t) - u(t-T));

b3 = @(t) (p(t, 1) + p(t-1, 1) - p(t-2, 1));

figure;
plot(t, b3(t));

figure;
plot(conv(b3(t), b3(-t)));
