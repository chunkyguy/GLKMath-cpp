//
//  vec3.h
//  GLKMath-cpp
//
//  Created by McLovin on 30/10/13.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef GLKMath_cpp_vec3_h
#define GLKMath_cpp_vec3_h
#include <iostream>
#include <GLKit/GLKVector3.h>

namespace glkm {
    
    class vec3{
    public:
        vec3() : v(GLKVector3Make(0.0, 0.0, 0.0)) {}
        vec3(float inXYZ) : v(GLKVector3Make(inXYZ, inXYZ, inXYZ)){}
        vec3(float inX, float inY, inZ) : v(GLKVector3Make(inX, inY, inZ)){}
        vec3(float array[3]) : v(GLKVector3MakeWithArray(array)) {}
        
        vec3 &operator-(){v = GLKVector3Negate(v);return *this;};
        
        friend vec3 operator+(const vec3 &a, const vec3 &b){return GLKVector3Add(a.v, b.v);}
        friend vec3 operator+(const vec3 &a, float x){return GLKVector3AddScalar(a.v, x);}
        
        friend vec3 operator-(const vec3 &a, const vec3 &b){return GLKVector3Subtract(a.v, b.v);}
        friend vec3 operator-(const vec3 &a, float x){return GLKVector3SubtractScalar(a.v, x);}
        
        friend vec3 operator*(const vec3 &a, const vec3 &b){return GLKVector3Multiply(a.v, b.v);}
        friend vec3 operator*(const vec3 &a, float x){return GLKVector3MultiplyScalar(a.v, x);}
        friend vec3 operator*(float x, const vec3 &a){return GLKVector3MultiplyScalar(a.v, x);}
        
        friend vec3 operator/(const vec3 &a, const vec3 &b){return GLKVector3Divide(a.v, b.v);}
        friend vec3 operator/(const vec3 &a, float x){return GLKVector3DivideScalar(a.v, x);}
        
        friend bool operator>(const vec3 &a, const vec3 &b){return GLKVector3AllGreaterThanVector3(a.v, b.v);}
        friend bool operator>=(const vec3 &a, const vec3 &b){return GLKVector3AllGreaterThanOrEqualToVector3(a.v, b.v);}
        friend bool operator<(const vec3 &a, const vec3 &b){return GLKVector3AllGreaterThanVector3(b.v, a.v);}
        friend bool operator<=(const vec3 &a, const vec3 &b){return GLKVector3AllGreaterThanOrEqualToVector3(b.v, a.v);}
        friend bool operator==(const vec3 &a, const vec3 &b){return GLKVector3AllEqualToVector3(a.v, b.v);}
        
        friend vec3 max(const vec3 &a, const vec3 &b){return GLKVector3Maximum(a.v, b.v);}
        friend vec3 min(const vec3 &a, const vec3 &b){return GLKVector3Minimum(a.v, b.v);}
        
        void normalize(){v = GLKVector3Normalize(v);}
        
        friend float dot(const vec3 &a, const vec3 &b){return GLKVector3DotProduct(a.v, b.v);};
        
        float length(){return GLKVector3Length(v);}
        
        friend float distance(const vec3 &a, const vec3 &b){return GLKVector3Distance(a.v, b.v);}
        
        friend vec3 lerp(const vec3 &a, const vec3 &b, float t){return GLKVector3Lerp(a.v, b.v, t);}
        
        void project(const vec3 &projection){v = GLKVector3Project(v, projection.v);}
        
        friend std::ostream &operator<<(std::ostream &os, const vec3 &vec){os  << "{" << vec.v.x << "," << vec.v.y << "}";return os;}
            
        private:
            vec3(GLKVector3 inV) : v(inV){}
            GLKVector3 v;
    };
}
#endif
