#include<iostream>
#include<string>
#include<stdexcept>
#include<DynArray.h>


using namespace std;


int main(){

    DynArray<int> box1;

    box1.insert(2);
    box1.insert(3);
    box1.insert(4);
    box1.insert(5);
    box1.insert(6);
    box1.insert(7);
    box1.insert(8);
    box1.insert(9);
    box1.insert(10);



    box1.show();
        
    box1.cut(4,6);

    box1.show();

    return 0;


};
