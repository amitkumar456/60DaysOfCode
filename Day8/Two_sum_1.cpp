/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Two Sum
=============================================================================*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//binary search algorithm
//t.c. for search operation o(nlogn)
int binarySearch(vector<int> &nums, int start, int end, int value)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == value)
            return mid;
        else if (nums[mid] > value)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

//approach 1 brute force soltuion
//t.c. o(n^2) s.c. o(1)
vector<int> twoSum_1(vector<int> &nums, int target)
{

    vector<int> result(2, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
//approach 2 little bit optimization using sorting
//t.c. o(nlogn) s.c. o(n)
vector<int> twoSum_2(vector<int> &nums, int target)
{
    vector<int> result(2, 0);
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    for (int i = 0; i < nums.size(); i++)
    {
        int value = target - nums[i];
        int j = binarySearch(temp, 0, temp.size() - 1, value);
        if (j != -1)
        {
            result[0] = i;
            result[1] = j;
            return result;
        }
    }
    return result;
}

// approach 3 using hashing technique
// t.c. o(n) s.c. o(n)
vector<int> twoSum_3(vector<int>& nums, int target) {
     vector<int> result;
     unordered_map<int,int> hashmap;
     
     for(int i=0;i<nums.size();i++){
         int valueToFind=target-nums[i];
         if(hashmap.find(valueToFind)!=hashmap.end()){
             result.push_back(i);
             result.push_back(hashmap[nums[i]]);
         }
         else{
             hashmap[nums[i]]=i;
         }

     }
        return result;
    }

int main()
{

    vector<int> nums = {3, 2, 4};
    int n = nums.size();
    int target = 6;

    //  vector<int> v=twoSum_2(nums,target);
    //  for(auto a:v){
    //      cout<<a<<" ";
    //  }
    cout << binarySearch(nums, 0, 2, 3) << endl;

    return 0;
}
