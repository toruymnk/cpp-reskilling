#include <iostream>

class product {
  int id;

 public:
  int get_id() const;
  void set_id(int new_id);
};

int product::get_id() const { return id; }

void product::set_id(int new_id) { id = new_id; }

int main() {
  product p;
  p.set_id(42);
  std::cout << p.get_id() << std::endl;

  const product cp{};

  // error
  // cp.set_id(42);

  std::cout << cp.get_id() << std::endl;
}
