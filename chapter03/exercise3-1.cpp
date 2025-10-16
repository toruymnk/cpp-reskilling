#include <iostream>

class A {
  int v;

 public:
  void set(int value);
  // int get() const;         // 1. constメンバー関数にする。
  int& get();              // 2. 非const参照を返すget()
  const int& get() const;  // 2. const参照を返すget()
};

void A::set(int value) { v = value; }

// int A::get() const  // 1. constメンバー関数にする。
// {
//   return v;
// }

int& A::get()  // 2.
{
  std::cout << "非const参照を返すget()" << std::endl;
  return v;
}

const int& A::get() const  // 2.
{
  std::cout << "const参照を返すget()" << std::endl;
  return v;
}

int main() {
  A a;
  a.set(42);

  const A& cra = a;
  cra.get();  // const参照を返す。

  // 2.
  a.get();  // 非const参照を返す。

  const A ca{};
  ca.get();  // const参照を返す。
}
