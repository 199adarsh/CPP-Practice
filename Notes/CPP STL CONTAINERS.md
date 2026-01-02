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
