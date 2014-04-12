#include<iostream>
#include<stdlib.h>
using namespace std;

//How to return the new array for merge
//1.use new array
//2.divide the array





void merge_1(int a[],int first_half_start,int second_half_start,int end) {
    int *b = (int *) malloc (sizeof(int) * (end-first_half_start) + 1);
    int i = 0;
    if (first_half_start < end && second_half_start < end) {
        if (a[first_half_start] < a[second_half_start] ) {
            //take element from the first half
            *(b+i) = a[first_half_start];
            first_half_start++; 
        }else {
            //take the element from the second half
            *(b+i) = a[second_half_start];
            second_half_start++;
        }
        i++;
    }
    if(first_half_start <= end) {
        //copy the first part      
        *(b+i) = a[first_half_start];
        first_half_start++;
        i++;
    } else if (second_half_start <= end) {
        //copy the second part 
        *(b+i) = a[second_half_start];
        second_half_start++;
        i++;
    }

    int len = (end - first_half_start) + 1;
    int k = 0;
    for (k=0;k<len;k++) {
        cout << *(b+k) << " ";
    }
    cout << "\n in the merge step with first_half_start = " << first_half_start << " end = " << end << " second_half_start = " << second_half_start  << endl;
}

void merge_sort_1 (int a[],int start,int end) {
    if (start < end) {
        int mid =  (start + end) / 2;
        merge_sort_1 (a,start,mid);
        merge_sort_1 (a,mid+1,end);
        merge_1(a,start,mid+1,end);
    }
}



void merge_sort (int a[],int start,int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        first_half = merge_sort (a,start,mid);
        second_half = merge_sort (a,mid+1,end);
        merge(a,first_half,second_half);
    }

}


int main () {
    int a [] = {100,-20,12,2,334,3,2,12};
    int start = 0;
    int end = 7;

    //merge_sort (a,start,end);
    merge_sort (a);
    return (0);
}
