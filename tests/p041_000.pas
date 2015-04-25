{------------------------------------------------------------------------------------}
{program p041_000 exercises production #041                                          }
{expression -> simple_expression relop simple_expression                             }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p041_000;
  var b:boolean;
  var i,j:integer;
begin{p041_000}
  b:=true;
  b:=i =  j;
  b:=i <> j;
  b:=i <  j;
  b:=i <= j;
  b:=i >  j;
  b:=i >= j
end{p041_000}.
