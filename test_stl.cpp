#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//containers
//Iterators
//Algorithm
//input
//output
//Forward
//Bidirectional
//Random access
int main () {
   
    //Vectors
    vector<int> v (3);
    v[0] = 1;
    v[1] = 10;
    v[2] = 17;
    for (int i=0;i<v.size();i++) {
        cout << v[i]  << " ";
    }
    reverse(v.begin(),v.end()); 
    cout << "\nAfter reversing " << endl;
    for (int i=0;i<v.size();i++) {
        cout << v[i]  << " ";
    }
    cout << endl;
    cout << "capacity = " << v.capacity() << endl;
    cout << "size = " << v.size() << endl;

    //String
    //In java strings are immutable while in case of c++ they are not
    string my_str("Hello world");
    cout << "the length of string = " << my_str.size() << endl;
    cout << "substr important = " << my_str.substr(2) << endl;

    //Iterator
    vector<int> :: iterator itr;
    for (itr = v.begin(); itr!= v.end(); itr++) {
        //like pointer dereferencing gives the value
        cout << (*itr) << " and the location = " << endl;
    }
    
    return (0);
}
