Glossary
========

Artifacts / Actions
-------------------

An artifact is any product that has been created during the development and maintance of a piece of software to help describe the function, architecture or design of the software or to manage the process of designing the software itself. For example, use cases, class diagrams, UML models, software requirement/specification documents, project plans, business cases, risk assesments, source and executable code, configuration files, test data and scripts and documentation could all be considered an artifact of a software development project.

### Class

A class is a template for defining the characteristics and operation of an object, listing all fields, properties, constructors and methods that the object can have. The class is also responsible for the creation of new objects.

```c++
class Rectangle {
    private:
        /* private data fields */
        int _x;
        int _y;

    public:
        /* constructor */
        Rectangle(int x, int y) { 
            _x = x;
            _y = y;
        }

        /* accessor methods ("getters") */
        int getX() { return _x; }
        int getY() { return _y; }

        /* mutator methods ("setters") */
        void setX(int x) { _x = x; }
        void setY(int y) { _y = y; }

        /* methods */
        int area() { return (_x * _y); }
}
```

**Note:** typically in C++, the class declaration is listed in a header file, and the class implentation is listed separately. When this is done, the class must be explictly refered to in the form of `<return_type> <class_name>::<method>(<parameters>) { ... }`

#### Fields

A field of a class is a declaration of an object's ability to store data. These fields are typically private to the class and can only be accessed using accessor methods or properties.

#### Properties *(a.k.a. accessor methods)*

A property of a class is typically implemented using accessor methods, functions whose sole purpose are to control the access to setting and getting data from a class's private data fields. A property is typically accessed by other objects as if it were a field however compilers ensure that the correct accessor methods are used and no direct access to private fields is allowed.
Accessor methods or "Getters" only return the value of a data field; Mutator methods or "Setters" only set a value of a data field.

#### Constructors

The constructor is called when a new object is created to initalise all the fields of an object and do any other set-up or processing required for the creation of a new object. A constructor may contain parameters to initially set the internal state of the object to the desired values rather than to first initialise to static constants that then must be overwritten using properties. 
For example in a card game, a Card class may have a constructor with parameters for which suit and rank of card it should represent. 

#### Methods

Methods give an object of a class it's ability to *do* something, they can implement functional code and processing of data of it's own instance and other objects.

#### Static Members

A static member of a class is something that is attached to the class's class object rather than being a part of each object. There is usually only one class object for a bunch of objects, this means that the field or method is essentially shared between all objects.

### Object

An object is an instance of a class. While a class defines the characteristics and operation of a type of objects, an object contains it's own data to make the operations relevant. Each object is distinct and unique, calling a method or changing the property of one object will not change every other object of that class. The object is central to the concept of Object-Oriented programming - the idea being that rather than separate by data and functions like in procedural programming, we can design programs around Objects that we can see in the real (or imaginary) world, and use these Objects as the building blocks of our program that encapsulate their own data and state. 

#### Declaring variables to refer to objects

The common method of refering to objects is to hold onto pointers to them.

```c++
Rectangle * my_rect;
```

#### Creating an object

Objects are created by their class in two steps, first the class must allocate enough memory to hold the object, and then it must initalise the object. In C++ this is done as one step when calling the class constructor with the 'new' keyword. 

```c++
my_rect = new Rectangle(1,2);
```

#### Method Calls (How to pass a message to an object)

Method calls are done "on" the object itself, so when using pointers to objects, they must be dereferenced. C++ allows us to use the `->` operator to call methods on the dereferenced pointer of the object.

```c++
int area = my_rect->area();
```

### Built in types (numeric, text and others)

#### Boolean types

C++ allows for Boolean types to be created using the `bool` datatype.

```c++
bool isCool = true;
bool isFinished = false;
```

#### Numeric types

C++ allows for the same numeric types as C, for example, `int`, `double`, `float`, etc. The size and range of the actual variable depends on the compiler and architecture, except for `char` which is standardised as 8-bits (1 byte).

#### String types

C++ has a special String class for creating and manlipulating String objects in the `std` namespace. C-style strings are still supported.

```c++
using namespace std;
string myString("Hello World");
cout << myString << endl;

// getting the length is easy as it is the same as a method call
cout << "String Length: " << myString.length() << endl;

// concaternation of strings is built-in
myString += " Again";
cout << myString << endl;

// so is comparison
if (myString == "Hello World Again") {
    cout << "See?" << endl;
}
```

### Arrays

Arrays are declared in the form `<data_type> <variable_name>[<size>];` the same way as C.

```c++
using namespace std;
int my_array[] = {1,2,3,4,5};
my_array[2] = 0;
cout << "Element #3 of the array is: " << my_array[2] << endl;
```

### Enumerations

Enumerations are variables that can contain only one of a limited set of values. Each value is typically assigned a symbol or name so that it's value can be referenced symbolically and the compiler can decide what underlying values to generate for each symbol during compilation.

Statements
----------

### Basic Statements

#### Assignment Statement
Assignments are done with the `=` symbol, with the variable name on the left, and the value you are assigning on the right.

```c++
my_variable = 55;
```

#### Method Calling

Methods are called in C++ using the name of the method followed by brackets () with parameters contained within them if nesicarry, separated by a comma.

```c++
my_method(); /* execute the my_method method with no parameters */
my_other_method(42, "hello"); /* execute the method with parameters 42 and "hello" */
```

#### Returning a value 

Returning a value from a function/method is done with the `return` statement.

```c++
int MyClass::MyMethod()
{
    return 55;
}
```

### Control Flow Statements

#### If Statement

The if statement is a basic conditional expression that will run the bit of code in the braces (or the next line if there are no braces). The first condition in an if..else if...else statement is the one that is executed, all others are skipped.

```c++
if (my_variable == 52) {
    // execute this code
} else if (my_other_variable == 51.555) {
    // execute this code
} else {
    // execute this code
}
```

#### Case Statement

The case statement selects a code path based on the value of the variable. It is mutually-exclusive and exhaustive of all options.

```c++
switch(my_variable) {
    case 0: /* this section of code is run if my_variable == 0 */
        // do something
        break; /* break is required to tell the compiler where to finish */
    case 52: /* this section of code is run if my_variable == 52 */
        // do something else
        break;
    default: /* this section of code is run if none of the above conditions are true */
        // do something else
}
```

#### While Loop

A while loop will enter the loop and continue when the condition in the brackets evaluates true.

```c++
while (running) { /* the condition here is when running is true */
    // do some task
}
```

The code within the curly braces will be executed again and again. It will be stopped only when running is no longer true, or if inside the while block the `break` statement is used. The `continue` statement is used to stop the current execution of the loop but continue again at the start of the loop if the condition is still true.

#### Do ... While Loop

A do...while loop is the same as a while loop except that it is guaranteed to run at least once, the condition is only checked after the first execution of the loop

```c++
do {
    // do some task
} while (my_patience > 52); /* the condition here is when the value of my_patience is greather than 52 */
```

#### For Loop

A for loop is a finite loop usually used for counting or iterating over an array of known length.
The first part of the for loop is the initaliser expression that defines the initial value of a variable, the second part is the conditional expression that must be true for the loop to start and continue looping, and the third part is the expression that increments the value in some way.

```c++
for (int i = 0; i < 2; i++ ) {
    cout << "Hello" << endl; // will be printed 2 times
}
```

### Language Naming Conventions

Identifiers should be clear and name what the class or variable is or contains respectively. They should not start with underscores, and should not be the same as another identifier with different case. Abbreviations should be avoided.

*Class:* Noun in Pascal Case, e.g. `Card`

*Preprocessor Macro:* In All Uppercase, e.g. `CARD_HEIGHT`

*Enumeration Type:* An Abbreviation of what the enum represents in Pascal Case, e.g. `CardRank`

*LocalVariable:* Camel Case, e.g. `myCard`

*Method:* Verbs or verb phrases in Camel Case, e.g. `turnOver`

*Namespace:* Camel Case, e.g. `system`

*Parameter:* A descriptive name clearly identifing purpose in Camel Case, without prefixes, e.g. `value`

Sources
-------
 * HIT3172 Lectures
 * [Artifact (Software Development) - Wikipedia](http://en.wikipedia.org/wiki/Artifact_(software_development))
 * [Artifact (Stanford Encyclopedia of Philosophy)](http://plato.stanford.edu/entries/artifact/)
 * [Software engineering mini glossary](http://www.idi.ntnu.no/grupper/su/publ/ese/se-defs.html)
 * [Identifying Object-Oriented Classes](http://www.codeproject.com/Articles/9900/Identifying-Object-Oriented-Classes)
 * [Class Tutorial - C++ Documentation](http://www.cplusplus.com/doc/tutorial/classes/)
 * [Swinburne C++ Coding Recommendations - Swinbrain](http://swinbrain.ict.swin.edu.au/wiki/C_Plus_Plus_coding_recommendations)