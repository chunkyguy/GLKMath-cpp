//
//  vec4.h
//  GLKMath-cpp
//
//  Created by Sid on 03/11/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef GLKMath_cpp_vec4_h
#define GLKMath_cpp_vec4_h
#include <iostream>
#include <GLKit/GLKVector4.h>

namespace glkm {
    
    class vec4{
    public:
        vec4() : v(GLKVector4Make(0.0, 0.0, 0.0, 0.0)) {}
        vec4(GLKVector4 inV) : v(inV){}
        vec4(float inXYZW) : v(GLKVector4Make(inXYZW, inXYZW, inXYZW, inXYZW)){}
        vec4(float inX, float inY, float inZ, float inW) : v(GLKVector4Make(inX, inY, inZ, inW)){}
        vec4(float array[4]) : v(GLKVector4MakeWithArray(array)) {}
        
        vec4 &operator-(){v = GLKVector4Negate(v);return *this;};
        
        friend vec4 operator+(const vec4 &a, const vec4 &b){return GLKVector4Add(a.v, b.v);}
        friend vec4 operator+(const vec4 &a, float x){return GLKVector4AddScalar(a.v, x);}
        
        friend vec4 operator-(const vec4 &a, const vec4 &b){return GLKVector4Subtract(a.v, b.v);}
        friend vec4 operator-(const vec4 &a, float x){return GLKVector4SubtractScalar(a.v, x);}
        
        friend vec4 operator*(const vec4 &a, const vec4 &b){return GLKVector4Multiply(a.v, b.v);}
        friend vec4 operator*(const vec4 &a, float x){return GLKVector4MultiplyScalar(a.v, x);}
        friend vec4 operator*(float x, const vec4 &a){return GLKVector4MultiplyScalar(a.v, x);}
        
        friend vec4 operator/(const vec4 &a, const vec4 &b){return GLKVector4Divide(a.v, b.v);}
        friend vec4 operator/(const vec4 &a, float x){return GLKVector4DivideScalar(a.v, x);}
        
        friend bool operator>(const vec4 &a, const vec4 &b){return GLKVector4AllGreaterThanVector4(a.v, b.v);}
        friend bool operator>=(const vec4 &a, const vec4 &b){return GLKVector4AllGreaterThanOrEqualToVector4(a.v, b.v);}
        friend bool operator<(const vec4 &a, const vec4 &b){return GLKVector4AllGreaterThanVector4(b.v, a.v);}
        friend bool operator<=(const vec4 &a, const vec4 &b){return GLKVector4AllGreaterThanOrEqualToVector4(b.v, a.v);}
        friend bool operator==(const vec4 &a, const vec4 &b){return GLKVector4AllEqualToVector4(a.v, b.v);}
        
        friend vec4 max(const vec4 &a, const vec4 &b){return GLKVector4Maximum(a.v, b.v);}
        friend vec4 min(const vec4 &a, const vec4 &b){return GLKVector4Minimum(a.v, b.v);}
        
        void normalize(){v = GLKVector4Normalize(v);}
        
        friend float dot(const vec4 &a, const vec4 &b){return GLKVector4DotProduct(a.v, b.v);}
		
		friend vec4 cross(const vec4 &a, const vec4 &b){return GLKVector4CrossProduct(a.v, b.v);}
        
        float length(){return GLKVector4Length(v);}
        
        friend float distance(const vec4 &a, const vec4 &b){return GLKVector4Distance(a.v, b.v);}
        
        friend vec4 lerp(const vec4 &a, const vec4 &b, float t){return GLKVector4Lerp(a.v, b.v, t);}
        
        void project(const vec4 &projection){v = GLKVector4Project(v, projection.v);}
        
        operator GLKVector4() const {return v;}
        
        friend std::ostream &operator<<(std::ostream &os, const vec4 &vec){os  << "{" << vec.v.x << "," << vec.v.y << "," << vec.v.z << "," << vec.v.w << "}";return os;}
            
        private:
            GLKVector4 v;
	};
}
#endif
