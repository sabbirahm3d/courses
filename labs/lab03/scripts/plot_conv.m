function plot_conv(t, func, title_str, filename)

    subplot(['31', filename])
    plot(t, func);
    title(title_str, 'Interpreter', 'latex', 'FontSize', 16);
    ylabel('Units')

end