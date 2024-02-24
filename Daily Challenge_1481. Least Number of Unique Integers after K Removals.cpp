#include <unordered_map>
#include <vector>
#include <heap>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        //credit to votrubac, TC O(n + i*logm), SC O(m)
    unordered_map<int, int> counts;
    vector<int> heap;
    for (auto n : arr)
        ++counts[n];
    for (auto &p: counts)
        heap.push_back(p.second);
    make_heap(begin(heap), end(heap), greater<int>());
    while (k > 0) {
        k -= heap.front();
        pop_heap(begin(heap), end(heap), greater<int>()); 
        if (k >= 0)
            heap.pop_back();
    }
    return heap.size();
}
};