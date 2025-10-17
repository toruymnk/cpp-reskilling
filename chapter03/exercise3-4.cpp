#include <iostream>

class Vector3D {
  float x_ = 12;  // 1.
  float y_ = 34;  // 1.
  float z_ = 56;  // 1.

 public:
  // Vector3D();

  void Show() const;
};

// Vector3D::Vector3D() : x_(0), y_(0), z_(0) {}

void Vector3D::Show() const {
  std::cout << "x_: " << x_ << ", y_: " << y_ << ", z_: " << z_ << std::endl;
}

int main() {
  Vector3D v3d;

  v3d.Show();
}
