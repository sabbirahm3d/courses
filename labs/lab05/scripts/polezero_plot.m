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
    %

    coef = @(c, i, s) (c*s^i);

    syms s;
    numerator = poly2sym(b, s);
    denominator = poly2sym(a, s);
    H = (numerator/denominator);
    
    h = matlabFunction(H);
    t = -10:1/1000:50;
    plot(h(t))
    
end