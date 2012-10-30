//
//  vec2.h
//  GLKMath-cpp
//
//  Created by McLovin on 30/10/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef __GLKMath_cpp__vec2__
#define __GLKMath_cpp__vec2__
#include <iostream>
#include <GLKit/GLKVector2.h>

namespace glkm {
    
    class vec2{
    public:
        vec2() : v(GLKVector2Make(0.0, 0.0)) {}
        vec2(float inXY) : v(GLKVector2Make(inXY, inXY)){}
        vec2(float inX, float inY) : v(GLKVector2Make(inX, inY)){}
        vec2(float array[2]) : v(GLKVector2MakeWithArray(array)) {}
        
        vec2 &operator-(){v = GLKVector2Negate(v);return *this;};
        
        friend vec2 operator+(const vec2 &a, const vec2 &b){return GLKVector2Add(a.v, b.v);}
        friend vec2 operator+(const vec2 &a, float x){return GLKVector2AddScalar(a.v, x);}
        
        friend vec2 operator-(const vec2 &a, const vec2 &b){return GLKVector2Subtract(a.v, b.v);}
        friend vec2 operator-(const vec2 &a, float x){return GLKVector2SubtractScalar(a.v, x);}
        
        friend vec2 operator*(const vec2 &a, const vec2 &b){return GLKVector2Multiply(a.v, b.v);}
        friend vec2 operator*(const vec2 &a, float x){return GLKVector2MultiplyScalar(a.v, x);}
        friend vec2 operator*(float x, const vec2 &a){return GLKVector2MultiplyScalar(a.v, x);}
        
        friend vec2 operator/(const vec2 &a, const vec2 &b){return GLKVector2Divide(a.v, b.v);}
        friend vec2 operator/(const vec2 &a, float x){return GLKVector2DivideScalar(a.v, x);}
        
        friend bool operator>(const vec2 &a, const vec2 &b){return GLKVector2AllGreaterThanVector2(a.v, b.v);}
        friend bool operator>=(const vec2 &a, const vec2 &b){return GLKVector2AllGreaterThanOrEqualToVector2(a.v, b.v);}
        friend bool operator<(const vec2 &a, const vec2 &b){return GLKVector2AllGreaterThanVector2(b.v, a.v);}
        friend bool operator<=(const vec2 &a, const vec2 &b){return GLKVector2AllGreaterThanOrEqualToVector2(b.v, a.v);}
        friend bool operator==(const vec2 &a, const vec2 &b){return GLKVector2AllEqualToVector2(a.v, b.v);}
        
        friend vec2 max(const vec2 &a, const vec2 &b){return GLKVector2Maximum(a.v, b.v);}
        friend vec2 min(const vec2 &a, const vec2 &b){return GLKVector2Minimum(a.v, b.v);}
        
        void normalize(){v = GLKVector2Normalize(v);}
        
        friend float dot(const vec2 &a, const vec2 &b){return GLKVector2DotProduct(a.v, b.v);};
        
        float length(){return GLKVector2Length(v);}

        friend float distance(const vec2 &a, const vec2 &b){return GLKVector2Distance(a.v, b.v);}
        
        friend vec2 lerp(const vec2 &a, const vec2 &b, float t){return GLKVector2Lerp(a.v, b.v, t);}

        void project(const vec2 &projection){v = GLKVector2Project(v, projection.v);}
        
        friend std::ostream &operator<<(std::ostream &os, const vec2 &vec){os  << "{" << vec.v.x << "," << vec.v.y << "}";return os;}
            
        private:
            vec2(GLKVector2 inV) : v(inV){}
            GLKVector2 v;
    };
}
#endif /* defined(__GLKMath_cpp__vec2__) */
