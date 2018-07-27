#ifndef __matrix__
#define __matrix__

#include "../myExceptions.h"

template <class T>
class matrix
{
    template <class E>
    friend ostream &operator<<(ostream &, const matrix<E> &);

  public:
    matrix(int theRow = 0, int theCol = 0);
    matrix(const matrix<T> &);
    ~matrix() { delete[] element; }

    int rows() const { return row; }
    int cols() const { return col; }

    T &operator()(int, int) const;
    matrix<T> &operator=(const matrix<T> &);
    matrix<T> operator+() const;
    matrix<T> operator-() const;
    matrix<T> operator+(const matrix<T> &) const;
    matrix<T> operator-(const matrix<T> &) const;
    matrix<T> operator*(const matrix<T> &)const;
    matrix<T> &operator+=(const T &);

  private:
    int row;
    int col;
    T *element;
};

template <class T>
matrix<T>::matrix(int theRow, int theCol)
{
    if (theRow < 0 || theCol < 0)
        throw illegalParameterValues("Rows and columns must be >= 0");
    if ((theRow == 0 || theCol == 0) &&
        (theRow != 0 || theCol != 0))
        throw illegalParameterValues("Either both or neither rows and columns should be zero");

    row = theRow;
    col = theCol;
    element = new T[row * col];
}

template <class T>
matrix<T>::matrix(const matrix<T> &m)
{
    row = m.row;
    col = m.col;
    element = new T[row * col];

    copy(m.element, m.element + row * col, element);
}

template <class T>
T &matrix<T>::operator()(int i, int j) const
{
    return element[(i - 1) * col + (j - 1)];
}

template <class T>
matrix<T> &matrix<T>::operator=(const matrix<T> &m)
{
    if (this != &m)
    {
        delete[] element;
        row = m.row;
        col = m.col;
        element = new T[row * col];

        copy(m.element, m.element + row * col, element);
    }
    return *this;
}

template <class T>
matrix<T> matrix<T>::operator-() const
{
    matrix<T> w(row, col);
    for (int i = 0; i < row * col; i++)
        w.element[i] = -element[i];
    return w;
}

template <class T>
matrix<T> matrix<T>::operator+(const matrix<T> &m) const
{
    if (row != m.row || col != m.col)
        throw matrixSizeMismatch();

    matrix<T> w(row, col);
    for (int i = 0; i < row * col; i++)
        w.element[i] = element[i] + m.element[i];
    return w;
}

template <class T>
matrix<T> matrix<T>::operator-(const matrix<T> &m) const
{
    if (row != m.row || col != m.col)
        throw matrixSizeMismatch();

    matrix<T> w(row, col);
    for (int i = 0; i < row * col; i++)
        w.element[i] = element[i] - m.element[i];
    return w;
}

template <class T>
matrix<T> matrix<T>::operator*(const matrix<T> &m) const
{
    if (col != m.row)
        throw matrixSizeMismatch();

    matrix<T> w(row, m.col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            T sum = 0;
            for (int k = 0; k < col; k++)
                sum += element[i * col + k] * m.element[j + k * m.col];
            w.element[i * m.col + j] = sum;
        }
    }

    return w;
}

template <class T>
matrix<T> &matrix<T>::operator+=(const T &m)
{
    for (int i = 0; i < row * col; i++)
        element[i] += m;

    return *this;
}

template <class T>
ostream &operator<<(ostream &out, const matrix<T> &m)
{
    int k = 0;
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
            cout << m.element[k++] << "  ";
        out << endl;
    }
    return out;
}

#endif