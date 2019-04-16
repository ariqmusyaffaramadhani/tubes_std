#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

typedef struct elm_parent *add_parent;
//#include "relation.h"
#define next_par(A) A->next_par
#define info_par(A) A->info_par
#define prev_par(A) A->prev_par
#define first_par(A) A.first_par
#define last_par(A) A.last_par

struct worker{
    string name;
    int nip,sum;
};

struct elm_parent{
    worker info_par;
    add_parent next_par;
    add_parent prev_par;
};
struct list_parent{
    add_parent first_par;
    add_parent last_par;
};

void create_list_par(list_parent &l);
add_parent alokasi_parent(worker a);
add_parent search_parent(list_parent l,int x);

void insert_parent(list_parent &l);
void insert_last(list_parent &l,worker a);
void insert_first(list_parent &l,worker a);
void insert_after(list_parent &l,worker a,worker prec);
void insert_sort(list_parent &l,worker a);

void marge_delete_parent(list_parent &, add_parent p);
void delete_first_parent(list_parent &l);
void delete_last_parent(list_parent &l);
void delete_after_parent(list_parent &l, worker prec);
void delete_parent(list_parent &l);
void view_parent(list_parent l);
#endif // PARENT_H_INCLUDED
