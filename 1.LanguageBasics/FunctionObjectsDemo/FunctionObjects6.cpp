#include <iostream>
#include <string>
#include <vector>
#include <functional>

// Generic findMax, with a function Object, C++ style
// Precondition: a.size() > 0

template <typename Object, typename Comparator>
const Object& findMax(const std::vector<Object>& arr, Comparator isLessThan) {
    int maxIndex = 0;

    for(int i=1; i < arr.size(); i++) {
        if(isLessThan(arr[maxIndex], arr[i])) {
            maxIndex = i;
        }
    }

    return arr[maxIndex];
}

// Generic findMax, using default ordering
template <typename Object>
const Object& findMax(const std::vector<Object>& arr) {
    return findMax(arr, std::less<Object>());
}

class CaseInsensitiveCompare {
    public:
        bool operator()(const std::string& lhs, const std::string& rhs) const {
            if(strcasecmp(lhs.c_str(), rhs.c_str()) == 0) {
                return lhs < rhs;
            }
            return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
        }
};

int main()
{
    std::vector<std::string> arr(3);
    arr[0] = "ZEBRA"; arr[1] = "Alligator"; arr[2] = "Crocodile";
    std::cout << findMax(arr, CaseInsensitiveCompare()) << '\n';
    std::cout << findMax(arr) << '\n';

    return 0;
}