#include <iostream>
#include <array>
#include <string>
using namespace std;

class Dish {
private:
string description;
public:
Dish() : description("Empty Dish") {}

Dish(string description) {
this->description = description;
}
string get_description() {
return this->description;
}
};

template <size_t MAX_SIZE>
class DishStack {
private:
array<Dish, MAX_SIZE> stack;
int top;
public:
DishStack() : top(-1) {}

void push(const Dish& dish) {
if (top >= MAX_SIZE - 1) {
cout << "The stack is full. Cannot push the dish." << endl;

return;
}
stack[++top] = dish;
}

void pop() {
if (top < 0) {
cout << "The stack is empty. Cannot pop a dish." << endl;
return;
}
top--;
}

Dish* peek() {
if (top < 0) {
cout << "The stack is empty. Nothing to peek at." << endl;
return nullptr;
}
return &stack[top];
}

int size() const {
return top + 1;
}

bool is_empty() const {
return top < 0;
}

bool is_full() const {
return top >= MAX_SIZE - 1;
}
};

int main() {
const size_t STACK_SIZE = 5;
DishStack<STACK_SIZE> stack;

stack.push(Dish("Plate 1"));
stack.push(Dish("Plate 2"));
stack.push(Dish("Plate 3"));
stack.push(Dish("Plate 4"));
stack.push(Dish("Plate 5"));
stack.push(Dish("Plate 6"));

Dish* topDish = stack.peek();
if (topDish) {
cout << "Top dish: " << topDish->get_description() << endl;
}

cout << "Current stack size: " << stack.size() << endl;

stack.pop();
topDish = stack.peek();
if (topDish) {
cout << "After popping, top dish: " << topDish->get_description() << endl;
}
cout << "Final stack size: " << stack.size() << endl;
return 0;
}