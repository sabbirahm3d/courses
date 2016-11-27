figure;

subplot(311);
plot(t, p1(t), 'LineWidth', 1.5);
ylabel('$$p(t+\frac{\tau}{2})$$', 'Interpreter', 'latex', 'FontSize', 12);

subplot(312);
plot(t, p2(t), 'LineWidth', 1.5);
ylabel('$$p(t)$$', 'Interpreter', 'latex', 'FontSize', 12);

subplot(313);
plot(t, p3(t), 'LineWidth', 1.5);
ylabel('$$p(t+\tau)$$', 'Interpreter', 'latex', 'FontSize', 12);

xlabel('Time');

% % % computing the coefficients
% x = zeros(length(t), 1);
% for n = 1:16
%     for m = 1 : 201
%         nT = n .* t;
%         y = p(n*(t + tau/2));
%         x = exp(-1j*2*pi*f[m]*nT);
%         x(:,n) = x*y;
%     end
% end
%  
% figure;
% plot(x)
% 
% figure;
% x=[2 1 0 1 2];
% ezplot(abs(DTFT(p1,-2)));
% title('DTFT of Original Signal');
% 
% figure;
% plot(real(p1.*exp(1j*2*pi*5*t)))

figure;
plot(t, estimates)