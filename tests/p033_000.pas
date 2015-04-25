{------------------------------------------------------------------------------------}
{program p033_000 exercises production #033                                          }
{statement -> WHILE expression DO statement                                          }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p033_000;
  var count:integer;
begin{p033_000}
  count:=10;
  while count>=0 do
  begin
    writeinteger(count);
    writestring(', ');
    count:=count-1
  end{while};
  writestring('Blast off!');
  writeln
end{p033_000}.
