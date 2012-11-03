//
//  mat2.h
//  GLKMath-cpp
//
//  Created by McLovin on 03/11/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef GLKMath_cpp_mat2_h
#define GLKMath_cpp_mat2_h
#include <GLKit/GLKMathTypes.h>

namespace glkm {
    class mat2{
    public:
        mat2(const GLKMatrix2 &m) : mat_(m) {}
        
    private:
        GLKMatrix2 mat_;
    };
}


#endif
