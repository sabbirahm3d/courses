% Explonential Growth Anonymous Function
growth = @(n, r, t) (n * exp(r.*t));

n = 1;
r = 0.6931;
t = 0:1:10;
growth(n, r, t)

% Exponential Decaying Anonymous Function
natural_response = @(omegaD, t) (2 * cos(omegaD .* t) - 1.5 * sin(omegaD .* t));

alpha = 0.7;
omega = 1.0;
omegaD = sqrt(omega^2 - alpha^2);
t = 0:0.1:10;
natural_response(omegaD, t)
