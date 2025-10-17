#include <iostream>
#include <string>

class Book {
  std::string title_ = "";
  int page_ = 0;

 public:
  Book();
  explicit Book(std::string title, int page);

  void Show() const;
};

// page_はNSDMIによってデフォルト値で初期化される。
Book::Book() : title_("untitled") {}

// メンバー初期化リストで指定した値で初期化される。
Book::Book(std::string title, int page) : title_(title), page_(page) {}

void Book::Show() const {
  std::cout << title_ << ", " << page_ << " ページ" << std::endl;
}

int main() {
  Book nsdmi;  // NSDMIによってデフォルト値で初期化される。

  nsdmi.Show();

  Book old_edition{"独習C++ 第4版", 568};

  old_edition.Show();
}
