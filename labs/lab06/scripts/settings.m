dt = 1/10000;
t = -15 : dt : 15;
T = 4;

u = @(t) (t > 0);
p = @(t) (u(t) - u(t-1));
r = @(t) ((t).*(p(t)));

xhat = zeros(1, length(t));
K=[10 50 100 200 400 800];
estimates = zeros(length(t), length(K));

mse = zeros(1, length(t));
mse_k = zeros(1, length(K));
