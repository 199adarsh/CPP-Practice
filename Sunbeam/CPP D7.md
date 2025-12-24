

━━━━━━━━━━━━━━━━━━━━━━
📦 **Topic: Class in C++**

🧠 **What is a Class?**
A class is a **blueprint** or **template** for creating objects.

Simple words 👇
Class = design
Object = real thing

Jaise:

* Class = Car design
* Object = BMW, Audi, etc.

---

🔹 **Important Points**

* Class divided into 2 groups:  1.Data members &  2.Member functions (methods)
* Memory is allocated only when **object** is created

---

🧪 **Short Example**

```cpp
class Student {
public:
    int age;        // data members 
    void show() {   // member functions
        cout << age;
    }
};
```


---

━━━━━━━━━━━━━━━━━━━━━━
📦 **Topic: Constructor & Destructor (Combined)**

🧠 **Constructor**
Constructor is a **special function** that runs **automatically** when object is created.

Kaam:

* initialize data
* setup object

---

🧠 **Destructor (Reverse kaam)**
Destructor runs **automatically** when object is destroyed.

Kaam:

* clean up memory
* close resources

---

🔹 **Important Points (EXAM GOLD)**

* Constructor name = class name
* No return type
* Runs automatically
* Destructor name = `~ClassName`
* Destructor bhi automatic
* One object → constructor first, destructor last

---

🧪 **Short Example**

```cpp
class Test {
public:
    Test() {
        cout << "Constructor";
    }
    // remaining code...
    ~Test() {
        cout << "Destructor";
    }
};
```

---

━━━━━━━━━━━━━━━━━━━━━━
📦 **Topic: Getter & Setter (Combined)**

🧠 **Why Getter & Setter?**
Direct data access is **dangerous**. Getter & setter are used for  **safe access**

Getter & Setter give:

* control
* security
* validation

---

🔹 **Getter (Read-only)**

* Used to **get** value
* Mostly `const`
* No modification


🔹 **Setter (Write-only)**

* Used to **set/update** value
* Can apply checks

---

🧪 **Short Example**

```cpp
class Student {
private:
    int age;

public:
    void setAge(int a) {
        if(a > 0)
            age = a;
    }

    int getAge() const {
        return age;
    }
};
```

---

🧠 Explanation:

* `age` is protected
* `setAge()` validates input
* `getAge()` only reads data


---


━━━━━━━━━━━━━━━━━━━━━━

## 📦 C++ OOP Keywords — **FINAL COMBINED NOTES**

(`this` • `static` • `const`)
━━━━━━━━━━━━━━━━━━━━━━

---

## 🔹 `this` Pointer

**Meaning:** address of current object
**Use:** resolve data member & parameter conflict

### IMP Points

* Available **only in non-static functions**
* Represents **current object**
* Used with `->`

```cpp
class A {
    int x;
public:
    void set(int x) {
        this->x = x;
    }
};

```

---

## 🔹 `static` Data Member

**Meaning:** class-level shared variable

### IMP Points

* **Single copy** for all objects
* Memory at **class level**
* Object independent
* **Must initialize outside class**
* Best access: `ClassName::variable`

```cpp
class box {
public:
    static int cnt;
};

int box::cnt = 0;  // must initialize this outside class

int main() {
    cout << box::cnt;
}
```

---

## 🔹 `static` Member Function

**Meaning:** class-level function

### IMP Points

* Object not required
* Call using `ClassName::function()`
* Access **only static data**
* `this` pointer ❌

```cpp
class A {
public:
    static void show() {
        cout << "Static Function";
    }
};

int main() {
    A::show();
}
```

---

## 🔹 `const` Data Member

**Meaning:** value fixed, cannot change

### IMP Points

* **Must be initialized**
* Only via **constructor initializer list**
* Modify later ❌

```cpp
class A {
public:
    const int x;
    A(int a) : x(a) {}
};
```

---

## 🔹 `const` Member Function

**Meaning:** function will not modify object

### IMP Points

* Cannot change data members
* Used for getters / display
* Improves safety

```cpp
class A {
    int x = 10;
public:
    int get() const {
        return x;
    }
};
```

---

## 🔹 `const` Object

**Meaning:** read-only object

### IMP Points

* Data modification ❌
* Can call **only const functions**
* Non-const functions ❌

```cpp
const A obj;
obj.get();   // ✅
```

---

━━━━━━━━━━━━━━━━━━━━━━

## 🔥 ACCESS RULES (VERY IMP)

━━━━━━━━━━━━━━━━━━━━━━

| Feature         | Access                   |
| --------------- | ------------------------ |
| static data     | `ClassName::var`         |
| static function | `ClassName::func()`      |
| const data      | `object.var` (read only) |
| const function  | `object.func()`          |
| const object    | only const functions     |
| this pointer    | `this->var`              |

---

━━━━━━━━━━━━━━━━━━━━━━

## 🧠 ONE-LINE MEMORY TRICK

━━━━━━━━━━━━━━━━━━━━━━

* `this` → **current object**
* `static` → **class level**
* `const` → **no change**

---
