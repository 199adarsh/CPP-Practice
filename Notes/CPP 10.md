📦 **Chapter: Abstract Classes, Binding, Virtual Functions & Exception Handling**
(C++ – College Level Notes)

## 🔹 1. ABSTRACT CLASSES

### **📌 Definition (real feel):**

An **abstract class** is a class jiska **object nahi bana sakte**.
It acts like a **blueprint** — and it **must contain at least one pure virtual function**.

👉 Pure virtual function =

> “Child class… tu isko **zaroor override karega**.”

---

### **🎯 Purpose (why it exists):**

* Create **common rules** for all derived classes
* Force subclasses to implement required behavior
* Hide details → show only what matters (**abstraction**)

Think:

> “Base class guideline deta hai, implementation child karega.”

---

### **🧾 Syntax (super simple):**

```cpp
class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0;  // Pure virtual

    void normalFunction() {                  // Allowed
        cout << "Normal function in abstract class" << endl;
    }

    virtual ~AbstractClass() { }             // Virtual destructor (good practice)
};
```

---

### **🔑 Key Points (yaad rakhna):**

✅ At least **1 pure virtual function** required (`= 0`)<br>
❌ Object bana nahi sakte: `AbstractClass obj;`<br>
✅ Pointer/reference bana sakte ho: `AbstractClass* ptr;` <br>
✅ **Every derived class must implement all pure virtual functions**<br>

👉 Hinglish note:

> “Abstract class = design.
> Real kaam = derived classes.”

---

### **🧪 Example (simple + realistic):**

```cpp
class Shape {   // Abstract
protected:
    string color;

public:
    Shape(string c) : color(c) { }

    virtual void draw() = 0;        // Must override
    virtual double area() = 0;      // Must override

    void setColor(string c) {       // Normal method
        color = c;
    }

    virtual ~Shape() { }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, string c) : Shape(c), radius(r) { }

    void draw() override {
        cout << "Drawing Circle" << endl;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Shape s;            // ❌ Not allowed

    Shape* ptr = new Circle(5, "Red");   // ✅ Works
    ptr->draw();
    cout << "Area: " << ptr->area() << endl;

    delete ptr;
}
```

👉 Key takeaway:

> Base pointer → Derived object → Runtime polymorphism.

---

### **🆚 Abstract Class vs Concrete Class**

| Abstract Class             | Concrete Class             |
| -------------------------- | -------------------------- |
| Has pure virtual functions | All functions implemented  |
| Cannot create object       | Object bana sakte          |
| Used as **blueprint**      | Used as **implementation** |
| Child must override        | Override optional          |

---

### **🧩 Interface (Pure Abstract Class)**

> C++ me “interface” officially nahi —
> but we **simulate** it using pure abstract class:

```cpp
class IDrawable {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~IDrawable() { }
};
```

👉 Rule of thumb:

> Interface = **sirf pure virtual functions**, no data, no implementation.


### ☕ Quick Mindset Recap

* Abstract class → **rules banane wala**
* Derived class → **kaam karne wala**
* Pure virtual → **“override karna hi padega”**

---

## 🔹 2. EARLY BINDING & LATE BINDING

### **📌 Definitions (simple + clear):**

**Early Binding (Static Binding)**

* Function call **compile-time par decide hota hai**
* Compiler checks pointer/reference type and fixes the call
* Default behavior in C++
* Fast (no extra lookup)

**Late Binding (Dynamic Binding)**

* Function call **runtime par decide hota hai**
* Depends on the **actual object**
* Happens only with **virtual functions**
* Slight performance cost (vtable lookup)

---

### **Early Binding Example**

```cpp
class Base {
public:
    void display() {           // non-virtual
        cout << "Base display" << endl;
    }
};

class Derived : public Base {
public:
    void display() {           // hides Base::display
        cout << "Derived display" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->display();            // Base display  ✅
    delete ptr;
}
```

**Explanation (hinglish tip):**
Compiler sirf **pointer type dekhta hai (`Base*`)** —
isliye call **Base::display()** ko bind ho jata hai.

---

### **Late Binding Example**

```cpp
class Base {
public:
    virtual void display() {   // virtual enables polymorphism
        cout << "Base display" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived display" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->display();            // Derived display  ✅
    delete ptr;
}
```

**Explanation:**
`virtual` ke wajah se decision **runtime par hota hai** —
actual object `Derived` hai, toh uska function call hota hai.

---

### **Comparison Table**

| Feature           | Early Binding          | Late Binding        |
| ----------------- | ---------------------- | ------------------- |
| When decided      | Compile-time           | Runtime             |
| Keyword           | None                   | `virtual`           |
| Speed             | Faster                 | Slightly slower     |
| Decision based on | Pointer/reference type | Actual object       |
| Works with        | Non-virtual            | Virtual             |
| Flexibility       | Low                    | High (polymorphism) |
| Memory            | No extra cost          | Uses vtable/vptr    |

---

### **Which Binding Happens Here?**

```cpp
class Base {
public:
    void func1() { }          // Early binding
    virtual void func2() { }  // Late binding
    static void func3() { }   // Early binding (no polymorphism)
};

Base* ptr = new Derived();

ptr->func1();   // Base::func1()   → early
ptr->func2();   // Derived::func2()→ late (if overridden)
Base::func3();  // static → early
```

**Mental shortcut:**

> **virtual = runtime decision**
> **non-virtual/static = compile-time decision**

## 🔹 3. VIRTUAL FUNCTION INTERNAL EXECUTION

### **📌 How Virtual Functions Work:**

C++ uses **vtable (Virtual Table)** and **vptr (Virtual Pointer)** mechanism.

### **Step-by-Step Process:**

### **Step 1: vtable Creation (Compile-time)**

Compiler creates a **vtable** for each class with virtual functions.

```cpp
class Animal {
public:
    virtual void eat() { }
    virtual void sleep() { }
};

class Dog : public Animal {
public:
    void eat() override { }  // Overridden
    // sleep() not overridden
};
```

**Animal's vtable:**
```
┌─────────────────┐
│ Animal::eat()   │
│ Animal::sleep() │
└─────────────────┘
```

**Dog's vtable:**
```
┌─────────────────┐
│ Dog::eat()      │  ← Overridden
│ Animal::sleep() │  ← Inherited
└─────────────────┘
```

---

### **Step 2: vptr in Object (Runtime)**

Each object gets a **vptr (virtual pointer)** pointing to its class's vtable.

```cpp
Animal a;
Dog d;
```

**Memory Layout:**

```
Animal object 'a':
┌─────────┐
│ vptr    │ ──→ Animal's vtable
├─────────┤
│ data    │
└─────────┘

Dog object 'd':
┌─────────┐
│ vptr    │ ──→ Dog's vtable
├─────────┤
│ data    │
└─────────┘
```

---

### **Step 3: Function Call (Runtime)**

```cpp
Animal* ptr = new Dog();
ptr->eat();  // How is this resolved?
```

**Resolution Process:**

1. **Dereference pointer** → Get object
2. **Follow vptr** → Get vtable address
3. **Look up function** in vtable (index-based)
4. **Call function** from vtable

```
ptr → Dog object → vptr → Dog's vtable → Dog::eat() → Execute
```

---

### **Complete Example with Visualization:**

```cpp
class Shape {
public:
    virtual void draw() { 
        cout << "Shape draw" << endl; 
    }
    virtual void area() { 
        cout << "Shape area" << endl; 
    }
};

class Circle : public Shape {
public:
    void draw() override { 
        cout << "Circle draw" << endl; 
    }
    // area() not overridden
};

int main() {
    Shape* s1 = new Shape();
    Shape* s2 = new Circle();
    
    s1->draw();  // Shape draw
    s2->draw();  // Circle draw
    s2->area();  // Shape area
    
    return 0;
}
```

**Memory Structure:**

```
s1 → Shape object
     ┌─────────┐
     │ vptr    │ ──→ Shape's vtable
     └─────────┘      ┌──────────────┐
                      │ Shape::draw()│
                      │ Shape::area()│
                      └──────────────┘

s2 → Circle object
     ┌─────────┐
     │ vptr    │ ──→ Circle's vtable
     └─────────┘      ┌──────────────┐
                      │ Circle::draw()│  ← Overridden
                      │ Shape::area() │  ← Inherited
                      └──────────────┘
```

---

### **Key Points:**

✅ **vtable** = Array of function pointers (one per class)  
✅ **vptr** = Pointer to vtable (one per object)  
✅ **Compile-time**: vtables created  
✅ **Runtime**: vptr used for function lookup  
✅ **Index-based lookup**: O(1) access time  
✅ **Space overhead**: One pointer (vptr) per object  
✅ **Time overhead**: One extra indirection (negligible)

---

### **Size Impact:**

```cpp
class WithoutVirtual {
    int x;
};

class WithVirtual {
    int x;
    virtual void func() { }
};

cout << sizeof(WithoutVirtual);  // 4 bytes (just int)
cout << sizeof(WithVirtual);     // 12 bytes (int + vptr)
// vptr typically 8 bytes on 64-bit systems
```

---
## 🔹 4. EXCEPTION HANDLING

### **📌 What is an Exception?**

**Exception** = koi aisa **runtime error** jo normal program flow ko tod de.

**Typical cases:**

* division by zero
* array index galat
* file open na ho paana
* memory allocate na ho paana
* invalid / unexpected user input

👉 Goal: program **crash na ho** — instead, handle it politely.

---

### **Why Exception Handling?**

* error-handling code ko normal logic se **alag rakhta hai**
* error ko safely **caller tak forward** kar sakte ho
* resources (files, memory, locks) safe close ho jaate hain
* program **recover** ya exit cleanly kar sakta hai

Think:

> “Problem aayi — panic nahi — handle kar ke aage badho.”

---

### **📌 try, catch, throw**

### **Syntax**

```cpp
try {
    // Code jo fail ho sakta hai
    // throw exception_object;
}
catch (ExceptionType e) {
    // Error ko handle karo
}
```

---

### **Basic Example**

```cpp
int main() {
    int a, b;
    cin >> a >> b;

    try {
        if (b == 0)
            throw "Division by zero error!";
        
        cout << a / b;
    }
    catch (const char* msg) {
        cout << "Error: " << msg;
    }

    cout << "\nProgram continues...";
}
```

👉 Program **rukta nahi**, error handle karke continue hota hai.

---

### **📌 Multiple catch Blocks**

```cpp
try {
    if (condition1) throw 10;
    if (condition2) throw 3.14;
    if (condition3) throw "Error!";
}
catch (int e)        { cout << "Integer: " << e; }
catch (double e)     { cout << "Double: " << e; }
catch (const char* e){ cout << "String: " << e; }
catch (...)          { cout << "Unknown exception"; }
```

👉 **Order important hai** — specific first, catch-all last.

---

### **📌 Standard Exception Classes**

C++ me built-in exceptions `<stdexcept>` me milte hain:

```cpp
int divide(int a, int b) {
    if (b == 0)
        throw runtime_error("Division by zero!");
    return a / b;
}
```

```cpp
try {
    cout << divide(10, 0);
}
catch (runtime_error& e) {
    cout << "Runtime Error: " << e.what();
}
```

**Hierarchy (simplified):**

```
exception
 ├─ logic_error
 │   ├─ invalid_argument
 │   ├─ out_of_range
 └─ runtime_error
     ├─ overflow_error
     └─ underflow_error
```

👉 Tip: `what()` message explain karta hai.

---

### **📌 Custom Exception Class**

```cpp
class MyException {
    string message;
public:
    MyException(string msg) : message(msg) {}
    string what() { return message; }
};
```

```cpp
try {
    throw MyException("Custom error occurred!");
}
catch (MyException& e) {
    cout << e.what();
}
```

👉 Apni meaningful error types bana sakte ho.

---

### **📌 Re-throwing Exceptions**

```cpp
void func2() {
    try {
        throw runtime_error("Error in func2");
    }
    catch (runtime_error& e) {
        cout << "Caught in func2\n";
        throw;   // forward again
    }
}
```

```cpp
void func1() {
    try { func2(); }
    catch (runtime_error& e) {
        cout << "Caught in func1\n";
    }
}
```

👉 Same error **upar wale function** tak propagate hota hai.

---

### **📌 Exception Specifications (Modern view)**

Old style (deprecated / removed):

```cpp
void func() throw(int, char) { }
```

Modern style:

```cpp
void f1() noexcept { }          // promise: no exception
void f2() noexcept(false) { }   // may throw
```

👉 Hinglish:

> `noexcept` = “main exception nahi phenkunga — agar phenka, program terminate!”

---

### **Quick takeaways**

* `throw` → error raise karo
* `try` → risk wali code block
* `catch` → error handle karo
* prefer **standard exceptions**
* **clean exit > program crash**

## 🔹 5. STACK UNWINDING  

### **📌 What is Stack Unwinding?**  

**Stack unwinding** = jab exception throw hota hai, tab compiler function-call stack ko **peeche ki taraf roll back** karta hai —  
aur har level par **local objects ke destructors automatically call** karta hai —  
jab tak matching `catch` block na mil jaaye.

👉 Simple bolun toh:  
> “Exception aayi → functions reverse order me band hone lagte hain.”

---

### **Step-by-Step Demo**

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
```

```cpp
void func3() {
    Resource r3(3);
    throw runtime_error("Error in func3");
}

void func2() {
    Resource r2(2);
    func3();
}

void func1() {
    Resource r1(1);
    func2();
}

int main() {
    try { func1(); }
    catch (runtime_error& e) {
        cout << "Caught: " << e.what();
    }
}
```

**Output (conceptually):**

```
Resource 3 released   ← func3 unwound
Resource 2 released   ← func2 unwound
Resource 1 released   ← func1 unwound
Caught: Error in func3
```

---

### **What Really Happens**

1️⃣ `func3()` throws exception  
2️⃣ `func3` ka stack frame destroy → r3 destructor called  
3️⃣ Control goes back to `func2` → r2 destructor  
4️⃣ Control goes back to `func1` → r1 destructor  
5️⃣ Finally `main()` catches the exception  

👉 LIFO rule: **jo last bana, woh pehle destroy**.

---

### **Key Points**

- ✔ Destructors **automatically call** hote hain  
- ✔ Cleanup always occurs **from bottom to top (stack order)**  
- ✔ Unwinding continues until a matching `catch` is found  
- ✔ RAII ensures resources release safely  
- ❌ Heap objects (`new`) auto-delete **nahi hote**

---

### **Pointer Problem (Danger Zone)**

```cpp
void dangerous() {
    int* ptr = new int[100];
    throw runtime_error("Error!");   // ❌ memory leak
}
```

Exception aayi → stack unwind hua →  
but pointer heap me tha, destructor nahi call hua.

---

### **Safer Version (manual cleanup)**

```cpp
void safe() {
    int* ptr = new int[100];
    try {
        throw runtime_error("Error!");
    }
    catch (...) {
        delete[] ptr;   // cleanup
        throw;          // rethrow
    }
}
```

---

### **Best Practice (RAII / Smart Pointers)**

```cpp
void best() {
    unique_ptr<int[]> ptr(new int[100]);
    throw runtime_error("Error!");   // cleanup automatic
}
```

👉 **Smart pointers = automatic delete during unwinding.**

---

### **Mental Model (short)**

- Exception → **rewind stack**
- Local objects → **auto destroy**
- Heap memory → **manual or smart pointer**
- Goal → **no resource leaks** during errors

## 🔹 6. RTTI (Runtime Type Information)  

### **📌 What is RTTI?**  

**RTTI** = mechanism jisse program **runtime par** yeh decide kar sakta hai:  

> “Yeh object actually **kaunsi class ka** hai?”  

It mainly works through:

1️⃣ `typeid` — get type info  
2️⃣ `dynamic_cast` — safe down-casting  

**Requirement:** class must be **polymorphic** (at least one `virtual` function).

---

### **📌 typeid Operator**

#### **Syntax:**

```cpp
typeid(expression)
typeid(type)
```

It returns a `type_info` object containing metadata about type.

---

### **Basic Usage**

```cpp
int x = 10;
double y = 3.14;

cout << typeid(x).name() << endl;
cout << typeid(y).name() << endl;

if (typeid(x) == typeid(int))
    cout << "x is int";
```

> Note: `name()` ka output compiler-specific hota hai.

---

### **📌 typeid with Polymorphic Classes**

```cpp
class Animal { public: virtual void sound() {} };
class Dog : public Animal {};
class Cat : public Animal {};
```

```cpp
Animal* p1 = new Dog();
Animal* p2 = new Cat();

cout << typeid(*p1).name();   // Dog
cout << typeid(*p2).name();   // Cat
cout << typeid(p1).name();    // Animal*
```

**Remember:**

- `typeid(*ptr)` → **actual object type** (runtime)  
- `typeid(ptr)` → pointer ka type (compile-time)

---

### **📌 Common Use Cases**

#### **1️⃣ Type Checking**

```cpp
void process(Animal* a) {
    if (typeid(*a) == typeid(Dog)) cout << "Processing Dog";
    else if (typeid(*a) == typeid(Cat)) cout << "Processing Cat";
}
```

#### **2️⃣ Debugging**

```cpp
cout << "Object type: " << typeid(*a).name();
```

#### **3️⃣ Factory Pattern**

```cpp
Animal* createAnimal(string t) {
    if (t=="dog") return new Dog();
    if (t=="cat") return new Cat();
    return nullptr;
}
```

---

### **📌 type_info Class (useful members)**

```cpp
const type_info& t = typeid(int);

t.name();        // readable name
t.hash_code();   // hash (C++11)
t.before(t2);    // ordering compare
```

Comparisons:

```cpp
typeid(int) == typeid(int);        // true
typeid(int) != typeid(double);     // true
```

---

### 📌 RTTI Performance Notes

- Small memory overhead  
- Some runtime cost  
- Practically: usually negligible  

**Use when:**  
✔ debugging/logging  
✔ reflection-like behavior  
✔ serialization/plugins  

**Avoid when:**  
❌ frequent type-checking (bad design smell)  
❌ place where virtual functions already solve it  
❌ critical performance paths  

👉 Hinglish:  
> “Agar virtual functions se kaam ho raha — RTTI mat ghusaao.”

---

### **📌 RTTI vs Virtual Functions**

#### ❌ Wrong pattern (forcing RTTI):

```cpp
if (typeid(*a) == typeid(Dog))  cout << "Woof!";
else if (typeid(*a) == typeid(Cat)) cout << "Meow!";
```

#### ✅ Correct pattern (polymorphism):

```cpp
class Animal { public: virtual void makeSound() = 0; };
class Dog   : public Animal { void makeSound(){ cout<<"Woof!"; } };
class Cat   : public Animal { void makeSound(){ cout<<"Meow!"; } };

Animal* a = new Dog();
a->makeSound();   // runtime dispatch
```

**Golden rule:** prefer **virtual functions first**, RTTI only when necessary.

---

## ⚠️ Common Mistakes & Important Points

### **Abstract Classes:**
```cpp
// ❌ Wrong
class Abstract {
    virtual void func() = 0;  // Private pure virtual
};

// ✅ Correct
class Abstract {
public:
    virtual void func() = 0;
    virtual ~Abstract() { }
};
```

### **Exception Handling:**
```cpp
// ❌ Wrong - Catch by value (slicing)
catch (exception e) { }

// ✅ Correct - Catch by reference
catch (exception& e) { }
catch (const exception& e) { }  // Even better
```

### **Stack Unwinding:**
```cpp
// ❌ Memory leak
void func() {
    Resource* r = new Resource();
    throw exception();  // r not deleted
}

// ✅ Use RAII
void func() {
    unique_ptr<Resource> r(new Resource());
    throw exception();  // Automatic cleanup
}
```

### **typeid:**
```cpp
// ❌ Non-polymorphic class
class Base { };  // No virtual function
typeid(*ptr);  // Compile-time type only

// ✅ Polymorphic class
class Base {
    virtual void func() { }
};
typeid(*ptr);  // Runtime type
```

---

## 🧪 Quick Review Questions

1. Abstract class aur interface mein kya difference hai?
2. Early binding fast kyun hai late binding se?
3. vtable aur vptr kya hain?
4. Stack unwinding mein destructors kis order mein call hote hain?
5. `typeid(*ptr)` aur `typeid(ptr)` mein kya difference hai?
6. Exception handling mein `catch(...)` kya karta hai?
7. Pure virtual function mein implementation kyun ho sakta hai?

---

## 📝 Exam-Style Questions

### **Short Answer:**
1. Explain abstract class with example.
2. Differentiate between early and late binding.
3. What is stack unwinding? Why is it important?
4. Write syntax for try-catch block.

### **Long Answer:**
1. Explain internal working of virtual functions with diagram.
2. Write a program demonstrating exception handling with multiple catch blocks.
3. Explain RTTI with typeid operator example.
4. Demonstrate stack unwinding with complete program.

### **Program Writing:**
1. Create abstract class Shape with pure virtual functions. Derive Circle and Rectangle.
2. Write program showing early vs late binding.
3. Write program with custom exception class.
4. Demonstrate typeid operator with polymorphic classes.

---

**Exam Tip:** Virtual functions = vtable + vptr. Exception handling = try-catch-throw. RTTI = typeid + dynamic_cast. Abstract class = pure virtual function! 📚