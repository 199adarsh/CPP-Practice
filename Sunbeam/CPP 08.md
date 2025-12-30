

# ⭐ Operator Overloading in C++


---

## 🧠 What is Operator Overloading?

Operator overloading lets us **give operators ( + , − , == , etc.) custom meaning**
for **user-defined types (classes)**.

👉 Simple idea:

> “Same operator — different work — based on data type.”

Example:

* `+` adds numbers
* but we can make `+` also **add objects** (like complex numbers, vectors, strings etc.)

---

## 🎯 Why do we need it?

* Makes code **readable & natural**
* Works like built-in types
* Better for mathematical/logic-type classes

👉 Hinglish tip:

> “Class ke objects ke saath operators ko friend jaisa bana dete ho.”

---

## 🧪 Basic Syntax

We overload using the **`operator` keyword** inside a class.

```cpp
class A {
public:
    A operator+(A obj);
};
```

Function name becomes:

```
operator+
```

---

## 🧩 Example: Adding Two Objects

```cpp
class Complex {
public:
    int a, b;

    Complex(int x, int y) {
        a = x; b = y;
    }

    Complex operator+(Complex c) {
        return Complex(a + c.a, b + c.b);
    }
};
```

Usage:

```cpp
Complex c1(2, 3), c2(4, 5);
Complex c3 = c1 + c2;
```

Now `+` works **just like numbers** 👍

---

## 📌 Rules (Very Important)

* Only **existing operators** can be overloaded
  (you can’t invent new ones)
* At least **one operand must be a user-defined type**
* Operator overloading **does not change precedence**
* It should be used for **meaningful logic only**

👉 Don’t abuse it — warna code unreadable ho jaata hai.

---

## 🔥 Common Operators You Can Overload

Arithmetic

```
+  -  *  /  %
```

Comparison

```
==  !=  <  >  <=  >=
```

Assignment

```
=
```

Unary

```
++  --  !
```

Input/Output

```
<<  >>
```

(very common for printing objects)

---

## 🧪 Example: Overloading `<<` (cout)

```cpp
class Student {
public:
    int age;

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Age: " << s.age;
        return out;
    }
};
```

Now:

```cpp
Student s;
s.age = 21;
cout << s;
```

---

## 🧪 Unary Operator Example ( ++ )

```cpp
class Counter {
public:
    int value;

    Counter(int v) : value(v) {}

    void operator++() {
        value++;
    }
};
```

Usage:

```cpp
Counter c(5);
++c;
```

---

## ⚠️ Confusing Points (Hinglish clarity)

* **Function overloading ≠ operator overloading**
  Function overloading = same function name, different params
  Operator overloading = customize operators

* **Overloading doesn’t create new operators**
  Bas existing operator ka behavior change hota hai.

* **Avoid overloading if logic becomes weird**
  Code readable rehna chaiye.

---

## 🚫 Operators You CANNOT Overload

```
.      (dot)
?:     (ternary)
::     (scope resolution)
sizeof
typeid
```

(Basically language-control operators)

---

## 🧠 Quick Summary (Cheat Sheet)

| Concept              | Meaning                            |
| -------------------- | ---------------------------------- |
| Operator overloading | Give operators meaning for objects |
| Where                | Inside class (usually)             |
| Keyword              | `operator`                         |
| Why                  | Readable, natural code             |
| Avoid                | Over-complicated overloads         |

---

## 🧪 Practice Tasks

1️⃣ Overload `+` for a `Time` class (hours/minutes)
2️⃣ Overload `==` to compare two `Student` objects
3️⃣ Overload `<<` to print a `Point(x, y)`
4️⃣ Overload `++` to increase counter value

---

### ☕ Final Takeaway

> **Operator overloading = same operator, meaningful behavior for objects.
> Use it where it makes code easier — not confusing.**

---
