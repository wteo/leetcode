//author:wangtao
//date:2015.6.15

/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
Algorithm:
Loop for all elements in arr[] and maintain two sums incl and excl where incl = Max sum including 
the previous element and excl = Max sum excluding the previous element.

Max sum excluding the current element will be max(incl, excl) and max sum including the current element 
will be excl + current element (Note that only excl is considered because elements cannot be adjacent).

At the end of the loop return max of incl and excl.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int incl=0,excl=0;
        int tmp;
        for(int i =0 ;i<nums.size();++i){
            tmp = (incl>excl)?incl:excl;
            incl = excl+nums[i];
            excl = tmp; 
        }
        return (incl>excl)?incl:excl;
    }
};

