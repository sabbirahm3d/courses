------------------------------------------------------------------------------
--
-- Module: DECODER_U14
-- Architecture used to decode address and control lines to the SRAM
--
------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U14 is
    port (
        A0, A16, A17, WR, BHE, MIO: in STD_LOGIC;
        O1, O2, O3, O4: out STD_LOGIC
    );
end DECODER_U14;

architecture V1 of DECODER_U14 is
begin
    O1 <= not(A17) or not(A16) or A0 or not(WR) or not(BHE) or not(MIO);
    O2 <= not(A17) or A16 or A0 or not(WR) or not(BHE) or not(MIO);
    O3 <= A17 or not(A16) or A0 or not(WR) or not(BHE) or not(MIO);
    O4 <= A17 or A16 or A0 or not(WR) or not(BHE) or not(MIO);
end V1;
