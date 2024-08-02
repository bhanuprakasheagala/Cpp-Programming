# Templates : Generic and Reusable Code

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

The process of replacing template parameters by concrete types is called _instantiation_. It results in an _instance_ of a template.
Note that the mere use of a function template can trigger such an instantiation process. There is no need for the programmer to request the instantiation separately.
<br/>Similarly, the other calls of max() instantiate the max template for double and std::string as if they were declared and implemented individually:
```
double max (double, double);
std::string max (std::string, std::string);
```
Note also that void is a valid template argument provided the resulting code is valid. For example:
```
template<typename T>
T foo(T*)
{
}
void* vp = nullptr;
foo(vp);            // OK: deduces void foo(void*)
```

## **Partial Template Specialization**

Partial template specialization enables you to define different implementations of a template for some but not all types of template parameters. This allows you to handle variations in types more flexibly than full specialization, which applies to specific types only.

### **Why Use Partial Template Specialization?**

Partial specialization is useful when you want to provide specialized behavior for specific patterns of template parameters while still keeping a general template for other cases. This is particularly helpful in generic programming where you might need different implementations based on the types or the number of template parameters.

### **Syntax of Partial Template Specialization**

The syntax for partial template specialization involves providing a specialized version of a template that matches a subset of possible template arguments. Here’s how you generally write it:

1. **Primary Template:**

   This is the general template that applies to most types.

   ```cpp
   template <typename T, typename U>
   class Pair
   {
   public:
       Pair(T first, U second) : first(first), second(second) {}
       T getFirst() const { return first; }
       U getSecond() const { return second; }

   private:
       T first;
       U second;
   };
   ```

2. **Partial Specialization:**

   This is a specialized version of the template that applies to a specific pattern of the template parameters.

   ```cpp
   template <typename T>
   class Pair<T, T>
   {
   public:
       Pair(T first, T second) : first(first), second(second) {}
       T getFirst() const { return first; }
       T getSecond() const { return second; }
       T getSum() const { return first + second; }

   private:
       T first;
       T second;
   };
   ```

   Here, the partial specialization is for the case where both template parameters are the same type (`T`).

### **Detailed Example:**

Consider a class `Pair` that holds a pair of values:

#### **Primary Template:**

```cpp
template <typename T, typename U>
class Pair
{
public:
    Pair(T first, U second) : first(first), second(second) {}
    T getFirst() const { return first; }
    U getSecond() const { return second; }

private:
    T first;
    U second;
};
```

This general `Pair` class can hold any two types, `T` and `U`. It has methods to access these values.

#### **Partial Specialization:**

Let's say we want a specific behavior when `T` and `U` are the same type. For example, we might want to add the values together if they are of the same type. We can use partial specialization to handle this case:

```cpp
template <typename T>
class Pair<T, T>
{
public:
    Pair(T first, T second) : first(first), second(second) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }
    T getSum() const { return first + second; }

private:
    T first;
    T second;
};
```

Here’s how this specialization works:

- **General Template:** `Pair<T, U>` is used for pairs where `T` and `U` can be different types.
- **Specialized Template:** `Pair<T, T>` is used when both types are the same. It provides an additional method, `getSum()`, which computes the sum of the two values.

### **Usage Example:**

```cpp
#include <iostream>

int main()
{
    // Using the general template
    Pair<int, std::string> pair1(1, "Hello");
    std::cout << "First: " << pair1.getFirst() << ", Second: " << pair1.getSecond() << std::endl;

    // Using the partial specialization
    Pair<int> pair2(3, 4);
    std::cout << "First: " << pair2.getFirst() << ", Second: " << pair2.getSecond() << std::endl;
    std::cout << "Sum: " << pair2.getSum() << std::endl;

    return 0;
}
```

In this example:
- `pair1` uses the general `Pair<int, std::string>` template.
- `pair2` uses the specialized `Pair<int, int>` template and can access the `getSum()` method.

### **Rules for Partial Specialization:**

1. **Substitution:** The partial specialization is selected if the provided template arguments match the specialized pattern. If they don’t, the primary template is used.
2. **Less Specific Specializations:** You can have multiple partial specializations, each targeting different patterns of template arguments.
3. **Restrictions:** You cannot partially specialize function templates, but you can use `std::enable_if` or SFINAE to achieve similar results.
