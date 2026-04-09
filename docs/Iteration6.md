# Studio 21
1. Patrick Liu <liu.patrick@wustl.edu>  
   Jason Zhou <z.zhanrui@wustl.edu>  

2. It is important to declare a virtual destructor in the base class to ensure that when a derived object is deleted through a base class pointer, 
   the correct derived class destructor is called. Without a virtual destructor, only the base class destructor would run, leading to memory leaks 
   or incomplete cleanup.

3. This design uses dependency injection, which makes the CommandPrompt flexible and reusable. Instead of the CommandPrompt creating its own file system,
   file factory, or commands, it receives these objects from outside. This allows the CommandPrompt to work with any objects that implement the required 
   interfaces, without depending on specific classes.As a result, the CommandPrompt can easily be used with different types of file systems or factories. 
   For example, if we implement a new file system or file factory in the future, we can inject them into the CommandPrompt without changing the 
   CommandPrompt’s code. This reduces coupling and makes testing easier because we can provide mock or test versions of file systems, factories, or commands.
   The CommandPrompt can easily be configured to use different file systems and factories because it only relies on the AbstractFileSystem and 
   AbstractFileFactory interfaces, not specific implementations.

4. To test the TouchCommand, I first dynamically created a SimpleFileSystem, a SimpleFileFactory, and a TouchCommand object, then added the TouchCommand 
   to the CommandPrompt.
   I ran the command prompt and manually entered the command touch t.txt to create a new file named t.txt.
   After exiting the command prompt, I verified whether the file was successfully created by attempting to open it using fs->openFile("t.txt").
   If the file pointer returned was not nullptr, it confirmed that the file had been created successfully. Otherwise, an error message was printed.
   Finally, I closed the file (if opened) and deleted the dynamically allocated resources to avoid memory leaks.

