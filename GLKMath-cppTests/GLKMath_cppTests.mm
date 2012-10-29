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
    v2_2 = new vec2(11.0, 31.0);
}

- (void)tearDown{
    [super tearDown];
    delete v2_0;
    delete v2_1;
    delete v2_2;
}

- (void)testVec2Construction{
    STAssertTrue(vec2() == *v2_0, @"vec2: Default construction fail");
}

@end
