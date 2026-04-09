# Auther 
1.Patrick Liu <liu.patrick@wustl.edu>  
  Jason Zhou <z.zhanrui@wustl.edu>  

2.To declare an ��interface��, we can create an abstract base class with pure virtual functions,  
  then implement the interface in the derived class.   
   
3.a.interface inheritance  
3.b.these member variables should be private.  

4.In the main function, we test TextFile class by creating an variable of type TextFile called f.   
  We use the write function to update f to contents "Zhou". Then, we test getSize, getName, and read functions, which run correctly as expectation.  
  Then, we use append function to f, and test it using the same way.  
    
5.TextFile f("test.txt");  
  AbstractFile* p = &f; //using pointer with static type AbstractFile  
  and also call all the function as p->getName(), the result is the same as question4.  