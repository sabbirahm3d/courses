rand_ints = round(rand(10,1), 1);

t = -1:(1/10):4;
T = 1;

u = @(t) (t >= 0);  % unit step
pulse = @(t, T) (u(t)) - (u(t-T));  % pulse
first_non_zero = @(t, p) (t(find(p, 1)));  % first non-zero sample

rand_pulses = zeros(size(rand_ints));

for index = 1 : numel(rand_ints)
    disp(index)
    rand_pulses(index) = pulse(t-rand_ints(index), T);
end

rand_pulses