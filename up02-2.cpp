#include <cmath>
#include <string>
#include <cstring>

namespace numbers
{
    class complex_stack {
        complex *_stack;
        size_t _size;
    public:
        complex_stack () : _stack(nullptr), _size(0) {}
        complex_stack (size_t size) : _stack(nullptr), _size(size) {
            _stack = new complex[_size];
        }
        complex_stack (const complex_stack& other) : _stack(nullptr), _size(other.size()) {
            _stack = new complex[_size];
            for (int i = 0; i < static_cast<int>(_size); i++) {
                _stack[i] = other._stack[i];
            }
        }
        size_t size() const {
            return _size;
        }
        complex operator[] (int index) const {
            return _stack[index];
        }
        complex_stack operator<< (complex elem) const {
            complex_stack nst(size() + 1);
            for (int i = 0; i < static_cast<int>(nst.size() - 1); i++) {
                nst._stack[i] = _stack[i];
            }
            nst._stack[nst.size() - 1] = elem;
            return nst;
        }
        complex operator+ () const {
            return _stack[size() - 1];
        }
        complex_stack operator~ () const {
            complex_stack nst(size() - 1);
            for (int i = 0; i < static_cast<int>(nst.size()); i++) {
                nst._stack[i] = _stack[i];
            }
            return nst;
        }
        void swap(complex_stack &st1, complex_stack &st2) noexcept {
            std::swap(st1._size, st2._size);
            std::swap(st1._stack, st2._stack);
        }
        const complex_stack& operator=(complex_stack other) {
            swap(other, *this);
            return *this;
        }
        ~complex_stack() {
            delete [] _stack;
        }
    };
};