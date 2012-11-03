//
//  WLVec4Tests.m
//  GLKMath-cpp
//
//  Created by Sid on 03/11/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

#import "WLVec4Tests.h"
#import "vec4.h"

@implementation WLVec4Tests
- (void)setUp{
    [super setUp];
}

- (void)tearDown{
    [super tearDown];
}

- (void)testvec4Construction{
    glkm::vec4 v2_0;
    STAssertTrue(glkm::vec4() == v2_0, @"vec4: construction 0 fail");
    
    glkm::vec4 v2_1(10.0, 20.0, 30.0, 40.0);
    STAssertTrue(glkm::vec4(10, 20, 30, 40) == v2_1, @"vec4: construction 1 fail");
    
    float arr[] = {11.0, 31.0, 41.0, 50};
    glkm::vec4 v2_2(arr);
    STAssertTrue(glkm::vec4(11, 31, 41, 50) == v2_2, @"vec4: construction 2 fail");
    
    glkm::vec4 v2_3(0.0);
    STAssertTrue(v2_3 == v2_0, @"vec4: construction 3 fail");
}

-(void)testvec4Negate{
    glkm::vec4 v2_1(10.0, 20.0, 30, 40);
    STAssertTrue(v2_1 == -(-(v2_1)), @"vec4: Negate fail");
}

-(void)testvec4Add{
    glkm::vec4 v2_1(10.0, 20.0, 30, 40);
    glkm::vec4 v2_2(11.0, 31.0, 41, 50);
    STAssertTrue(v2_1 + glkm::vec4(1.0, 11.0, 11.0, 10) == v2_2, @"vec4: Add vectors fail");
    STAssertTrue(v2_1 + 0.0 == v2_1, @"vec4: Add scalar 1 fail");
    STAssertTrue(0.0 + v2_2 == v2_2, @"vec4: Add scalar 2 fail");
}

-(void)testvec4Sub{
    glkm::vec4 v2_1(10.0, 20.0, 30, 40);
    glkm::vec4 v2_2(11.0, 31.0, 41.0, 50);
    STAssertTrue(v2_1 == v2_2 - glkm::vec4(1.0, 11.0, 11.0, 10), @"vec4: Sub vectors fail");
    STAssertTrue(v2_1 - 0.0 == v2_1, @"vec4: Sub scalar 1 fail");
    STAssertTrue(0.0 - v2_2 == -(v2_2), @"vec4: Sub scalar 2 fail");
}

-(void)testvec4Mul{
    glkm::vec4 v2_0;
    glkm::vec4 v2_2(11.0, 31.0, 41, 50);
    STAssertTrue(v2_0 * v2_2 == v2_0, @"vec4: Mul vectors fail");
    STAssertTrue(glkm::vec4(10.0, 10.0, 30, 50) * 2.0 == glkm::vec4(20.0, 20.0, 60.0, 100), @"vec4: Mul scalar 1 fail");
    STAssertTrue(2.0 * glkm::vec4(10.0, 10.0, 10, 50) == glkm::vec4(20.0, 20.0, 20.0, 100), @"vec4: Mul scalar 2 fail");
}

-(void)testvec4Div{
    glkm::vec4 v2_1(10.0, 20.0, 30, 40);
    STAssertTrue(v2_1 / glkm::vec4(1.0, 1.0, 1.0, 1.0) == v2_1, @"vec4: Div vectors fail");
    STAssertTrue(glkm::vec4(10.0, 10.0, 10.0, 50)/5.0 == glkm::vec4(2.0, 2.0, 2.0, 10), @"vec4: Div scalar fail");
}

-(void)testvec4Max{
    glkm::vec4 a(10, 10, 10, 10);
    glkm::vec4 b(20, 20, 20, 20);
    STAssertTrue(b == max(a,b), @"vec4: Max fail");
}

-(void)testvec4Min{
    glkm::vec4 a(10, 10, 10, 10);
    glkm::vec4 b(20, 20, 20, 20);
    STAssertTrue(a == min(a,b), @"vec4: Min fail");
}

-(void)testvec4Equal{
    glkm::vec4 a(10, 10, 10, 10);
    STAssertTrue(a == a, @"vec4: Equal 1 fail");
    STAssertTrue(a == 10, @"vec4: Equal 2 fail");
}

-(void)testvec4Equality{
    glkm::vec4 a(10, 10, 10, 10);
    glkm::vec4 b(20, 20, 20, 20);
    STAssertTrue(b > a, @"vec4: > fail");
    STAssertTrue(a < b, @"vec4: < fail");
}

-(void)testvec4EqualityEqual{
    glkm::vec4 a(10, 10, 10, 10);
    glkm::vec4 b(20, 20, 20, 20);
    STAssertTrue(b >= a, @"vec4: >= 1 fail");
    STAssertTrue(b >= b, @"vec4: >= 2 fail");
    STAssertTrue(a <= b, @"vec4: <= 1 fail");
    STAssertTrue(a <= a, @"vec4: <= 2 fail");
}

-(void)testvec4Normalize{
    glkm::vec4 a(10.0, 20.0, 30.0, 40);
    a.normalize();
    std::cout << "a.normalize(): " << a << std::endl;
    STAssertTrue(a <= 1.0, @"vec4: Normalize fail");
}

-(void)testvec4Dot{
    glkm::vec4 a(10, 20, 30, 40);
    glkm::vec4 b(40, 50, 60, 70);
    STAssertTrue(dot(a, b) == 6000.0, @"vec4: Dot fail");
}

-(void)testvec4Cross{
    glkm::vec4 a(10, 20, 30, 40);
    glkm::vec4 b(40, 50, 60, 70);
	glkm::vec4 c(-300,600,-300, 0);
	std::cout << "cross(a,b) " << cross(a,b) << std::endl;
	STAssertTrue(cross(a,b) == c, @"vec4: Cross fail");
}

-(void)testvec4Length{
    glkm::vec4 a(10, 20, 30, 40);
    // = 10*√30
    STAssertEqualsWithAccuracy(a.length(), 10 * sqrtf(30), 0.1, @"vec4: length fail");
}

-(void)testvec4Dist{
    glkm::vec4 a(10, 10, 10, 10);
    glkm::vec4 b(20, 20, 20, 20);
    // = 10√4
    STAssertEqualsWithAccuracy(distance(a,b), 10 * sqrtf(4), 0.1, @"vec4: distance fail");
}

-(void)testvec4Proj{
    glkm::vec4 a(10, 20, 30, 40);
    glkm::vec4 b(40, 50, 60, 70);
    //http://onlinemschool.com/math/assistance/vector/projection/ = {1280/77, 1600/77, 1920/77}
    glkm::vec4 c(19.0476,23.8095,28.5714,33.3333);
    a.project(b);
    std::cout << "a.project(b): " << a << std::endl;
	STAssertEqualsWithAccuracy(a, c, 0.1, @"vec4: projection failed");
	//    STAssertTrue(a == c, @"vec4: projection failed");
}

@end
