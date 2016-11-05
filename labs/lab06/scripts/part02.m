xt = zeros(1, length(t));

for i = 1: length(t)
    xt(i) = sum(real(ck.*exp(1j*2*pi*k*t(i)/T)));
end

figure;
plot(t, xt)