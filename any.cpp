//The class any describes a type-safe container for single values of any 
//copy constructible type.
#include <iostream
#include <vector>
#include <string>
#include <any>
struct S{
	S(const S &s) = default;
	S() = default;
}
int main(){
std:: vector<std::any>v{5,3.5,"hello world",S()};
std::cout<<std::any_cast<int>(v[0]);
std::cout<<v[1].type().name()<<"\n";
int *i = std::any_cast<int>(&v[0]);
*i=10;
std::cout<<std::any_cast<int>(v[0]);
};