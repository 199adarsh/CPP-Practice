📦 **Chapter: Friend Functions & Operator Overloading**
(C++ – Advanced Features Series)

---

## 🧠 What is a Friend Function?

**Friend function** ek special function hai jo class ka member nahi hai, but phir bhi class ke **private aur protected members** ko access kar sakta hai.

**Real-life analogy:**
- Tumhare ghar ka darwaza normally locked hai
- Lekin tumhare best friend ko key di hai – wo andar aa sakta hai
- Wo family member nahi hai, but trusted access hai

**Why needed?**
- Kabhi-kabhi external functions ko private data access dena padta hai
- Operator overloading mein useful (jab dono operands ko access karna ho)
- Bridge banata hai between classes

---

## 🔹 Friend Function – Key Points

✅ Class ke andar `friend` keyword se declare karte hain
✅ Class ka member nahi hai (no `this` pointer)
✅ Private/protected members access kar sakta hai
✅ Object pass karke call karte hain (normal function ki tarah)
✅ Multiple classes ka friend ban sakta hai

---

## 🧪 Friend Function – Basic Syntax


### **Example 1: Friend Function with Multiple Classes**

```cpp
#include <iostream>
using namespace std;

class ClassB;  // Forward declaration

class ClassA {
private:
    int valueA;

public:
    ClassA(int v) : valueA(v) {}
    
    friend void compareValues(ClassA a, ClassB b);
};

class ClassB {
private:
    int valueB;

public:
    ClassB(int v) : valueB(v) {}
    
    friend void compareValues(ClassA a, ClassB b);
};

// Friend function accessing both classes
void compareValues(ClassA a, ClassB b) {
    if(a.valueA > b.valueB) {
        cout << "A is greater" << endl;
    } else if(a.valueA < b.valueB) {
        cout << "B is greater" << endl;
    } else {
        cout << "Both are equal" << endl;
    }
}

int main() {
    ClassA objA(50);
    ClassB objB(30);
    
    compareValues(objA, objB);
    
    return 0;
}
```

---

### **Example 2: Friend Class**

```cpp
#include <iostream>
using namespace std;

class Bank {
private:
    int balance;

public:
    Bank(int b) : balance(b) {}
    
    // Puri Auditor class ko friend bana diya
    friend class Auditor;
};

class Auditor {
public:
    void checkBalance(Bank &b) {
        cout << "Current Balance: " << b.balance << endl;
    }
    
    void adjustBalance(Bank &b, int amount) {
        b.balance += amount;
        cout << "New Balance: " << b.balance << endl;
    }
};

int main() {
    Bank account(5000);
    Auditor auditor;
    
    auditor.checkBalance(account);
    auditor.adjustBalance(account, 1000);
    
    return 0;
}
```

**Note:** Friend class ke saare member functions private data access kar sakte hain!

---

## 🧠 What is Operator Overloading?

**Operator overloading** matlab built-in operators (`+`, `-`, `*`, `==`, etc.) ko custom classes ke liye redefine karna.

**Real example:**
```cpp
Complex c1(3, 4);
Complex c2(1, 2);
Complex c3 = c1 + c2;  // '+' ko overload karke ye possible banaya!
```

**Normal case mein:**
```cpp
int a = 5, b = 10;
int c = a + b;  // Works fine (built-in types)
```

**Custom class ke liye:**
```cpp
Complex c3 = c1.add(c2);  // ❌ Boring!
Complex c3 = c1 + c2;     // ✅ Natural aur readable!
```

---

## 🔹 Operator Overloading – Key Rules

✅ **Member function** ya **friend function** ke roop mein overload kar sakte hain

✅ Built-in operators ke precedence/associativity **change nahi** kar sakte

✅ New operators create **nahi** kar sakte (jaise `**`, `@`)

✅ At least ek operand user-defined type ka hona chahiye

✅ `.`, `::`, `.*`, `?:`, `sizeof` ko overload **nahi** kar sakte

---

## 🧪 Unary Operator Overloading

**Unary operators** → Ek hi operand ke saath kaam karte hain:
- `++` (increment)
- `--` (decrement)
- `-` (unary minus)
- `!` (logical NOT)




Unary operators → **single operand** (`++`, `--`, `-`, `!`)

### Prefix `++`

```cpp
class Counter {
    int count;
public:
    Counter(int c=0):count(c){}

    // Prefix ++  → first increment, then return updated object
    Counter operator++() {
        ++count;
        return *this;
    }
};
```

### Postfix `++`

> Dummy `int` parameter separates postfix from prefix.

```cpp
// Postfix ++  → return old value, then increment
Counter operator++(int) {
    Counter temp = *this;   // store old state
    count++;                // increment later
    return temp;            // old object returned
}
```

### Unary minus `-`

```cpp
class Number {
    int value;
public:
    Number(int v=0):value(v){}

    // Unary minus → sign change
    Number operator-() {
        Number t;
        t.value = -value;
        return t;
    }
};
```

---

## Binary Operator Overloading

Binary → **two operands** (`+ - * /`, comparisons, assignment)

### `+` (member function)

```cpp
class Complex {
    int real, imag;
public:
    Complex(int r=0,int i=0):real(r),imag(i){}

    // Adds corresponding parts of two Complex numbers
    Complex operator+(Complex &c){
        return Complex(real + c.real, imag + c.imag);
    }
};
// c1 + c2  →  c1.operator+(c2)
```

### `+` (friend function)

```cpp
class Distance {
    int meters;
public:
    Distance(int m=0):meters(m){}

    // Friend allows access to private members
    friend Distance operator+(Distance d1, Distance d2);
};

// Adds meters of both objects
Distance operator+(Distance d1, Distance d2){
    return Distance(d1.meters + d2.meters);
}
```

**Member vs Friend**

* Member → `obj1.operator+(obj2)`
* Friend → `operator+(obj1, obj2)`

### `==` (equality)

```cpp
// Compare both coordinates
bool operator==(Point &p){
    return (x == p.x && y == p.y);
}
```


---

## 🧠 Advanced Operator Overloading


---

## 1️⃣ Assignment Operator (=)

> Deep copy + self-assignment check + return reference.

```cpp
class String {
    char* str;
    int length;

public:
    String(const char* s="");          // alloc + copy
    String(const String &s);           // deep copy (copy ctor)

    // Assignment operator
    String& operator=(const String &s){
        if(this == &s) return *this;   // avoid self-assign
        delete[] str;                  // free old memory
        length = s.length;
        str = new char[length+1];
        strcpy(str, s.str);            // deep copy
        return *this;                  // enable chaining
    }

    ~String(){ delete[] str; }
};
```

✔ Key ideas: self-check | delete old | deep copy | return `*this`

---

## 2️⃣ Subscript Operator ([])

> Use object like array + return **reference**.

```cpp
int& operator[](int index){
    if(index < 0 || index >= size){
        cout<<"Index out of bounds!\n";
        exit(1);
    }
    return arr[index];   // allows a[i] = 10;
}
```

---

## 3️⃣ Stream Operators (<< and >>)

> Usually implemented as **friend** functions.

```cpp
friend ostream& operator<<(ostream &out, const Complex &c){
    return out << c.real << " + " << c.imag << "i";   // chaining
}

friend istream& operator>>(istream &in, Complex &c){
    in >> c.real >> c.imag;   // read values
    return in;
}
```

---

## 4️⃣ Function Call Operator `()`

> Makes an object “callable”.

```cpp
int operator()(int x){
    return x * factor;
}
```

---

## 5️⃣ Arrow Operator (->)

> Smart-pointer–like behavior.

```cpp
Data* operator->(){
    return ptr;   // lets us call sp->display()
}
```

---

## 6️⃣ Comparison Operators

> Implement logically and mark as `const`.

```cpp
bool operator==(const Money &m) const { return rupees == m.rupees; }
bool operator!=(const Money &m) const { return !(*this == m); }
bool operator<(const Money &m)  const { return rupees <  m.rupees; }
```

(You can derive the rest similarly.)

---

## 7️⃣ Type Conversion Operators

> Convert object → built-in types.

```cpp
operator int()   { return (int)value; }
operator double(){ return value; }
```

---

### 🔎 Quick revision chart

| Operator          | Return                   | Common use            |
| ----------------- | ------------------------ | --------------------- |
| `=`               | reference (`*this`)      | deep copy + chaining  |
| `[]`              | reference                | read/write like array |
| `<< >>`           | stream reference         | chaining              |
| `() `             | custom function behavior | functor               |
| `->`              | pointer                  | smart pointers        |
| `== < …`          | bool                     | comparisons           |
| `operator type()` | value                    | implicit conversion   |



---

## ⚠️ Common Confusions

### **1. Friend Function vs Member Function**
```cpp
// Member function (implicit first parameter)
Complex operator+(Complex &c) {
    // 'this' available
}

// Friend function (explicit both parameters)
friend Complex operator+(Complex &c1, Complex &c2) {
    // No 'this' pointer
}
```

### **2. Prefix vs Postfix Increment**
- Prefix: `operator++()`
- Postfix: `operator++(int)` ← dummy parameter
- Postfix zyada memory use karta hai (copy banata hai)

### **3. Return by Value vs Reference**
```cpp
// Return by value (new object)
Complex operator+(Complex &c) {
    return temp;  // OK
}

// Return by reference (assignment ke liye)
Complex& operator=(const Complex &c) {
    return *this;  // Chaining ke liye
}
```

### **4. Self-Assignment Check**
```cpp
String& operator=(const String &s) {
    if(this == &s) return *this;  // Zaroori hai!
    // ... rest of code
}
```

### **5. Stream Operators Must be Friend**
```cpp
// ❌ Wrong (member function nahi ban sakta)
ostream operator<<(ostream &out) { }

// ✅ Correct (friend function)
friend ostream& operator<<(ostream &out, const Complex &c);
```

### **6. Operators You CANNOT Overload**
- `.` (dot operator)
- `::` (scope resolution)
- `.*` (pointer to member)
- `?:` (ternary)
- `sizeof`
- `typeid`

### **7. At Least One Operand Must be User-Defined**
```cpp
// ❌ Wrong (dono built-in types)
int operator+(int a, int b) { }

// ✅ Correct
Complex operator+(Complex &c1, Complex &c2) { }
```

---

## 🧠 Mindset Rules

✅ **Friend functions** → Trusted external access, useful for operator overloading

✅ **Operator overloading** → Make code natural and readable

✅ **Unary operators** → Ek operand, easy syntax

✅ **Binary operators** → Do operands, member ya friend

✅ **Assignment operator** → Deep copy + self-assignment check + return reference

✅ **Stream operators** → Always friend, always return stream reference

**Golden Rule:** *Operator overloading ka matlab natural syntax dena, magic nahi karna!*

---

## 🧪 Practice Zone

### **Basic Level**

1. **Friend Function:**
   ```cpp
   // Rectangle class banaao (length, width private)
   // Friend function calculatePerimeter() banao
   ```

2. **Unary Minus:**
   ```cpp
   // Point class banaao (x, y coordinates)
   // Unary minus overload karke coordinates ko negate karo
   ```

3. **Prefix Increment:**
   ```cpp
   // Score class banaao
   // Prefix ++ overload karo to increase score by 10
   ```

### **Intermediate Level**

4. **Binary Addition:**
   ```cpp
   // Time class banaao (hours, minutes)
   // + operator overload karo
   // Example: Time t1(2, 30) + Time t2(1, 45) = Time(4, 15)
   ```

5. **Comparison Operators:**
   ```cpp
   // Date class banaao (day, month, year)
   // ==, !=, <, > operators overload karo
   // Compare dates properly
   ```

6. **Stream Operators:**
   ```cpp
   // Student class (name, rollNo, marks)
   // << and >> operators overload karo
   // Input/output cleanly
   ```

### **Advanced Level**

7. **Complete Matrix Class:**
   ```cpp
   // Matrix class with:
   // - Dynamic 2D array
   // - +, -, * operators (matrix operations)
   // - == operator (compare matrices)
   // - << operator (display matrix)
   // - [] operator (access elements)
   ```

8. **String Class:**
   ```cpp
   // Custom String class with:
   // - Dynamic char array
   // - + operator (concatenation)
   // - == operator (comparison)
   // - << and >> operators
   // - [] operator (character access)
   // - Assignment operator (deep copy)
   ```

9. **Fraction Class:**
   ```cpp
   // Fraction class (numerator, denominator)
   // Overload: +, -, *, / (proper fraction math)
   // Simplify fractions automatically
   // Example: 1/2 + 1/3 = 5/6
   ```

10. **Smart Pointer Class:**
    ```cpp
    // Template-based smart pointer
    // Overload: *, ->, = operators
    // Automatic memory management
    // Reference counting
    ```

---

**Ab practice karo aur master bano! 💪**

**Pro Tip:** Operator overloading ko naturally use karo. Agar code confusing lag raha hai, toh simple function use karo. Readability > Cleverness! 🚀