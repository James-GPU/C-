#include <iostream>
#include <cmath>   
using namespace std;
//Ng James The N Queens
bool ok(int q[], int c){
 for(int i = 0;i < c;i++)if(q[c] == q[i] || (abs(q[c] - q[i])) == (c - i))return false;
 return true;
}
                
// This function should return the number of solutions for the given board size.
int nqueens(int n) {  
int count;
// Dynamically declare an array of size n and initialize the first element to 0.
// Reuse the code from your 1D 8 queens program without goto statement to find the solutions (you may have to make changes).
for(int i = 0;i <= n;i++){   
    int *q = new int[i];//allocates the array
    q[0] = 1;
    count = -1;   
    int c = 0;
    bool from_backtrack = false; // even though there is no function, it still works
    while(true){ //like the last homeworks we use this to loop
          while(c<i){ // loops until it is at the end of i
          		//Column Section
                if(!from_backtrack)q[c] = -1;//sets q[c] if not from backtrack
                from_backtrack = true;
                //Row Section
                while(q[c] < i){
                q[c]++;
				if(q[c] == i){
                from_backtrack = true;
                c--;
                break;
              } // end of q[c] == i
 
                if (ok(q,c) == true){
                from_backtrack = false;
                c++;
                break;
  				} // end of ok
        }//end of while q[c] < i
        if(c == -1)break; //if the column goes to negative, it will stop the loop
        }//end of c < i
        count++;
        c--;
        from_backtrack = true;
        if(c <= -1) break; //breaks if the column is negative   
		}// while true loop
		 delete[]q; // we don't need the memory anymore so we delete it
	} //end for loop
		return count;//Returns number of solutions
}//end of nqueens
int main(){
int n = 0;
cout << "How many Queens?" << endl;
cin >> n;
for (int i = 1; i <= n; ++i)
cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
return 0;
}

