template <class Iterator>
void
myreverse (Iterator start, Iterator finish)
{
    typename Iterator::value_type tmp;

    if (start == finish) return;


    while (true) {
        finish--;
        if (start == finish) return;
        tmp = *start;
        *start = *finish;
        *finish = tmp;
        start++;
        if (start == finish) return;
    }
}