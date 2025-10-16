#include <iostream>
#include <string>

class Person {
  std::string name_;
  int age_;

 public:
  Person();
  ~Person();  // 3.2.5

  void SetName(std::string name);
  void SetAge(int age);

  std::string Name() const;
  int Age() const;
};

// 不正な値で年齢を初期化するコンストラクター。
// name_はstd::stringのデフォルトで初期化される。
Person::Person() : age_(-1) {
  std::cout << "コンストラクター呼び出し" << std::endl;
}

// 3.2.5
// Personのインスタンスを破棄するときに呼ばれるデストラクター。
// デストラクターはオーバーロードできない。
Person::~Person() { std::cout << "デストラクター呼び出し" << std::endl; }

void Person::SetName(std::string name) { name_ = name; }

void Person::SetAge(int age) { age_ = age; }

std::string Person::Name() const { return name_; }

int Person::Age() const { return age_; }

int main() {
  Person alice;  // コンストラクターによる初期化が行われる。

  std::cout << "初期化直後の年齢: " << alice.Age() << std::endl;
  alice.SetName("alice");
  alice.SetAge(30);
  std::cout << "名前: " << alice.Name() << std::endl;
  std::cout << "年齢: " << alice.Age() << std::endl;
}
