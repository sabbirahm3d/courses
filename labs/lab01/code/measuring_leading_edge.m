rand_ints = round(rand(10000,1), 1);

t = -1:(1/10):4;
T = 1;

u = @(t) (t >= 0);  % unit step
pulse = @(t, T) (u(t)) - (u(t-T));  % pulse
first_non_zero = @(t, p) (t(find(p, 1)));  % first non-zero sample

rand_pulses = zeros(size(rand_ints));

for index = 1 : numel(rand_ints)
    rand_pulses(index) = first_non_zero(t, pulse(t-rand_ints(index), T));
end

Count = length(rand_pulses);
Minimum = min(rand_pulses);
Maximum = max(rand_pulses);
Mean = mean(rand_pulses);
Standard_Deviation = std(rand_pulses);

stats = table(Count, Minimum, Maximum, Mean, Standard_Deviation);

figure;
histogram(rand_pulses);
ylabel('Frequency');
xlabel('Value');
title('Random Pulses with a 0.1 second Sampling Rate')
writetable(stats, 'stats.csv');



rand_ints = round(rand(10000,1), 2);

t = -1:0.05:4;
T = 1;

u = @(t) (t >= 0);  % unit step
pulse = @(t, T) (u(t)) - (u(t-T));  % pulse
first_non_zero = @(t, p) (t(find(p, 1)));  % first non-zero sample

rand_pulses = zeros(size(rand_ints));

for index = 1 : numel(rand_ints)
    rand_pulses(index) = first_non_zero(t, pulse(t-rand_ints(index), T));
end

Count = length(rand_pulses);
Minimum = min(rand_pulses);
Maximum = max(rand_pulses);
Mean = mean(rand_pulses);
Standard_Deviation = std(rand_pulses);

stats = table(Count, Minimum, Maximum, Mean, Standard_Deviation);

figure;
histogram(rand_pulses);
ylabel('Frequency');
xlabel('Value');
title('Random Pulses with a 0.05 second Sampling Rate')
writetable(stats, 'stats_1.csv');
