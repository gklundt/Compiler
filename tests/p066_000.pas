{------------------------------------------------------------------------------------}
{program p066_000 exercises production #066                                          }
{factor -> ( expression )                                                            }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p066_000;
  var c:real;
  function celsius(f:real):real;
  begin{celsius}
    celsius:=5*(f-32)/9.0
  end{celsius};
begin{p066_000}
  c:=celsius(77)
end{p066_000}.
