//
// Created by zhangjiayuan on 23-5-23.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

void merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = vec[i++];
    }
    while (j <= right) {
        temp[k++] = vec[j++];
    }

    for (int m = 0; m < temp.size(); m++) {
        vec[left + m] = temp[m];
    }
}

// [4,2,1,3]

void divideConquer(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        divideConquer(vec, left, mid);
        divideConquer(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

//class DivideConquer {
//    void merge(int[] array, int left, int mid, int right) {
//        int[] temp = new int[right - left + 1];
//        int i = left, j = mid + 1;
//        int k = 0;
//
//        while (i <= mid && j <= right) {
//            if (array[i] <= array[j]) {
//                temp[k++] = array[i++];
//            } else {
//                temp[k++] = array[j++];
//            }
//        }
//        while (i <= mid) {
//            temp[k++] = array[i++];
//        }
//        while (j <= right) {
//            temp[k++] = array[j++];
//        }
//
//        for (int m = 0; m < temp.length; m++) {
//            array[left + m] = temp[m];
//        }
//    }
//
//    void doSort(int[] array, int left, int right) {
//        if (left < right) {
//            int mid = (left + right) / 2;
//            doSort(array, left, mid);
//            doSort(array, mid + 1, right);
//            merge(array, left, mid, right);
//        }
//    }
//}
//

//int n;
//int c[12000],d[12000];
//
//void merge(int low,int mid,int high)
//{
//    int i=low,j=mid+1,k=low;
//    while (i<=mid && j<=high)
//    {
//        if (c[i]<c[j])
//            d[k++]=c[i++];
//        else
//            d[k++]=c[j++];
//    }
//    while (i<=mid)
//        d[k++]=c[i++];
//    while (j<=high)
//        d[k++]=c[j++];
//    for (int i=low;i<=high;i++)
//        c[i]=d[i];
//}

//void mergesort(int x,int y)
//{
//    if (x>=y) return;
//    int mid=(x+y)/2;
//    mergesort(x,mid);
//    mergesort(mid+1,y);
//    merge(x,mid,y);
//}

//75. Sort Colors
//
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//
//You must solve this problem without using the library's sort function.
//
//
//
//Example 1:
//
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
//
//Example 2:
//
//Input: nums = [2,0,1]
//Output: [0,1,2]
//
//

//void sortColors(vector<int>& nums) {
//
//}
