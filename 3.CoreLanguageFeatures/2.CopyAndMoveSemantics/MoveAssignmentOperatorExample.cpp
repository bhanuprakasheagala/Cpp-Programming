#include <iostream>
#include <cstring>

class ResourceManager {
    public:
        // Constructor
        ResourceManager(const char* str) : resource(nullptr) {
            if(str) {
                resource = new char[std::strlen(str)+1];
                std::strcpy(resource, str);
            }
        }
        
        // Move assignment operator
        ResourceManager& operator=(ResourceManager&& other) noexcept {
            if(this != &other) {
                // Release current resource
                delete[] resource;
                
                // Steal resource from 'other'
                resource = other.resource;
                
                // Nullify 'other's resource to avoid double deletion
                other.resource = nullptr;
            }
            
            return *this;
        }
        
        ~ResourceManager() {
            delete[] resource;
        }
        
        // Print Method
        void print() const {
            if(resource)
                std::cout << "Resource content: " << resource << '\n';
            else
                std::cout << "Resource is empty!\n";
        }
        
    private:
        char* resource;
};



int main()
{
    //std::cout<<"Hello World";
    
    ResourceManager rm1("Hello");
    ResourceManager rm2("World");
    
    // Move assignment
    rm1 = std::move(rm2); // rm2's resource moved to rm1
    
    // Print after moved
    rm1.print();
    rm2.print();
    

    return 0;
}
