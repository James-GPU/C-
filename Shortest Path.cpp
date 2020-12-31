#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using namespace std;
//Ng James Shortest Path Problem
const int rows = 5;
const int cols = 6;
int paths(int i, int j){// This is meant for memoization
	static int memo[100] = {0};
	if((i == 0) || (j == 0))return 1;
	return paths(i,j - 1) + paths(i - 1, j);
}

int cost(int i, int j){ // i is the row, j is the column
 int weight[rows][cols]={
 {3,4,1,2,8,6},
 {6,1,8,2,7,4},
 {5,9,3,9,9,5},
 {8,4,1,3,2,6},
 {3,7,2,8,6,4}
 };

 //base case
 if(j==0) return weight[i][0];

 // recursive call
 int up = weight[i][j] + cost((i - 1)% 5,j - 1);
 int left = weight[i][j] + cost(i,j-1);
 int down = weight[i][j] + cost((i + 1)% 5,j - 1);

 // find the value of the shortest path through cell (i,j)
 int min = left;
    if (up < min)min = up;
    if (down < min)min = down;
	return min;
 }

int main(){
 int ex[rows];

 // get the shortest path out of each cell on the right
 for(int i = 0; i<rows; i++)ex[i]=cost(i,cols-1);

 // now find the smallest of them
int min = ex[0];
    for (int i = 1; i<rows; i++)if (ex[i] < min)min = ex[i];
 cout << "The length of the shortest path is " << min  << "." <<endl;
 cout << "
 return 0;
} 
