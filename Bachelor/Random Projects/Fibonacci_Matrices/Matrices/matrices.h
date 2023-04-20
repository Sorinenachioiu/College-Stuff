#ifndef MATRICES_H
#define MATRICES_H

#include <omp.h>
#include <vector>
#include <string>
#include <stdexcept>

namespace matrices {
    template<typename T>
    class Matrix {
    private:
        int rows, columns; //the number of rows and columns of the matrix
        std::vector<std::vector<T>> matrix; //the values inside the matrix
    public:
        /**
         *
         * @param rows - the number of rows of the matrix
         * @param columns - the number of columns of the matrix
         */
        Matrix<T>(int rows, int columns)
        :rows(rows), columns(columns), matrix(rows, std::vector<T>(columns, 0)) {};

        static std::vector<Matrix<T>> readFromFile(const std::string& filename);
        static Matrix<T> getIdentity(int size);
        static std::vector<T> calculateEigenvalues(Matrix<T> A, int iterations);
        [[nodiscard]] int getRows() const {return rows;};
        [[nodiscard]] int getColumns() const {return columns;};
        Matrix<T> exponentiation(int power);
        Matrix<T> slowExponentiation(int power);
        Matrix<T> bringToEchelon();
        T determinant() const;

        void displayMatrix();


        /**
         * This operator enables changes of values inside of the matrix
         *
         * @param row - the row
         * @param column  - the column
         * @return - the value in the matrix on position [row][column]
         */
        //Access operator of a value inside the matrix
        T& operator()(int row, int column) {
            if(row < 0 || row >= rows || column < 0 || column >= columns) {
                throw std::out_of_range("Index out of range.");
            }
            return matrix[row][column];
        };

        /**
         * This operator enables accesses of a specific value inside the matrix
         * without changing them
         *
         * @param row - the row
         * @param column - the column
         * @return - the value in the matrix on position[row][column]
         */
        const T& operator()(int row, int column) const {
            if(row < 0 || row >= rows || column < 0 || column >= columns) {
                throw std::out_of_range("Index out of range.");
            }
            return matrix[row][column];
        };

        /**
         * This operator enables addition of two matrices of the same sizes
         *
         * @param B - the other matrix to be added to 'this'
         * @return - the matrix resulted after adding up 'this' with B
         * @throw - invalid_argument exception if they do not have the same size
         */
        Matrix<T> operator+(const Matrix<T>& B) const {
            if (!(columns == B.columns && rows == B.rows)) {
                throw std::invalid_argument("Matrices must have the same dimensions.");
            }
            int rows = getRows(), columns = getColumns();
            Matrix<T> result(rows, columns);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    result(i, j) = matrix[i][j] + B(i, j);
                }
            }
            return result;
        }

        /**
         * This operator enables multiplication of two matrices
         *
         * @param B - the other matrix to be multiplied with this
         * @return - the matrix resulted after multiplying 'this' with B
         * @throw - invalid_argument exception if the number columns of 'this' are not
         * equal to the number of rows of B
         */
        Matrix<T> operator*(const Matrix<T>& B) const {
            if (!(columns == B.rows)) {
                throw std::invalid_argument("Matrices do not match: A.columns == B.rows.");
            }

            int rows = getRows(), columnsB = B.getColumns();
            Matrix<T> result(rows, columnsB);

            #pragma omp parallel for collapse(2)
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columnsB; j++) {
                    T temp = 0;
                    for (int k = 0; k < columns; k++) {
                        temp += matrix[i][k] * B(k, j);
                    }
                    result(i, j) = temp;
                }
            }
            return result;
        }

        /**
         * This operator enables multiplication of a matrices with a scalar
         *
         * @param value - the scalar value
         * @return - the matrix resulted after multiplying 'this' with the scalar
         */
        Matrix<T> operator*(const T& value) const {
            matrices::Matrix<T> result(rows, columns);

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    result(i, j) = matrix[i][j] * value;
                }
            }

            return result;
        }
    };


}

#endif //MATRICES_H