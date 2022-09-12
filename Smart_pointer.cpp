#include <iostream>
#include <memory>
 
// Forward declare class B
class B;
 
class A{
    public:
        int a;
        std::shared_ptr<B> ptr;
        A(int value = 200) { a = value; }
        ~A() {std::cout << "Destructor for A\n"; }
};
 
class B{
    public:
        int a;
        std::weak_ptr<A> ptr;
        B(int value = 200) { a = value; }
        ~B() {std::cout << "Destructor for B\n"; }
};
 
int main() {
    std::shared_ptr<A> ptr_a = std::make_shared<A>(750);
    std::shared_ptr<B> ptr_b = std::make_shared<B>(750);
     //ptr_a.use_count();
    // Make ptr_a point to ptr_b
    ptr_a->ptr = ptr_b;
    // And make ptr_b point to ptr_a
    // Since ptr_b->ptr is a weak pointer, we don't have the problem now!
    ptr_b->ptr = ptr_a;
	// But if we want to explicitly free the raw pointer, we can use unique_ptr.reset(),shared_ptr.reset()
    std::cout << "Freeing the pointers...\n";
    ptr_a.reset();
 
    return 0;
}