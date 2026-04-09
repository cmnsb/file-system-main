# Studio 19

1. Patrick Liu <liu.patrick@wustl.edu>  
   Jason Zhou <z.zhanrui@wustl.edu>

2. For this question, I tried the text txt->write({'H','e','l','l','o'}), since the read method is commented out,
   it cannot print out anything here, the test just exits with code 0. After that, I modify the contents by pushing 
   back a '!', so the txt is 'Hello!' right now. I check this by using basicdisplayvisitor later and it prints out Hello!
   For the image file, i tried  
   img->write({'X',' ','X',' ','X',' ','X',' ','X','3'});  
   vector<char> imgContents = img->read();  
   imgContents[0] = ' ';  
   imgContents.push_back('3');  
   img->write(imgContents);   
   since the read file doesn't print out anything, I tried the test later with basicdisplayvisitor and the output is    
     X  
   X X  
   X  

3. When a visitor is applied to a file, the client calls file -> accept(visitor). This triggers the accept method and then
   calls the corresponding visit* method.  This allows the visitor to interact with the file without the file needing to know
   what operation is being performed, enabling flexible and extensible behavior.

4. The visitor pattern uses delegation by allowing a file object to delegate a task. For example, in our code, the delegation
   involves using the external visitor object to display the contents. Instead of embedding display logic to each file class,
   the file class calls visitor method through accept() method, passing itself as a parameter. In this way, the behavior is 
   handled externally in the visitor class and keep the original class interface clean and tidy. This allows further extending
   the functionality through new visitor method without modifying the file classes, which gives more flexibility and make the codes
   more clear.

5. A drawback of the visitor pattern is that when you add a new file type, you must update every existing visitor with a new visit_* 
   method. This becomes tedious and error-prone if there are many visitors. In systems where file types change often, the visitor 
   pattern adds overhead and can reduce flexibility.