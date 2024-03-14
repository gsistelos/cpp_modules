#include "Serializer.hpp"
#include <iostream>

int main(void) {
  Data data = {"gguedes", 42};
  std::cout << "Data address: " << &data << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Raw: " << raw << std::endl;

  Data *ptr = Serializer::deserialize(raw);

  std::cout << "Name: " << ptr->name << std::endl;
  std::cout << "Age: " << ptr->age << std::endl;

  return 0;
}
