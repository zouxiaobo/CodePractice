#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/time.h>
#include <map>	
#include <vector>

using namespace std;


class Solution {
public:
    void DFS(const vector<int>& candidates, int target, int start)
    {
        if(target == 0)
        {
            ans.push_back(tmp);
            return;
        }

        for(int i=start; i<candidates.size()&&target>=0; i++)
        {
            tmp.push_back(candidates[i]);
            DFS(candidates,target-candidates[i],i);
            tmp.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        DFS(candidates, target, 0);

        return ans;
    }

private:
        vector<vector<int>> ans;
        vector<int> tmp;
};



int main()
{
	vector<int> vecSource = {2,3,6,7};
	int target = 7;
	vector<vector<int>> res = combinationSum(vecSource, target);

	return 0;
}