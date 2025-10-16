#include <iostream>
#include <string>

class Person {
  std::string name_;
  int age_;

  Person(int age);  // 3.3.2

 public:
  Person();
  Person(std::string name, int age);  // 3.3.2
  ~Person();                          // 3.2.5

  Person(const Person& other);  // 3.3.3

  void SetName(std::string name);
  void SetAge(int age);

  std::string Name() const;
  int Age() const;
};

// 3.3.2
// 共通の初期化処理を行うprivateなコンストラクター。
Person::Person(int age) : age_(age) {
  std::cout << "privateなコンストラクター呼び出し" << std::endl;
  std::cout << "...共通の初期化処理..." << std::endl;
}

// 不正な値で年齢を初期化するコンストラクター。
// name_はstd::stringのデフォルトで初期化される。
Person::Person() : Person(-1) {
  std::cout << "デフォルトコンストラクター呼び出し" << std::endl;
}

// 3.3.2
// 引数ありコンストラクター
Person::Person(std::string name, int age) : Person(age) {
  std::cout << "引数ありコンストラクター呼び出し" << std::endl;

  // メンバー関数を呼び出すことができる。
  SetName(name);
}

// 3.2.5
// Personのインスタンスを破棄するときに呼ばれるデストラクター。
// デストラクターはオーバーロードできない。
Person::~Person() { std::cout << "デストラクター呼び出し" << std::endl; }

// 3.3.3
// コピーコンストラクター
Person::Person(const Person& other) {
  std::cout << "コピーコンストラクター呼び出し" << std::endl;

  // 名前と年齢をコピー
  SetName(other.Name());
  SetAge(other.Age());
}

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

  // 3.3.2
  Person bob("bob", 40);

  std::cout << "名前: " << bob.Name() << std::endl;
  std::cout << "年齢: " << bob.Age() << std::endl;

  // 3.3.3
  Person copied_bob(bob);

  std::cout << "名前: " << copied_bob.Name() << std::endl;
  std::cout << "年齢: " << copied_bob.Age() << std::endl;
}
