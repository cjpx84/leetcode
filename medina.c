#include <stdio.h>
#include <stdlib.h>

int findkth(int* nums1, int m, int* nums2, int n, int k)
{
    int i = 0;
    int j = 0;
    
    if (m > n)
        return findkth(nums2, n, nums1, m, k);
    if (m == 0)
        return nums2[k-1];
    if (k == 1)
        return (nums1[0] < nums2[0]) ? nums1[0] : nums2[0];
    
    i = (k/2 < m) ? k/2 : m;
    j = k - i;
    
    if(nums1[i - 1] < nums2[j - 1])
        return findkth(nums1 + i , m-i, nums2, n, k - i);
    else if (nums1[i - 1] > nums2[j - 1])
        return findkth(nums1, m, nums2 + j, n-j, k - j);
    else
        return nums1[i-1];    
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int total = nums1Size + nums2Size;
    if (total & 0x1) {
        return (double)findkth(nums1, nums1Size, nums2, nums2Size, total/2 +1);
        return k1;
    } else {
        return ((double)findkth(nums1, nums1Size, nums2, nums2Size, total/2) +
        (double)findkth(nums1, nums1Size, nums2, nums2Size, total/2 +1) ) / 2;
    }

}

int main()
{
    int a[] = {1, 2};
    int b[] = {3,4};
    double m = 0.0;
    m = findMedianSortedArrays(a, 2,b, 2);
    printf("m=%f\n", m);
    
}
