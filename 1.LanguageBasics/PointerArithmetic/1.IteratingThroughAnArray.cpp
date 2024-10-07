#include <iostream>
void printArray(int* arr, size_t size) {
  for(int* ptr = arr; ptr < arr+size; ++ptr) {
    std::cout << *ptr << " ";
  }
  std::cout << '\n';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
