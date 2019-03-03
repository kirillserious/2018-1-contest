template <typename Iterator, typename Pred>
int
myfilter (Iterator start,
        Iterator finish, 
        const Pred & pred, 
        typename Iterator::value_type value = typename Iterator::value_type())
{
    int cnt = 0;
    for(;start != finish; start++) {
        if (pred(*start)) {
            *start = value;
            cnt++;
        }
    }
    return cnt;
}