#include "relation.h"
#include <windows.h>

void creat_list_rel(list_rel &l)
{
    first_rel(l) = null;
}

add_rel alokasi_rel(add_parent p, add_chil q)
{
    add_rel r = new elm_rel;
    parent(r) = p;
    child(r) = q;
    next_rel(r) = null;
    return r;
}

add_rel get_last_rel(list_rel l)
{
    if(first_rel(l)!=null)
        {
            add_rel p = first_rel(l);
            while(next_rel(p)!=null)
                p = next_rel(p);

            return p;
        }
    else
        return null;
}

add_rel get_prev_rel(list_rel l,add_rel p)
{
    if(first_rel(l)!=null)
    {
        add_rel q = first_rel(l);
        while(q!=null && next_rel(q)!=p)
            q = next_rel(q);
        return q;
    }
    else
        return null;
}
add_rel search_rel(list_rel l,add_parent p, add_chil q)
{
    add_rel r = first_rel(l);
    if(r!=null)
        {
            while (r!=null)
                {
                    if(parent(r)==p && child(r)==q)
                        break;

                    r = next_rel(r);
                }
            return r;
        }
    else
        return null;
}



void insert_first_rel(list_rel &l,add_rel p)
{
    if(first_rel(l)!=null)
        {
            next_rel(p) = first_rel(l);
            first_rel(l) = p;
        }
    else
        {
            first_rel(l) = p;
        }
}

bool chek_child_relation(add_parent p, add_chil q, list_rel l)
{
    add_rel r = first_rel(l);
    bool chk = false;
    while(r!=null && chk!=true)
    {
        if(parent(r)==p && child(r)==q)
            {
                chk = true;
            }
        else
        r = next_rel(r);
    }
    return chk;
}

bool chek_parent_relation(add_parent p, list_rel l)//ga guna
{
    add_rel r = first_rel(l);
    bool chk = false;
    while(r!=null && chk==false)
    {
        if(parent(r)==p)
            chk = true;
        else
            r = next_rel(r);
    }
    return chk;
}

bool check_child(add_chil p, list_rel l)
{
    add_rel r = first_rel(l);
    bool chk = false;
    while(r!=null && chk==false)
        {
            if(child(r)==p)
                chk = true;
            else
                r = next_rel(r);
        }
    return chk;
}

void relation(list_parent &j, list_child &k, list_rel &l)
{
        worker a;
        shift b;
        cout<<endl;
        cout<<"----------ADD SHIFT TO A WORKERS----------"<<endl;
        cout<<endl;

        cout<<"NIP          : "; cin>>a.nip;
        add_parent p = search_parent(j,a.nip);
    if(p!=null)
        {
            cout<<"Name         :"<<info_par(p).name<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Shift Code   : "; cin>>b.code;
        add_chil q = search_child(k,b.code);
        if(q!=null)
            {
                cout<<"Shift        :"<<info_child(q).shf<<endl;
                cout<<endl;
                if (chek_child_relation(p,q,l))
                    {
                        cout<<"You are alreaddy take this shift"<<endl;
                    }
                else
                    {
                        info_par(p).sum++;
                        add_rel r = alokasi_rel(p,q);
                        insert_first_rel(l,r);
                        cout<<"Shift "<<info_child(q).shf <<" added"<<endl;
                    }
            }

        else
            cout<<"Code not found"<<endl;
        }
    else
        cout<<"NIP not found"<<endl;

    cout<<endl;
    system("pause");
    system("cls");
}


void delete_first_rel(list_rel &l)
{
    if(first_rel(l)!=null)
        {
            add_rel p = first_rel(l);
            if(next_rel(p)==null)
                {
                    parent(p) = null;
                    child(p) = null;
                    first_rel(l) = null;
                    delete p;
                }
            else
                {
                    first_rel(l) = next_rel(p);
                    parent(p) = null;
                    child(p) = null;
                    next_rel(p) = null;
                    delete p;
                }
        }
}

void delete_last_rel(list_rel &l)
{
    if (first_rel(l)!=null)
    {
        add_rel p = get_last_rel(l);
        add_rel q = get_prev_rel(l,p);
        if(next_rel(first_rel(l))!=null)
            {
                parent(p) = null;
                child(p) = null;
                next_rel(q) = null;
                delete p;
            }
        else
            delete_first_rel(l);
    }
}

void delete_after_rel(list_rel &l, add_rel prec)
{
    add_rel p;
    if (first_rel(l)!=null)
        {
            if(first_rel(l)!=get_last_rel(l))
            {
                if(prec!=null)
                    {
                        if(next_rel(prec)==get_last_rel(l))
                            delete_last_rel(l);
                        else
                            {
                                p = next_rel(prec);
                                next_rel(prec) = next_rel(p);
                                next_rel(p) = null;
                                parent(p) = null;
                                child(p) = null;
                                delete p;
                            }
                    }
            }
            else
                delete_first_rel(l);
        }
}

void marge_delete_rel(list_rel &l, add_rel p)
{
    if(first_rel(l)!=null && p!=null)
        {
            if(p == first_rel(l))
                delete_first_rel(l);
            if(next_rel(p) == null)
                delete_last_rel(l);
            else
                delete_after_rel(l,get_prev_rel(l,p));

        }

}

void delete_relation(list_parent &j, list_child &k, list_rel &l)
{
    if(first_rel(l)!=null)
        {
            int a;
            cout<<"---FIND WORKER TO DELETE---"<<endl;
            cout<<endl;
            cout<<"NIP          : "; cin>>a;
            add_parent p = search_parent(j,a);
            if(p!=null)
                {
                    cout<<"Name         : "<<info_par(p).name<<endl;
                    if(chek_parent_relation(p,l))
                        {
                            view_one_parent(p,l);
                            cout<<endl;
                            int b;
                            cout<<"select shift code to delete : "; cin>>b;
                            add_chil q = search_child(k,b);
                            if(chek_child_relation(p,q,l))
                                {
                                    add_rel r = search_rel(l,p,q);
                                    if(r!=null)
                                    {
                                        char yn;
                                        cout<<"Delete? y/n : "; cin>>yn;
                                            if(yn=='y')
                                                {
                                                    info_par(parent(r)).sum--;
                                                    marge_delete_rel(l,r);
                                                    cout<<"Deleted"<<endl;
                                                }
                                            else
                                                cout<<"Delete canceled"<<endl;

                                    }
                                    else
                                        cout<<"not found"<<endl;
                                }
                            else
                                cout<<"You are not taking this shift"<<endl;

                        }
                    else
                        cout<<"You have not registered any shift yet"<<endl;
                }
            else
                cout<<"NIP not found"<<endl;
        }
    else
        cout<<"No workers take any shift"<<endl;

system("pause");
system("cls");
}

void delete_parent_real(list_parent &j,list_rel &l)
{
    if(first_par(j)!=null)
        {
            cout<<"---DELETE WORKER---"<<endl;
            cout<<endl;
            int x;
            cout<<"NIP          : "; cin>>x;
            add_parent p = search_parent(j,x);
            if(p!=null)
                {
                    cout<<"Name         : "<<info_par(p).name<<endl;
                    char a;
                    cout<<"Delete? y/n  : "; cin>>a;
                    //add_rel r = first_rel(l);
                    if(a=='y')
                        {
                            add_rel r = first_rel(l);
                            while(r!=null)
                                {
                                    if(parent(r)==p)
                                        {
                                            child(r) = null;
                                            parent(r) = null;
                                        }

                                    r = next_rel(r);
                                }

                            marge_delete_parent(j,p);

                            cout<<"Deleted"<<endl;

                        }
                        else
                            cout<<"Delete canceled"<<endl;

                }
            else
                cout<<"NIP not found"<<endl;

        }
    else
        cout<<"No worker registered"<<endl;

    system("pause");
    system("cls");
}

void delete_child_real(list_child &k, list_rel &l)
{
    if(first_child(k)!=null)
    {
        cout<<"---DELETE SHIFT---"<<endl;
        cout<<endl;
        int y;
        cout<<"Code          : "; cin>>y;
        add_chil p = search_child(k,y);
        if(p!=null)
            {
                cout<<"Shift         : "<<info_child(p).shf<<endl;
                char a;
                cout<<"Delete? y/n  : "; cin>>a;
                if(a=='y' || a=='Y')
                    {
                        add_rel r = first_rel(l);
                         while(r!=null)
                                {
                                    if(child(r)==p)
                                        {
                                            child(r) = null;
                                            parent(r) = null;

                                        }
                                    r = r->next_rel;
                                }

                            marge_delete_child(k,p);
                            cout<<"Deleted"<<endl;

                    }
                else
                    cout<<"Delete canceled"<<endl;
            }
        else
            cout<<"Code not found"<<endl;
    }
    else
        cout<<"No shift registered"<<endl;

    system("pause");
    system("cls");

}

void view_one_parent(add_parent p, list_rel l)
{
    add_rel r = first_rel(l);
        if (r!=null)
            {
                if(chek_parent_relation(p,l))
                {
                    cout<<"No.|"<<"     Shift        |"<<"Code "<<endl;
                    int i = 1;
                    while(r!=null)
                    {
                        if(parent(r)==p)
                            {
                                cout<<i<<"  |  "<<info_child(child(r)).shf<<"     | "<<info_child(child(r)).code<<endl;
                                i++;
                            }
                        r = next_rel(r);
                    }
                }
                else
                    {
                        cout<<"You have not registered any shift yet"<<endl;
                        cout<<endl;
                    }
            }
        else
            cout<<"There is no shift taken"<<endl;

}

void view_one_parent_search(list_parent j,list_rel l)
{
    int x;
    if(first_rel(l)!=null)
    {
        cout<<endl;
        cout<<"----------SEARCH WORKERS----------"<<endl;
        cout<<endl;
        cout<<"NIP             : "; cin>>x;
        add_parent p = search_parent(j,x);
        if (p!=null)
        {
            cout<<"Name            : "<<info_par(p).name<<endl;
            cout<<"Shift taken     :"<<info_par(p).sum<<endl;
            cout<<endl;
            view_one_parent(p,l);
        }
        else
            cout<<"NIP not found"<<endl;

    }
    else
        cout<<"No worker take any shift"<<endl;

system("pause");
system("cls");
}

void view_one_child(add_chil p, list_rel l)
{
    add_rel r = first_rel(l);
    if(r!=null)
        {
            if(check_child(p,l))
                {
                    cout<<"NIP. |"<<"  Name"<<endl;
                    while(r!=null)
                        {
                            if(child(r)==p)
                                cout<<info_par(parent(r)).nip<<"    |  "<<info_par(parent(r)).name<<endl;

                            r = next_rel(r);
                        }
                }
            else
                cout<<"no worker taking this shift"<<endl;
        }
}

void view_one_child_search(list_child k, list_rel l)
{
    int y;
    if(first_rel(l)!=null)
        {
            cout<<endl;
            cout<<"----------SEARCH SHIFT----------"<<endl;
            cout<<endl;
            cout<<"Code            : "; cin>>y;
            add_chil p = search_child(k,y);
            if (p!=null)
                {
                    cout<<"Shift           : "<<info_child(p).shf<<endl;
                    cout<<"Taken by        :"<<endl;
                    cout<<endl;
                    view_one_child(p,l);
                }
            else
                cout<<"NIP not found"<<endl;
        }
    else
        cout<<"No worker take any shift"<<endl;

    system("pause");
    system("cls");
}

void viewall(list_parent j, list_child k, list_rel l)
{
if(first_par(j)!=null && first_child(k)!=null && first_rel(l)!=null)
{
    cout<<endl;
    cout<<"----------All WORKERS AND THEIR SHIFT----------"<<endl;
    cout<<endl;
    add_parent p = first_par(j);
    while(p!=null)
    {
        cout<<"NIP          : "<<info_par(p).nip<<endl;
        cout<<"Name         : "<<info_par(p).name<<endl;
        cout<<"Shift taken  : "<<info_par(p).sum<<endl;
        cout<<endl;
        view_one_parent(p,l);
        cout<<endl;
        cout<<endl;
        cout<<endl;
        p = next_par(p);
    }
}
else
    cout<<"EMPTY"<<endl;

system("pause");
system("cls");
}

void view_few(list_parent j, list_child k, list_rel l)
{
    if(first_par(j)!=null)
    {
            int minnn =999 ;
            add_parent minn;
            add_parent q = first_par(j);
            while(q!=null)
            {
                if(info_par(q).sum < minnn)
                    {
                        minn = q;
                        minnn = info_par(q).sum;
                    }
                q = next_par(q);
            }
            cout<<endl;
            cout<<endl;
            cout<<"** THE FEWEST SCHEDULE **"<<endl;
            cout<<endl;
            cout<<"NIP           : "<<info_par(minn).nip<<endl;
            cout<<"Name          : "<<info_par(minn).name<<endl;
            cout<<endl;
            view_one_parent(minn,l);


        }
    else
        cout<<"EMPTY"<<endl;
}

void view_most(list_parent j, list_child k, list_rel l)
{
    if(first_par(j)!=null)
        {
            worker a;
            a.name ="max";
            a.nip = 00;
            a.sum = 0;
            add_parent maxx = alokasi_parent(a);
            add_parent p = first_par(j);
            while(p!=null)
            {
                if(info_par(p).sum > info_par(maxx).sum)
                    maxx = p;
                p = next_par(p);
            }
            cout<<endl;
            cout<<"** THE DENSEST SCHEDULE **"<<endl;
            cout<<endl;
            cout<<"NIP           : "<<info_par(maxx).nip<<endl;
            cout<<"Name          : "<<info_par(maxx).name<<endl;
            cout<<endl;
            view_one_parent(maxx,l);


        }
    else
        cout<<"EMPTY"<<endl;


}
void delete_all_null(list_rel &l)
{
    if(first_rel(l)!=null)
    {
        add_rel p = first_rel(l);
        while(p!=null)
        {
            if(child(p)==null && parent(p)==null)
                marge_delete_rel(l,p);

            p = p->next_rel;
        }
    }
}

void gotoxy(int x,int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
