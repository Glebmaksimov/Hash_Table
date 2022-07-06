
#include "Declarations.h"

int main() {
    Hash_Table<int,string> HT;

    cout<<endl;

    cout<<HT.empty()<<endl;

    cout<<endl;
    HT.insert(43,"John1");
    HT.insert(345,"John2");
    HT.insert(345,"John8");
    HT.insert(343,"John3");
    HT.insert(2345,"John4");
    HT.insert(543,"John5");
    HT.insert(345,"John6");
    cout<<endl;

    HT.print();

    cout<<endl;
    HT.remove(43);
    HT.remove(543);

    cout<<endl;

    HT.print();

    cout<<endl;

    cout<<HT.empty()<<endl;

    cout<<HT.search(343)<<endl;
    cout<<HT.get_table()->size()<<endl;

    return 0;
}

