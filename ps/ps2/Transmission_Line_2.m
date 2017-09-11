% Transmission_Line_2
%
% This routine calculates the transient response of a pulsed
% transmission line.  SI units are used.  (Paul, Example 6.2)

% LINE PARAMETERS
length = 400;             % transmission line length
Z_0 = 50;                 % characteristic impedance
velocity = 2e8;           % propagation velocity

% GENERATOR AND LOAD PARAMETERS
Z_g = 100;                % input impedance
V_g = 100;                % input voltage
t_D = 6e-6;               % pulse duration
Z_L = 0;                  % load impedance

Total_Time = 20e-6;       % total time for the plot

Delta = 0:0.001:1.0;  tinc = 0.001*Total_Time;
Ndelay = round(t_D/tinc);
Ccomp = zeros(1,Ndelay);
time = Delta*Total_Time;   % the time axis is cut into increments
T = length/velocity;       % the transit time is calculated

% Time-independent coefficients
Gamma_g = (Z_g - Z_0)/(Z_g + Z_0);   % generator reflection coefficient
Gamma_L = (Z_L - Z_0)/(Z_L + Z_0);   % load reflection coefficient
I_fac = V_g/(Z_g + Z_0);             % current factor
V_fac = Z_0*I_fac;                   % voltage factor
C_f = Gamma_g*Gamma_L;               % concatenation coefficent

% Time-independent coefficients
Gamma_g = (Z_g - Z_0)/(Z_g + Z_0);   % generator reflection coefficient
Gamma_L = (Z_L - Z_0)/(Z_L + Z_0);   % load reflection coefficient
I_fac = V_g/(Z_g + Z_0);             % current factor
V_fac = Z_0*I_fac;                   % voltage factor
C_f = Gamma_g*Gamma_L;               % concatenation coefficent

% Time-dependent coefficients
M_g = floor(0.5*time/T);             % bounce number at the generator
M_L = floor(0.5*(time+T)/T);         % bounce number at the load
C_vec_g = C_f.^M_g;                  % generator concatenation vector
C_vec_L = C_f.^M_L;                  % load concatenation vector

% Time-dependent load and generator currents and voltages
I_vec_g = I_fac*(1.0 - C_f*C_vec_g ...
    - Gamma_L*(1.0 - C_vec_g))./(1.0 - C_f);  % generator current
I_vec_g = I_vec_g - [Ccomp, I_vec_g(1:1001-Ndelay)]; % back subtraction

V_vec_g = V_fac*(1.0 - C_f*C_vec_g ...
    + Gamma_L*(1.0 - C_vec_g))./(1.0 - C_f);  % generator voltage
V_vec_g = V_vec_g - [Ccomp, V_vec_g(1:1001-Ndelay)];  % back subtraction
    
I_vec_L = I_fac*((1.0 - Gamma_L)*(1.0 - C_vec_L))./(1.0 - C_f);
I_vec_L = I_vec_L - [Ccomp, I_vec_L(1:1001-Ndelay)];  % load current
                                              
V_vec_L = V_fac*((1.0 + Gamma_L)*(1.0 - C_vec_L))./(1.0 - C_f);
V_vec_L = V_vec_L - [Ccomp, V_vec_L(1:1001-Ndelay)];  % load voltage

% Plotting
figure;
subplot(2,2,1), plot(time,I_vec_g, '-r','LineWidth',2); 
    title('Generator Current'), xlabel('time (sec)'), 
    ylabel('current (amps)'), axis([0.0, Total_Time, -0.5, 1.5])
subplot(2,2,2), plot(time,V_vec_g,'LineWidth',2); 
    title('Generator Voltage'), xlabel('time (sec)'), 
    ylabel('voltage (volts)'), axis([0.0, Total_Time, -50, 50])
subplot(2,2,3), plot(time,I_vec_L, '-r', 'LineWidth',2); 
    title('Load Current'), xlabel('time (sec)'), 
    ylabel('current (amps)'), axis([0.0, Total_Time, -0.5, 1.5])
subplot(2,2,4), plot(time,V_vec_L,'LineWidth',2); 
    title('Load Voltage'), xlabel('time (sec)'), 
    ylabel('voltage (volts)'), axis([0.0, Total_Time, -50, 50])
