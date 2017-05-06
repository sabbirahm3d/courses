------------------------------------------------------------------------------
--
-- Module: DECODER_U38
-- Architecture of PLD used to decode address and control lines to the LEDs
--
------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U38 is
    port (
        A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12_A15, 
            MIO: in STD_LOGIC;
        O1, O2, O8: out STD_LOGIC
    );
end DECODER_U38;

architecture V1 of DECODER_U38 is
begin
    A12_A15 <= A15 or A14 or A13 or A12;
    O1 <= A12_A15 or
          A11 or A10 or A9 or A8 or
          not(A7) or not(A6) or A5 or A4 or
          not(A3) or not(A2) or not(A1) or A0;
    O2 <= A12_A15 or
          A11 or A10 or A9 or A8 or
          not(A7) or not(A6) or A5 or A4 or
          not(A3) or not(A2) or A1 or A0;
    O8 <= A12_A15 or
          A11 or A10 or A9 or A8 or
          not(A7) or not(A6) or A5 or A4 or
          not(A3) or not(A2) or not(A1) or not(A0);
end V1;
