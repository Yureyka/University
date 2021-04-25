Program IntegralSinus; 
Const  MaxIter = 500;   
Var Si, y: real;          
    x, xi, x1, x2, dx, eps: real;               
    n, m: integer; 
Begin   
  Writeln('¬ведите начальный и конечный аргументы, точность и шаг:');  
  Readln(x1, x2, eps, dx);
  writeln('|------------------------------|');
  writeln('|----x----|----Si----|----n----|');
  writeln('|------------------------------|');
  Si:=x1;        
  y:=Si;   
  x:=x1;
  n:=0;  
  While x<=x2 do
    Begin
     While abs(Si)>=eps do 
      Begin
        Si:=Si*(((-1)*(sqr(x))*(2*n+1))/((2*n+3)*(2*n+2)*(2*n+3)));        
        n:=n+1;
        y:=y+Si;
        If n>MaxIter then                  
          Begin                      
            Writeln('–€д расходитс€!');                                           
            Break;                  
          End;           
      End;
      writeln('|',x:9:3,'|',y:10:6,'|',n:9,'|');
      x:=x+dx;
      Si:=x;
      y:=Si;
      n:=0;
    End;
writeln('|------------------------------|');  
End.