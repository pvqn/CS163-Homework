#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else
			if (nums[mid] < target)
				left = mid + 1;
			else right = mid - 1;
	}
	return -1;
}
int searchInsert(vector<int>& nums, int target)
{
	int index = search(nums, target);
	if (index == -1)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > target)
			{
				return i;
			}
		}
		return nums.size() ;
	}
	else return index;
}
int main()
{
	vector<int> nums = {1,3,5,6};
	cout << searchInsert(nums, 5);
	return 0;
}