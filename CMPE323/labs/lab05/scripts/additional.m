b1 = [2];
a1 = [1 4 5];
% polezero_plot(b1,a1,'s',[-2 inf]);

% zeros_ =
% 
%    Empty matrix: 0-by-1
% 
% 
% poles_ =
% 
%   -2.0000 + 1.0000i
%   -2.0000 - 1.0000i

[r,p,k] = residue(b1, a1);
% r =
% 
%    0.0000 - 1.0000i
%    0.0000 + 1.0000i
% 
% 
% p =
% 
%   -2.0000 + 1.0000i
%   -2.0000 - 1.0000i
% 
% 
% k =
% 
%      []

u = @(t) (t >= 0);

sigma = real(p(1));
omega = imag(p(1));
E = 2*real(r(1));
F = 2*imag(r(1));

t = 0:0.01:20;

h = deal(zeros(1, length(t)));

for idx = 1 : numel(t)
    h(idx) = exp(sigma*t(idx))*(E*cos(omega*t(idx))+F*sin(omega*t(idx)))*u(t(idx));
end

figure;
plot(t, h);
title('$$-2\mathrm{e}^{(-2t)}\sin(t) u(t)$$', 'Interpreter', 'latex', 'FontSize', 18);
ylabel('Units');
xlabel('Time (s)')
