class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty())
            return false;
        map<int, int> check;
        vector<int> numbersWithoutZero;
        for (vector<int>::size_type i = 0; i < numbers.size(); ++i){
            check[numbers[i]]++;
            if ((numbers[i] != 0 && check[numbers[i]] > 1) || check[0] > 4)
                return false;
            if (numbers[i] != 0)
                numbersWithoutZero.push_back(numbers[i]);
        }
        sort(numbersWithoutZero.begin(), numbersWithoutZero.end());
        int maxNumber = numbersWithoutZero[numbersWithoutZero.size() - 1];
        int minNumber = numbersWithoutZero[0];
        if (maxNumber - minNumber < 5)
            return true;
        else
            return false;  
    }
};
