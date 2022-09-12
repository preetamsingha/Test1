//if constexor
template<typename T>
void print_type_info(const T&){
if constexpr(std::is_integral<T>::value){
cout<<"is intigral \n";
} else {
cout<<"is not intigral \n";
}
}
int main(){
	print_type_info(5);
	print_type_info(2.3);
}