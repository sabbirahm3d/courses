dt = 1/1000;
t = -1 : dt : 10;
t2 = -2 : dt : 20;
freq = [0 1 4 6.5 7.5 8.5 11.5 19.5];

u = @(t) (t >= 0);
pulse = @(t, T) (u(t) - u(t - T));
x = @(t, f) (exp(2j*pi*f*t).*u(t));
h = pulse(t, 0.25);
disp(length(h))
% h = h(h ~= 0);
disp(length(h))

figure;
for index = 1 : numel(freq) / 2
    subplot(['41' num2str(index)]);
    plot(t2, dt*abs(conv(x(t, freq(index)), h)));
    title(['Frequency: ' num2str(freq(index))])
    xlim([0 10]);
end

figure;
for index = numel(freq) / 2 + 1 : numel(freq)
    subplot(['41' num2str(index - 4)]);
    plot(t2, dt*abs(conv(x(t, freq(index)), h)));
    title(['Frequency: ' num2str(freq(index))])
    xlim([0 10]);
end

