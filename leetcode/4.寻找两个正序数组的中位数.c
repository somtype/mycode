/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int m=nums1Size,n=nums2Size;
    int temp=(m+n)/2;
    int inum=0,key;
    char *p1,*p2;
    p1=nums1;p2=nums2;
    while(inum<=temp){
        key=*p1<*p2?*(p1++):*(p2++);
        inum++;
    }
    if((n+m)%2!=0) return key;
    else{
        int key2=*p1<*p2?*p1:*p2;
        return (key+key2)/2.0;
    }
}


// @lc code=end