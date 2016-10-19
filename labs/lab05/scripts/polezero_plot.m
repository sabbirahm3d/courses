function [  ] = polezero_plot( b,a,s_or_z,ROC)
    % function [  ] = polezero_plot( b,a,s_or_z,ROC)
    % Creates a pole­zero plot in either the s­domain or z­domain based on
    % the M­th order numerator polynomial with coefficients in b and the N­th
    % order denominator polynomial with coefficients in a
    % EFCL 11/5/2014
    %
    % Calling Parameters
    %   b:  1 x (M+1) array of numerator coefficients, with b(1) being the
    %   coefficient of s^(M) and b(M+1) being the coefficient of s^(0)
    %   a:  1 x (N+1) array of denominator coefficients, with a(1) being the
    %   coefficient of s^(N) and a(N+1) being the coefficient of s^(0).
    %   s_or_z:  single character with 's' indicating that the plot is in the
    %   s­plane and 'z' indicating the plot is in the z­plane (used for
    %   discrete­time systems).  Any other input is invalid.
    %   ROC:  1 x 2 array [ROCmin ROCmax] indicating the Region of Convergence.
    %   values of +/­Inf are accceptable
    %
    % This first version should display an error message with no other output
    % if s_or_z = 'z', that is, the z­plane implementation will be provided at
    % a later time.

    if s_or_z == 'z'
        error('Z-plane not implemented yet');

    elseif s_or_z == 's'

        zeros_ = roots(b);
        poles_ = roots(a);
        data_points = cat(1, zeros_, poles_);

        [~, idx] = sort(imag(data_points));
        sorted_imag = imag(data_points(idx));

        [im_min, im_max] = deal(sorted_imag(1) - 1, sorted_imag(end) + 1);

        hold on;

        positive_area = area(ROC, [im_max, im_max]);
        negative_area = area(ROC, [im_min, im_min]);
        set(positive_area, 'FaceColor', 'g');
        set(negative_area, 'FaceColor', 'g');
        alpha(0.5);

        plot(zeros_, 'or');
        plot(poles_, 'xb');
        ylabel('$$\j\omega=Im(s)$$', 'Interpreter', 'latex', 'FontSize', 18);
        xlabel('$$\sigma=Re(s)$$', 'Interpreter', 'latex', 'FontSize', 18);
        title('Pole-Zero Plot', 'FontSize', 16);

        hold off;

    else
        error('Select a valid plane to plot');

    end

end