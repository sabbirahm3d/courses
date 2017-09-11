% Simple computations
figure
plot(t_1, growth)
title('Simple Computation')
% Semilog
figure
plot(t_1, log(growth))
title('Semilog Computation')

% Exponentially Decaying Sinusoid
figure
plot(t_2, natural_response, 'LineWidth',2)
axis([0 5 -3 3])
title('Exponentially Decaying Sinusoid')
xlabel('Time (s)') % x-axis label
ylabel('Natural Response (V)') % y-axis label
grid on;

x = t_3;
figure
subplot(2,2,1)
plot(x, real(complex_exp_1), x, real(complex_exp_2), 'LineWidth', 2)
title('Real Parts');
xlabel('Time (s)'); % x-axis label
ylabel('Value'); % y-axis label
grid on;

subplot(2,2,2)
plot(x, imag(complex_exp_1), x, imag(complex_exp_2), 'LineWidth', 2)
title('Imaginary Parts')
xlabel('Time (s)') % x-axis label
ylabel('Value') % y-axis label
grid on;

c_t = (complex_exp_1 + complex_exp_2) / 2;
subplot(2,2,3)
plot(x, abs(c_t - cos(0.71*x)), 'LineWidth', 2)
title('Error Function')
xlabel('Time (s)') % x-axis label
ylabel('Value') % y-axis label
grid on;

