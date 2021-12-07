
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
                else if(pos == 2) revenue();
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
