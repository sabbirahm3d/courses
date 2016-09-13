% a
syms t;
x = 2 * heaviside(sym(t)) - heaviside(sym(t-1));
dx = diff(x,t, 1);

figure;
subplot(211);
fplot(t,x);
subplot(212);
fplot(t,dx);


% b
x = dirac(t+pi)- 2 * dirac(t-pi);
int_x = int(x, t);

figure;
subplot(211);
fplot(t,x);
subplot(212);
fplot(t,int_x);

% c
figure
n = [1 2 3 0 2 5 0 1];
f = zeros(length(n));
for i = 1 : length(n)
    f(i) = delta_comb(n(i));
end
stem(f)