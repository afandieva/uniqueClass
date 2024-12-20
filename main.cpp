#include <iostream>
#include <memory>
template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node>next;
    };
    std::unique_ptr<Node> head;
public:
    void Pushfront(const T& elem) {
        head = std::make_unique<Node> (elem,std::move(head));
    }
    void Popfront() {
        head = std::move(head -> next);
    }
    const T& Front() const {
        return head -> data;
    }
    bool Empty() const {
        return head == nullptr;
    }
    ~ForwardList() {
        while(!Empty()) {
            Popfront();
        }
    }
};
int main() {
}
