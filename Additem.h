#include <string.h>
void loaditem(int n){
    ifstream f;
	f.open("data.txt", ios::in);

    SetColor(15);
    gotoxy(0, n+5);
    cout << setfill('*') << setw(51) << "\n";
    cout << "Item                Quantity       Price     ";
    gotoxy(0, n+7);
    cout << setfill('*') << setw(51) << "\n";

    string line, temp3, temp2;
	getline(f,line);

    long long cnt, temp, temp1 = 0;
    while (line.length() != 0){

        temp1++;
        items[temp1].name="";
        items[temp1].amount=0;
        items[temp1].price=0;
        temp2="";
        temp3="";
        cnt = 0;

        for (int j = 0; j <= line.length()-1 ; j++)
        if (line[j]== ' ' ){
            cnt++;
            if (cnt==1){
                for (int i = 1; i <= 20 - j ; i++)
                    cout << " ";
                temp = 20 - j;
            }
            else
                for (int i = 1; i <= 35 - j + 1 - temp; i++)
                    cout << " ";
        }
        else {
            if (cnt == 0){
                items[temp1].name = items[temp1].name + line[j];
                if (line[j+1]==' ') cout << items[temp1].name;
            }
            else if (cnt == 1){
                temp2 = temp2 + line[j];
                if (line[j+1]==' '){
                    items[temp1].amount = stoi(temp2);
                    cout << items[temp1].amount;
                }
            }
            else {
                temp3 = temp3 + line[j];
            }
        }
        items[temp1].price = stoi(temp3);
        cout << items[temp1].price;
        cout << '\n';
        getline(f,line);
	}
	f.close();
}

void additem(){
    clrscr();
    takedata();

    long long n, temp2, temp3, temp = nitem;
    bool check;
    string temp1;
    SetColor(11);
    cout << "If you just want to see current items, type 0 " << '\n';
    SetColor(15);
    cout << "Number of item you wish to add: ";
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cout << "Input name - quantity - price of item " << i << " : ";
        cin >>  temp1 >> temp2 >> temp3;
        check = false;
        for (int j = 1; j <= nitem; j++)
        if (items[j].name == temp1){
            items[j].amount += temp2;
            check = true;
        }
        if (!check){
            nitem++;
            items[nitem].name = temp1;
            items[nitem].amount = temp2;
            items[nitem].price = temp3;
        }
    }

    ofstream data;
    data.open("data.txt", ofstream::out | ofstream::trunc);
    for (int i = 1; i <= nitem; i ++)
        data << items[i].name << " " << items[i].amount << " " << items[i].price << '\n';

    SetColor(10);
    if (n >= 1) cout <<'\n' << "ADDED SUCCESSFULLY!" << '\n';

    data.close();
    loaditem(n);
    _getch();
}
