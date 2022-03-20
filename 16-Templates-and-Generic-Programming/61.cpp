



#include <iostream>
#include <memory>

template <typename T, typename ... Args>
auto make_shared(Args&&... args) -> std::shared_ptr<T>
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
    auto i = make_shared<int>(10);
    return 0;
}