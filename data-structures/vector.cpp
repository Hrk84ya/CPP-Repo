#include<iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> v1;
    v1.push_back(1);        //inserting elements
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    for(int i=0;i<5;i++){       //printing elements
        cout<<v1[i]<<endl;
    }

    cout<<"*****"<<endl;

    vector<int> v2(5,20); //creating 5 instances of 20
    for(int i=0;i<5;i++){
        cout<<v2[i]<<endl;
    } 

    cout<<"*****"<<endl;

    vector <int> v3(v2);  //copying vector v2 in vector v3
    for(int i=0;i<5;i++){
        cout<<v3[i]<<endl;
    }

    cout<<"*****"<<endl;

    vector<int>::reverse_iterator it=v3.rend();
    it--;                           //since the pointer points at the position after the last element, we need to bring it back to the last element
    cout<<*(it)<<" ";


    v3.erase(v3.begin()+1,v3.begin()+3);   //deleting elements from 1st index to 2nd index; the 3rd index won't be included
    //we need to give an extra index(or call) in the end section of the erase function or [start,end) i.e start included and end not included
    
    v3.insert(v3.begin()+1,2,10); //insert two 10's at index 1 and 2

    v3.clear(); //erases the complete vector

    cout<<v2.empty(); //checks whether vector is empty or not

    return 0;
}