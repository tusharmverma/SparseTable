#include <iostream>
class SparseTable
{
    int data;
    Node* left;
    Node* right;
    struct Node* next;
};


template < typename T, typename Comp >
void sparse_table< T, Comp >::build_table() {
    if (!data.size()) {
        throw std::invalid_argument("Empty set is passet as a parameter.");
    }
    table.resize(1);
    table[0].resize(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        table[0][i] = i;
    }
    unsigned pow = 1;
    const unsigned max_pow = mlog(data.size());
    table.resize(max_pow + 1);
    const Comp cmp;
    for (; pow <= max_pow; ++pow) {
        const size_t cur_step_len = static_cast< size_t >(1) << pow,
        prev_step_len = static_cast< size_t >(1) << (pow - 1);
        table[pow].resize(data.size() - cur_step_len + 1);
        for (int i = 0; i <= data.size() - cur_step_len; ++i) {
            table[pow][i] = cmp(data[table[pow - 1][i]], data[table[pow - 1][i + prev_step_len]]) ?
            table[pow - 1][i] : table[pow - 1][i + prev_step_len];
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
