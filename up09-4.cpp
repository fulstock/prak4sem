#include <iostream>
#include <string>

// grammar:
// S -> aB
// B -> Sd | Ad
// A -> bC
// C -> Ac | c

void S(int, int);
void B(int, int);
void A(int);
void C(int);

void S(int n, int m)
{
    std::cout << "a";
    B(n, m);
}

void B(int n, int m)
{
    if (n > 1) {
        S(n - 1, m);
    } else {
        A(m);
    }
    std::cout << "d";
}

void A(int m)
{
    std::cout << "b";
    C(m);
}

void C(int m)
{
    if (m > 1) {
        A(m - 1);
    }
    std::cout << "c";
}

void recur(int k, int i) {
    if (i > 1) {
        recur (k, i - 1);
    }
    S (k / 2 - i, i);
    std::cout << std::endl;
}

int main()
{
    int k;
    std::cin >> k;
    if (k >= 4 && k % 2 == 0) {
        recur(k, k / 2 - 1);
    }
    return 0;
}