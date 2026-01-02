📦 **Chapter: Modular Approach, Composition, Dynamic Memory & Copy Constructor**
(C++ – Real-World Coding Series)

---

## 🧠 What is Modular Programming?

**Modular programming** matlab apna code ko alag-alag files mein organize karna – jaise ek bade project ko chote-chote manageable pieces mein divide kar dete hain.

Think of it like this:
- Ek book ko chapters mein divide karte hain (easy to read, easy to manage)
- Similarly, C++ code ko **header files (.h)** aur **implementation files (.cpp)** mein divide karte hain

**Why?**
- Code reusable ho jata hai
- Debugging easy ho jati hai
- Large projects maintain karna simple ho jata hai
- Team mein kaam karna asaan ho jata hai

---

## 🔹 Header Files (.h) vs Implementation Files (.cpp)

### **Header File (.h)** – The Declaration File
Ye file sirf **declarations** contain karti hai:
- Function prototypes
- Class declarations
- Constants
- Include guards (to prevent multiple inclusions)

### **Implementation File (.cpp)** – The Definition File
Ye file actual **logic aur code** contain karti hai:
- Function definitions
- Member function implementations
- Main logic

**Simple rule:** Header mein declare karo, CPP mein define karo!

---

## 🧪 Modular Approach – Syntax Example

### **student.h** (Header file)
```cpp
#ifndef STUDENT_H  // Include guard start
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks;

public:
    // Constructor declaration
    Student(string n, int r, float m);
    
    // Member function declarations
    void display();
    float getMarks();
};

#endif  // Include guard end
```

**Samjho kya ho raha hai:**
- `#ifndef STUDENT_H` → Agar ye file pehle include nahi hui hai, tab hi include karo
- `#define STUDENT_H` → Ab isko mark kar do as "included"
- `#endif` → Include guard khatam
- Sirf declarations hain, definitions nahi

---

### **student.cpp** (Implementation file)
```cpp
#include "student.h"
#include <iostream>
using namespace std;

// Constructor definition
Student::Student(string n, int r, float m) {
    name = n;
    rollNo = r;
    marks = m;
}

// Member function definition
void Student::display() {
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "Marks: " << marks << endl;
}

float Student::getMarks() {
    return marks;
}
```

**Dhyan do:**
- `#include "student.h"` → Apni header file include kari
- `Student::` → Ye batata hai ki ye function Student class ka hai
- Yahan actual logic likha hai

---

### **main.cpp** (Main program file)
```cpp
#include "student.h"
#include <iostream>
using namespace std;

int main() {
    // Student object banao
    Student s1("Rahul", 101, 89.5);
    
    s1.display();
    
    cout << "Total marks: " << s1.getMarks() << endl;
    
    return 0;
}
```

**To compile:**
```bash
g++ main.cpp student.cpp -o program
./program
```
<br><br><br><br>
---

## 🧠 What is Composition?

**Composition** matlab **"has-a" relationship** – jab ek class ke andar dusri class ka object hota hai.

**Real-life example:**
- Car **has-a** Engine
- House **has-a** Door
- Student **has-a** Address

Composition mein parent class ke bina child class ka koi existence nahi hota (strong relationship).

---

## 🧪 Composition – Syntax Example

```cpp 

#include <iostream>
using namespace std;

class Address {
    string city;
    int pincode;

public:
    Address(string c, int p) : city(c), pincode(p) {}
    void show() { cout << city << " - " << pincode << endl; }
};

//------ address class end ------

class Student {
    string name;
    Address addr;   // Student HAS-A Address // inherited the object fro Address class

public:
    Student(string n, string c, int p) : name(n), addr(c, p) {}
    void show() {
        cout << name << endl;
        addr.show();
    }
};

int main() {
    Student s("Priya", "Delhi", 110001);
    s.show();
}


```
**Output:**
```
Name: Priya
City: Delhi, Pincode: 110001
```

**Samjho:**
- `Student` class ke andar `Address` class ka object hai
- Student constructor mein initializer list use karke Address ko initialize kiya
- Agar Student destroy ho jaye, Address bhi automatically destroy ho jayega

<br><br><br><br>
---

## 🧠 What is Dynamic Memory Allocation?

**Dynamic memory** matlab runtime pe memory allocate karna – jab aapko compile time pe pata nahi hai kitni memory chahiye.

**Stack vs Heap:**
- **Stack memory** → Automatic, fixed size, function scope
- **Heap memory** → Manual allocation using `new`, flexible size, manual deallocation using `delete`

**Important operators:**
- `new` → Memory allocate karo (heap pe)
- `delete` → Single object ka memory free karo
- `delete[]` → Array ka memory free karo

---

## 🧪 Dynamic Memory – Syntax Examples

### **Single Object Allocation**
```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a) : name(n), age(a) {
        cout << "Constructor: " << name << endl;
    }

    ~Student() {
        cout << "Destructor: " << name << endl;
    }
};

int main() {
    Student* s = new Student("Amit", 20);   // dynamically created object

    cout << s->name << " " << s->age << endl;  // use -> for pointer object

    delete s;   // must free memory (destructor runs)
}


```
**Output:**
```
Constructor called for Amit
Name: Amit
Age: 20
Destructor called for Amit
```

---

### **Dynamic Array Allocation**

```cpp 

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int* marks = new int[n];      // dynamic array (new [])

    for (int i = 0; i < n; i++)
        cin >> marks[i];

    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";

    delete[] marks;               // free dynamic array (delete[])
}


```
**Dhyan do:**
- Array ke liye `new int[n]` use kiya
- Free karne ke liye `delete[]` use kiya (not just `delete`)

---

### **Dynamic 2D Array**
```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;
    
    // Allocate array of pointers
    int** arr = new int*[rows];
    
    // Allocate each row
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    // Fill array
    int value = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = value++;
        }
    }
    
    // Display
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // Free memory (in reverse order)
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];  // First delete each row
    }
    delete[] arr;  // Then delete the array of pointers
    
    return 0;
}
```
<br><br><br><br>
---

## 🧠 What is Copy Constructor?

**Copy constructor** wo special constructor hai jo ek object ko doosre object se copy karne ke liye use hota hai.

**Automatically called jab:**
1. Object ko value se pass karte hain function mein
2. Object ko return karte hain function se
3. Object ko doosre object se initialize karte hain

**Syntax:**
```cpp
ClassName(const ClassName &obj)
```

---

## 🧪 Copy Constructor – Types

### **1. Shallow Copy (Default)**
Compiler automatically banata hai – bas values copy karta hai

```cpp

#include <iostream>
using namespace std;

class Student {
public:
    int* marks;

    Student(int m) { 
        marks = new int(m); 
    }

    void display() {
         cout << *marks << endl;
    }
};

int main() {
    Student s1(90);
    Student s2 = s1;   // shallow copy (same pointer)

    *s2.marks = 95;    // modifies BOTH

    s1.display();      // 95  (bad!)
    s2.display();      // 95
}


```
**Problem:** Dono objects same memory location point kar rahe hain! ❌

---

### **2. Deep Copy (Custom)**
Alag memory allocate karke values copy karo

```cpp

#include <iostream>
using namespace std;

class Student {
public:
    int* marks;          // pointer that will store address of heap memory

    // Constructor: allocate memory and store value
    Student(int m) {
        marks = new int(m);   // new memory created on heap, value stored
    }

    // Copy constructor (DEEP COPY)
    Student(const Student &s) {
        marks = new int(*s.marks);   // new memory + copy value (not pointer)
    }

    void display() {
        cout << *marks << endl;      // print value stored at pointer
    }
};

int main() {
    Student s1(90);      // object created, marks = 90

    Student s2 = s1;     // deep copy → s2 gets its own memory
    Student s2 (s1);     // alternate (easy) way for deep copy


    *s2.marks = 95;      // change only s2's marks

    s1.display();        // prints 90 (unchanged)
    s2.display();        // prints 95 (separate copy)

    return 0;
}

```
**Ab sahi hai! Dono objects ke paas alag memory hai.** ✅
<br><br><br><br>
---

## ⚠️ Common Confusions

### **1. Include Guards**
- Hamesha header files mein `#ifndef`, `#define`, `#endif` use karo
- Ye multiple inclusions se bachata hai

### **2. new vs delete**
- `new` use kiya toh `delete` zaroori hai!
- `new[]` ke liye `delete[]` use karo
- Memory leak se bacho!

### **3. Shallow vs Deep Copy**
- Dynamic memory ke saath hamesha **deep copy** implement karo
- Default copy constructor shallow copy karti hai

### **4. Arrow vs Dot Operator**
- Object ke liye → `obj.member`
- Pointer ke liye → `ptr->member`

### **5. Composition Initialization**
- Member objects ko constructor initializer list mein initialize karo
- Constructor body mein initialize karne se error aa sakta hai

### **6. Memory Leak**
```cpp
int* ptr = new int[100];
// delete[] ptr;  // Ye bhool gaye? Memory leak! ❌
```

### **7. Dangling Pointer**
```cpp
int* ptr = new int(10);
delete ptr;
cout << *ptr;  // Danger! Already deleted memory access kar rahe ho ❌
```

---

## 🧠 Mindset Rules

✅ **Modular approach** → Code ko organize rakho, team work easy ho

✅ **Composition** → "has-a" relationship banao, code reusable banao

✅ **Dynamic memory** → Runtime flexibility, but responsibility tumhari hai

✅ **Deep copy** → Dynamic memory ke saath hamesha implement karo

✅ **Memory management** → Har `new` ke baad `delete` zaroor karo

**Golden Rule:** *New kiya toh Delete karo, Allocate kiya toh Free karo!*

---

## 🧪 Practice Zone

### **Basic Level**

1. **Modular Practice:**
   - `calculator.h` aur `calculator.cpp` banaao with functions: add, subtract, multiply, divide
   - `main.cpp` mein use karo

2. **Include Guards:**
   - Kya hoga agar include guards na ho? Explain with example

3. **Composition:**
   - `Engine` class banaao (horsepower, type)
   - `Car` class banaao jo Engine ka object contain kare
   - Display car details with engine info

### **Intermediate Level**

4. **Dynamic Array:**
   ```cpp
   // Runtime pe size input lo aur array create karo
   // Array mein even numbers store karo (2, 4, 6...)
   // Display karo aur memory free karo
   ```

5. **Deep Copy Constructor:**
   ```cpp
   // Bank Account class banaao with dynamic balance pointer
   // Deep copy constructor implement karo
   // Test karo: ek account se doosra copy karo, balance change karo
   ```

6. **Dynamic 2D Array:**
   - 2D matrix (rows×cols) dynamic allocate karo
   - Identity matrix create karo (diagonal pe 1, baaki 0)
   - Display aur free karo

### **Advanced Level**

7. **Complete Modular Project:**
   - **book.h / book.cpp** → Book class (title, author, price, ISBN)
   - **library.h / library.cpp** → Library class jo books ka array contain kare (composition + dynamic allocation)
   - **main.cpp** → Menu-driven program (add book, display all, search by author)

8. **Memory Management Challenge:**
   ```cpp
   // Student class with:
   // - name (string)
   // - subjects (dynamic array of strings)
   // - marks (dynamic array of int)
   // Implement: Constructor, Copy Constructor, Destructor
   // Test: Create student, copy it, modify copy, check original
   ```

---


