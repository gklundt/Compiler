{------------------------------------------------------------------------------------}
{program p018_000 exercises production #018                                          }
{subprogram_head -> FUNCTION ID subprogram_parameters : standard_type ;              }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p018_000;
  function max(a,b:integer):integer;
  begin{max}
    if a>b then max:=a else max:=b
  end{max};
  procedure print(c,d:integer);
    var g:array[1..20] of real;
  begin{print}
    writeln('The maximum of ',c,' and ',d,' is ',max(c,d))
  end{print};
begin{p018_000}
  print(2,3)
end{p018_000}.
