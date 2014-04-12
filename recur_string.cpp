#include<iostream>
#include<string>
using namespace std;


void print_path(string path,int k) {
    int i;
    for (i=0;i<k;i++) {
        cout << path[i] ;
    }
    cout << endl;
}

void recur_string(string path,string name,int k,int solution_size,int start) {

    if ( k == solution_size) {
        print_path(path,k);
    }else {
        k = k + 1;
        int i;
        for (i = k;i<solution_size;i++) {
            path[k] = name[i];
            //cout << "path[" << k << "] = "<< path[k] << "name[" << i<< "] = " << name[i] << endl;
            recur_string (path,name,k,solution_size,start);
        }
        //start += 1;
    }
}


int main () {
    string name = "LIFE";    
    string path = "XXXX";
    recur_string(path,name,-1,4,0);
}
