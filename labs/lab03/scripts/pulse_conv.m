function pulse_conv(t, x, h)

    y_hat = zeros(length(t));

    for i = 1 : numel(t)
        for j = 1 : (i)
            y_hat(i) = y_hat(i) + (x(j) * h(i-j+1));
        end;
    end;

    figure;
    plot_conv(t, x, '$$x(t)$$', '1');
    plot_conv(t, h, '$$h(t)$$', '2');
    plot_conv(t, y_hat, '$$\hat{y} = \sum_{k=-\infty}^{\infty}{x_{n-k}h_{k}}$$', '3');
    xlabel('Time (s)');

end