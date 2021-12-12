void Welcome(){
    ShowConsoleCursor(false);
    gotoxy(0, 0);
    cout << setfill('*') << setw(57) << "\n";
    gotoxy(0, 11);
    cout << setfill('*') << setw(57) << "\n";
    for(int i = 1; i <= 10; i++){
        gotoxy(0, i);
        cout << "*";
        gotoxy(55, i);
        cout << "*";
    }

    gotoxy(13, 2);
    SetColor(12);
    cout << "* * * ";
    SetColor(10);
    cout << "STORE MANAGEMENT";
    SetColor(12);
    cout << " * * *\n";

    gotoxy(17, 6);
    SetColor(9);
    cout << "/* Pham Gia Thinh */\n";


    gotoxy(15, 9);
    SetColor(15);
    cout << "Press any key to START!";

    _getch();
    clrscr();
}

int menu(string Menu[], int menu_len, string type, int x, int y, bool vertical){
    char n;
    int pos = 0;
    bool Back = false;

    while(true){
        show_menu(Menu, menu_len, pos, type, x, y, vertical);
        n = getch(); // Press key
        if(n == 72 || n == 75) pos = max(0, pos - 1); // Up or Left
        else if(n == 80 || n == 77) pos = min(menu_len - 1, pos + 1); // Down or Right
        else if(n == 13 or n == 32){ // Enter or SPACE
            if(type == "main"){
                if(pos == 0) additem();
                else if(pos == 1) restock();
                else if(pos == 2) revenue();
                else if(pos == 3) findanddelete();
                else if(pos == 4) update();
                else if(pos == 5) customermenu();
                else if(pos == 6) employee();
                else if(pos == 7) changepassword();
                else return 0;
            }
            else if(type == "update"){
                if (pos == 0){
                    updateprice(); break;
                }
                else if (pos == 1) {
                    updateamount(); break;
                }
                else if (pos == 2) {
                    updateboth(); break;
                }
            }
            else if(type == "again"){
                return !pos;
            }
            else if(type == "customer"){
                if(pos == 0) getbill();
                else if(pos == 1) customerinfor();
                else if(pos == 2) rate();
                else if(pos == 3) finditem();
                else break;
            }
            else if(type == "employee"){
                if(pos == 0) listemployee();
                else if(pos == 1) checkin();
                else if(pos == 2) checkout();
                else if(pos == 3) statistic();
                else break;
            }
        }
        else if(n == 27){ // ESC
            return 0;
        }
    }
}

void show_menu(string Menu[], int menu_len, int choose, string type, int x, int y, bool vertical){
    if(type != "again" && type != "update") system("cls");


    //Print menu
    for(int i = 0; i < menu_len; i++){
        if(vertical) gotoxy(y, x + i);
        else gotoxy(y + 8 * i, x);
        //Selecting now
        if(choose == i){
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, BACKGROUND_GREEN);
            cout << Menu[i] << endl;
            SetConsoleTextAttribute(h, 15);
        }
        //If not selected
        else{
            SetBGColor(16);
            SetColor(15);
            cout << Menu[i] << endl;
        }
    }
}
void changepassword(){
    string line, current, confirm, newpass;
    while (true){
        clrscr();

        ifstream f;
        f.open("pass.txt", ios::in);
        getline(f,line);
        f.close();
        SetColor(11);
        cout << "Current password: ";
        SetColor(15);
        cin >> current;

        SetColor(11);
        cout << '\n' << "New password: ";
        SetColor(15);
        cin >> newpass;
        SetColor(11);
        cout << '\n' << "Confirm password: ";
        SetColor(15);
        cin >> confirm;

        if (confirm == newpass && current == line){
            ofstream f;
            f.open("pass.txt", ios::out | ios::trunc);
            f << newpass;
            f.close();
            SetColor(10);
            cout <<'\n' << "Changed successfully!";
            SetColor(15);
            _getch();
            break;
        }
        else{
            SetColor(12);
            cout <<'\n' << "Please try again";
            SetColor(15);
            _getch();
        }
    }
}

bool password(){
    char x[10];
    string s = "", ss, pass;
    clrscr();
    SetColor(11);
    cout << "     PASSWORD     " << '\n';
    SetColor(15);

    for(int i=0; i<10;i++){
        x[i]=getch();
        cout<<"*";

        if(x[i]=='\r') //check if enter key is pressed
            break;
        else s = s+x[i];
    }

    ifstream f;
    f.open("pass.txt", ios::in);
    getline(f,pass);
    f.close();

    for (int i = 0; i <= s.length()-1; i++)
        if (s[i]!= ' ') ss +=s[i];

    if (ss==pass || (ss == defaultpass && pass.length()==0)){
        SetColor(10);
        cout << '\n' << "Logged in successfully!";
        _getch();
        return true;
    }
    else{
        SetColor(12);
        cout << '\n' << "Failed to log in, please try again";
        _getch();
        return false;
    }
}
