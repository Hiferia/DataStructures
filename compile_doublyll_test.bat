MD bin

clang.exe -IDoublyLinkedList\include -o bin\doublyll.lib DoublyLinkedList\src\*.c -fuse-ld=llvm-lib

clang.exe -Itest\include -IDoublyLinkedList\include -o bin\doublyLL_test.exe test\src\*.c -Lbin -l doublyll