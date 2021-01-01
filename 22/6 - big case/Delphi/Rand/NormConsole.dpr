program NormConsole;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
s : String;
val, count : Integer;
begin

 for count := 1 to 10 do
  begin
  Randomize;
  val := random(6);
  WriteLn(val);

  end;
        ReadLn
end.
