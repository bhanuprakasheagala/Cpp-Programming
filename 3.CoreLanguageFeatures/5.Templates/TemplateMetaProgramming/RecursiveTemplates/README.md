# Recursive Templates in C++

## Overview

Recursive templates in C++ are a powerful feature of Template Metaprogramming (TMP), allowing you to perform computations at compile time using recursive instantiations of templates. This technique enables the creation of flexible, highly optimized, and generic code by leveraging recursion to break down problems into simpler subproblems that are solved at compile-time.

A recursive template works by repeatedly instantiating a template with modified parameters, with each instantiation leading closer to a base case that terminates the recursion. The result of the recursion is determined during compilation rather than at runtime.

This document will focus specifically on the concept and syntax of **recursive templates** in C++.

---

## How Recursive Templates Work

A recursive template involves two primary components:

1. **Recursive Case**: A template that calls itself with modified parameters.
2. **Base Case**: A template specialization or condition that stops the recursion.

At compile time, the recursive template will instantiate itself with a reduced set of parameters, eventually reaching the base case. This mechanism allows complex computations to be done during compilation, reducing runtime overhead.

### Basic Structure of Recursive Templates

A recursive template generally consists of:

- **Primary Template**: A template that recursively calls itself with modified parameters.
- **Template Specialization (Base Case)**: A specialized template that provides the termination condition for the recursion.

#### Example Pattern of a Recursive Template

```cpp
template <typename T, int N>
struct factorial {
    static const int value = N * factorial<T, N - 1>::value;  // Recursive call
};

template <typename T>
struct factorial<T, 0> {
    static const int value = 1;  // Base case
};
```

In this example:

1. **Recursive Case**: The template `factorial<T, N>` calls itself with `factorial<T, N-1>`.
2. **Base Case**: The specialization `factorial<T, 0>` terminates the recursion and returns 1.

### Template Instantiation Process

When a recursive template is used, the compiler instantiates the templates and performs the recursive calls until the base case is reached.

For example, when evaluating `factorial<int, 5>::value`:

- The compiler first instantiates `factorial<int, 5>` and computes `5 * factorial<int, 4>::value`.
- Then, it instantiates `factorial<int, 4>` and computes `4 * factorial<int, 3>::value`.
- This continues until `factorial<int, 0>::value` is reached, which returns `1`.
- Finally, the results of the recursive calls are multiplied together: `5 * 4 * 3 * 2 * 1`.

The entire process occurs at compile time, resulting in a constant value that can be used wherever needed.

---

## Common Recursive Template Use Cases

Recursive templates are useful in many situations where compile-time computation is beneficial. Here are some common patterns:

### 1. **Factorial Calculation**

The classic example of a recursive template is calculating the factorial of a number.

```cpp
template <int N>
struct factorial {
    static const int value = N * factorial<N - 1>::value;
};

template <>
struct factorial<0> {
    static const int value = 1;
};
```

This calculates the factorial of `N` at compile time, and the final result is available as a constant expression.

### 2. **Fibonacci Sequence**

Another example is calculating the Fibonacci sequence:

```cpp
template <int N>
struct fibonacci {
    static const int value = fibonacci<N - 1>::value + fibonacci<N - 2>::value;
};

template <>
struct fibonacci<0> {
    static const int value = 0;
};

template <>
struct fibonacci<1> {
    static const int value = 1;
};
```

This recursively computes the Fibonacci number for `N` at compile time.

### 3. **Type Traits**

Recursive templates can be used to define type traits, which are templates that inspect or manipulate types. For instance, determining the size of a type recursively:

```cpp
template <typename T>
struct size_of {
    static const int value = 1 + size_of<typename T::next>::value;  // Recursive case
};

template <>
struct size_of<int> {
    static const int value = 1;  // Base case for int
};
```

This example calculates the size of a type using recursion. The base case returns `1` for `int`, and for types that contain other types (like a linked list), the recursion will continue.

---

## Recursion with Variadic Templates

With the introduction of **variadic templates** in C++11, recursive templates can now handle an arbitrary number of template parameters. This allows for more generalized recursive templates.

Here’s an example of recursive templates with variadic templates:

```cpp
template <typename T>
void print_types() {
    std::cout << typeid(T).name() << std::endl;  // Print type of T
}

template <typename T, typename... Args>
void print_types(T t, Args... args) {
    std::cout << typeid(T).name() << std::endl;  // Print type of T
    print_types(args...);  // Recursively print remaining types
}
```

This template recursively prints the types of the given parameters.

### Breakdown of the Example:
- The **base case** (`print_types<T>`) handles the final type in the parameter list.
- The **recursive case** (`print_types<T, Args...>`) prints the current type and recursively processes the rest of the parameter pack (`args...`).

---

## Important Considerations

While recursive templates are a powerful tool, there are some important considerations:

1. **Base Case is Essential**: Always ensure that the recursion has a termination point, or else it will lead to infinite recursion and cause a compile-time error.

2. **Template Instantiation Depth**: Recursive templates can result in deep template instantiations, which could cause problems in compilers that have limits on recursion depth. For example, a very large value for `N` in a factorial calculation might exceed the compiler's instantiation depth limit.

3. **Performance**: Since recursive templates are resolved at compile time, the recursion cost is effectively "paid" at compile time. However, complex recursions may lead to longer compilation times. In some cases, using `constexpr` functions may provide a more efficient alternative for simpler recursion.

4. **Template Specialization**: Recursive templates often rely heavily on template specialization for base cases. It’s crucial to handle these edge cases properly to ensure correctness.

---

## Conclusion

Recursive templates in C++ are a powerful feature of Template Metaprogramming that allow you to perform computations at compile time. By leveraging recursive instantiation and template specialization, you can create efficient, flexible, and highly generic solutions. Recursive templates are useful for tasks such as calculating factorials, generating Fibonacci sequences, and manipulating types in type traits. They are an essential tool for anyone working with TMP in C++, and mastering them can lead to highly optimized and more maintainable code.