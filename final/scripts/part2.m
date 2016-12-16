% import global variables    
settings_2;

plot_fft(d(t), theory_d(f), 'p_{1}', '$$\tau sinc(f\tau)$$');
plot_fft(c(t).*d(t), theory_d(f), 'p_{1}', '$$\tau sinc(f\tau)$$');
