% pulse_conv
% creates the pulses to plotted

function pulse_conv(t, x, h, y_int, conv_scale)

    y_hat = zeros(length(t));

    % iterate through the time axis to convolve the functions
    for i = 1 : numel(t)
        for j = 1 : i
            y_hat(i) = y_hat(i) + (x(j) * h(i-j+1));
        end;
    end;

    % figure for plotting the convolution sum and integral
    figure;
    plot_conv(t, x, '$$x(t)$$', '411');
    plot_conv(t, h, '$$h(t)$$', '412');
    plot_conv(t, y_hat, '$$\hat{y} = \sum_{k=-\infty}^{\infty}{x_{k}h_{n-k}}$$', '413');
    plot_conv(t, y_int, '$$y(t) = \int_{-\infty}^{\infty} x(\tau)h(t-\tau) d\tau$$', '414');
    xlabel('Time (s)');

    % figure for plotting the conv method
    figure;
    plot_conv(t, x, '$$x(t)$$', '311');
    plot_conv(t, h, '$$h(t)$$', '312');
    plot_conv([], conv(x, h, conv_scale), 'conv(x, h)', '313');
    xlabel('Time (s)');
    
end