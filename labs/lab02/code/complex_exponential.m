% typo: e^(j*omega*t-/+theta) -> e^(j*(omega-/+theta))

omega = 100;
t = -0.1:(1/(2*1020*100)):0.1;

exp_func = exp(1j*(omega*t-10));
plot(exp_func)