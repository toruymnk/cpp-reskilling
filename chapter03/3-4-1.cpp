#include <iostream>

class Foo {
 public:
  int answer_ = 42;        // Non Static Data Member Initializer (NSDMI)
  float pi_{3.14159565f};  // NSDMI
};

int main() {
  Foo foo;  // NSDMIによってデフォルト値で初期化される。

  std::cout << "foo.answer_: " << foo.answer_ << std::endl;
  std::cout << "foo.pi_: " << foo.pi_ << std::endl;
}
