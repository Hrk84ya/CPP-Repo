#include <iostream>
#include <string>
using namespace std;

int uniqueElement(int arr[], int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                low=mid+2;
            }else{
                high=mid-1;
            }
        }else{
            if(arr[mid]==arr[mid-1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    
    return arr[low];
}

int main() {
    int arr[]={3,3,2,2,1,1,7,9,9,4,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<uniqueElement(arr,n)<<endl;
    return 0;
}

