program nuts;

{$APPTYPE CONSOLE}

uses
SysUtils;
var
numnuts,sq : Integer;
begin
WriteLn('Hello, my forest friend');
WriteLn('so, do you see heap of nuts?');
WriteLn('please, tell me number of nuts in heap');
ReadLn(numnuts);
WriteLn('Thank you!');
WriteLn('CAUTION!!! Army of squirrel is coming');
WriteLn('Tell me number of squirrel in this squad');
ReadLn(sq);
WriteLn('O my God, all its lost');
WriteLn('No panic! We are have');
Write(numnuts);
WriteLn(' of nuts');
while numnuts >= sq do
	begin
	Write(sq);
	Write(' of squirrel take by one nut - ');
	numnuts := numnuts - sq;
	Write(numnuts);
	Write(' - nuts of rest');
	WriteLn
	end;
	
WriteLn('So, not bad, now we are have - '); Write(numnuts); 
WriteLn(' of nuts, lets eat!!!!');
ReadLn;
end.