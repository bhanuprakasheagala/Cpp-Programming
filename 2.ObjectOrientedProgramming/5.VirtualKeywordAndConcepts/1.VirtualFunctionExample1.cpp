#include <iostream>
#include <string>

class Entity {
    public:
        std::string getName() const{
            return "Entity Name";
        }

        /*
        By using the virtual keyword, informing compiler to generate the vtable for this
        function so that if it's overriden, it can point to the correct function
        */
        virtual std::string getClass(){
            return "Entity Class";
        }

};

class Player : public Entity {
    private:
        std::string m_Name;
        std::string m_Class;
    public:
        Player(const std::string& name, const std::string& Class) : m_Name(name), m_Class(Class) {}

        std::string getName() const {
            return m_Name;
        }
        // We can mark the overriden function with override keyword => (OPTIONAL)
        // We should do it as it helps us identify that this is overrding function
        // and prevents bugs like spelling mistakes.
        // override keyword checks if there is any method in the base class with exactly same
        // method name otherise it gives compiler error. Also, if we mark override to a non-virtula method
        // we will get an error.
        std::string getClass() override{ 
            return m_Class;
        }
};

void printName(Entity* obj) {
    std::cout << obj->getName() << std::endl;
}

void printClass(Entity* obj) {
    std::cout << obj->getClass() << std::endl;
}

int main() {

    Entity* e = new Entity();
    printName(e); // prints Entity Name
    printClass(e); // prints Entity Class

    Player* p = new Player("Player1", "Class Player");
    printName(p); // We are passing Player object to Entity object which is valid because class Player is one Entity.
    // Even though we expect to print Player1, it prints Entity.
    
    printClass(p);
    // In Entiry class(base class), we defined getClass as a virtual method. Hence, when we pass the object of class
    // Player(derived class object) to the printName in which this object being assigned to base(Entity) class, we
    // get the output as Class Player insted of Class Entity.

    return 0;
}

/*
Notes:
When you declare a function as virtual, the decision on which function to invoke is made at runtime based on the
actual object type (not the pointer/reference type). This is called dynamic dispatch or run-time polymorphism.
*/