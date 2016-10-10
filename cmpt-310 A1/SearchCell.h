//
//  SearchCell.h
//  cmpt-310 A1
//
//  Created by Lydia on 2016-10-01.
//  Copyright © 2016 Lydia. All rights reserved.
//

#pragma once
#define WORLD_SIZE 18 //The grid is 18*18, with co-ordinates running from (0,0) to (17,17)
#include <cstdlib>
#include <stdio.h>
#include <math.h>

struct SearchCell{
    
public:
    int m_xcoord, m_ycoord; //the cell's coordinates
    int m_id; //The index of each cell
    
    SearchCell *parent; //the cell before the next choosing cell
    int G;    //the cost that needs to get to the node
    int H;    //heuristic funciton - estimate distance to the goal
    
    SearchCell() {parent = NULL;} //constructor
    
    SearchCell(int x, int y, SearchCell *_parent = 0) : m_xcoord(x), m_ycoord(y),
    parent(_parent), m_id(y * WORLD_SIZE + x), G(0), H(0) {} //
    
    int GetF() {return G + H ;} //f(n) = g(n) + h(n)
    int ManHattanDistance(SearchCell *nodeEnd)
    {
        int x = abs(this->m_xcoord - nodeEnd->m_xcoord);
        int y = abs(this->m_ycoord - nodeEnd->m_ycoord);
        return x+y;
    }
};
