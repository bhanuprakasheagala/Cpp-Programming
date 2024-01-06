/*
A number of the form a+ib,where i square = -1,and a&b are realnumbers,is called a complex number.
We call a the real part and b the imaginary part of a + ib.
Complex numbers can also be represented as ordered pairs (a, b).

The addition and multi- plication of complex numbers is defined by the following rules:
(a + ib) + (c + id) = (a + c) + i(b + d)
(a + ib) * (c + id) = (ac - bd) + i(ad + bc)
Using the ordered pair notation, these rules are written as follows:
(a, b) + (c, d) = ((a + c), (b + d))
(a, b) * (c, d) = ((ac - bd), (ad + bc))

C++ has no built-in data type that allows us to manipulate complex numbers. In this example,
we will construct a data type, complexType, that can be used to process complex numbers.
We will overload the stream insertion and stream extraction operators for easy input and output.
We will also overload the operators + and * to perform addition and multiplication of complex numbers.
If x and y are complex numbers, we can evaluate expressions such as x + y and x * y.
*/

#ifndef H_complexNumber
#define H_complexNumber

class complexType {
    
    // Overload the stream insertion and extraction operators
    friend std::ostream& operator<< (std::ostream&, const complexType&);
    friend std::istream& operator>> (std::istream&, complexType&);

    public:
        // Function to set the complex numbers according to the parameters
        void setComplex(const double& real, const double& imag);

        // Function to retrieve the complex number
        void getComplex(double& real, double& imag) const;

        // Constructor
        complexType(double real = 0, double imag = 0);

        // Overload the operator +
        complexType operator+ (const complexType& otherComplex) const;

        // Overload the operator *
        complexType operator* (const complexType& otherComplex) const;

        // Overload the operator ==
        bool operator== (const complexType& otherComplex) const;

    private:
        double realPart;
        double imaginaryPart;
};

#endif