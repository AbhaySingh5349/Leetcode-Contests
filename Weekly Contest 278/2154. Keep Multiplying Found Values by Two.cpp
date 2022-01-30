Question Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution {
public:
    int findFinalValue(vector<int>& a, int k) {
        set<int> s(begin(a), end(a));
        while (s.count(k)!=0) k *= 2;
        return k;
    }
};
