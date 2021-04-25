Program LAB7;
Uses Crt;
Type 
  data = Record
          fio:string[15];
          year:string[12];
          sex:char;
          sp:string[12];
          cn:integer;
          sal:real;
         End;
  u = ^query;
  query = Record
            inf:data;
            next:u;
          End;
Var
  newe, com, fin, tmp:u;
  z:data;
  key:char;

Procedure Create;
Begin
  Writeln('������� ������ � ����������. ||||| ��� ������ ������� "*"');
  Writeln('������� ��� ����������:');
  Readln(z.fio);
  If z.fio='*' then Exit;
  Writeln('������� ���� �������� � ��� ����������:');
  Readln(z.year);
  Readln(z.sex);
  Writeln('������� �������� ��������� � ����������� ����� ����������:');
  Readln(z.sp);
  Readln(z.cn);
  Writeln('������� ����� ����������:');
  Readln(z.sal);
  New(newe);
  newe^.inf.fio:=z.fio;
  newe^.inf.year:=z.year;
  newe^.inf.sex:=z.sex;
  newe^.inf.sp:=z.sp;
  newe^.inf.cn:=z.cn;
  newe^.inf.sal:=z.sal;
  newe^.next:=nil;
  com:=newe;
  fin:=newe;
  While true do
    Begin
      Writeln('������� ��� ����������:');
      Readln(z.fio);
      If z.fio='*' then Exit;
      Writeln('������� ���� �������� � ��� ����������:');
      Readln(z.year);
      Readln(z.sex);
      Writeln('������� �������� ��������� � ����������� ����� ����������:');
      Readln(z.sp);
      Readln(z.cn);
      Writeln('������� ����� ����������:');
      Readln(z.sal);
      New(newe);
      newe^.inf.fio:=z.fio;
      newe^.inf.year:=z.year;
      newe^.inf.sex:=z.sex;
      newe^.inf.sp:=z.sp;
      newe^.inf.cn:=z.cn;
      newe^.inf.sal:=z.sal;
      newe^.next:=nil;
      fin^.next:=newe;
      fin:=newe; 
    End;
End;
{------------------------------------------}
Procedure Add;
Begin
  Writeln('������� ������ � ����������. ||||| ��� ������ ������� "*"');
  Writeln('������� ��� ����������:');
  Readln(z.fio);
  If z.fio='*' then Exit;
  Writeln('������� ���� �������� � ��� ����������:');
  Readln(z.year);
  Readln(z.sex);
  Writeln('������� �������� ��������� � ����������� ����� ����������:');
  Readln(z.sp);
  Readln(z.cn);
  Writeln('������� ����� ����������:');
  Readln(z.sal);
  New(newe);
  newe^.inf.fio:=z.fio;
  newe^.inf.year:=z.year;
  newe^.inf.sex:=z.sex;
  newe^.inf.sp:=z.sp;
  newe^.inf.cn:=z.cn;
  newe^.inf.sal:=z.sal;
  newe^.next:=nil;
  fin^.next:=newe;
  fin:=newe;
End;
{-------------------------------------------}
Procedure Exception;
Begin
  If com<>nil then
    Begin
      tmp:=com; 
      com:=com^.next; 
      Dispose(tmp); 
      If com=nil then fin:=nil; 
    End;
End;
{-------------------------------------------}
Procedure View;
Var i:integer;
Begin
  Writeln('����� �������:');
  tmp:=com;
  i:=1;
  While tmp<>nil do
    Begin
      Writeln(i,' ', tmp^.inf.fio,' ',tmp^.inf.year,' ',tmp^.inf.sex,' ',tmp^.inf.sp,' ',tmp^.inf.cn,' ',tmp^.inf.sal);
      tmp:=tmp^.next;
      i:=i+1;
    End;
  Writeln('������� Enter, ����� ����������...');
  Readln;
End;
{-------------------------------------------}
Begin
  fin:=nil; com:=nil;
  Repeat
    ClrScr; 
    Writeln('1-����������� �������');
    Writeln('2-���������� �������� � �������');
    Writeln('3-�������� �������� �� �������');
    Writeln('4-�������� �������');
    Writeln('5-�����');
    Writeln('-------------------------------');
    Writeln('�������� ����������� ����� ����...');
    key:=ReadKey; 
    Case key of 
      '1':Create;
      '2':Add;
      '3':Exception;
      '4':View;
    End
  Until Key='5' {����� �� ���������}
End.


  
    
  
    