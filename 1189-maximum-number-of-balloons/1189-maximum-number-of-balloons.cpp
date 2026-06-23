class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int counts[26] = {0}; 
        
        for (char c : text) {
            counts[c - 'a']++;
        }
        
        return min({
            counts['b' - 'a'], 
            counts['a' - 'a'], 
            counts['l' - 'a'] / 2, 
            counts['o' - 'a'] / 2, 
            counts['n' - 'a']
        });
    }
};