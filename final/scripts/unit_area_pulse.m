function unit_area_pulse(t, tau)

    a = zeros(size(t)); % Preallocating enough memory for y

    region1 = t<tau/2; % First interval
    a(region1) = 0;

    region2 = (-tau/2<=t) & (t<tau/2); % Second interval
    a(region2) = 1/tau;

    region3 = (tau/2<=t); % Third interval
    a(region3) = 0;

    plot(a);

end