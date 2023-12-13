mkdir "dist/windows"
mkdir "dist/windows/amd64"
mkdir "dist/windows/amd64/bin"
mkdir "dist/windows/amd64/o"
mkdir "dist/windows/amd64/libs"

mkdir "dist/windows/i686"
mkdir "dist/windows/i686/bin"
mkdir "dist/windows/i686/o"
mkdir "dist/windows/i686/libs"
build_o_amd(){
    x86_64-w64-mingw32-g++ -c src/KLLC/$1.cpp -o dist/windows/amd64/o/$1.o -fPIC -I./includes
}
build_o_i686(){
    i686-w64-mingw32-g++ -c src/KLLC/$1.cpp -o dist/windows/i686/o/$1.o -fPIC -I./includes
}
build_o_amd namespace
build_o_amd utils
build_o_amd vm

build_o_i686 namespace
build_o_i686 utils
build_o_i686 vm

x86_64-w64-mingw32-g++ -shared -o dist/windows/amd64/libs/libkllc.dll dist/windows/amd64/o/*.o
i686-w64-mingw32-g++ -shared -o dist/windows/i686/libs/libkllc.dll dist/windows/i686/o/*.o

x86_64-w64-mingw32-ar rcs dist/windows/amd64/libs/libkllc.lib dist/windows/amd64/o/*.o
i686-w64-mingw32-ar rcs dist/windows/i686/libs/libkllc.lib dist/windows/i686/o/*.o

x86_64-w64-mingw32-g++ src/EXE/exe.cpp dist/windows/amd64/libs/libkllc.lib -I./includes -o dist/windows/amd64/bin/kllc.exe
i686-w64-mingw32-g++ src/EXE/exe.cpp dist/windows/i686/libs/libkllc.lib -I./includes -o dist/windows/i686/bin/kllc.exe