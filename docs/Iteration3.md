# Studio 18
1.Patrick Liu <liu.patrick@wustl.edu>  
  Jason Zhou <z.zhanrui@wustl.edu>  
   
2.We currently use createFile() in SimpleFileSystem to constructs files like TextFile and ImageFile.   
  If we want to support a new file type, like MusicFile, we need to modify the createFile method.    
  we should delegate file creation to a separate object. This would allow the file system to manage  
  files without the concrete types, its easier to support multiple file system implementations and    
  new file types in the future.  
   
3.the advantages of abstract factory is it follows the single responsibility principle,  
  when we have new concrete file type, its easy to extend or maintain our file system.  
  the disadvantage is that we created more classes in order to separate this function.  

4.In order to test the SimpleFileFactory, I used SimpleFileFactory object to create 2 files.  
  then, add them to the SimpleFileSystem, for each file type, I tried opening, writing, and reading the files.  
    
  AbstractFileSystem* fs = new SimpleFileSystem();  
  AbstractFileFactory* ff = new SimpleFileFactory();  
  AbstractFile* f1 = ff->createFile("text.txt");  
  AbstractFile* f2 = ff->createFile("image.img");  
  fs->addFile("text.txt", f1);  
  fs->addFile("image.img", f2);  
    
  AbstractFile* txt = fs->openFile("text.txt");  
  txt->write({ 'H','e','l','l','o' });  
  txt->read();  
  fs->closeFile(txt);  
    
  AbstractFile* img = fs->openFile("image.img");  
  img->write({ 'X',' ','X',' ','X',' ','X',' ','X','3' });  
  img->read();  
  fs->closeFile(img);  
     
  output:  
  Hello  
  X X  
   X  
  X X  

5.SimpleFileSystem now only depends on the AbstractFile interface.  
