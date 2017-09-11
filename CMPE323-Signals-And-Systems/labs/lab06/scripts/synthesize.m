function synthesize(waveform, wave_name, K, estimates, t, T, mse, mse_k)

    for i = 1: length(K)

        figure;
        hold on;
        plot(t, estimates(1:end, i), '-r', 'LineWidth', 1, 'DisplayName', 'Synthesized function');
        alpha(0.1);
        plot(t, waveform, '--b', 'LineWidth', 1, 'DisplayName', 'Original function');
        legend('show');
        hold off;
        
        xlabel('Time');
        ylabel('Amplitude');
        title(['$$\hat{', wave_name, '}(t) = \sum_{k=-', num2str(K(i)), '}^{',num2str(K(i)), ...
            '}{c_ke^{j\omega_okt}}$$'], 'Interpreter', 'latex', 'FontSize', 15);

        for j = 1 : length(estimates(1:end, i))
            mse = (waveform(j) - estimates(j, i))^2;
        end
        mse_k(i) = 1/T*sum(mse);

    end

    figure;
    plot(K, mse_k, '-r')
    xlabel('Estimates');
    ylabel('Amplitude');
    title('Mean Squared Error against the K Estimators', 'FontSize', 15);

        figure;
    for i = 1 : length(K)
        hor_plot = 3;
        if i <= hor_plot
            hor_plot = 1;
        end
        hor_plot = 2;
        subplot(['3', num2str(hor_plot), num2str(i)]);
        plot(t, estimates(1:end, i));
        xlim([0.45 0.55]);
        xlabel('Time');
        ylabel(['k = ', num2str(K(i)), ' estimates']);
    end

end