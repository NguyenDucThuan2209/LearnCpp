/*
------------------------------------------
+ Let's say you are driving to a friend's house for the first time, and the address given to you is 245 Front Street in Mill City. Upon reaching Mill City, you take out your map, only to discover that Mill City actually has two different Front Streets across town from each other! Which one would you go to? Unless there were some additional clue to help you decide (e.g. you remember your friend's house was near the river) you'd have to call your friend and ask for more information. Because this would be confusing and inefficient (particularly for your mail carrier), in most contries, all street names and house addresses within a city are required to be unique.
+ Similarly, C++ requires that all identifiers be non-ambiguous. If two identical identifiers are introduced into the same program in a way that the compiler or linker can't tell them apart, the compiler or linker will produce an error. This error is generally referred to as a naming collision (or naming conflict).
+ If the colliding identifiers are introduced into the same file, the result will be a compiler error. If the colliding identifiers are introduced into separate files belonging to the same program, the result will be a linker error.
------------------------------------------
SCOPE REGIONS
+ Back to our address analogy for a moment, having two Front Streets was only problematic because those streets existed within the same city. On the other hand, if you had to deliver mail to two addresses, one at 245 Front Street in Mill City, and another address at 245 Front Street in Jones Ville, there would be no confusion about where to go. Put another way, cities provide groupings that allow us to disambiguate addresses that might otherwise conflict with each other.
+ A scope region is an area of source code where all declared identifiers are considered distinct from names declared in other scopes (much like the cities in our analogy). Two identifiers with the same name can be declared in separate scope regions without causing a naming conflict. However, within a given scope region, all identifiers must be unique, otherwise a naming collision will result.
+ The body of a function is one example of a scope region. Two identically-named identifiers can be defined in separate functions without issue -- because each function provides a separate scope region, there is no collision. however, if you try to define 2 identically-named identifiers within the same function, a naming collision will result, and the compiler will complain.
------------------------------------------
NAMESPACES
+ A namespace provides another type of scope region (called namespace scope) that allows you to declare or define names inside of it for the purpose of disambiguation. The names declared in a namespace are isolated from names declared in other scopes,  allowing such names to exist without conflict.
+ A name declared within a scope region (such as a namespace) is distinct from any identical name declared in another scope.
+ For example, 2 functions with identical declarations can be defined iside different namespaces, and no naming collision or ambiguity will occur.
+ Namespaces may only contain declarations and definitions (e.g. variables and functions). Executable statements are not allowed unless they are part of a definition (e.g. within a function).
+ A namespace may only contain declarations and definitions. Executable statements are only allowed as part of a definition (e.g. of a function).
+ Namespaces are often used to group related identifiers in a large project to help ensure they don't inadvertently collide with other identifiers. For example, if you put all your math functions in a namespace named math, then your math functions won't collide with identically named functions outside the math namespace.
------------------------------------------
THE GLOBAL NAMESPACE
+ In C++, any name that is not defined inside a class function, or a namespace is considered to be part of an implicitly-defined namespace called the global namespace (sometimes also called the global scope).
+ For now, there are two things you should know:
    Identifiers declared inside the global scope are in scope from the point of declaration to the end of the file
    Although variables can be defined in the global namespace, this should generally be avoided.
------------------------------------------
THE std NAMESPACE
+ When C++ was originally designed, all of the identifiers in the C++ standard library (including std::cin and std::cout) were available to be used without the std::prefix (they were part of the global namespace). However, this meant that any identifier in the standard library could potentially conflict with any name you picked for your own identifiers (also defined in the global namespace). Code that was once working might suddenly have a naming conflict when you include a different part of the standard library. Or worse, code that compiled under one version of C++ might not compile under the next version of C++, as new identifiers introduced into the standard library could have a naming conflict with already written code. So C=+ moved all of the functionality in the standard library into a namespace named std (short for "standard").
+ It turns out that std::cout name isn't really std::cout. It's actually just cout, and std is the name of the namespace that identifier cout is part of. Because cout is defined in the std namespace, the name cout won't conflict with any objects or functions named cout that we create outside of the std namespace (such as in the tglobal namespace).
+ When you use an identifier that is defined inside a non-global namespace, you need to tell the compiler that the identifier lives inside the namespace.
------------------------------------------
EXPLICIT nAMESPACE QUALIFIER std::
+ The most straightforward way to tell the compiler that we want to use cout from the std namespace is by explicitly using the std:: prefix.
+ The :: symbol is an operator called the scope resolution operator. The identifier to the left of the :: symbol identifies the namespace that the name to the right of the :: symbol is contained within. If no identifier to the left of the :: symbol is provided, the global namespace is assumed.
+ This is the safest way to use cout, because there's no ambiguity about which cout we're referencing (the one in the std namespace).
+ Best practice: Use explicit namespace prefixes to access identifiers defined in a namespace.
+ When an identifier includes a namespace prefix, the identifier is called a qualified name.
------------------------------------------
USING NAMESPACE std (AND WHY TO AVOID IT)
+ Another way to access identifiers inside a namespace is to use a using-directive statement.
+ A using directive allows us to access the names in a namespace without using a namespace prefix. 
+ Many texts, tutorials, and even some IDEs recommend or use a using-directive at the top of the program. However, used in this way, this is a bad practice, and highly discouraged.
+ When using a using-directive in this manner, any identifier we define may conflict with any identically named identifier in the std namespace. Even worse, while an identifier name may not conflict today, it may conflict with new identifiers added to the std namespace in future language revisions. This was the whole point of moving all of the identifiers in the standard library into the std namespace in the first place!
------------------------------------------
CURLY BRACES AND INDENTED CODE
+ In C++, curly braces are often used to delineate a scope region that is nested within another scope region (braces are also used for some non-scope-related purposes, such as list initialization). For example, a function defined inside the global scope region uses curly braces to separate the scope region of the function from the global scope. 
+ In certain cases, identifiers defined outside the curly braces may still be part of the scope defined by the curly braces rather than the surrounding scope -- function parameters are a good example of this.
+ The code that exists inside a nested scope region is conventionally indented one level, both for readability and to help indicate that it exists inside a separate scope region.
*/