class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i =0
        j = len(numbers)-1
        suma = numbers[i] + numbers[j]

        while suma != target:
            if target < suma:
                j -= 1
            else:
                i += 1
            suma = numbers[i] + numbers[j] 
        
        return [i+1, j+1]