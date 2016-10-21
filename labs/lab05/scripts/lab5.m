b = [1 2 5];
a = [1.0000 7.0000 14.8125 12.8750 6.5000];

polezero_plot(b,a,'s',[-1 inf]);

% zeros_ =
% 
%   -1.0000 + 2.0000i
%   -1.0000 - 2.0000i
% 
% 
% poles_ =
% 
%   -4.0000 + 0.0000i
%   -2.0000 + 0.0000i
%   -0.5000 + 0.7500i
%   -0.5000 - 0.7500i

[r,p,k] = residue(b, a);
u = @(t) (t >= 0);

sigma = real(p(3));
omega = imag(p(3));
E = 2*real(r(3));
F = 2*imag(r(3));

t = 0:0.01:20;

[impulse1, impulse2, impulse3] = deal(zeros(1, length(t)));

for idx = 1 : numel(t)
    impulse1(idx) = r(1)*exp(p(1)*t(idx))*u(t(idx));
    impulse2(idx) = r(2)*exp(p(2)*t(idx))*u(t(idx));
    impulse3(idx) = exp(sigma*t(idx))*(E*cos(omega*t(idx))+F*sin(omega*t(idx)))*u(t(idx));
end

h = impulse1 + impulse2 + impulse3;

figure;

subplot(311);
plot(t, impulse1);
title('$$-0.5073 \mathrm{e}^{(-4t)} u(t)$$', 'Interpreter', 'latex', 'FontSize', 18);
ylabel('Units');

subplot(312);
plot(t, impulse2);
title('$$-0.8889 \mathrm{e}^{(-2t)} u(t)$$', 'Interpreter', 'latex', 'FontSize', 18);
ylabel('Units');

subplot(313);
plot(t, impulse3);
title('$$-\mathrm{e}^{(-0.5t)}(0.3816\cos(0.75t)+0.7436\sin(0.75t)) u(t)$$', 'Interpreter', 'latex', 'FontSize', 18);
ylabel('Units');
xlabel('Time (s)')

figure;
plot(t, h);
title('$$h(t)$$', 'Interpreter', 'latex', 'FontSize', 18);
ylabel('Units');
xlabel('Time (s)')
