#include "relation.h"
void create_list_par(list_parent &l)
{
    first_par(l) = null;
    last_par(l) = null;
}

add_parent alokasi_parent(worker a)
{
    add_parent p;
    p = new elm_parent;
    a.sum = 0;
    info_par(p) = a;
    next_par(p) = null;
    return p;
}

add_parent search_parent(list_parent l,int x)
{
    add_parent p = first_par(l);
    while(p!=null && info_par(p).nip!=x)
        {
            p = next_par(p);
        }
    if (p!=null)
        return p;
    else
        return null;
}

void insert_first(list_parent &l,worker a)
{
    add_parent p = alokasi_parent(a);
    if (first_par(l)!=null && last_par(l)!=null)
        {
            next_par(p) = first_par(l);
            prev_par(first_par(l)) = p;
            first_par(l) = p;
        }
    else
        {
           first_par(l) = p;
           last_par(l) = p;
        }
}

void insert_last(list_parent &l,worker a)
{
    add_parent p = alokasi_parent(a);
    if (first_par(l)!=null && last_par(l)!=null)
        {
            prev_par(p) = last_par(l);
            next_par(last_par(l)) = p;
            last_par(l) = p;
        }
    else
        {
            insert_first(l,a);
        }
}

void insert_after(list_parent &l,worker a,worker prec)
{
    add_parent prc = search_parent(l,prec.nip);
    add_parent q = alokasi_parent(a);

    if(first_par(l)!=null && last_par(l)!=null)
        {
            if (prc!=null)
                {
                    if(prc == last_par(l))
                        insert_last(l,a);
                    else
                        {
                            next_par(q) = next_par(prc);
                            prev_par(q) = prc;
                            prev_par(next_par(prc)) = q;
                            next_par(prc) = q;
                        }
                }
        }
    else
        insert_first(l,a);
}

void insert_sort(list_parent &l,worker a)
{
    add_parent p = alokasi_parent(a);
    if(first_par(l)!=null)
    {
        if(a.nip < info_par(first_par(l)).nip)
            insert_first(l,a);
        else if(a.nip > info_par(last_par(l)).nip)
            insert_last(l,a);
        else
        {
            add_parent q = first_par(l);
            while(next_par(q)!=null && info_par(p).nip > info_par(next_par(q)).nip)
                q = next_par(q);
            insert_after(l,a,info_par(q));

        }
    }
    else
        insert_first(l,a);
}

void insert_parent(list_parent &l)
{
    worker a;
    cout<<endl;
    cout<<"----------ADD WORKER----------"<<endl;
    cout<<endl;
    cout<<"NIP    : "; cin>>a.nip;
    add_parent p = search_parent(l,a.nip);
    if (p!=null)
        {
            cout<<"Sorry, NIP already registered"<<endl;
            cout<<endl;
        }
    else
    {
        cout<<"Name   : "; cin.ignore(); getline(cin,a.name);
        insert_sort(l,a);
        cout<<a.name<<" Added!"<<endl;
        cout<<endl;
    }
    system("pause");
    system("cls");

}

void delete_first_parent(list_parent &l)
{
    if(first_par(l)!=null && last_par(l)!=null)
        {
            add_parent p = first_par(l);
            if(first_par(l)!=last_par(l))
                {
                    first_par(l) = next_par(p);
                    prev_par(first_par(l)) = null;
                    next_par(p) = null;
                }
            else
                {
                    first_par(l) = null;
                    last_par(l) = null;
                }
            delete p;
        }
}

void delete_last_parent(list_parent &l)
{
    if(first_par(l)!=null && last_par(l)!=null)
        {

            add_parent p = last_par(l);
            if(first_par(l)!=last_par(l))
                {
                    last_par(l) = prev_par(p);
                    next_par(last_par(l)) = null;
                    prev_par(p) = null;
                }
            else
                {
                    delete_first_parent(l);
                }
            delete p;
        }
}

void delete_after_parent(list_parent &l, worker prec)
{
    add_parent p;
    if (first_par(l)!=null && last_par(l)!=null)
    {
        if(first_par(l)!=last_par(l))
        {
            add_parent prc = search_parent(l,prec.nip);
            if (prc!=null)
                {
                    if (next_par(prc)==last_par(l))
                        delete_last_parent(l);
                    else
                        {
                            p = next_par(prc);
                            next_par(prc) = next_par(p);
                            prev_par(next_par(p)) = prc;
                            next_par(p) = null;
                            prev_par(p) = null;
                            delete p;
                        }
                }
        }
        else
            delete_first_parent(l);
    }
}

void marge_delete_parent(list_parent &l, add_parent p)
{
    if (first_par(l)!=null && last_par(l)!=null)
    {
        if(p==null)
            {
                cout<<"NIP not found"<<endl;
            }
        else
            {
                if(p==first_par(l))
                    delete_first_parent(l);
                else if(p==last_par(l))
                    delete_last_parent(l);
                else
                    {
                        delete_after_parent(l,info_par(prev_par(p)));
                    }
            }
    }
}

void delete_parent(list_parent &l)
{
    if (first_par(l)!=null)
    {
        worker a;
        char chk;
        cout<<endl;
        cout<<"----------DELETE WORKER----------"<<endl;
        cout<<endl;
        cout<<"NIP    : "; cin>>a.nip;
        add_parent p = search_parent(l,a.nip);
        cout<<"delete "<<info_par(p).name<<"? y/n : "; cin>>chk;
        if (chk=='y')
            marge_delete_parent(l,p);
        else
            cout<<"delete canceled"<<endl;
    }
    else
        cout<<"Empty"<<endl;

        cout<<endl;
        system("pause");
        system("cls");
}

void view_parent(list_parent l)
{
    if (first_par(l)!=null && last_par(l)!=null)
    {
        cout<<endl;
        cout<<"----------VIEW WORKERS----------"<<endl;
        cout<<endl;
        add_parent p = first_par(l);
        while(p!=null)
            {
                cout<<"nama : "<<info_par(p).name<<endl;
                cout<<"nip  : "<<info_par(p).nip<<endl;
                cout<<endl;
                p = next_par(p);
            }
    }
    else
        cout<<"EMPTY"<<endl;

    system("pause");
    system("cls");
}

