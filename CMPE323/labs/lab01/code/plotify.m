function plotify = plotify(p, t, T, f, plot_title)

figure;
pulse_plot = plot(t, p);
hold on;
find_non_zero = plot(f, T, 'o','MarkerSize', 10);
title(plot_title);
ylabel('Units');
xlabel('Time (s)');
legend([pulse_plot; find_non_zero], 'Unit pulse', 'First non-zero value')
