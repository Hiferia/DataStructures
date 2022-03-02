MD bin

clang.exe -IsrcDoublyLL -o bin\doublyll.lib srcDoublyLL\*.c -fuse-ld=llvm-lib

clang.exe -Itest -IsrcDoublyLL -o bin\doublyLL_test.exe test\*.c -Lbin -l doublyll