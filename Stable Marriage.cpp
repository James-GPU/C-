#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
//Ng,James
//CS211 HW 11 Stable Marriage
bool ok(int q[], int col){
	int mp[3][3] = {{0,2,1},{0,2,1},{1,2,0}};
	int wp[3][3] ={{2,1,0},{0,1,2},{2,0,1}};
	int nm = col;//new man
	int nw = q[col];// new woman
	
	for(int i = 0; i < col;i++){
	int tm = i; //This man
	int tw = q[i];//This woman
	if(tw == nw)return false;
	if((mp[tm][nw]) < (mp[tm][tw]) &&(wp[nw][tm]) < (wp[nw][nm])) return false; 
	//if the pair is larger than the next pair returns false
	if((mp[nm][tw]) < (mp[nm][nw]) && (wp[tw][nm]) < (wp[tw][tm])) return false; 
	}
	return true;
}
void backtrack(int &col){
         --col;
         if (col == -1) exit(1); //exit is used instead of return since it is a void method
         // if the column goes beyond the board it'll end the method
         }


void print(int q[]){
static int solution = 0;
cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
for(int i = 0;i < 3;++i)cout << i << "\t:" << q[i] <<"\n";
cout <<"\n";
}

int main(){
int q[3];
int c = 0;
int count = 0;
q[0] = 0;

bool from_backtrack = false;
        while(true){
            while(c < 3){
                if(!from_backtrack){
                   //Column Section
                   ++c;//increase column number
                   if(c == 3)break; //check column number break if c == 8
                   q[c] =-1; //initilize row number
                   }
                   from_backtrack = false;
                 
                   //Row Section
                   while(q[c] < 3){
                       ++q[c];//increase row number
                       while(q[c] == 3){
                           backtrack(c);//check row number
                           ++q[c];
                           }
                           ok(q,c);//call ok function,break if true
                           if(ok(q,c) == true)break;
                           }
                           }
                           print(q); //print section
                           backtrack(c); //backtrack section
                           from_backtrack = true;
                           }
}

