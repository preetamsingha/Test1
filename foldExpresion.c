//fold expresion in c++17
#include <iostream>
using namespace std;
template<typename ...T>
auto div(T... t) {
    return (.../t); //or return (t/...);
}
 template<typename ...T>
auto sum(T... t) {
    return (t+...); 
}
 template<typename ...T>
auto avg(T... t) {
    return (t+...)/sizeof...(t); 
}

int main(){
cout<<div(1.0,2.0,3.0)<<endl;
cout<<sum(1,2,3)<<endl;
cout<<avg(1,2,3)<<endl;
}