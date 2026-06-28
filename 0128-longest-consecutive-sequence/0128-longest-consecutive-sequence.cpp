class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for(const int &num: nums){
            set.insert(num);
        }

        int longest= 0;
        for(const int &start: set){
            if(!set.contains(start-1)){
                int end= start+1;
                while(set.contains(end)){
                    end++;
                }
                longest= max(longest, end-start);
            }
        }
        return longest;
    }
};