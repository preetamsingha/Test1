// `if` and `switch` Init Statements
std::vector<int> make_vec(){
	return {1,2,3,4};
}
int main(){
	auto vec = make_vec();
	if(const auto itr = std::find(vec.begin(),vec.end(),2);
		itr != vec.rend()){
			*itr=3;
		} else if(const auto front = vec.front(); front !=1) {
			vec.insert(itr,4);
		}else {
			//itr
			return front;
		}
}