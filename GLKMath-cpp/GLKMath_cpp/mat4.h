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
             float m30, float m31, float m32, float m33, bool transpose = false){
            if(transpose){
                mat_ = GLKMatrix4MakeAndTranspose(m00,  m01,  m02,  m03,
                                                  m10,  m11,  m12,  m13,
                                                  m20,  m21,  m22,  m23,
                                                  m30,  m31,  m32,  m33);
            }else{
                mat_ = GLKMatrix4Make(m00,  m01,  m02,  m03,
                                      m10,  m11,  m12,  m13,
                                      m20,  m21,  m22,  m23,
                                      m30,  m31,  m32,  m33);
            }
        }
        
        mat4(float values[16], bool transpose = false){
            if(transpose){
                mat_ = GLKMatrix4MakeWithArrayAndTranspose(values);
            }else{
                mat_ = GLKMatrix4MakeWithArray(values);
            }
        }
        
        mat4(GLKQuaternion q) : mat_(GLKMatrix4MakeWithQuaternion(q)) {}
        
        enum ROW_COL {ROW, COLUMN};
        mat4(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3, ROW_COL r = ROW){
            if(r == ROW)
                mat_ = GLKMatrix4MakeWithRows(r0, r1, r2, r3);
            else
                mat_ = GLKMatrix4MakeWithColumns(r0, r1, r2, r3);
        }
        
        mat4(float x, float y, float z, bool isTranslate = false){
            if(isTranslate)
                mat_ = GLKMatrix4MakeTranslation(x, y, z);
            else
                mat_ = GLKMatrix4MakeScale(x, y, z);
        }
        
        mat4(float radians, float x, float y, float z) : mat_(GLKMatrix4MakeRotation(radians, x, y, z)){}

        enum ROTATION_AXIS{X, Y, Z};
        mat4(float radians, ROTATION_AXIS r){
            switch(r){
                case X: mat_ = GLKMatrix4MakeXRotation(radians); break;
                case Y: mat_ = GLKMatrix4MakeYRotation(radians); break;
                case Z: mat_ = GLKMatrix4MakeZRotation(radians); break;
            }
        }
        
        mat4 makePerspective(float FOV_Radians, float aspect, float nz, float fz){
            return GLKMatrix4MakePerspective(FOV_Radians, aspect, nz, fz);
        }
        
        mat4(float left, float right, float bottom, float top, float near, float far, bool isOrtho = false){
            if(isOrtho){
                mat_ = GLKMatrix4MakeOrtho(left, right, bottom, top, near, far);
            }else{
                mat_ = GLKMatrix4MakeFrustum(left, right, bottom, top, near, far);
            }
        }

        mat4(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) : mat_(GLKMatrix4MakeLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)){}
        
        operator mat3(){
            return GLKMatrix4GetMatrix3(mat_);
        }
        
        operator mat2(){
            return GLKMatrix4GetMatrix2(mat_);
        }
        
        vec4 get(int i, ROW_COL r){
            if(r == ROW)
                return GLKMatrix4GetRow(mat_, i);
            return GLKMatrix4GetColumn(mat_, i);
        }
        
        void set(int i, const vec4 &v, ROW_COL r){
            if(r == ROW)
                mat_ = GLKMatrix4SetRow(mat_, i, v);
            mat_ = GLKMatrix4SetColumn(mat_, i, v);
        }
        
        void transpose(){
            mat_ = GLKMatrix4Transpose(mat_);
        }
        
        bool invert(bool transpose = false){
            bool success;
            GLKMatrix4 i = (transpose)?GLKMatrix4InvertAndTranspose(mat_, &success):GLKMatrix4Invert(mat_, &success);
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
        
        void rotate(float radians, ROTATION_AXIS r){
            switch(r){
                case X: mat_ = GLKMatrix4RotateX(mat_, radians); break;
                case Y: mat_ = GLKMatrix4RotateY(mat_, radians); break;
                case Z: mat_ = GLKMatrix4RotateZ(mat_, radians); break;
            }
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
