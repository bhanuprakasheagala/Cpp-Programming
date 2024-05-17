# Template Meta Programming

## Introduction
Templates are used for generic metaprogramming when a specific pattern or behaviour shall be provided to an arbitrary set of different types. 
Templates are used by the compiler as code generators to build type safe data containers.

Templates are parameter based. There are two parameter kinds allowed to be used for tem-plate implementations. The first kind is all kind of data types (structs, classes, standard types like chars). The second kind are non-type parameters. 
These are either constant integers (or enums values) or constant pointers to data or functions.

Based on the given parameters of an instantiated or called template, the compiler decides which variant of the template has to be compiled by replacing the template parameters with the provided types.

There are two kinds of templates. Function templates and class templates. Class templates can be used for structs, classes and unions.

A template is not a type, but only a pattern, that tells the compiler how to generate a type based on template parameters. 
That means that for each template, that is used with different template parameter types in the code, the compiler defines independent types, 
that consume independent memory resources.

## Function Templates
Function templates provide a functional behavior that can be called for different types. In other words, a function template represents a family of functions. The representation looks a lot like an ordinary function, except that some elements of the function are left undetermined: These elements are parameterized.

```
template <typename T>
T max(T a, T b) {
  // if b<a then yield a, else yield b
  return b < a ? a : b;
}
```
The keyword typename introduces a type parameter. Here, the type parameter is T. You can use any identifier as a parameter name, but using T is the convention. The type parameter represents an arbitrary type that is determined by the caller when the caller calls the function. You can use any type (fundamental type, class, and so on) as long as it provides the operations that the template uses. In this case, type T has to support operator < because a and b are compared using this operator. Perhaps less obvious from the definition of max() is that values of type T must also be copyable in order to be returned.

**Using the Template**

```
int i = 42;
std::cout << "max(7, i): " << ::max(7,i) << '\n';

double f1 = 3.4;
double f2 = -6.7;
std::cout << "max(f1, f2): " << ::max(f1, f2) << '\n';

std::string s1 = "mathematics";
std::string s2 = "math";
std::cout << "max(s1,s2): " << ::max(s1,s2) << '\n';
```
Inside the program, max() is called three times: once for two ints, once for two doubles, and once for two std::strings. Each time, the maximum is computed. As a result, the program has the following output: <br/>
max(7,i):   42 <br/>
max(f1,f2): 3.4 <br/>
max(s1,s2): mathematics <br/>

Note that each call of the max() template is qualified with ::. This is to ensure that our max() template is found in the global namespace. There is also a std::max() template in the standard library, which under some circumstances may be called or may lead to ambiguity.

Templates aren’t compiled into single entities that can handle any type. Instead, different entities are generated from the template for every type for which the template is used.4 Thus, max() is compiled for each of these three types. For example, the first call of max() <br/>
int i = 42; <br/>
... max(7, i) ... <br/>
uses the function template with int as template parameter T. Thus, it has the semantics of calling the following code:
```
int max (int a, int b){
  return b<a?a:b;
}
```
