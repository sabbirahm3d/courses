mse = zeros(1, length(t));


for i = 1: length(K)

    figure;
    plot(t, estimates(1:end, i));
%     xlim([0.45 0.55]);
    for j = 1 : length(estimates(1:end, i))
        mse = (x(j) - estimates(j, i))^2;
    end
    1/T*sum(mse)

end
