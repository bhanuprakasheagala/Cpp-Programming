#include "rectangleTypes.h"

#ifndef H_boxType
#define H_boxType

class boxType : public rectangleType {
    public:
        // Function to set length, width, and height of the box
        void setDimension(double l, double w, double h);

        // Function to return the height of the box
        double getHeight() const;

        // Function to return the surface area of the box
        double area() const; // Overrides the print method of the class `rectangleTypes`

        // Function to return the volume of the box
        double volume() const;

        // Function to print the length, width, and height of the box
        void print() const; // Overrides the print method of the class `rectangleTypes`

        // Default constructor
        boxType();

        // Constructor with return type
        boxType(double l, double w, double h);

    private:
        double height;
};

#endif