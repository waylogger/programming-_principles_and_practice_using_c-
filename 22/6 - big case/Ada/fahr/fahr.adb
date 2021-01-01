With Ada.Text_IO; use Ada.Text_IO;
With Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure fahr is
count, fahren, cels, low, upper, step : Integer;
s : String(1..80);


begin
upper := 300;
step := 20;
low := 0;
fahren := low;

while fahren <= upper loop

cels := 5 * (fahren - 32) /9;

Put("In "); Put(fahren);
Put(" - "); Put(cels); Put(" of cels");
new_line(1);
fahren := fahren + step;
end loop;

Get_line(s,count);

end fahr;