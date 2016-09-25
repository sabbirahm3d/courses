function pulse_conv(t, x, h, sec)

    y_hat = zeros(length(t));

    for i = 1 : numel(t)
        for j = 1 : (i)
            y_hat(i) = y_hat(i) + (x(j) * h(i-j+1));
        end;
    end;

    plot_conv(t, x, '$$x(t)$$', ['3.', sec, '_1']);
    plot_conv(t, h, '$$h(t)$$', ['3.', sec, '_2']);
    plot_conv(t, y_hat, '$$\hat{y} = \sum_{k=-\infty}^{\infty}{x_{n-k}h_{k}}$$', ['3.', sec, '_3']);

end