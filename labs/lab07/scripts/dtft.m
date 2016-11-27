function [ X ] = dtft( x, n, w, dt )
% [X] = dtft(x, n, w)
% X = DTFT values computed at w frequencies
% x = finite duration sequence over n
% n = sample position vector
% w = frequency location vector

    temp = -1j * w' * n;

    e = exp(temp);

    X = dt*e * x';

end