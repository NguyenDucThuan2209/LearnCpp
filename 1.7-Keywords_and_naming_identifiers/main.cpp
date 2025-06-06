/*
------------------------------------------
KEYWORDS
+ C++ reserves a set of 92 words (as of C++23) for its own use. These words are called keywords (or reserved words), and each of these keywords has a special meaning within the C++ language.
+ Here is a list of all the C++ keywords:
    alignas alignof and and_eq asm auto
    bitand bitor bool break
    case catch char char8_t char16_t char32_t class compl concept const consteval constexpr constinit const_cast continue co_await co_return co_yield 
    decltype default delete do double dynamic_cast
    else enum explicit export extern
    false float for friend
    goto
    if inline int 
    long
    mutable
    namespace new noexpect not not_eq nullptr
    operator or or_eq
    private protected public 
    register reinterpret_cast requires return
    short signed sizeof static static_assert static_cast struct switch
    template this thread_local throw true try typedef typeid typename
    union unsigned using 
    virtual void volatile
    wchar_t while 
    xor xor_eq
+ C++ also defines special identifiers: override, final, import, module. These have a specific meaning when used in certain contexts but are not reserved otherwise.
+ You have already run across some of these keywords. Along with a set of operators, these keywords and special identifiers define the entire language of C++ (preprocessor commands excluded). Because keywords and special identifiers have special meaning, your IDEs will likely change the text color of these words to make them stand out from other identifiers.
------------------------------------------
IDENTIFIER NAMEING RULES
+ As a reminder, the name of a variable (or function, type, or other kind of item) is called an identifier. C++ gives you a lot of flexibility to name identifiers as you wish. However, there are a few rules that must be followed when naming identifiers:
    1. The identifier can not be a keyword. Keywords are reserved.
    2. The identifier can only be composed of letters (lower or upper case), numbers, and the underscore character. That means the name can not contain symbols (except the underscore) nor whitespace (spaces or tabs).
    3. The identifier must begin with a letter (lower or upper case) or an underscore. It can not start with a number.
    4. C++ is case sensitive, and thus distinguishes between lower and upper case letters. nvalue is different than nValue is different than NVALUE.
------------------------------------------
IDENTIFIER NAMING BEST PRACTICES
+ Now that you know how you can name a variable, let's talk about how you should name a variable (or function).
    1. It is conventional in C++ that variable names should begin with a lowcase character. If the variable name is a single word or acronym, the whole thing should be written in lowercase letters.
        Most often, function names are also started with a lowercase letter (though there's some disagreement on this point). We'll follow this convention, sinc function name (which all programs must have) starts with a lowercase letter, as do all of the functions in c++ standard library.
        Identifier names that start with a capital letter are typically used for user-defined types (such as structs, classes, and enumerations, all of which we will cover later).
        If the variable or function name is multi-word, there are two common conventions: words separated by underscores (sometimes called snake_case), or inter-capped (sometimes called camelCase, since the capital letters stick up like the humps on a camel).
        Best practice: When working in an existing program, use the conventions of that program (even if they don't conform to modern best practices). Use modern best practices when you're writing new programs.
    2. Avoid naming your identifiers starting with an underscore. Although syntactically legal, these names are typically reserved for OS, library, and/or compiler use.
    3. The name of your identifiers should make clear what the value they are holding means (particularly if the units aren't obvious). Identifiers should be named in a way that would help someone who has no idea what your code does be able to figure it out as quickly as possible. In 3 months, when you look at your program again, you'll have forgotten how it works, and you'll thank yourself for picking variable names that make sense.
        + However, giving a trivial identifier an overly-complex name impedes overall understanding of what the program is doing almost as much as giving a non-trivial identifier an inadequate name. A good rule of thumb is to make the length of an identifier proportional to how specific and accessible the identifier is. This mean:
            An identifier that exists for only a few statements (e.g. in the body of a short function) can have a shorter name.
            An identifier that is accessible from anywhere might benefit from a longer name.
            An identifier that represents a non-specific number (e.g. anything the user provides) can have a shorter name.
            An identifier that represents a specific value (e.g. the length of an inseam in millimeters) should have a longer name.
    4. Avoid abbreviations, excepts when they are common and unambiguous
        Code is read more often than it is written, so any time saved while writing the code is time that every reader, including future you, will waste while reading it. If you're looking to write code faster, use your editor's auto-complete feature.
    5. For variable declarations, it can be useful to use a comment to describe what a variable is going to be used for, or to explain anything else that might not be obvious. For example, say we've declared a variable that is supposed to store the number of characters in a piece of text. Does the text "Hello World!" have 10, 11, 12 characters? It depends on whether we're including whitespace or punctuation. Rather than naming the variable 'numCharsIncludingWhitespaceAndPunctuation', which is rather lengthy, a well placed comment on or above the declaration line should help the user figure it out:
        // A count of the number of chars in a piece of text, including whitespace and punctuation
        int numChars{};
------------------------------------------
QUIZ TIME
+ Question: Base on how you should name a variable, indicate whether each variable name is conventional (follows best practices), unconventional (compiler will accept but does not follow best practices), or invalid (will not compile), and why.
    1. int sum{};
    → It's valid and if it's obvious what we're summing, this is conventional.
    2. int _apples{};
    → It's valid but it's unconventional because it start with an underscore.
    3. int VALUE{};
    → It's valid but it's unconventional because it goes with all upper case.
    4. int my variable name{};
    → It's invalid and will not be compiled because variable name can't contain spaces.
    5. int TotalCustomers{};
    → It's valid but it's unconventional because it start with a upper case letter.
    6. int void{};
    → It's invalid because 'void' is a keyword of the C++ language.
    7. int numFruit{};
    → It's valid and conventional.
    8. int 3some{};
    → It's invalid because it start with a number.
    9. int meters_of_pipe{};
    -> It's valid and conventional.
*/