figure;

subplot(311);
plot(t, p1(t), 'LineWidth', 1.5);
ylabel('$$p_{1}(t) = p(t+\frac{\tau}{2})$$', 'Interpreter', 'latex', 'FontSize', 12);
title('Basic Unit Pulses', 'FontSize', 15);

subplot(312);
plot(t, p2(t), 'LineWidth', 1.5);
ylabel('$$p_{2}(t) = p(t)$$', 'Interpreter', 'latex', 'FontSize', 12);

subplot(313);
plot(t, p3(t), 'LineWidth', 1.5);
ylabel('$$p_{3}(t) = p(t+\tau)$$', 'Interpreter', 'latex', 'FontSize', 12);

xlabel('Time');