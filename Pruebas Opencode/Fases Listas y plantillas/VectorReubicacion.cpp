#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    std::cout << "capacity inicial: " << v.capacity() << '\n';

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "size=" << v.size() << " capacity=" << v.capacity()
                  << (v.size() == v.capacity() ? "  <-- se lleno (reubicara en el proximo push)" : "")
                  << '\n';
    }
    return 0;
}