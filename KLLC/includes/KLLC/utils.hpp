#ifndef kllc_utils_h
#define kllc_utils_h
#include <iostream>
#include <string>
#include "types.hpp"
namespace kllc{
    std::string BytesToHex(byte* bytes,size_t bytes_size);
    byte* readFile(std::string path, size_t& size);
    bool temPrefixo(kllc::byte* buffer, std::size_t tamanho, const char* prefixo);
}
#endif