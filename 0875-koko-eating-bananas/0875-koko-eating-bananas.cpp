class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        unsigned int left= 1, mid= 0, total= 0;
        unsigned int right= *std::max_element(piles.begin(), piles.end());
        unsigned int res= right;

        while(left<=right){
            mid= (left+right)/2;
            total= 0;
            for(auto& p:piles){
                total+= std::ceil((double)p/mid);
            }
            if(total<=h){
                res= std::min(res, mid);
                right= mid-1;
            }
            else{
                left= mid+1;
            }
        }
        return (res);
    }
};