#include <iostream>

class heavy_class {
  int value_;

  mutable int cache_;
  mutable bool cache_valid_;

 public:
  int generate() const;

  void set(int value);
  int get() const;
};

int heavy_class::generate() const {
  std::cout << "とても重いデータ生成関数" << std::endl;
  return value_;
}

void heavy_class::set(int value) {
  cache_valid_ = false;
  value_ = value;
}

int heavy_class::get() const {
  if (cache_valid_) {
    return cache_;
  }

  cache_ = generate();
  cache_valid_ = true;

  return cache_;
}

int main() {
  heavy_class heavy_object;

  heavy_object.set(100);

  std::cout << heavy_object.get() << std::endl;

  // キャッシュを返す。
  std::cout << heavy_object.get() << std::endl;

  heavy_object.set(200);

  std::cout << heavy_object.get() << std::endl;

  // キャッシュを返す。
  std::cout << heavy_object.get() << std::endl;
}
