 // author:wangtao
 // date  :2014.10.28

/*******************************************************************************
*
*   Given two binary strings, return their sum (also a binary string).
*   For example,
*   a = "11"
*   b = "1"
*   Return "100".
*
*******************************************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        
        string rst;
        int len = a.size()<b.size()?b.size():a.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;
        
        for(int i=0;i<len;++i){
            int ai = i < a.size() ? a[i] - '0':0;
            int bi = i < b.size() ? b[i] - '0':0;
            int value = (ai + bi + carry)%2;
            carry = (ai + bi + carry)/2;
            rst.insert(rst.begin(),value + '0');
        }
        if(carry == 1) rst.insert(rst.begin(),'1');
        return rst;
    }
};
