function ghetto_plot(x, dt, t, t2, freq, h, xlimit)

    figure;
    for index = 1 : numel(freq) / 2

        subplot(['41' num2str(index)]);
        y = dt*abs(conv(x(t, freq(index)), h));

        plot(t2, y);
        title(['Frequency: ' num2str(freq(index)) ' Hz'] , 'FontSize', 16)
        if xlimit
            xlim([0 10])
        end
        ylabel('Units')
    end

    figure;
    for index = numel(freq) / 2 + 1 : numel(freq)
        subplot(['41' num2str(index - 4)]);
        y = dt*abs(conv(x(t, freq(index)), h));

        plot(t2, y);
        title(['Frequency: ' num2str(freq(index)) ' Hz'] , 'FontSize', 16)
        if xlimit
            xlim([0 10])
        end
        ylabel('Units')
    end
    xlabel('Time (s)')
    
end