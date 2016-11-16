figure;

subplot(311);
plot(t, p1, 'LineWidth', 1.5);
ylabel('$$p(t+\frac{\tau}{2})$$', 'Interpreter', 'latex', 'FontSize', 12);

subplot(312);
plot(t, p2, 'LineWidth', 1.5);
ylabel('$$p(t)$$', 'Interpreter', 'latex', 'FontSize', 12);

subplot(313);
plot(t, p3, 'LineWidth', 1.5);
ylabel('$$p(t+\tau)$$', 'Interpreter', 'latex', 'FontSize', 12);

xlabel('Time');

% computing the coefficients
x = zeros(length(t), 1);
for n = 1:16
    nT = n .* t;
    y = p(n*(t + tau/2));
    x = exp(-1j*2*pi*nT*f');
    x(:,n) = y*x;
end

figure;
plot(x)