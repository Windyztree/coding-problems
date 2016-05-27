class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())
            return 0;
    	sort(numbers.begin(), numbers.end());
        int begin = numbers.size() / 2;
        int candidate = numbers[begin / 2];
        int i, j;
        i = j = begin;
        while (numbers[i] == candidate)
            i++;
        while (numbers[j] == candidate)
            j--;
        if (i - j - 1 > begin)
            return candidate;
        else
            return 0;
    }
};
