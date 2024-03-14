#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *data) {
  return reinterpret_cast<uintptr_t>(data);
}

Data *Serializer::deserialize(uintptr_t address) {
  return reinterpret_cast<Data *>(address);
}
