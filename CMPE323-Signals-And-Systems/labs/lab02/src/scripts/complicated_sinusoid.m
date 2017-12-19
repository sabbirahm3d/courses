t = -0.1:(1/(2*1020*100)):0.1;

figure;

subplot(211);
dsb_am = 1 + 0.25*sin(180*pi*t)+0.15*sin(300*pi*t)+0.4*sin(2040*pi*t);
plot(t, dsb_am, '-b');
title('x(t)')
ylabel('Units')

subplot(212);
dsb_am_delayed = 1 + 0.25*sin(180*pi*(t - 2*pi))+0.15*sin(300*pi*(t - 2*pi))+0.4*sin(2040*pi*(t - 2*pi));
plot(t, dsb_am_delayed, '-r')
title('x(t) delayed by 2\pi')
xlabel('Time (s)')
ylabel('Units')

% piecewise
figure;
subplot(311);
plot(t, 0.25 * sin(180*pi*t))
title('x(t) Broken Down to its Constituents')
subplot(312);
plot(t, 0.15 * sin(300*pi*t))
subplot(313);
plot(t, 0.4 * sin(2040*pi*t))
xlabel('Time (s)')

% piecewise delayed
figure;
subplot(311);
plot(t, 0.25 * sin(180*pi*(t - 2*pi)))
title('x(t) Broken Down to its Constituents and Delayed by 2\pi')
subplot(312);
plot(t, 0.15 * sin(300*pi*(t - 2*pi)))
subplot(313);
plot(t, 0.4 * sin(2040*pi*(t - 2*pi)))
xlabel('Time (s)')

