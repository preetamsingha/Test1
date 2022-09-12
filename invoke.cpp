
#include <iostream
#include <functional>

int do_something(const int i){
	return 5+i;
}

struct S {
int j =5;
int do_something(const int i){
	return j+i;
}
int do_something_2(const int i){
	return j*i;
}
}
int main(){
	std::cout<<std::invoke(&do_something,5)<<"\n";
	S s;
	std::cout<<s.do_something(3)<<endl;
	auto fp = &S::do_something;
	std::cout<<(s.*fp)(2)<<endl;
	int(S::*fp2)(int) =  &S::do_something;
	std::cout<<(s.*fp)(1)<<endl;
	
	//
	std::cout<<std::invoke(&S::do_something, s,10)<<"\n";
	std::cout<<std::invoke(&S::do_something_2, s,10)<<"\n";
}