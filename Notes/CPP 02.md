
## Function Overloading

**Definition (1 line):**
Same function name, **inputs alag**, jaise ek hi remote se TV, AC, fan control karna.

**Small Example:**

```cpp
int add(int a, int b) {
    return a + b;   // int add
}

double add(double a, double b) {
    return a + b;   // double add
}

add(2, 3);      // calls int version
add(2.5, 3.5);  // calls double version
```

**Tips ☕️**

* ❌ Sirf return type change karke overload nahi hota
* ⚠️ Default arguments ke saath overload mat karo
* Same kaam, different input → overloading use karo

---

## Class & Object

**Definition (1 line):**
**Class** = blueprint (ghar ka design), **Object** = real ghar jo bana.

**Small Example:**

```cpp
class Car {
public:
    int speed;
};

Car c1;      // object of class Car
c1.speed = 100;
```

**Tips ☕️**

* Class ke end me `;` lagta hai ❗
* Class define hoti hai, object use hota hai
* Ek class se multiple objects ban sakte hain

---

## Data Members & Member Functions

**Definition (1 line):**
Class ke andar ke variables = **data members**,
aur andar ke functions = **member functions**.

**Small Example:**

```cpp
class Student {
private:
    int roll;        // data member
public:
    void set(int r) { // member function
        roll = r;
    }
};
```

**Tips ☕️**

* Data members mostly `private` rakho
* Member functions data ko access kar sakti hain
* Getter / setter pattern use karo

---

## Types of Member Functions

**Definition (1 line):**
Class ke different kaam ke functions, jaise office me different roles.

**Small Example:**

```cpp
class Demo {
public:
    Demo() { }          // constructor
    ~Demo() { }         // destructor

    void show() const { // const function
        // data change nahi karega
    }

    static void info() {
        // object ki zarurat nahi
    }
};
```

**Tips ☕️**
### Constructor & Destructor

### Constructor

**Definition (1 line):**
Constructor ek special function hota hai jo **object bante hi automatically call** hota hai — jaise **naya phone on karte hi basic setup** ho jana.

**Small Example:**

```cpp
class Student {
    int roll;
public:
    Student(int r) {   // constructor
        roll = r;      // object ko initial value mil rahi
    }
};
```

**Use Case / Tips ☕️**

* Object ko **initial state** dene ke liye
* Variables ko **garbage value se bachane** ke liye
* File, memory, resource open karne ke liye
* Class ke naam jaisa hota hai
* ❌ return type nahi hota

---

### Destructor

**Definition (1 line):**
Destructor ek special function hota hai jo **object destroy hone se pehle call** hota hai — jaise **phone band karte time apps close hona**.

**Small Example:**

```cpp
class Student {
public:
    ~Student() {   // destructor
        // cleanup code
    }
};
```

**Use Case / Tips ☕️**

* **Memory free** karne ke liye
* File / resource close karne ke liye
* `~` symbol se start hota hai
* Sirf **ek destructor** hota hai
* ❌ overload nahi hota


---

## Constructor Initializer List

**Definition (1 line):**
Constructor se pehle data initialize karne ka proper tareeqa,
jaise exam form pehle fill karna, baad me submit.

**Small Example:**

```cpp
class Car {
    const int speed;
public:
    Car(int s) : speed(s) { } // correct way
};
```

**Tips ☕️**

* `const` aur reference ke liye **mandatory**
* Body ke andar assign nahi kar sakte
* Efficient aur clean code hota hai

---





<br><br><br><br>
## 11. Function Overloading

**Definition:** Multiple functions with the same name but different parameters (like having different "print" buttons - one for color, one for black-and-white, one for double-sided).<br>
Same function name, parameters alag → compiler khud samajh jaata hai kaunsa call karna hai.


**Syntax:**
```cpp
return_type function_name(type1 param1);
return_type function_name(type2 param2);
return_type function_name(type1 param1, type2 param2);
```

**Example:**
```cpp
#include <iostream>
#include <string>

// Overloaded functions - same name, different parameters
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

void display(int value) {
    std::cout << "Integer: " << value << "\n";
}

void display(double value) {
    std::cout << "Double: " << value << "\n";
}

void display(const std::string& value) {
    std::cout << "String: " << value << "\n";
}

int main() {
    std::cout << add(5, 3) << "\n";           // Calls int version -> 8
    std::cout << add(5.5, 3.2) << "\n";       // Calls double version -> 8.7
    std::cout << add(1, 2, 3) << "\n";        // Calls 3-parameter version -> 6
    
    display(42);                               // Calls int version
    display(3.14);                             // Calls double version
    display("Hello");                          // Calls string version
    
    return 0;
}
```


**Key Points:**

* Overloading = **same name, different parameters**
* **Return type alone** se overloading ❌
* Compiler **best match** choose karta hai
* **Parameter order matters**
* `const` / reference se bhi overload ho sakta hai
* **Default arguments** ambiguity laa sakte hain
* Kuch operators overload nahi hote: `:: . .* ?: sizeof`

**Common Mistakes:**

* Sirf return type change karna ❌
* Default argument + overload ❌
* `int` vs `long` jaise similar types ❌
* Bahut zyada overloads → **templates use karo**



---

## 12. Class & Object

### Class & Object ☕️ (Very Short)

* **Class** → blueprint / user-defined type
* **Object** → class ka instance (variable)

**Why use:**

* Data + functions together
* OOP implement karne ke liye
* Code reuse
* Program ko structured banana
* Data control (`public / private`)


**Syntax:**
```cpp
class ClassName {
    // Access specifiers: private (default), public, protected
private:
    // Data members
public:
    // Member functions
};

// Creating objects
ClassName objectName;           // Stack allocation
ClassName* ptr = new ClassName; // Heap allocation
```

**Example:**
```cpp
#include <iostream>
#include <string>

class Car {
private:
    std::string brand;
    int year;
    double price;

public:
    // Constructor
    Car(std::string b, int y, double p) : brand(b), year(y), price(p) {}
    
    // Member functions
    void displayInfo() {
        std::cout << "Brand: " << brand 
                  << ", Year: " << year 
                  << ", Price: $" << price << "\n";
    }
    
    void updatePrice(double newPrice) {
        if (newPrice > 0) {
            price = newPrice;
        }
    }
    
    std::string getBrand() const {
        return brand;
    }
};

int main() {
    // Creating objects
    Car car1("Toyota", 2020, 25000.0);
    Car car2("Honda", 2022, 30000.0);
    
    // Using objects
    car1.displayInfo();
    car2.displayInfo();
    
    car1.updatePrice(23000.0);
    std::cout << "After update: ";
    car1.displayInfo();
    
    // Dynamic allocation
    Car* car3 = new Car("Tesla", 2023, 45000.0);
    car3->displayInfo();
    delete car3;
    
    return 0;
}
```

### Class – Important Points (One-line each ☕️)

* **Class members default private** → struct ke members public hote hain
* **Access specifiers** → `private` (hide), `public` (use), `protected` (inherit)
* **Stack vs Heap objects** → normal vs `new` se bane
* **`.` vs `->`** → object ke liye `.`, pointer ke liye `->`
* **OOP support** → encapsulation, inheritance, polymorphism
* **Multiple objects allowed** → same class, different instances
* **Data members per object** → har object ka apna data
* **Member functions shared** → ek hi copy sab use karte hain
* **Forward declaration** → class ko pehle declare kar sakte ho

---

### Common Mistakes (One-line)

* **Class ke baad `;` bhool jana** ❌
* **Private member ko bahar se access karna** ❌
* **Object initialize na karna** ❌
* **`new` ke baad `delete` bhool jana** ❌
* **`.` aur `->` mix kar dena** ❌
* **Sab kuch public bana dena** ❌
* **`const` member function use na karna** ❌
* **Class aur object ko confuse karna** ❌

---

## 13. Data Members & Member Functions

**Definition:** Data members are variables inside a class (like characteristics of a person: name, age), and member functions are functions that operate on that data (like actions: talk, walk).

**Why/Use:**
- Encapsulate related data and behavior together
- Control access to data (getter/setter pattern)
- Maintain class invariants
- Hide implementation details
- Provide interface to interact with objects
- Ensure data integrity

**Syntax:**
```cpp
class ClassName {
private:
    // Data members (attributes)
    type dataMember1;
    type dataMember2;
    
public:
    // Member functions (methods)
    returnType memberFunction() {
        // can access data members
    }
};
```

**Example:**
```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    // Data members
    std::string accountNumber;
    std::string holderName;
    double balance;
    static int totalAccounts;  // Static data member (shared by all objects)

public:
    // Constructor
    BankAccount(std::string accNum, std::string name, double initialBalance) 
        : accountNumber(accNum), holderName(name), balance(initialBalance) {
        totalAccounts++;
    }
    
    // Member functions
    
    // Getter functions (accessors)
    std::string getAccountNumber() const {
        return accountNumber;
    }
    
    double getBalance() const {
        return balance;
    }
    
    // Setter functions (mutators)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << "\n";
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
            return true;
        }
        std::cout << "Insufficient funds!\n";
        return false;
    }
    
    void displayInfo() const {
        std::cout << "Account: " << accountNumber 
                  << ", Holder: " << holderName 
                  << ", Balance: $" << balance << "\n";
    }
    
    // Static member function
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Static member initialization (outside class)
int BankAccount::totalAccounts = 0;

int main() {
    BankAccount acc1("ACC001", "Alice", 1000.0);
    BankAccount acc2("ACC002", "Bob", 500.0);
    
    acc1.displayInfo();
    acc1.deposit(500);
    acc1.withdraw(200);
    acc1.displayInfo();
    
    std::cout << "Total accounts: " << BankAccount::getTotalAccounts() << "\n";
    
    return 0;
}
```

**Key Points:**
- **Data Members:**
  - Store object's state/properties
  - Usually private for encapsulation
  - Each object has own copy (except static members)
  - Can be any type (built-in, class, pointer, reference)
  - Can have default initialization
  - Static data members shared by all objects

- **Member Functions:**
  - Operate on object's data
  - Have access to all class members (private/public)
  - Can be `const` (don't modify object)
  - Can be `static` (don't need object instance)
  - Can be overloaded
  - Implicit `this` pointer available

**Common Mistakes:**
- Making all data members public (violates encapsulation)
- Not using `const` for functions that don't modify object
- Forgetting to initialize static data members outside class
- Direct access to private members from outside class
- Not providing getters/setters when needed
- Making getters return non-const references to private data
- Naming conflicts between parameters and data members (use `this->`)
- Accessing non-static members from static functions

---

## 14. Types of Member Functions

**Definition:** Different categories of functions in a class, each serving specific purposes (like different types of workers in a company: managers, technicians, supervisors).

**Why/Use:**
- Organize class behavior logically
- Control object lifecycle (constructors/destructors)
- Provide data access (getters/setters)
- Enable special operations (operator overloading)
- Support polymorphism (virtual functions)
- Share functionality across instances (static functions)

**Syntax:**
```cpp
class ClassName {
public:
    // 1. Constructor
    ClassName() { }
    
    // 2. Destructor
    ~ClassName() { }
    
    // 3. Const member function
    void func() const { }
    
    // 4. Static member function
    static void staticFunc() { }
    
    // 5. Inline member function
    inline void inlineFunc() { }
    
    // 6. Virtual function
    virtual void virtualFunc() { }
    
    // 7. Friend function
    friend void friendFunc(ClassName& obj);
};
```

**Example:**
```cpp
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int rollNo;
    static int totalStudents;

public:
    // 1. Default Constructor
    Student() : name("Unknown"), rollNo(0) {
        totalStudents++;
        std::cout << "Default constructor called\n";
    }
    
    // 2. Parameterized Constructor
    Student(std::string n, int r) : name(n), rollNo(r) {
        totalStudents++;
        std::cout << "Parameterized constructor called\n";
    }
    
    // 3. Copy Constructor
    Student(const Student& other) : name(other.name), rollNo(other.rollNo) {
        totalStudents++;
        std::cout << "Copy constructor called\n";
    }
    
    // 4. Destructor
    ~Student() {
        totalStudents--;
        std::cout << "Destructor called for " << name << "\n";
    }
    
    // 5. Const Member Function (doesn't modify object)
    void display() const {
        std::cout << "Name: " << name << ", Roll No: " << rollNo << "\n";
    }
    
    // 6. Non-const Member Function (can modify object)
    void setName(std::string n) {
        name = n;
    }
    
    // 7. Static Member Function (no access to non-static members)
    static int getTotalStudents() {
        return totalStudents;
        // Cannot access 'name' or 'rollNo' here
    }
    
    // 8. Inline Member Function (defined inside class)
    inline int getRollNo() const { return rollNo; }
    
    // 9. Friend Function (not a member, but has access to private members)
    friend void printDetails(const Student& s) {
        std::cout << "Friend function: " << s.name << " - " << s.rollNo << "\n";
    }
};

// Static member initialization
int Student::totalStudents = 0;

int main() {
    Student s1;                          // Default constructor
    Student s2("Alice", 101);            // Parameterized constructor
    Student s3 = s2;                     // Copy constructor
    
    s2.display();                        // Const member function
    s2.setName("Alice Smith");           // Non-const member function
    s2.display();
    
    std::cout << "Total: " << Student::getTotalStudents() << "\n";  // Static
    
    printDetails(s2);                    // Friend function
    
    return 0;
}
```

**Key Points:**

**1. Constructors:**
- Initialize objects
- Same name as class, no return type
- Can be overloaded
- Default, parameterized, copy, move constructors

**2. Destructors:**
- Clean up resources
- `~ClassName()` syntax
- Called automatically when object destroyed
- Cannot be overloaded (only one destructor)

**3. Const Member Functions:**
- Promise not to modify object
- Use `const` after parameter list
- Can be called on const objects
- Cannot modify data members (unless `mutable`)

**4. Static Member Functions:**
- Belong to class, not objects
- No `this` pointer
- Can only access static members
- Called using class name: `ClassName::function()`

**5. Inline Member Functions:**
- Functions defined inside class are implicitly inline
- Suggestion to compiler for optimization
- Can also use `inline` keyword explicitly

**6. Virtual Functions:**
- Enable runtime polymorphism
- Can be overridden in derived classes
- Used with inheritance

**7. Friend Functions:**
- Not member functions but have access to private/protected members
- Declared with `friend` keyword
- Break encapsulation (use sparingly)

**Common Mistakes:**
- Forgetting `const` on functions that don't modify object
- Trying to access non-static members from static functions
- Making destructor non-virtual in base class (when using inheritance)
- Not implementing copy constructor when needed (deep copy issues)
- Calling non-const functions on const objects
- Overusing friend functions (breaks encapsulation)
- Forgetting to initialize static members outside class
- Making constructor explicit when implicit conversion is wanted

---

## 15. Constructor Initializer List

**Definition:** A special syntax to initialize class members before the constructor body executes (like filling out a form's required fields before submitting, rather than submitting and editing later).

**Why/Use:**
- Initialize const members (cannot be assigned in constructor body)
- Initialize reference members (must be initialized, cannot be assigned)
- Initialize base class constructors
- More efficient (direct initialization vs assignment)
- Initialize members in declaration order
- Required for members without default constructors

**Syntax:**
```cpp
ClassName(parameters) : member1(value1), member2(value2), member3(value3) {
    // Constructor body (optional)
}
```

**Example:**
```cpp
#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {
        std::cout << "Engine created with " << hp << " HP\n";
    }
    
    void display() const {
        std::cout << "Engine: " << horsepower << " HP\n";
    }
};

class Car {
private:
    const std::string brand;      // const member - must use initializer list
    int& yearRef;                 // reference member - must use initializer list
    Engine engine;                // object member - no default constructor
    int modelYear;
    double price;

public:
    // Constructor with initializer list
    Car(const std::string& b, int& year, int hp, double p) 
        : brand(b),           // Initialize const member
          yearRef(year),      // Initialize reference
          engine(hp),         // Initialize Engine object
          modelYear(year),    // Initialize regular member
          price(p)            // Initialize regular member
    {
        std::cout << "Car constructor body\n";
        // brand = "Toyota";  // ERROR: Cannot assign to const
        // yearRef = 2024;    // ERROR: Cannot reassign reference
    }
    
    void display() const {
        std::cout << "Car: " << brand 
                  << ", Year: " << yearRef 
                  << ", Price: $" << price << "\n";
        engine.display();
    }
};

class Point {
private:
    int x, y;
    
public:
    // Multiple ways to initialize
    
    // Method 1: Traditional assignment (less efficient)
    Point(int a, int b) {
        x = a;  // Default initialization, then assignment
        y = b;
    }
    
    // Method 2: Initializer list (more efficient)
    // Point(int a, int b) : x(a), y(b) {
    //     // Direct initialization
    // }
    
    // Method 3: Delegating constructor (C++11)
    Point() : Point(0, 0) {  // Calls Point(int, int)
        std::cout << "Default Point created\n";
    }
    
    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    int year = 2023;
    Car car1("Toyota", year, 250, 35000.0);
    car1.display();
    
    std::cout << "\n";
    
    Point p1(10, 20);
    p1.display();
    
    Point p2;  // Delegating constructor
    p2.display();
    
    return 0;
}
```

**Key Points:**
- Initialization happens before constructor body executes
- Members initialized in order they are declared in class, NOT in initializer list order
- More efficient than assignment (direct initialization vs default + assignment)
- REQUIRED for:
  - const members
  - reference members
  - members without default constructors
  - base class constructors (inheritance)
- Can call other constructors (delegating constructors - C++11)
- Use uniform initialization: `member{value}` (C++11)
- Can use function calls or expressions in initializer list

**Common Mistakes:**
- Initializing in wrong order (should match declaration order in class)
- Trying to initialize const/reference members in constructor body
- Not initializing members without default constructors
- Forgetting to initialize all members (undefined values)
- Using initialization instead of assignment for complex logic (use body)
- Circular initialization dependencies
- Not using initializer list for efficiency (extra copy/assignment)
- Initializing with uninitialized members: `a(x), b(a)` when `a` used before initialized

---

## Summary Table - New Topics

| Concept | Primary Use | Key Feature |
|---------|-------------|-------------|
| Function Overloading | Same name, different parameters | Compile-time polymorphism |
| Class & Object | Blueprint and instances | Encapsulation and OOP |
| Data Members | Store object state | Attributes/properties |
| Member Functions | Object behavior | Methods/operations |
| Constructor Initializer List | Efficient initialization | Required for const/references |

---

**Best Practices:**
1. Use `const&` for large object parameters
2. Prefer `const` and `inline` over macros
3. Avoid `using namespace std;` in headers
4. Use `std::endl` only when flush needed
5. Always parenthesize macro parameters
6. Initialize references immediately
7. Use `boolalpha` for readable boolean output
8. Use initializer lists for all constructors
9. Make data members private, provide getters/setters
10. Mark functions `const` when they don't modify object
11. Use function overloading for similar operations
12. Initialize all members in constructor initializer list




<br >
<br >
<br >
<br >

---

