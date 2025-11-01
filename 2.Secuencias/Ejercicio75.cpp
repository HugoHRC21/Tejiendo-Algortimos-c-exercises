#include<iostrema>
using namespace std

namespace Aleph {

void permutar_pares(Dlink * lista)
{
    if (lista == nullptr || lista->is_empty() || lista->is_unitarian())
        return;

    Dlink * first = lista->get_first();

    while (first != lista && first->get_next() != lista)
    {
        Dlink * second = first->get_next();

        Dlink * before = first->get_prev();
        Dlink * after  = second->get_next();

        first->del();
        second->del();

        before->insert(second);
        second->insert(first);

        first = after;
    }
}

} // namespace Aleph
