//
//  mat3.h
//  GLKMath-cpp
//
//  Created by McLovin on 03/11/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef GLKMath_cpp_mat3_h
#define GLKMath_cpp_mat3_h
#include <iostream>
#include <GLKit/GLKMatrix3.h>
#include "glkm_types.h"
#include "mat2.h"
#include "vec3.h"
#include "vec4.h"

namespace glkm {
    class mat3 {
    public:
        mat3() : mat_(GLKMatrix3Identity){}
        
        mat3(const GLKMatrix3 &m) : mat_(m){}
        
        mat3(float m00, float m01, float m02,float m10, float m11, float m12,float m20, float m21, float m22, bool transpose = false){
            mat_ = (transpose)?GLKMatrix3MakeAndTranspose( m00, m01, m02, m10, m11, m12, m20, m21, m22):GLKMatrix3Make(m00, m01, m02, m10,  m11,  m12, m20,  m21,  m22);
        }
        
        mat3(float values[9], bool transpose = false){
            mat_ = (transpose)?GLKMatrix3MakeWithArrayAndTranspose(values):GLKMatrix3MakeWithArray(values);
        }
        
        mat3(GLKQuaternion q) : mat_(GLKMatrix3MakeWithQuaternion(q)) {}
        

        mat3(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2, ROW_COL r = ROW){
            mat_ = (r == ROW)? GLKMatrix3MakeWithRows(r0, r1, r2) : GLKMatrix3MakeWithColumns(r0, r1, r2);
        }

                
        mat3(float sx, float sy, float sz) : mat_(GLKMatrix3MakeScale(sx, sy, sz)){}
        
        mat3(float radians, float x, float y, float z) : mat_(GLKMatrix3MakeRotation(radians, x, y, z)){}
        
        mat3(float radians, ROTATION_AXIS r){
            switch (r) {
                case X: mat_ = GLKMatrix3MakeXRotation(radians); break;
                case Y: mat_ = GLKMatrix3MakeYRotation(radians); break;
                case Z: mat_ = GLKMatrix3MakeZRotation(radians); break;
            }
        }
        
        operator mat2(){
            return GLKMatrix3GetMatrix2(mat_);
        }
        
        vec3 get(int i, ROW_COL r){
            if(r == ROW)
                return GLKMatrix3GetRow(mat_, i);
            return GLKMatrix3GetColumn(mat_, i);
        }
        
        void set(int i,const vec3 &v, ROW_COL r){
            mat_ = (r == ROW) ? GLKMatrix3SetRow(mat_, r, v) : GLKMatrix3SetColumn(mat_, i, v);
        }
        
        void transpose(){
            mat_ = GLKMatrix3Transpose(mat_);
        }
        
        bool invert(bool transpose){
            bool success;
            GLKMatrix3 i = (transpose) ? GLKMatrix3InvertAndTranspose(mat_, &success) : GLKMatrix3Invert(mat_, &success);
            if(success)
                mat_ = i;
            return success;
        }
        
        friend mat3 operator*(const mat3 & a, const mat3 & b){
            return GLKMatrix3Multiply(a.mat_  , b.mat_);
        }

        friend mat3 operator+(const mat3 & a, const mat3 & b){
            return GLKMatrix3Add(a.mat_, b.mat_);
        }
        
        friend mat3 operator-(const mat3 &a, const mat3 &b){
            return GLKMatrix3Subtract(a.mat_, b.mat_);
        }
        
        void scale(float x, float y, float z){
            mat_ = GLKMatrix3Scale(mat_, x, y, z);
        }
        
        void scale(const vec3 &v){
            mat_ = GLKMatrix3ScaleWithVector3(mat_, v);
        }
        
        void scale(const vec4 &v){
            mat_ = GLKMatrix3ScaleWithVector4(mat_, v);
        }
        
        void rotate(float radians, float x, float y, float z){
            mat_ = GLKMatrix3Rotate(mat_, radians, x, y, z);
        }
        
        void rotate(float radians, const vec3 &v){
            mat_ = GLKMatrix3RotateWithVector3(mat_, radians, v);
        }
        
        void rotate(float radians, const vec4 &v){
            mat_ = GLKMatrix3RotateWithVector4(mat_, radians, v);
        }
        
        void rotate(float radians, ROTATION_AXIS r){
            switch(r){
                case X: mat_ = GLKMatrix3RotateX(mat_, radians); break;
                case Y: mat_ = GLKMatrix3RotateY(mat_, radians); break;
                case Z: mat_ = GLKMatrix3RotateZ(mat_, radians); break;
            }
        }

        friend vec3 operator*(const mat3 &m, const vec3 &v){
            return GLKMatrix3MultiplyVector3(m.mat_, v);
        }

        friend vec3 operator*(const vec3 &v, const mat3 &m){
            return GLKMatrix3MultiplyVector3(m.mat_, v);
        }

    private:
        GLKMatrix3 mat_;
    };
}
#endif
