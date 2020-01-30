#include "matrix4.h"
#include "vector4.h"

namespace math {

// #################### Functions ####################
Vector4 matmulMV(const Matrix4 m, const Vector4 v) {
    Vector4 result = Vector4();
    result.x = (m.m[0][0] * v.x) + (m.m[0][1] * v.y) + (m.m[0][2] * v.z) + (m.m[0][3] * v.w);
    result.y = (m.m[1][0] * v.x) + (m.m[1][1] * v.y) + (m.m[1][2] * v.z) + (m.m[1][3] * v.w);
    result.z = (m.m[2][0] * v.x) + (m.m[2][1] * v.y) + (m.m[2][2] * v.z) + (m.m[2][3] * v.w);
    result.w = (m.m[3][0] * v.x) + (m.m[3][1] * v.y) + (m.m[3][2] * v.z) + (m.m[3][3] * v.w);
    return result;
}

Matrix4 matmulMM(const Matrix4 a, const Matrix4 b) {
    Matrix4 result = Matrix4();
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            double sum = 0;
            for (size_t k = 0; k < 4; k++) {
                sum += a.m[i][k] * b.m[k][j];
            }
            result.m[i][j] = sum;
        }
    }
    return result;
}

// ######################## helpers ########################
 Matrix4 rotationZMatrix(const double angle) {
    Matrix4 rm = Matrix4();
    rm.m[0][0] = cos(angle);
    rm.m[0][1] = -sin(angle);
    rm.m[1][0] = sin(angle);
    rm.m[1][1] = cos(angle);

    // rm.m[0][0] = cos(angle); rm.m[0][1] = -sin(angle); rm.m[0][2] = 0.0; rm.m[0][3] = 0.0;
    // rm.m[1][0] = sin(angle); rm.m[1][1] = cos(angle);  rm.m[1][2] = 0.0; rm.m[1][3] = 0.0;
    // rm.m[2][0] = 0.0;        rm.m[2][1] = 0.0;         rm.m[2][2] = 1.0; rm.m[2][3] = 0.0;
    // rm.m[3][0] = 0.0;        rm.m[3][1] = 0.0;         rm.m[3][2] = 0.0; rm.m[3][3] = 1.0;
    return rm;
}

Matrix4 rotationYMatrix(const double angle) {
    Matrix4 rm = Matrix4();
    rm.m[0][0] = cos(angle);
    rm.m[0][2] = sin(angle);
    rm.m[2][0] = -sin(angle);
    rm.m[2][2] = cos(angle);

    // rm.m[0][0] = cos(angle);  rm.m[0][1] = 0.0; rm.m[0][2] = sin(angle); rm.m[0][3] = 0.0;
    // rm.m[1][0] = 0.0;         rm.m[1][1] = 1.0; rm.m[1][2] = 0.0;        rm.m[1][3] = 0.0;
    // rm.m[2][0] = -sin(angle); rm.m[2][1] = 0.0; rm.m[2][2] = cos(angle); rm.m[2][3] = 0.0;
    // rm.m[3][0] = 0.0;         rm.m[3][1] = 0.0; rm.m[3][2] = 0.0;        rm.m[3][3] = 1.0;
    return rm;
}

Matrix4 rotationXMatrix(const double angle) {
    Matrix4 rm = Matrix4();
    rm.m[1][1] = cos(angle);
    rm.m[1][2] = -sin(angle);
    rm.m[2][1] = sin(angle);
    rm.m[2][2] = cos(angle);

    // rm.m[0][0] = 1.0; rm.m[0][1] = 0.0;        rm.m[0][2] = 0.0;         rm.m[0][3] = 0.0;
    // rm.m[1][0] = 0.0; rm.m[1][1] = cos(angle); rm.m[1][2] = -sin(angle); rm.m[1][3] = 0.0;
    // rm.m[2][0] = 0.0; rm.m[2][1] = sin(angle); rm.m[2][2] = cos(angle);  rm.m[2][3] = 0.0;
    // rm.m[3][0] = 0.0; rm.m[3][1] = 0.0;        rm.m[3][2] = 0.0;         rm.m[3][3] = 1.0;
    return rm;
}

// #################### Matrices ####################
Matrix4 scaleMatrix(const Vector4 scale) {
    Matrix4 sm = Matrix4();
    sm.m[0][0] = scale.x;
    sm.m[1][1] = scale.y;
    sm.m[2][2] = scale.z;

    // sm.m[0][0] = scale.x; sm.m[0][1] = 0.0;     sm.m[0][2] = 0.0;     sm.m[0][3] = 0.0;
    // sm.m[1][0] = 0.0;     sm.m[1][1] = scale.y; sm.m[1][2] = 0.0;     sm.m[1][3] = 0.0;
    // sm.m[2][0] = 0.0;     sm.m[2][1] = 0.0;     sm.m[2][2] = scale.z; sm.m[2][3] = 0.0;
    // sm.m[3][0] = 0.0;     sm.m[3][1] = 0.0;     sm.m[3][2] = 0.0;     sm.m[3][3] = 1.0;
    return sm;
}

Matrix4 rotationMatrix(const Vector4 angles) {
    Matrix4 rz = rotationZMatrix(angles.z);
    Matrix4 ry = rotationYMatrix(angles.y);
    Matrix4 rx = rotationXMatrix(angles.x);

    Matrix4 result = Matrix4();
    result = matmulMM(result, rz);
    result = matmulMM(result, ry);
    result = matmulMM(result, rx);

    return result;
}

Matrix4 translationMatrix(const Vector4 delta) {
    Matrix4 tm = Matrix4();
    tm.m[0][3] = delta.x;
    tm.m[1][3] = delta.y;
    tm.m[2][3] = delta.z;

    // tm.m[0][0] = 1.0; tm.m[0][1] = 0.0; tm.m[0][2] = 0.0; tm.m[0][3] = delta.x;
    // tm.m[1][0] = 0.0; tm.m[1][1] = 1.0; tm.m[1][2] = 0.0; tm.m[1][3] = delta.y;
    // tm.m[2][0] = 0.0; tm.m[2][1] = 0.0; tm.m[2][2] = 1.0; tm.m[2][3] = delta.z;
    // tm.m[3][0] = 0.0; tm.m[3][1] = 0.0; tm.m[3][2] = 0.0; tm.m[3][3] = 1.0;
    return tm;
}

Matrix4 modelMatrix(const Vector4 position, const Vector4 rotation, const Vector4 scale) {
    // get corresponding matrices
    Matrix4 scalematrix = scaleMatrix(scale);
    Matrix4 rotmatrix = rotationMatrix(rotation);
    Matrix4 transmatrix = translationMatrix(position);

    // create modelmatrix. order is important (first scale, then rotate, finally translate).
    Matrix4 modelmatrix;
    modelmatrix = matmulMM(scalematrix, modelmatrix);
    modelmatrix = matmulMM(rotmatrix, modelmatrix);
    modelmatrix = matmulMM(transmatrix, modelmatrix);
    return modelmatrix;
}

// #################### Scale ####################
Vector4 scale(const Vector4 origin, const Vector4 scale) {
    return matmulMV(scaleMatrix(scale), origin);
}

// #################### Rotation ####################
Vector4 rotateZ(const Vector4 vec, const double angle) {
    return matmulMV(rotationZMatrix(angle), vec);
}

Vector4 rotateY(const Vector4 vec, const double angle) {
    return matmulMV(rotationYMatrix(angle), vec);
}

Vector4 rotateX(const Vector4 vec, const double angle) {
    return matmulMV(rotationXMatrix(angle), vec);
}

Vector4 rotate(const Vector4 vec, const Vector4 angles) {
    Vector4 ret = Vector4(vec.x, vec.y, vec.z, vec.w);
    ret = rotateZ(ret, angles.z);
    ret = rotateY(ret, angles.y);
    ret = rotateX(ret, angles.x);
    return ret;
}

// #################### Translation ####################
Vector4 translate(const Vector4 origin, const Vector4 delta) {
    return matmulMV(translationMatrix(delta), origin);
}

} // namespace math