program FahrToCels;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
upper, lower, step, fahr : Integer;
     celsus : integer;
     x : Extended;
     inpcel, inpfahr : String;

begin
lower := 0;
fahr := lower;
upper :=300;
step :=20;
while fahr <= upper do
  begin
  x:= 5*(fahr-32)/9;
  celsus := Round(x);
  inpcel := IntToStr(celsus);
  inpfahr := IntToStr(fahr);
  WriteLn('In ' + inpcel + ' celsus, - ' + inpfahr + ' fahrenheit');
  fahr := fahr + step;
  end;
 ReadLn;
  
end.
