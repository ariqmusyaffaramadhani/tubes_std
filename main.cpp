#include "relation.h"
#include "menu.h"

int main()
{
    list_parent gg;
    create_list_par(gg);
    list_rel ll;
    creat_list_rel(ll);
    list_child jj;
    create_list_child(jj);
    main_menu(gg,jj,ll);
    return 0;
}
