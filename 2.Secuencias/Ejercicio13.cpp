#include<iostream>
#include<string>
#include<stdexcept>
#include<DynArray.h>


using namespace std;


int main(){

    DynArray<char> box;

    box.insert('H');
    box.insert('u');
    box.insert('g');
    box.insert('o');

    box.show();

    box.reverse_elements();

    box.show();
   
    return 0;


};
