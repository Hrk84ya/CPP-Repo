//given a rotated sorted array having unique elements, find the target element in the array

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

int binarySearch(vector<int> &arr, int low, int high, int target){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

int search(vector<int> &arr, int target){
    int pivot=findPivot(arr);
    if(pivot==-1){
        return binarySearch(arr, 0, arr.size()-1, target);
    }
    if(arr[pivot]==target){
        return pivot;
    }
    if(arr[0]<=target){
        return binarySearch(arr, 0, pivot-1, target);
    }
    return binarySearch(arr, pivot+1, arr.size()-1, target);
}

int main(){
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    int target;
    cin>>target;
    cout<<search(arr, target)<<endl;
    return 0;
}

