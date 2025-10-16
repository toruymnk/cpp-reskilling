#include <iostream>
#include <string>

class Book {
  std::string title_;
  std::string author_;
  int price_;

 public:
  Book(std::string title, std::string author, int price);

  // 2.
  Book(const Book& book);

  std::string Title() const;
  std::string Author() const;
  int Price() const;
};

// 1.
Book::Book(std::string title, std::string author, int price)
    : title_(title), author_(author), price_(price) {
  std::cout << "コンストラクター呼び出し" << std::endl;
}

// 2.
Book::Book(const Book& book)
    : title_(book.Title()), author_(book.Author()), price_(book.Price()) {
  std::cout << "コピーコンストラクター呼び出し" << std::endl;
}
std::string Book::Title() const { return title_; }

std::string Book::Author() const { return author_; }

int Book::Price() const { return price_; }

int main() {
  // 1.
  Book cpp("独習C++", "高橋航平", 3718);

  std::cout << "タイトル: " << cpp.Title() << std::endl;
  std::cout << "著者: " << cpp.Author() << std::endl;
  std::cout << "価格: " << cpp.Price() << " 円" << std::endl;

  // 2.
  Book copied_cpp(cpp);

  std::cout << "タイトル: " << copied_cpp.Title() << std::endl;
  std::cout << "著者: " << copied_cpp.Author() << std::endl;
  std::cout << "価格: " << copied_cpp.Price() << " 円" << std::endl;
}
