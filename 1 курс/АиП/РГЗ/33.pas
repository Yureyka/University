Program Number3;
Type
  Stroka = array [1..80] of char;
Var 
  t, n, m: integer;
  f: text;
  s:string;
Function count(s:string; f: text): byte;
Var 
  a, str, k, i: integer;
Begin
  k:=0;
  count:=0;
  Assign(f, 'text.txt');
  Reset(f);
  While not eof(f) do
    Begin
      Readln(f, s);
      If s[Length(s)]='z' then
        a:=a+1;
        count:=a;
    End; 
End;
Begin
m:=count(s, f);
Writeln(m);
End.
      