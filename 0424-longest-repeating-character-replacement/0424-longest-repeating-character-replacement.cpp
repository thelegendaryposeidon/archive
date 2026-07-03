class Solution {
public:
    int characterReplacement(string s, int k) {
        int map[26]= {0};
        int left= 0;
        int right= 0;
        int maxFreq= 0;
        int longest= 0;

        while(right<s.length()){
            map[s[right]-'A']++;
            maxFreq= max(maxFreq, map[s[right]-'A']);

            if((right-left+1)-maxFreq>k){
                map[s[left]-'A']--;
                left++;
            }

            longest= max(longest, right-left+1);
            right++;
        }
        return longest++;
    }
};