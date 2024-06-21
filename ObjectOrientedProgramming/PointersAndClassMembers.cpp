#include <iostream>

class Testpm {
    public:
        void m_func1() {
            std::cout << "m_func1\n";
        }
        
        int m_num;
};

void (Testpm::*pmfn)() = &Testpm::m_func1;
int Testpm::*pmd = &Testpm::m_num;


int main()
{
    std::cout<<"Hello World\n";
    
    Testpm A;
    Testpm *ptr = new Testpm;
    
    (A.*pmfn)();
    (ptr->*pmfn)();
    
    A.*pmd = 1;
    ptr->*pmd = 2;
    
    std::cout << A.*pmd << '\n';
    std::cout << ptr->*pmd << '\n';
    
    delete ptr;

    return 0;
}