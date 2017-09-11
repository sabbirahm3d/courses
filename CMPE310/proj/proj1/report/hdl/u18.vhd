------------------------------------------------------------------------------
--
-- Module: DECODER_U18
-- Architecture used to decode address and control lines to the PPI chips
--
------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;

entity DECODER_U18 is
    port (
        A12_A15, A3, A4, A5, A6, A7, A8, A9, A10, A11, MIO: in STD_LOGIC;
        PPI1, PPI2, PPI3: out STD_LOGIC
    );
end DECODER_U18;

architecture V1 of DECODER_U18 is
begin
    A12_A15 <= A15 or A14 or A13 or A12;
    PPI1 <= A12_A15 or
            A11 or A10 or A9 or A8 or
            A7 or A6 or A5 or A4 or
            not(A3) or not(A0) or not(MIO);
    PPI2 <= A12_A15 or
            A11 or A10 or A9 or A8 or
            A7 or A6 or A5 or A4 or
            not(A3) or A0 or not(MIO);
    PPI3 <= A12_A15 or
            A11 or A10 or A9 or A8 or
            A7 or A6 or A5 or A4 or
            A3 or not(A0) or not(MIO);
end V1;
