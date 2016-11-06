xhat = zeros(1, length(t));
K=[10 50];

estimates = zeros(length(t), length(K));

for term = 1 : length(K)
    k1 = -K(term):K(term);
    for i = 1: length(t)
        xhat(i) = sum(real((1/T).* sinc(k1/T).*exp(1j*2*pi*k1*t(i)/T)));
    end
    estimates(:,term) = xhat;
end
