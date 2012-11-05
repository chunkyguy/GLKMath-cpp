//
//  mat4.h
//  GLKMath-cpp
//
//  Created by McLovin on 05/11/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef GLKMath_cpp_mat4_h
#define GLKMath_cpp_mat4_h
#include <iostream>
#include <GLKit/GLKMatrix4.h>
#include "mat3.h"
#include "vec3.h"
#include "vec4.h"

namespace glkm {
    class mat4 {
    public:
        mat4() : mat_(GLKMatrix4Identity){}
        
        mat4(const GLKMatrix4 &m) : mat_(m){}
        
        mat4(float m00, float m01, float m02, float m03,
             float m10, float m11, float m12, float m13,
             float m20, float m21, float m22, float m23,
             float m30, float m31, float m32, float m33) :
        mat_(GLKMatrix4Make(m00,  m01,  m02,  m03,
                             m10,  m11,  m12,  m13,
                             m20,  m21,  m22,  m23,
                             m30,  m31,  m32,  m33)){}
        
        mat4(float values[16]) : mat_(GLKMatrix4MakeWithArray(values)){}
        
        mat4(GLKQuaternion q) : mat_(GLKMatrix4MakeWithQuaternion(q)) {}
        
        mat4 makeWithRows(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3){
            return GLKMatrix4MakeWithRows(r0, r1, r2, r3);
        }
        
        mat4 makeWithColumns(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3){
            return GLKMatrix4MakeWithColumns(r0, r1, r2, r3);
        }
        
        mat4 makeTranspose(float m00, float m01, float m02, float m03,
                           float m10, float m11, float m12, float m13,
                           float m20, float m21, float m22, float m23,
                           float m30, float m31, float m32, float m33){
            return GLKMatrix4MakeAndTranspose(m00,  m01,  m02,  m03,
                                              m10,  m11,  m12,  m13,
                                              m20,  m21,  m22,  m23,
                                              m30,  m31,  m32,  m33);
        }
        
        mat4 makeTranspose(float values[16]){
            return GLKMatrix4MakeWithArrayAndTranspose(values);
        }
        
        mat4 makeTranslation(float x, float y, float z){
            return GLKMatrix4MakeTranslation(x, y, z);
        }
        
        mat4 makeScale(float x, float y, float z){
            return GLKMatrix4MakeScale(x, y, z);
        }
        
        mat4 makeRotate(float radians, float x, float y, float z){
            return GLKMatrix4MakeRotation(radians, x, y, z);
        }
        
        mat4 makeXRotation(float radians){
            return GLKMatrix4MakeXRotation(radians);
        }
        
        mat4 makeYRotation(float radians){
            return GLKMatrix4MakeYRotation(radians);
        }
        
        mat4 makeZRotation(float radians){
            return GLKMatrix4MakeZRotation(radians);
        }
        
        mat4 makePerspective(float FOV_Radians, float aspect, float nz, float fz){
            return GLKMatrix4MakePerspective(FOV_Radians, aspect, nz, fz);
        }
        
        mat4 makeFrustrum(float left, float right, float bottom, float top, float near, float far){
            return GLKMatrix4MakeFrustum(left, right, bottom, top, near, far);
        }
        
        mat4 makeOrtho(float left, float right, float bottom, float top, float near, float far){
            return GLKMatrix4MakeOrtho(left, right, bottom, top, near, far);
        }
        
        mat4 makeLookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ){
            return GLKMatrix4MakeLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
        }
        
        operator mat3(){
            return GLKMatrix4GetMatrix3(mat_);
        }
        
        operator mat2(){
            return GLKMatrix4GetMatrix2(mat_);
        }
        
        vec4 getRow(int r){
            return GLKMatrix4GetRow(mat_, r);
        }
        
        vec4 getColumn(int c){
            return GLKMatrix4GetColumn(mat_, c);
        }
        
        void setRow(int r,const vec4 &v){
            mat_ = GLKMatrix4SetRow(mat_, r, v);
        }
        
        void setColumn(int c, const vec4 &v){
            mat_ = GLKMatrix4SetColumn(mat_, c, v);
        }
        
        void transpose(){
            mat_ = GLKMatrix4Transpose(mat_);
        }
        
        bool invert(){
            bool success;
            GLKMatrix4 i = GLKMatrix4Invert(mat_, &success);
            if(success)
                mat_ = i;
            return success;
        }
        
        bool invertAndTranspose(){
            bool success;
            GLKMatrix4 i = GLKMatrix4InvertAndTranspose(mat_, &success);
            if(success)
                mat_ = i;
            return success;
        }
        
        friend mat4 operator*(const mat4 & a, const mat4 & b){
            return GLKMatrix4Multiply(a.mat_  , b.mat_);
        }
        
        friend mat4 operator+(const mat4 & a, const mat4 & b){
            return GLKMatrix4Add(a.mat_, b.mat_);
        }
        
        friend mat4 operator-(const mat4 &a, const mat4 &b){
            return GLKMatrix4Subtract(a.mat_, b.mat_);
        }
        
        void translate(float x, float y, float z){
            mat_ = GLKMatrix4Translate(mat_, x, y, z);
        }
        
        void translate(const vec3 &v){
            mat_ = GLKMatrix4TranslateWithVector3(mat_, v);
        }

        void translate(const vec4 &v){
            mat_ = GLKMatrix4TranslateWithVector4(mat_, v);
        }

        void scale(float x, float y, float z){
            mat_ = GLKMatrix4Scale(mat_, x, y, z);
        }
        
        void scale(const vec3 &v){
            mat_ = GLKMatrix4ScaleWithVector3(mat_, v);
        }
        
        void scale(const vec4 &v){
            mat_ = GLKMatrix4ScaleWithVector4(mat_, v);
        }
        
        void rotate(float radians, float x, float y, float z){
            mat_ = GLKMatrix4Rotate(mat_, radians, x, y, z);
        }
        
        void rotate(float radians, const vec3 &v){
            mat_ = GLKMatrix4RotateWithVector3(mat_, radians, v);
        }
        
        void rotate(float radians, const vec4 &v){
            mat_ = GLKMatrix4RotateWithVector4(mat_, radians, v);
        }
        
        void rotateX(float radians){
            mat_ = GLKMatrix4RotateX(mat_, radians);
        }
        
        void rotateY(float radians){
            mat_ = GLKMatrix4RotateY(mat_, radians);
        }
        
        void rotateZ(float radians){
            mat_ = GLKMatrix4RotateZ(mat_, radians);
        }
        
        friend vec3 operator*(const mat4 &m, const vec3 &v){
            return GLKMatrix4MultiplyVector3(m.mat_, v);
        }
        
        friend vec3 operator*(const vec3 &v, const mat4 &m){
            return GLKMatrix4MultiplyVector3(m.mat_, v);
        }
        
        vec3 multiplyWithTranslation(const vec3 & v){
            return GLKMatrix4MultiplyVector3WithTranslation(mat_, v);
        }
        
        vec3 multiplyAndProject(const vec3 & v){
            return GLKMatrix4MultiplyAndProjectVector3(mat_, v);
        }
        
    private:
        GLKMatrix4 mat_;
    };
}
#endif
