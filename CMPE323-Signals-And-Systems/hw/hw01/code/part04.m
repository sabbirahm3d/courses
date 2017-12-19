T = 1.5;  % amplitude
t = -5:0.01:5;  % time scale
pulse = @(t, T) (t >= 0)-(t-T >= 0);

subplot(311);
plot(t, pulse(t, T));
title('Unit Pulse');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(312);
plot(t, pulse(t-3, T));
title('Delay 3 seconds');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(313);
plot(t, pulse(t+2.5, T));
title('Advance 2.5 seconds');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

figure
subplot(311);
plot(t, pulse(t, T));
title('Unit Pulse');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(312);
plot(t, pulse(2*t, T));
title('Compress by factor of 2');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(313);
plot(t, pulse(t/2, T));
title('Expand by factor of 2');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

figure
subplot(311);
plot(t, pulse(t, T));
title('Unit Pulse');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(312);
plot(t, pulse(-t, T));
title('Reverse the time scale');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(313)
plot(t, pulse(-0.2*t + 1, T));
title('Unit Pulse: p(-0.2t+1)');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

