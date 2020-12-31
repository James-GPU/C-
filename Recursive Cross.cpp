#include <iostream>
#include <cmath>
using namespace std;
//Ng James Recursive Cross Problem
bool ok(int * q, int i){
	 static int check[8][5] = {
	{-1,-1,-1,-1,-1},//This is for 0
	{-1,-1,-1,-1,0},//1
	{-1,-1,-1,0,1},//2
	{-1,-1,-1,0,2},//3
	{-1,-1,-1,1,2},//4
	{-1,1,2,3,4},//5
	{-1,-1,2,3,5},// 6
	{-1,-1,4,5,6},// 7
	};
	
 for (int k = 0; k < i; k++){
 if((q[k] == q[i]) || abs(q[i] - q[k] == (i - k)))return false; //conflict, go back and try next row 
 else if(q[i] == (check[i][k] - 1))return false; // checks if there is a previous number is adjacent
 }
 return true; //this one's ok, return and move on to next column
}
void print(int * q){ 
static int count = 0;
cout << ++count << endl;
for (int k = 0; k < 8; k++) cout << q[k];
cout << endl;
}
void move(int* q, int i){ // try place in col i
 if(i == 8) {
 print(q);
 return;
}

 for(int j = 0;j < 8;j++){ // j is the row value
 q[i] = j;
 if(ok(q,i)) // try and place a queen in row j of col i,if yes
 move(q,i + 1); // go to next column otherwise try next j
 }
 return;// no value of j worked so return;
}
int main(){
 int q[8];
 move(q,0);
}
