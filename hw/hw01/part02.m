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

% % c
% syms t k T
% x = sum(dirac(t-k*T));
% figure
% fplot(k,x)
