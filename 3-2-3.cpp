#include <iostream>
#include <string>

class person {
  std::string name_;
  int age_;

 public:
  person();
  ~person();  // 3.2.5

  void set_name(std::string name);
  void set_age(int age);

  std::string name() const;
  int age() const;
};

// 不正な値で年齢を初期化するコンストラクター。
// name_はstd::stringのデフォルトで初期化される。
person::person() : age_(-1) {
  std::cout << "コンストラクター呼び出し" << std::endl;
}

// 3.2.5
// personのインスタンスを破棄するときに呼ばれるデストラクター。
// デストラクターはオーバーロードできない。
person::~person() { std::cout << "デストラクター呼び出し" << std::endl; }

void person::set_name(std::string name) { name_ = name; }

void person::set_age(int age) { age_ = age; }

std::string person::name() const { return name_; }

int person::age() const { return age_; }

int main() {
  person alice;  // コンストラクターによる初期化が行われる。

  std::cout << "初期化直後の年齢: " << alice.age() << std::endl;
  alice.set_name("alice");
  alice.set_age(30);
  std::cout << "名前: " << alice.name() << std::endl;
  std::cout << "年齢: " << alice.age() << std::endl;
}
