% part 1
% a

t = -5:0.1:5;

unit_step = @(t) (ceil(heaviside(t)));
unit_impulse = @(t) (dirac(t));

is_even = @(f, t) (isequal(f(t), f(-t)));
is_odd= @(f, t) (isequal(f(t), -f(-t)));

even_part = @(f, t) ((f(t) + f(-t))/2);
odd_part = @(f, t) ((f(t) - f(-t))/2);

a = @(t) (unit_impulse(t) - unit_impulse(t - 1));

b = @(t) (-2 * unit_impulse(t) + 2 * unit_impulse(t - 1));

c = @(t) (unit_impulse(t + 1) - unit_impulse(t - 1));

d = @(t) (-unit_impulse(t + 2) - unit_impulse(t + 1) + 4*unit_impulse(t) + ...
    4*unit_impulse(t - 1) + unit_impulse(t - 2) + unit_impulse(t - 3));

plot_components(d, t);

even = is_even(d, t)
odd = is_odd(d, t)

