% w = -2*pi:0.01:2*pi;
w = f;
x = p1(t);
% x = exp(t .* (1i*2));

X = dtft(x, t, w, dt);

subplot(2,1,1);
plot(t, x);
title('signal = exp(jw0n)');
% ylim([0 1.5]);

subplot(2,1,2);
plot(w, X);
title('DTFT');
% ylim([0 1.5]);