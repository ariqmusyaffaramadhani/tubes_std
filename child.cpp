#include "child.h"

void create_list_child(list_child &l)
{
    first_child(l) = null;
}

add_chil alokasi_child(shift a)
{
    add_chil p;
    p = new elm_child;
    info_child(p) = a;
    next_chil(p) = null;
    return p;
}

add_chil search_child(list_child l,int a)
{
    if (first_child(l)!=null)
    {
        add_chil p = first_child(l);
        while (next_chil(p)!=first_child(l) && info_child(p).code !=a)
            {
                p = next_chil(p);
            }
        if (info_child(p).code==a)
            return p;
        else
            return null;
    }
    else
        return null;
}

add_chil get_last(list_child l)
{
    if(first_child(l)!=null)
    {
        add_chil p = first_child(l);
        while(next_chil(p)!=first_child(l))
            {
                p = next_chil(p);
            }
        return p;
    }
    else
        return null;
}

add_chil get_prev(list_child l,add_chil p)
{
    if(first_child(l)!=null)
    {
        add_chil q = first_child(l);
        while(next_chil(q)!=p)
        {
            q = next_chil(q);
        }
        return q;

    }

    else return null;
}

void insert_last_child(list_child &l, shift a)
{
    add_chil p = alokasi_child(a);
    if (first_child(l)!=null)
        {
            add_chil q = get_last(l);
            next_chil(q) = p;
            next_chil(p) = first_child(l);
        }
    else
        {
            first_child(l) = p;
            next_chil(p) = first_child(l);
        }
}

void insert_child(list_child &l)
{
    shift a;
    cout<<endl;
    cout<<"----------ADD WORK SHIFT----------"<<endl;
    cout<<endl;
    cout<<"CODE         : "; cin>>a.code;
    add_chil p = search_child(l,a.code);
    if (p!=null)
        cout<<"Sorry, ID already registered"<<endl;
    else
        {
            cout<<"#time format : 12:00-24:00#"<<endl; //mask input
            cout<<"Time         : "; cin.ignore(); getline(cin,a.shf);
            insert_last_child(l,a);
            cout<<"Shift added!"<<endl;
        }

    cout<<endl;
    system("pause");
    system("cls");

}

void view_child(list_child l)
{
    if (first_child(l)!=null)
        {
            cout<<endl;
            cout<<"----------VIEW WORKERS----------"<<endl;
            cout<<endl;
            add_chil p =first_child(l);
            do
                {
                    cout<<"code  = "<<info_child(p).code<<endl;
                    cout<<"shift = "<<info_child(p).shf<<endl;
                    cout<<endl;
                    p = next_chil(p);
                }
            while(p!=first_child(l));
        }
    else
        cout<<"EMPTY"<<endl;

    system("pause");
    system("cls");
}

void delete_first_child(list_child &l)
{
    if (first_child(l)!=null)
        {
            add_chil p = first_child(l);
            if (next_chil(p)!=first_child(l))
                {
                    add_chil q = get_last(l);
                    first_child(l) = next_chil(p);
                    next_chil(p) = null;
                    next_chil(q) = first_child(l);

                }
            else
                {
                    first_child(l) = null;
                    next_chil(p) = null;
                }
            delete p;
        }
    else
        {
            cout<<"Empty, can't delete "<<endl;
        }
}

void delete_last_child(list_child &l)
{
    if (first_child(l)!=null)
        {
            add_chil p = get_last(l);
            add_chil q = get_prev(l,p);
            if (first_child(l)!=get_last(l))
                {
                    next_chil(p) = null;
                    next_chil(q) = first_child(l);
                }
            else
                {
                    delete_first_child(l);
                }
            delete p;
        }
    else
        {
            cout<<"Empty, can't delete "<<endl;
        }

}

void delete_after_child(list_child &l, shift prec)
{
    add_chil p;
    if(first_child(l)!=null)
        {
           if(first_child(l)!=get_last(l))
           {
                add_chil prc = search_child(l,prec.code);
                if(prc!=null)
                    {
                        if(next_chil(prc)==get_last(l))
                            delete_last_child(l);
                        else
                            {
                                p = next_chil(prc);
                                next_chil(prc) = next_chil(p);
                                next_chil(p) = null;
                                delete p;
                            }
                    }
           }
           else
            delete_first_child(l); //cek
        }
}
void marge_delete_child(list_child &l, add_chil p)
{
    if (first_child(l)!=null)
        {
            if (p==null)
                cout<<"Code not found"<<endl;
            else
                {
                    if(p==first_child(l))
                        delete_first_child(l);
                    else if(p==get_last(l))
                        delete_last_child(l);
                    else
                        delete_after_child(l,info_child(get_prev(l,p)));
                }
        }

}

void delete_child(list_child &l)
{
    if(first_child(l)!=null)
        {
            shift a;
            char chk;
            cout<<endl;
            cout<<"----------DELETE SHIFT----------"<<endl;
            cout<<endl;
            cout<<"Code        : "; cin>>a.code;
            add_chil p = search_child(l,a.code);
            cout<<"delete "<<info_child(p).shf<<" ? y/n  : "; cin>>chk;
            if(chk=='y')
                marge_delete_child(l,p);
            else
                cout<<"delete canceled"<<endl;
        }
    else
        cout<<"Empty"<<endl;

        cout<<endl;
        system("pause");
        system("cls");

}
