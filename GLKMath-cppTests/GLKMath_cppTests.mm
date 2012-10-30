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
    v2_0 = new vec2();
    v2_1 = new vec2(10.0, 20.0);
    float arr[] = {11.0, 31.0};
    v2_2 = new vec2(arr);
}

- (void)tearDown{
    [super tearDown];
    delete v2_0;
    delete v2_1;
    delete v2_2;
}

- (void)testVec2Construction{
    STAssertTrue(vec2() == *v2_0, @"vec2: Default construction 0 fail");
    STAssertTrue(vec2(10, 20) == *v2_1, @"vec2: Default construction 1 fail");
    STAssertTrue(vec2(11, 31) == *v2_2, @"vec2: Default construction 2 fail");
}

-(void)testVec2Negate{
    STAssertTrue(*v2_1 == -(-(*v2_1)), @"vec2: Negate fail");
}

-(void)testVec2Add{
    STAssertTrue(*v2_1 + vec2(1.0, 11.0) == *v2_2, @"vec2: Add vectors fail");
}

-(void)testVec2Sub{
    STAssertTrue(*v2_1 == *v2_2 - vec2(1.0, 11.0), @"vec2: Sub vectors fail");
}

-(void)testVec2Mul{
    STAssertTrue(*v2_0 * *v2_2 == *v2_0, @"vec2: Mul vectors fail");
}

-(void)testVec2Div{
    STAssertTrue(*v2_1 / vec2(1.0, 1.0) == *v2_1, @"vec2: Div vectors fail");
}

@end
