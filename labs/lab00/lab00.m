% Exponential Growth
n = 1;
r = 0.6931;
t_1 = 0:1:10;
growth = n*exp(r.*t_1);

% Exponential decaying solution
alpha = 0.7;
omega = 1.0;
omegaD = sqrt(omega^2 - alpha^2);
t_2 = 0:0.1:10;
natural_response = 2*cos(omegaD.*t_2) - 1.5*sin(omegaD.*t_2);

% Complex Exponential
t_3 = 0 : 0.1 : 5;
complex_exp_1 = exp(1j*0.71.*t_3);
complex_exp_2 = exp(-1j*0.71.*t_3);
complex_exp_1;
complex_exp_2;

% % Simple computations
% figure
% 
% plot(t_1, growth)
% title('Simple Computation')
% hold on
% 
% % Semilog
% plot(t_1, log(growth))
% title('Semilog Computation')
% hold off

% figure
% plot(t_2, natural_response, 'LineWidth',2)
% axis([0 5 -3 3])
% title('Exponentially Decaying Sinusoid')
% xlabel('Time (s)') % x-axis label
% ylabel('Natural Response (V)') % y-axis label
% grid on;

x = t_3;

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


diary diary_file.txt
growth
natural_response
complex_exp_1
complex_exp_2
diary off