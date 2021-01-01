with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;



procedure nuts is
subtype Sub_int is Integer range 0..10000;

Nuts, squirrel : Sub_int;
To_end : String (1..1);
count : Integer := 0;

begin
Put("Number of nuts");
new_line(1);
Get(Nuts);
Put("Number of squish");
new_line(1);
Get(squirrel);
new_line(1);

while (Nuts >= squirrel) loop
Put("We have - ");
Put(Nuts);
Put(" of nuts");
new_line(1);
Put(squirrel);
Put(" of squirrel, take by one nuts");
new_line(1);
Nuts := Nuts - squirrel;
Put(Nuts);
Put(" is rest");
new_line(1);
end loop;

Get(To_end);

end nuts;