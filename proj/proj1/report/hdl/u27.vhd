------------------------------------------------------------------------------
--
-- Module: DECODER_U27
-- Architecture of PLD used to decode address and control lines to the
-- programmable interval counter
--
------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U27 is
    port (
        A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, 
            A15: in STD_LOGIC;
        O8: out STD_LOGIC
    );
end DECODER_U27;

architecture V1 of DECODER_U27 is
begin
    O8 <= A15 or A14 or A13 or A12 or
          A11 or A10 or A9 or A8 or
          not(A7) or not(A6) or not(A5) or A4 or
          A3;
end V1;
