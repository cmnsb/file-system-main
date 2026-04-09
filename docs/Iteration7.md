# Auther
Patrick Liu <liu.patrick@wustl.edu>   
Jason Zhou <z.zhanrui@wustl.edu>   
  
  
additional MacroCommand:   
We created a new MacroCommand tcd, which is touch + cat + ds commands.  
Users can invoked with command: tcd <filename>  
tcd command create a file with the filename input, and prompt the user to modify the contents of the file.  
then immediately display the file contents after editing. it's easier for users to create a new file.  
testing:  
$  tcd test1.txt  
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.  
hello   
world  
:wq  
hello   
world  
   
$ tcd test2.img  
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.  
X X X X X3  
:wq  
X X  
 X   
X X  
these tests check tcd for both txt and img file, and the results are as expected.  
  

Errors/bugs:  
1.PasswordProxy caused phantom input issues  
After entering a password using cin >>, the leftover newline (\n) remained in the input buffer, causing the next getline() to read an empty string.  
it is fixed by changing password input to use getline(cin, input) to consume the newline correctly.  

2.CopyCommand failed for ImageFile  
ImageFile::clone() used read() but forgot to add the final size digit before calling write(), which caused size_not_match errors.  
After calling read(), I added content.push_back('0' + this->size); to fix this error.  
return value: 103  

3.CatCommand added unwanted new line characters
During cat -a (append mode), I appended each user input line with a '/n' before the content instead of after, which led to unexpected content such as:  
\nhello world  
this caused multiple unit test failures including:  
so I moved tempContents.push_back('\n') to after the content, ensuring that newlines are correctly placed at the end of each line. and remove the last new line character.  


Main testing:  
1.test1: touch �C Create New Files  
$  touch t.txt  
$  touch i.img   
$  ls  
i.img               t.txt  


2.test2: cat �C Edit File Contents  
$  cat t.txt  
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.  
hello world   
:wq  
$  cat t.txt -a   
t.txt  
hello world  
Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving.  
tetete  
:wq  
$  cat t.txt -a  
:q  
$  ds t.txt  
hello worldtetete    

this test cat [-a] with text file. 

$  cat i.img  
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.  
X X X X X3  
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  cat i.img -a  
i.img  
X X X X X  
Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving.  
X1  
:wq  
return value: 103  
command execution fail.   
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.   
$  ds i.img  
X X  
 X  
X X  
  
this test cat [-a] with image file.  

3.test3: ds �C Display File Contents   
  
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ds i.img  
X X  
 X  
X X  
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ds i.img -d  
X X X X X  
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ds t.txt  
hello worldtetete  
  
4.test4: ls �C List Files  

$  ls  
i.img               t.txt  
$  touch tt.txt    
$  touch ii.img  
$  ls  
i.img               t.txt  
tt.txt              ii.img  

5.test5: rm �C Remove Files  

$  rm tt.txt   
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ls  
i.img               ii.img  
t.txt  

6.test6: cp �C Copy Files   
$  cp t.txt t_copy  
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  cat t_copy.txt  
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.  
aaa   
:wq   
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ds t.txt  
hello worldtetete  
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ds t_copy.txt  
aaa  
  
7.test7: rn �C Rename (MacroCommand: cp + rm)  
$  rn t.txt teeest  
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ls  
i.img               ii.img  
t_copy.txt          teeest.txt  
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.  
$  ds teeest.txt  
hello worldtetete  

8.test8: all unit tests pass.  