class Solution {
public:
    int Fibonacci(int n) {
        int n1 = 0;
        int n2 = 1;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        else{
            while (n - 1 > 0){
                int temp = n1;
            	n1 = n2;
            	n2 += temp;
                n--;
            }
        }
        return n2;
    }
};
