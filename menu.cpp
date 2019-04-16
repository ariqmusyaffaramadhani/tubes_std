#include "menu.h"


void main_menu(list_parent &j, list_child &k, list_rel &l)
{
    int x;
    while(x!=5)
    {
    cout<<endl;
    cout<<"----------MAIN MENU----------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"1. Workers Menu"<<endl;
    cout<<endl;
    cout<<"2. Shift Menu"<<endl;
    cout<<endl;
    cout<<"3. Shift registration"<<endl;
    cout<<endl;
    cout<<"4. View Menu"<<endl;
    cout<<endl;
    cout<<"5. Exit"<<endl;
    cout<<endl;

    cout<<"Select menu : "; cin>>x;
        if(x==1)
            {
                system("cls");
                worker_menu(j,k,l);
            }

        if(x==2)
            {
                system("cls");
                shift_menu(j,k,l);
            }
        if(x==3)
            {
                system("cls");
                shift_regis(j,k,l);
            }
        if(x==4)
            {
                system("cls");
                view_menu(j,k,l);
            }
        else
            system("cls");
    }

}

void worker_menu(list_parent &j, list_child &k, list_rel &l)
{
int x;
    while(x!=4)
    {
    cout<<endl;
    cout<<"----------WORKER MENU----------"<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"1. Add Workers"<<endl;
    cout<<endl;
    cout<<"2. Delete Workers"<<endl;
    cout<<endl;
    cout<<"3. View Workers"<<endl;
    cout<<endl;
    cout<<"4. Exit"<<endl;
    cout<<endl;

    cout<<"Select menu : "; cin>>x;
        if(x==1)
        {
            system("cls");
            insert_parent(j);
        }

        if(x==2)
            {
                system("cls");
                delete_parent_real(j,l);
            }
        if(x==3)
            {
                system("cls");
                view_parent(j);
            }
        else
            system("cls");
    }
}

void shift_menu(list_parent &j, list_child &k, list_rel &l)
{
int x;
    while(x!=4)
    {
    cout<<endl;
    cout<<"----------SHIFT MENU----------"<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"1. Add Shift"<<endl;
    cout<<endl;
    cout<<"2. Delete Shift"<<endl;
    cout<<endl;
    cout<<"3. View Shift"<<endl;
    cout<<endl;
    cout<<"4. Exit"<<endl;
    cout<<endl;

    cout<<"Select menu : "; cin>>x;
        if(x==1)
        {
            system("cls");
            insert_child(k);
        }

        if(x==2)
            {
                system("cls");
                delete_child_real(k,l);
            }
        if(x==3)
            {
                system("cls");
                view_child(k);
            }
        else
            system("cls");
    }
}

void shift_regis(list_parent &j, list_child &k, list_rel &l)
{
int x;
    while(x!=3)
    {
    cout<<endl;
    cout<<"----------SHIFT REGISTRATION MENU----------"<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"1. Add Shift to a Workers"<<endl;
    cout<<endl;
    cout<<"2. Delete Shift from a Workers"<<endl;
    cout<<endl;
    cout<<"3. Exit"<<endl;
    cout<<endl;

    cout<<"Select menu : "; cin>>x;
        if(x==1)
            {
                system("cls");
                relation(j,k,l);
            }

        if(x==2)
            {
                system("cls");
                delete_relation(j,k,l);
            }
        else
            system("cls");
    }
}

void view_menu(list_parent &j, list_child &k, list_rel &l)
{
int x;
    while(x!=5)
    {
    cout<<endl;
    cout<<"----------SHIFT REGISTRATION MENU----------"<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"1. View All"<<endl;
    cout<<endl;
    cout<<"2. Search Workers"<<endl;
    cout<<endl;
    cout<<"3. Search Shift"<<endl;
    cout<<endl;
    cout<<"4. View Most-Workers"<<endl;
    cout<<endl;
    cout<<"5. Exit"<<endl;
    cout<<endl;

    cout<<"Select menu : "; cin>>x;
        if(x==1)
            {
                system("cls");
                viewall(j,k,l);
            }

        if(x==2)
            {
                system("cls");
                view_one_parent_search(j,l);
            }
        if(x==3)
            {
                system("cls");
                view_one_child_search(k,l);
            }
        if(x==4)
            {
                system("cls");
                view_most(j,k,l);
                view_few(j,k,l);
                system("pause");
                system("cls");

            }
        else
            system("cls");
    }
}
