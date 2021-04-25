Program LAB4;
Const n=5; m=7;
Type matrix=array [1..n, 1..m] of integer;
Var A: matrix;
    s, p, num, numcon: integer;
Procedure Input (Var A: matrix);
  Var i,j: integer;
  Begin
    Writeln ('Введите значения элементов массива:');
    For i:=1 to n do
      Begin
        For j:=1 to m do
            Readln(A[i,j]); 
        Writeln('---');
      End;
  End;
Procedure Poisk1 (A: matrix; Var s: integer);
  Var i, j: integer;
  Begin 
    s:=0;
    For j:=1 to m do
      For i:=1 to n do
        If (A[i,j]=0) then 
          Begin 
            s:=s+1;
            Break;
          End;
  End;
Procedure Poisk2 (Const A:matrix; Var p, num, numcon:integer);
  Var i, j: integer;
  Begin
    For i:=1 to n do
      Begin
        num:=0;
        numcon:=0;
        For j:=1 to m do
            If (j+1<=m) then
              If (A[i,j]=A[i,j+1]) then num:=num+1;
        If (num>numcon) then 
          Begin 
            numcon:=num;
            p:=i;
          End;
       End;
  End;
Procedure Output (Const A: matrix; Const s, p:integer);
  Var i, j: integer;
  Begin
    For i:=1 to n do
      Begin
        For j:=1 to m do
          Write(A[i,j], '  ' );
        Writeln;
      End;
    Writeln('Количество столбцов хоть с одним нулевым элементом: ', s);
    Writeln('Номер строки с самой длинной серией одинаковых элементов: ',p);
  End;
Begin
  Input(A);
  Poisk1(A, s);
  Poisk2(A, p, num, numcon);
  Output(A, s, p);
End.
  