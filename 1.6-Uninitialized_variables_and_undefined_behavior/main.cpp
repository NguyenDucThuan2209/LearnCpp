/*
------------------------------------------
UNINITIALIZED VARIABLES
+ Unlike some programming languages, C/C++ does not automatically initialize most variables to a given value (such as zero). When a variable that is not initialized is given a memory address to use to store data, the default value of that variable is whatever (garbage) value happens to already be in that memory address! A variable that has not been given a known value (through initialization or assignment) is called an uninitialized variable.
+ Nomenclature: 
    Many readers expect the terms "initialized" and "uninitialized" to be strict opposites, but they aren't quite! In common language, "initialized" means the object was provided with an initial value at the point of definition. "Uninitialized" means the object has not been given a know value yet (through any means, including assignment). Therefore, an object that is not initialized but is then assigned a value is no longer uninitialized (because it has been given a know value).
    To recap:
        Initialized = The object is given a know value at the point of definition.
        Assignment = The object is given a know value beyond the point of definition.
        Uninitialized = The object has not been given a know value yet.
    Relatedly, consider this variable definition:

*/