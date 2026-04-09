# Studio 17
1.Patrick Liu <liu.patrick@wustl.edu>  
  Jason Zhou <z.zhanrui@wustl.edu>  
   
2.Testing ImageFile class:   
  I tested all the functions of ImageFile class, including write, read, getName, getSize, and append,  
  by creating a new ImageFile object, and use write and read function to modify and print the content.  
  then simply call the getName and getSize methods.  
  Then, I tested the bad cases, first I called append method, and it returned an non-zero value.  
  I also tested size dismatch and bad contents input:  
    //testing size dismatch  
    vector<char> badSize = { 'X', 'X', 'X', '3' };  
    cout << "Bad size: " << p->write(badSize) << endl;  
    //testing bad contents input  
    vector<char> badContents = { 'T', '1' };  
    cout << "Bad contents input: " << p->write(badContents) << endl;  
  output:  
    Bad size: 3  
    Bad contents input: 2  

3.programming a client to use an interface rather than a concrete class,   
  it makes the program easy to extend, test, and maintain.  

4.To create an object of a new concrete file type, we should add an if statement in createFile() method,  
  if (extension == "mp3") new MusicFile(...)  