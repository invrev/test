#include<iostream>
using namespace std;

void one_d_arr_pass (int a[],int len) {
    int i = 0;
    for (i=0;i<len;i++) {
        cout << a[i] << " ";
    }  
    cout << endl;
}

void two_d_arr_pass (int a[][10]) {

}

int main () {

    //matrices representation
    int a[] = {1,2,3,4,5};
    one_d_arr_pass(a,5);

}
