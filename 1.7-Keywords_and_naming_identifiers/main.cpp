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

*/