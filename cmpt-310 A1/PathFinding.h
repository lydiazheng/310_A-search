//
//  PathFinding.hpp
//  cmpt-310 A1
//
//  Created by Lynn on 2016-10-01.
//  Copyright © 2016 Lydia. All rights reserved.
//

#pragma once

#include "Vec.h"
#include "SearchCell.h"
#include <vector>
#include <stdio.h>

class PathFinding
{
private:
    void SetStartAndGoal(SearchCell start, SearchCell goal);//set start cell and goal cell with user input
    void PathOpened(int x, int y, int newCost, SearchCell *parent);//check the current cell is in the open list
    SearchCell *GetNextCell(); //get next available cell -find the smallest cell
    void ContinuePath(); //search thoughout the world and expand the position to find the goal cell
    
    SearchCell *m_startCell;
    SearchCell *m_goalCell;
    std::vector<SearchCell*> m_openList; //open list
    std::vector<SearchCell*> m_visitedList; //closed list
    std::vector<Vec*> m_pathToGoal; //get the short path to the goal cell
    
    
public:
    PathFinding(void);//constructor
    ~PathFinding(void);//destructor
    
    void FindPath(Vec currentPos, Vec targetPos);//path from the current position to the goal position
    void ClearOpenList() { m_openList.clear(); } //clear open list
    void ClearVisitedList() { m_visitedList.clear(); }
    void ClearPathToGoal() { m_pathToGoal.clear(); }
    bool m_initializedStartGoal;
    bool m_foundGoal;
    std::vector<Vec*> getShortPath();
    std::vector<SearchCell*> getOpenListPath();
    std::vector<SearchCell*> getVisitedListPath();
};
