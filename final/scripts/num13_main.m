b = [1 2 5];
a = [1.0000 7.0000 14.8125 12.8750 6.5000];

w_c = 2*pi*10e3;



% polezero_plot(b,a,'s',[-1 inf]);

w = logspace(-1,2);
figure;
freqs(b,a,w);
