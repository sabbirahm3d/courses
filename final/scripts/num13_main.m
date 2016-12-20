a_p = 3;
a_s = 64;
f_p = 10e3;
f_s = 50e3;
n = 5;

nu_s = f_s/f_p;
epsilon = (10^(a_p/10)-1)^(1/2);
nu_3 = (1/epsilon)^(1/n);

theta = zeros(1, n);
s = zeros(1, n);

for k = 1:n
    theta(k) = (2*(k-1)+n-1)*pi/(2*n);
    s(k) = nu_3*exp(-1j*theta(k));
end

w_c = prod(s, 2)^(1/n);
w_cn = w_c^n;
s
