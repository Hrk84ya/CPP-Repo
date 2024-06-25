#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&v,int tar,int i){
    if(i==v.size()){
        if(tar==0){
            return 1;
        }
        return 0;

    }
    int take=0;
    if(v[i]<=tar){
        take=solve(v,tar-v[i],i);
    }
    int not_take=solve(v,tar,i+1);
    return take+not_take;
    
}
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    int tar=10;
    cout<<solve(v,tar,0);
    
}