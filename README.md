# Comparing Algorithms

This is the 2nd Milestone of the course "Advanced Programming 1"  
In this milestone we will test the following search algorithms:
 
* A* 
* Best-first Search
* BFS
* DFS

We will receive a specific problem - a matrix that includes a starting &ending cell, run the algorithms and decide which algorithm will return the shortest solution of the matrix.
We will keep the SOLID principals and use Design patterns.
Later we will combine this milestone with the first milestone to improve the flight simulator's routes and etc with the comparing algorithms.

## Servers

We implemented two kinds of servers:
1. Serial Server - can accept 10 clients but handles each client at a time.
2. Parallel Server - can accept 10 clients and handles all the clients at once.  

The Servers use TCP protocol, receives port via argv[1], if no port sent - the default port is 5600.

## Cache

Each solution is saved for an unique matrix, so that next time when a client sends the same matrix the solution is already saved in the cache. 
## Compiling
Run the following command in Linux terminal:

```g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread```

Run the server with the following command in Linux terminal:
``` ./a.out *insert port number*```




## Matrix
The matrix as we mentioned above has a starting&ending point, "-1" represents a wall, therefor it can not be passed and a route isn't valid through "-1". You can go only up\down\left\right. 
The client sends the matrix via text file seperated by "\n" , afterwards a line with the starting coordinates, a line with the ending coordinates and finally "end".

 For example:

 
``` 
6,1,9,17,9,0,20,13,12,7,17,11,5,4,9,18,15,10,-1,6
17,17,2,10,9,20,1,3,6,14,10,6,-1,12,3,4,10,16,16,11
8,8,5,11,0,19,15,0,7,5,19,6,1,4,16,3,5,10,20,15
4,15,11,20,17,11,-1,10,4,6,12,6,5,6,5,6,2,7,10,4
3,17,6,-1,12,-1,12,11,13,11,0,5,6,9,0,16,20,3,2,15
1,13,11,5,18,19,16,19,6,16,15,13,3,10,0,9,10,13,8,2
19,9,4,7,10,13,18,20,5,6,9,5,4,7,19,-1,2,18,20,3
5,8,13,16,3,14,8,11,18,16,8,12,1,-1,9,12,6,17,6,5
4,1,15,0,14,19,17,15,11,9,20,4,19,13,14,1,2,17,12,13
10,12,15,10,19,6,4,20,17,10,10,13,20,20,4,14,20,-1,4,11
11,17,14,8,2,20,14,6,0,6,18,14,12,18,9,5,9,10,19,15
15,8,17,11,1,-1,14,16,1,5,20,20,11,6,6,10,10,7,5,7
18,0,9,1,18,6,16,11,7,19,1,0,10,7,1,3,8,8,9,20
20,4,14,12,0,0,8,5,2,9,16,18,7,10,-1,1,14,4,13,10
13,8,17,10,17,14,3,7,9,0,-1,14,16,9,5,4,15,6,13,17
11,0,5,8,-1,12,16,5,0,1,20,-1,3,16,2,10,13,14,7,3
18,6,12,18,17,10,1,10,9,20,4,2,-1,20,18,20,8,10,15,10
1,7,8,11,13,12,9,3,5,17,11,13,5,2,9,7,10,11,6,1
13,20,18,11,20,9,14,-1,15,13,3,6,11,16,18,2,11,3,15,5
12,10,19,18,20,6,12,5,6,0,13,20,1,4,15,5,3,1,15,15
0,0
19,19
end
```
## Authors
Yam Ben-Hamo - Bar-Ilan Universty

Iris Gorelek - Bar-Ilan University

link to github: https://github.com/bhyamy/AP_project_2
