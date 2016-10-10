//
//  PathFinding.cpp
//  cmpt-310 A1
//
//  Created by Lydia on 2016-10-01.
//  Copyright © 2016 Lydia. All rights reserved.
//
#include "PathFinding.h"
#include "Vec.h"

//constructor
PathFinding::PathFinding(void)
{
    m_initializedStartGoal = false;
    m_foundGoal = false;
}

//destructor
PathFinding::~PathFinding(void)
{
}

void PathFinding::FindPath(Vec currentPos, Vec targetPos){
    
    if (!m_initializedStartGoal){    // for the first time m_initializedStartGoal = true
        SearchCell start;
        start.m_xcoord = currentPos.x;
        start.m_ycoord = currentPos.y;

        //Initialize goal cell
        SearchCell goal;
        goal.m_xcoord = targetPos.x;
        goal.m_ycoord = targetPos.y;

        SetStartAndGoal(start, goal);
        m_initializedStartGoal = true;
    }

    if(m_initializedStartGoal){
        ContinuePath();
    }
}

void PathFinding::SetStartAndGoal(SearchCell start, SearchCell goal){
    m_startCell = new SearchCell(start.m_xcoord, start.m_ycoord, NULL);//set parent to NULL
    m_goalCell = new SearchCell(goal.m_xcoord, goal.m_ycoord, &goal);
    
    m_startCell->G = 0;
    m_startCell->H = m_startCell->ManHattanDistance(m_goalCell);
    m_startCell->parent = NULL;
    
    m_openList.push_back(m_startCell);//push the cell to the open list and push back the start cell
}


SearchCell* PathFinding::GetNextCell(){
    int bestF = 99999; //check  which is the bestF is in the open list
    int cellIndex = -1;
    SearchCell* nextCell = 0;
    
    for(int i = 0; i < m_openList.size(); i++){
        if(m_openList[i]->GetF() < bestF){ //for the first time at beginning bestF is bigger
            bestF = m_openList[i] ->GetF();

            cellIndex = i;
        }
    }
    
    if(cellIndex >= 0){
        nextCell = m_openList[cellIndex];
        m_visitedList.push_back(nextCell);
        m_openList.erase(m_openList.begin()+ cellIndex);
    }
    
    return nextCell;
}

void PathFinding::PathOpened(int x,int y, int newCost, SearchCell *parent){
    /*if (CELL_BLOCKED){
     return;
     }
     */
    int id = y * WORLD_SIZE +x;
    
    //if the node is already in the closed list then we return it
    for (int i = 0; i < m_visitedList.size(); i++){
        if(id == m_visitedList[i]->m_id){
            return;
        }
    }
    if(x < 0 || x > 17 || y < 0 || y > 17){
        return;
    }
    
    //create a new cell
    //SearchCell* newChild = new SearchCell(x, z, parent);
    //test whether the cell is an obstacle or not
    //add the obstacle cell in the visited list and then return
    if(id == 97 || id == 115 || id == 133 || id == 151 || id == 169 || id == 244 || id == 245 || id == 246 || id == 247 || id == 248 || id == 249 || id == 231){ //coordinates of 2 obstacles cell
        //SearchCell* Child = new SearchCell(x, y, parent);
        //m_visitedList.push_back(Child);
        return;
    }
    
    
    
    //newChild is a pointer which points to the newChild node
    SearchCell* newChild = new SearchCell(x, y, parent);//we should move this line
    
    newChild->G = newCost;//??
    newChild->H = newChild->ManHattanDistance(m_goalCell);//?? newChild->ManHattanDistance(m_goalCell)
    
    for(int i = 0; i < m_openList.size(); i++){
        if(id == m_openList[i]->m_id){
            int newF = newChild->G + m_openList[i]->H;//we should remove newCost(F = G+H)
            
            if(m_openList[i]->GetF() >newF){
                m_openList[i]->G = newChild->G;
                m_openList[i]->parent = parent; //newChild should point to the formal parent
                return;
            }
            else {     //if the F is not better
                delete newChild;
                return;
            }
        }
    }
    
    m_openList.push_back(newChild);
}


void PathFinding::ContinuePath(){
    if(m_openList.empty()){
        return;
    }
    
    SearchCell* currentCell = GetNextCell();
    
    if(currentCell->m_id == m_goalCell->m_id){
        m_goalCell->parent = currentCell->parent;
        
        SearchCell* getPath;
        for(getPath = m_goalCell; getPath != NULL; getPath = getPath->parent){
            m_pathToGoal.push_back(new Vec(getPath->m_xcoord, getPath->m_ycoord, 0));
        }
        
        m_foundGoal = true;
        return;
    }
    else{
        //rightCell
        PathOpened(currentCell->m_xcoord+1, currentCell->m_ycoord, currentCell->G+10, currentCell);
        //Up
        PathOpened(currentCell->m_xcoord, currentCell->m_ycoord+1, currentCell->G+10, currentCell);
        //leftCell
        PathOpened(currentCell->m_xcoord-1, currentCell->m_ycoord, currentCell->G+10, currentCell);
        //Down
        PathOpened(currentCell->m_xcoord, currentCell->m_ycoord-1, currentCell->G+10, currentCell);
        
        for(int i = 0; i< m_openList.size(); i++){
            if(currentCell->m_id == m_openList[i]->m_id){
                m_openList.erase(m_openList.begin() + i);
            }
        }
    }
    ContinuePath();
}

std::vector<Vec*> PathFinding::getShortPath(){
    return m_pathToGoal;
}
std::vector<SearchCell*> PathFinding::getOpenListPath(){
    return m_openList;
}

std::vector<SearchCell*> PathFinding::getVisitedListPath(){
    return m_visitedList;
}









