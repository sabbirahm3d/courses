% computing the coefficients
x = zeros(length(t), 1);
for kn = 1:11
    k = kn * T - 8;
    x(:,kn) = p(t + 0.5 - k);
end

figure;
plot(t, sum(x, 2))
xlabel('Time');
ylabel('Amplitude');
title('$$x(t) = \sum_{n=-N}^{N}{p(t-nT)}$$', 'Interpreter', 'latex', 'FontSize', 15);

k = [-800:800];
ck = (1/T).* sinc(k/T);
figure;
plot(k, real(ck))

