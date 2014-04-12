#include<iostream>
using namespace std;



int rev_str_rec(string st) {
    int len = st.size();
    if(len == 1) {
        cout << st;
        return 0;
    }else {
        cout << st[len-1];
        rev_str_rec(st.substr(0,len-1));
    }

}

void rev_str_iter(string st) {
    int len = st.size();
    int i = 0;
    string rev_str = "";
    for (i=len-1;i>=0;i--){
        rev_str += st[i];
    }
    cout << "Rev string = " << rev_str << endl;
}

int main () {
    string st = "Hello_world";
    cout << st << endl;
    //rev_str_iter (st);
    rev_str_rec (st);
    cout << endl;
    return (0);
}
