# An Introduction to CPP 

This guide intends that you read it through, top to bottom, line by line, to get a basic grasp on the language.
Skipping around sections is neither easy nor effective for this guide. There is a reason for that!
This does assume you have worked with OOP before.
I will be leaving out information about operators, variables, and assignment as those are common in all OOP languages.
It is to your benefit to view this file in an IDE like VSCode or text editor like Neovim.
Happy learning!

```cpp
// This file should probably cover most of the basics of the language at least up to C++11. By the way, the "//" at the beginning here denotes a single line comment.

/*
You may have noticed that line was getting a bit long...
So you may want a multiline comment like this!
This is much more modular for verbose comments.
To denote a multiline comment, we use "/*". In most IDEs, the closing part is autocompleted.
*/
```

```cpp
#include <iostream>
```

This is a directive, which is read by the preprocessor before compilation. In this case, it includes 'header iostream' in our program. Unlike statements, which MUST end with a semicolon, directives do not need semicolons as they are not statements. 

Should you want to include more directives...

```cpp
#include <name>
...
```

Unlike statements, which MUST end with a semicolon, directives do not need semicolons as they are not statements.

```cpp
using namespace std;
```

Here, 'std' is a namespace. This basically allows us to use an element of the 'std' library without qualifying that it is from std.

Below is our main method. Those familiar with languages like Java or C# will recognize it as the 'entrypoint' to the program. Any call is routed through here

```cpp
int main(){
    std::cout << "Hello World!";
```

We don't actually *need* the std qualifier here because of line 31. cout is the standard output mechanism for cpp.

We can only do so much without variables. Because cpp is strongly-typed, there's a couple rules we must follow for variables:

1. A name that is NOT one of cpp's keywords. Those can be found here: https://en.cppreference.com/cpp/keyword.
    - Don't worry too much about this though; a good programmer picks names according to their unique specs!
2. A data type. You should be familiar with a few of these, like 'int', or 'string' (not String!).
    - There's many, all of which are here: https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
    - With different types comes a different memory allocation. Choose what is best for your spec.

With that in mind, let's continue!

We declare a var frogs of the int type. We have not YET initialized it.

```cpp
    int frogs;
```
We assign the integer value 0 to frogs. We INITIALIZE frogs. No cute frogs to be found :(

```cpp
    int frogs = 0;
```

We declare tadpoles.

```cpp
    int tadpoles;
```
Woah, that's a lot of tadpoles.

```cpp
    int tadpoles = 1234;
```

```cpp
    int totalPopulation = frogs + tadpoles;
```

Operators like +, /, -, % are pretty much the same for every OOP language.

```cpp
    cout << totalPopulation; // 1234
```

You could also initialize variables in the same line as your declaration like so:

```cpp
    int x = 0;
    int y (0);
    int z {0};


}
```

That closing brace is the end of our main method. Everything between the braces is called the 'body'. You may notice main returns an int but we never wrote a return... cpp lets main (and ONLY main) skip it, and it will return 0 for you. Most devs still write it out anyway:

```cpp
    return 0;
```

From here on out, assume any snippet that is indented is of main. Snippets that are NOT indented (functions, structs, classes, etc.) are NOT of main. Keep that in mind!

We know output, so naturally we have input too. cin is the standard input mechanism for cpp. Notice the arrows point the other way! With cout, data flows *out* to the console. With cin, data flows *in* to our variable.

```cpp
    int frogsSpotted; 
    cout << "How many frogs did you see? ";
    cin >> frogsSpotted;
```

You can also tie these together, for both cout and cin:

```cpp
    cout << "You saw " << frogsSpotted << " frogs!" << endl;
```

endl ends the line and moves to the next one. You could also use "\n" inside of your string, which does the same thing (and is a little faster).

Speaking of strings... To use string, we need another directive at the top of our file:

```cpp
#include <string>
```

Now we can make strings. Note that strings use double quotes "", while a single char uses single quotes ''. These are NOT interchangeable like in some other languages (Python!).

```cpp
    string pondName = "Cool Lake";
    char grade = 'A';
```

Strings can be added (concatenated) together and they have a few built in functions:

```cpp
    string greeting = "Welcome to " + pondName; // Welcome to Cool Lake (note the <space> after "to"!)
    cout << greeting.length(); // 24
    cout << greeting[0]; // W
```

cin is a bit annoying in that it stops reading at the first space. So if you were to type "Cool Lake", pondName would only get "Cool". To grab a whole line, use getline:

```cpp
    getline(cin, pondName);
```

Now for decision making. The if statement should already be familar. The condition goes in parentheses, and the code to run should be in braces.

```cpp
    if (frogs > 10) {
        cout << "Frogpalooza!";
    } else if (frogs > 0) {
        cout << "A few frogs...";
    } else {
        cout << "No cute frogs to be found :(";
    }
```

Keep in mind that in cpp, any number that is not 0 counts as true, and 0 counts as false. So writing `if (frogs)` is perfectly valid and means "if frogs is not 0". There is also a bool type with the values true and false:

```cpp
    bool isRaining = true;
```

When you are checking one variable against many of exact values, a switch can be cleaner than a many ifs conditons. The break is imperative! Without it, cpp will "fall through" and run the next case too.

```cpp
    switch (grade) {
        case 'A':
            cout << "Excellent!";
            break;
        case 'B':
            cout << "Good job!";
            break;
        default:
            cout << "Keep hopping.";
            break;
    }
```

Loops. You should know these, so here is cpp specific format for them. A while loop runs as long as its condition is true:

```cpp
    while (tadpoles > 0) {
        tadpoles--; // The tadpoles are growing up to become froggies!
        frogs++;
    }
```

A do-while loop is the same, except it ALWAYS runs at least once, since the condition is checked at the end:

```cpp
    do {
        cout << "Ribbit!";
    } while (false); // Still prints Ribbit! once
```

And the for loop, which is great when you know how exactly how many times you want to loop:

```cpp
    for (int i = 0; i < 5; i++) {
        cout << i; // 01234
    }
```

break leaves the loop entirely, and continue skips to the next iteration. These work in all the three loops.

Now, what if we want a lot of frogs, each with their own weight? We could make frog1, frog2, frog3... but that's verbose. Instead, we use an array. An array holds a FIXED number of values, all of the same type.

```cpp
    int frogWeights[3] = {12, 15, 9};
    cout << frogWeights[0]; // 12
    frogWeights[2] = 10; // Changing the third frog's weight
```

For arrays:
1. Indexing starts at 0, not 1.
2. The size cannot change once it is made.
3. cpp will NOT stop you from going out of bounds. frogWeights[5] will not throw up some warning like in Rust. Careful!
    - There is no .length on a plain array either. We'll see a better option for that later on.

With that in mind, let's look at functions. A function needs a return type, a name, and parameters in parentheses. If a function doesn't return anything, its return type is void.

```cpp
int addFrogs(int a, int b) {
    return a + b;
}

void ribbit() {
    cout << "Ribbit!";
}
```

Then inside main, we call them like this:

```cpp
    int total = addFrogs(3, 4); // 7
    ribbit();
```

If you did Java or C# before: cpp reads your file top to bottom. If you call a function in main, but the function is written BELOW main, the compiler doesn't know it exists yet! You can fix this by moving the function above main, or by writing a declaration (also called a prototype) above main:

```cpp
int addFrogs(int a, int b); // Just the "signature", ending with a semicolon.

int main() {
    cout << addFrogs(1, 2);
}

int addFrogs(int a, int b) { // The actual definition can now go down here.
    return a + b;
}
```

Parameters can have default values. If the caller leaves them out, the default is used. Defaults must go at the END of the parameter list.

```cpp
void croak(int times = 1) {
    for (int i = 0; i < times; i++) {
        cout << "Croak! ";
    }
}
```

```cpp
    croak();  // Croak!
    croak(3); // Croak! Croak! Croak!
```

You can also have multiple functions with the SAME name, as long as their parameters are different. This is overloading, and cpp figures out which one to use based on what arg you pass in.

```cpp
int area(int side) {
    return side * side;
}

int area(int width, int height) {
    return width * height;
}
```

By default, cpp passes arguments by value. That means the function gets a COPY, and changing it does nothing to the original:

```cpp
void feedFrog(int weight) {
    weight++; // Only changes the copy
}
```

If we want the function to change the original, we pass by reference using &:

```cpp
void feedFrog(int& weight) {
    weight++; // Changes the original!
}
```

References... are pretty important in cpp. And pointers. This is an important part to read through.

A reference is basically an alias for a variable that already exists. Whatever occurs to the reference, occurs to the original. A reference must be initialized when it is declared, and it can never be changed to refer to something else.

```cpp
    int lily = 5;
    int& lilyRef = lily;
    lilyRef = 10;
    cout << lily; // 10
```

Every variable lives somewhere in memory (don't worry where exactly), and that somewhere has an address. A pointer is a variable that holds an address. We use & to GET the address of something, and * to declare a pointer and to "dereference" it (go to the address and get what is there).

```cpp
    int pad = 7;
    int* padPtr = &pad; // padPtr holds the address of pad
    cout << padPtr; // Something like 0x7ffee4b2c9ac. That's the address
    cout << *padPtr; // 7. That's the value AT the address.
    *padPtr = 8; // pad is now 8
```

& and * each mean different things depending on where they are! 
1. In a declaration: int& is a reference, int* is a pointer.
2. In an expression: &x gets the address of x, *p gets the value p points to.

Unlike references, a pointer can point to nothing. For that we use nullptr (from C++11. You might see NULL or 0 in older code). Dereferencing a nullptr will crash your program, so check first!

```cpp
    int* nowhere = nullptr;
    if (nowhere != nullptr) {
        cout << *nowhere;
    }
```

Pointers are important for their use in dynamic memory. So far, all of our variables have lived on the "stack", and they are cleaned up automatically when their braces end. We may need memory that is present longer, or that we don't know the size of until the program is running. For that, we use new to get memory from the "heap":

```cpp
    int* bigFrog = new int(500);
    cout << *bigFrog; // 500
    delete bigFrog; // We MUST give the memory back ourselves.
```

You can make arrays like this too, which lets you pick the size while the program is running:

```cpp
    int count;
    cin >> count;
    int* pond = new int[count];
    delete[] pond; // Note the [] for arrays!
```

cpp has NO garbage collector. If you new something and forget to delete it, that memory is gone until your program ends. This is called a memory leak. Every new needs a matching delete. This is why, for purposes demanding exceptional security, languages like Rust are often preferred.

Before we get into making our own types, we should understand const. Marking something const means it cannot be changed after it is initialized (ie. it is **const**ant). The compiler will let you know if you try to modify it.

```cpp
    const int MAX_FROGS = 100;
    MAX_FROGS = 200; // Error!
```

const is very common with references in function parameters. It gives you the speed of passing by reference (no copy!).

```cpp
void printPond(const string& name) {
    cout << name;
}
```

Now let's make our own types. The simplest way is a struct (which C devs are surely familiar with), which groups a few variables together. Note the semicolon after the closing brace! Forgetting it is no good.

```cpp
struct Frog {
    string name;
    int weight;
};
```

```cpp
    Frog lolfrog;
    lolfrog.name = "Lolfrog";
    lolfrog.weight = 12;

    Frog mizuki {"Mizuki", 14}; // You can also initialize like this
```

If you have a pointer to a struct (or class), you use -> instead of . to get at its members:

```cpp
    Frog* lolfrogPtr = &lolfrog;
    cout << lolfrogPtr->name; // Lolfrog. Same as (*lolfrogPtr).name
```

Now for classes. You should already know the gist from other OOP languages. In cpp, a class is almost the same thing as a struct. The only difference is that members of a struct are public by default, and members of a class are private by default. By this convention, people use struct for simple bundles of data and class for anything with behavior.

```cpp
class Pond {
private:
    string name;
    int frogCount;

public:
    Pond(string n, int count) : name(n), frogCount(count) {} // This is a constructor.

    void addFrog() {
        frogCount++;
    }

    int getFrogCount() const {
        return frogCount;
    }
};
```

There's a few things to unpack, so let's go through them:
1. private: and public: are labels. Everything below a label has that access level until the next label.
    - There is also protected:, which is like private, but child classes can see it too.
2. The constructor has the same name as the class, but no return type.
    - That ": name(n), frogCount(count)" part is an initializer list. It sets members before the constructor body runs. It's the preferred way to initialize members in cpp.
3. The const after getFrogCount() means this function will not change the object.
4. Don't forget the semicolon at the end...

Making an object doesn't need new in cpp. You can just declare it like any other variable, and it will be on the stack:

```cpp
    Pond lilyPond("Cool Lake", 3);
    lilyPond.addFrog();
    cout << lilyPond.getFrogCount(); // 4
```

Inside of a member function, this is a POINTER to the current object. So you'd use this->name, not this.name. It's useful when a parameter has the same name as a member.

Classes can also have a destructor (cool ass name!). It has the same name as the class with a ~ in front, and it runs automatically when the object is destroyed (when it goes out of scope, or when you delete it). This is where anything the object got with new is cleaned up.

```cpp
class Bucket {
private:
    int* tadpoles;

public:
    Bucket(int size) {
        tadpoles = new int[size];
    }

    ~Bucket() {
        delete[] tadpoles; // Cleaned up automatically.
    }
};
```

The idea of getting resources in the constructor and giving them back in the destructor, is important. It even has a name: RAII (Resource Acquisition Is Initialization).

In bigger programs, you'll often see classes split into two files. A header file (.h) has the declaration, and a source file (.cpp) has the definitions. Functions defined outside of the class use the class name and :: to denote which class they belong to.

```cpp
// Pond.h
#pragma once // Makes sure this header only gets included once.

class Pond {
public:
    void addFrog();
private:
    int frogCount;
};
```

```cpp
// Pond.cpp
#include "Pond.h" // Our headers use quotes instead of < >.

void Pond::addFrog() {
    frogCount++;
}
```

Now, inheritance. A class can inherit from another class using a colon. The child gets everything from the parent, and can add new things on top.

```cpp
class Animal {
public:
    void breathe() {
        cout << "Breathing";
    }
};

class Frog : public Animal {
public:
    void hop() {
        cout << "Hop";
    }
};
```

```cpp
    Frog lolfrog;
    lolfrog.breathe(); // From Animal
    lolfrog.hop();     // From Frog
```

Here's where cpp differs from Java and C#. If you want a child class to be able to override a function, the parent must mark it virtual. Without virtual, a parent pointer will ALWAYS call the parent's version, even if it's actually pointing to a child.

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "...";
    }
    virtual ~Animal() {} // If a class has virtual functions, give it a virtual destructor too!
};

class Frog : public Animal {
public:
    void speak() override { // override makes the compiler double check you are really overriding something.
        cout << "Ribbit!";
    }
};
```

```cpp
    Animal* someAnimal = new Frog();
    someAnimal->speak(); // Ribbit! Thanks to virtual.
    delete someAnimal;
```

This is polymorphism. Note that it only works through pointers or references. If you copy a Frog into a plain Animal variable, the Frog parts get taken off.

If you want a function that the parent has NO version of, and every child MUST write their own, you make it pure virtual with = 0. Any class with a pure virtual function is abstract, which means you can't make an object of it directly. This is how cpp does what other languages call interfaces. It's somewhat like a standardized format which children classes must follow.

```cpp
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};
```

Ease-of-use things now. We can use namespaces to our advantage. You must remember 'std'. You can make your own namespaces to keep names from clashing w/ each other:

```cpp
namespace swamp {
    int depth = 3;
}
```

```cpp
    cout << swamp::depth; // 3
```

By the way, "using namespace std;" at the top of a file is fine for small programs like this. In large projects, many people avoid it and just write std:: every time, since std has a LOT of names that could clash with yours.

Next, enums. An enum is a type with a fixed set of named values. I would prefer enum class, which keeps the names inside the enum (so you have to write Weather::Sunny instead of just Sunny):

```cpp
enum class Weather {
    Sunny,
    Rainy,
    Foggy
};
```

```cpp
    Weather today = Weather::Rainy;
    if (today == Weather::Rainy) {
        cout << "Great frog seeking day!!";
    }
```

We have auto. auto tells the compiler to figure out the type for you based on what you initialize it with. Don't forget, cpp is still strongly-typed! The type is just decided at compile time.

```cpp
    auto lilyPads = 42; // int
    auto swampName = string("Mud Puddle"); // string
```

Use it when the type is pretty obvious or verbose to type. Don't let it encourage lazy programing though.

Now templates. Say we want a function that returns the larger of two values. We'd need one for int, one for double, one for string... which is annoying to say the least. Templates let us write it ONCE, and cpp makes a version for each type we use.

```cpp
template <typename T>
T bigger(T a, T b) {
    return (a > b) ? a : b;
}
```

```cpp
    cout << bigger(3, 7);     // 7
    cout << bigger(2.5, 1.5); // 2.5
```

You can make template classes too. In fact, you've basically already been using one, which brings us to the Standard Template Library, or STL. The STL is a collection of readily made containers and tools. One of which is vector: it actually grows in size unlike array!

```cpp
#include <vector>
```

```cpp
    vector<int> frogWeights = {12, 15, 9};
    frogWeights.push_back(20); // Add to the end. It grows!!!
    cout << frogWeights.size(); // 4
    cout << frogWeights[0];     // 12
```

The type in the < > is the template part. It's what type the vector holds. For most everyday cpp, vector should be your go-to instead of a basic array (ew).

Similar to Java, we also have the range-based for loop, which goes through every element in a container. This works well w/ auto!

```cpp
    for (int weight : frogWeights) {
        cout << weight << " ";
    }

    for (auto& weight : frogWeights) { // Using a reference lets us change the elements.
        weight++;
    }
```

Another very handy container is map, which stores key and value pairs (like a dictionary or HashMap in other languages). A map keeps its keys sorted. If you don't need sorting, there is also unordered_map, which is usually faster.

```cpp
#include <map>
```

```cpp
    map<string, int> frogsPerPond;
    frogsPerPond["Cool Lake"] = 4;
    frogsPerPond["Mud Puddle"] = 1;

    for (auto& entry : frogsPerPond) {
        cout << entry.first << ": " << entry.second << endl; // first is the key, second is the value.
    }
```

There are many more containers (set, list, deque, stack, queue...), all of which are here: https://en.cppreference.com/w/cpp/container

The STL also has an <algorithm> header w/ functions that work on containers, like sort. These work using iterators, which are like pointers into a container. begin() points at the first element, and end() points one PAST the last element.

```cpp
#include <algorithm>
```

```cpp
    sort(frogWeights.begin(), frogWeights.end()); // Smallest to biggest
```

Sometimes you want to pass a small function into something like sort. Instead of writing a whole separate function, cpp lets you write a lambda right where you need it:

```cpp
    sort(frogWeights.begin(), frogWeights.end(), [](int a, int b) {
        return a > b; // Biggest to smallest this time
    });
```

The [] at the start is the capture list. It says which outside variables the lambda can use. [] means none, [=] means copies of everything, and [&] means references to everything.

```cpp
    int minWeight = 10;
    auto isHeavy = [minWeight](int w) { return w > minWeight; };
    cout << isHeavy(15); // 1 (true)
```

Remember how easy it is to leak memory? Smart pointers are our friend here. They are classes that hold a pointer and delete it for you in their destructor (RAII again!). They are in the <memory> header.

```cpp
#include <memory>
```

unique_ptr is the one most frequently used. Only ONE unique_ptr can own an object at a time. When it gets out of scope, the object is deleted.

```cpp
    unique_ptr<Frog> lolfrog(new Frog());
    lolfrog->hop(); // Works just like a normal pointer
    // No delete necessary
```

shared_ptr lets multiple pointers own the same object. It keeps count of how many owners there are, and deletes the object when the last one is gone.

```cpp
    shared_ptr<Frog> mizuki = make_shared<Frog>();
    shared_ptr<Frog> alsoMizuki = mizuki; // Two owners now
```

(In C++14 and later, you'll also see make_unique<Frog>(), which is the preferred way to make a unique_ptr.) In modern cpp, you should rarely need to write new and delete yourself.

Last but not least, errors. When something goes wrong, you can throw an exception and catch it. This should look familiar if you've used try/catch before.

```cpp
#include <stdexcept>
```

```cpp
int divideFrogs(int frogs, int ponds) {
    if (ponds == 0) {
        throw invalid_argument("Division by zero!");
    }
    return frogs / ponds;
}
```

```cpp
    try {
        divideFrogs(10, 0);
    } catch (const invalid_argument& e) {
        cout << e.what(); // Division by zero!
    }
```

Note that we catch by const reference. That's the usual way to do it in cpp. Unlike some languages, cpp does NOT have a finally block. Instead, cleanup is done by destructors and RAII.

To run any of what you wrote you need to compile it. With g++, it's as follows:

```
g++ -std=c++11 SyntaxBasics.cpp -o SyntaxBasics
./SyntaxBasics
```

The -std=c++11 flag tells the compiler which version of cpp to use. Most newer compilers default to something more recent, but it doesn't hurt to be specific.

That's about it! There's a lot more, but with all this, you should be able to read and write most everyday cpp. Everything else can be found here: https://en.cppreference.com

Have fun?!