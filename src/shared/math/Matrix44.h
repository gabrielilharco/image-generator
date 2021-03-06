//
// Created by leao on 28/08/16.
//

#ifndef IMAGE_GENERATOR_MATRIX_H
#define IMAGE_GENERATOR_MATRIX_H
#include <vector>

class Matrix44 {
private:
    double matrix_[4][4];
public:
    Matrix44 ();
    Matrix44 (std::vector<double>);
    std::vector<double> getRowsAsVector() const;
    const double get(const int i, const int j) const;
    void print() const;
    static Matrix44 inverse(const Matrix44& mat);
    static Matrix44 identity();
};
#endif //IMAGE_GENERATOR_MATRIX_H
