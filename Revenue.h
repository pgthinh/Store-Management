void revenue(){
    clrscr();
    takebill();

    gotoxy(0,0);
    cout << setfill('*') << setw(49) << "\n";
    cout << "Day           Revenue            Profit      ";
    gotoxy(0,2);
    cout << setfill('*') << setw(49) << "\n";

    int cnt= 0;
    long long  sum;
    if (nbill == 1){
        gotoxy(0,3);
        cout << billinfors[1].date;
        gotoxy(14, 3);
        cout << billinfors[1].money;
        gotoxy(33, 3);
        cout << billinfors[1].money*0.2;
    }
    else{
        sum = billinfors[1].money;
        for (int i = 2 ; i <= nbill; i++)
        if (billinfors[i].date==billinfors[i-1].date)
            sum += billinfors[i].money;
        else{
            cnt++;
            gotoxy(0,2+cnt);
            cout << billinfors[i-1].date;
            gotoxy(14, 2+cnt);
            cout << sum;
            gotoxy(33, 2+cnt);
            cout << sum*0.2;
            sum = billinfors[i].money;
        }
    }

    cnt++;
    gotoxy(0,2+cnt);
    cout << billinfors[nbill].date;
    gotoxy(14, 2+cnt);
    cout << sum;
    gotoxy(33, 2+cnt);
    cout << sum*0.2;
    sum = billinfors[nbill].money;

    updatebill(0);
    _getch();
}
