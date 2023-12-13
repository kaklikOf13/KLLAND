#include "KLLC/utils.hpp"
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstring>
namespace kllc{
    std::stringstream ss;
    std::string BytesToHex(byte* bytes,size_t bytes_size){
        ss.clear();
        ss<<std::hex<<std::setfill('0');
        for(size_t i=0;i<bytes_size; i++){
            ss<<std::setw(2)<<static_cast<int>(bytes[i]);
        }
        return ss.str();
    };
    byte* readFile(std::string path, size_t& size) {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            size = 0;
            return nullptr;
        }
        file.seekg(0, std::ios::end);
        size = static_cast<size_t>(file.tellg());
        file.seekg(0, std::ios::beg);
        byte* buffer = new byte[size];
        file.read(reinterpret_cast<char*>(buffer), size);

        file.close();

        return buffer;
    }
    bool temPrefixo(kllc::byte* buffer, std::size_t tamanho, const char* prefixo) {
        if (tamanho < strlen(prefixo)) {
            return false;
        }
        return strncmp(reinterpret_cast<const char*>(buffer), prefixo, strlen(prefixo)) == 0;
    }

}