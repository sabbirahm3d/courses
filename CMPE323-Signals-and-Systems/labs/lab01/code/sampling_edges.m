% 3.2

t = -0.001:(1/10000):0.001;
u = @(t) (t >= 0);

figure;
plot(t, u(t))
title('Sampling Edges')
xlabel('Time (s)')
ylabel('Units')
