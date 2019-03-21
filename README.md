## CMPT 310 Assignment 1
Created by Lydia Zheng

### Introduction
This is an assignment for course Artificial Intelligence Survey in Simon Fraser University. The program, written in C++, was designed to study and implement A* search algorithm.

### Algorithm overview 
#### This assignment deals with an offline navigation problem. In general, the search algorithm can be applied on a directed and labelled graph.

A star search as the chosen strategy aims to find the shortest path between start point and the goal point. 

**Two C++ classes, namely `SearchNode` and `PathSearch` are created in the implementation. Below are the explanation of these two classes.**

A start search was used as my strategy to find the shortest path from the start point to the goal point. 

The class named 'SearchNode' represents the node with attributes x y coordinates, node-id. G is the node’s movement cost and H, which represents the Heuristic cost, is a pointer storing the address its parent node. In addition, the default constructor and parameterized constructor are customized. GetF function, who utilized Manhattan distance function, targets on getting the total costs by F = G + H. The Manhattan distance adds the differences in x and y directions between the current node and the goal node. 


The class 'PathSearch' is to find the path from the starting node to the goal node. For the implementation of each function are included in the Astarsearch.cpp. The main idea of the A star search is we first create two lists, open list and close list to hold nodes. We insert the starting node into the open list, then expanding the adjacent nodes of the current node are retrieved from the open list with the smallest value when such node becomes starting node at the first occasion. After that, the current node is inserted into the close list. The adjacent nodes of the current node are defined by its right node, left node, upper node and the node below except boundary nodes. The node were appended into the open list and continue the process recursively. Moreover, if the expanded node is already in the open list, we need to check whether its value and the pointer to its parent need to be updated. After expansions, we will get the goal node.



----------------------------------------------------------------------------------------------------------------
### How to run the program:
##### 1) PartA and PartB stay the same main function, so first run PartA then PartB

##### 2) In the PartA:
	a) Show an 18*18 grid map with '.' and obstacles with '|' and '--'.
	b) Input the start cell's coordinate and the goal cell's coordinate .
		<e.g> start cell:
			  1 1
			  goal cell:
			  5 5
		Use ' '(space) to seperate x coordinate and y coordinate.
	c) When you enter the block cell as the start cell or the goal cell, you will need to run the program again.
	d) The output will show the map of the shortest path using the path sigh '*',
		each cell of the path,
		the length of the path and
		the total number of the cells on the frontier.

##### 3)In the PartB:
	a) Show a new 18*18 grid map with '.' , obstacles with '|' and '--' and A,B,C,D landmarks.
	b) Input the start cell's coordinate and the goal cell's coordinate .
		<e.g.> start cell:
			  1 1
			  goal cell:
			  5 5
		Use ' '(space) to separate x coordinate and y coordinate.
	c) If you enter the block cell as the start cell or the goal cell, you will need to run the program again.
		And you should repeat the steps in PartA.
	d) i/   The output will show the map of the more efficient path, if the path goes through the landmark, the sign of the 
	       landmark will be covered by the path sigh '*'.
	   ii/  Show each cell of the path, the length of the path.
	   iii/ If the more efficient path is not the shortest path, the output will show the number of cells on the frontier 
	       from start cell to the nearest landmark and the number of cells on the frontier from the goal cell to the nearest landmark. 
	   iv/  And it also show the number of the whole path cells on the frontier from the goal cell to the goal cell.
		
