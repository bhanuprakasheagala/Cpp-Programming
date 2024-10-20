#include <iostream>

class GameObject {
    public:
        GameObject() {
            std::cout << "GameObject created\n";
        }
        virtual ~GameObject() {
            std::cout << "GameObject destroyed\n";
        }
};

class Player : public GameObject {
    public:
        Player() {
            std::cout << "Player created\n";
        }
        ~Player() {
            std::cout << "Player destroyed\n";
        }
};

int main()
{
    GameObject* obj = new Player();
    delete obj; // Calls Player's destructor first, the GameObject's destructor

    return 0;
}