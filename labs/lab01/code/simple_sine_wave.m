% 3.1.1
omega_s = 100;
nyquist = 2 * 1;

% part 1
t = -5:(1/omega_s):5;
sample_cos = cos(2*pi*t);

figure;
y1 = plot(t, sample_cos);
title('One Hertz Cosine')
hold on;

t = -5:(1/(100*nyquist)):5;
sample_cos = cos(2*pi*t);

y2 = plot(t, sample_cos);
xlabel('Time (s)');
ylabel('Units');
legend([y1; y2], '100 Hz', '100 times the Nyquist rate')
hold off;

% part 2

t = -5:(1/omega_s):5;
sample_cos = cos(2*pi*t);

figure;
y1 = plot(t, sample_cos);
title('One Hertz Cosine')
hold on;

t = -5:(1/nyquist):5;
sample_cos = cos(2*pi*t);

y2 = plot(t, sample_cos);
xlabel('Time (s)');
ylabel('Units');
legend([y1; y2], '100 Hz', 'Nyquist rate')
hold off;

% part 3

t = -5:(1/omega_s):5;
sample_cos = sin(2*pi*t);

figure;
y1 = plot(t, sample_cos);
title('One Hertz Sine')
hold on;

t = -5:(1/nyquist):5;
sample_cos = sin(2*pi*t);

y2 = plot(t, sample_cos);
xlabel('Time (s)');
ylabel('Units');
legend([y1; y2], '100 Hz', 'Nyquist rate')
hold off;


% part 4

t = -5:(1/omega_s):5;
sample_cos = cos(2*pi*t);

figure;
y1 = plot(t, sample_cos);
title('One Hertz Cosine')
hold on;

t = -5:(1/(0.75*nyquist)):5;
sample_cos = cos(2*pi*t);

y2 = plot(t, sample_cos);
xlabel('Time (s)');
ylabel('Units');
legend([y1; y2], '100 Hz', '0.75 times the Nyquist rate')
hold off;

% part 5

t = -5:(1/omega_s):5;
sample_cos = sin(2*pi*t);

figure;
y1 = plot(t, sample_cos);
title('One Hertz Sine')
hold on;

t = -5:(1/(0.75*nyquist)):5;
sample_cos = sin(2*pi*t);

y2 = plot(t, sample_cos);
xlabel('Time (s)');
ylabel('Units');
legend([y1; y2], '100 Hz', '0.75 times the Nyquist rate')
hold off;
