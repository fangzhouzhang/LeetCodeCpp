//
// Created by Fangzhou Zhang on 2020/5/2.
//
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(), false);
        int max_candy = INT_MIN;
        for (int &c : candies) {
            max_candy = max(max_candy, c);
        }
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max_candy) res[i] = true;
        }
        return res;
    }
};
