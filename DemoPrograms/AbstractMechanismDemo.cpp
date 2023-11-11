/********************************************************************************************************
			Demo on Abstract Mechanism in C++ From The_C++_Programming_Language_4th_Edition_Bjarne_Stroustrup
*********************************************************************************************************/

#include <iostream>
#include <list>

using namespace std;

// Simple Implementation of Vector
class Vector{
    private:
        double* elem;
        int sz;
    public:
        Vector(int s) :elem{new double[s]},sz{s}
        {
            for(int i=0; i != s; ++i)
                elem[i] = i+1;
        }
        ~Vector(){
            delete[] elem;
        }
        
        double& operator[](int i);
        int size() const {return sz;}
};

double& Vector::operator[](int i){
    return elem[i];
}


// Container is an Abstract Class
// A class derived from Container provides an implementation for the Container interface
// Thus, it is not possible to define an object that is just a
// Container; a Container can only serve as the interface to a class that implements its operator[]() and
// size() functions.


// Container does have a destructor and that destructor
// is virtual. Again, that is common for abstract classes because they tend to be manipulated through
// references or pointers, and someone destroying a Container through a pointer has no idea what
// resources are owned by its implementation.
class Container{
    public:
        virtual double& operator[](int) = 0; // pure virtual function
        virtual int size() const = 0;
        virtual ~Container(){}
};

// Implementation for Container using Vector
// A container that implements the functions required by the interface defined by the abstract class
// Container could use the concrete class Vector:

class Vector_container : public Container{
    Vector v;
    public:
        Vector_container(int s) : v(s) {}
        ~Vector_container(){}
        
        double& operator[](int i){return v[i];}
        int size() const {return v.size();}
};

// Implementation for Container using List

class List_container : public Container{
    std::list<double> ld;
    
    public:
        List_container(){}
        List_container(initializer_list<double> il) : ld{il} {}
        ~List_container(){}
        
        double& operator[](int i);
        int size() const {return ld.size();}
};

double& List_container::operator[](int i){
    for(auto& x : ld){
        if(i == 0)
            return x;
        --i;
    }
    throw out_of_range("List Container");
}

// Container can be used like this:

void use(Container& c){
    const int sz = c.size();
    
    for(int i=0; i != sz; ++i)
        cout<<c[i]<<'\n';
}


// use() uses the Container interface in complete ignorance of implementation details. It
// uses size() and [] without any idea of exactly which type provides their implementation.

// For a function like use(Container&) to use a Container in complete ignorance of implementation
// details, some other function will have to make an object on which it can operate.
int main()
{
    Vector_container vc(5);
    List_container lc = {1,2,3,4,5,6,7,8,9};
	
	// Since use() doesn’t know about Vector_containers but only knows the Container interface, it will
    // work just as well for a different implementation of a Container.
    use(vc);
    use(lc);
    return 0;
}

/*
The point is that use(Container&) has no idea if its argument is a Vector_container, a List_container,
or some other kind of container; it doesn’t need to know. It can use any kind of Container. It knows
only the interface defined by Container. Consequently, use(Container&) needn’t be recompiled if the
implementation of List_container changes or a brand-new class derived from Container is used.

The flip side of this flexibility is that objects must be manipulated through pointers or references.
*/
