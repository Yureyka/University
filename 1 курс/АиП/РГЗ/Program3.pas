Program Zadacha1;
Const n=5; m=3;
Type 
  mass = array [1..n,1..m] of integer;
  vec = array [1..m] of integer;
Var A:mass; B:vec;
Procedure Zadacha (A:mass; B:vec);
 Var i, j, k, l, t: byte;
 Begin
  For i:=1 to n do
    For j:=1 to m do
      Readln(A[i,j]);
  Writeln;
  Readln(k,l);
  For i:=1 to m do 
    Begin
      t:=A[k,i];
      A[k,i]:=A[l,i];
      A[l,i]:=t;
    End;       
For i:=1 to n do
  Begin
    For j:=1 to m do
      Write(A[i,j],' ');
    Writeln;
  End;

End;
Begin
Zadacha(A, B);
End.
    
      
  
  
  