// author: wangtao
// date	 : 2020.1.28

/*********************************************************************************************

Given an array nums of integers, return how many of them contain an even number of digits.

*********************************************************************************************/

class Solution {
public:
    bool _hasEvenNumber(int num){
        int n = 0;
        while(num){
            n++;
            num = num / 10;
        };
        if(n & 0x1) return false;
        return true;
    }
    
    int findNumbers(vector<int>& nums) {
        int counter = 0;
        for(auto n: nums){
            if (_hasEvenNumber(n)){
                counter += 1;
            }
        }
        return counter;
    }
    
};
