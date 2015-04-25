{------------------------------------------------------------------------------------}
{program p065_000 exercises production #065                                          }
{factor -> ID ( expression_list )                                                    }
{Standard functions                                                                  }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p065_000;
  var i:integer;
  var r:real;
  var c:char;
begin{p065_000}
  i:=2;
  i:=succ(i);
  i:=pred(i);
  r:=3.14159;
  i:=round(r);
  c:='b';
  r:=sqrt(r);
  r:=sqrt(i);
  r:=abs(r);
  i:=abs(i);
  i:=trunc(r);
  c:=chr(97);
  i:=ord('b')
end{p065_000}.
