Program Number3;
Var 
  t, n, m: integer;
  f: text;
Function count(f: text): byte;
Var 
  s:char;
  a, str: integer;
Begin
  count:=0;
  Assign(f, 'text.txt');
  Reset(f);
  While not eof do
    Begin
      Readln(f, s);
      str:=length(s);
      If s[str]='z' then
        a:=a+1;
        count:=a;
    End; 
End;
Begin
m:=count(f);
Writeln(m);
End.
      