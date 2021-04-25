Program LAB8;
Uses Crt;
Type
  zap = Record 
          fio:string[20];
          year:string[12];
          sex:char;
          sp:string[15];
          cn:byte;
          sal:integer;
        End;
  tree = ^tr;
  tr = Record
          data: Zap;
          left, right: tree
         End;
Var
  top: Tree;
  z: zap;
  level, n, i: integer;
  num: integer;

Function AddTree(top: tree; newnode: zap): Tree;
Begin
  If top = nil then
    Begin
      New(top);
      top^.data := newnode;
      top^.left := nil;
      top^.right := nil;
    End
  else
    If top^.data.fio > newnode.fio then
      top^.left := AddTree(top^.left, newnode)
    else
      top^.right := AddTree(top^.right, newnode);
  Addtree := top
End;
{---------------------------------------------------}
Procedure CreateTree;
Begin
  Writeln('����������� ��������� ����������� ������');
  Writeln('��� ������ �� ��������� ������� "*" ');
  Writeln('------------------------------------------');
  top := nil;
  While True do
    Begin
      Writeln('������� ��� ����������:');
      Readln(z.fio);
      If z.fio='*' then Exit;
      Writeln('������� ���� �������� � ��� ����������:');
      Readln(z.year);
      Readln(z.sex);
      Writeln('������� �������� ��������� � ���������� ����� ���������� ����������:');
      Readln(z.sp);
      Readln(z.cn);
      Writeln('������� ����� ����������:');
      Readln(z.sal);
      top := AddTree(top, z);
    End
End;
{--------------------------------------------------------}
Procedure AddL;
Begin
  Writeln('����������� ��������� ���������� �����');
  Writeln('��� ������ �� ��������� ������� "*" ');
  Writeln('---------------------------------------------');
  Writeln('������� ��� ����������:');
  Readln(z.fio);
  If z.fio='*' then Exit;
  Writeln('������� ���� �������� � ��� ����������:');
  Readln(z.year);
  Readln(z.sex);
  Writeln('������� �������� ��������� � ���������� ����� ���������� ����������:');
  Readln(z.sp);
  Readln(z.cn);
  Writeln('������� ����� ����������:');
  Readln(z.sal);
  Top := Addtree(Top, Z);
End;
{----------------------------------------------------------}
Procedure View(top: tree);
Begin
  If top <> nil then
    Begin
      View(top^.left);
      Writeln(i,' ',top^.data.fio,' ',top^.data.year,' ',top^.data.sex,' ',top^.data.sp,' ',top^.data.cn,' ',top^.data.sal);
      i := i + 1;
      View(top^.right)
    End;
End;
{---------------------------------------------------------------}
Procedure St(top: tree; o: integer);
Begin
  If top <> nil then
    Begin
      o := o + 3;
      St(top^.right, o);
      Writeln(' ':o, top^.data.fio);
      St(top^.left, o);
    End
End;
{---------------------------------------------------------------}
Procedure NC(top: tree; level: integer; Var n: integer);
Begin
  If (level >= 1) and (top <> nil) then
    Begin
      If level = 1 then n := n + 1;
      NC(top^.left, level - 1, n);
      NC(top^.right, level - 1, n);
    End
End;
{---------------------------------------------------------------}
Begin
  Repeat
    ClrScr; 
    Writeln('1-����������� ��������� ������');
    Writeln('2-���������� ����� � ������');
    Writeln('3-�������� ������');
    Writeln('4-������� ���������� ������ �� n-o� ������');
    Writeln('5-�����');
    Writeln('-------------------------------');
    Writeln('�������� ����������� ����� ����');
    Readln(num);
    Case num of 
      1: CreateTree;
      2: AddL;
      3:Begin
          Writeln('����������� ��������� ��������� ������');
          Writeln('---------------------------------------');
          i := 0;
          View(top);
          St(top, 1);
          Writeln('������� Enter');
          Readln
        End;
      4:Begin
          Writeln('������� ���������� ������ �� n-��� ������');
          Writeln('------------------------------------------');
          Write('������� �������� ������:');
          Read(level);
          n := 0;
          NC(top, level, n);
          Writeln;
          Writeln('�� ������ ', level, ' ��������� ', n, ' ������');
          Writeln('������� ������� Enter');
          ReadKey
        End;
    End;
  Until num = 5;
End.