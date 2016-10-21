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

    % Throw an error if option for plotting on the z-plane is selected
    if s_or_z == 'z'
        error('Z-plane not implemented yet');

    elseif s_or_z == 's'

        % zeros and poles from the coefficients
        zeros_ = roots(b);
        poles_ = roots(a);

        % sort all the roots by their imaginary parts to determine the
        % bounds on the imaginary axis
        data_points = cat(1, zeros_, poles_);
        [~, idx] = sort(imag(data_points));
        sorted_imag = imag(data_points(idx));

        % lower and upper bound of the imaginary axis
        [im_min, im_max] = deal(ceil(sorted_imag(1)) - 1, ceil(sorted_imag(end)) + 1);

        [re_min, re_max] = deal(ROC(1), ROC(end));

        % special conditions for infinite bounds of the region of
        % convergence
        zoom = 0;  % determines if the real axis needs to be manipulated
        if any(ROC == -inf) || any(ROC == inf)
            [~, idx] = sort(real(data_points));
            sorted_real= real(data_points(idx));
            zoom = 1;
            if any(ROC == -inf)
                [re_min, re_max] = deal(ceil(sorted_real(1)) - 1, ROC(end));
            end
            if any(ROC == inf)
                [re_min, re_max] = deal(ROC(1), ceil(sorted_real(end)) + 3);
            end
        end
        
        figure;
        hold on;

        % shading the region of convergence
        positive_area = area([re_min, re_max], [im_max, im_max]);
        negative_area = area([re_min, re_max], [im_min, im_min]);
        % additional settings for the region of convergence
        set(positive_area, 'FaceColor', 'g');
        set(negative_area, 'FaceColor', 'g');
        alpha(0.5);

        % plot the zeros and plots on the same plot
        plot(zeros_, 'or');
        plot(poles_, 'xb');

        % if zooming in is required to fit the region of convergence
        if zoom
            xlim([re_min - 1, re_max]);
        end

        % convert the coefficients into a symbolic polynomial, casted into
        % LaTex formatted string to be used for the title of the plot
        syms s;
        poly_equ = latex(poly2sym(b, s) / poly2sym(a, s));
        title_str = ['$$H(s)=', poly_equ, '$$'];

        % labels for the plot
        ylabel('$$\j\omega=Im(s)$$', 'Interpreter', 'latex', 'FontSize', 18);
        xlabel('$$\sigma=Re(s)$$', 'Interpreter', 'latex', 'FontSize', 18);
        title(title_str, 'Interpreter', 'latex', 'FontSize', 16);

        hold off;

    % throw an error if an invalid option for plane is selected
    else
        error('Select a valid plane to plot');

    end

end