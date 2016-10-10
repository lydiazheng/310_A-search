//
//  main.cpp
//  cmpt-310 A1
//
//  Created by Lydia on 2016-10-05.
//  Copyright © 2016 Lydia. All rights reserved.
//
#include <iostream>
#include <vector>
#include "Vec.h"
#include "SearchCell.h"
#include "PathFinding.h"

using namespace std;
int min(int a, int b, int c, int d){
    
        int min;
        if(a <= b && a <= c && a <= d)
            min = a;
        if(b <= a && b <= c && b <= d)
            min = b;
        if(c <= a && c <= b && c <= d)
            min = c;
        if(d <= a && d <= b && d <= c)
            min = d;
        return min;
};


int main(){
    //Assignment part A
    cout << "-----------------------------------------------------" << endl;
    cout << "---------------Assignment 1 Part A-------------------" << endl;
    cout << "-----------------------------------------------------" << endl << endl;
    cout << "This is an 18*18 grid with co-ordinates from 0 to 17."<< endl;
    //int i = 18, j = 18;
    string grid[18][18];

    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 18; j++){
            grid[i][j] = ". ";
        }
           }
    
    grid[12][15] = "| ";
    for (int i = 5; i < 10; i++){
        grid[i][7] = "| ";
    }
    for(int i = 10; i < 16; i++){
        grid[13][i] = "--";
    }
    
    for (int i = 17; i >= 0; i--){
        for (int j = 0; j <18; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    cout << "Please enter the start cell(x coordinate and y coordinate): " << endl;
    int x_start, y_start;
    cin >> x_start >> y_start;
    cout << "Please enter the goal cell(x coordinate and y coordinate): "<< endl;
    int x_goal, y_goal;
    cin >> x_goal >> y_goal;
    
    //If user input is euqal to the block cell
    if ((x_start == 7 && (y_start == 5 || y_start == 6 || y_start == 7 || y_start == 8 || y_start == 9)) ||
        (x_goal == 7 && (y_goal == 5 || y_goal == 6 || y_goal == 7 || y_goal == 8 || y_goal == 9)) ||
        ((y_start == 13) && (x_start == 10 || x_start == 11 || x_start == 12 || x_start == 13 || x_start == 14 || x_start == 15)) ||
        ((y_goal == 13) && (x_goal == 10 || x_goal == 11 || x_goal == 12 || x_goal == 13 || x_goal == 14 || x_goal == 15)) ||
        ((x_start == 15 && y_start == 12) || (x_goal == 15 && y_goal == 12))
        ){
        cout << "You enter the block cell, please run the program again." << endl;
        return 0;
    };
    
    
    //Set the start cell and goal cell
    Vec start_cellA(x_start, y_start, 0);
    Vec goal_cellA(x_goal, y_goal, 0);
    
    PathFinding cellA;
    cellA.FindPath(start_cellA, goal_cellA);
    
    int size_shortest_path_partA = cellA.getShortPath().size();
    cout << endl;

    cout << "The shortest path is labelled by '* '" << endl;
    for (int i = 0; i < size_shortest_path_partA; i++){
        int x, y;
        x = cellA.getShortPath()[i]->x;
        y = cellA.getShortPath()[i]->y;
        grid[y][x] = "* ";
    }
    
    for (int i = 17; i >= 0; i--){
        for (int j = 0; j <= 17; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    //Output the shortest path through each cell.
    cout << "The shortest path is :" << endl;
    for (int i = (size_shortest_path_partA - 1); i >= 0; i--){
        cout << "(" << cellA.getShortPath()[i]->x <<"," << cellA.getShortPath()[i]->y << ") - ";
    }
    cout << endl;
    cout << "The length of the shortest path is " << (size_shortest_path_partA - 1)<< endl;
    
    //Output the total number of nodes places on the frontier
    int size_openList = cellA.getOpenListPath().size();
    int size_visitedList = cellA.getVisitedListPath().size();
    
    cout << "The total number of nodes is " << size_openList + size_visitedList << " which is places on the frontier" << endl;
    cout << endl << endl;
    
    
    
    
    
    
    
    
    
    //Assignment part B
    
    cout << "-----------------------------------------------------" << endl;
    cout << "---------------Assignment 1 Part B-------------------" << endl;
    cout << "-----------------------------------------------------" << endl << endl;
    cout << "This is an 18*18 grid with co-ordinates from 0 to 17." << endl
        << "With A, B, C and D landmarks"<< endl;
    
    //Create the whole grid
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 18; j++){
            grid[i][j] = ". ";
        }
    }
    
    grid[12][15] = "| ";
    for (int i = 5; i < 10; i++){
        grid[i][7] = "| ";
    }
    for(int i = 10; i < 16; i++){
        grid[13][i] = "--";
    }
    grid[12][5] = "A ";
    grid[12][12] = "B ";
    grid[5][5] = "C ";
    grid[5][12] = "D ";
    
    for (int i = 17; i >= 0; i--){
        for (int j = 0; j <18; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    //User input the start cell and goal cell
    cout << "Please enter the start cell(x coordinate and y coordinate): " << endl;
    cin >> x_start >> y_start;
    cout << "Please enter the goal cell(x coordinate and y coordinate): "<< endl;
    cin >> x_goal >> y_goal;
    
    //If user input is euqal to the block cell
    if ((x_start == 7 && (y_start == 5 || y_start == 6 || y_start == 7 || y_start == 8 || y_start == 9)) ||
        (x_goal == 7 && (y_goal == 5 || y_goal == 6 || y_goal == 7 || y_goal == 8 || y_goal == 9)) ||
        ((y_start == 13) && (x_start == 10 || x_start == 11 || x_start == 12 || x_start == 13 || x_start == 14 || x_start == 15)) ||
        ((y_goal == 13) && (x_goal == 10 || x_goal == 11 || x_goal == 12 || x_goal == 13 || x_goal == 14 || x_goal == 15)) ||
        ((x_start == 15 && y_start == 12) || (x_goal == 15 && y_goal == 12))
        ){
        cout << "You enter the block cell, please run the program again." << endl;
        return 0;
    };
    
    //Set the start cell and goal cell
    Vec start_cellB(x_start, y_start, 0);
    Vec goal_cellB(x_goal, y_goal, 0);
    
    PathFinding cellB;
    cellB.FindPath(start_cellB, goal_cellB);
    
    //the total number of cells on the frontier from start cell to goal cell
    int size_shortest_path_partB = cellB.getOpenListPath().size() + cellB.getVisitedListPath().size();
    
    //Start cell to A,B,C,D landmarks------find the nearest landmark
    //1) start cell to A
    Vec startA(x_start, y_start, 0);
    Vec A(5, 12, 0);
    PathFinding start_A;
    start_A.FindPath(startA, A);
    int size_path_startToA = start_A.getShortPath().size();
    
    //2)start cell to B
    Vec startB(x_start, y_start, 0);
    Vec B(12, 12, 0);
    PathFinding start_B;
    start_B.FindPath(startB, B);
    int size_path_startToB = start_B.getShortPath().size();
    
    //3)start cell to C
    Vec startC(x_start, y_start, 0);
    Vec C(5, 5, 0);
    PathFinding start_C;
    start_C.FindPath(startC, C);
    int size_path_startToC = start_C.getShortPath().size();
    
    //4)start cell to D
    Vec startD(x_start, y_start, 0);
    Vec D(12, 5, 0);
    PathFinding start_D;
    start_D.FindPath(startD, D);
    int size_path_startToD = start_D.getShortPath().size();
    
    int shortestPath_startToLandMark = min(size_path_startToA, size_path_startToB, size_path_startToC, size_path_startToD);

    //Find the nearest cell to the start cell
    Vec landmark1;
    if(size_path_startToA == shortestPath_startToLandMark){
        landmark1 = A;
        shortestPath_startToLandMark = start_A.getOpenListPath().size() + start_A.getVisitedListPath().size();
    }
    else if(size_path_startToB == shortestPath_startToLandMark){
        landmark1 = B;
        shortestPath_startToLandMark = start_B.getOpenListPath().size() + start_B.getVisitedListPath().size();
    }
    else if(size_path_startToC == shortestPath_startToLandMark){
        landmark1 = C;
        shortestPath_startToLandMark = start_C.getOpenListPath().size() + start_C.getVisitedListPath().size();
    }
    else{
        landmark1 = D;
        shortestPath_startToLandMark = start_D.getOpenListPath().size() + start_D.getVisitedListPath().size();
    }
    
    
    //Goal cell to A,B,C,D landmarks--------find the nearest landmark
    //1) goal cell to A
    Vec goalA(x_goal, y_goal, 0);
    PathFinding goal_A;
    goal_A.FindPath(goalA, A);
    int size_path_goalToA = goal_A.getShortPath().size();
    
    //2) goal cell to B
    Vec goalB(x_goal, y_goal, 0);
    PathFinding goal_B;
    goal_B.FindPath(goalB, B);
    int size_path_goalToB = goal_B.getShortPath().size();
    
    //3) goal cell to C
    Vec goalC(x_goal, y_goal, 0);
    PathFinding goal_C;
    goal_C.FindPath(goalC, C);
    int size_path_goalToC = goal_C.getShortPath().size();
    
    //4) goal cell to D
    Vec goalD(x_goal, y_goal, 0);
    PathFinding goal_D;
    goal_D.FindPath(goalD, D);
    int size_path_goalToD = goal_D.getShortPath().size();
    
    int shortestPath_goalToLandMark = min(size_path_goalToA, size_path_goalToB, size_path_goalToC, size_path_goalToD);
    
    //Find the nearest cell to the goal cell
    Vec landmark2;
    if(size_path_goalToA == shortestPath_goalToLandMark){
        landmark2 = A;
        shortestPath_goalToLandMark = goal_A.getOpenListPath().size() + goal_A.getVisitedListPath().size();
    }
    else if(size_path_goalToB == shortestPath_goalToLandMark){
        landmark2 = B;
        shortestPath_goalToLandMark = goal_B.getOpenListPath().size() + goal_B.getVisitedListPath().size();
    }
    else if(size_path_goalToC == shortestPath_goalToLandMark){
        landmark2 = C;
        shortestPath_goalToLandMark = goal_C.getOpenListPath().size() + goal_C.getVisitedListPath().size();
    }
    else if (size_path_goalToD == shortestPath_goalToLandMark){
        landmark2 = D;
        shortestPath_goalToLandMark = goal_D.getOpenListPath().size() + goal_D.getVisitedListPath().size();
    }
    
    //The more efficiency path from the start cell to goal cell
    int size_eff_path = 0;
    if (size_shortest_path_partB < (shortestPath_startToLandMark + shortestPath_goalToLandMark)){
        size_eff_path = size_shortest_path_partB;
        int size_cellB = cellB.getShortPath().size();
        
        cout << "The shortest path is labelled by '* '" << endl;
        for (int i = 0; i < size_cellB; i++){
            int x, y;
            x = cellB.getShortPath()[i]->x;
            y = cellB.getShortPath()[i]->y;
            grid[y][x] = "* ";
        }
        
        for (int i = 17; i >= 0; i--){
            for (int j = 0; j <= 17; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        
        cout << "The shortest path is :" << endl<<endl;
        for (int i = (size_cellB - 1); i >= 0; i--){
            cout << "(" << cellB.getShortPath()[i]->x <<"," << cellB.getShortPath()[i]->y << ") - ";
        }
        cout << endl<<endl;
        cout << "The length of the shortest path is " << (size_cellB - 1)<< endl;

        
    }
    else{
        size_eff_path = shortestPath_startToLandMark + shortestPath_goalToLandMark;
        PathFinding path1, path3;
        path1.FindPath(start_cellB, landmark1);
        path3.FindPath(landmark2, goal_cellB);
        
        int size_path1 = path1.getShortPath().size();
        int size_path3 = path3.getShortPath().size();
        
        PathFinding landmark1To2;
        landmark1To2.FindPath(landmark1, landmark2);
        int size_landmark = landmark1To2.getShortPath().size();
        
        cout << "The shortest path is labelled by '* '" << endl;
        for (int i = 0; i < size_path1; i++){
            int x1, y1;
            x1 = path1.getShortPath()[i]->x;
            y1 = path1.getShortPath()[i]->y;
            grid[y1][x1] = "* ";
        }
        for(int i = 0;i < size_landmark; i++){
            int x2, y2;
            x2 = landmark1To2.getShortPath()[i]->x;
            y2 = landmark1To2.getShortPath()[i]->y;
            grid[y2][x2] = "* ";
        }
        for (int i = 0; i <size_path3; i++){
            int x3, y3;
            x3 = path3.getShortPath()[i]->x;
            y3 = path3.getShortPath()[i]->y;
            grid[y3][x3] = "* ";
        }
        
        for (int i = 17; i >= 0; i--){
            for (int j = 0; j <= 17; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }

        //Output the shortest path through each cell.
        cout << "The shortest path is :" << endl;
        for (int i = (size_path1 - 1); i >= 0; i--){
            cout << "(" << path1.getShortPath()[i]->x <<"," << path1.getShortPath()[i]->y << ") - ";
        }
        for (int i = (size_landmark - 1); i > 0; i--){
            cout << "(" << landmark1To2.getShortPath()[i]->x <<"," << landmark1To2.getShortPath()[i]->y << ") - ";
        }
        for (int i = (size_path3 - 1); i >= 0; i--){
            cout << "(" << path3.getShortPath()[i]->x <<"," << path3.getShortPath()[i]->y << ") - ";
        }
        cout << endl<< endl;
        
        cout << "The length of the shortest path is " << (size_path1 + size_landmark + size_path3 - 3)<< endl;
        cout << endl;
        cout << "The number of cells on the frontier that is from start cell to nearest landmark: " << shortestPath_startToLandMark << endl;
        cout << "The number of cells on the frontier that is from goal cell to nearest landmark: " << shortestPath_goalToLandMark << endl;
    };
    
    //Output the total number of nodes places on the frontier
  
    cout << "The total number of nodes is " << size_eff_path << " which is places on the frontier" << endl;
    cout << endl << endl;

    return 0;
}


