//
// Created by zhangjiayuan on 23-5-23.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

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

//int main()
//{
//    cin >>n;
//    for (int i=1;i<=n;i++)
//        cin >>a[i];
//    mergesort(1,n);  //调用函数
//    for (int i=1;i<=n;i++)
//        cout <<a[i] <<" ";
//    return 0;
//}

class DivideConquer {
    void merge(int[] array, int left, int mid, int right) {
        int[] temp = new int[right - left + 1];
        int i = left, j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (array[i] <= array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = array[i++];
        }
        while (j <= right) {
            temp[k++] = array[j++];
        }

        for (int m = 0; m < temp.length; m++) {
            array[left + m] = temp[m];
        }
    }

    void doSort(int[] array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            doSort(array, left, mid);
            doSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
}

