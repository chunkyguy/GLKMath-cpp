//
//  GLKMath_cppTests.m
//  GLKMath-cppTests
//
//  Created by Sid on 26/10/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#import "GLKMath_cppTests.h"

@implementation GLKMath_cppTests
- (void)setUp{
    [super setUp];
}

- (void)tearDown{
    [super tearDown];
}

- (void)testVec2Construction{
    glkm::vec2 v2_0;
    STAssertTrue(glkm::vec2() == v2_0, @"vec2: construction 0 fail");
    
    glkm::vec2 v2_1(10.0, 20.0);
    STAssertTrue(glkm::vec2(10, 20) == v2_1, @"vec2: construction 1 fail");
    
    float arr[] = {11.0, 31.0};
    glkm::vec2 v2_2(arr);
    STAssertTrue(glkm::vec2(11, 31) == v2_2, @"vec2: construction 2 fail");
    
    glkm::vec2 v2_3(0.0);
    STAssertTrue(v2_3 == v2_0, @"vec2: construction 3 fail");
}

-(void)testVec2Negate{
    glkm::vec2 v2_1(10.0, 20.0);
    STAssertTrue(v2_1 == -(-(v2_1)), @"vec2: Negate fail");
}

-(void)testVec2Add{
    glkm::vec2 v2_1(10.0, 20.0);
    glkm::vec2 v2_2(11.0, 31.0);
    STAssertTrue(v2_1 + glkm::vec2(1.0, 11.0) == v2_2, @"vec2: Add vectors fail");
    STAssertTrue(v2_1 + 0.0 == v2_1, @"vec2: Add scalar 1 fail");
    STAssertTrue(0.0 + v2_2 == v2_2, @"vec2: Add scalar 2 fail");
}

-(void)testVec2Sub{
    glkm::vec2 v2_1(10.0, 20.0);
    glkm::vec2 v2_2(11.0, 31.0);
    STAssertTrue(v2_1 == v2_2 - glkm::vec2(1.0, 11.0), @"vec2: Sub vectors fail");
    STAssertTrue(v2_1 - 0.0 == v2_1, @"vec2: Sub scalar 1 fail");
    STAssertTrue(0.0 - v2_2 == -(v2_2), @"vec2: Sub scalar 2 fail");
}

-(void)testVec2Mul{
    glkm::vec2 v2_0;
    glkm::vec2 v2_2(11.0, 31.0);
    STAssertTrue(v2_0 * v2_2 == v2_0, @"vec2: Mul vectors fail");
    STAssertTrue(glkm::vec2(10.0, 10.0) * 2.0 == glkm::vec2(20.0, 20.0), @"vec2: Mul scalar 1 fail");
    STAssertTrue(2.0 * glkm::vec2(10.0, 10.0) == glkm::vec2(20.0, 20.0), @"vec2: Mul scalar 2 fail");
}

-(void)testVec2Div{
    glkm::vec2 v2_1(10.0, 20.0);
    STAssertTrue(v2_1 / glkm::vec2(1.0, 1.0) == v2_1, @"vec2: Div vectors fail");
    STAssertTrue(glkm::vec2(10.0, 10.0)/5.0 == glkm::vec2(2.0, 2.0), @"vec2: Div scalar fail");
}

-(void)testVec2Max{
    glkm::vec2 a(10, 10);
    glkm::vec2 b(20, 20);
    STAssertTrue(b == max(a,b), @"vec2: Max fail");
}

-(void)testVec2Min{
    glkm::vec2 a(10, 10);
    glkm::vec2 b(20, 20);
    STAssertTrue(a == min(a,b), @"vec2: Min fail");
}

-(void)testVec2Equal{
    glkm::vec2 a(10, 10);
    STAssertTrue(a == a, @"vec2: Equal 1 fail");
    STAssertTrue(a == 10, @"vec2: Equal 2 fail");
}

-(void)testVec2Equality{
    glkm::vec2 a(10, 10);
    glkm::vec2 b(20, 20);
    STAssertTrue(b > a, @"vec2: > fail");
    STAssertTrue(a < b, @"vec2: < fail");
}

-(void)testVec2EqualityEqual{
    glkm::vec2 a(10, 10);
    glkm::vec2 b(20, 20);
    STAssertTrue(b >= a, @"vec2: >= 1 fail");
    STAssertTrue(b >= b, @"vec2: >= 2 fail");
    STAssertTrue(a <= b, @"vec2: <= 1 fail");
    STAssertTrue(a <= a, @"vec2: <= 2 fail");
}

-(void)testVec2Normalize{
    glkm::vec2 a(10.0, 20.0);
    a.normalize();
    std::cout << "a.normalize(): " << a << std::endl;
    STAssertTrue(a <= 1.0, @"vec2: Normalize fail");
}

-(void)testVec2Dot{
    glkm::vec2 a(10, 10);
    glkm::vec2 b(20, 20);
    //Calculate here: http://tinyurl.com/98bro6o
    STAssertTrue(dot(a, b) == 400.0, @"vec2: Dot fail");
}

-(void)testVec2Length{
    glkm::vec2 a(10, 20);
    // = 10*√5
    STAssertEqualsWithAccuracy(a.length(), 10 * sqrtf(5), 0.1, @"vec2: length fail");
}

-(void)testVec2Dist{
    glkm::vec2 a(10, 10);
    glkm::vec2 b(20, 20);
    // = 10√2
    STAssertEqualsWithAccuracy(distance(a,b), 10 * sqrtf(2), 0.1, @"vec2: distance fail");
}

-(void)testVec2Proj{
    glkm::vec2 a(10, 20);
    glkm::vec2 b(30, 40);
    //http://onlinemschool.com/math/assistance/vector/projection/ = {13.2, 17.6}
    glkm::vec2 c(13.2, 17.6);
    a.project(b);
    std::cout << "a.project(b): " << a << std::endl;
    STAssertTrue(a == c, @"vec2: projection failed");
}
@end
