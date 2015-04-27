{------------------------------------------------------------------------------------}
{program p017_000 exercises production #017                                          }
{subprogram_declaration -> subprogram_head declarations compound_statement           }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p017_000;
  function max(a,b:integer):integer;
  begin{max}
    if a>b then max:=a else max:=b
  end{max};
  procedure print(a,b:integer);
  begin{print}
    writeln('The maximum of ',a,' and ',b,' is ',max(a,b))
  end{print};
begin{p017_000}
  print(2,3)
end{p017_000}.
