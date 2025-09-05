/*class Solution {
    int jumpHelper(vector<int>& nums,int pos,int jumps,int size){
        if(dp[pos][jumps] != -1) return dp[pos][jumps];
        int mini = INT_MAX;
        for(int i = 1;i<nums[pos];i++){
            mini = min(mini,jumpHelper(nums,pos+i,jumps+1,size));
        }
        return dp[pos][jumps] = mini;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int,int> dp(vector<int>(n,-1));
        return jumpHelper()
    }
};
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)  return 0;

        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for(int i=0;i<nums.size();i++){
            farthest = max(farthest, i + nums[i]);

            if( i == currEnd){
                currEnd = farthest;
                jumps++;

                if(currEnd >= n-1)  break;
            }
        }

        return jumps;
    }
};
