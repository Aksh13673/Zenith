# 🚀 Zenith-C
**The Ultimate OOP Framework for Procedural C**

Zenith-C is a lightweight, header-only library that brings modern Object-Oriented features to C. Designed for developers who need the organization of classes with the raw power of systems-level programming.

## ✨ Features
- **Dynamic Multiple Inheritance**: Link multiple parent behaviors at runtime using a unique **Linked vTable** system.
- **Universal Compatibility**: Macro-driven syntax (`ZC_NEW`, `ZC_DELETE`) compatible with GCC, Clang, and MSVC.
- **Deep Memory Management**: Automatic destructor logic that "walks the chain" to prevent memory leaks in complex inheritance trees.
- **Zero Boilerplate**: Define classes, methods, and constructors in seconds.

## 🛠 Installation
Zenith-C is a **header-only library**. Just drop `zenith_c.h` into your project directory and include it:
```c
#include "zenith_c.h"

💻 Quick Start Example
This example demonstrates a Voter class inheriting behavior and performing a security check.
#include <stdio.h>
#include "zenith_c.h"

// 1. Define the Class
ZC_CLASS(Voter)
    int id;
ZC_METHODS(Voter)
    void (*vote)(Voter* self, int candidate_id);
ZC_END_CLASS

// 2. Implement the Method
void voter_vote(Voter* self, int candidate_id) {
    printf("Voter %d is casting a vote for Candidate %d!\n", self->id, candidate_id);
}

// 3. Create the vTable Instance
struct Voter_vtable Voter_methods = { .vote = voter_vote };

// 4. Define the Constructor
void zc_init_Voter(Voter* self, int id) {
    self->id = id;
    // Attach behavior to the object's linked list
    self->vlist = zc_attach(NULL, "Voter", &Voter_methods);
}

int main() {
    Voter* v;
    // Instantiate using the Zenith-C Factory
    ZC_NEW(v, Voter, 777); 

    if (v) {
        // Retrieve and call the method
        struct Voter_vtable* m = (struct Voter_vtable*)zc_get_vtable(v->vlist, "Voter");
        if (m) m->vote(v, 101);

        // Safe cleanup with Zenith-C Destructor
        ZC_DELETE(v);
    }
    return 0;
}

⚖️ License
Distributed under the MIT License. See LICENSE for more information.

✍️ Author
Created with 🚀 by Aksheita Dholakia (March 2026).
