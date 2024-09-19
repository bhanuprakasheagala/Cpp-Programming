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
        
        // Function to compute the determinant of an n x n Matrix
        long determinant() const {
            static_assert(Rows == Cols, "Determinant is only defined for square Matrices.\n");
            
            // Base case : 1 x 1 Matrix
            if(Rows == 1) {
                return data[0][0]; // The determinant is the element itself
            }
            
            // Base Case : 2 x 2 Matrix
            if(Rows == 2) {
                return data[0][0] * data[1][1] - data[0][1] * data[1][0]; // ad - bc
            }
            
            long det = 0;
            
            // Loop over each column of the first row(for cofactor expansion)
            for(size_t j = 0; j < Cols; ++j) {
                // Create a submatrix M_ij by excluding the first row and j-th column
                Matrix<Rows - 1, Cols - 1> submatrix;
                
                // Fill the submatrix
                for(size_t sub_i = 0; sub_i < Rows - 1; ++sub_i) {
                    for(size_t sub_j = 0; sub_j < Cols - 1; ++sub_j) {
                        // Fill in the submatrix elements by skipping the first row and the current column (j)
                        submatrix.set(sub_i, sub_j, this->get(sub_i + 1, (sub_j >= j ? sub_j + 1 : sub_j)));

                    }
                }
                
                // Add the contribution of this column's cofactor to the determinant
                // The sign alternates based on the column Index
                // data[0][j] is the element  from the first row and j-th column
                
                det += (j%2 == 0 ? 1 : -1) * data[0][j] * submatrix.determinant();
            }
            
            return det;
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
    
    // Determinant for square Matrices
    Matrix<2, 2> mat4;
    mat4.set(0, 0, 4);
    mat4.set(0, 1, 3);
    mat4.set(1, 0, 2);
    mat4.set(1, 1, 1);
    
    std::cout << "Matrix 4:\n";
    mat4.print();
    
    std::cout << "Determinant of Matrix:\n" << mat4.determinant() << '\n';

    return 0;
}
