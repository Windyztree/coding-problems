class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if (n == 0)
            return -1;
        queue<int> children;
        for (int i = 0; i < n; ++i)
            children.push(i);
        unsigned order = 0;
        while (children.size() != 1){
            int thisPop = children.front();
            order++;
           	children.pop();
            if (order % m != 0)
                children.push(thisPop);
        }
        return children.front();
    }
};
