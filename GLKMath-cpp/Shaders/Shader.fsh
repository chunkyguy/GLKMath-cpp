//
//  Shader.fsh
//  GLKMath-cpp
//
//  Created by Sid on 26/10/12.
//  Copyright (c) 2012 whackylabs. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
