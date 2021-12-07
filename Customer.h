#include <string.h>
#include<iostream>
#include<cmath>
#include <ctime>
void customermenu(){
    clrscr();
    menu(customer_menu, customer_menu_len, "customer", 0, 0, true);
}

void getbill(){
    clrscr();
    takebill();

    SetColor(15);
    SetBGColor(3);
    cout << "                      ---WELCOME TO OUR STORE---                     " << '\n';
    cout << '\n';

    SetBGColor(0);
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    cout << "Date: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< " " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << '\n';

    SetColor(10);
    cout << "Input the bill, when you have done type 0";

    SetColor(15);
    gotoxy(0, 4);
    cout << setfill('*') << setw(70) << '\n';
    cout << "Name                     Quantity                 Money           ";
    gotoxy(0,6);
    cout << setfill('*') << setw(70) << '\n';

    int i = 6;
    long long amount, sum = 0;
    string product;
    while (true){
        i++;
        gotoxy(0,i);
        cin >> product;
        if (product == "0") break;
        gotoxy(25,i);
        cin >> amount;
        for (int j = 1; j <= nitem; j++)
        if (items[j].name == product){
            sum += amount * items[j].price;
            gotoxy(50, i);
            cout << amount * items[j].price;
            items[j].amount -= amount;
        }
    }

    gotoxy(0,i+1);
    cout << setfill('*') << setw(70) << '\n';
    string temp = to_string(sum);
    gotoxy(39 ,i+2);
    cout << "Discount : ";
    int x;
    cin >> x;
    gotoxy(42 ,i+3);
    long long temp1 = sum - sum * x * 0.01;
    cout << "Total : " << temp1 << '\n';

    takebill();
    updatedata();
    updatebill(temp1);
    _getch();
}

void customerinfor(){
    clrscr();

    string name, phone;
    bool choose = menu(yes_no_menu3, yes_no_menu_len3, "again", 2 , 7 , true);
    if (choose){
        clrscr();
        ofstream f;
        f.open("infor.txt", ofstream::out | ofstream::app);

        SetColor(11);
        cout << "Name : ";
        SetColor(15);
        cin >> name;
        SetColor(11);
        cout << "Phone : ";
        SetColor(15);
        cin >> phone;
        f << name;
        for (int i = 1; i <= 29- name.length(); i++) f << " ";
        f << phone << '\n';
        SetColor(10);
        cout << '\n' << "CREATED SUCCESSFULLY!";

        f.close();
        _getch();
    }
    else {
        clrscr();
        ifstream f;
        f.open("infor.txt", ios::in);

        SetBGColor(3);
        cout << "                         MEMBER                         ";

        SetBGColor(0);
        gotoxy(0, 2);
        cout << setfill('*') << setw(57) << "\n";
        cout << "Name                         Phone";
        gotoxy(0, 4);
        cout << setfill('*') << setw(57) << "\n";

        string line;
        getline(f,line);

        while (line.length()!=0){
            cout << line<< '\n';
            getline(f,line);
        }
        _getch();
    }


}
