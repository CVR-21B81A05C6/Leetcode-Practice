#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr,int l,int mid,int r){
    vector<int> temp;
    int i = l, j = mid + 1;

    while(i<= mid && j<=r){
        if(arr[i] <= arr[j])    temp.push_back(arr[i++]);

        else    temp.push_back(arr[j++]);
    }

    while(i<= mid)  temp.push_back(arr[i++]);
    while(j<=r) temp.push_back(arr[j++]);

    for(int k = l;k<=r;k++){
        arr[k] = temp[k-l];
    }

}

void mergeSort(vector<int> &arr,int l,int r){
    if(l == r)  return;
    int mid = (l+r)/2;
    mergeSort(arr,l,mid); mergeSort(arr,mid+1,r);

    merge(arr,l,mid,r);
}

int main(){
        int n;
        cin>>n;

        vector<int> arr;
        for(int i=0;i<n;i++){
            int val; cin>>val;
            arr.push_back(val);
        }

        cout<<"Before Sorting: ";

        for(int i = 0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;


        mergeSort(arr,0,n-1);
        cout<<"After Sorting: ";

        for(int i = 0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
}
