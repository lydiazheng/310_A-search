//
//  Vec.cpp
//  cmpt-310 A1
//
//  Created by Lynn on 2016-10-01.
//  Copyright © 2016 Lydia. All rights reserved.
//

#include <stdio.h>
#include "Vec.h"

Vec::Vec(void){
    x = 0;
    y = 0;
    z = 0;
}

Vec::Vec(int xcoord, int ycoord, int zcoord){
    x = xcoord;
    y = ycoord;
    z = zcoord;
}


