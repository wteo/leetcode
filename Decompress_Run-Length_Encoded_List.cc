// author: wangtao
// date	 : 2020.1.28

/*********************************************************************************************

We are given a list nums of integers representing a list compressed with run-length encoding.

Consider each adjacent pair of elements [a, b] = [nums[2*i], nums[2*i+1]] (with i >= 0).  
For each such pair, there are a elements with value b in the decompressed list.

Return the decompressed list.

*********************************************************************************************/


class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
       vector<int> r;
        for (int i = 0; i < nums.size(); i+=2){
            int a = nums[i];
            int b = nums[i+1];
            for (int j = 0; j < a; j++){
                r.push_back(b);
            }
        }
        return r;
    }
};
