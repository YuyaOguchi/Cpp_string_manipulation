//
// Name: Yuya Oguchi, Student ID: W1048226, Chapter 4, Project 1
//
// #include <cstdlib>
#include <iostream>
#include "mystring.h"
using namespace std;

// strings::strings(const char str[ ] = "") {
//     allocated = 10;
//     sequence = new char[allocated];
// }
//
// strings::~strings( ){
// }

//part a
strings::strings(const char &source) {
    allocated = 30;
    current_length = 1;
    sequence = new char[allocated];
    sequence[0] = source;
}

//part b
void strings::insertion(const string& input, const int pos){
    if (current_length >= pos){
        if(pos + input.length() > allocated){
            allocated = allocated + input.length();
            char *temp = new char[allocated];
            for (int i =0; i < pos; i++){
                temp[i] = sequence[i];
            }for (int j = pos; j < pos+input.length() ;j++){
                temp[j] = input[j - pos];
                current_length ++;
            }for (int k = pos; k < pos+input.length() ;k++){
                temp[k] = sequence[k - pos];
            }
            sequence = temp;
            delete temp;
        }else{
            current_length += input.length();
            for (int i = pos+input.length(); i > pos ;i--){
                sequence[i] = sequence[i - input.length()];
            }for (int j = pos; j < pos+input.length() ;j++){
                sequence[j] = input[j - pos];
            }
        }
    }else{
        cout << "String can not be positioned at " << pos << endl;
    }
}

//part c
void strings::deletion(const int from,const int to){
    int removelength = 0;
    removelength = to - from;
    for (int i = to; i < current_length; i++){
        sequence[i - removelength] = sequence[i];
    }
    current_length -= removelength;
    for (int i = current_length; i < allocated; i++){
        sequence[i] = '\0';
    }
}

//part d
void strings::swapchar(const char &input, const int pos){
    sequence[pos] = input;
}

//part e
void strings::swapstring(const string& input, const int pos){
    for (int i = pos; i < input.length(); i++){
        if(i < allocated){
            sequence[i] = input[i - pos];
        }
    }
}
//part f
int strings::searchchar(const char &input){
    for (int i =0; i < current_length; i++){
        if (input == sequence[i]){
            return i;
        }
    }
    return -1;
}
//part g
int strings::occurence(const char &input){
    int count = 0;
    for (int i =0; i < current_length; i++){
        if (input == sequence[i]){
            count++;
        }
    }
    return count;
}
//part h
int strings::searchstr(const string& input){
    bool flag = false;
    for (int i =0; i < current_length-input.length(); i++){ // loop through string
        if (input[0] == sequence[i]){ // look for first char match
            flag = true;
            for(int j = 1; j < input.length(); j++){
                if (input[j] != sequence[i+j]){
                    flag = false;
                }
            }
            if (flag == true){
                return i;
            }
        }
    }
    return -1;
}



void strings::dump(){
    cout << "strings is " << sequence << endl;
}

int main()
{
   strings s('A');
   s.insertion("Hello world", 0);
   cout << "s" << endl;
   s.dump();

   s.deletion(0,6);
   cout << "s deleted" << endl;
   s.dump();

   s.swapchar('Z',5);
   cout << "s character swapped" << endl;
   s.dump();

   s.swapstring("Byeee",0);
   cout << "s string swapped" << endl;
   s.dump();

   cout << "s char e at index "<< s.searchchar('e') <<  endl;
   cout << "s char e occurence "<< s.occurence('e') <<  endl;
   cout << "s string yee at index "<< s.searchstr("yee") <<  endl;


   return 0;
}
