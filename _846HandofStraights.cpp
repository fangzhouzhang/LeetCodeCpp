//
// Created by Fangzhou Zhang on 2020/2/29.
//
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> map;
        for (int i = 0; i < hand.size(); i++) {
            map[hand[i]]++;
        }
        while (map.size() > 0) {
            std::map<int, int>::iterator it = map.begin();
            int first = it->first;
            for (int i = 0; i < W; i++) {
                if (map[first + i] > 0) {
                    map[first + i]--;
                    if (map[first + i] == 0) {
                        map.erase(first + i);
                    }
                } else return false;
            }

        }
        return true;
    }
};
