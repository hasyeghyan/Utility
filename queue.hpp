#ifndef Queue_HPP
#define Queue_HPP

#include <iostream>
#include <list>

template <typename T>
class Queue {
    private:
        std::list<T> ls;
    public:
        Queue() : ls() {}
        explicit Queue(const std::list<T>& cont) : ls{cont} {}
        explicit Queue(std::list<T>&& cont) : ls{std::move(cont)} {}
        Queue(const Queue& other) : ls{other.ls} {}
        Queue(Queue&& other) : ls{std::move(other.ls)} {}
        template<typename InputIt>
        Queue(InputIt first, InputIt last) : ls(first, last) {}

        ~Queue() {}

        Queue& operator=(const Queue& other);
        Queue& operator=(Queue&& other);

        T& front() { return ls.front(); }
        const T& front() const { return ls.front(); }

        T& back() { return ls.back(); }
        const T& back() const { return ls.back(); }

        bool empty() const { return ls.empty(); }
        size_t size() const { return ls.size(); }
 
        void push(const T& value ) { ls.push_back(value); }
        void push(T&& value ) { ls.push_back(std::move(value)); }

        template<typename... Args>
        void emplace(Args&&... args) { ls.emplace_back(std::forward<Args>(args)...); }

        void pop() { ls.pop_front(); }

        void swap(Queue& other) { std::swap(ls, other.ls); }


        template<typename U>
        friend bool operator==(const Queue<U>& lhs, const Queue<U>& rhs ) { return lhs.ls == rhs.ls; }
        template<typename U>
        friend bool operator!=(const Queue<U>& lhs, const Queue<U>& rhs ) { return !(lhs == rhs); }
        template<typename U>
        friend bool operator>(const Queue<U>& lhs, const Queue<U>& rhs ) { return lhs.ls > rhs.ls; }
        template<typename U>
        friend bool operator>=(const Queue<U>& lhs, const Queue<U>& rhs ) { return lhs.ls >= rhs.ls; }
        template<typename U>
        friend bool operator<(const Queue<U>& lhs, const Queue<U>& rhs ) { return lhs.ls < rhs.ls; }
        template<typename U>
        friend bool operator<=(const Queue<U>& lhs, const Queue<U>& rhs ) { return lhs.ls <= rhs.ls; }

};

template<typename U>
void swap(Queue<U>& lhs, Queue<U>& rhs) { lhs.swap(rhs); }

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        ls = other.ls;
    }

    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) {
    if (this != &other) {
        ls = std::move(other.ls);
    }

    return *this;
}

#endif