void listemployee(){
    clrscr();
    ifstream f;
    f.open("employee.txt", ios::in);

    SetBGColor(3);
    cout << "                  EMPLOYEE INFORMATION                  ";
    SetBGColor(0);
    gotoxy(0, 2);
    cout << setfill('*') << setw(57) << "\n";
    cout << "Name                         Phone";
    gotoxy(0, 4);
    cout << setfill('*') << setw(57) << "\n";

    string line, name, phone;
    getline(f,line);

    while (line.length()!=0){
        cout << line<< '\n';
        getline(f,line);
    }

    _getch();
    SetColor(10);
    gotoxy(60, 2);
    cout << "Do you want to add ?" << '\n';
    SetColor(15);
    bool choose = menu(yes_no_menu, yes_no_menu_len, "again", 3 ,  65 , false);
    if (choose){
        clrscr();
        ofstream f;
        f.open("employee.txt", ofstream::out | ofstream::app);

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
        cout << "ADDED SUCCESSFULLY!";
        _getch();
    }
}

void checkin(){
    clrscr();
    ofstream f;
    f.open("checkinout.txt", ofstream::out | ofstream::app);

    string name;

    SetBGColor(0);
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    cout << "Date: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< " " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << '\n';

    cout << "Name: ";
    cin >> name;

    SetColor(10);
    cout <<'\n' << "DONE!";
    f <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< " " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << " " << name << " OUT" << '\n';
    f.close();;

    _getch();
}

void checkout(){
    clrscr();
    ofstream f;
    f.open("checkinout.txt", ofstream::out | ofstream::app);

    string name;

    SetBGColor(0);
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    cout << "Date: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< " " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << '\n';

    cout << "Name: ";
    cin >> name;

    SetColor(10);
    cout <<'\n' << "DONE!";
    f <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< " " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << " " << name << " OUT" << '\n';
    f.close();

    _getch();
}

void statistic(){
    clrscr();
    ifstream f;
    f.open("checkinout.txt", ios::in);

    SetBGColor(3);
    cout << "                         STATISTICS                        " << '\n';
    SetBGColor(0);
    cout << '\n' << setfill('*') << setw(60) << "\n";
    cout << "Date                       Name                  Check       " << '\n';
    cout << setfill('*') << setw(60) << "\n";

    string line;
    getline(f,line);
    int temp = 4, cnt;
    while (line.length()!=0){
        cnt = -1;
        temp ++;
        for (int i = 0; i <= line.length()-1; i++)
        if (line[i]==' ' && cnt == -1){
            cnt++;
            cout << " ";
        }
        else if (line[i]==' ' && cnt == 0){
            cnt++;
            gotoxy(27, temp);
        }
        else if (line[i]==' ' && cnt ==1) gotoxy(49,temp);
        else cout << line[i];
        cout << '\n';
        getline(f,line);
    }
    f.close();
    _getch();
}

void employee(){
    clrscr();
    menu(employee_menu, employee_menu_len, "employee", 0, 0, true);
}
