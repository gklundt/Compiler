program example(input,output);
  var x,y:integer;
  function gcd(a,b:integer):integer;
  begin{gcd}
    if (b=0) then gcd:=a else gcd:=gcd(b,a mod b)
  end{gcd};
begin{example}
  readinteger(x);
  readinteger(y);
  writeinteger(gcd(x,y),5)
end{example}.

