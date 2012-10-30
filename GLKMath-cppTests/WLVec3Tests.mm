//
//  WLVec3Tests.m
//  GLKMath-cpp
//
//  Created by McLovin on 30/10/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#import "WLVec3Tests.h"
#import "vec3.h"

@implementation WLVec3Tests
- (void)setUp{
    [super setUp];
}

- (void)tearDown{
    [super tearDown];
}

- (void)testvec3Construction{
    glkm::vec3 v2_0;
    STAssertTrue(glkm::vec3() == v2_0, @"vec3: construction 0 fail");
    
    glkm::vec3 v2_1(10.0, 20.0, 30.0);
    STAssertTrue(glkm::vec3(10, 20, 30) == v2_1, @"vec3: construction 1 fail");
    
    float arr[] = {11.0, 31.0, 41.0};
    glkm::vec3 v2_2(arr);
    STAssertTrue(glkm::vec3(11, 31, 41) == v2_2, @"vec3: construction 2 fail");
    
    glkm::vec3 v2_3(0.0);
    STAssertTrue(v2_3 == v2_0, @"vec3: construction 3 fail");
}

-(void)testvec3Negate{
    glkm::vec3 v2_1(10.0, 20.0, 30);
    STAssertTrue(v2_1 == -(-(v2_1)), @"vec3: Negate fail");
}

-(void)testvec3Add{
    glkm::vec3 v2_1(10.0, 20.0, 30);
    glkm::vec3 v2_2(11.0, 31.0, 41);
    STAssertTrue(v2_1 + glkm::vec3(1.0, 11.0, 11.0) == v2_2, @"vec3: Add vectors fail");
    STAssertTrue(v2_1 + 0.0 == v2_1, @"vec3: Add scalar 1 fail");
    STAssertTrue(0.0 + v2_2 == v2_2, @"vec3: Add scalar 2 fail");
}

-(void)testvec3Sub{
    glkm::vec3 v2_1(10.0, 20.0, 30);
    glkm::vec3 v2_2(11.0, 31.0, 41.0);
    STAssertTrue(v2_1 == v2_2 - glkm::vec3(1.0, 11.0, 11.0), @"vec3: Sub vectors fail");
    STAssertTrue(v2_1 - 0.0 == v2_1, @"vec3: Sub scalar 1 fail");
    STAssertTrue(0.0 - v2_2 == -(v2_2), @"vec3: Sub scalar 2 fail");
}

-(void)testvec3Mul{
    glkm::vec3 v2_0;
    glkm::vec3 v2_2(11.0, 31.0, 41);
    STAssertTrue(v2_0 * v2_2 == v2_0, @"vec3: Mul vectors fail");
    STAssertTrue(glkm::vec3(10.0, 10.0, 30) * 2.0 == glkm::vec3(20.0, 20.0, 60.0), @"vec3: Mul scalar 1 fail");
    STAssertTrue(2.0 * glkm::vec3(10.0, 10.0, 10) == glkm::vec3(20.0, 20.0, 20.0), @"vec3: Mul scalar 2 fail");
}

-(void)testvec3Div{
    glkm::vec3 v2_1(10.0, 20.0, 30);
    STAssertTrue(v2_1 / glkm::vec3(1.0, 1.0, 1.0) == v2_1, @"vec3: Div vectors fail");
    STAssertTrue(glkm::vec3(10.0, 10.0, 10.0)/5.0 == glkm::vec3(2.0, 2.0, 2.0), @"vec3: Div scalar fail");
}

-(void)testvec3Max{
    glkm::vec3 a(10, 10, 10);
    glkm::vec3 b(20, 20, 20);
    STAssertTrue(b == max(a,b), @"vec3: Max fail");
}

-(void)testvec3Min{
    glkm::vec3 a(10, 10, 10);
    glkm::vec3 b(20, 20, 20);
    STAssertTrue(a == min(a,b), @"vec3: Min fail");
}

-(void)testvec3Equal{
    glkm::vec3 a(10, 10, 10);
    STAssertTrue(a == a, @"vec3: Equal 1 fail");
    STAssertTrue(a == 10, @"vec3: Equal 2 fail");
}

-(void)testvec3Equality{
    glkm::vec3 a(10, 10, 10);
    glkm::vec3 b(20, 20, 20);
    STAssertTrue(b > a, @"vec3: > fail");
    STAssertTrue(a < b, @"vec3: < fail");
}

-(void)testvec3EqualityEqual{
    glkm::vec3 a(10, 10, 10);
    glkm::vec3 b(20, 20, 20);
    STAssertTrue(b >= a, @"vec3: >= 1 fail");
    STAssertTrue(b >= b, @"vec3: >= 2 fail");
    STAssertTrue(a <= b, @"vec3: <= 1 fail");
    STAssertTrue(a <= a, @"vec3: <= 2 fail");
}

-(void)testvec3Normalize{
    glkm::vec3 a(10.0, 20.0, 30.0);
    a.normalize();
    std::cout << "a.normalize(): " << a << std::endl;
    STAssertTrue(a <= 1.0, @"vec3: Normalize fail");
}

-(void)testvec3Dot{
    glkm::vec3 a(10, 10, 10);
    glkm::vec3 b(20, 20, 20);
    STAssertTrue(dot(a, b) == 600.0, @"vec3: Dot fail");
}

-(void)testvec3Length{
    glkm::vec3 a(10, 20, 30);
    // = 10*√14
    STAssertEqualsWithAccuracy(a.length(), 10 * sqrtf(14), 0.1, @"vec3: length fail");
}

-(void)testvec3Dist{
    glkm::vec3 a(10, 10, 10);
    glkm::vec3 b(20, 20, 20);
    // = 10√3
    STAssertEqualsWithAccuracy(distance(a,b), 10 * sqrtf(3), 0.1, @"vec3: distance fail");
}

-(void)testvec3Proj{
    glkm::vec3 a(10, 20, 30);
    glkm::vec3 b(40, 50, 60);
    //http://onlinemschool.com/math/assistance/vector/projection/ = {1280/77, 1600/77, 1920/77}
    glkm::vec3 c(1280.0/77.0, 1600.0/77.0, 1920.0/77.0);
    a.project(b);
    std::cout << "a.project(b): " << a << std::endl;
    STAssertTrue(a == c, @"vec3: projection failed");
}
@end
