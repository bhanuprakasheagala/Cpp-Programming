#include <iostream>

class classIllusFriend {
    friend void friendFunc(classIllusFriend cIFObject);

    public:
        void print();
        void setx(int a);
    
    private:
        int x;
};

void classIllusFriend::print() {
    std::cout << "In class classIllusFriend: x = " << x << '\n';
}

void classIllusFriend::setx(int a) {
    x = a;
}

void friendFunc(classIllusFriend cIFObject) {
    classIllusFriend localTwoObject;
    
    localTwoObject.x = 45;
    localTwoObject.print();
    std::cout << "In friendFunc accessing private member variable x = " << localTwoObject.x << '\n';
    
    cIFObject.x = 88;
    cIFObject.print();
    std::cout << "In friendFunc accessing private member variable x = " << cIFObject.x << '\n';
}

int main() {

    classIllusFriend aObject;
    aObject.setx(32);
    std::cout << "aObject.x: ";
    aObject.print();
    std::cout << '\n';

    std::cout << "*~*~*~*~ Testing friendFunc *~*~*~*~" << "\n\n";
    friendFunc(aObject);
    
    return 0;
}