{------------------------------------------------------------------------------------}
{program p065_000 exercises production #065                                          }
{factor -> ID ( expression_list )                                                    }
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
  function max(a,b:integer):integer;
  begin{max}
    if a>b then max:=a else max:=b
  end{max};
begin{p065_000}
  i:=max(3,4)
end{p065_000}.
