class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_xor_y = accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>());
        int bit = x_xor_y & (-x_xor_y);
        
        int x = 0;
        for(const auto &i:nums){
            if(bit & i){
                x ^= i;
            }
        }
        return {x, x_xor_y ^ x};
    }
};