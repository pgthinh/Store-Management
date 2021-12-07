///===== Variables =====
//Menu
string main_menu[7] = {" 1. Add & Current Item ", " 2. Restock ", " 3. Revenue & Profit ", " 4. Find & Delete ", " 5. Update Price & Quantity ", " 6. Customer Service ", " 7. Exit "};
const int main_menu_len = 7;
string customer_menu[6] = {" 1. Get Bill ", " 2. Customer Infor ", " 3. Rate ", " 4. Impossible (899 mines, 30*30 grid) ", " 5. Custom ", " 6. Return "};
const int customer_menu_len = 6;
string yes_no_menu[2] = {" YES ", " NO "};
const int yes_no_menu_len = 2;
string yes_no_menu1[3] = {" PRICE ", " AMOUNT ", " BOTH "};
const int yes_no_menu1_len = 3;
string yes_no_menu2[2] = {" FIND ", " DELETE "};
const int yes_no_menu_len2 = 2;
string yes_no_menu3[2] = {" 1. Create New Member Card ", " 2. List of member "};
const int yes_no_menu_len3 = 2;
string Level_Highscore[4] = {" EASY ", " INTERMEDIATE ", " EXPERT ", " IMPOSSIBLE "};

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
