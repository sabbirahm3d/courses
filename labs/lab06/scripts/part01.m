% computing the coefficients
x = zeros(length(t), 1);
for kn = 1:16
    k = kn * T - 16;
    x(:,kn) = p(t + 0.5 - k);
end

x = sum(x, 2)';

figure;
plot(t, x, 'LineWidth', 1);
ylim([0 1.5]);
xlabel('Time');
ylabel('Amplitude');
title('$$x(t) = \sum_{n=-3}^{3}{p(t-nT)}$$', 'Interpreter', 'latex', 'FontSize', 15);

k = -800:800;
ck = (1/T).* sinc(k/T);
figure;
plot(k, real(ck), 'LineWidth', 1);
xlabel('Time');
ylabel('Amplitude');
title('$$c_{k} = \int_{-0.5}^{0.5}{x(t)e^{-j\omega_o kt}dt}$$', 'Interpreter', 'latex', 'FontSize', 15);

synthesize(x, 'x', K, estimates, t, T, mse, mse_k)