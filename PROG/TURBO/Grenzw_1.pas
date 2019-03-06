program
             grenzwert                                                   ;

uses         crt                                                         ;

const        eps = 1E-5                                                  ;

var          yy   : integer                                              ;
             xx   : real                                                 ;

function     f (n:real):real                                             ;
             begin
             f := sin(1/n) / (1/n)                                       ;
             end                                                         ;

procedure    berechnung  ( var xx : real;var yy : integer )              ;
             begin
                         yy      :=      1                               ;
                repeat   yy      :=   yy+1  until  f(yy+1)-f(yy)<eps     ;                         ;
                         xx      :=  f(yy)                               ;
             end                                                         ;

procedure    ausgabe(xx:real;yy:integer)                                 ;
             begin
             writeln                                                     ;
             writeln ('Im folgenden wird der Grenzwert der Funktion   ') ;
             writeln ('y = sin (1/n) / (1/n)  berechnet               ') ;
             writeln                                                     ;
             writeln ('Der Grenzwert der gegebenen Funktion           ') ;
             writeln ('wurde berechnet mit  ',xx : 15 : 15             ) ;
             writeln                                                     ;
             writeln ('Die Anzahl der Iterationen bei einer Differenz ') ;
             writeln ('von ',eps : 0 , ' betraegt  ', yy               ) ;
             repeat  until  keypressed                                   ;
             end;

begin
            clrscr                                                       ;
            berechnung (xx,yy)                                           ;
            ausgabe (xx,yy)                                              ;
end.