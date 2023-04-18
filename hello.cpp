#include <iostream>
#include <vector>
#include <functional>
using namespace std;

<<<<<<< HEAD
<<<<<<< HEAD
int main()
{
=======
=======
>>>>>>> 1f53a8e66cc398f0f73c0b8b6d8fb74b0eae1d81
template<typename T>
class MyIter {
public:
    typedef T value_type; //内嵌类型声明
    MyIter(T *p = 0) : m_ptr(p) {}
    T& operator*() const { return *m_ptr;}
private:
    T *m_ptr;
};

//以迭代器所指对象的类型作为返回类型
//注意typename是必须的，它告诉编译器这是一个类型
template<typename MyIter>
typename MyIter::value_type Func(MyIter iter) {
    return *iter;
}

int main(int argc, const  char *argv[]) {
    MyIter<int> iter(new int(666));
    std::cout<<Func(iter)<<std::endl;  //print=> 666
<<<<<<< HEAD
>>>>>>> 1f53a8e66cc398f0f73c0b8b6d8fb74b0eae1d81
=======
>>>>>>> 1f53a8e66cc398f0f73c0b8b6d8fb74b0eae1d81
}
