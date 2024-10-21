#include <iostream>

class Animal {
    public:
        virtual void makeSound() const {
            std::cout << "Animal Sound\n";
        }

        virtual Animal* clone() const = 0; // Pure virtual function for cloning

        virtual ~Animal() {
            std::cout << "Animal Destructor\n";
        }
};

class Dog : public Animal {
    public:
        void makeSound() const override {
            std::cout << "Bark\n";
        }

        Dog* clone() const override {
            return new Dog(*this); // Covariant return type
        }

        ~Dog() {
            std::cout << "Dog Destructor\n";
        }
};

class Cat : public Animal {
    public:
        void makeSound() const override {
            std::cout << "Meow\n";
        }

        Cat* clone() const override {
            return new Cat(*this);  // Coveriant return type
        }

        ~Cat() {
            std::cout << "Cat Destructor\n";
        }
};

void animalSound(Animal* animal) {
    animal->makeSound();
}

int main()
{
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    animalSound(a1); // Calls Dog's makeSound
    animalSound(a2); // Calls Cat's makeSound

    delete a1;
    delete a2;

    return 0;
}