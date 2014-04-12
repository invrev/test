#include<iostream>
using namespace std;

void get_string_input() {
    std::cout << "Hello world" << std::endl;
    string input_str;
    getline(cin,input_str);
    cout << "Hello, " << input_str << std::endl;
}


void print_char_string(char *s) {
    while(*s != '\0') {
        cout << *s;
        s += 1; 
    }
    cout << endl;
}

void print_char_string_version_2(char s[]) {
  while (*s != '\0')  {
        cout << *s;
        s += 1; 
  }
  cout << endl;
}

int main() {
    //Gloden Rule in C/C++
    //1.Allocate
    //2.Initialize
    //3.Assign
    //*var => value in variable
    //&var => address of variable
    //pointer indirection
    const size_t s = 5;
    int A[5];
    int B[] = {1,2,3,4,5};
    int i;
    cout << "size of B =" << sizeof(B) << endl;
    for (i=0;i < s ;i++) {
        cout << "i = " << i << " B[i] = " << B[i] << endl;
    }

    //C-Based styled strings
    char *hello = new char[6];
    char another_hello[] = "hello";
    char new_hello [] = {'h','e','l','l','o','\0'};
    cout << "sizeof(another_hello)" << sizeof(another_hello) 
        << "\tsizeof(new_hello) = " << sizeof(new_hello) << endl ;
    i = 0;
    while(new_hello[i] != '\0') {
        hello[i] = new_hello[i];
        i += 1;
    }
    print_char_string(new_hello);
    print_char_string_version_2(hello);

    return 0;
}
