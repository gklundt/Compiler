program example;
var x,y,z:integer;
function gcd(a,b:integer):integer;
begin{gcd}
if b=0 then gcd:=a else gcd:=gcd(b,a mod b)
end{gcd};
begin{example}
x:=105; y:=15;
WriteInteger(gcd(x,y),5);
WriteLn
end{example}.

