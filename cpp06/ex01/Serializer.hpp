#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>

typedef struct Data {
  std::string name;
  unsigned int age;
} Data;

class Serializer {
private:
  Serializer();
  ~Serializer();

  Serializer(const Serializer &src);

  Serializer &operator=(const Serializer &rhs);

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
