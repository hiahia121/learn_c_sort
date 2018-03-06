#include <iostream>
using namespace std;


//交换
void swap(int* array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

//冒泡排序
/*
 遍历数组，相邻的两个数进行比较，将逆序状态的两个数交换位置，这样交换结束后，使得最大的数置到数组末尾。
 平均时间复杂度为：O(n2)
 */
void bubble_sort(int* array, int size)
{
    for(int i = 0; i< size; i++)
    {
        for(int j = 1; j < size - i; j++)
        {
            if(array[j] < array[j - 1])
            {
                swap(array, j, j-1);
            }
        }
    }
}


//选择排序
/*
遍历数组，选择最小的数放在数组起始位置，再选择无序集合中最小的放入起始，周而复始，完成排序
平均时间复制度为：O(n2)
 */
void select_sort(int* array, int size)
{
    int min_index;
    for(int i = 0; i < size; i++)
    {
        min_index = i;
        for(int j = i + 1; j < size; j++)
        {
            if(array[min_index] > array[j])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            swap(array, i, min_index);
        }
    }
}


//插入排序
/*
 将数组分为两个集合，分别为排好序的集合和乱序的集合，默认数组第一个元素为排好序集合中的元素。遍历数组除了第一个元素剩下数，
 并将数往有序的集合中插入，从而完成排序。
 平均时间复杂度为：O(n2)
 */
void insert_sort(int* array, int size)
{
    for(int i = 1; i < size; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(array[j] < array[j - 1])
            {
                swap(array, j, j-1);
            }
        }
    }
}


//快速排序
/*
 1.开始选择数组中的一个基数（可以是开始第一个数，也可以是数组中间位置的数），将小于该基数的放到左侧，大于该基数的放到右侧
 2.分别对左右两侧数列，重复1的操作
 3.挖坑填数＋分治法
 */
void quick_sort(int* array, int left, int right)
{
    if(left < right)
    {
        int i = left - 1, j = right + 1;
        int mid = array[(left + right) / 2];
        while(true)
        {
            while(array[++i] < mid);
            while (array[--j] > mid);
            if(i >= j)
            {
                break;
            }
            swap(array, i, j);
        }
        quick_sort(array, left, i - 1);
        quick_sort(array, j + 1, right);
    }
}


//归并排序
/*

 */
void merge(int* array, int left, int mid, int right)
{
    int* temp = new int[right - left + 1];
    int i = left, j = mid + 1, m = 0;
    while(i <= mid && j <= right)
    {
        if(array[i] < array[j])
        {
            temp[m++] = array[i++];
        }
        else
        {
            temp[m++] = array[j++];
        }
    }
    while(i <= mid)
    {
        temp[m++] = array[i++];
    }
    while(j <= right)
    {
        temp[m++] = array[j++];
    }
    for(int n = left, m = 0; n <= right; n++, m++)
    {
        array[n] = temp[m];
    }
    delete temp;
}


void merge_sort(int* array, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}


//合并两个有序数列
//将有序数组a[]和b[]合并到c[]中,n为数组a的长度，m为数组b的长度
void merge_array(int a[], int n, int b[], int m, int c[])
{
    int i, j, k;
    i = j = k = 0;
    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while(i < n)
    {
        c[k++] = a[i++];
    }
    while(j < m)
    {
        c[k++] = b[j++];
    }
    for(int l = 0; l < k; l++)
    {
        cout << c[l] << " ";
    }
}


int main() {
    int data[] = {1, 3, 4, 5, 2, 6};
    int data_a[] = {2, 3, 4, 5, 7, 9};
    int a_size = sizeof(data_a)/sizeof(data_a[0]);
    int data_b[] = {1, 4, 7, 10};
    int b_size = sizeof(data_b)/ sizeof(data_b[0]);
    int data_size = sizeof(data)/sizeof(data[0]);
    int result[] = {};
//    bubble_sort(data, data_size);
//    select_sort(data, data_size);
//    insert_sort(data, data_size);
//    quick_sort(data, 0, data_size - 1);
    merge_sort(data, 0, 5);
    for(int i = 0; i < data_size; i++)
    {
        cout << data[i] << endl;
    }
//    merge_array(data_a, a_size, data_b, b_size, result);
    return 0;
}