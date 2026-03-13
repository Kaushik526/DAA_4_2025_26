class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(int num : nums){
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if(it == temp.end())
                temp.push_back(num);
            else
                *it = num;
        }
        return temp.size();
    }
};