
# 🧮 PART 3: STL ALGORITHMS

## 🧠 Algorithm Categories

STL mein 100+ algorithms hain, categorized by functionality:

1. **Non-modifying** (search, count, compare)
2. **Modifying** (copy, move, transform, fill)
3. **Sorting** (sort, partial_sort, nth_element)
4. **Binary Search** (lower_bound, upper_bound, binary_search)
5. **Set Operations** (union, intersection, difference)
6. **Heap Operations** (make_heap, push_heap, pop_heap)
7. **Min/Max** (min, max, minmax, min_element)
8. **Numeric** (accumulate, inner_product, partial_sum)

---

## 🔹 1. NON-MODIFYING ALGORITHMS

### **find() / find_if()**
Linear search – first occurrence

```cpp
Time Complexity: O(n)
Use case: Unsorted data mein search
Alternative: binary_search (sorted data ke liye)
```

### **count() / count_if()**
Count occurrences

```cpp
Time Complexity: O(n)
Use case: Frequency counting
Note: For map/set, use member function count() - O(log n)
```

### **all_of() / any_of() / none_of()**
Condition checking

```cpp
all_of  → All elements satisfy condition
any_of  → At least one satisfies
none_of → None satisfy
```

### **equal() / mismatch()**
Compare ranges

```cpp
equal    → Check if two ranges are equal
mismatch → Find first difference
```

---

## 🔹 2. MODIFYING ALGORITHMS

### **copy() / copy_if()**
Copy elements

```cpp
Time Complexity: O(n)
Variants: copy_backward, copy_n
```

### **transform()**
Apply function to range

```cpp
Use case: Map operation (functional programming)
Example: Square all elements, convert to uppercase
Time Complexity: O(n)
```

### **fill() / fill_n()**
Set all elements to value

```cpp
fill(v.begin(), v.end(), 0);  // All zeros
fill_n(v.begin(), 5, -1);     // First 5 to -1
```

### **replace() / replace_if()**
Replace values

```cpp
replace(v.begin(), v.end(), 10, 20);  // 10 → 20
replace_if(v.begin(), v.end(), isEven, 0);  // Even → 0
```

### **remove() / remove_if()**
**IMPORTANT:** Doesn't actually delete!

```cpp
auto newEnd = remove(v.begin(), v.end(), 5);
v.erase(newEnd, v.end());  // Actually delete

Why? Algorithms don't have container access
```

### **unique()**
Remove consecutive duplicates

```cpp
MUST sort first for all duplicates!
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

### **reverse()**
Reverse range

```cpp
Time Complexity: O(n)
In-place operation
```

### **rotate()**
Rotate elements

```cpp
rotate(v.begin(), v.begin()+3, v.end());
// [1,2,3,4,5] → [4,5,1,2,3]
```

---

## 🔹 3. SORTING ALGORITHMS

### **sort()**
**Most used algorithm!**

```cpp
Time Complexity: O(n log n) average
Algorithm: IntroSort (hybrid: QuickSort + HeapSort + InsertionSort)
Stable: No (relative order of equal elements may change)
```

**Custom Comparator:**
```cpp
sort(v.begin(), v.end());                  // Ascending
sort(v.begin(), v.end(), greater<int>());  // Descending
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;  // Custom lambda
});
```

### **stable_sort()**
```cpp
Time Complexity: O(n log n)
Preserves relative order of equal elements
Slightly slower than sort()
More memory usage
```

### **partial_sort()**
Sort only first k elements

```cpp
Time Complexity: O(n log k)
Use case: Top-k problems
partial_sort(v.begin(), v.begin()+5, v.end());
```

### **nth_element()**
Find nth smallest element (quick select)

```cpp
Time Complexity: O(n) average
Elements before nth are smaller, after are larger
Not fully sorted
Use case: Median finding, selection algorithm
```

---

## 🔹 4. BINARY SEARCH ALGORITHMS

**IMPORTANT:** Array must be sorted!

### **binary_search()**
Check if element exists

```cpp
Time Complexity: O(log n)
Returns: bool (true/false)
```

### **lower_bound()**
First element >= value

```cpp
Time Complexity: O(log n)
Returns: Iterator
Use case: Finding insertion position
```

### **upper_bound()**
First element > value

```cpp
Time Complexity: O(log n)
Returns: Iterator
```

### **equal_range()**
Range of elements equal to value

```cpp
Returns: pair of iterators (lower_bound, upper_bound)
Use case: Find all occurrences in sorted array
```

---

## 🔹 5. SET OPERATIONS (on Sorted Ranges)

### **set_union()**
Combine two sorted ranges

```cpp
Time Complexity: O(n + m)
Result: Sorted union
```

### **set_intersection()**
Common elements

```cpp
Time Complexity: O(n + m)
Result: Sorted intersection
```

### **set_difference()**
Elements in first but not in second

```cpp
Time Complexity: O(n + m)
```

### **set_symmetric_difference()**
Elements in either, but not both

```cpp
Time Complexity: O(n + m)
```

---

## 🔹 6. HEAP OPERATIONS

### **make_heap()**
Convert range to heap

```cpp
Time Complexity: O(n)
Creates max-heap by default
```

### **push_heap()**
Insert into heap

```cpp
Time Complexity: O(log n)
Element must be at end before calling
```

### **pop_heap()**
Remove max element

```cpp
Time Complexity: O(log n)
Moves max to end, must call pop_back() separately
```

### **sort_heap()**
Sort heap (destroys heap property)

```cpp
Time Complexity: O(n log n)
```

---

## 🔹 7. MIN/MAX ALGORITHMS

### **min() / max()**
```cpp
Time Complexity: O(1)
Works with 2+ arguments
```

### **min_element() / max_element()**
```cpp
Time Complexity: O(n)
Returns: Iterator to min/max element
```

### **minmax_element()**
```cpp
Time Complexity: O(n)
Returns: pair of iterators (min, max)
More efficient than calling both separately
```

---

## 🔹 8. NUMERIC ALGORITHMS (in <numeric>)

### **accumulate()**
Sum/reduce range

```cpp
Time Complexity: O(n)
accumulate(v.begin(), v.end(), 0);  // Sum
accumulate(v.begin(), v.end(), 1, multiplies<int>());  // Product
```

### **inner_product()**
Dot product of two ranges

```cpp
Time Complexity: O(n)
```

### **partial_sum()**
Running sum

```cpp
Time Complexity: O(n)
[1,2,3,4] → [1,3,6,10]
```

### **iota()**
Fill with incrementing values

```cpp
Time Complexity: O(n)
iota(v.begin(), v.end(), 0);  // [0,1,2,3,4...]
```

---

## 🔹 9. PERMUTATION ALGORITHMS

### **next_permutation()**
Next lexicographic permutation

```cpp
Time Complexity: O(n)
Returns: false when last permutation reached
Use case: Generate all permutations
```

### **prev_permutation()**
Previous permutation

```cpp
Time Complexity: O(n)
```

---

## ⚠️ Common Confusions & Pitfalls

### **1. remove() Doesn't Actually Remove!**
```cpp
// ❌ Wrong
remove(v.begin(), v.end(), 5);

// ✅ Correct
auto newEnd = remove(v.begin(), v.end(), 5);
v.erase(newEnd, v.end());
```

### **2. end() is Not the Last Element**
```cpp
v.end()      // Past-the-last (sentinel)
v.end() - 1  // Actual last element
```

### **3. [] vs at() for map**
```cpp
map[key]     // Creates entry if not exists
map.at(key)  // Throws exception if not exists
```

### **4. Binary Search Requires Sorted Data**
```cpp
// ❌ Wrong - unsorted
binary_search(v.begin(), v.end(), 5);

// ✅ Correct
sort(v.begin(), v.end());
binary_search(v.begin(), v.end(), 5);
```

### **5. unique() Needs Sorting for All Duplicates**
```cpp
// ❌ Only removes consecutive duplicates
unique(v.begin(), v.end());

// ✅ Removes all duplicates
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

### **6. Iterator Invalidation**
```cpp
// ❌ Dangerous
for(auto it = v.begin(); it != v.end(); ++it) {
    if(*it == 5) v.erase(it);  // Iterator invalid after erase!
}

// ✅ Correct
for(auto it = v.begin(); it != v.end(); ) {
    if(*it == 5) it = v.erase(it);
    else ++it;
}
```

### **7. Algorithm Header Confusion**
```cpp
<algorithm>  // Most algorithms (sort, find, etc.)
<numeric>    // Numeric algorithms (accumulate, iota)
<iterator>   // Iterator utilities
```

### **8. Comparing Containers**
```cpp
// Direct comparison works!
vector<int> v1 = {1,2,3};
vector<int> v2 = {1,2,3};
if(v1 == v2) { }  // ✅ Lexicographic comparison
```

---

## 🧠 Algorithm Selection Guide

### **Search Operations:**
| Need | Use | Complexity |
|------|-----|------------|
| Unsorted | `find()` | O(n) |
| Sorted | `binary_search()` / `lower_bound()` | O(log n) |
| Multiple occurrences | `count()` / `equal_range()` | O(n) / O(log n) |

### **Sorting Operations:**
| Need | Use | Complexity |
|------|-----|------------|
| General sorting | `sort()` | O(n log n) |
| Stable sorting | `stable_sort()` | O(n log n) |
| Top-k elements | `partial_sort()` | O(n log k) |
| Nth element | `nth_element()` | O(n) |

### **Container Operations:**
| Need | Use |
|------|-----|
| Ordered, unique | `set` |
| Ordered, duplicates | `multiset` |
| Unordered, unique, fast | `unordered_set` |
| Key-value, unique keys | `map` |
| Key-value, fast | `unordered_map` |
| Dynamic array | `vector` |
| Frequent insert/delete | `list` |

---

## 🧠 Performance Cheat Sheet

### **Time Complexities:**
```
Vector:
- Access: O(1)
- Insert/Delete end: O(1) amortized
- Insert/Delete middle: O(n)
- Search: O(n) unsorted, O(log n) sorted

List:
- Access: O(n)
- Insert/Delete (with iterator): O(1)
- Search: O(n)

Map/Set:
- Insert/Delete/Search: O(log n)
- Ordered iteration: O(n)

Unordered Map/Set:
- Insert/Delete/Search: O(1) average, O(n) worst
- No order guarantee

Priority Queue:
- Top: O(1)
- Insert/Delete top: O(log n)
```

---

## 🧪 Practice Zone

### **Container Selection:**
1. Kaunsa container chahiye when: constant time append + random access needed?
2. Kaunsa container fast lookup deta hai without order?
3. Sorted key-value pairs ke liye best container?

### **Algorithm Selection:**
4. Top 10 elements chahiye bade array se – efficient algorithm?
5. Array mein duplicates remove karne ka complete process?
6. Two sorted arrays ka merge karne ka best way?

### **Iterator Challenges:**
7. Bidirectional iterator se random access iterator ka difference?
8. Iterator invalidation kis-kis case mein hota hai?

### **Real-World Scenarios:**
9. LRU Cache implement karna – which containers?
10. Autocomplete system – which container for fast prefix search?
11. Task scheduler with priorities – which container?
12. Finding median in stream of numbers – which data structure?

---

**STL Master Mantra:**
- **Containers** → Right tool for right job
- **Algorithms** → Don't reinvent the wheel
- **Iterators** → Bridge between containers and algorithms

**Pro Tip:** STL ko ache se jaan lo, 90% coding problems solve ho jayenge! 🚀
