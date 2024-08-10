# C++ Standard Template Library (STL)

Welcome to the **C++ Standard Template Library (STL)** repository! This repository is a comprehensive guide and reference to the C++ STL, covering all the essential components, data structures, and algorithms that are part of the library.

## Table of Contents

1. [Introduction](#introduction)
2. [Containers](#containers)
   - [Sequence Containers](#sequence-containers)
   - [Associative Containers](#associative-containers)
   - [Unordered Containers](#unordered-containers)
   - [Container Adaptors](#container-adaptors)
3. [Iterators](#iterators)
   - [Iterator Categories](#iterator-categories)
   - [Iterator Functions](#iterator-functions)
4. [Algorithms](#algorithms)
   - [Non-Modifying Algorithms](#non-modifying-algorithms)
   - [Modifying Algorithms](#modifying-algorithms)
   - [Sorting Algorithms](#sorting-algorithms)
   - [Set Operations](#set-operations)
5. [Utilities](#utilities)
   - [Pairs and Tuples](#pairs-and-tuples)
   - [Function Objects (Functors)](#function-objects-functors)
   - [Type Traits](#type-traits)

## Introduction

The C++ Standard Template Library (STL) is a powerful collection of generic classes and functions that provide support for common data structures, algorithms, and iterators. It is an essential component of modern C++ programming, offering a wide range of functionalities that enable developers to write efficient, reusable, and maintainable code.

## Containers

Containers are the backbone of the STL, providing ways to store and organize data efficiently.

### Sequence Containers

#### Vector

- **Description:**  
  `std::vector` is a dynamic array that can grow or shrink in size. It provides fast access to elements through an index and supports efficient insertion and deletion at the end.

- **Syntax/Template:**  
  ```cpp
  std::vector<T> vec;
  ```
  Here, `T` is the type of the elements.

- **Important Methods:**
  - `push_back(const T& value)`: Adds an element to the end.
  - `pop_back()`: Removes the last element.
  - `at(size_t pos)`: Returns a reference to the element at the given position with bounds checking.
  - `size()`: Returns the number of elements in the vector.
  - `resize(size_t count)`: Resizes the container to contain `count` elements.

- **Use Cases in Real-World Applications:**
  - **Gaming:** Storing dynamic entities like players, enemies, and projectiles in a game.
  - **GUI Applications:** Maintaining a list of UI components like buttons, labels, etc.
  - **Data Processing:** Managing a list of data points in scientific simulations.

#### List

- **Description:**  
  `std::list` is a doubly linked list that allows for constant time insertions and deletions from anywhere in the sequence. However, accessing elements by index is slower compared to `std::vector`.

- **Syntax/Template:**  
  ```cpp
  std::list<T> lst;
  ```
  Here, `T` is the type of the elements.

- **Important Methods:**
  - `push_back(const T& value)`: Adds an element to the end.
  - `push_front(const T& value)`: Adds an element to the beginning.
  - `pop_back()`: Removes the last element.
  - `pop_front()`: Removes the first element.
  - `insert(iterator pos, const T& value)`: Inserts an element before the specified position.

- **Use Cases in Real-World Applications:**
  - **Web Browsers:** Maintaining a history of visited web pages.
  - **Operating Systems:** Implementing task scheduling algorithms where tasks need to be added/removed dynamically.
  - **Music Players:** Managing a playlist where songs can be added/removed from both ends.

#### Deque

- **Description:**  
  `std::deque` (Double-Ended Queue) is a sequence container that allows for fast insertions and deletions at both the front and back. It is implemented as a dynamic array of fixed-size arrays, providing the functionality of both `std::vector` and `std::list`.

- **Syntax/Template:**  
  ```cpp
  std::deque<T> dq;
  ```
  Here, `T` is the type of the elements.

- **Important Methods:**
  - `push_back(const T& value)`: Adds an element to the end.
  - `push_front(const T& value)`: Adds an element to the beginning.
  - `pop_back()`: Removes the last element.
  - `pop_front()`: Removes the first element.
  - `at(size_t pos)`: Returns a reference to the element at the given position with bounds checking.

- **Use Cases in Real-World Applications:**
  - **Real-Time Systems:** Implementing task queues where tasks are dynamically added or removed from both ends.
  - **Simulations:** Managing events in a time-ordered sequence, where events can be added to both ends of the queue.
  - **Web Servers:** Handling requests where both FIFO and LIFO orders are required.

### Associative Containers

#### Set

- **Description:**  
  `std::set` is an associative container that stores unique elements in a sorted order. It provides fast lookup, insertion, and deletion operations.

- **Syntax/Template:**  
  ```cpp
  std::set<T> s;
  ```
  Here, `T` is the type of the elements.

- **Important Methods:**
  - `insert(const T& value)`: Inserts an element if it is not already present.
  - `find(const T& value)`: Finds an element and returns an iterator to it.
  - `erase(iterator pos)`: Removes the element at the specified position.
  - `count(const T& value)`: Returns the number of elements with a specific value (0 or 1 for `set`).

- **Use Cases in Real-World Applications:**
  - **Database Management:** Implementing indexes where unique constraints need to be enforced.
  - **Network Systems:** Maintaining a set of unique IP addresses connected to a server.
  - **Security Applications:** Storing a set of unique user identifiers (UIDs) for authentication.

#### Map

- **Description:**  
  `std::map` is an associative container that stores elements in key-value pairs, with unique keys. The elements are sorted by the key, and it allows fast retrieval based on the key.

- **Syntax/Template:**  
  ```cpp
  std::map<Key, T> m;
  ```
  Here, `Key` is the type of the keys, and `T` is the type of the mapped values.

- **Important Methods:**
  - `insert(const std::pair<Key, T>& value)`: Inserts a key-value pair if the key is not already present.
  - `find(const Key& key)`: Finds the element with the specified key and returns an iterator to it.
  - `at(const Key& key)`: Returns a reference to the mapped value of the element with the specified key.
  - `erase(const Key& key)`: Removes the element with the specified key.

- **Use Cases in Real-World Applications:**
  - **Configuration Systems:** Storing configuration settings as key-value pairs.
  - **Compiler Design:** Implementing symbol tables where variable names are mapped to their attributes.
  - **Financial Systems:** Managing account information, where account numbers are mapped to customer details.
 
---
### Algorithms

#### Sorting Algorithms

##### std::sort

- **Description:**  
  `std::sort` is a highly optimized algorithm used to sort elements in a range. It generally uses a hybrid of quicksort, heapsort, and insertion sort, providing a good balance between performance and stability.

- **Syntax/Template:**  
  ```cpp
  std::sort(RandomIt first, RandomIt last);
  ```
  Here, `RandomIt` is a random access iterator pointing to the first and last elements of the range to be sorted.

- **Important Methods:**
  - `std::sort(RandomIt first, RandomIt last)`: Sorts the elements in ascending order by default.
  - `std::sort(RandomIt first, RandomIt last, Compare comp)`: Sorts the elements using a custom comparator.

- **Use Cases in Real-World Applications:**
  - **E-commerce:** Sorting products by price, rating, or popularity.
  - **Data Analysis:** Sorting data points for statistical analysis.
  - **Event Management:** Ordering events by time in a scheduling application.

##### std::stable_sort

- **Description:**  
  `std::stable_sort` is a sorting algorithm that maintains the relative order of equivalent elements. It is typically implemented using a combination of merge sort, which ensures stability while sorting.

- **Syntax/Template:**  
  ```cpp
  std::stable_sort(RandomIt first, RandomIt last);
  ```
  Here, `RandomIt` is a random access iterator pointing to the first and last elements of the range to be sorted.

- **Important Methods:**
  - `std::stable_sort(RandomIt first, RandomIt last)`: Sorts the elements in ascending order while maintaining stability.
  - `std::stable_sort(RandomIt first, RandomIt last, Compare comp)`: Sorts the elements using a custom comparator while maintaining stability.

- **Use Cases in Real-World Applications:**
  - **Database Management:** Sorting records by multiple fields where order matters (e.g., by name and then by date of birth).
  - **Event Scheduling:** Sorting events while keeping the original sequence for events that start at the same time.
  - **E-commerce:** Sorting product lists by rating, and then by price if ratings are identical.

##### std::partial_sort

- **Description:**  
  `std::partial_sort` rearranges elements in such a way that the smallest elements appear in a sorted order at the beginning of the range, while the rest of the elements are left in an unspecified order.

- **Syntax/Template:**  
  ```cpp
  std::partial_sort(RandomIt first, RandomIt middle, RandomIt last);
  ```
  Here, `RandomIt` is a random access iterator, `first` and `last` define the range, and `middle` defines the end of the sorted portion.

- **Important Methods:**
  - `std::partial_sort(RandomIt first, RandomIt middle, RandomIt last)`: Sorts the elements in the range `[first, middle)` in ascending order.
  - `std::partial_sort(RandomIt first, RandomIt middle, RandomIt last, Compare comp)`: Sorts the elements using a custom comparator.

- **Use Cases in Real-World Applications:**
  - **Data Analysis:** Extracting the top-N elements from a large dataset.
  - **Sports:** Ranking the top few teams or players without sorting the entire list.
  - **Gaming:** Displaying the top scores or fastest times from a leaderboard.

#### Non-Modifying Algorithms

##### std::find

- **Description:**  
  `std::find` searches for the first occurrence of a value in a given range and returns an iterator to it.

- **Syntax/Template:**  
  ```cpp
  std::find(InputIt first, InputIt last, const T& value);
  ```
  Here, `InputIt` is an input iterator pointing to the first and last elements of the range, and `T` is the type of the value being searched for.

- **Important Methods:**
  - `std::find(InputIt first, InputIt last, const T& value)`: Returns an iterator to the first occurrence of the value.

- **Use Cases in Real-World Applications:**
  - **Text Processing:** Finding a specific word or phrase in a document.
  - **Networking:** Searching for a specific packet in a stream of network data.
  - **Inventory Systems:** Locating a specific item in a product catalog.

#### Modifying Algorithms

##### std::copy

- **Description:**  
  `std::copy` copies elements from one range to another, preserving the order of the elements.

- **Syntax/Template:**  
  ```cpp
  std::copy(InputIt first, InputIt last, OutputIt d_first);
  ```
  Here, `InputIt` is the input iterator pointing to the first and last elements of the source range, and `OutputIt` is the output iterator pointing to the beginning of the destination range.

- **Important Methods:**
  - `std::copy(InputIt first, InputIt last, OutputIt d_first)`: Copies the range `[first, last)` to the destination starting at `d_first`.

- **Use Cases in Real-World Applications:**
  - **Backup Systems:** Copying files or data from one location to another for backup.
  - **Image Processing:** Copying pixel data from one image buffer to another.
  - **Memory Management:** Copying contents of one memory block to another in low-level programming.

#### Set Operations

##### std::set_union

- **Description:**  
  `std::set_union` computes the union of two sorted ranges, resulting in a sorted range that contains all elements that are present in either of the input ranges.

- **Syntax/Template:**  
  ```cpp
  std::set_union(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first);
  ```
  Here, `InputIt1` and `InputIt2` are input iterators defining the ranges, and `OutputIt` is the output iterator for the resulting range.

- **Important Methods:**
  - `std::set_union(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first)`: Computes the union of two ranges and stores the result.

- **Use Cases in Real-World Applications:**
  - **Data Merging:** Combining data from two sorted datasets into one.
  - **Inventory Management:** Merging stock lists from different warehouses.
  - **Social Media:** Merging followers or friends lists from different networks.

##### std::set_intersection

- **Description:**  
  `std::set_intersection` computes the intersection of two sorted ranges, resulting in a sorted range that contains only the elements that are present in both input ranges.

- **Syntax/Template:**  
  ```cpp
  std::set_intersection(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first);
  ```
  Here, `InputIt1` and `InputIt2` are input iterators defining the ranges, and `OutputIt` is the output iterator for the resulting range.

- **Important Methods:**
  - `std::set_intersection(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first)`: Computes the intersection of two ranges and stores the result.

- **Use Cases in Real-World Applications:**
  - **Database Queries:** Finding common records between two datasets.
  - **Networking:** Identifying common nodes or connections between two networks.
  - **Retail:** Finding products that are common in multiple stores for competitive analysis.

##### std::set_difference

- **Description:**  
  `std::set_difference` computes the difference between two sorted ranges, resulting in a sorted range that contains elements present in the first range but not in the second.

- **Syntax/Template:**  
  ```cpp
  std::set_difference(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first);
  ```
  Here, `InputIt1` and `InputIt2` are input iterators defining the ranges, and `OutputIt` is the output iterator for the resulting range.

- **Important Methods:**
  - `std::set_difference(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first)`: Computes the difference of two ranges and stores the result.

- **Use Cases in Real-World Applications:**
  - **Version Control:** Identifying differences between two versions of code.
  - **Inventory Management:** Finding out which items are in one warehouse but not in another.
  - **Mailing Lists:** Removing unsubscribed users from a mailing list.

### Utilities

#### Pairs and Tuples

##### std::pair

- **Description:**  
  `std::pair` is a simple container that stores two heterogeneous objects as a single unit. It is often used to return two values from a function or to represent a key-value pair.

- **Syntax/Template:**  
  ```cpp
  std::pair<T1, T2> p;
  ```
  Here, `T1` and `T2` are the types of the first and second elements.

- **Important Methods:**
  - `std::make_pair(T1&& t1, T2&& t2)`: Creates a pair object from two values.
  - `first`: The first element in the pair.
  - `second`: The second element in the pair.

- **Use Cases in Real-World Applications:**
  - **Key-Value Storage:** Representing entries in associative containers like `std::map`.
  - **Return Multiple Values:** Returning two values from a function without creating a custom struct.
  - **Geolocation:** Storing coordinates as a pair of latitude and longitude.

##### std::tuple

- **Description:**  
  `std::tuple` is a fixed-size collection of heterogeneous values. It generalizes `std::pair` by allowing more than two elements, making it useful for grouping multiple values of different types.

- **Syntax/Template:**  
  ```cpp
  std::tuple<Types...> tpl;
  ```
  Here, `Types...` are the types of the elements.

- **Important Methods:**
  - `std::make_tuple(Types&&... args)`: Creates a tuple object from the provided arguments.
  - `std::get<N>(tuple)`: Accesses the Nth element of the tuple.
  - `std::tie(T&... args)`: Unpacks the tuple into individual variables.

- **Use Cases in Real-World Applications:**
  - **Multi-Return Functions:** Returning multiple values from a function when the number of values exceeds two.
  - **Complex Data Structures:** Grouping related but differently-typed data together in complex structures like graphs.
  - **Configuration Systems:** Storing settings with different types in a single structure.

#### Function Objects (Functors)

##### Custom Functors

- **Description:**  
  A functor (function object) is any object that can be used in place of a function. Functors are often used in algorithms that require a function as a parameter because they allow storing state and behavior together.

- **Syntax/Template:**  
  ```cpp
  struct Functor {
      void operator()(int x) const {
          // Implementation
      }
  };
  ```
  Here, `operator()` is overloaded to make the object callable like a function.

- **Important Methods:**
  - `operator()`: The function call operator that makes the object callable.
  - `std::function`: A standard library component that can store a functor, lambda, or function pointer.

- **Use Cases in Real-World Applications:**
  - **Event Handling:** Using functors to define event handlers with state.
  - **Custom Sorting:** Passing functors as custom comparators to sorting algorithms.
  - **Mathematical Operations:** Creating reusable functors for operations like summing, averaging, etc.
