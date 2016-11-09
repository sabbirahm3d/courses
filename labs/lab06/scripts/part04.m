% computing the coefficients
z = zeros(length(t), 1);
for kn = 1:16
    k = kn * T - 16;
    z(:,kn) = r(t + 0.5 - k);
end

z = sum(z, 2)';

figure;
plot(t, z);
xlabel('Time');
ylabel('Amplitude');
title('$$z(t) = \sum_{n=-3}^{3}{r(t-nT)}$$', 'Interpreter', 'latex', 'FontSize', 15);

% k = -800:800;
% ck = (1/T).* sinc(k/T);
% figure;
% plot(k, real(ck));
% 
% synthesize(z, 'x', K, estimates, t, T, mse, mse_k)