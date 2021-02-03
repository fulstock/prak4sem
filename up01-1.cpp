class Sum
{
    long long sum = 0;
public:
    Sum (long long a, long long b) : sum(a + b) {}
    Sum (const Sum &s, long long c) : sum(s.sum + c) {}
    long long get() const {
        return this->sum;
    }
};