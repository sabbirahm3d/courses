% 1. MATLAB Practice

% a.
t = 0 : 0.005 : 10;
y_1 = 2 * cos(2*pi.*t);

% verify data type of array generated
class(y_1);

sum_of_y_1 = 0;

for idx = 1:numel(y_1)
    sum_of_y_1 = sum_of_y_1 + y_1(idx);
end

sum_of_y_1 / numel(y_1) == mean(y_1)

% b.
y_1_anon = @(t) (2 * cos(2*pi.*t));
y_1_anon(t);
integral(y_1_anon, 0, 10)