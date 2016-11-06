% computing the coefficients
x = zeros(length(t), 1);
for kn = 1:16
    k = kn * 4 - 16;
    x(:,kn) = p(t + 0.5 - k);
end

x = sum(x, 2)';

figure;
plot(t, x)
xlabel('Time');
ylabel('Amplitude');
title('$$x(t) = \sum_{n=-3}^{3}{p(t-nT)}$$', 'Interpreter', 'latex', 'FontSize', 15);

k = -800:800;
ck = (1/T).* sinc(k/T);
figure;
plot(k, real(ck))

