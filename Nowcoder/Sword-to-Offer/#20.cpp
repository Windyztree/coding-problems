class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2)
            return;
        map<int, int> check;
        int count = 0;
        for (vector<int>::size_type i = 0; i < data.size(); ++i)
            check[data[i]]++;
        for (vector<int>::size_type i = 0; i < data.size(); ++i){
            if (check[data[i]] == 1){
                count++;
                if (count == 1)
                    *num1 = data[i];
                else if (count == 2)
                    *num2 = data[i];
            }
        }
    }
};
