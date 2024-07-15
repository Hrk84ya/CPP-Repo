#include <iostream>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(int i=0;i<n;i++){
        //for space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        //for the star
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        //for space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern8(int n){
    for(int i=0;i<n;i++){
        //for space
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        //for the star
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        //for space
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}



int main(){
    int n=5;
    // pattern1(n);
    // cout<<endl;
    // pattern2(n);
    // cout<<endl;
    // pattern3(n);
    // cout<<endl;
    // pattern4(n);
    // cout<<endl;
    // pattern5(n);
    // cout<<endl;
    // pattern6(n);
    // cout<<endl;
    // pattern7(n);
    // cout<<endl;
    //pattern8(n);
    pattern7(n);
    pattern8(n);

    return 0;
}