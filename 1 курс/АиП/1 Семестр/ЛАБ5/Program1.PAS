Program LAB5;
Const
  dlmtr=[' ','.',',',':',';'];
Var
  inf: text;
  tword, str: string[80];
  tnum: string[2];
  k, n, strlen: word;
  ch, err: integer;
  namef: string[20];
Begin
  Writeln('Input name of your file');
  Readln(namef);
  {$I-} 
  Assign(inf, namef);
  Reset(inf);
  n:=0;
  While not Eof(inf) do 
    Begin
      Inc(n);
      Readln(inf, str);
      strlen:=Length(str);
      k:=1;
      tword:=' ';
      For k:=1 to strlen do
        Begin
          If (str[k] in dlmtr) or (k=strlen) then
            Begin
              If (k=strlen) then
                tword:=tword+str[k];
              Val (tword, ch, err); 
              If (err=0) then 
                Begin 
                  tnum:=tword;
                  If Length(tnum)=2 then
                    Begin
                      Writeln('Number ', tword, ' was found in the string ', n, ':');
                      Writeln(str);
                  Break;
                End;
                End;
              tword:=' ';
            End
          Else tword:=tword+str[k];
        End;
    End;
  Close(inf);
  Writeln('Press "Enter" for exit');
  Readln;
End.