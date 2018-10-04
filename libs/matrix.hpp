/* by stanford */

#ifndef MATRIX
#define MATRIX

#include <stdexcept>
#include <iostream>
#include <iomanip>

using std::ostream;
using std::cerr;
using std::endl;

namespace simple_matrix {


struct Dot {
    int x;
    int y;
    Dot() = default;
    inline Dot(const Dot &dot);
    inline Dot(int, int);
    inline friend Dot operator+(const Dot& left, const Dot& right);
    inline friend bool operator==(const Dot& left, const Dot& right);
    inline friend ostream& operator<<(ostream&, const Dot &dot);
};


Dot::Dot(const Dot &dot) : x(dot.x), y(dot.y) {}
Dot::Dot(int _x, int _y) : x(_x), y(_y) {}


bool operator==(const Dot &left, const Dot &right) {
    return left.x == right.x && left.y == right.y;
}

ostream& operator<<(ostream &stream, const Dot &dot) {
    stream << dot.x << "," << dot.y;
    return stream;
}

// i'm not sure, if I should return a reference
Dot operator+(const Dot &left, const Dot &right) {
    return Dot(left.x + right.x, left.y + right.y);
}

/* ************************************************************************* */

template <typename T> class Matrix;
template <typename T> ostream& operator<<(ostream&, const Matrix<T>&);

template <typename T>
class Matrix {
public:
    Matrix(const int _width, const int _height, const bool defaultInit = false);
    ~Matrix();
    bool DotIsValid(const Dot &dot) const;
    int getWidth() const;
    int getHeight() const;
    int fill(const Dot &first, const Dot &last,
             const T value, const bool toBorders = false);

    T& operator[](const Dot &dot);
    const T& operator[](const Dot &dot) const;

    /* useful for debug */
    friend ostream& operator<< <T>(ostream& stream, const Matrix<T> &matrix);

private:
    T **array;
    int width;
    int height;
};

template <typename T>
Matrix<T>::Matrix(const int _width, const int _height, const bool defaultInit)
: width(_width), height(_height) {
    array = new T*[width];
    if (!defaultInit) {
        for (int i = 0; i != width; i++) array[i] = new T[height];
    } else {
        for (int i = 0; i != width; i++) array[i] = new T[height]();
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i != width; i++)
        delete [] array[i];
    delete [] array;
}

template <typename T>
bool Matrix<T>::DotIsValid(const Dot &dot) const {
    return
        (dot.x < width && dot.x >= 0) &&
        (dot.y < height && dot.y >= 0);
}

template <typename T>
T& Matrix<T>::operator[](const Dot &dot) {
    if (!DotIsValid(dot)) {
        cerr << "writing value at dot " << dot.x << "," << dot.y << endl;
        cerr << "max dot coordinate is " << width - 1 << "," << height - 1 << endl;
        throw std::out_of_range( " writing failed " );
    }
    return array[dot.x][dot.y];
}

template <typename T>
const T& Matrix<T>::operator[](const Dot &dot) const {
    if (!DotIsValid(dot)) {
        cerr << "reading value at dot " << dot.x - 1 << "," << dot.y - 1 << endl;
        cerr << "max dot coordinate is " << width - 1 << "," << height - 1 << endl;
        throw std::out_of_range( " reading failed " );
    }
    return array[dot.x][dot.y];
}

template <typename T>
ostream& operator<<(ostream &stream, const Matrix<T> &matrix) {
    for (int i = 0; i != matrix.width; i++) {
        for (int j = 0; j != matrix.height; j++)
            stream << std::setw(3) << std::left << (int)matrix.array[i][j] << " ";
        stream << endl;
    }
    return stream;
}

template <typename T>
int Matrix<T>::getWidth() const {
    return width;
}

template <typename T>
int Matrix<T>::getHeight() const {
    return height;
}

template <typename T>
int Matrix<T>::fill(const Dot &first, const Dot &last,
                    const T value, const bool toBorders) {

    if (toBorders == false
    && (!DotIsValid(first) || !DotIsValid(last))) {
        cerr << "Dots are invalid. Out of matrix." << endl;
        throw std::out_of_range( " writing failed " );
    }

    int filled = 0;

    int startX = first.x < last.x ? first.x : last.x;
    int stopX  = first.x > last.x ? first.x : last.x;
    int startY = first.y < last.y ? first.y : last.y;
    int stopY  = first.y > last.y ? first.y : last.y;

    if (startX < 0) startX = 0;
    if (stopX >= width) stopX = width - 1;
    if (startY < 0) startY = 0;
    if (stopY >= height) stopY = height - 1;

    for (int x = startX; x != stopX + 1; x++) {
        for (int y = startY; y != stopY + 1; y++) {
            array[x][y] = value;
            filled++;
        }
    }

    return filled;
}

}  // namespace simple_matrix

#endif
