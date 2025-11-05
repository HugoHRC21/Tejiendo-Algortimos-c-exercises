
template <typename BidirectionalIterator>
void selection_sort(BidirectionalIterator begin, BidirectionalIterator end) {
    for (auto i = begin; i != end; ++i) {
        auto min_pos = i;
        for (auto j = std::next(i); j != end; ++j) {
            if (*j < *min_pos) {
                min_pos = j;
            }
        }
        if (min_pos != i) {
            iter_swap(i, min_pos);
        }
    }
}