{------------------------------------------------------------------------------------}
{program p038_000 exercises production #038                                          }
{expression_list -> expression                                                       }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p038_000;
  function max(a,b:integer):integer;
  begin{max}
    if a>b then max:=a else max:=b
  end{max};
  procedure print(a:integer;b:integer);
  begin{print}
    writestring('The maximum of ');
    writeinteger(a);
    writestring(' and ');
    writeinteger(b);
    writestring(' is ');
    writeinteger(max(a,b));
    writeln
  end{print};
begin{p038_000}
  print(2,3)
end{p038_000}.
