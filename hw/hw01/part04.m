T = 1.5;
t = -5:1:5;
pulse = @(t, T) (t >= 0)-(t-T >= 0);

subplot(611);
plot(t, pulse(t, T));

subplot(612);
plot(t, pulse(t, T-3));

subplot(613);
plot(t, pulse(t, T+2.5));

subplot(614);
plot(t, pulse(t, 2*T));

subplot(615);
plot(t, pulse(t, T/2));

subplot(616);
plot(t, pulse(t, -T));

figure
plot(t, pulse(-0.2*t, 1));

