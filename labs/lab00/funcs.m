% Exponential Growth
n = 1;
r = 0.6931;
t_1 = 0:1:10;
growth = n*exp(r.*t_1);

% Exponential decaying solution
alpha = 0.7;
omega = 1.0;
omegaD = sqrt(omega^2 - alpha^2);
t_2 = 0:0.1:10;
natural_response = 2*cos(omegaD.*t_2) - 1.5*sin(omegaD.*t_2);

% Complex Exponential
t_3 = 0 : 0.1 : 5;
complex_exp_1 = exp(1j*0.71.*t_3);
complex_exp_2 = exp(-1j*0.71.*t_3);

diary diary_file.txt
disp('3.1.1')
growth
disp('3.1.2')
natural_response
disp('3.1.3')
complex_exp_1
complex_exp_2
diary off