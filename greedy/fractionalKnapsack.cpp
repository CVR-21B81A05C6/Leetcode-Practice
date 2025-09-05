/* Problem Statement:
 You are given n items, where the i-th item has a value of value[i] and a weight of weight[i]. You are also given a knapsack with a maximum w*eight capacity W.

 Unlike the 0/1 Knapsack problem, you can take fractions of items rather than having to take the whole item or none at all.

 Your goal is to maximize the total value you can put in the knapsack.

 Return the maximum total value that can be put in the knapsack. You may assume that you can take any fraction of an item (i.e., from 0 to 1).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,maxWeight;
    cin>>n>>maxWeight;

    vector<int> values(n,0);
    vector<int> weights(n,0);

    vector<pair<int,int>> items(n);

    for(int i=0;i<n;i++){
        cout<<"Enter the value and corresponding weight: ";
        cin>>values[i];
        cin>>weights[i];
    }


    for(int i=0;i<n;++i){
        items[i] = {values[i],weights[i]};
    }

    sort(items.begin(),items.end(), [](const pair<int,int>& x, const pair<int,int>& y){
        double r1 = (double)x.first/x.second;
        double r2 = (double)y.first/y.second;
        return r1>r2;
    });


    int i=0,weight=0;
    double maxValue = 0;

    while(weight+items[i].second <=maxWeight && i<n){
        weight += items[i].second;
        maxValue += items[i].first;
        i++;
    }

    if(weight < maxWeight && i < items.size()){
        maxValue += (maxWeight - weight) * items[i].first / items[i].second;
    }

    cout<<maxValue;
    return 0;
}
