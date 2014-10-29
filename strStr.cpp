/*****************************************************************************************************************************
 Implement strStr().

 Returns a pointer to the first occurrence of needle in haystack, 
 or null if needle is not part of haystack. 

KMP:http://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

 algorithm kmp_table:
    input:
        an array of characters, W (the word to be analyzed)
        an array of integers, T (the table to be filled)
    output:
        nothing (but during operation, it populates the table)

    define variables:
        an integer, pos ← 2 (the current position we are computing in T)
        an integer, cnd ← 0 (the zero-based index in W of the next character of the current candidate substring)

    (the first few values are fixed but different from what the algorithm might suggest)
    let T[0] ← -1, T[1] ← 0

    while pos < length(W) do
        (first case: the substring continues)
        if W[pos - 1] = W[cnd] then
            let cnd ← cnd + 1, T[pos] ← cnd, pos ← pos + 1

        (second case: it doesn't, but we can fall back)
        else if cnd > 0 then
            let cnd ← T[cnd]

        (third case: we have run out of candidates.  Note cnd = 0)
        else
            let T[pos] ← 0, pos ← pos + 1


algorithm kmp_search:
    input:
        an array of characters, S (the text to be searched)
        an array of characters, W (the word sought)
    output:
        an integer (the zero-based position in S at which W is found)

    define variables:
        an integer, m ← 0 (the beginning of the current match in S)
        an integer, i ← 0 (the position of the current character in W)
        an array of integers, T (the table, computed elsewhere)

    while m + i < length(S) do
        if W[i] = S[m + i] then
            if i = length(W) - 1 then
                return m
            let i ← i + 1
        else
            if T[i] > -1 then
                let m ← m + i - T[i], i ← T[i]
            else
                let i ← 0, m ← m + 1
            
    (if we reach here, we have searched all of S unsuccessfully)
    return the length of S

*****************************************************************************************************************************/

class Solution {
public:
    char *strStr(char *haystack, char *needle){
        int pos = kmp(haystack,needle);
        if(pos == -1) return nullptr;
        return (char *)haystack + pos;
    }
    
    void kmp_table(const char *pattern,int next[ ]){
    	int len = strlen (pattern);
    	int j = -1;
    	next[0] = j;

    	for (int i = 1; i < len; ++i){
    		while(j>-1 &&  pattern[i] != pattern[j+1])
    			j = next[j];
    		if (pattern[i] == pattern[j+1])
    			j++;
    		next[i] = j;
    	} // for
    }

    int kmp(const char* text ,const char* pattern){
    	int len_t = strlen(text);
    	int len_p = strlen(pattern);
    	if(len_p == 0 && len_t == 0) return 0;
    	if(len_p == 0) return 0;
    	if(len_p > len_t) return -1;

    	int * next = (int *)malloc(sizeof(int)*len_p);
    	kmp_table(pattern,next);

    	for (int i = 0,j = -1; i < len_t; ++i){
    		while(j > -1 && pattern[j+1] != text[i])
    			j = next[j];
    		if(text[i] == pattern[j+1])
    			j++;
    		if(j == len_p-1){
    			free(next);
    			return i-j;
    		}
    	}
    	free(next);
    	return -1;
    }
};
