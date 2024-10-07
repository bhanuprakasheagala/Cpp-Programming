// 1. C style
#include <iostream>
#include <cstring>

void reverse(char s[]){
    int len = strlen(s);
    int i,j;
    for(i=0, j=len-1; i<j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main(){
    char s[] = "This is a string";
    std::cout<<"Main string: " << s << std::endl;
    reverse(s);
    std::cout<<"Reveresed String: "<< s << std::endl;

    return 0;
}


// 2. Using a reverse function in C++
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
    getline(cin, word);
	// passing the begin() and end() iterators of the string
	reverse(word.begin(), word.end());
	cout << word << endl;
	return 0;
}

