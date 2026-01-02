
# C++ Core Concepts – Merged & Clean Notes (Core + Chai ☕)



## 1. Namespaces, Scope Resolution `::` & Using Directive

**Definition:**  
A **namespace** groups related code to avoid name conflicts.  
The **scope resolution operator `::`** is used to access members inside a namespace or class.  
The **`using` directive** helps bring namespace members into the current scope to reduce verbosity.

In short:  
> Namespace = container  
> `::` = address of the container  
> `using` = shortcut to avoid writing full address again ☕

**Why / Use (Merged):**
- Prevents name conflicts when using multiple libraries  
- Organizes large codebases logically  
- Allows same identifier names in different contexts  
- Reduces repetitive `std::` usage  
- Clearly resolves scope ambiguity  


**Syntax:**
```cpp
namespace namespace_name {
    // declarations
}

namespace_name::member;

using namespace namespace_name;
using namespace_name::member;
````

---

**Example:**

```cpp
#include <iostream>

namespace Math {
    int value = 10;
}

int value = 5;

using Math::value;   // brings Math::value into scope

int main() {
    std::cout << value << "\n";   // Math::value
    std::cout << ::value << "\n"; // global value
}
```

---

**Key Points (Merged):**

* `std` is a namespace used by the standard library
* `::` specifies exact scope (namespace, class, or global)
* Prefer `using namespace_name::member` over full namespace
* Avoid `using namespace std;` in header files
* Essential for clean, conflict-free large projects

---

## 2. cin / cout, Escape Sequences & Manipulators

**Definition:**
`cin` and `cout` are stream objects used for console input/output.
**Escape sequences** format text output.
**Manipulators** control how data is displayed.

Basically:

> `cin/cout` = talking to console
> escape sequences = line breaks & spacing
> manipulators = styling the output ☕

---

**Why / Use (Merged):**

* Perform type-safe console I/O
* Format output using newlines, tabs, precision, alignment
* Improve readability and presentation of output

---

**Syntax:**

```cpp
std::cin >> variable;
std::cout << value;

"\n", "\t"

std::cout << std::setprecision(n);
```

---

**Example:**

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159;
    std::cout << "Value:\n";
    std::cout << std::setprecision(3) << pi << "\n";
}
```

---

**Key Points (Merged):**

* `<iostream>` required for `cin`/`cout`
* `<iomanip>` required for most manipulators
* `<<` output, `>>` input
* `\n` is most commonly used escape sequence
* Manipulators improve output formatting

---

## 3. Macros & Inline Functions

**Definition:**
**Macros** perform text replacement before compilation.
**Inline functions** suggest the compiler to replace function calls with function body.

Think of it as:

> Macro = unsafe shortcut
> Inline function = safe shortcut ☕

---

**Why / Use (Merged):**

* Reduce repetitive code
* Improve performance for small functions
* Replace function-like macros safely

---

**Syntax:**

```cpp
#define NAME value

inline return_type function(parameters)
```

---

**Example:**

```cpp
#define SQUARE_MACRO(x) ((x) * (x))

inline int square(int x) {
    return x * x;
}
```

---

**Key Points (Merged):**

* Macros have no type checking
* Inline functions are type-safe
* Prefer inline functions in modern C++
* Compiler may ignore `inline` keyword
* Overusing macros causes debugging issues

---

## 4. Default Arguments & References

**Definition:**
**Default arguments** provide values when arguments are not passed.
**References** act as aliases for existing variables.

In short:

> Default arguments = flexibility
> References = efficiency ☕

---

**Why / Use (Merged):**

* Simplify function calls
* Avoid unnecessary copying
* Allow modification of original data
* Improve performance with large objects

---

**Syntax:**

```cpp
void func(int x = 10);

type& ref = variable;
```

---

**Example:**

```cpp
void increment(int& x, int step = 1) {
    x += step;
}

int main() {
    int a = 10;
    increment(a);
}
```

---

**Key Points (Merged):**

* Default arguments must be rightmost
* References must be initialized
* References cannot be null or reassigned
* Use `const&` for read-only parameters
* Cleaner and safer than pointers

---

