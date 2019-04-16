#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

#define null NULL



#include "child.h"
#include "parent.h"
typedef struct elm_rel *add_rel;
#define next_rel(A) A->next_rel
#define first_rel(A) A.first_rel
#define parent(A) A->parent
#define child(A) A->child

struct elm_rel{
    add_rel next_rel;
    add_parent parent;
    add_chil child;
};

struct list_rel{
    add_rel first_rel;
};

add_rel alokasi_rel(add_parent p, add_chil q);
add_rel get_last_rel(list_rel l);
add_rel get_prev_rel(list_rel l,add_rel p);
add_rel search_rel(list_rel l,add_parent p, add_chil q);

//add_chil search_child_relation_parent(add_parent p,list_child k, list_rel l, int code_child); //search childnya yg nyangkut sama parent aja

void creat_list_rel(list_rel &l);
void insert_first_rel(list_rel &l,add_rel p);
void relation(list_parent &j, list_child &k, list_rel &l);

bool chek_child_relation(add_parent p, add_chil q, list_rel l);
bool chek_parent_relation(add_parent p, list_rel l);
bool check_child(add_chil p, list_rel l);

void delete_first_rel(list_rel &l);
void delete_last_rel(list_rel &l);
void delete_after_rel(list_rel &l, add_rel prec);
void marge_delete_rel(list_rel &l, add_rel p);
void delete_relation(list_parent &j, list_child &k, list_rel &l);

void view_one_child(add_chil p, list_rel l);
void view_one_child_search(list_child k, list_rel l);

void view_one_parent(add_parent p, list_rel l);//nyari satu parent baanyak shift
void view_one_parent_search(list_parent j,list_rel l);

void delete_parent_real(list_parent &j, list_rel &l);
void delete_child_real(list_child &k, list_rel &l);
void delete_all_null(list_rel &l);


void view_most(list_parent j, list_child k, list_rel l);
void view_few(list_parent j, list_child k, list_rel l);
void viewall(list_parent j, list_child k, list_rel l);

void gotoxy(int x,int y);

//void view_one_child();

#endif // RELATION_H_INCLUDED
