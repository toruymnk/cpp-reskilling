#include <iostream>

class Foo {
  int value_;

 public:
  Foo(int value);

  int Value() const;
};

Foo::Foo(int value) : value_(value) {
  std::cout << "コンストラクター呼び出し" << std::endl;
}

int Foo::Value() const { return value_; }

int main() {
  Foo foo = 42;

  if (foo.Value() == 42) {
    std::cout << "True" << std::endl;
  }
}
