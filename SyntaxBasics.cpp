// An Introduction to CPP - - - - - - -

/*
This guide intends that you read it through, top to bottom, line by line, to get a basic grasp on the language. 
Skipping around sections is neither easy nor effective for this guide. There is a reason for that!
This does assume you have worked with OOP before. 
I will be leaving out information about operators, variables, and assignment as those are common in all OOP languages.
It is to your benefit to view this file in an IDE like VSCode or text editor like Neovim.
Happy learning!
*/


// This file should probably cover most of the basics of the language at least up to C++11. By the way, the "//" at the beginning here denotes a single line comment.

/*
You may have noticed that line was getting a bit long...
So you may want a multiline comment like this!
This is much more modular for verbose comments.
Unlike statements, which MUST end with a semicolon, directives do not need semicolons as they are not statements. 
To denote a multiline comment, we use "/*". In most IDEs, the closing part is autocompleted.
*/

#include <iostream> // This is a directive, which is read by the preprocessor before compilation. In this case, it includes 'header iostream' in our program.

/* 
Should you want to include more directives...
#include <name>
...

Unlike statements, which MUST end with a semicolon, directives do not need semicolons as they are not statements. 
*/

using namespace std; // Here, 'std' is a namespace. This basically allows us to use an element of the 'std' library without qualifying that it is from std. 

//Below is our main method. Those familiar with languages like Java or C# will recognize it as the 'entrypoint' to the program. Any call is routed through here
int main(){
    std::cout << "Hello World!"; // We don't actually *need* the std qualifier here because of line 31. cout is the standard output mechanism for cpp.
    /*
    We can only do so much without variables. Because cpp is strongly-typed, there's a couple rules we must follow for variables:
    1. A name that is NOT one of cpp's keywords. Those can be found here: https://en.cppreference.com/cpp/keyword.
        - Don't worry too much about this though; a good programmer picks names according to their unique specs!
    2. A data type. You should be familiar with a few of these, like 'int', or 'string' (not String!).
        - There's many, all of which are here: https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
        - With different types comes a different memory allocation. Choose what is best for your spec.
    With that in mind, let's continue!
    */
    int frogs; // We declare a var frogs of the int type. We have not YET initialized it.
    int frogs = 0; // We assign the integer value 0 to frogs. We INITIALIZE frogs. No cute frogs to be found :(

    int tadpoles; // We declare tadpoles. 
    int tadpoles = 1234; // Woah, that's a lot of tadpoles.

    int totalPopulation = frogs + tadpoles; // Operators like +, /, -, % are pretty much the same for every OOP language.

    cout << totalPopulation; // 1234

    // You could also initialize variables in the same line as your declaration like so:

    int x = 0;
    int y (0);
    int z {0};


}