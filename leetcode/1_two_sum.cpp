#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::map<int,int> value_index;

        for(int i=0; i<nums.size(); i++)
        {
            value_index[nums[i]] = i;
        }        

        for(int i=0; i<nums.size()-1; i++)
        {
            int required_number = target - nums[i];

            std::cout<<"Number: "<<nums[i]<<", Required number: "<<required_number<<"\n";

            if(value_index.count(required_number) > 0)
            {
                int required_num_index = value_index[required_number];
                if(required_num_index != i)
                {
                    vector<int> vec{i,value_index[required_number]};
                    return vec;
                }
            }
        }

        vector<int> vec{0,0};
        return vec;
    }
};