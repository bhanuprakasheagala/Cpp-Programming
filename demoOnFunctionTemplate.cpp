// Author : BHANUPRAKASH EAGALA
// Function Templates Demo

#include <iostream>

using namespace std;

// Version1
template<class FirstType, class SecondType>
bool isSameType1(void){
    return true;
}

// Version2
template<class FirstType, class SecondType>
bool isSameType2(FirstType const f_first, SecondType const f_second){
    return true;
}

int main(void){

    // Version1 -> Function Templates
    // the function template has to be called by explicitly mentioning both template parameter 
    // types during the function call inside the <> brackets
    bool isSame1{isSameType1<int, char>()};
    cout << isSame1 << endl;

    // Version2 -> Function Templates
    // If a template parameter of a function template is part of the argument list of this function.
    // the calling function does not have to explicitly mention the template parameter type any more during the function call inside the <> brackets
    int value{8};
    char character{'B'};

    bool isSame2{isSameType2(value, character)};
    cout << isSame2 << endl;

    

    return 0;
}
