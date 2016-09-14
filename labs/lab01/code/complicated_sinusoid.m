t = -0.1:(1/(2*1020*10)):0.1;
dsb_am = 1 + 0.25*sin(180*pi*t)+0.15*sin(300*pi*t)+0.4*sin(2040*pi*t);
plot(t, dsb_am)