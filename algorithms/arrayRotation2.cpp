//given a rotated sorted array having unique elements, find the smallest element in the array

#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid<high && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(mid>low && arr[mid]<arr[mid-1]){
            return mid-1;
        }
        if(arr[low]>=arr[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

int findMin(vector<int> &arr){
    int pivot=findPivot(arr);
    if(pivot==-1){
        return arr[0];
    }
    return arr[pivot+1];
}

int main() {
    vector<int> arr;
    int n;
    cout<<"Enter the number of elements: ";
    cin >> n;
    cout<<"\n";
    cout<<"Enter the elements: ";
    cout<<"\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout<<"\n";
    cout << "Smallest element in the array is: "<<findMin(arr) << endl;
    return 0;
}
