class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        #lets do brute force for now. we will look for sth bettwer later on:
        
        new = list([])
        i =0
        j=0

        while i<len(nums1) and j <len(nums2):
            if nums2[j] < nums1[i]:
                new.append(nums2[j])
                j+=1
            else:
                new.append(nums1[i])
                i+=1

        while i<len(nums1):
            new.append(nums1[i])
            i+=1  
        while j <len(nums2):
            new.append(nums2[j])
            j+=1

        mid = len(new)//2
        if len(new)%2 == 0:
            return (new[mid]+new[mid-1])/2
        else:
            return new[mid]
            

