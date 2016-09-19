function plot_components = plot_components(f, t)

    figure;
    subplot(311);
    plot(t, f(t))
    title('f(t)');
    subplot(312);
    plot(t, f(-t));
    title('f(-t)');
    subplot(313);
    plot(t, -f(-t));
    title('-f(-t)');

end