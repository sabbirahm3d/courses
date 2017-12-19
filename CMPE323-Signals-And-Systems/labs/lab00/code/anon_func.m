% Anonymous functions

pulse = @(t, T) (t>=0)-(t-T >= 0);
t = 0:1:10;
T = 3;

unit_pulse = pulse(t, T);
pulse_2 = pulse(2.*t, T);
pulse_3 = pulse(0.5.*t, T);
pulse_4 = pulse(t+3, T);
pulse_5 = pulse(t-3, T);

subplot(3,3,2)
plot(unit_pulse)
title('Unit Pulse')

subplot(3,3,4)
plot(pulse_2)
title('Unit Pulse * 2')

subplot(3,3,6)
plot(pulse_3)
title('Unit Pulse * 0.5')

subplot(3,3,7)
plot(pulse_4)
title('Unit Pulse + 3')

subplot(3,3,9)
plot(pulse_5)
title('Unit Pulse - 3')
