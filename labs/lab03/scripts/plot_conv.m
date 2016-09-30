% plot_conv
% helper function to plot and title functions

function plot_conv(t, func, title_str, plot_mat)

    subplot(plot_mat);

    % the t input is optional
    if ~isempty(t)
        plot(t, func);
    else
        plot(func);
    end
    
    % parse the title in LaTex
    title(title_str, 'Interpreter', 'latex', 'FontSize', 16);
    ylabel('Units')

end