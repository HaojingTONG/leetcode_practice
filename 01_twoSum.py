from ast import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_map = {} # Create a dictionary to store number: index pairs
        for i, num in enumerate(nums):
            complement = target - num
            if complement in index_map:
                return [index_map[complement], i]  # Found the pair
            index_map[num] = i # Store the element of current 
        return []
    