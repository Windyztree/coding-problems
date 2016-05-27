class Solution {
public:
    string LeftRotateString(string str, int n) {
        string result;
        queue<char> strQueue;
        for (string::size_type i = 0; i < str.size(); ++i){
            strQueue.push(str[i]);
        }
        int j = 0;
        while (j < n){
            char temp = strQueue.front();
            strQueue.pop();
            strQueue.push(temp);
            ++j;
        }
        while (!strQueue.empty()){
            result.push_back(strQueue.front());
            strQueue.pop();
        }
        return result;
    }
};
