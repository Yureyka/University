Program LAB6;
Uses Crt;
Type student=record
      fio: string[15];
      num: integer;
      usp: integer;
      End;
Var f: file of student;
    stud1, stud2: student;
    number: integer;
Procedure Input_File;         
  Begin 
    Seek(f,FileSize(f));  
    Writeln('??????? ?????? ? ?????????');
    Writeln('??? ?????? ??????? "*"'); 
    While True Do
      Begin
        Write('??????? ???: '); 
        Readln(stud1.fio); 
        If stud1.fio='*' then Break; 
        Writeln('??????? ????? ??????: '); 
        Readln(stud1.num); 
        Writeln('??????? ????????????: '); 
        Readln(stud1.usp);  
        Write(f,stud1);
      End;
  End;
{---------------------------------------------}
Procedure View; 
  Begin 
    Seek(f,0);
    Writeln('???       ':15, '  ??????':5, '  ????????????   ':7);  
    While not eof(f) do     
      Begin   
        Read(f,stud1);
        Writeln(stud1.fio:15, stud1.num:7, stud1.usp:7);   
      End; 
      Readln; 
  End;
{-----------------------------------------------}
Procedure Sort;
  Var i,j: integer;
  Begin
    Seek(f,0);
    For i:=filesize(f)-1 downto 1 do 
      For j:=0 to i-1 do 
        Begin 
          Seek(f,j);
          Read(f,stud1, stud2);
          If  ord(stud1.fio[1])>ord(stud2.fio[1]) then 
            Begin
              Seek(f, j);
              Write(f, stud2, stud1);
            End;
        End;
  End;
{-------------------------------------------------------}
Procedure Search;
  Var found: boolean; 
      s: string[15];  
      n: integer;
  Begin
    n:=0;
    While True do 
      Begin  
        Writeln('??????? ??????? ??? "*"');
        Readln(s);   
        If s='*' then Break;
        found:=False;    
        Seek(f,0);
        While not eof(f) and not found do  
          Begin 
            Read(f,stud1);  
            If (Pos(s,stud1.fio)<>0) and (stud1.fio[Length(s)+1]=' ')then
              Begin
                Writeln(stud1.fio:15, stud1.num:3, stud1.usp:5);  
                n:=n+1;
                found:=True;  
              End;
          End;
        If not found then  
        Writeln('Error');
      End; 
      Readln;
  End;

Begin
  Assign(f, 'data.dat');
  {$I-} 
  Reset(f);  
  {$I+}
  While True do 
    Begin ClrScr;
      Writeln('1-???????? ?????'); 
      Writeln('2-?????????? ?????'); 
      Writeln('3-????? ??????????? ?????'); 
      Writeln('4-????? ?????????');
      Writeln('5-?????'); 
      Writeln('-------------------------------'); 
      Writeln('??????? ????? ?????? ????');
      Readln(number); 
      Case number  of
        1:Input_File; 
        2:Sort;   
        3:View;  
        4:Search; 
        5:Exit    
      End;
    End;
End.
  
           
 