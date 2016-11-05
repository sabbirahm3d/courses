A = kron(k',t);
argument = 1j*2*pi*A/t;
kernel = exp(argument);
xhat = ck*kernel*dt;