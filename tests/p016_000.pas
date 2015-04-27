{------------------------------------------------------------------------------------}
{program p016_000 exercises production #016                                          }
{subprogram_declarations -> subprogram_declarations subprogram_declaration ;         }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p016_000;
  function max(a,b:integer):integer;
  begin{max}
    if a>b then max:=a else max:=b
  end{max};
  procedure print(a,b:integer);
  begin{print}
    writeln('The maximum of ',a,' and ',b,' is ',max(a,b))
  end{print};
begin{p016_000}
  print(2,3)
end{p016_000}.
