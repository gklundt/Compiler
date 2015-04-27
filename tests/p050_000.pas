{------------------------------------------------------------------------------------}
{program p050_000 exercises production #050                                          }
{simple_expression -> simple_expression addop term                                   }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p050_000;
  var i,j,k:integer;
  var r,s,t:real;
  var b,c,d:boolean;
begin{p050_000}
  i:=1;j:=2;k:=3;
  r:=1.0;s:=1.0;t:=2.0;
  b:=false;c:=true;d:=false;
  i:=+j;
  i:=-j;
  i:=j+k;
  r:=j+t;
  r:=s+k;
  r:=s+t;
  i:=j-k;
  r:=j-t;
  r:=s-k;
  r:=s-t;
  b:=c or d
end{p050_000}.
