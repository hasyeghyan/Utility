#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>

template <typename T>
class Stack {
    private:
        std::vector<T> vec;
    public:
        Stack() : vec() {}
        explicit Stack(const std::vector<T>& cont) : vec{cont} {}
        explicit Stack(std::vector<T>&& cont) : vec{std::move(cont)} {}
        Stack(const Stack& other) : vec{other.vec} {}
        Stack(Stack&& other) : vec{std::move(other.vec)} {}
        template<typename InputIt>
        Stack(InputIt first, InputIt last) : vec(first, last) {}

        ~Stack() {}

        Stack& operator=(const Stack& other);
        Stack& operator=(Stack&& other);

        T& top() { return vec.back(); }
        const T& top() const { return vec.back(); }

        bool empty() const { return vec.empty(); }
        size_t size() const { return vec.size(); }
 
        void push(const T& value ) { vec.push_back(value); }
        void push(T&& value ) { vec.push_back(std::move(value)); }

        template<typename... Args>
        void emplace(Args&&... args) { vec.emplace_back(std::forward<Args>(args)...); }

        void pop() { vec.pop_back(); }

        void swap(Stack& other) { std::swap(vec, other.vec); }


        template<typename U>
        friend bool operator==(const Stack<U>& lhs, const Stack<U>& rhs ) { return lhs.vec == rhs.vec; }
        template<typename U>
        friend bool operator!=(const Stack<U>& lhs, const Stack<U>& rhs ) { return !(lhs == rhs); }
        template<typename U>
        friend bool operator>(const Stack<U>& lhs, const Stack<U>& rhs ) { return lhs.vec > rhs.vec; }
        template<typename U>
        friend bool operator>=(const Stack<U>& lhs, const Stack<U>& rhs ) { return lhs.vec >= rhs.vec; }
        template<typename U>
        friend bool operator<(const Stack<U>& lhs, const Stack<U>& rhs ) { return lhs.vec < rhs.vec; }
        template<typename U>
        friend bool operator<=(const Stack<U>& lhs, const Stack<U>& rhs ) { return lhs.vec <= rhs.vec; }

};

template<typename U>
void swap(Stack<U>& lhs, Stack<U>& rhs) { lhs.swap(rhs); }

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        vec = other.vec;
    }

    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) {
    if (this != &other) {
        vec = std::move(other.vec);
    }

    return *this;
}

#endif