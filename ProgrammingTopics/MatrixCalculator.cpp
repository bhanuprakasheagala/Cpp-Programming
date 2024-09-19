#include <iostream>
#include <array>
#include <stdexcept>

// Matrix class template
template <size_t Rows, size_t Cols>
class Matrix {
    private:
        std::array<std::array<int, Cols>, Rows> data;
    
    public:
        // Constructor to initialize the Matrix
        Matrix() {
            for(auto& row : data) {
                row.fill(0);    // Initialize all elements to 0
            }
        }
        
        // Function to set an element
        void set(size_t row, size_t col, int value) {
            if(row >= Rows || col >= Cols) {
                throw std::out_of_range("Index out of range\n");
            }
            data[row][col] = value;
        }
        
        // Function to get an element
        int get(size_t row, size_t col) const {
            if(row >= Rows || col >= Cols) {
                throw std::out_of_range("Index out of range\n");
            }
            return data[row][col];
        }
        
        // Function to print the Matrix
        void print() const {
            for(const auto& row : data) {
                for(const auto& element : row) {
                    std::cout << element << " ";
                }
                std::cout << '\n';
            }
        }
        
        // Function to add another Matrix
        Matrix<Rows, Cols> add(const Matrix<Rows, Cols>& other) const {
            Matrix<Rows, Cols> result;
            for(size_t i = 0; i < Rows; ++i) {
                for(size_t j = 0; j < Cols; ++j) {
                    result.set(i, j, this->get(i, j) + other.get(i, j));
                }
            }
            return result;
        }
        
        // Function to multiply with another Matrix
        template <size_t OtherCols>
        Matrix<Rows, OtherCols> multiply(const Matrix<Cols, OtherCols>& other) const {
            Matrix<Rows, OtherCols> result;
            for(size_t i = 0; i < Rows; ++i) {
                for(size_t j = 0; j < OtherCols; ++j) {
                    int sum = 0;
                    for(size_t k = 0; k < Cols; ++k) {
                        sum += this->get(i, k) * other.get(k, j);
                    }
                    result.set(i, j, sum);
                }
            }
            
            return result;
        }
        
        // Function to transpose the Matrix
        Matrix<Cols, Rows> transpose() const {
            Matrix<Cols, Rows> result;
            for(size_t i = 0; i < Rows; ++i) {
                for(size_t j = 0; j < Cols; ++j) {
                    result.set(j, i, this->get(i, j));
                }
            }
            return result;
        }
};

int main() {
    Matrix<2,3> mat1;
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(0, 2, 3);
    mat1.set(1, 0, 4);
    mat1.set(1, 1, 5);
    mat1.set(1, 2, 6);

    Matrix<2, 3> mat2;
    mat2.set(0, 0, 7);
    mat2.set(0, 1, 8);
    mat2.set(0, 2, 9);
    mat2.set(1, 0, 1);
    mat2.set(1, 1, 2);
    mat2.set(1, 2, 3);
    
    std::cout << "Matrix 1:\n";
    mat1.print();
    
    std::cout << "Matrix 2:\n";
    mat2.print();
    
    // Matrix addition
    Matrix<2, 3> matSum = mat1.add(mat2);
    std::cout << "Matrix Sum:\n";
    matSum.print();
    
    // Transpose of the first Matrix
    Matrix<3, 2> matTranspose = mat1.transpose();
    std::cout << "Transpose of Matrix 1:\n";
    matTranspose.print();
    
    // Matrix multiplication (2x3 * 3x2)
    Matrix<3, 2> mat3;
    mat3.set(0, 0, 1);
    mat3.set(0, 1, 2);
    mat3.set(1, 0, 3);
    mat3.set(1, 1, 4);
    mat3.set(2, 0, 5);
    mat3.set(2, 1, 6);
    
    std::cout << "Matrix 3:\n";
    mat3.print();
    
    Matrix<2, 2> matProduct = mat1.multiply(mat3);
    std::cout << "Matrix Product (Matrix 1 * Matrix 3):\n";
    matProduct.print();
    
    return 0;
}
