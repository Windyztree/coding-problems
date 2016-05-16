class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return -1;
        map<char, int> check;
        for (int i = 0; i < str.length(); ++i)
            check[str[i]]++;
        for (int i = 0; i < str.length(); ++i){
            if (check[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
