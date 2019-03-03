template <class T>
typename T::value_type process (const T & container)
{
    typename T::value_type sum = typename T::value_type();
    int i = 0;
    for (typename T::const_reverse_iterator it = container.rbegin(); it != container.rend(); it++) {
        sum += *it;
        i++;
        if (i == 3) break;
    }
    return sum;
}