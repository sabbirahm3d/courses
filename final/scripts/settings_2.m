A = 1;
a1 = 0.2;
a2 = 0.2;

f1 = 90;
f2 = 150;

phi1 = -pi/2;
phi2 = -pi/2;

dt = 1/(10*300);
t0 = -0.05:dt:0.05;

fsa=1000;
dt=1/fsa;
t=[-4096:4095]*dt; % an array with 2^M points, but starting at M=-4096
NFFT = length(t);
trecord = NFFT*dt; % total measurement time
fresolution = 1/trecord; % the resolution is 1/(measurement time)
df = fresolution; %...which is also the frequency resolution

funshifted=[0:NFFT-1]*df; % FFTs go from 0 to (N-1)df
f = [-NFFT/2: NFFT/2-1]*df;  % centered version

f_c = 100000;

d = @(t) (A*(1 + a1*cos(2*pi*f1*t+phi1) + a2*cos(2*pi*f2*t+phi2) ));
c = @(t) (cos(2*pi*f_c*t));

theory_d = @(f) (f*0.0001);

