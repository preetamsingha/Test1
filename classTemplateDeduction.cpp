// class template deduction guide
#include <iostream>
#include <functional>
using namespace std;
namespace std{
 template <typename Ret, typename ...Arg>function(Ret(*)(Arg...))
->function<Ret (Arg...)>;
 template <typename Ret,typename Class, typename ...Arg>function(Ret(Class::*)(Arg...))
->function<Class &, Arg...>;
 template <typename Ret,typename Class, typename ...Arg>function(Ret(Class::*)(Arg...)const)
->function<Ret(const Class &, Arg...)>;
}
struct MyClass{
	void member(){};
	void member2()const{};
};
void test(){};
int test2(int, char){}

int main(){
	std::function f(&test);
	std::function f2(&test2);
	f2(1,'a');
	std::function m(&MyClass::member);
	std::function m(&MyClass::member2);
}