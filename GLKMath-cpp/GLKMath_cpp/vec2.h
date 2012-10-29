//
//  vec2.h
//  GLKMath-cpp
//
//  Created by McLovin on 30/10/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#ifndef __GLKMath_cpp__vec2__
#define __GLKMath_cpp__vec2__
class vec2{
public:
    //GLKVector2Make
    vec2(float inX = 0.0, float inY = 0.0) : x(inX), y(inY) {}
    
    bool operator==(const vec2 &v){ return (v.x == x) && (v.y == y);}
    
private:
    float x, y;
};

#endif /* defined(__GLKMath_cpp__vec2__) */
