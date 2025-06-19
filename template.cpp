#include <iostream>

template <typename T>
T f(T a, T b) {
    return a + b;
}

int main(){
    int i, j;
    
    std::cin >> i;
    std::cin >> j;

    std::cout << f<int>(i, j);
    std::cout << f<float>(i, j);

    return 0;
}
