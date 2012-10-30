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
    v2_0 = new glkm::vec2();
    v2_1 = new glkm::vec2(10.0, 20.0);
    float arr[] = {11.0, 31.0};
    v2_2 = new glkm::vec2(arr);
}

- (void)tearDown{
    [super tearDown];
    delete v2_0;
    delete v2_1;
    delete v2_2;
}

- (void)testVec2Construction{
    STAssertTrue(glkm::vec2() == *v2_0, @"vec2: Default construction 0 fail");
    STAssertTrue(glkm::vec2(10, 20) == *v2_1, @"vec2: Default construction 1 fail");
    STAssertTrue(glkm::vec2(11, 31) == *v2_2, @"vec2: Default construction 2 fail");
}

-(void)testVec2Negate{
    STAssertTrue(*v2_1 == -(-(*v2_1)), @"vec2: Negate fail");
}

-(void)testVec2Add{
    STAssertTrue(*v2_1 + glkm::vec2(1.0, 11.0) == *v2_2, @"vec2: Add vectors fail");
    STAssertTrue(*v2_1 + 0.0 == *v2_1, @"vec2: Add scalar 1 fail");
    STAssertTrue(0.0 + *v2_2 == *v2_2, @"vec2: Add scalar 2 fail");
}

-(void)testVec2Sub{
    STAssertTrue(*v2_1 == *v2_2 - glkm::vec2(1.0, 11.0), @"vec2: Sub vectors fail");
    STAssertTrue(*v2_1 - 0.0 == *v2_1, @"vec2: Sub scalar 1 fail");
    STAssertTrue(0.0 - *v2_2 == -(*v2_2), @"vec2: Sub scalar 2 fail");
}

-(void)testVec2Mul{
    STAssertTrue(*v2_0 * *v2_2 == *v2_0, @"vec2: Mul vectors fail");
    STAssertTrue(glkm::vec2(10.0, 10.0) * 2.0 == glkm::vec2(20.0, 20.0), @"vec2: Mul scalar 1 fail");
    STAssertTrue(2.0 * glkm::vec2(10.0, 10.0) == glkm::vec2(20.0, 20.0), @"vec2: Mul scalar 2 fail");
}

-(void)testVec2Div{
    STAssertTrue(*v2_1 / glkm::vec2(1.0, 1.0) == *v2_1, @"vec2: Div vectors fail");
    STAssertTrue(glkm::vec2(10.0, 10.0)/5.0 == glkm::vec2(2.0, 2.0), @"vec2: Div scalar fail");
}

@end
