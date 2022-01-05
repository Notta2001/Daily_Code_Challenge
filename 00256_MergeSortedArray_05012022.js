var merge = function(nums1, m, nums2, n) {
    let k = m + n -1, i = m -1, j = n - 1;
    
    while(i >= 0 || j >= 0){
          if(i >= 0 && j >= 0 && nums1[i] < nums2[j]){
              nums1[k--] = nums2[j--];
            }else{
                if(i >= 0)
                nums1[k--] = nums1[i--];
                else
                 nums1[k--] = nums2[j--];
            }
          }
};