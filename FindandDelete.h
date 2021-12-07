#include <string.h>
void finditem(){
    takedata();

do{
    clrscr();
    SetColor(11);
    cout << "Input the item you want to find : ";

    SetColor(15);
    string s;
    cin >> s;
    cout << '\n';

    bool check = false;
    for (int i = 1; i <= nitem; i ++)
    if (s==items[i].name){
        check = true;
        cout << items[i].name << '\n' << "Quantity : " << items[i].amount << '\n' << "Price : " << items[i].price;
        break;
    }

    SetColor(12);
    if (!check) cout << "This item does not exist!" << '\n';
    _getch();

    clrscr();
    SetColor(10);
    cout << "Do you want to continue finding ?" << '\n';
    bool findi = menu(yes_no_menu, yes_no_menu_len, "again", 2 , 7 , false);

    if (!findi) break;
} while (true);

}

void deleteitem(){
    clrscr();
    takedata();

    int n;
    string s;
    bool free[LEN_MAX];
    for (int i = 1; i <=nitem; i++) free[i]=true;
do{
    clrscr();
    loaditem(-5);
    SetColor(11);
    cout << '\n' << "The number items you want to delete : ";
    cin >> n;

    SetColor(15);
    for (int i = 1; i <= n; i ++){
        cout << "Type the name of item " << i << " : ";
        cin >> s;
        for (int j = 1 ; j <= nitem; j++)
        if (s==items[j].name)
            free[j]=false;
    }

    SetColor(10);
    if (n != 0 ) cout << '\n' << "DELETED!" << '\n';
    _getch();

    clrscr();
    SetColor(10);
    cout << "Do you want to continue deleting ?" << '\n';
    bool dlti = menu(yes_no_menu, yes_no_menu_len, "again", 2 , 7 , false);

    if (!dlti) break;
} while (true);

    ofstream data;
    data.open("data.txt", ofstream::out | ofstream::trunc);
    for (int i = 1; i <= nitem; i ++)
    if (free[i])
        data << items[i].name << " " << items[i].amount << " " << items[i].price << '\n';
    data.close();

}
void findanddelete(){
    clrscr();
    SetColor(10);
    cout << "Do you want to find or delete item ?" << '\n';
    bool findi = menu(yes_no_menu2, yes_no_menu_len2, "again", 2 , 7 , false);
    if (findi) finditem();
    else deleteitem();
}
