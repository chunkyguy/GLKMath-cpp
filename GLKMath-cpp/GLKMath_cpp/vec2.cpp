//
//  vec2.cpp
//  GLKMath-cpp
//
//  Created by McLovin on 30/10/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#include "vec2.h"

bool operator==(const vec2 &a, const vec2 &b){
    return GLKVector2AllEqualToVector2(a.v, b.v);
}

vec2 operator+(const vec2 &a, const vec2 &b){
    return GLKVector2Add(a.v, b.v);
}
vec2 operator+(const vec2 &a, float x){
    return GLKVector2AddScalar(a.v, x);
}

vec2 operator-(const vec2 &a, const vec2 &b){
    return GLKVector2Subtract(a.v, b.v);
}
vec2 operator-(const vec2 &a, float x){
    return GLKVector2SubtractScalar(a.v, x);
}

vec2 operator*(const vec2 &a, const vec2 &b){
    return GLKVector2Multiply(a.v, b.v);
}
vec2 operator*(const vec2 &a, float x){
    return GLKVector2MultiplyScalar(a.v, x);
}

vec2 operator/(const vec2 &a, const vec2 &b){
    return GLKVector2Divide(a.v, b.v);
}
vec2 operator/(const vec2 &a, float x){
    return GLKVector2DivideScalar(a.v, x);
}
