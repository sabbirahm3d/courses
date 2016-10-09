t = -1 : 1/1000: 10;
freq = [0 1 4 6.5 7.5 8.5 11.5 19.5];

u = @(t) (t >= 0);
pulse = @(t, T) (u(t) - u(t - T));
x = @(t, f) (exp(2j*pi*f*t).*u(t));
h = pulse(t, 0.25);

figure;
for index = 1 : numel(freq) / 2
    subplot_mat = ['41' num2str(index)];
    subplot(subplot_mat);
    plot(abs(conv(x(t, freq(index)), h)));
    title(['Frequency: ' num2str(freq(index))])
end

figure;
for index = numel(freq) / 2 + 1 : numel(freq)
    subplot_mat = ['41' num2str(index - 4)];
    subplot(subplot_mat);
    plot(abs(conv(x(t, freq(index)), h)));
    title(['Frequency: ' num2str(freq(index))])
end

