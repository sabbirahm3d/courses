% a
syms t;
x = 2 * heaviside(sym(t)) - heaviside(sym(t-1));
dx = diff(x,t, 1);

figure;
subplot(211);
fplot(t,x);
title('x(t) = 2u(t) − u(t − 1)');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(212);
fplot(t,dx);
title('dx(t)/dt');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label


% b
x = dirac(t+pi)- 2 * dirac(t-pi);
int_x = int(x, t);

figure;
subplot(211);
fplot(t,x);
title('x(t) = \delta(t+\pi) - 2\delta(t-\pi)');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

subplot(212);
fplot(t,int_x);
title('integral(x(t)dt)');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

% c
figure;
T = 2;  % period
n = ones(12);
for i = 1 : T: length(n)
    n(i) = 0;
end

pulse_train = zeros(length(n));
for i = 1 : length(n)
    pulse_train(i) = delta_comb(n(i));
end

stem(pulse_train);
title('Pulse Train');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label

