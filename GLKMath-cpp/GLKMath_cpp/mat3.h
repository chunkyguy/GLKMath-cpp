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
#include "mat2.h"
#include "vec3.h"

namespace glkm {
    class mat3 {
    public:
        mat3() : mat_(GLKMatrix3Identity){}
        
        mat3(float m00, float m01, float m02,float m10, float m11, float m12,float m20, float m21, float m22) :
        mat_(GLKMatrix3Make(m00, m01, m02, m10,  m11,  m12, m20,  m21,  m22)){}
        
        mat3(float values[9]) : mat_(GLKMatrix3MakeWithArray(values)){}
        
        mat3(GLKQuaternion q) : mat_(GLKMatrix3MakeWithQuaternion(q)) {}
        
        mat3 makeWithRows(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2){
            return GLKMatrix3MakeWithRows(r0, r1, r2);
        }

        mat3 makeWithColumns(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2){
            return GLKMatrix3MakeWithColumns(r0, r1, r2);
        }
        
        mat3 makeTranspose(float m00, float m01, float m02,float m10, float m11, float m12,float m20, float m21, float m22){
            return GLKMatrix3MakeAndTranspose( m00, m01, m02, m10, m11, m12, m20, m21, m22);
        }
        
        mat3 makeTranspose(float values[9]){
            return GLKMatrix3MakeWithArrayAndTranspose(values);
        }
        
        mat3 makeScale(float x, float y, float z){
            return GLKMatrix3MakeScale(x, y, z);
        }
        
        mat3 makeRotate(float radians, float x, float y, float z){
            return GLKMatrix3MakeRotation(radians, x, y, z);
        }
        
        mat3 makeXRotation(float radians){
            return GLKMatrix3MakeXRotation(radians);
        }

        mat3 makeYRotation(float radians){
            return GLKMatrix3MakeYRotation(radians);
        }

        mat3 makeZRotation(float radians){
            return GLKMatrix3MakeZRotation(radians);
        }
        
        operator mat2(){
            return GLKMatrix3GetMatrix2(mat_);
        }
        
        vec3 getRow(int r){
            return GLKMatrix3GetRow(mat_, r);
        }
        
        vec3 getColumn(int c){
            return GLKMatrix3GetColumn(mat_, c);
        }
        
        void setRow(int r, vec3 v){
            mat_ = GLKMatrix3SetRow(mat_, r, v);
        }

    private:
        mat3(const GLKMatrix3 &m) : mat_(m){}
        GLKMatrix3 mat_;
    };
}
#endif
