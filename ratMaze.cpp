bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
 
    return false;
}
 
/* This function solves the Maze problem using Backtracking.  It mainly uses
solveMazeUtil() to solve the problem. It returns false if no path is possible,
otherwise return true and prints the path in the form of 1s. Please note that
there may be more than one solutions, this function prints one of the feasible
solutions.*/
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
 
    printSolution(sol);
    return true;
}
 
/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }
 
    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;
 
        /* Move forward in x direction */
        if (solveMazeUtil(maze, x+1, y, sol) == true)
            return true;
 
        /* If x moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y+1, sol) == true)
            return true;
 
        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }  
 
    return false;
}
