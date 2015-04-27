{------------------------------------------------------------------------------------}
{program p058_000 exercises production #058                                          }
{mulop -> *                                                                          }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p058_000;
  var i,j,k:integer;
  var r,s,t:real;
  var b,c,d:boolean;
begin{p058_000}
  b:=true;c:=true;d:=true;
  i:=1;j:=2;k:=3;
  r:=1.0;s:=2.0;t:=3.0;
  i:=j*k;
  r:=s/t;
  i:=j div k;
  i:=j mod k;
  b:=c and d
end{p058_000}.
