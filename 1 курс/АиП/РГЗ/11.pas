Program Zad2;
Const
  n = 2;
Type
  data = record 
    name: string[30];
    pol: char;
    rost: 140..200 
         end;
  gruppa = array [1..n] of data;
Var 
  gr: gruppa;

Procedure Proc(Var gr: gruppa; max: integer);
  Var
    i: integer;
  Begin
    max:=0;
    For i:=1 to n do
      Begin
        Writeln('������� ��� ���������');
        Readln(gr[i].name);
        Writeln('������� ��� ���������');
        Readln(gr[i].pol);
        Writeln('������� ���� ���������');
        Readln(gr[i].rost);
      End;
    For i:=1 to n do
      If gr[i].pol='M' then
        If max<gr[i].rost then
            max:=gr[i].rost;
    Writeln('������������ ������� ���� � ������: ', max);
  End;
Begin
  Proc(gr, max);
End.

