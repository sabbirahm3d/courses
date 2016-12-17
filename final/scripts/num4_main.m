beta = (tau1 + tau3)/2;
w = @(t, tau1, tau2, tau3) dt*(conv(a(t + tau3/2 - beta, tau1), heaviside(t)) ...
    - conv(a(t - tau3/2 - beta, tau2), heaviside(t)));

x_tick_str = cell(1, 12);
y_tick_str = cell(1, 4);

y_tick_str{1} = 0;
y_tick_str{3} = 1;

x_tick_str{2} = 0;
x_tick_str{4} = '\tau_1';
x_tick_str{7} = '\tau_3 + (\tau_1 - \tau_2)/2';
x_tick_str{11} = '\tau_3 + (\tau_1 + \tau_2)/2';


figure;

subplot(311);
plot(t2, dt*conv(a(t + tau3/2 - beta, tau1), heaviside(t)));

xlim([-0.5 tau2+tau3]);
ylim([0 1.5]);
ylabel('$$y_{1}(t-\beta)$$', 'Interpreter', 'latex', 'FontSize', 16);

set(gca, 'xTickLabel', x_tick_str, 'yTickLabel', y_tick_str);

subplot(312);
plot(t2, dt*conv(a(t - tau3/2 - beta, tau2), heaviside(t)));

xlim([-0.5 tau2+tau3]);
ylim([0 1.5]);
ylabel('$$y_{2}(t-\beta)$$', 'Interpreter', 'latex', 'FontSize', 16);

set(gca, 'xTickLabel', x_tick_str, 'yTickLabel', y_tick_str);

subplot(313);
plot(t2, w(t, tau1, tau2, tau3));

xlim([-0.5 tau2+tau3]);
ylim([0 1.5]);
ylabel('$$y_{1}(t-\beta) - y_{2}(t-\beta)$$', ...
    'Interpreter', 'latex', 'FontSize', 16);
xlabel('Time (s)')

set(gca, 'xTickLabel', x_tick_str, 'yTickLabel', y_tick_str);

% figure;
% subplot(211);
% fft_w1 = fft(a(t + tau3/2, tau1));
% fft_w1 = fftshift(fft_w1);
% 
% fft_w2 = fft(heaviside(t));
% fft_w2 = fftshift(fft_w2);
% 
% fft_w3 = fft(a(t - tau3/2, tau2));
% fft_w3 = fftshift(fft_w3);
% 
% plot(t, abs(fft_w1.*fft_w2 - fft_w3.*fft_w2));
% xlim([-0.1 0.1])
% 
% fft_w0 = fft(w(t, tau1, tau2, tau3));
% fft_w0 = fftshift(fft_w0);
% 
% subplot(212)
% plot(t2, abs(fft_w0));
% xlim([-0.1 0.1])
% 

