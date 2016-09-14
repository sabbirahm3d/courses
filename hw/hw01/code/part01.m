% 1. MATLAB Practice

% a.
t = 0 : 0.005 : 10;
signal = 2 * cos(2*pi.*t);
figure;
plot(t, signal)
title('Signal');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label
grid on;

% b.
% verify data type of array generated
class(signal);

sum_of_signal = 0;
for index = 1:numel(signal)
    sum_of_signal = sum_of_signal + signal(index);
end
av_func = sum_of_signal / numel(signal);
av_func == mean(signal)
av_func

% c.
syms t;
signal_func = 2*cos(2*pi*t);
int(signal_func, t, 0, 10)
int_signal = int(signal_func, t);

% d.
d_signal = diff(signal_func, t, 1);

% e.
figure
subplot(311);
fplot(matlabFunction(signal_func),[0 10])
title('Signal');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label
grid on;

subplot(312);
fplot(matlabFunction(int_signal),[0 10])
title('Integral of the signal')
xlabel('Time (s)') % x-axis label
ylabel('Value') % y-axis label
grid on;

subplot(313);
fplot(matlabFunction(d_signal),[0 10])
title('Derivative of the signal')
xlabel('Time (s)') % x-axis label
ylabel('Value') % y-axis label
axis([0 10 -10 10])
grid on;
