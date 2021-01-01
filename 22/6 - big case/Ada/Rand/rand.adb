with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Numerics.Discrete_Random;


procedure rand is
val, score , step: Integer := 0;
type Rand_Range is range 1..6;
package Rand_Int is new Ada.Numerics.Discrete_Random(Rand_Range);
seed : Rand_Int.Generator;
Num : Rand_Range;
s : String (1..80);
begin
while score < 10 loop
Put("Drop");
new_line(1);
Get_Line(s,step);
Rand_Int.Reset(seed);

Num := Rand_Int.Random(seed);

Put_Line(Rand_Range'Image(Num));

score := score +1;
end loop;
Get_Line(s,step);
new_line(1);
end rand;