/*
 There are n different online courses numbered from 1 t*o n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

 You will start on the 1st day and you cannot take two or more courses simultaneously.

 Return the maximum number of courses that you can take.*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(),courses.end(),[](auto &a,auto &b){
            return a[1] < b[1];
        });
        int totalTime = 0;
        priority_queue<int> pq;

        for(int i=0;i<courses.size();i++){
            if(totalTime + courses[i][0] <= courses[i][1]){
                totalTime += courses[i][0];
                pq.push(courses[i][0]);
            }

            else if(!pq.empty() && pq.top() > courses[i][0]){
                if(pq.top() > courses[i][0]){
                    totalTime -= (pq.top() - courses[i][0]);
                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }

        return pq.size();
    }
};
