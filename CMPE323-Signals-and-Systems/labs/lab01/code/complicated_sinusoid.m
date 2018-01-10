t = -0.1:(1/(2*1020*100)):0.1;
dsb_am = 1 + 0.25*sin(180*pi*t)+0.15*sin(300*pi*t)+0.4*sin(2040*pi*t);

figure;
plot(t, dsb_am)
title('x(t) = 1 + 0.25sin(180\pit) + 0.15sin(300\pit) + 0.4sin(2040\pit)')
xlabel('Time (s)')
ylabel('Units')

t = -0.1:(1/(2*1020)):0.1;
dsb_am = 1 + 0.25*sin(180*pi*t)+0.15*sin(300*pi*t)+0.4*sin(2040*pi*t);

figure;
plot(t, dsb_am)
title('x(t) = 1 + 0.25sin(180\pit) + 0.15sin(300\pit) + 0.4sin(2040\pit)')
xlabel('Time (s)')
ylabel('Units')
