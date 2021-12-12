#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <utility>
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
#include "Music.h"
#include "Saveboard.h"
#include "Additem.h"
#include "Restock.h"
#include "Revenue.h"
#include "FindandDelete.h"
#include "UpdatePrice.h"
#include "Customer.h"
#include "Employee.h"
/*
to do
*/
///==================== Main Program ====================
main(){

    srand(time(NULL));
    SetConsoleTitle("STORE MANAGEMENT - Pham Gia Thinh");
    ShowConsoleCursor(false);
 //   Music();
    Welcome();
    while(true){
        if (password()){
            menu(main_menu, main_menu_len, "main", 0, 0, true);
            break;
        }
    }
}
