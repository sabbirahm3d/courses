A = 1;
a1 = 0.2;
a2 = 0.2;

f1 = 90;
f2 = 150;

phi1 = -pi/2;
phi2 = -pi/2;

f_c = 100000;

d = @(t) (A*(1 + a1*cos(2*pi*f1*t+phi1) + a2*cos(2*pi*f2*t+phi2) ));
c = @(t) (cos(2*pi*f_c*t));
