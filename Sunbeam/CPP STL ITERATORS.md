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
