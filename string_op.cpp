#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main () {
    
   string my_str("cpp_string"); 
   cout << "cpp string = " << my_str << endl;
   string no_str("1234"); 
   cout << "len of str = " << my_str.size() << endl;
   cout << "max size of str = " << my_str.max_size() << endl;
   cout << "result string from loc 2 = " << my_str.substr(2,100) << endl;
   //int conv_no = stoi(no_str);
   //cout << "converted str = " << conv_no ;
   //if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
   //else if( __cplusplus == 199711L ) std::cout << "C++98\n" ;
   //else std::cout << "pre-standard C++\n" << __cplusplus << endl;


   vector <int> v;
   v.push_back(5);
   v.push_back(9);
   v.push_back(19);

   vector <float> v3 (5, 2.0);
   vector <float> v4(v.begin(), v.begin() + 1);

   return (0);
}
