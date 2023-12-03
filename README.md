# LearningCpp

This Repo is intended to keep my learning progress on the topics of CPP. The main ideal for C++ Programming is to express concepts(ideas, notions, etc.) from a design directly in code.
#### Represent ideas, relationships among ideas in code
#### Represent independent ideas independently in code
#### Keep simple things simple without making complex things impossible.

## DemoPrograms Folder
### Template Programming
Templates are used for generic metaprogramming when a specific pattern or behaviour shall be provided to an arbitrary set of different types. 
Templates are used by the compiler as code generators to build type safe data containers.

Templates are parameter based. There are two parameter kinds allowed to be used for tem-plate implementations. The first kind is all kind of data types (structs, classes, standard types like chars). The second kind are non-type parameters. 
These are either constant integers (or enums values) or constant pointers to data or functions.

Based on the given parameters of an instantiated or called template, the compiler decides which variant of the template has to be compiled by replacing the template parameters with the provided types.

There are two kinds of templates. Function templates and class templates. Class templates can be used for structs, classes and unions.

A template is not a type, but only a pattern, that tells the compiler how to generate a type based on template parameters. 
That means that for each template, that is used with different template parameter types in the code, the compiler defines independent types, 
that consume independent memory resources.

### Simple Shell using CPP
This simple shell reads user input, splits it into arguments, and then forks a child process to execute the specified command. The execvp function is used to replace the child process's image with the specified command. The parent process waits for the child process to finish using waitpid.

### Abstract Types Demo
An abstract type is a type that completely insulates a user from implementation details. To do that, we decouple the interface from the representation and give up genuine local variables. Since we don’t know anything about the representation of an abstract type (not even its size), we must allocate objects on the free store and access them through references or pointers.

### Count number of Bytes in a file
A simple version of wc that takes the command line option -c and outputs the number of bytes in a file.

About the line:
`std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>())`

1. `std::istreambuf_iterator<char>(file)`: This part creates an input iterator (std::istreambuf_iterator) for reading characters
    from the file. It's used to iterate over the contents of the file.
2. `std::istreambuf_iterator<char>()`: It's used as the ending iterator for the range.
    When used like this, it signifies the end of the stream. This explicitly specifies the type for the ending iterator. 
3. `std::vector<char>`: This is the type of the vector that we are creating. In this case, it's a vector of characters.

The entire line is essentially using the range constructor of std::vector. This constructor takes two iterators representing the
range to copy. In this case, it uses the iterators created from the file to copy the contents of the file into the vector.
So, the `buffer` vector is being initialized with the contents of the file, and the type of elements in the vector is `char`.
After this line, the `buffer` vector contains all the characters from the file, effectively representing the file content.

Check Notes section in cpp file to learn more...

### I/O of User-Defined Types
In addition to the I/O of builtin types and standard `string`s, the `iostream` library allows programmers to define I/O for their own Types.
Here a `struct` type taken as simple example. Outputtuing is straightforward. The corresponding input operator is more complicated.

Note, The `is>>c` skips whitespace by default, but `is.get(c)` does not, so that this `Entry` - input operator ignores(skips) whitespace
outside the name string, but not within it.

## EbpInterpreter
### Journey to the center of a language interpretation

EbpInterpreter is a full functional interpreter for a scripting language. In this personal project I am focusing on learning the background of a language
journey from the high level stream of englist characters to the low level or machine understandable string of one's and zero's.

In this Project, I explore the world of Compilers, Interpreters, and how they work underhood by building one from the scratch!

Exciting journey of learning in Progress...
