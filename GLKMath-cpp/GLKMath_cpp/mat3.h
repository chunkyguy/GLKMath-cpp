//
//  mat3.h
//  GLKMath-cpp
//
//  Created by McLovin on 03/11/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef GLKMath_cpp_mat3_h
#define GLKMath_cpp_mat3_h
#include <GLKit/GLKMatrix3.h>
namespace glkm {
    class mat3 {
    public:
        mat3 : mat_(GLKMatrix3Identity){}
        mat3(float m00, float m01, float m02,float m10, float m11, float m12,float m20, float m21, float m22) :mat_(GLKMatrix3Make(fm00, m01, m02, m10,  m11,  m12, m20,  m21,  m22)){}
        
        
    private:
        GLKMatrix3 mat_;
    };
}
#endif
