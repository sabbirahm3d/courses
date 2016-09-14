% 3.1.1
omega_s = 100;

t = -5:0.01:5;
sample_cos = cos(2*pi.*t);
figure;
plot(t, sample_cos);
xlabel('time');
ylabel('value');

t = -5:(1/2):5;
sample_cos = cos(2*pi.*t);
figure;
plot(t, sample_cos);
xlabel('time');
ylabel('value');


t = -5:(1/2):5;
sample_cos = sin(2*pi.*t);
figure;
plot(t, sample_cos);
xlabel('time');
ylabel('value');

