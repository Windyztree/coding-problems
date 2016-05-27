/*可以用位运算实现。
异或运算满足交换律、结合律，因此如果将所有数异或，最后的结果肯定是两个只出现一次的数的异或。
根据异或的结果中1所在的最低位，将所有数分成两类，各含一个只出现一次的数和若干成对出现的数。
分别将这两类的所有数异或，得到的结果就是那两个只出现一次的数。*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2)
            return;
        int size = data.size();
        int temp = data[0];
        for (int i = 1; i < size; ++i)
            temp ^= data[i];
        if (temp == 0)
            return;
        int index = 0;
        while ((temp & 1) == 0){
            temp = temp >> 1;
            ++index;
        }
        *num1 = *num2 = 0;
        for (int i = 0; i < size; ++i){
            if (IsBit(data[i], index))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
 
    bool IsBit(int num, int index)
    {
        num = num >> index;
        return (num & 1);
    }
};
