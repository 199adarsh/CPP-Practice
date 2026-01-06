📦 **Chapter: Exception Handling, RTTI, Casting, Templates & Data Structures**
(C++ – Concise College Notes)

---

## 🔹 1. EXCEPTION HANDLING

### **📌 Basic Syntax:**

```cpp
try {
    // Risky code
    if (error_condition)
        throw exception_object;  // Throw exception
}
catch (ExceptionType e) {
    // Handle exception
}
```

### **Example - Division by Zero:**

```cpp
try {
    int a = 10, b = 0;
    if (b == 0)
        throw "Division by zero!";
    cout << a / b;
}
catch (const char* msg) {
    cout << "Error: " << msg << endl;
}
```

---

### **📌 Multiple Catch Blocks:**

```cpp
try {
    if (condition1) throw 10;        // int
    if (condition2) throw 3.14;      // double
    if (condition3) throw "Error!";  // string
}
catch (int e) {
    cout << "Int exception: " << e;
}
catch (double e) {
    cout << "Double exception: " << e;
}
catch (const char* e) {
    cout << "String exception: " << e;
}
catch (...) {  // Catch all
    cout << "Unknown exception";
}
```

**Rule:** Specific exceptions first, generic (`...`) last.

---

### **📌 Standard Exception Classes:**

```cpp
#include <stdexcept>

try {
    throw runtime_error("Runtime problem!");
    throw invalid_argument("Bad input!");
    throw out_of_range("Index out of bounds!");
}
catch (exception& e) {  // Base class - catches all
    cout << e.what();  // Print error message
}
```

**Hierarchy:**
```
exception
├── logic_error (programming errors)
│   ├── invalid_argument
│   ├── out_of_range
│   └── length_error
└── runtime_error (runtime problems)
    ├── overflow_error
    └── underflow_error
```

---

### **📌 Custom Exception Class:**

```cpp
class MyException {
    string message;
public:
    MyException(string msg) : message(msg) { }
    string what() { return message; }
};

// Usage:
try {
    throw MyException("Custom error!");
}
catch (MyException& e) {
    cout << e.what();
}
```

---

### **📌 Re-throwing Exception:**

```cpp
void innerFunc() {
    try {
        throw runtime_error("Inner error");
    }
    catch (runtime_error& e) {
        cout << "Caught in inner: " << e.what();
        throw;  // Re-throw to outer
    }
}

void outerFunc() {
    try {
        innerFunc();
    }
    catch (runtime_error& e) {
        cout << "Caught in outer: " << e.what();
    }
}
```

---

## 🔹 2. STACK UNWINDING

### **📌 Concept:**

When exception is thrown, program **unwinds the call stack** - going back through function calls, destroying local objects.

### **Example:**

```cpp
class Resource {
    int id;
public:
    Resource(int i) : id(i) { 
        cout << "Resource " << id << " acquired\n"; 
    }
    ~Resource() { 
        cout << "Resource " << id << " released\n"; 
    }
};

void func3() {
    Resource r3(3);
    throw runtime_error("Error!");
}

void func2() {
    Resource r2(2);
    func3();
}

void func1() {
    Resource r1(1);
    func2();
}

// In main:
try {
    func1();
}
catch (runtime_error& e) {
    cout << "Caught: " << e.what();
}
```

**Output:**
```
Resource 1 acquired
Resource 2 acquired
Resource 3 acquired
Resource 3 released  ← Unwinding starts
Resource 2 released  ← Going back
Resource 1 released  ← Finally
Caught: Error!
```

---

### **📌 Visual Representation:**

```
Call Stack:
main() → func1() → func2() → func3() → EXCEPTION!
                                         ↓
                               Stack Unwinding
                                         ↓
main() ← func1() ← func2() ← func3() (destroyed)
  ↑
Exception caught here
```

---

### **📌 Important Points:**

✅ **Automatic cleanup** of local objects (destructors called)  
✅ **LIFO order** (Last In First Out)  
❌ **Not for pointers** - manual delete needed  
✅ **Use RAII** (Resource Acquisition Is Initialization)

### **Problem with Raw Pointers:**

```cpp
void badFunc() {
    int* ptr = new int[100];
    throw exception();  // ❌ Memory leak! ptr not deleted
}

void goodFunc() {
    unique_ptr<int[]> ptr(new int[100]);
    throw exception();  // ✅ Automatic cleanup
}
```

---

## 🔹 3. RTTI - typeid Operator

### **📌 What is RTTI?**

**Runtime Type Information** - Determine object's actual type at runtime.

### **📌 typeid Syntax:**

```cpp
#include <typeinfo>

typeid(variable).name()  // Get type name
typeid(Type).name()      // Get type name

// Comparison
if (typeid(var1) == typeid(var2)) { }
```

---

### **📌 Basic Types:**

```cpp
int x = 10;
double y = 3.14;
string s = "hello";

cout << typeid(x).name();    // i (int)
cout << typeid(y).name();    // d (double)
cout << typeid(s).name();    // NSt7__cxx11string (implementation-dependent)

if (typeid(x) == typeid(int))
    cout << "x is int";
```

---

### **📌 With Polymorphic Classes:**

**Requirement:** Class must have **at least one virtual function**.

```cpp
class Animal {
public:
    virtual void sound() { }  // Virtual = polymorphic
};

class Dog : public Animal {
public:
    void sound() override { }
};

class Cat : public Animal {
public:
    void sound() override { }
};

// Usage:
Animal* ptr = new Dog();

cout << typeid(*ptr).name();  // Dog (runtime type) ✅
cout << typeid(ptr).name();   // Animal* (pointer type)

if (typeid(*ptr) == typeid(Dog))
    cout << "It's a Dog!";

delete ptr;
```

**Key Difference:**
- `typeid(*ptr)` → Actual object type (runtime)
- `typeid(ptr)` → Pointer type (compile-time)

---

### **📌 Without Virtual Function:**

```cpp
class Base { };  // No virtual function

class Derived : public Base { };

Base* ptr = new Derived();
cout << typeid(*ptr).name();  // Base (compile-time type only)
                              // ❌ No runtime check!
```

**Rule:** typeid gives runtime type only for **polymorphic classes**.

---

## 🔹 4. CASTING OPERATORS

C++ has **4 casting operators** (safer than C-style cast).

### **📌 1. static_cast (Compile-Time Cast)**

**Use:** Type conversions known to be safe at compile-time.

```cpp
// Primitive types
int x = 10;
double y = static_cast<double>(x);  // int → double

// Pointers (Upcasting - always safe)
Dog* d = new Dog();
Animal* a = static_cast<Animal*>(d);  // Child → Parent ✅

// Pointers (Downcasting - risky, no check!)
Animal* a = new Animal();
Dog* d = static_cast<Dog*>(a);  // ⚠️ Unsafe if a is not Dog
```

**Characteristics:**
- Compile-time check only
- No runtime overhead
- Programmer's responsibility to ensure safety

---

### **📌 2. dynamic_cast (Runtime Cast)**

**Use:** Safe downcasting in polymorphic hierarchies.

**Requirement:** Polymorphic class (virtual function needed).

```cpp
class Animal {
public:
    virtual ~Animal() { }  // Virtual function
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!"; }
};

// Safe downcasting:
Animal* a = new Dog();
Dog* d = dynamic_cast<Dog*>(a);  // Runtime check

if (d != nullptr) {  // Check if cast succeeded
    d->bark();  // ✅ Safe
} else {
    cout << "Not a Dog!";
}

// Wrong cast:
Animal* a2 = new Animal();
Dog* d2 = dynamic_cast<Dog*>(a2);  // Returns nullptr
```

**With References:**
```cpp
try {
    Animal& a = getSomeAnimal();
    Dog& d = dynamic_cast<Dog&>(a);  // Throws exception if fails
}
catch (bad_cast& e) {
    cout << "Cast failed!";
}
```

**Characteristics:**
- Runtime type checking (RTTI)
- Returns `nullptr` for pointers (if failed)
- Throws `bad_cast` for references (if failed)
- Slower than static_cast

---

### **📌 3. const_cast (Remove/Add const)**

**Use:** Add or remove `const` qualifier.

```cpp
void modifyData(int* ptr) {
    *ptr = 100;
}

const int x = 50;
// modifyData(&x);  // ❌ Error - can't pass const* to int*

modifyData(const_cast<int*>(&x));  // ✅ Removes const

// Note: Modifying truly const data = undefined behavior!
```

**Typical Use Case:**
```cpp
void legacyFunction(char* str);  // Old API (no const)

const char* myStr = "hello";
legacyFunction(const_cast<char*>(myStr));  // Remove const temporarily
```

**⚠️ Warning:** Use with caution! Modifying const data = undefined behavior.

---

### **📌 4. reinterpret_cast (Low-Level Cast)**

**Use:** Reinterpret bit pattern (dangerous!).

```cpp
// Pointer to integer
int* ptr = new int(100);
long addr = reinterpret_cast<long>(ptr);  // Pointer → integer
cout << "Address: " << addr;

// Integer to pointer
int* newPtr = reinterpret_cast<int*>(addr);  // Integer → pointer

// Unrelated pointer types
char* cptr = reinterpret_cast<char*>(ptr);  // int* → char*
```

**Use Cases:**
- Low-level memory manipulation
- Hardware interfacing
- Serialization

**⚠️ Warning:** Most dangerous cast - avoid unless necessary!

---

### **📌 Casting Summary:**

| Cast | Use | Safety | Speed |
|------|-----|--------|-------|
| **static_cast** | Known safe conversions | No runtime check | Fast |
| **dynamic_cast** | Safe downcasting | Runtime check (RTTI) | Slow |
| **const_cast** | Add/remove const | Programmer's responsibility | Fast |
| **reinterpret_cast** | Bit reinterpretation | Very unsafe | Fast |

**Comparison:**
```cpp
// C-style cast (avoid!)
Dog* d = (Dog*)animalPtr;  // ❌ No type safety

// C++ style (prefer)
Dog* d = static_cast<Dog*>(animalPtr);    // Explicit intent
Dog* d = dynamic_cast<Dog*>(animalPtr);   // Safe with check
```

---

## 🔹 5. TEMPLATE FUNCTIONS

### **📌 Concept:**

**Generic functions** that work with any data type.

### **📌 Syntax:**

```cpp
template <typename T>
T functionName(T param) {
    // Function body
}

// OR
template <class T>
T functionName(T param) {
    // Function body
}
```

**Note:** `typename` and `class` are interchangeable here.

---

### **📌 Simple Example:**

```cpp
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Usage:
int x = maximum(10, 20);        // T = int
double y = maximum(3.14, 2.71); // T = double
char c = maximum('a', 'z');     // T = char

// Explicit type specification:
int z = maximum<int>(10, 20);
```

**Compiler generates:**
```cpp
// maximum<int>
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// maximum<double>
double maximum(double a, double b) {
    return (a > b) ? a : b;
}
```

---

### **📌 Multiple Type Parameters:**

```cpp
template <typename T1, typename T2>
void display(T1 a, T2 b) {
    cout << a << " and " << b;
}

// Usage:
display(10, 3.14);        // T1=int, T2=double
display("Hello", 'A');    // T1=const char*, T2=char
```

---

### **📌 Template with Non-Type Parameters:**

```cpp
template <typename T, int size>
T getMax(T arr[]) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Usage:
int nums[] = {10, 50, 30, 20};
int m = getMax<int, 4>(nums);
```

---

### **📌 Function Overloading with Templates:**

```cpp
// Generic template
template <typename T>
void print(T value) {
    cout << "Template: " << value;
}

// Specialized for int
void print(int value) {
    cout << "Int: " << value;
}

// Usage:
print(10);      // Calls specialized int version
print(3.14);    // Calls template version (T=double)
print("Hi");    // Calls template version (T=const char*)
```

**Rule:** Non-template function preferred over template if both match.

---

## 🔹 6. TEMPLATE CLASS

### **📌 Concept:**

**Generic classes** that work with any data type.

### **📌 Basic Syntax:**

```cpp
template <typename T>
class ClassName {
private:
    T data;
public:
    ClassName(T d) : data(d) { }
    T getData() { return data; }
    void setData(T d) { data = d; }
};

// Usage:
ClassName<int> obj1(10);        // T = int
ClassName<double> obj2(3.14);   // T = double
ClassName<string> obj3("Hello");// T = string
```

---

### **📌 Array Class Example:**

```cpp
template <typename T>
class Array {
private:
    T* arr;
    int size;
public:
    Array(int s) : size(s) {
        arr = new T[size];
    }
    
    ~Array() {
        delete[] arr;
    }
    
    T& operator[](int index) {
        return arr[index];
    }
    
    int getSize() { return size; }
};

// Usage:
Array<int> intArr(5);
intArr[0] = 10;
intArr[1] = 20;

Array<string> strArr(3);
strArr[0] = "Hello";
```

---

### **📌 Multiple Type Parameters:**

```cpp
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) { }
    
    void display() {
        cout << first << ", " << second;
    }
};

// Usage:
Pair<int, string> p1(1, "One");
Pair<double, char> p2(3.14, 'A');
p1.display();  // 1, One
```

---

### **📌 Template with Default Type:**

```cpp
template <typename T = int>  // Default type = int
class Box {
    T value;
public:
    Box(T v) : value(v) { }
    T getValue() { return value; }
};

// Usage:
Box<> b1(10);        // Uses default (int)
Box<double> b2(3.14);// Explicit double
```

---

### **📌 Member Function Definition Outside Class:**

```cpp
template <typename T>
class Calculator {
public:
    T add(T a, T b);      // Declaration
    T multiply(T a, T b); // Declaration
};

// Definition outside (note template before each function)
template <typename T>
T Calculator<T>::add(T a, T b) {
    return a + b;
}

template <typename T>
T Calculator<T>::multiply(T a, T b) {
    return a * b;
}
```

---

### **📌 Template Specialization:**

**Full Specialization:**
```cpp
// Generic template
template <typename T>
class Printer {
public:
    void print(T value) {
        cout << value;
    }
};

// Specialization for bool
template <>
class Printer<bool> {
public:
    void print(bool value) {
        cout << (value ? "true" : "false");
    }
};

// Usage:
Printer<int> p1;
p1.print(10);     // 10

Printer<bool> p2;
p2.print(true);   // true (not 1)
```

---

## 🔹 7. STACK DATA STRUCTURE

### **📌 Concept:**

**LIFO** (Last In First Out) - Last element added is first to be removed.

**Real-life:** Stack of plates, browser back button, undo/redo.

### **📌 Basic Operations:**

```cpp
push()   // Add element to top
pop()    // Remove element from top
top()    // View top element (no removal)
empty()  // Check if empty
size()   // Get number of elements
```

---

### **📌 Array Implementation:**

```cpp
class Stack {
private:
    int arr[100];
    int topIndex;
public:
    Stack() : topIndex(-1) { }
    
    void push(int value) {
        if (topIndex >= 99) {
            cout << "Stack Overflow!";
            return;
        }
        arr[++topIndex] = value;
    }
    
    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow!";
            return;
        }
        topIndex--;
    }
    
    int top() {
        if (topIndex < 0) {
            cout << "Stack Empty!";
            return -1;
        }
        return arr[topIndex];
    }
    
    bool empty() {
        return topIndex < 0;
    }
};
```

**Usage:**
```cpp
Stack s;
s.push(10);
s.push(20);
s.push(30);

cout << s.top();  // 30
s.pop();
cout << s.top();  // 20
```

---

### **📌 Linked List Implementation:**

```cpp
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) { }
};

class Stack {
private:
    Node* topNode;
public:
    Stack() : topNode(nullptr) { }
    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }
    
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack Empty!";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    
    int top() {
        if (topNode == nullptr) {
            cout << "Stack Empty!";
            return -1;
        }
        return topNode->data;
    }
    
    bool empty() {
        return topNode == nullptr;
    }
};
```

---

### **📌 STL Stack:**

```cpp
#include <stack>

stack<int> s;

s.push(10);
s.push(20);
s.push(30);

cout << s.top();  // 30
s.pop();
cout << s.size(); // 2
cout << s.empty();// false
```

---

### **📌 Applications:**

1. **Function Call Management** (call stack)
2. **Expression Evaluation** (postfix, prefix)
3. **Parenthesis Matching**
4. **Backtracking** (maze, N-Queens)
5. **Undo/Redo** functionality

---

## 🔹 8. QUEUE DATA STRUCTURE

### **📌 Concept:**

**FIFO** (First In First Out) - First element added is first to be removed.

**Real-life:** Line at ticket counter, printer queue, breadth-first search.

### **📌 Basic Operations:**

```cpp
enqueue() / push()  // Add element to rear
dequeue() / pop()   // Remove element from front
front()             // View front element
rear() / back()     // View rear element
empty()             // Check if empty
size()              // Get number of elements
```

---

### **📌 Array Implementation (Circular Queue):**

```cpp
class Queue {
private:
    int arr[100];
    int frontIndex, rearIndex, count;
public:
    Queue() : frontIndex(0), rearIndex(-1), count(0) { }
    
    void enqueue(int value) {
        if (count >= 100) {
            cout << "Queue Full!";
            return;
        }
        rearIndex = (rearIndex + 1) % 100;  // Circular
        arr[rearIndex] = value;
        count++;
    }
    
    void dequeue() {
        if (count <= 0) {
            cout << "Queue Empty!";
            return;
        }
        frontIndex = (frontIndex + 1) % 100;  // Circular
        count--;
    }
    
    int front() {
        if (count <= 0) {
            cout << "Queue Empty!";
            return -1;
        }
        return arr[frontIndex];
    }
    
    bool empty() {
        return count == 0;
    }
    
    int size() {
        return count;
    }
};
```

**Why Circular?** Efficient space utilization - reuse empty front space.

---

### **📌 Linked List Implementation:**

```cpp
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) { }
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;
public:
    Queue() : frontNode(nullptr), rearNode(nullptr) { }
    
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rearNode == nullptr) {  // Empty queue
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }
    
    void dequeue() {
        if (frontNode == nullptr) {
            cout << "Queue Empty!";
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr)  // Queue became empty
            rearNode = nullptr;
        delete temp;
    }
    
    int front() {
        if (frontNode == nullptr) {
            cout << "Queue Empty!";
            return -1;
        }
        return frontNode->data;
    }
    
    bool empty() {
        return frontNode == nullptr;
    }
};
```

---

### **📌 STL Queue:**

```cpp
#include <queue>

queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.front();  // 10
q.pop();
cout << q.front();  // 20
cout << q.size();   // 2
cout << q.empty();  // false
```

---

### **📌 Types of Queues:**

### **1. Simple Queue (FIFO)**
```cpp
queue<int> q;
q.push(10); q.push(20); q.push(30);
// Front: 10 → 20 → 30 :Rear
```

### **2. Circular Queue**
```cpp
// When rear reaches end, wraps to beginning
// Efficient space utilization
```

### **3. Priority Queue (Heap)**
```cpp
#include <queue>

priority_queue<int> pq;  // Max-heap by default

pq.push(30);
pq.push(10);
pq.push(20);

cout << pq.top();  // 30 (highest priority)
pq.pop();
cout << pq.top();  // 20
```

**Min-Heap:**
```cpp
priority_queue<int, vector<int>, greater<int>> minPQ;

minPQ.push(30);
minPQ.push(10);
minPQ.push(20);

cout << minPQ.top();  // 10 (lowest value)
```

### **4. Deque (Double-Ended Queue)**
```cpp
#include <deque>

deque<int> dq;

dq.push_front(10);  // Add to front
dq.push_back(20);   // Add to back
dq.pop_front();     // Remove from front
dq.pop_back();      // Remove from back
```

---

### **📌 Applications:**

1. **CPU Scheduling** (process queue)
2. **Printer Queue** (job scheduling)
3. **BFS Algorithm** (graph traversal)
4. **Buffer Management** (keyboard buffer)
5. **Handling Interrupts**

---

## 📊 Quick Comparison Table

### **Stack vs Queue:**

| Feature | Stack | Queue |
|---------|-------|-------|
| **Order** | LIFO | FIFO |
| **Insertion** | Top (push) | Rear (enqueue) |
| **Deletion** | Top (pop) | Front (dequeue) |
| **Access** | Top only | Front only |
| **Example** | Undo/Redo | Print Queue |

---

### **Casting Operators:**

| Operator | Use | Check | Speed |
|----------|-----|-------|-------|
| **static_cast** | Compile-time conversion | Compile-time | Fast |
| **dynamic_cast** | Safe runtime downcasting | Runtime (RTTI) | Slow |
| **const_cast** | Add/remove const | None | Fast |
| **reinterpret_cast** | Bit reinterpretation | None | Fast |

---

## 🧪 Exam Quick Points

### **Exception Handling:**
- `try` block contains risky code
- `throw` raises exception
- `catch` handles exception
- Stack unwinding = automatic cleanup

### **RTTI:**
- `typeid(*ptr)` gives runtime type (polymorphic class needed)
- `typeid(ptr)` gives compile-time type

### **Casting:**
- Use `dynamic_cast` for safe downcasting
- Use `static_cast` for known conversions
- Avoid C-style cast `(Type)`

### **Templates:**
- Function templates: `template <typename T>`
- Class templates: Must specify type `ClassName<int>`
- Generic programming = code reuse

### **Stack:**
- LIFO structure
- Operations: push, pop, top
- Array or linked list implementation

### **Queue:**
- FIFO structure
- Operations: enqueue, dequeue, front
- Circular queue = efficient space

---

## 📝 Common Exam Questions

**Short Answer:**
1. Difference between stack and queue?
2. What is stack unwinding?
3. Difference between static_cast and dynamic_cast?
4. Syntax of template function?

**Long Answer:**
1. Explain exception handling with example.
2. Write template class for Array with all operations.
3. Implement Stack using linked list.
4. Explain RTTI with typeid operator.

**Programs:**
1. Template function to swap two values.
2. Stack implementation using array.
3. Queue implementation using linked list.
4. Exception handling for division by zero.

---

**Final Tip:** Templates = Generic, RTTI = Runtime type, Cast = Type conversion, Stack = LIFO, Queue = FIFO! 🎯