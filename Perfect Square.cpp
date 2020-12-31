#include <iostream>
using namespace std;
// Ng,James Perfect Square Problem
int main(){
int i = 1;
while (i > 0){// This is to make sure the number is positive
if ((i*i)% 2 != 0){
int f = (i*i) % 10;
(i*i) / 10; // This is to make sure the second digit is given
}
int g = ((i*i) % 10);
if ((i*i) % 2 == 0)i++; // This is to keep the number increasing
cout << i*i << " is a perfect square where the last two digits are odd. "<< endl;
cout << "There is no such thing as a perfect square where the last two digits are odd" << endl;
return 0;
}
// There is no such number that has two odd digits as their last two digits
// Otherwise the code will keep going and it will never stop
}
