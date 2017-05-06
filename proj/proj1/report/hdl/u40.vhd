------------------------------------------------------------------------------
--
-- Module: DECODER_U40
-- Architecture used to decode address and control lines to the LCD and DIP 
-- switches
--
------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U40 is
    port (
        A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12_A15, 
            MIO: in STD_LOGIC;
        O1, O8: out STD_LOGIC
    );
end DECODER_U40;

architecture V1 of DECODER_U40 is
begin
    A12_A15 <= A15 or A14 or A13 or A12;
    O1 <= A12_A15 or
          A11 or A10 or A9 or A8 or
          not(A7) or not(A6) or A5 or A4 or
          not(A3) or A2 or not(A1) or A0;
    O8 <= A12_A15 or
          A11 or A10 or A9 or A8 or
          not(A7) or not(A6) or A5 or not(A4) or
          A3 or A0;
end V1;
