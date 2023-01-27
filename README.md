# LearningCpp

This Repo is intended to keep my learning progress on the topics of CPP. The topics that are both important and useful in real world applications.

# Template Programming
Templates are used for generic metaprogramming when a specific pattern or behaviour shall be provided to an arbitrary set of different types. 
Templates are used by the compiler as code generators to build type safe data containers.

Templates are parameter based. There are two parameter kinds allowed to be used for tem-plate implementations. The first kind is all kind of data types (structs, classes, standard types like chars). The second kind are non-type parameters. 
These are either constant integers (or enums values) or constant pointers to data or functions.

Based on the given parameters of an instantiated or called template, the compiler decides which variant of the template has to be compiled by replacing the template parameters with the provided types.

There are two kinds of templates. Function templates and class templates. Class templates can be used for structs, classes and unions.

A template is not a type, but only a pattern, that tells the compiler how to generate a type based on template parameters. 
That means that for each template, that is used with different template parameter types in the code, the compiler defines independent types, 
that consume independent memory resources.
