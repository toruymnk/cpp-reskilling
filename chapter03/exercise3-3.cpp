#include <iostream>
#include <string>

class Book {
  std::string title_;
  std::string author_;
  int price_;

 public:
  Book(std::string title, std::string author, int price);

  std::string Title() const;
  std::string Author() const;
  int Price() const;
};

// 1.
Book::Book(std::string title, std::string author, int price)
    : title_(title), author_(author), price_(price) {}

std::string Book::Title() const { return title_; }

std::string Book::Author() const { return author_; }

int Book::Price() const { return price_; }

int main() {
  // 1.
  Book cpp("独習C++", "高橋航平", 3718);

  std::cout << "タイトル: " << cpp.Title() << std::endl;
  std::cout << "著者: " << cpp.Author() << std::endl;
  std::cout << "価格: " << cpp.Price() << " 円" << std::endl;
}
