
void fun(int x){
	while(x-->0){cout<<x<<endl;}
}
//Functor
class Base{
	public:
	void operator()(int x){
		while(x-->0){cout<<x<<endl;}
	}
};
// non-static data member
class Base{
	public:
	void run(int x){
		while(x-->0){cout<<x<<endl;}
	}
};
// static data member
class Base{
	public:
	static void run(int x){
		while(x-->0){cout<<x<<endl;}
	}
};
int main(){
	//using function pointer
	std::thread t(fun,10);
	t.join();
	//using lambda expression
	std::thread t1([](int x){while(x-->0){cout<<x<<endl;}},10);
	t1.join();
	//using functor
	std::thread t2((Base()),10);
	t2.join();
	Base b;
	//non-static data member function
	std::thread t3(&Base::run,&b,10);
	t3.join();
	//Static member function
	std::thread t4(&Base::run,10);
	t4.join();
}