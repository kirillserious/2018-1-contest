#include <functional>

template <typename Iterator, typename Comparator = std::less<typename Iterator::value_type>>
void
selection_sort (Iterator start, Iterator finish, Comparator comp = std::less<typename Iterator::value_type>())
{
    for (Iterator i = start; i != finish; i++) {

        auto max   = *i;
        auto max_i =  i;
        for (Iterator j = i; j != finish; j++) {
            if (comp(*j, max)) {
                max = *j;
                max_i = j;
            }
        }
        max = *i;
        *i = *max_i;
        *max_i = max;
    }
}