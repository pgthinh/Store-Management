void addrestock(){
    clrscr();
    cout << "Input the quantity you wish to restock";

    gotoxy(0,3);
    cout << setfill('*') << setw(59) << "\n";
    cout << "      Item          Quantity         Restock     ";
    gotoxy(0, 5);
    cout << setfill('*') << setw(59) << "\n";

    int cnt = 0;
    for (int i = 1; i <= nitem; i++)
    if (items[i].amount == 0){
        cnt++;
        cout << items[i].name;
        for (int j = 1; j <= 20 - items[i].name.length(); j++) cout << " ";
        cout << items[i].amount;
        gotoxy(37 , cnt+5);
        cin >> items[i].amount;
    }

    int temp;
    for (int i = 1; i <= nitem; i++)
    if (items[i].amount <= 5 && items[i].amount > 0){
        cnt++;
        cout << items[i].name;
        for (int j = 1; j <= 20 - items[i].name.length(); j++) cout << " ";
        cout << items[i].amount;
        gotoxy(37,cnt+5);
        cin >> temp;
        items[i].amount +=temp;
    }

    cout << '\n';
    SetColor(10);
    cout << "DONE!";

    updatedata();
}
void restock(){

    takedata();
    clrscr();

    SetColor(10);
    cout << "Have to restock: " << '\n';

    bool check =false;
    SetColor(15);
    for (int i = 1; i <= nitem; i++)
    if (items[i].amount == 0){
        check = true;
        cout << items[i].name;
        for (int j = 1; j <= 20 - items[i].name.length(); j++) cout << " ";
        cout << items[i].amount << '\n';
    }

    cout << '\n';

    SetColor(10);
    cout << "Should restock: " << '\n';

    SetColor(15);
    for (int i = 1; i <= nitem; i++)
    if (items[i].amount <= 5 && items[i].amount > 0){
        check = true;
        cout << items[i].name;
        for (int j = 1; j <= 20 - items[i].name.length(); j++) cout << " ";
        cout << items[i].amount << '\n';
    }
    cout << '\n';

    SetColor(12);
    gotoxy(30, 5);
    _getch();
    if (check) {
        SetColor(10);
        cout << "Do you want to restock any of them?" << '\n';
        cout << '\n';
        bool Restock = menu(yes_no_menu, yes_no_menu_len, "again", 6 , 42 , false);
        if (Restock) {
            addrestock();
            _getch();
        }
    }
}
