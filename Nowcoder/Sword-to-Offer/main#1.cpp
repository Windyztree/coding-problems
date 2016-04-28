class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int doubleSum = sum * 2;
    	vector<int> candidates;
    	vector<vector<int> > result;
        if (sum == 1)
            return result;
    	for (int i = 1; i <= sqrt(doubleSum); ++i){
        	if ((doubleSum % i) == 0){
            	int another = doubleSum / i;
            	if ((i % 2 == 0) && (another % 2 != 0)){
                	if (another - 1 - 2 * (i / 2 - 1) > 0)
                    	candidates.push_back(i);
                	if (i - 2 * (another / 2) > 0)
                    	candidates.push_back(another);
            	}
            	else if ((i % 2 != 0) && (another % 2 == 0)){
                	if (another - 2 * (i / 2) > 0)
                    	candidates.push_back(i);
                	if (i - 1 - 2 * (another / 2 - 1) > 0)
                    	candidates.push_back(another);
            	}
        	}
    	}
    	sort(candidates.begin(), candidates.end());
    	for (int i = candidates.size() - 1; i >= 0; i--){
        	vector<int> oneElem;
        	int first;
        	if (candidates[i] == 1)
            	continue;
            if (candidates[i] % 2 == 0)
                first = doubleSum / candidates[i] - 1 - 2 * (candidates[i] / 2 - 1);
            else if (candidates[i] % 2 != 0)
                first = doubleSum / candidates[i] - 2 * (candidates[i] / 2);
            oneElem.push_back(first / 2);
            int count = 1;
            while (count < candidates[i]){
                first += 2;
                oneElem.push_back(first / 2);
                count++;
            }
            result.push_back(oneElem);
    	}
    	return result;
    }
};
