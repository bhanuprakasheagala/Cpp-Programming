#include <iostream>
#include <exception>

class BaseException : std::exception {
    public:
        const char* what() const noexcept override {
            return "Base Exception";
        }
};

class DerivedException : public BaseException {
    public:
        const char* what() const noexcept override {
            return "Derived Exception";
        }
};

void testFunction(bool triggerDerived) {
    if(triggerDerived){
        throw DerivedException();
    }
    else {
        throw BaseException();
    }
}

int main()
{
    try{
        testFunction(true);
        testFunction(false);
    }
    catch(const DerivedException& e) {
        std::cerr << "Caught derived exception: " << e.what() << '\n';
    }
    catch(const BaseException& e) {
        std::cerr << "Caught base exception: " << e.what() << '\n';
    }


    return 0;
}