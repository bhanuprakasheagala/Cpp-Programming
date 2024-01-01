#ifndef H_rectangleType
#define H_rectangleType

class rectangleType {
    
    public:
        
        // Function to set the length and width of the rectangle
        void setDimension(double l, double w);
        
        // Function to return the length of the rectangle
        double getLength() const;

        // Function to return the width of the rectangle
        double getWidth() const;

        // Function to return the surface area of the rectangle
        double area() const;

        // Function to return the perimeter of the rectangle
        double perimeter() const;

        // Function to output the length and width of the rectangle
        void print() const;

        // Default constructor
        rectangleType();

        // Constructor with parameters
        rectangleType(double l, double w);

    private:
        double length;
        double width;
};

#endif
