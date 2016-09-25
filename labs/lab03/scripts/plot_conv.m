function plot_conv(t, func, title_str, filename)

    fig = figure;
    plot(t, func);
    title(title_str, 'Interpreter', 'latex', 'FontSize', 16);
    xlabel('Time (s)');
    ylabel('Units')

    saveas(fig, [filename, '.png'], 'png');

end