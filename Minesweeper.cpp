#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <mmsystem.h>

#define LEN_MAX 100000

using namespace std;

#include "FuncVar.h"
#include "ConsoleText.h"
#include "Menu.h"
#include "Display.h"
#include "Music.h"
#include "Saveboard.h"
#include "Additem.h"
#include "Restock.h"
#include "Revenue.h"
#include "FindandDelete.h"
#include "UpdatePrice.h"
#include "Customer.h"
/* To-do list
        bill
        rate
        information of customer

*/
///==================== Main Program ====================
main(){

    srand(time(NULL));
    SetConsoleTitle("STORE MANAGEMENT - Pham Gia Thinh");
    ShowConsoleCursor(false);
  //  Music();
    Welcome();
    clrscr();
    menu(main_menu, main_menu_len, "main", 0, 0, true);
}
