### CMPT 310 Assignment 1
### Created by Lydia Zheng

#### Introduction

### This assignment deals with an offline navigation problem. In general, Search can be on a directed, labelled graph.

I used the A start search as my strategy to find the shortest path from the start point to the goal point. 
I create a class called SearchNode to represent the node with attributes x y coordinates, node-id,G is the node’s movement cost and H, which represents the Heuristic cost is a pointer pointing to it’s parent node. Also, I included the default constructor and parameterized constructor, GetF function to get the total costs by F = G + H and GetH function that uses Manhattan distance. The Manhattan distance adds the x differences and y differences between the current node and the goal node. 

I created the class called PathSearch used to find the path from the start node to goal node. For the implementation of each function in the class, they are included in the Astarsearch.cpp. The main idea of the A star search is that we first create two lists, open list and close list to hold nodes. We start with the start node and put it into the open list, and then expanding the adjacent nodes of the current node retrieved from the open list with the smallest value when the node would be the start node at the first time. After that, we put the current node into the close list. The adjacent nodes of the current node are the right node, left node, and upper node and down node. Next, we check the expanded nodes, if the node is the block or is out of boundary, then we just skip the node. Otherwise, we add the node into the open list and continue the process recursively. Moreover, if the expanded node is already in the open list, we need to check if its value and pointer to its parent need to be updated. After expansions, we will get the goal node.



#### C++ language for the whole program
----------------------------------------------------------------------------------------------------------------
##### How to run the program:
##### 1) I put PartA and PartB in the same main function, so we should firstly run the PartA then run PartB.

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
	   iv/  And it will also show the number of the whole path cells on the frontier from the goal cell to the goal cell.
		
