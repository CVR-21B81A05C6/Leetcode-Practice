#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int> &arr,int low,int high){
    int pivot = arr[high];
    int i = low -1;

    for(int j = low; j< high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}


int quickSelect(vector<int> &arr,int low,int high,int k){
    if(low == high) return arr[low];

    int pivotIndex = partition(arr,low,high);

    if(pivotIndex == k)
        return arr[pivotIndex];
    else if(pivotIndex > k)
        return quickSelect(arr,low,pivotIndex-1,k);

    return quickSelect(arr,pivotIndex+1,high,k);

}

int main(){
    int n;  cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }

    int k;  cin>>k;

    while(k > n){
        cout<<"Enter k values less than: "<<n;
        cin>>k;
    }

    int result = quickSelect(arr,0,arr.size() - 1,k);
    cout<<"The "<<k+1<<"th Smallest Element is: "<<result<<endl;

    return 0;
}
