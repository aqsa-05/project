#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
// GLOBAL ARRAYS
string usernames[100];
string passwords[100];
string roles[100];
int usercount = 0;
string members[100];
string ids[100];
string addresses[100];
string membern[100];
string memberid[100];
string memberaddress[100];
string membergmail[100];

// FUNCTIONS PROTOTYPES>>>>>>>>
void signUP(string username, string password);
bool signIn(string username, string password);
void storetofile(string username, string password);
bool isvalidusername(string username);
void loaddatafromfile();
void viewUsers();
int takechoice();
void addmember();
int adminMenu();
void adminfun();
string sellMembership();
void allotTrainer();
void searchRecords();
void deleteMembership();
void checkRecords();
void updateMembership();
void storeinfile1();
int membership();
void header();
void gheader();
void loaddatafromfile1();
string parseRecord(string line, int field);
void userMenu();
void createprofile();
void searchmembership();
void viewmembership();
void buymembership();
void ratemembership();
void editprofile();
void readfile();
void storeinfile2();
void loaddatafromfile2();
void readfile1();
void headerU();

// Variables Declaration
int usercount1 = 0;
string membershipType;
int count = 0;
int choice;
int membercount = 0;
// ParseRecord Declaration
string parseRecord(string line, int field)
{
    int commaCount = 1;
    string item;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + line[i];
        }
    }
    return item;
}
// validation
int function(int num)
{
    while(!(cin>>num))
    {
        cin.clear();
        cin.ignore(123,'\n');
        cout<<"Invalid input!! Put integer as an integer:";
    }
    return num;
}
//*********MAIN************

main()
{
    system("CLS");
    gheader();
    readfile();
    loaddatafromfile();
    loaddatafromfile1();
    loaddatafromfile2();
    string username;
    string password;
    string role;
    bool decision;
    bool check;

    int choice = 3;
    while (choice != 0)
    {
        choice = takechoice();
        if (choice == 1)
        {
            cout << "Enter username:";
            cin >> username;
            cout << "Enter password:";
            cin >> password;

            decision = isvalidusername(username);
            if (decision = true)
            {
                int choice1;
                signUP(username, password);
                storetofile(username, password);
                cout << "CREATED SUCCESSFULLY " << endl;
            }
            else
            {
                cout << "USERNAME ALREADY EXISTS" << endl;
            }
        }

        else if (choice == 2)
        {
            string username, password;
            cout << "enter username" << endl;
            cin >> username;
            cout << "enter password " << endl;
            cin >> password;
            cout << "Enter role";
            cin >> role;
            check = signIn(username, password);
            if (check = true)
            {
                cout << "login successfully";
                if (role == "admin")
                {
                    adminfun();
                }
                else if (role == "user")
                {
                    userMenu();
                }
            }

            getch();
        }
        else if (choice == 3)
        {
            viewUsers();
            break;
        }
    }
}
// SIGN UP>>>>>

void signUP(string username, string password)
{

    usernames[usercount] = username;
    passwords[usercount] = password;

    usercount++;
}
// ###.......... FILING........ #####
void storetofile(string username, string password)
{
    fstream file;
    file.open("users.txt", ios::app);
    file << username << endl
         << password << endl;
    file.close();
}
void viewUsers()
{
    cout << "USERNAME"
         << "\t\t"
         << "password" << endl
         << endl;
    for (int index = 0; index < usercount; index++)
    {
        cout << usernames[index] << passwords[index] << endl;
    }
}
// sign in>>>>>>>
bool signIn(string username, string password)
{
    bool isfound = false;
    for (int index = 0; index < usercount; index++)
    {
        if (usernames[index] == username && passwords[index] == password && roles[index] == "admin" || roles[index] == "user")
        {
            isfound = true;
            break;
        }
    }
    return isfound;
}

// is valiid
bool isvalidusername(string username)
{
    bool flag = false;
    for (int index = 0; index < usercount; index++)
    {
        if (usernames[index] != username)
        {
            flag = true;
            break;
        }
        return flag;
    }
}
// CHOICE>>>>>
int takechoice()
{
    cout << "-------- MAIN MENU-----------" << endl;
    int choice;
    int choise;
    cout << "1.SIGNUP" << endl;
    cout << "2.SIGNIN" << endl;
    cout << "3.VIEW USERS" << endl;
    cout << "0.exit" << endl;
    cout << "ENTER CHOICE:";
    choice = function(choise);
    return choice;
}
void loaddatafromfile()
{
    fstream file;
    string username;
    string password;
    file.open("users.txt", ios::in);
    while (getline(file, username) && getline(file, password))
    {

        usernames[usercount] = username;
        passwords[usercount] = password;
        usercount++;
    }
    file.close();
}
// ADMIN MENUEEEEE>>>>>>>
int adminMenu()
{

    int choice1;
    int choise;
    cout << "_________ADMIN MENUE____________" << endl;
    cout << "1 to add member" << endl;
    cout << "2.Sell silver or gold membership" << endl;
    cout << "3.Allot trainer" << endl;
    cout << "4.Search records" << endl;
    cout << "5.Delete membership" << endl;
    cout << "6.Check records" << endl;
    cout << "7.Update membership " << endl;
    cout << "8.go to main menue" << endl;
    cout << "Enter Choice:";
    
     choice1 = function(choise);
    return choice1;
}
// ADMIN FUNCTIONS>>>>>>>>>>>
void adminfun()
{
p:
    system("CLS");
    header();
    int option = adminMenu();
    if (option == 1)
    {
        addmember();
        adminfun();
    }
     if (option == 2)
    {
        sellMembership();
        adminfun();
    }
     if (option == 3)
    {
        allotTrainer();
        adminfun();
    }
     if (option == 4)
    {
        searchRecords();
        adminfun();
    }
     if (option == 5)
    {
        deleteMembership();
        adminfun();
    }
     if (option == 6)
    {
        checkRecords();
        adminfun();
    }
     if (option == 7)
    {
        updateMembership();
        adminfun();
    }
     if (option == 8)
    {
        takechoice();
    }
}
// FUNCTIONS>>>>>>>>>>>
void addmember()
{
    system("cls");
    cout << "############ ADD MEMBER ##############" << endl;

    cout << "Enter Member name:";
    cin >> members[count];
    cout << "Enter ID:";
    cin >> ids[count];
    cout << "Enter address:";
    cin >> addresses[count];
    cout << "Member added successfully"<<endl;
    storeinfile1();
    count++;
    getch();
}

void storeinfile1()
{
    fstream file;
    file.open("addmember.txt", ios::app);
    file << members[count] << "," << ids[count] << "," << addresses[count] << endl;
    file.close();
}
void loaddatafromfile1()
{

    fstream file;
    string member;
    string id;
    string address;
    file.open("addmember.txt", ios::in);
    while (!file.eof())

    {
        string record;
        getline(file, record);
        if (record != "")
        {
            member = parseRecord(record, 1);
            members[count] = member;
            id = parseRecord(record, 2);
            ids[count] = id;
            address = parseRecord(record, 3);
            addresses[count] = address;
            count++;
        }
    }
    file.close();
}
// SELL MEMBERSHIP>>>>>
string sellMembership()
{
    system("cls");
    string membershiptype;
    int goldcounter = 0;
    int silvercounter = 0;
    float total = 0;
    int choise;
    cout << "How many memberships you want to sell? "<<endl;
    choice = function(choise);
    for (int index = 0; index < choice; index++)
    {
        cout << "Enter the types of membership yo want to sell?"<<endl;
        cin >> membershiptype;
        if (membershiptype == "gold")
        {
            goldcounter++;
        }
        else if (membershiptype == "silver")
        {
            silvercounter++;
        }
    }
    /*cout << goldcounter << endl;*/
    //cout << silvercounter << endl;
    total = (goldcounter * 10000) + (silvercounter * 5000);
    cout << "Total is" << total << endl;
    getch();
}
// ALLOT  TRAINER........
void allotTrainer()
{
    system ("cls");
    string membership;
    cout << "Enter membership:"<<endl;
    cin >> membership;
    if (membership == "gold" || membership == "silver")
    {
        cout << "The trainer is alloted" << endl;
        cout << "press any key to continue";
        getch();
    }
    else
    {
        cout << "Invalid membership Since no trainer is alloted" << endl;
        cout << "press any key to continue";
        getch();
    }
}
// SEARCH RECORDS.........
void searchRecords()
{
     system("cls");
    string name1;
    cout << "Enter name:";
    cin >> name1;
    for (int index = 0; index < count; index++)
    {
        if ( members[index] == name1 )
        {
            cout << "The user is found successfully"<<endl;
            cout << members[index] << endl;
            cout << ids[index] << endl;
            cout << addresses[index] << endl;
        }
        else
        {
            cout << "User not found";
        }
       
    }
     cout<<"Press any key to continue";
     getch();
}
// DELETE MEMBERSHIP
void deleteMembership()
{
    system("cls");
    string word;
    cout << "Enter member id which you want to delete:"<<endl;
    cin >> word;
    int check = 0;
    if (count == 0)
    {
        cout << "The structure is empty" << endl;
    }
    for (int index = 0; index < count; index++)
    {
        if (word == ids[index])
        {
            cout << "Loading is in process please wait";
            for (int index = 0; index < 4; index++)
            {
                cout << ".";
                Sleep(1000);
            }
            for (int m = index; m < count; m++)
            {
                ids[m] = ids[m + 1];
                members[m] = members[m + 1];
                addresses[m] = addresses[m + 1];
            }
            storeinfile1();
            cout << endl;
            cout << "Deleted Successfully"<<endl;
            Sleep(1000);
            index--;
            break;
        }
    }
}
// CHECK RECORDS
void checkRecords()
{
    system("cls");
    cout << endl;
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Member name" << members[i] << endl;
        cout << "Member id" << ids[i] << endl;
        cout << "Member address" << addresses[i] << endl;
        cout << "##################################" << endl;
        cout << "\n\n"
             << endl;
    }
    getch();
}
// UPDATE MEMBERSHIP>>>>>>
void updateMembership()
{
    system("cls");
    string word;
    cout << "Enter the id of member which you want to edit:"<<endl;
    cin >> word;
    int check = 0;
    if (count == 0)
    {
        cout << "Structure is empty" << endl;
    }
    for (int index = 0; index < count; index++)
    {
        if (word == ids[index])
        {
            cout << "Enter member name:";
            getline(cin, members[index]);
            getline(cin, members[index]);
            cout << "Enter member address:";
            getline(cin, addresses[index]);
            cout << "Edit successfully"<<endl;
            check++;
            getch();
            break;
        }
    }
    if (check == 0)
    {
        cout << "Record is empty";
    }
    getch();
}
void readfile()
{
    fstream file;
    file.open("addmember.txt", ios::in);
    while (!file.eof())
    {
        string line = "";
        getline(file, line);
    
    }
}
// USER MENUE
void userMenu()
{
p:
    int option2;
    system("CLS");
    headerU();
    int choise;
    while (option2 != 6)
    {
        cout << "********** USER MENU***********" << endl;
        cout << "1.Create profile" << endl;
        cout << "2,Search Membership" << endl;
        cout << "3.Buy Membership" << endl;
        cout << "4.Rating Membership" << endl;
        cout << "5.Editting own profile" << endl;
        cout << "6.Go to control pannel" << endl;
        cout << "7.EXit the portal" << endl;
option2 = function(choise);
        if (option2 == 1)
        {
            createprofile();
        }
        if (option2 == 2)
        {
            searchmembership();
        }

        if (option2 == 3)
        {
            buymembership();
        }
        if (option2 == 4)
        {
            ratemembership();
        }
        if (option2 == 5)
        {
            editprofile();
        }
        if (option2 == 6)
        {
            userMenu();
        }
        if (option2 == 7)
        {
            exit(0);
        }
    }
}
// USER FUNCTIONS...........
void createprofile()
{
     system("cls");
    cout << "********** CREATING PROFILE***********" << endl;
    cout << "Enter your name:";
    cin >> membern[membercount];
    cout << "Enter your id:";
    cin >> memberid[membercount];
    cout << "Enter your address:";
    cin >> memberaddress[membercount];
    cout << "Enter your gmail:";
    cin >> membergmail[membercount];
    cout << "Your profile hass been created"<<endl;
    storeinfile2();
    membercount++;
}
void storeinfile2()
{
    fstream file;
    file.open("profile.txt", ios::app);
    file << membern[membercount] << "," << memberid[membercount] << "," << memberaddress[membercount] << "," << membergmail[membercount] << endl;
    file.close();
}
void loaddatafromfile2()
{

    fstream file;
    string member;
    string id;
    string address;
    string gmail;
    file.open("profile.txt", ios::in);
    while (getline(file, member) && getline(file, id) && getline(file, address) && getline(file, gmail))
    {
        membern[membercount] = member;
        memberid[membercount] = id;
        memberaddress[membercount] = address;
        membergmail[membercount] = gmail;
        membercount++;
    }
    file.close();
}
void readfile1()
{
    fstream file;
    file.open("profile.txt", ios::in);
    while (!file.eof())
    {
        string line = "";
        getline(file, line);
    
    }
}
// SEARCH MEMBERSHIP>>>>
void searchmembership()
{
    system("cls");
    string name;
    cout << "Enter the name of membership you want to search:";
    cin >> name;
    for (int index = 0; index < membercount; index++)
    {
        if (name == membern[index])
        {
            cout << "Membership already exist" << endl;
            cout << membern[index];
            cout << memberid[index];
            cout << memberaddress[index];
            cout << membergmail[index];
        }
       
    }
}
// BUY MEMBERSHIP
void buymembership()
{
    system("cls");
    string word;
    cout << "Enter the membership you want to buy";
    cin >> word;
    if (word == "gold" || word == "silver")
    {
        cout << "Membership has been bought" << endl;
    }
    else
    {
        cout << "you have not bought the membership" << endl;
    }
}
// RATE MEMBERSHIP
void ratemembership()
{
    system("cls");
    int stars[10];
    int countratting = 0;
    cout << "Enter Stars from 1 to 5:";
    cin >> stars[countratting];

    if (stars[countratting] > 5 || stars[countratting] < 1)
    {
        cout << "PLease enter from 1 to 5 ";
    }
    else
    {
        for (int index = 0; index < 10; index++)
        {
        }
        cout << "thanks for your feedback" << endl;
        cout<<"You have rated"<<stars[countratting]<<"stars"<<endl;
    }
    countratting++;
}
// Edit profile......
void editprofile()
{
    system("cls");
    string word;
    cout << "Enter the name of member which you want to Edit:";
    cin >> word;
    int check = 0;
    if (membercount == 0)
    {
        cout << "Structure is empty" << endl;
    }
    for (int index = 0; index < membercount; index++)
    {
        if (word == membern[index])
        {
            cout << "Edit your  name:";
            getline(cin, membern[index]);
            getline(cin, membern[index]);
            cout <<"Edit your id:";
            getline(cin,memberid[index]);
            cout << "Edit Your address:";
            getline(cin, memberaddress[index]);
            cout << "Edit successfully"<<endl;
            check++;
            getch();
        }
    }
    if (check == 0)
    {
        cout << "Record is empty";
    }
    getch();
}
// HEADER
void header()
{
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "***                                                                ***" << endl;
    cout << "***                          ADMIN MENU                            ***" << endl;
    cout << "***                                                                ***" << endl;
    cout << "***                                                                ***" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
// HEADER
void headerU()
{
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "***                                                                ***" << endl;
    cout << "***       _________   USER MAIN MENUE__________                    ***" << endl;
    cout << "***                                                                ***" << endl;
    cout << "***                                                                ***" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
void gheader()
{
system("color 03");

    cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl;
    cout << " @@@                                                          @@@ " << endl;
    cout << " @@@   GGGGGGGGG   YY      YY  MMM M       M MMM              @@@ " << endl;
    cout << " @@@   GG            YY  YY    MMM  M     M  MMM              @@@ " << endl;
    cout << " @@@   GG              YY      MMM   M   M   MMM              @@@ " << endl;
    cout << " @@@   GG              YY      MMM    M M    MMM              @@@ " << endl;
    cout << " @@@   GG   GGGG       YY      MMM           MMM              @@@ " << endl;
    cout << " @@@   GG     GG       YY      MMM           MMM              @@@ " << endl;
    cout << " @@@   GG     GG       YY      MMM           MMM              @@@ " << endl;
    cout << " @@@   GGGGGGGGG       YY      MMM           MMM              @@@ " << endl;
    cout << " @@@                                                          @@@ " << endl;
    cout << " @@@   ************MANAGEMENT SYSTEM*****************         @@@ " << endl;
    cout << " @@@                                                          @@@ " << endl;
    cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl;
}