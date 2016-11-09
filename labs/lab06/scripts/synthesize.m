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

        figure;
        plot(t, estimates(1:end, i));
        xlim([0.45 0.55]);
        xlabel('Time');
        ylabel('Amplitude');
        title(['Gibbs Phenomenon demonstration of k=', num2str(K(i))], 'FontSize', 15);

        for j = 1 : length(estimates(1:end, i))
            mse = (waveform(j) - estimates(j, i))^2;
        end
        mse_k(i) = 1/T*sum(mse);

    end

    figure;
    plot(K, mse_k, '-r')
    xlabel('K Estimates');
    ylabel('Amplitude');
    title('Mean Squared Error against the K Estimators', 'FontSize', 15);
end