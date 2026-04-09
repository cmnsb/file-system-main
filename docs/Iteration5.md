# Studio 20
d
1. Patrick Liu <liu.patrick@wustl.edu>  
   Jason Zhou <z.zhanrui@wustl.edu>  

2. we delete the pointer because the proxy owns the real file. If we didn't clean the file in proxy, there will be
   memory leaks since the real file would persist in memory without being accessed.

3. Inherit all the methods and add constructing methods and verifying password method.d

4. At first, I tried 1 imagefile:  
   /Users/zhouzhanrui/CLionProjects/oop-work-lab5/cmake-build-debug/src/studio20  
   Enter password: 456  
   write successful  
   Enter password: 456  
   read successful  
   Enter password: 456  
   accept successful  
   X X  
   X  
   X X  
   Enter password: 456  
   accept successful  
   image.img           image     9   
   This is the output of an image file. I create tshe proxy like this AbstractFile* secretFile2 = new PasswordProxy(imgFile, "456");
   imgFile is the name of the file I created as type AbstractFile*.
   I set the file as secretFile2 -> write({ 'X',' ','X',' ','X',' ','X',' ','X','3' });The read and write are all successful  
   and accept is good and then call the basicdisplay visitor.  All the functions are good to use  
    
Secondly, I tried 1 textfile:  
/Users/zhouzhanrui/CLionProjects/oop-work-lab5/cmake-build-debug/src/studio20  
Enter password: 123  
write successful  
Enter password: 123   
append successful  
Enter password: 123  
read successful  
Enter password: 123  
accept successful  
Hello!  
accept successful  
secret.txt          text      6  

Process finished with exit code 0  
This is the output. Similarly, I write the file as secretFile-> write({'H', 'e', 'l', 'l', 'o'});  
secretFile -> append({'!'}); And finally use accept to call the basicdisplayvisitor, they are all successful.  
  
When I tried incorrect password, it will return invalid password.     
Enter password: 456  
invalid password  

5.  /Users/zhouzhanrui/CLionProjects/oop-work-lab5/cmake-build-debug/tests/teststudio20 --gtest_color=no
    Testing started at 5:26 PM ...
    Running main() from /Users/zhouzhanrui/CLionProjects/oop-work-lab5/cmake-build-debug/_deps/googletest-src/googletest/src/gtest_main.cc
    Process finished with exit code 0

    No errors when running the unit test.# Studio 20
