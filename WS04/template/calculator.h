namespace calc
{
    template<typename T>
    T sum(T x, T y)
    {
        static_assert(std::is_literal_type<T>());

        return x + y;
    }
}