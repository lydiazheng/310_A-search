CMPT 310 Assignment 1
Created by Lydia Zheng


C++ language for the whole program
----------------------------------------------------------------------------------------------------------------
How to run the program:
1)I put PartA and PartB in the same main function, so we should firstly run the PartA then run PartB.

2)In the PartA:
	a)Show a 18*18 grid map with '.' and obstacles with '|' and '--'.
	b)Input the start cell's coordinate and the goal cell's coordinate .
		<e.g> start cell:
			  1 1
			  goal cell:
			  5 5
		Use ' '(space) to seperate x coordinate and y coordinate.
	c)If you enter the block cell as the start cell or the goal cell, you will need to run the program again.
	d)The output will show the map of the shortest path using the path sigh '*',
		each cell of the path,
		the length of the path and
		the total number of the cells on the frontier.

3)In the PartB:
	a)Show a new 18*18 grid map with '.' , obstacles with '|' and '--' and A,B,C,D landmarks.
	b)Input the start cell's coordinate and the goal cell's coordinate .
		<e.g> start cell:
			  1 1
			  goal cell:
			  5 5
		Use ' '(space) to seperate x coordinate and y coordinate.
	c)If you enter the block cell as the start cell or the goal cell, you will need to run the program again.
		And you should repeat the steps in PartA.
	d)i/   The output will show the map of the more efficient path, if the path goes through the landmark, the sign of the 
	       landmark will be covered by the path sigh '*'.
	  ii/  Show each cell of the path, the length of the path.
	  iii/ If the more efficient path is not the shortest path, the output will show the number of cells on the frontier 
	       from start cell to the nearest landmark and the number of cells on the frontier from the goal cell to the nearest landmark. 
	  iv/  And it will also show the number of the whole path cells on the frontier from the goal cell to the goal cell.
		
