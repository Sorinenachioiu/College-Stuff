#include <fstream>
#include <stdexcept>
#include "matrices.h"
#include <cmath>
#include <limits>

/**
 * This function enables the reading of multiple matrices from a file
 *
 * @tparam T - the type of elements the Matrices are going to contain
 * @param filename - the file to read from, which has the following format:
 *         numberOfMatrices
 *         for i in range(numberOfMatrices)
 *              rows columns
 *              and then the values of mat
 * @return - a vector of Matrices, which contains on each position a different Matrix object
 */
template<typename T>
std::vector<matrices::Matrix<T>> matrices::Matrix<T>::readFromFile(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Failed to open file");
    }

    int numberOfMatrices;
    in >> numberOfMatrices;
    std::vector<matrices::Matrix<T>> result;

    while(numberOfMatrices--){

        int columns, rows;
        in >> rows >> columns;

        matrices::Matrix<T> aux(columns, rows);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                in >> aux(i, j);
            }
        }
        result.push_back(aux);
    }

    return result;
}

/**
 * This operator enables multiplication of a matrices with a scalar
 * no matter where the scalar is positioned
 *
 * @tparam T - the type of elements the Matrices are going to contain
 * @param value - the scalar to be multiplied with the Matrix
 * @param mat - the Matrix
 * @return - the product between the Matrix with the scalar
 */
template<typename T>
matrices::Matrix<T> operator*(const T& value, const matrices::Matrix<T>& mat) {
    return mat * value;
}

/**
 * This function enables a matrix to be raised to a power in logarithmic time
 *
 * @tparam T - the type of elements the Matrices are going to contain
 * @param power - the power 'this' is going to be raised at
 * @return - a new Matrix object that is equal to 'this' raised to the power
 *          'power'
 */
template<typename T>
matrices::Matrix<T> matrices::Matrix<T>::exponentiation(int power) {
    if(power <= 0)
        return matrices::Matrix<T>::getIdentity(columns);
    if(power&1){
        return exponentiation(power-1)* *(this);
    }
    matrices::Matrix<T> halfPower = exponentiation(power/2);
    return halfPower * halfPower;
}


/**
 * This function is the naive implementation of a Matrix exponentiation
 *
 * @tparam T - the type of elements the Matrices are going to contain
 * @return - a new Matrix object that is equal to 'this' raised to the power
 *          'power'
 */
template<typename T>
matrices::Matrix<T> matrices::Matrix<T>::slowExponentiation(int power) {
    matrices::Matrix<T> result = matrices::Matrix<T>::getIdentity(rows);
    for(int i = 0; i < power; i++){
        result = result * (*this);
    }
    return result;
}

/**
 * This function generates the identity matrix of size 'size'
 *
 * @tparam T - the type of elements the Matrices are going to contain
 * @param size - the size of the matrix to be generated
 * @return - the identity matrix of size 'size'
 */
template<typename T>
matrices::Matrix<T> matrices::Matrix<T>::getIdentity(int size) {
    matrices::Matrix<T> result(size, size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j){
                result(i, j) = 1;
            }
            else{
                result(i, j) = 0;
            }
        }
    }
    return result;
}

/**
 * This function enables the outputting of a Matrix to the terminal
 *
 * @tparam T - the type of elements the Matrices are going to contain
 */
template<typename T>
void matrices::Matrix<T>::displayMatrix() {
    for(int i = 0; i < rows; i++){
        std:: cout << "| ";
        for(int j = 0; j < columns; j++){
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "| \n";
    }
    std::cout << '\n';
}

/**
 * This function brings the matrix to echelon form
 *
 * @return - the matrix in echelon form
 */
template<typename T>
matrices::Matrix<T> matrices::Matrix<T>::bringToEchelon() {
    int lead = 0;
    const int rowCount = rows;
    const int columnCount = columns;

    for (int r = 0; r < rowCount; r++) {
        if (columnCount <= lead) {
            break;
        }
        int i = r;
        while (matrix[i][lead] == 0) {
            i++;
            if (rowCount == i) {
                i = r;
                lead++;
                if (columnCount == lead) {
                    return *this;
                }
            }
        }
        // swap rows i and r
        std::swap(matrix[i], matrix[r]);
        // divide row r by matrix[r][lead]
        T lv = matrix[r][lead];
        for (int j = 0; j < columnCount; j++) {
            matrix[r][j] /= lv;
        }
        // subtract A[r][lead] multiplied by row i from row i
        for (i = 0; i < rowCount; i++) {
            if (i != r) {
                T lv = matrix[i][lead];
                for (int j = 0; j < columnCount; j++) {
                    matrix[i][j] -= lv * matrix[r][j];
                }
            }
        }
        lead++;
    }

    return *this;
}

/**
 * Calcucates the determinant
 *
 * @tparam T
 * @return
 */
template<typename T>
T matrices::Matrix<T>::determinant() const {
    if(rows != columns) {
        throw std::invalid_argument("Matrix must be square.");
    }
    if(rows == 1) {
        return matrix[0][0];
    }
    if(rows == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    T det = 0;
    for(int i = 0; i < rows; i++) {
        Matrix<T> subMatrix(rows-1, columns-1);
        for(int j = 1; j < rows; j++) {
            for(int k = 0; k < columns; k++) {
                if(k < i) {
                    subMatrix(j-1,k) = matrix[j][k];
                } else if(k > i) {
                    subMatrix(j-1,k-1) = matrix[j][k];
                }
            }
        }
        det += std::pow(-1,i)*matrix[0][i]*subMatrix.determinant();
    }
    return det;
}


