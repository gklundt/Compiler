{------------------------------------------------------------------------------------}
{program p055_000 exercises production #055                                          }
{addop -> OR                                                                         }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p055_000;
  var i,j,k:integer;
  var b,c,d:boolean;
begin{p055_000}
  i:=1;j:=2;k:=3;
  b:=false;c:=true;d:=false;
  i:=+j;
  i:=-j;
  i:=j+k;
  i:=j-k;
  b:=c or d
end{p055_000}.
