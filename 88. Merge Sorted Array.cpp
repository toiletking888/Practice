class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        bool empty1 = false, empty2 = false;
        if(m == 0){
            nums1 = nums2;
        }
        while(i >= 0 || j >= 0){
            if(i < 0) empty1 = true;
            if(j < 0) empty2 = true;
            if(empty1){
                nums1[i+j+1] = nums2[j];
                j--;
            }
            else if(empty2){
                nums1[i+j+1] = nums1[i];
                i--;
            }
            else{
                if(nums2[j] > nums1[i]){
                    nums1[i+j+1] = nums2[j];
                    j--;
                }
                else if(nums2[j] < nums1[i]){
                    nums1[i+j+1] = nums1[i];
                    i--;
                }
                else{
                    nums1[i+j+1] = nums1[i];
                    i--;
                }
            }
        }
    }
};