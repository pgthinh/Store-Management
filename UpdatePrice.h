#include <string.h>
void update(){
    clrscr();
    SetColor(10);
    cout << "Do you want to update price , quantity or both ?";
    bool up = menu(yes_no_menu1, yes_no_menu1_len, "update", 2 , 12 , false);
}
void updateprice(){
    clrscr();
    takedata();
    loaditem(-5);

    SetColor(11);
    cout << '\n' << "The number of item you want to update price : ";

    long long n, temp;
    string s;
    SetColor(15);
    cin >> n;

    for (int i = 1 ; i <= n ; i++){
        cout << "Type name - new price : ";
        cin >> s >> temp;
        for (int j = 1; j <= nitem; j ++)
        if (s == items[j].name)
            items[j].price = temp;
    }
    SetColor(10);
    cout << '\n' << "UPDATED!";
    updatedata();

    _getch();
}

void updateamount(){
    clrscr();
    takedata();
    loaditem(-5);

    SetColor(11);
    cout << '\n' << "The number of item you want to update quantity : ";

    long long n, temp;
    string s;
    SetColor(15);
    cin >> n;

    for (int i = 1 ; i <= n ; i++){
        cout << "Type name - new quantity : ";
        cin >> s >> temp;
        for (int j = 1; j <= nitem; j ++)
        if (s == items[j].name)
            items[j].amount = temp;
    }
    SetColor(10);
    cout << '\n' << "UPDATED!";
    updatedata();

    _getch();
}

void updateboth(){
        clrscr();
    takedata();
    loaditem(-5);

    SetColor(11);
    cout << '\n' << "The number of item you want to update quantity & price : ";

    long long n, temp, temp2;
    string s;
    SetColor(15);
    cin >> n;

    for (int i = 1 ; i <= n ; i++){
        cout << "Type name - new quantity - new price : ";
        cin >> s >> temp >> temp2;
        for (int j = 1; j <= nitem; j ++)
        if (s == items[j].name){
            items[j].amount = temp;
            items[j].price = temp2;
        }
    }
    SetColor(10);
    cout << '\n' << "UPDATED!";
    updatedata();

    _getch();
}
