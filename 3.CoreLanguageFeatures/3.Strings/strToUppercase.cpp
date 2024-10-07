#include <iostream>
#include <string>
#include <cctype>

void stringToUpper(std::string& str) {
  for(auto& c : str) {
      c = toupper(c);
  }
}

int main() {
  std::cout << "Enter some text in lower-, mixed-, or upper-case:\n";
  std::string input;
  std::getline(std::cin, input);
  stringToUpper(input);
  std::cout << "The same text in uppercase is: " << input << '\n';
  return 0;
}
