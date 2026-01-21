#include "header.h"

// Задание 2
// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m)
{
    out.data_ = nullptr;
    out.n_ = 0u;
    out.m_ = 0u;

    if (n == 0u || m == 0u)
    {
        return;
    }

    out.n_ = n;
    out.m_ = m;

    out.data_ = new int*[out.m_];

    for (size_t i = 0; i < out.m_; i++)
    {
        out.data_[i] = new int[out.n_];

        for (size_t j = 0; j < out.n_; j++)
        {
            out.data_[i][j] = 0;
        }
    }
}


// Освобождает выделенную память.
void Destruct(Matrix& in)
{
    if (in.data_ != nullptr)
    {
        for (size_t i = 0; i < in.m_; i++)
        {
            delete[] in.data_[i];
        }

        delete[] in.data_;
    }

    in.data_ = nullptr;
    in.n_ = 0u;
    in.m_ = 0u;
}


// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix)
{
    Matrix out;
    Construct(out, matrix.n_, matrix.m_);

    if (out.data_ == nullptr || matrix.data_ == nullptr)
    {
        return out;
    }

    for (size_t i = 0; i < matrix.m_; i++)
    {
        for (size_t j = 0; j < matrix.n_; j++)
        {
            out.data_[i][j] = matrix.data_[i][j];
        }
    }

    return out;
}


// Возвращает сумму двух матриц.
Matrix Add(const Matrix& a, const Matrix& b)
{
    Matrix out;

    if (a.data_ == nullptr || b.data_ == nullptr)
    {
        return out;
    }

    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return out;
    }

    Construct(out, a.n_, a.m_);

    for (size_t i = 0; i < a.m_; i++)
    {
        for (size_t j = 0; j < a.n_; j++)
        {
            out.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }

    return out;
}


// Возвращает разницу двух матриц.
Matrix Sub(const Matrix& a, const Matrix& b)
{
    Matrix out;

    if (a.data_ == nullptr || b.data_ == nullptr)
    {
        return out;
    }

    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return out;
    }

    Construct(out, a.n_, a.m_);

    for (size_t i = 0; i < a.m_; i++)
    {
        for (size_t j = 0; j < a.n_; j++)
        {
            out.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }

    return out;
}


// Возвращает произведение двух матриц.
Matrix Mult(const Matrix& a, const Matrix& b)
{
    Matrix out;

    if (a.data_ == nullptr || b.data_ == nullptr)
    {
        return out;
    }

    // a: m_ x n_, b: m_ x n_
    // для умножения: a.n_ (столбцы a) == b.m_ (строки b)
    if (a.n_ != b.m_)
    {
        return out;
    }

    Construct(out, b.n_, a.m_); // результат: a.m_ строк, b.n_ столбцов

    for (size_t i = 0; i < out.m_; i++)
    {
        for (size_t j = 0; j < out.n_; j++)
        {
            int sum = 0;

            for (size_t k = 0; k < a.n_; k++)
            {
                sum = sum + a.data_[i][k] * b.data_[k][j];
            }

            out.data_[i][j] = sum;
        }
    }

    return out;
}


// Транспонирование матрицы.
void Transposition(Matrix& matrix)
{
    if (matrix.data_ == nullptr)
    {
        return;
    }

    Matrix temp;
    Construct(temp, matrix.m_, matrix.n_); // меняем местами n и m

    for (size_t i = 0; i < matrix.m_; i++)
    {
        for (size_t j = 0; j < matrix.n_; j++)
        {
            temp.data_[j][i] = matrix.data_[i][j];
        }
    }

    Destruct(matrix);
    matrix = temp;
}


// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b)
{
    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return false;
    }

    if (a.data_ == nullptr && b.data_ == nullptr)
    {
        return true;
    }

    if (a.data_ == nullptr || b.data_ == nullptr)
    {
        return false;
    }

    for (size_t i = 0; i < a.m_; i++)
    {
        for (size_t j = 0; j < a.n_; j++)
        {
            if (a.data_[i][j] != b.data_[i][j])
            {
                return false;
            }
        }
    }

    return true;
}
