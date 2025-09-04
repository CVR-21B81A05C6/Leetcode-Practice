/*
 You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
 Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(i<flowerbed.size()){
            if(flowerbed[i] == 1){
                i += 2;
            }
            else{
                bool leftEmpty = ((i==0) || flowerbed[i-1] == 0);
                bool rightEmpty = ((i==flowerbed.size()-1) || flowerbed[i+1] == 0);
                if(leftEmpty && rightEmpty){
                    flowerbed[i] = 1;
                    n--;
                    i+=2;
                }
                else    i+=1;
            }
        }
        return n<=0;
    }
};

int main(){
    int n,numOfFlowers;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }

    cin>>numOfFlowers;

    Solution sol;
    bool ans = sol.canPlaceFlowers(arr,numOfFlowers);
    cout<<"Can place given flowers?: "<<ans;
    return 0;
}
