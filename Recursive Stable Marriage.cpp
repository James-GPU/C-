#include <iostream>
#include <cmath>
using namespace std;
//Ng James Recursive Stable Marriage
bool ok(int * q, int i){
	int mp[3][3] = {{0,2,1},{0,2,1},{1,2,0}};
	int wp[3][3] ={{2,1,0},{0,1,2},{2,0,1}};
	int nm = i;//new man
	int nw = q[i];// new woman
	for(int j = 0; j < i;j++){
	int tm = j; //This man
	int tw = q[j];//This woman
	if(tw == nw)return false;
	if((mp[tm][nw]) < (mp[tm][tw]) &&(wp[nw][tm]) < (wp[nw][nm])) return false; 
	//if the pair is larger than the next pair returns false
	if((mp[nm][tw]) < (mp[nm][nw]) && (wp[tw][nm]) < (wp[tw][tm])) return false; 
	}
	return true;
}
void print(int * q){ 
static int count = 0;
 cout << "Solution #" << ++count << ":\nMan\tWoman\n";
 for (int k = 0; k < 3; k++)cout << k << "\t" << q[k] << "\n";//prints the number
 cout << "\n";
}
void move(int* q, int i) // try place in col i
{
 if(i==3)
 {
 print(q);
 return;
 }

 for(int j = 0;j < 3;j++) // j is the row value
 { q[i]=j;
 if(ok(q,i)) // try and place a queen in row j of col i,if yes
 move(q,i+1); // go to next column otherwise try next j
 }

return;// no value of j worked so return;
}
int main()
{
 int q[3];
 move(q,0);
} 
