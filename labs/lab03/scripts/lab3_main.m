% lab3_main
% main script to instantiate all the vectors and functions

u = @(t) (t >= 0);  % unit step
d = @(t) (~t);  % unit impulse
pulse = @(t, T) (u(t) - u(t-T));  % pulse of duration T
t = 0: 0.01: 5;  % time axis
t2 = -1: 0.01: 4;  % time axis shifted 1 to the negative

% 3.1
y_int = zeros(length(t));  % piecewise function for the convolution integral
y_int(t <= 1) = t(t <= 1);
y_int(t > 1) = 2-t(t > 1);
y_int(t > 2) = 0;

% pass in time axis, input signal, response signal and piecewise function as parameters
pulse_conv(t, pulse(t, 1), pulse(t, 1), y_int);

% 3.2
y_int = zeros(length(t));
y_int(t <= 1) = t(t <= 1);
y_int(t > 1) = 1;
y_int(t > 2) = 3-t(t > 2);
y_int(t > 3) = 0;

pulse_conv(t, pulse(t, 2), pulse(t, 1), y_int);

% 3.3

y_int = zeros(length(t2));
y_int(t2 < -1) = t2(t2 < -1);
y_int(t2 >= -1) = 1 + t2(t2 >= -1);
y_int(t2 > 0) = 1;
y_int(t2 > 1) = 2-t2(t2 > 1);
y_int(t2 > 2) = 0;

pulse_conv(t2, pulse(t2 + 1, 2), pulse(t2, 1), y_int);

% 3.4
y_int = zeros(length(t2));
y_int(t2 < -1) = 0;
y_int(t2 >= -1) = 2;
y_int(t2 >= 1) = 0;

pulse_conv(t2, pulse(t2 + 1, 2), 2*d(t2-0.5), y_int);
