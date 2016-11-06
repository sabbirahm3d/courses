
for i = 1: length(K)

    figure;
    plot(t, estimates(1:end, i));
    xlim([0.45 0.55]);

end
