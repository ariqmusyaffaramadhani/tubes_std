#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
typedef struct elm_child *add_chil;
#define null NULL
//#include "relation.h"
#define next_chil(A) A->next_chil
#define info_child(A) A->info_child
#define first_child(A) A.first_child


struct shift{
    int code;
    string shf;

};
struct elm_child{
    shift info_child;
    add_chil next_chil;
};

struct list_child{
    add_chil first_child;
};

void create_list_child(list_child &l);
add_chil alokasi_child(shift a);
add_chil search_child(list_child l,int a);
add_chil get_last(list_child l);
add_chil get_prev(list_child l,add_chil p);
void insert_last_child(list_child &l, shift a);
void insert_child(list_child &l);

void delete_first_child(list_child &l);
void delete_last_child(list_child &l);
void delete_after_child(list_child &l, shift prec);
void marge_delete_child(list_child &l, add_chil p);
void delete_child(list_child &l);

void view_child(list_child l);
#endif // CHILD_H_INCLUDED
