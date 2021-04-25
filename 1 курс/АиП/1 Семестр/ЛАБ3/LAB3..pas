Program LAB3;
Const n=10;
Var
    i, nul1, nul2, j, k, na, nb : integer;
    A : array [1..n] of real;
    sum, mult, x : real;
Begin 
    na:=0; nb:=0;
    Writeln('Введите ', n, ' элементов массива');
    mult:=1;
    sum:=0;
    For i:=1 to n do Read(A[i]); Writeln;
    For i:=1 to n do
      If (i mod 2 = 0) then
        Begin 
            mult:=mult*A[i]; 
            Write(mult, ' ');
        End;
    Writeln; Writeln('------------------------------------------------');
    For i:=n downto 1 do
      Begin
        If (A[i]=0) then nul1:=i;
      End;
    For i:=1 to n do
      If (A[i]=0) then nul2:=i;
    For i:=nul1+1 to nul2-1 do
      sum:=sum+A[i];
    For i:=1 to n-1 do  
      Begin 
          k:=i; 
          x:=A[i]; 
          For j:=i+1 to n do                     
            If A[j]>x then 
             Begin
                 k:=j; 
                 x:=A[k];
                 na:=na+1;
             End; 
            A[k]:=A[i]; 
            A[i]:=x;
            nb:=nb+1;
      End; 
    Writeln('Сумма элементов между крайними нулями = ', sum, '   ', 'Произведение четных элементов = ', mult);
    Writeln('------------------------------------------------');
    For i:=1 to n do 
      Begin
          Write(A[i]);
          Write(' ');
      End;
      Writeln (na, '   ', nb);
End.