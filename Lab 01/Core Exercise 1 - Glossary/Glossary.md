Glossary
========

Artifacts / Actions
-------------------

An artifact is any product that has been created during the development and maintance of a piece of software to help describe the function, architecture or design of the software or to manage the process of designing the software itself. For example, use cases, class diagrams, UML models, software requirement/specification documents, project plans, business cases, risk assesments, source and executable code, configuration files, test data and scripts and documentation could all be considered an artifact of a software development project.

### Class

A class is a template for defining the characteristics and operation of an object instances, listing all fields, properties, constructors and methods that the object can have.

    class Rectangle {
        private:
            /* fields */
            int _x;
            int _y;

        public:
            /* constructor */
            Rectangle(int x, int y) { 
                _x = x;
                _y = y;
            }

            /* accessor methods */
            int getX() { return _x; }
            int getY() { return _y; }

            /* methods */
            int area() { return (_x * _y); }
    }

#### Fields

A field of a class is a declaration of an object's ability to store data. These fields are typically private to the class and can only be accessed using accessor methods or properties.

#### Properties *(a.k.a. accessor methods)*

A property of a class is typically implemented using accessor methods, functions whose sole purpose are to control the access to setting and getting data from a class's private data fields. A property is typically accessed by other objects as if it were a field however compilers ensure that the correct accessor methods are used and no direct access to private fields is allowed.
Accessor methods or "Getters" only return the value of a data field; Mutator methods or "Setters" only set a value of a data field.

#### Constructors

The constructor is called when a new object is created to initalise all the fields of an object and do any other set-up or processing required for the creation of a new object.

#### Methods

Methods give an object of a class it's ability to *do* something, they can implement functional code and processing of data of it's own instance and other objects.

### Object

An object is an instance of a class. While a class defines the characteristics and operation of a type of objects, an object contains it's own data to make the operations relevant.

#### Declaring variables to refer to objects

#### Creating an object

#### Method Calls (How to pass a message to an object)

### Built in types (numeric, text and others)

### Arrays

### Enumerations

Enumerations are variables that can contain only one of a limited set of values. Each value is typically assigned a symbol or name so that it's value can be referenced symbolically and the compiler can decide what underlying values to generate for each symbol during compilation.

Sources
-------
 * [Artifact (Software Development) - Wikipedia](http://en.wikipedia.org/wiki/Artifact_(software_development))
 * [Artifact (Stanford Encyclopedia of Philosophy)](http://plato.stanford.edu/entries/artifact/)
 * [Software engineering mini glossary](http://www.idi.ntnu.no/grupper/su/publ/ese/se-defs.html)
 * [Identifying Object-Oriented Classes](http://www.codeproject.com/Articles/9900/Identifying-Object-Oriented-Classes)
 * [Class Tutorial - C++ Documentation](http://www.cplusplus.com/doc/tutorial/classes/)