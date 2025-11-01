#include<iostream>
#include<string>
using namespace std;

namespace Aleph {


void conmuta_pares(Dlink * l1, Dlink * l2)
{
    if (l1 == nullptr || l2 == nullptr)
        return;

    Dlink * p1 = l1->get_first();
    Dlink * p2 = l2->get_first();
    int pos = 0;

    while (p1 != l1 && p2 != l2)
    {
        if (pos % 2 == 0)
        {
            p1->del();
            p2->del();

            Dlink * next1 = p1->get_next(); 
            Dlink * next2 = p2->get_next();

            p1->get_prev()->insert(p2);
            p2->insert(next1);

            p2->get_prev()->insert(p1);
            p1->insert(next2);

            p1 = next1;
            p2 = next2;
        }
        else
        {
            p1 = p1->get_next();
            p2 = p2->get_next();
        }

        pos++;
    }
}

}
