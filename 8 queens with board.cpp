#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
//Ng James CS211 HW9 8 Queens with fancy board
bool ok(int q[], int col){
	for(int i = 0; i < col;i++) if(q[col] == q[i] || (abs(q[col] - q[i])) == (col - i))return false;
	return true;
	}
	void backtrack(int &col){
	--col;
	if(col == -1)exit(1);//exit is used instead of return since it is a void method
	// if the column goes beyond the board it'll end the method
	}
	void print(int q[]){
		static int count = 0;//This is to ensure that the count will not always go back to 0
		++count;
		cout << "Solution #" << count << endl;
		int i,j,k,l;
		typedef char box[5][7];
		box bb,wb,*board[8][8];
		char ws = char(219);
		char bs = char(176);
		//fill in bb = black box and wb = whitebox
		//black queen
		box bq =
		{
			ws, ws, ws, ws, ws, ws, ws,
			ws, ' ', ws, ' ', ws, ' ', ws,
			ws, ' ', ' ', ' ', ' ', ' ', ws,
			ws, ' ', ' ', ' ', ' ', ' ', ws,
			ws, ws, ws, ws, ws, ws, ws
		};// end of black queen
		box wq =
		{
			' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', bs, ' ', bs, ' ', bs, ' ',
			' ', bs, bs, bs, bs, bs, ' ',
			' ', bs, bs, bs, bs, bs, ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' '
		}; //end of white queen
		for(i = 0;i < 5;i++)
			for(j = 0;j < 7;j++){
				wb[i][j] = ' ';
				bb[i][j] = char(219);
			}
			//fill board with pointers to bb and wb in alternate positions
			for(i = 0;i < 8;i++)
				for(j = 0;j < 8;j++)
					if((i+j)% 2 == 0){
						if(q[i] == j){
							board[i][j] = &wq;
							}
						else{
							board[i][j] = &wb;
						}
					}
					else
						if(q[i] == j){
							board[i][j] =&bq;
						}
						else{
							board[i][j] = &bb;
						}
						// print the board via the pointers in array board
						// first print upper border
						cout << " ";
						for(i = 0;i < 7*8;i++)cout << '_';
						cout << endl;
						//Now print the board
						for(i = 0;i < 8;i++)
							for(k = 0; k < 5;k++){
								cout << " " << char(179);// Print left border
								for(j = 0;j < 8;j++)
									for(l = 0; l < 7; l++)
										cout << (*board[i][j])[k][l];
									cout << char(179) << endl;// At the end of line print bar and then new line
							}
							//before exiting print lower border
							cout << " ";
							for(i = 0; i < 7*8;i++)
								cout << char(196);
							cout << endl;
				}
				int main(){
				int q[8]; q[0] = 0;
				int c = 0;
				bool from_backtrack = false;
				while(true){
				while(c < 8){
				if(!from_backtrack){
		   		//Column Section
				   ++c;//increase column number
				   if(c == 8)break; //check column number break if c == 8
                   q[c] =-1; //initilize row number
				   }
				   from_backtrack = false;
                   //Row Section
                   while(q[c] < 8){
                       ++q[c];//increase row number
                       while(q[c] == 8){
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
