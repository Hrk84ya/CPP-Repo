#include <iostream>
#include <string>
using namespace std;

int main(){
    enum Level{
        Low,
        Medium,
        High
    };
    
    Level myLevel=Medium;

    switch(myLevel){
        case Low:
            cout <<"Low level\n";
            break;
        case Medium:
            cout <<"Medium level\n";
            break;
        case High:
            cout <<"High level\n";
            break;
    }
    return 0;
}