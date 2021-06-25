/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        single number
=============================================================================*/

	int singleNumber(int a[], int n) {
     //xor all numbers, the left over number would be the non repeated one
     // since the equl numbers cancel out each others bits
     int num = 0;
     for (int i = 0; i < n; ++i) {
         num ^= a[i];
     }
     return num;
    }


    class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size() < 1) {
            return 0;
        }
        
        else if(nums.size() > 1) {
            
            sort(nums.begin(), nums.end());
            
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] != nums[i+1]) {
                    return nums[i];
                }
                i++;
            }
        }
        
        //else for nums.size() == 1
        return nums[0];
    }
};


    unordered_set<int> mySet;
    for(int i = 0;i < nums.size();++i){
        if(mySet.find(nums[i]) == mySet.end()) mySet.insert(nums[i]);
        else mySet.erase(nums[i]);
    }
    auto it = mySet.begin();
    return *it;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int, bool> map;

		// build a map
        for(int i = 0; i < nums.size(); i++)
			// update the value to true if key is duplicate
            map.count(nums[i]) ? map[nums[i]] = true : map[nums[i]] = false;

		// traverse a map
        for(const auto& it : map)
            if(!it.second) return it.first;

        return -1;  // no single number found
    }
};