estimates = zeros(length(t), length(f));
xhat = zeros(1, length(t));

for cur_freq = 1 : length(f)
    n = -1:dt:1;
%     for i = 1: length(t)
%         xhat(i) = sum(p1(n*t(i)).*exp(1j*2*pi*n*t(i)*f(cur_freq)));
%     end
    estimates(cur_freq) = sum(test(n).*exp(-1j*2*pi*n*f(cur_freq)));
end
