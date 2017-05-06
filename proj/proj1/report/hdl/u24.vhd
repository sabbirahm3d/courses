------------------------------------------------------------------------------
--
-- Module: DECODER_U24
-- Architecture used to decode address and control lines to the
-- programmable interval counter
--
------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U24 is
    port (
        A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, 
            A15: in STD_LOGIC;
        O8: out STD_LOGIC
    );
end DECODER_U24;

architecture V1 of DECODER_U24 is
begin
    O8 <= not(A15) or not(A14) or not(A13) or not(A12) or
          not(A11) or not(A10) or not(A9) or not(A8) or
          not(A7) or not(A6) or not(A5) or A4 or
          not(A3) or A2;
end V1;
