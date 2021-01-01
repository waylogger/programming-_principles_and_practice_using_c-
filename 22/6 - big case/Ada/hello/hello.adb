with Ada.Text_IO; use Ada.Text_IO;


procedure hello is 

	Name : String (1..80);
	Length : Integer :=1;
	
begin
	
	Put("SAY MY NAME!!!");
	new_line(1);
	Get_Line(Name,Length);
	If (Name(1..Length) = "Heisenberg") then
		Put("You are dumn it right");
	else 
		Put("You are deadman");
		new_line(1);
		Put(Name);
	end if;
	
end hello;