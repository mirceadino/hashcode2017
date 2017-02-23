#include "global.h"

using namespace std;

/* ============================= */
/* ===== GLOBAL VARIABLES ====== */
/* ============================= */

int a;


/* ============================= */
/* ======== I/O METHODS ======== */
/* ============================= */

void read() {

}

extern void solve_mircea();

extern void solve_razvan();

void print() {
    cout << a << endl;
}


/* ============================= */
/* =========== MAIN ============ */
/* ============================= */

int main() {
    read();
    solve_mircea();
    solve_razvan();
    print();

    return 0;
}