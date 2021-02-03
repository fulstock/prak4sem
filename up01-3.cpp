class Sub
{
    int sub;
public:
    Sub (int a) : sub(a) {}
    Sub (Sub a, Sub b) : sub(a.sub - b.sub) {}
    int value() const {
        return sub;
    }
};