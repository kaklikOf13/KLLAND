[ -d "dist" ] && rm -rf "dist"
mkdir "dist"
mkdir "dist/linux"
mkdir "dist/linux/bin"
mkdir "dist/linux/o"
mkdir "dist/linux/libs"
build_o(){
    g++ -c src/KLLC/$1.cpp -o dist/linux/o/$1.o -fPIC -I./includes
}
build_o namespace
build_o utils
build_o vm
g++ -shared -o dist/linux/libs/libkllc.so dist/linux/o/*.o
ar rcs dist/linux/libs/libkllc.a dist/linux/o/*.o
g++ src/EXE/exe.cpp dist/linux/libs/libkllc.a -I./includes -o dist/linux/bin/kllc