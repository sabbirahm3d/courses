library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U14 is
    port (
        A0, A16, A17, WR, BHE, MIO: in STD_LOGIC;
        O4, O3, O2, O1: out STD_LOGIC;
    );
end DECODER_U14;

architecture V1 of DECODER_U14 is
begin
    O4 <= not(A17) or not(A16) or A0 or WR or BHE or MIO
    O3 <= not(A17) or A16 or A0 or WR or BHE or MIO
    O2 <= A17 or not(A16) or A0 or WR or BHE or MIO
    O1 <= A17 or A16 or A0 or WR or BHE or MIO
end V1;
