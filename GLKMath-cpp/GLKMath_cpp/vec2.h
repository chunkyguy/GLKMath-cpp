//
//  vec2.h
//  GLKMath-cpp
//
//  Created by McLovin on 30/10/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef __GLKMath_cpp__vec2__
#define __GLKMath_cpp__vec2__
#include <GLKit/GLKVector2.h>

namespace glkm {
    
    class vec2{
    public:
        vec2(float inX = 0.0, float inY = 0.0) : v(GLKVector2Make(inX, inY)){}
        vec2(float array[2]) : v(GLKVector2MakeWithArray(array)) {}
        vec2 &operator-(){
            v = GLKVector2Negate(v);
            return *this;
        };
        friend vec2 operator+(const vec2 &, const vec2 &);
        friend vec2 operator+(const vec2 &, float x);
        
        friend vec2 operator-(const vec2 &, const vec2 &);
        friend vec2 operator-(const vec2 &, float x);
        
        friend vec2 operator*(const vec2 &, const vec2 &);
        friend vec2 operator*(const vec2 &, float x);
        friend vec2 operator*(float x, const vec2 &);
        
        friend vec2 operator/(const vec2 &, const vec2 &);
        friend vec2 operator/(const vec2 &, float x);
        
        friend bool operator==(const vec2 &, const vec2 &);
    private:
        vec2(GLKVector2 inV) : v(inV){}
        GLKVector2 v;
    };
}
#endif /* defined(__GLKMath_cpp__vec2__) */
