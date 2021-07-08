//parsing string infix nomor 1
/*
Sample input 0 : 12*5+7-(23+2)/5-4 	=> 12 * 5 + 7 - ( 23 + 2 ) / 5 - 4
Sample input 1 : 2+-(4 + 6)			=> 2 + -1 * ( 4 + 6 )
Sample input 2 : 7+18-5*7			=> 7 + 18 - 5 * 7
Sample input 3 : 20 +2-4*3+(17-5)/2	=> 20 + 2 - 4 * 3 + ( 17 - 5 ) / 2
Sample input 4 : 18+-5*(12- 9)		=> 18 + -1 * 5 * ( 12 - 9 )
Sample input 5 : -9 +(20/5-4)		=> -9 + ( 20 / 5 - 4 )
Sample input 6 : 7+18-5*7			=> 7 + 18 - 5 * 7
Sample input 7 : -(7/8) - 1/8		=> -1 * ( 7 / 8 ) - 1 / 8
Sample input 8 : -49 - 17%5 * 2		=> -49 - 17 % 5 * 2
*/ 
/*

#include <vector>
#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
    string eval; getline(cin,eval);
    vector<char> data;
    long unsigned int i;
    
    for(i=0; i<eval.length(); i++){
        if(eval[i] == ' ')
            continue;
        else if(isdigit(eval[i])){ 
            while(i<eval.length() && isdigit(eval[i])){
                data.push_back(eval[i]);
                i++;
            }
            i--;
        }
        else if(eval[i] == '-'){
            data.push_back(eval[i]);
            if(i==0){
                if(isdigit(eval[i+1])){
                    i++;
                    while(i<eval.length() && isdigit(eval[i])){
                        data.push_back(eval[i]);
                        i++;
                    }
                    i--;
                } else {
                    data.push_back('1');
                    data.push_back(' ');
                    data.push_back('*');
                }
            } else {
                if(!isdigit(eval[i-1]) && eval[i+1] != ' '){
                    data.push_back('1');
                    data.push_back(' ');
                    data.push_back('*');
                } 
            }
        } else
            data.push_back(eval[i]);
        data.push_back(' ');
    }
    for(auto j:data)
        cout << j;
    return 0;
}
