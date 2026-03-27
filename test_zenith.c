#include <stdio.h>
#include "zenith_c.h" // Including your brand new library!

// 1. Define a "Voter" Class
ZC_CLASS(Voter)
    int id;
ZC_METHODS(Voter)
    void (*vote)(Voter* self, int candidate_id);
ZC_END_CLASS

// 2. Implement the method
void voter_vote(Voter* self, int candidate_id) {
    printf("Voter %d is voting for Candidate %d!\n", self->id, candidate_id);
}

// 3. Create the vTable instance
struct Voter_vtable Voter_methods = { .vote = voter_vote };

// 4. Define the Constructor
void zc_init_Voter(Voter* self, int id) {
    self->id = id;
    // Attach the Voter behavior to the object
    self->vlist = zc_attach(NULL, "Voter", &Voter_methods);
}

int main() {
    // 5. Create a Voter using your ZC_NEW macro
    Voter* v;
    ZC_NEW(v, Voter, 777); 

    if (v) {
        printf("--- Testing Zenith-C Library ---\n");
        
        // 6. Get the methods and call them
        struct Voter_vtable* m = (struct Voter_vtable*)zc_get_vtable(v->vlist, "Voter");
        if (m) m->vote(v, 101);

        // 7. Use your ZC_DELETE macro to clean up memory
        ZC_DELETE(v);
        printf("Memory cleaned. Test Success!\n");
    }

    return 0;
}
