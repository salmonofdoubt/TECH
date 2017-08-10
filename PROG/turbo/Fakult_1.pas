program
             fakultaet(input,output)                                     ;
{$N+}

uses         crt                                                         ;

var          yy:double                                                   ;
             xx:integer                                                  ;

procedure    abfrage(var xx:integer)                                     ;
             begin
               writeln                                                   ;
               write   ('Geben sie eine natuerliche Zahl ein   ')        ;
               readln  (xx)                                              ;
             end                                                         ;

procedure    berechnung(xx:integer;var yy:double)                        ;
             var   i:integer                                             ;
             begin
                   yy    :=1                                             ;
               for i     :=1  to  xx  do
                   yy    :=i * yy                                        ;
             end                                                         ;

procedure    ausgabe(xx,yy:double)                                       ;
             begin
             writeln                                                     ;
             writeln('Die Fakultaet der gegebenen Zahl      ',xx:0:0)    ;
             writeln;
             writeln('wurde berechnet mit                   ',yy:0:0)    ;
             repeat until keypressed                                     ;
             end;

begin
            clrscr                                                       ;
            abfrage (xx)                                                 ;
            berechnung (xx,yy)                                           ;
            ausgabe (xx,yy)                                              ;
end.