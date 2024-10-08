#include <iostream>
class MathUtils {
    public:
        // Static function
        static int add(int a, int b) {
            return a + b;
        }

        // Static constant
        static const double PI;
};

// Definition of static constant outside the class
const double MathUtils::PI = 3.14159;

int main()
{
    // Use the static method without creating an object
    int result = MathUtils::add(3, 4);
    std::cout << "Result: " << result << '\n';

    // Access the static constant
    std::cout << "PI: " << MathUtils::PI << '\n';

    return 0;
}