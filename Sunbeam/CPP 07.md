📦 **Chapter: STL – Containers, Algorithms & Iterators**
(C++ – Standard Template Library Deep Dive)

---

## 🧠 What is STL?

**STL (Standard Template Library)** C++ ka powerhouse hai – pre-built, tested, optimized data structures aur algorithms ka collection.

**STL ke 3 main pillars:**
1. **Containers** → Data store karne ke liye (vector, list, map, etc.)
2. **Algorithms** → Data process karne ke liye (sort, search, find, etc.)
3. **Iterators** → Containers aur algorithms ko connect karne ke liye (pointers ka advanced version)

**Why STL?**
- Khud se wheel reinvent nahi karna padta
- Industry-standard, optimized code
- Generic programming (templates ke through)
- Bug-free, well-tested implementations

**Think of it as:** Ready-made kitchen appliances vs building from scratch

---

# 📦 PART 1: STL CONTAINERS

## 🧠 Container Categories

STL containers 3 categories mein divide hote hain:

### **1. Sequence Containers** (Order maintained)
- `vector`, `deque`, `list`, `forward_list`, `array`

### **2. Associative Containers** (Sorted, key-based)
- `set`, `multiset`, `map`, `multimap`

### **3. Unordered Associative Containers** (Hash-based, no order)
- `unordered_set`, `unordered_map`, `unordered_multiset`, `unordered_multimap`

### **4. Container Adapters** (Restricted interfaces)
- `stack`, `queue`, `priority_queue`

---

## 🔹 1. VECTOR (Dynamic Array)

### **Core Concept:**
Dynamic array jo runtime pe grow/shrink kar sakta hai. Sabse commonly used container.

### **Internal Working:**
- Contiguous memory allocation (array ki tarah)
- Capacity doubles jab full ho jata hai (amortized O(1) insertion)
- Elements sequentially stored hain

### **Key Characteristics:**
✅ Random access: O(1)  
✅ Insert/delete at end: O(1) amortized  
❌ Insert/delete at beginning/middle: O(n)  
✅ Cache-friendly (contiguous memory)  
✅ Size dynamic (runtime pe change)

### **When to Use:**
- Default choice for most cases
- Random access chahiye
- End pe insertion/deletion zyada hai
- Cache performance important hai

### **When NOT to Use:**
- Frequent insertion/deletion at beginning
- Memory reallocation expensive lag raha hai
- Size fixed hai (use `array` instead)

### **Important Methods:**
```cpp
push_back(), pop_back()     // End operations - O(1)
insert(), erase()           // Middle operations - O(n)
size(), capacity()          // Size queries
reserve(), shrink_to_fit()  // Memory management
front(), back()             // Access first/last
clear()                     // Remove all
```

### **Memory Insight:**
```
Size vs Capacity:
Size = actual elements
Capacity = allocated memory

vector<int> v;
v.push_back(10);  // size=1, capacity=1
v.push_back(20);  // size=2, capacity=2
v.push_back(30);  // size=3, capacity=4 (doubled!)
```

---

## 🔹 2. DEQUE (Double-Ended Queue)

### **Core Concept:**
Vector ka cousin – dono ends se fast insertion/deletion. Internally multiple fixed-size arrays ka collection.

### **Internal Working:**
- Multiple chunks (blocks) of memory
- Ek central map array jo blocks ko track karti hai
- Not contiguous like vector

### **Key Characteristics:**
✅ Random access: O(1)  
✅ Insert/delete at both ends: O(1)  
❌ Insert/delete in middle: O(n)  
❌ Less cache-friendly than vector  
✅ No reallocation (grows in chunks)

### **When to Use:**
- Insertion/deletion at both ends chahiye
- Queue/deque behavior chahiye
- Reallocation overhead avoid karna hai

### **Deque vs Vector:**
| Feature | Vector | Deque |
|---------|--------|-------|
| Memory | Contiguous | Chunked |
| Front insertion | O(n) | O(1) |
| Cache performance | Better | Good |
| Reallocation | Full copy | No copy |

---

## 🔹 3. LIST (Doubly Linked List)

### **Core Concept:**
Traditional doubly linked list – har node pe prev aur next pointers.

### **Internal Working:**
- Nodes dynamically allocated
- Each node has data + two pointers
- Non-contiguous memory

### **Key Characteristics:**
❌ Random access: O(n)  
✅ Insert/delete anywhere: O(1) (agar iterator hai)  
❌ No index-based access  
✅ No reallocation needed  
❌ Extra memory overhead (pointers)

### **When to Use:**
- Frequent insertion/deletion in middle
- No random access needed
- Stable iterators chahiye (insertion/deletion se invalidate nahi hote)

### **List vs Vector:**
```
Vector: [1][2][3][4][5]  → Contiguous, fast access
List:   [1]→[2]→[3]→[4]→[5]  → Non-contiguous, fast insert/delete
```

### **Special Methods:**
```cpp
splice()    // Transfer elements from another list - O(1)
merge()     // Merge two sorted lists - O(n)
unique()    // Remove consecutive duplicates - O(n)
reverse()   // Reverse list - O(n)
```

---

## 🔹 4. FORWARD_LIST (Singly Linked List)

### **Core Concept:**
List ka lightweight version – sirf forward pointers, no backward traversal.

### **Key Differences from List:**
- Half memory overhead (one pointer vs two)
- Can't traverse backward
- No `size()` method (O(1) mein available nahi)
- Slightly faster than list

### **When to Use:**
- Memory constraint hai
- Backward traversal ki zarurat nahi
- Minimal overhead chahiye

---

## 🔹 5. ARRAY (Fixed-Size Array)

### **Core Concept:**
C-style array ka STL wrapper with safety features.

### **Key Characteristics:**
✅ Zero overhead over C arrays  
✅ Size fixed at compile-time  
✅ Stack-allocated (usually)  
✅ Bounds checking with `.at()`  
❌ Can't resize

### **Array vs Vector:**
```
array<int, 5> arr;    // Fixed size, stack
vector<int> vec;      // Dynamic size, heap
```

### **When to Use:**
- Size fixed hai compile-time pe
- No dynamic allocation chahiye
- Performance-critical code

---

## 🔹 6. SET (Sorted Unique Elements)

### **Core Concept:**
Binary Search Tree (usually Red-Black Tree) – sorted, unique elements.

### **Internal Working:**
- Self-balancing BST
- Elements always sorted
- Automatic duplicate removal

### **Key Characteristics:**
✅ Auto-sorted: Elements always in order  
✅ Unique elements only  
✅ Insert/delete/search: O(log n)  
❌ No random access  
❌ Can't modify elements (have to erase + insert)

### **When to Use:**
- Need sorted data
- No duplicates allowed
- Fast search required

### **Set Operations:**
```cpp
insert()      // O(log n)
erase()       // O(log n)
find()        // O(log n)
count()       // O(log n) - returns 0 or 1
lower_bound() // First element >= value
upper_bound() // First element > value
```

---

## 🔹 7. MULTISET (Sorted, Allows Duplicates)

### **Core Concept:**
Set ka version jo duplicates allow karta hai.

### **Key Difference:**
- `count()` can return > 1
- Same element multiple times store ho sakta hai
- Still sorted

### **When to Use:**
- Sorted data + duplicates allowed
- Frequency tracking with sorting

---

## 🔹 8. MAP (Key-Value Pairs, Sorted by Key)

### **Core Concept:**
Dictionary/associative array – keys sorted hain, each key unique.

### **Internal Working:**
- Red-Black Tree based
- Keys sorted in ascending order
- O(log n) operations

### **Key Characteristics:**
✅ Sorted by keys  
✅ Unique keys  
✅ Insert/delete/search: O(log n)  
✅ Access via `[]` or `.at()`  
❌ `[]` creates entry if not exists

### **When to Use:**
- Key-value mapping chahiye
- Sorted keys chahiye
- Fast lookup required

### **Map vs Unordered_Map:**
| Feature | map | unordered_map |
|---------|-----|---------------|
| Order | Sorted | No order |
| Implementation | Red-Black Tree | Hash Table |
| Insert/Search | O(log n) | O(1) average |
| Memory | Less | More (buckets) |

---

## 🔹 9. MULTIMAP (Allows Duplicate Keys)

### **Core Concept:**
Map jo duplicate keys allow karta hai.

### **Key Characteristics:**
- One key → multiple values possible
- Still sorted by keys
- Can't use `[]` operator (ambiguity)

### **When to Use:**
- One-to-many relationship
- Sorted keys with duplicate entries

---

## 🔹 10. UNORDERED_SET / UNORDERED_MAP

### **Core Concept:**
Hash table based – no sorting, but O(1) average operations.

### **Internal Working:**
- Hash function determines bucket
- Collisions handled (chaining/open addressing)
- No order maintained

### **Key Characteristics:**
✅ Insert/delete/search: O(1) average  
✅ Fastest for lookups  
❌ Worst case: O(n) (bad hash function)  
❌ No sorted order  
❌ More memory (buckets)

### **When to Use:**
- Order ki zarurat nahi
- Maximum speed chahiye
- Large datasets with frequent lookups

### **Hash Collision Handling:**
```
Bucket 0: []
Bucket 1: [10] → [20] → [30]  // Collision chain
Bucket 2: [15]
Bucket 3: []
```

---

## 🔹 11. STACK (LIFO)

### **Core Concept:**
Last In First Out – top se hi insert/delete.

### **Internal Working:**
- Container adapter (uses deque/vector/list internally)
- Restricted interface

### **Key Operations:**
```cpp
push()    // Insert at top - O(1)
pop()     // Remove from top - O(1)
top()     // Access top - O(1)
empty()   // Check if empty
size()    // Get size
```

### **When to Use:**
- Function calls (recursion)
- Undo/redo operations
- Expression evaluation
- DFS algorithm

---

## 🔹 12. QUEUE (FIFO)

### **Core Concept:**
First In First Out – front se remove, back se insert.

### **Key Operations:**
```cpp
push()    // Insert at back - O(1)
pop()     // Remove from front - O(1)
front()   // Access front - O(1)
back()    // Access back - O(1)
```

### **When to Use:**
- BFS algorithm
- Task scheduling
- Buffer management
- Order processing

---

## 🔹 13. PRIORITY_QUEUE (Heap)

### **Core Concept:**
Max-heap by default – highest priority element always on top.

### **Internal Working:**
- Binary heap implementation
- Parent >= children (max-heap)
- Uses vector internally

### **Key Characteristics:**
✅ Top element: O(1)  
✅ Insert: O(log n)  
✅ Delete top: O(log n)  
❌ No random access  
❌ Can't iterate

### **When to Use:**
- Always need max/min element
- Dijkstra's algorithm
- Job scheduling
- Huffman coding

### **Min-Heap Syntax:**
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

---

## 🧠 Container Selection Guide

### **By Access Pattern:**
- **Random access needed** → `vector`, `deque`, `array`
- **Sequential access only** → `list`, `forward_list`
- **Key-based access** → `map`, `unordered_map`

### **By Insertion/Deletion:**
- **End only** → `vector`
- **Both ends** → `deque`
- **Anywhere** → `list`
- **Sorted insertion** → `set`, `map`

### **By Speed:**
- **Fastest lookup** → `unordered_set`, `unordered_map`
- **Sorted lookup** → `set`, `map`
- **Fastest iteration** → `vector`, `array`

### **By Memory:**
- **Least overhead** → `array`, `vector`
- **More overhead** → `list` (pointers), `unordered_map` (buckets)

---

# 🔄 PART 2: ITERATORS

## 🧠 What are Iterators?

**Iterators** pointers ki tarah hote hain – containers ke elements ko traverse karte hain.

**Think of them as:** Generalized pointers that work across all containers

### **Why Iterators?**
- Uniform way to traverse different containers
- Algorithms ko generic banate hain
- Type-safe pointer alternative

---

## 🔹 Iterator Categories (5 Types)

### **1. Input Iterator** (Read-only, forward)
- Ek baar traverse (single pass)
- Read-only
- Example: `istream_iterator`

**Capabilities:**
```cpp
++it        // Move forward
*it         // Read value
it1 == it2  // Compare
```

---

### **2. Output Iterator** (Write-only, forward)
- Ek baar traverse
- Write-only
- Example: `ostream_iterator`

**Capabilities:**
```cpp
++it        // Move forward
*it = val   // Write value
```

---

### **3. Forward Iterator** (Read/Write, forward)
- Multiple passes possible
- Read + Write
- Example: `forward_list::iterator`

**Capabilities:**
```cpp
++it        // Move forward (multiple times)
*it         // Read
*it = val   // Write
```

---

### **4. Bidirectional Iterator** (Forward + Backward)
- Move both directions
- Example: `list::iterator`, `set::iterator`, `map::iterator`

**Capabilities:**
```cpp
++it        // Move forward
--it        // Move backward
*it         // Read/Write
```

---

### **5. Random Access Iterator** (Full pointer features)
- Jump to any position
- Pointer arithmetic
- Example: `vector::iterator`, `deque::iterator`, `array::iterator`

**Capabilities:**
```cpp
++it, --it      // Increment/decrement
it + n, it - n  // Jump
it[n]           // Index access
it1 < it2       // Comparison
```

---

## 🔹 Iterator Types per Container

| Container | Iterator Type |
|-----------|---------------|
| `vector`, `deque`, `array` | Random Access |
| `list` | Bidirectional |
| `forward_list` | Forward |
| `set`, `map` | Bidirectional |
| `unordered_set`, `unordered_map` | Forward |
| `stack`, `queue`, `priority_queue` | No iterator |

---

## 🔹 Iterator Operations

### **Common Operations:**
```cpp
begin()       // First element
end()         // Past-the-last element (sentinel)
rbegin()      // Reverse begin (last element)
rend()        // Reverse end (before first)
cbegin()      // Const begin
cend()        // Const end
```

### **Iterator Arithmetic:**
```cpp
it++, ++it      // Forward
it--, --it      // Backward
it + n          // Jump forward by n (random access only)
it - n          // Jump backward by n
it1 - it2       // Distance between iterators
```

### **Iterator Functions:**
```cpp
advance(it, n)       // Move iterator by n positions
distance(it1, it2)   // Count elements between iterators
next(it, n)          // Get iterator n positions ahead
prev(it, n)          // Get iterator n positions back
```

---

## 🔹 Iterator Invalidation

**Critical concept:** Kab iterators invalid ho jate hain.

### **Vector:**
```
Insertion → All iterators after insertion point invalid
Deletion → All iterators after deletion point invalid
Reallocation → ALL iterators invalid
```

### **List:**
```
Insertion → No invalidation
Deletion → Only deleted element's iterator invalid
```

### **Map/Set:**
```
Insertion → No invalidation
Deletion → Only deleted element's iterator invalid
```

### **Deque:**
```
Insertion at ends → No invalidation (except end())
Insertion in middle → All invalid
Deletion at ends → Affected iterators invalid
```

---

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