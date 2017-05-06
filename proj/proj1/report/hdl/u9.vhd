library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U9 is
    port (
        A0, A12, A13, A14, A15, A18, A19, WR, RD, MIO, BHE: in STD_LOGIC;
        A0xA12_A15, A12_A15, IORC, IOWC, O2, O1: out STD_LOGIC;
    );
end DECODER_U9;

architecture V1 of DECODER_U9 is
begin
    A0xA12_A15 <= A15 or A14 or A13 or A12 or A0;
    A12_A15 <= A15 or A14 or A13 or A12;
    IORC <= RD or MIO;
    IOWC <= WR or MIO;
    O2 <= A19 or A18 or A15 or A14 or A13 or A12 or A0;
    O1 <= A19 or A18 or A15 or A14 or A13 or A12 or not(A0);
end V1;
