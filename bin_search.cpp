#include<iostream>
using namespace std;







int bin_search_rec_bound (int a[],int key,int start,int end) {
    int mid;    
    bool is_found = false;
    if(start <= end) {
        mid = (start + end) / 2; 
        //if (a[mid] == key) {
        //    is_found = true;
        //    //return mid;
        //}
        if (a[mid] < key) {
            return (bin_search_rec_bound(a,key,mid+1,end)) ;
        }
        else if (a[mid] > key) {
            return (bin_search_rec_bound(a,key,start,mid-1));
        }
    } else {
        return start;
    }

}


void bin_search_rec (int a[],int key,int start,int end) {
    int mid;    
    bool is_found = false;
    if(start <= end) {
        mid = (start + end) / 2; 
        if (a[mid] == key) {
            is_found = true;
            cout << "key found at location "  << mid << endl;
            //return true;
        }
        else if (a[mid] < key) {
            bin_search_rec(a,key,mid+1,end) ;
        }
        else if (a[mid] > key) {
            bin_search_rec(a,key,start,mid-1);
        }
    } else {
        cout << "key not found" << endl;   
    }

}


//void find_min_from_vec_rec(vector<int>&a) {
//
//
//}

int main () {
    int a[] = {1,1,2,3,4,4,4,5,6,23,23,23,89,89};
    int key = 3;  
    //cout << "searching key = " << key << endl;
    //bin_search_rec(a,key,0,5);
    //
    //cout << "searching key = 8" << endl;
    //bin_search_rec(a,8,0,8);
    //
    //cout << "searching key = 1" << endl;
    //bin_search_rec(a,1,0,1);

    //cout << "searching key = 6" << endl;
    //bin_search_rec(a,6,0,6);


    cout << "bin_search_rec_bound () " << bin_search_rec_bound(a,1,0,9)  << endl;
    cout << "bin_search_rec_bound () " << bin_search_rec_bound(a,23,0,14)  << endl;

    return 0;
}
