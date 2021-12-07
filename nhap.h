
void show(){
    clrscr();
    ifstream f;
	f.open("profit.txt", ios::in);

	gotoxy(0,0);
    cout << setfill('*') << setw(47) << "\n";
    cout << "Day         Revenue            Profit      ";
    gotoxy(0,2);
    cout << setfill('*') << setw(47) << "\n";

	string line;
    int cnt = 0, temp;

    getline(f,line);
    while (line.length()!=0){
        cnt++;
        gotoxy(0,2+cnt);
        cout << cnt;
        gotoxy(12, 2+cnt);
        cout << line;
        getline(f,line);
        gotoxy(31, 2+cnt);
        cout << line;
        getline(f,line);
    }
    _getch();
}
void revenue1(){

    clrscr();
    takedata();

    SetColor(11);
    cout << "TYPE THE QUANTITY OF EACH ITEM YOU SOLD TODAY" << '\n' ;

    double sum = 0, res = 0, a[LEN_MAX];
    SetColor(15);

    for (int i = 1; i <= nitem; i++){
        cout << items[i].name;
        for (int j = 1; j <= 20 - items[i].name.length(); j++) cout << " ";
        cout << ": ";
        cin >> a[i];
        if (a[i] > res)
            res = a[i];
        sum = sum + a[i]* items[i].amount;
    }

    SetColor(12);
    if (res != 0){
        cout << '\n' << "Best-seller : " << '\n';
        SetColor(15);
        for (int i = 1; i <= nitem; i++)
        if (a[i]==res)
            cout << "              " << items[i].name << '\n';
    }

    SetColor(1);
    cout << '\n' << "REVENUE : " << sum << '\n' << "PROFIT  : " << sum * 0.2 << '\n';

    ofstream profit;
    profit.open("profit.txt", ofstream::out | ofstream::app);
    profit << sum << '\n' << sum*0.2 << '\n';
    profit.close();

    SetColor(10);
    gotoxy (48, 5);
    cout << "Do you want to see revenue and profit several days?";
    bool See = menu(yes_no_menu, yes_no_menu_len, "again", 6 , 67 , false);
    if (See) show();

}
