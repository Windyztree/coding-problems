class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if (n == 0)
        return 0;
        int result = n / 10;
        if (result * 10 < n)
            result++;
        int i = 1;
        while (n > maxnum(i)){
            int large = powerof(10, i + 1);
            int small = powerof(10, i);
            int left = n / large;
            result += left * small;
            if (left * large + small <= n){
            	int view;
            	if (n < left * large + 2 * small)
                	view = (n % small) + 1;
           	 	else
               	 	view = small;
            	result += view;
        	}
            i++;
        }
        return result;
    }
    
    int maxnum(int n)
	{
        int result = 0;
        if (n > 0){
            for (int i = 0; i < n; ++i)
                result += 9 * powerof(10, i);
        }
        return result;
	}
    
    int powerof(int base, int power)
    {
        int result = 1;
        for (int i = 0; i < power; ++i)
            result *= base;
        return result;
    }
};
