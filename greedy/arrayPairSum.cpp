/*
 Question  Number 561: Array Partition
 Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
*/

//Solution 1 : O(n*log(n))
/*class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int sum = 0;

        for(int i=0;i<nums.size();i+=2){
            sum += nums[i];
        }

        return sum;
    }
};
*/

//Solution 2 : O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int *arr = new int[20001]();
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            arr[nums[i] + 10000]++;
        }

        bool odd = true;
        for(int i=0;i<=20000;i++){
            while(arr[i] > 0){
                if(odd){
                    sum += i - 10000;
                }
                odd = !odd;
                arr[i]--;
            }
        }

        return sum;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> array;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        array.push_back(val);
    }
    Solution sol;
    int out = sol.arrayPairSum(array);
    cout<<out;
    return 0;
}
