class Solution {
public:
    void Insert(int num)
    {
        dataFlow.push_back(num);
    }

    double GetMedian()
    { 
    	sort(dataFlow.begin(), dataFlow.end());
        vector<int>::size_type n = dataFlow.size();
        if (n % 2 == 0)
            return ((dataFlow[n / 2 - 1] + dataFlow[n / 2]) / 2.0);
        else
            return dataFlow[n / 2];
    }

private:
    vector<int> dataFlow;
    
};
