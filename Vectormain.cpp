#include <iostream>
#include "VECTOR.h"
 
 int main() {
   Vector vector;
       
    for (int i = 0; i < 100; ++i) {
        vector.push_front(i);
        std::cout << "i: " << i << ", size >: " << vector.size() << ", capacity >: " << vector.capacity() << std::endl;
    }
    for (int i = 0; i < 100; ++i) {
        std::cout << "i: " << vector[i] << std::endl;
    }
        for (int i = 0; i < 100; ++i) {
        vector.pop_back();
        std::cout << "i: " << i << ", size >: " << vector.size() << ", capacity >: " << vector.capacity() << std::endl;
    }
    return 0;
 }