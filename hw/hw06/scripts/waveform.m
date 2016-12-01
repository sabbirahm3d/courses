f1 = 1;
f2 = 3;
dt = 0.01;
delta_t = 0.125;
t = 0:delta_t:0.875;
x = 4*cos(2*pi*t) - 3*sin(2*pi*f2*t+pi/4);

figure;
hold on;
stem(x);
plot(x);
title('$$x(t) = 4cos(2\pi f_{1}t) - 3sin(2\pi f_{2}t + \frac{\pi}{4})$$',...
    'Interpreter', 'latex', 'FontSize', 14);
ylabel('Amplitude');
xlabel('Time');
hold off;

figure;
subplot(211);
stem(abs(fft(x)), 'LineWidth', 2);
title('Magnitude of FFT(x)', 'FontSize', 14);
ylabel('Magnitude');

subplot(212);
stem(angle(fft(x)), '-r', 'LineWidth', 2);
title('Phase of FFT(x)', 'FontSize', 14);
ylabel('Angle');
xlabel('Frequency');

N = length(x);
if ~mod(N, 2)
    n = linspace(0,N-1,N);
    k = n';
    M = exp((-2 * 1j * pi)/N);    
end