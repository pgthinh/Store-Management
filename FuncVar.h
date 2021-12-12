///===== Variables =====
//Menu
string main_menu[9] = {" 1. Add & Current Item ", " 2. Restock ", " 3. Revenue & Profit ", " 4. Find & Delete ", " 5. Update Price & Quantity ", " 6. Customer Service "," 7. Employee ", " 8. Change Password"," 9. Exit "};
const int main_menu_len = 9;
string customer_menu[5] = {" 1. Get Bill ", " 2. Customer Infor ", " 3. Rate & Feedback ", " 4. Find Items", " 5. Return "};
const int customer_menu_len = 5;
string yes_no_menu[2] = {" YES ", " NO "};
const int yes_no_menu_len = 2;
string yes_no_menu1[3] = {" Price ", " Amount ", " Both "};
const int yes_no_menu1_len = 3;
string yes_no_menu2[2] = {" Find ", " Delete "};
const int yes_no_menu_len2 = 2;
string yes_no_menu3[2] = {" 1. Create New Member Card ", " 2. List of member "};
const int yes_no_menu_len3 = 2;
string yes_no_menu4[2] = {" 1. Rate for us ", " 2. See feedback "};
const int yes_no_menu_len4 = 2;
string employee_menu[5] = {" 1. List ", " 2. Check-in ", " 3. Check-out ", " 4. Statistics ", " 5. Return "};
const int employee_menu_len = 5;
string defaultpass = "123";

///===== Function Prototype
struct billinfor{
    string date;
    int money;
};
billinfor billinfors[LEN_MAX];

struct item{
    string name;
    int amount;
    long long price;
};
item items[LEN_MAX];

//ConsoleText.h
void SetBGColor(WORD color);
void SetColor(WORD color);
void gotoxy(short x,short y);
void clrscr(void);
void ShowConsoleCursor(bool showFlag);
int WhichColor(char Cell);

//Menu.h
void Welcome();
int menu(string Menu[], int menu_len, string type, int x, int y, bool vertical);
void show_menu(string Menu[], int menu_len, int choose, string type, int x, int y, bool vertical);
bool password();
void changepassword();

//music.h
void Music();

//Additem.h
void additem();

//Saveboard.h
void takedata();
void updatedata();
void updatebill();
void takebill();
void updateinfor();
void takeinfor();

//Restock.h
void restock();

//Revenue.h
void revenue();
void show();

//FindandDelete
void finditem();
void deleteitem();
void findanddelete();

//UpdatePrice.h
void updateprice();
void update();
void updateamount();
void updateboth();

//Customer.h
void customermenu();
void getbill();
void customerinfor();
void rate();
void feedback();
void showfb();

//Employee.h
void employee();
void listemployee();
void checkin();
void checkout();
void statistic();
