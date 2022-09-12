//structure binding in c++17 example
#include<iostream>
struct  S{
	int i=4;
	int j =5;
};
int &add_local(std::map<std:;string, int>vars, const std::string &new_var_name){
	//c11//auto new_var = vars.insert(std::make_pair(new_var_name,0));
	//c11//if( new_var.second == false){
	if( auto [itr,sucess] = vars.insert(std::make_pair(new_var_name,0));
	sucess ==false){
		throw std::runtime_error("variable already exist");
	} else {
		//c11//new_var.first->second;
		auto [Key, value] = *itr;
		return value;
	}
}
int main(){
	std::map<std::string , int> locals;
	int &i =add_local(loacls, "my_var");
	i=5;
	auto [1,j] =s();
	return 0;
}