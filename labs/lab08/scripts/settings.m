dt = 1/1000;
t=[-4096:4095]*dt; % an array with 2^M points, but starting at M=-4096
NFFT = length(t);
trecord = NFFT*dt;
fresolution = 1/trecord; % the resolution is 1/(measurement time)
df = fresolution; %...which is also the frequency resolution
funshifted=[0:NFFT-1]*df; % FFTs go from 0 to (N-1)df
f = [-NFFT/2: NFFT/2-1]*df;  % centered version

tau = 1;

f_c = 5.0049;

u = @(t) (t >= 0);
p = @(t) (u(t) - u(t-tau));
c = @(t) (exp(1j*2*pi*f_c*t));

p1 = @(t) (p(t + tau/2));
p2 = @(t) (p(t));
p3 = @(t) (p(t + tau));

theory_p1 = @(f) (tau*sinc(f*tau));
theory_p2 = @(f) (exp(-1j*pi*tau*f)*tau.*sinc(f*tau));
theory_p3 = @(f) (exp(1j*pi*tau*f)*tau.*sinc(f*tau));