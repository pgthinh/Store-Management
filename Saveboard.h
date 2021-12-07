int nitem=0, nbill=0, ninfor = 0;
void takedata(){
    ifstream f;
	f.open("data.txt", ios::in);

	string line, temp3, temp2;
	getline(f,line);

    int cnt, temp, temp1 = 0;
    while (line.length() != 0){
        temp1++;
        items[temp1].name="";
        items[temp1].amount=0;
        items[temp1].price=0;
        temp2="";
        temp3="";
        cnt = 0;
        for (int j = 0; j <= line.length()-1 ; j++)
        if (line[j]== ' ' ) cnt++;
        else {
            if (cnt == 0)
                items[temp1].name = items[temp1].name + line[j];
            else if (cnt == 1){
                temp2 = temp2 + line[j];
                if (line[j+1]==' ')
                    items[temp1].amount = stoi(temp2);
            }
            else {
                temp3 = temp3 + line[j];
            }
        }
        items[temp1].price = stoi(temp3);
        getline(f,line);
	}
	f.close();
	nitem = temp1;
}

void updatedata(){
    ofstream data;
    data.open("data.txt", ofstream::out | ofstream::trunc);
    for (int i = 1; i <= nitem; i ++)
        data << items[i].name << " " << items[i].amount << " " << items[i].price << '\n';
    data.close();
}

void takebill(){
    ifstream f;
	f.open("bill.txt", ios::in);

	string line,temp2;
	int cnt, temp1=0, temp;
	getline(f,line);

	while (line.length() != 0){
        cnt = 0;
        temp1++;
        temp2="";
        billinfors[temp1].date = "";
        billinfors[temp1].money=0;
        for (int j = 0; j <= line.length()-1 ; j++)
        if (line[j]== ' ' ) cnt++;
        else  {
            if (cnt == 0)
                billinfors[temp1].date += line[j];
            else if (cnt == 1)
                temp2 = temp2 + line[j];
        }
        billinfors[temp1].money = stoi(temp2);
        getline(f,line);
	}

    nbill =  temp1 ;
    //for (int i = 1; i <= nbill; i++)
      // cout << billinfors[i].date << " " << billinfors[i].money << '\n';

    f.close();
}

void updatebill(int temp1){
    ofstream bill;
    bill.open("bill.txt", ofstream::out | ofstream::trunc);

    for (int i = 1; i <= nbill; i ++)
        bill << billinfors[i].date << " " << billinfors[i].money << '\n';

    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    if (temp1 != 0)
        bill << (tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< " " << temp1 << '\n';

    bill.close();
}

