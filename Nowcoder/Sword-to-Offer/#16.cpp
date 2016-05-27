class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size() || pushV.size() == 0 || popV.size() == 0)
            return false;
        int min = popV[0];
        for (vector<int>::size_type i = 1; i < popV.size(); ++i){
            if (popV[i] < popV[i - 1]){
                if ((popV[i] != min - 1) && (popV[i] != popV[i - 1] - 1))
                    return false;
            }
            if (popV[i] < min)
                min = popV[i];
        }
        sort(pushV.begin(), pushV.end());
        sort(popV.begin(), popV.end());
        for (vector<int>::size_type i = 0; i < popV.size(); ++i){
            if (pushV[i] != popV[i])
                return false;
        }
        return true;
    }
};
