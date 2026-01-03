## 🔹 Pure Virtual Function

**Definition:**
A **pure virtual function** is a virtual function that has **no implementation in the base class** and is declared using `= 0`.
It forces all derived classes to **provide their own implementation**.

```cpp
class Shape {
public:
    virtual void draw() = 0;
};
```

👉 Hinglish:

> “Base bolta — *ye function tu implement karega hi karega*.”

---

## 🔹 Abstract Class

**Definition:**
An **abstract class** is a class that **cannot be instantiated** and is used only as a **blueprint for derived classes**.
It contains **at least one pure virtual function**.

```cpp
class Shape {
public:
    virtual void draw() = 0;
};
```

👉 Use for **rules/interfaces** instead of direct objects.

---

## 🔹 Early Binding (Static Binding)

**Definition:**
Early binding is when a function call is **resolved at compile-time** based on the **pointer/reference type**, not the actual object.
It applies to **non-virtual functions**.

```cpp
Base* b = new Derived();
b->show();     // Base::show() (compile-time)
```

👉 Fast, no runtime lookup.

---

## 🔹 Late Binding (Dynamic Binding)

**Definition:**
Late binding is when a function call is **resolved at runtime** based on the **actual object type**.
It occurs only with **virtual functions**.

```cpp
Base* b = new Derived();
b->show();     
// Derived::show() (runtime)
```

👉 Enables **runtime polymorphism**.

---

## 🔹 Virtual Function — Internal Execution

**Definition:**
A **virtual function** uses a mechanism called **vtable (virtual table)** and **vptr (virtual pointer)** so that the correct overridden function is chosen **at runtime**, depending on the actual object.

### Simple flow:

1️⃣ Each polymorphic class has a **vtable**
2️⃣ Each object stores a hidden **vptr → points to vtable**
3️⃣ When calling a virtual function:

```
object -> vptr -> vtable -> correct function address
```

👉 Hinglish:

> “Program runtime par table dekh ke decide karta hai — kaunsa function call hoga.”

---

### ☕ Final Quick Recap

* Pure virtual → no implementation, must override
* Abstract class → blueprint, no objects
* Early binding → compile-time decision
* Late binding → runtime decision
* Virtual execution → vtable + vptr choose function dynamically



---

## 🔹 RTTI — `typeid` Operator

**Definition:**
`typeid` is an operator in C++ used to obtain **runtime type information** about an expression or type.
It returns a reference to a `type_info` object that describes the type.

👉 In simple words:

> “`typeid` batata hai — yeh object **actually kis type ka** hai.”

---

### **📌 Syntax**

```cpp
typeid(expression)
typeid(type)
```

It returns:

```cpp
const type_info&
```

---

### **📌 Basic Example**

```cpp
int x = 5;
cout << typeid(x).name();    // prints type name (e.g., "int")
```

⚠️ Output of `name()` **compiler-dependent** hota hai.

---

### **📌 With Polymorphism (real use)**

```cpp
class Animal { public: virtual void speak() {} };
class Dog : public Animal {};
class Cat : public Animal {};

Animal* p = new Dog();
cout << typeid(*p).name();   // Dog (runtime type)
```

Important difference:

* `typeid(*p)` → **actual object type**
* `typeid(p)`  → pointer type (`Animal*`)

---

### **📌 Requirement**

RTTI works **fully** only when the class is **polymorphic**
(i.e., has at least one `virtual` function).

---

### **📌 Common Uses**

✔ debugging / logging <br>
✔ type checking in rare cases<br>
✔ plugin or serialization systems<br>

👉 But:

> “Agar virtual functions se kaam ho raha — RTTI ko mat ghusaao.”

---

### **📌 Quick Example Check**

```cpp
if (typeid(*p) == typeid(Dog))
    cout << "Dog detected!";
```

---

### **Summary Line (memorize)**

> **`typeid` provides runtime type information by returning a `type_info` object describing the type of an expression or type.**
