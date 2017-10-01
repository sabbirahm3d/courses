k = -10:10;
A = kron(k',t);
argument = 1j*2*pi*A/t;
kernel = exp(argument);
xhat = (1/T).* sinc(k/T)*kernel'*dt;

plot(real(xhat))
