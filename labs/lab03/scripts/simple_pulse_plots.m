u = @(t) (t >= 0);  % unit step
pulse = @(t, T) (u(t)) - (u(t-T));  % pulse

t = 0: 0.01: 5;

% 3.1
pulse_conv(t, pulse(t, 1), pulse(t, 1), '1');

% 3.2
pulse_conv(t, pulse(t, 2), pulse(t, 1), '2');

% 3.3
pulse_conv(t, pulse(t + 1, 2), pulse(t, 1), '3');

% 3.4
pulse_conv(t, pulse(t + 1, 2), 2*pulse(t - 0.5, 1), '4');

