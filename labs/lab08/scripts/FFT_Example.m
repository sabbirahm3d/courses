% FFT_Example.m
%  EFCL  11/23/2016

pulse = @(t,T) (t>=0)-(t>=T);
 
fsa=1000;
dt=1/fsa;
t=[-4096:4095]*dt; % an array with 2^M points, but starting at M=-4096
NFFT = length(t);
trecord = NFFT*dt; % total measurement time
fresolution = 1/trecord; % the resolution is 1/(measurement time)
df = fresolution; %...which is also the frequency resolution

tau = 1;
p1 = pulse(t+tau/2,tau); % a centered pulse

funshifted=[0:NFFT-1]*df; % FFTs go from 0 to (N-1)df
f = [-NFFT/2: NFFT/2-1]*df;  % centered version
 
P1 = fft(p1)*dt; % multiply by dt to scale to be an integral

figure(1);
subplot(3,1,1);
theory_p1 = tau*sinc(f*tau);
plot(funshifted,abs(P1),f,abs(theory_p1),'r:','LineWidth',2);
ylabel('|P_1(f)|');
xlim([0 fsa]);
legend('|FFT of p_1(t)|','Theory');
grid on;

subplot(3,1,2);
P1 = fftshift(P1); % use fftshift to reorder
plot(f,abs(P1),f,abs(theory_p1),'r:','LineWidth',2); % use the shifted version
ylabel('|P_1(f)|');
xlim([-10 10]);
legend('|FFT of p_1(t)|','Theory');
grid on;

subplot(3,1,3);
% remove erroneous phase shift due to first sample not at t=0
P1adj = exp(1j*2*pi*min(t)*f).*P1;

plot(f,angle(P1adj)/pi,'b',f,angle(theory_p1)/pi,'r:','LineWidth',2);
xlim([-10, 10]);
ylabel('Angle(P1adj)/\pi');
xlabel('Frequency in Hz');

