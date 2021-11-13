#include <iostream>
#include <vector>
class Matrix
{
    public:
        Matrix(uint r, uint c);
    private:
        unsigned rows;
        unsigned columns;
        std::vector<std::vector<double> > matrix;
};

Matrix::Matrix(uint r, uint c)
{
    rows = r;
    columns = c;
    matrix.resize(r);
    for(unsigned i = 0; i < matrix.size(); i++)
    {
        matrix[i].resize(c);
    }
}

int main()
{
    Matrix ricky(3,3);
    return 0;
}