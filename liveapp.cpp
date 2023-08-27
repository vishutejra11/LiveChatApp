// #include <iostream>
// #include <map>
// #include <vector>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void page1();
void page2(string);

// char *waiting;

map<string, string> user;

class frnd
{
    vector<string> flist;
    struct chat
    {
        int message_id;
        string sender, receiver;
        char mess[50][100];
        int num_of_message = 0;
    };

public:
    map<string, chat> sms;   
    void addfrnd(string);
    void unfrnd();
    void dispfrnd(string);
    void chat_on(string, string, char *);
    void inbox(string);
};

void frnd::chat_on(string uname, string reciepient, char *message)
{
    int i;
    char cuname[20];
    for (i = 0; uname[i] != '\0'; i++)
    {

        cuname[i] = uname[i]; // name transfer
    }
    strcpy(sms[reciepient].mess[sms[reciepient].num_of_message], cuname);
    strcat(sms[reciepient].mess[sms[reciepient].num_of_message], ":  ");
    strcat(sms[reciepient].mess[sms[reciepient].num_of_message], message);

    sms[reciepient].num_of_message++;
}

void frnd::inbox(string uname)
{
    cout << "\nWelcome " << uname << " to your Inbox\n\n";
    cout << "All Messages in your Inbox:\n\n";
    for (int i = 0; i <= sms[uname].num_of_message; i++)
    {
        puts(sms[uname].mess[i]);
        cout << endl
             << endl;
    }
}

void frnd::addfrnd(string uname)
{
    vector<string>::iterator iv;
    map<string, string>::iterator iuser;
    int flag = 0, flag3 = 0;
A:
    string addname;
    cout << "\nEnter the name which you want to add in your friend list:- ";
    cin >> addname;
    // cout << "\nPlease wait! checking for  " << addname << "......\n";
    
    if(addname==uname)
       {
        cout << "\nSorry! Can't add yourself to your friend list\n";
        goto A;
       }
    for (iuser = user.begin(); iuser != user.end(); iuser++)
    {
        for (iv = flist.begin(); iv != flist.end(); iv++)
        {
            if (*iv == addname)
                flag3++;
        }
         if (iuser->first == addname)
            flag++;
    }
    if (flag == 1  && flag3 == 0)
    {
        cout << "\nFound\t" << addname << endl;
        flist.push_back(addname);
        cout << "\nCongratulations! " << addname << " has been added to your friend list\n"
             << endl;
    }
    else if (flag == 0)
    {
        cout << "\nSorry!! this username does not exist\n";
    }
    else if (flag3)
    {
        cout << "\n"
             << addname << " already exists in your friend list\n";
    }
}

void frnd::dispfrnd(string uname)
{
    int c = 1;
    vector<string>::iterator i;
    i = flist.begin();
    cout << "\nWelcome " << uname << " Your Friends are:- \n"
         << endl;
    for (; i != flist.end(); i++)
    {
        cout << c << "-->" << *i << endl;
        c++;
    }
    cout << endl
         << "\nTotal friends: " << --c;
}

void frnd::unfrnd()
{
    if (flist.empty())
    {
        cout << "\nFriend list empty..!!\a\n";
    }
    else
    {
        int c = 0, pos = 0, flag = 0;
        string name;
        cout << "\nenter the friend name you want to unfriend \n";
        cin >> name;
        vector<string>::iterator i;
        i = flist.begin();

        for (; i != flist.end(); i++)
        {
            c++;
            if (*i == name)
            {
                flag++;
                pos = c - 1;
                break;
            }
        }

        i = flist.begin();
        if (pos || flag)
        {
            cout << "\n Removing " << name << " from your friend list..\a\a\a\a\n";
            flist.erase(i + pos);
            cout << name << " has been successfully removed from your friend list\n";
        }
        if (flag == 0 && pos == 0)
        {
            cout << "\nNo such friend exists in your friend list\n";
        }
    }
}

void page1()
{
    int flag = 0, choice;

    cout << "\n\t\t\tWELCOME TO THE V-MESSENGER\n";

    while (1)
    {
        cout << endl
             << endl;
        cout << "\nPlease Enter your choice\n  1-Sign_up\n  2-Sign_in\n  3-Display All user\n  4-Exit \n \n"
             << endl;
        cout << "Enter your choice:- ";
        cin >> choice;

        switch (choice)
        { //
        case 1:
        {

            string username, pwd;
            cout << "\nchoose a username:- ";
            cin >> username;
            cout << "\nchoose a password:- ";
            cin >> pwd;
            cout << endl
                 << endl;

            if (user.empty())
            {
                user[username] = pwd;
            }
            else
            {
                int flag0=0;
                map<string, string>::iterator iuser;
                for (iuser = user.begin(); iuser != user.end(); iuser++)
                {
                    if (iuser->first == username)
                    {
                        cout << "\nSorry! username already available..please try with some other name\n";
                        flag0=1;
                        break;
                    }
                }
                if(flag0==0)
                 user[username] = pwd;
                  
            }
            break;
        }

        case 2:
        {

            string lusername, lpwd;
            cout << "\nenter your username:- ";
            cin >> lusername;
            cout << "\nenter your password:- ";
            cin >> lpwd;
            map<string, string>::iterator iuser;
            for (iuser = user.begin(); iuser != user.end(); iuser++)
            {
                if (iuser->first == lusername && iuser->second == lpwd)
                {
                    cout << "\nWELCOME " << lusername << "!!  You have successfully logged in \n";

                    flag = 1;
                    page2(lusername);
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "\nusername or password incorrect\n\t!!Please try again\n";
                break;
            }

            break;
        }

        case 3:
        {

            map<string, string>::iterator iuser;
            cout << "\n\n---------All Users---------\n";
            int count = 1;
            for (iuser = user.begin(); iuser != user.end(); iuser++)
            {
                cout << count << "-->" << iuser->first << endl;
                count++;
            }
            count = 1;
            break;
        }
        case 4:
           {
            exit(0);
           }
        default:
        {
            // exit(0);
            cout<<"You Entered Wrong Choice\n";
            break;
        }
        }

        if (flag == 1)
        {
            break;
        }
    }
}

map<string, frnd> f;
 
void page2(string uname)
{

    int choice2, choice3;
main_menu:
    // goto statment
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
    // cout << "\t\t\t     ⓦⓔⓛⓒⓞⓜⓔ    " << uname << endl
    //      << endl;

    cout << "\t\t__          ________ _      _____ ____  __  __ ______ " << endl;
    cout << "\t\t\\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____|" << endl;
    cout << "\t\t \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__   " << endl;
    cout << "\t\t  \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|  " << endl;
    cout << "\t\t   \\  /\\  /  | |____| |___| |___| |__| | |  | | |____ " << endl;
    cout << "\t\t    \\/  \\/   |______|______\\_____\\____/|_|  |_|______|" << endl;

    cout << "\n\t    ***********Choose from following menu**********\n";
    cout << "\n1-Inbox\n2-Chat\n3-Friend_list\n4-Add friend\n5-Unfriend\n6-Broadcast\n7-Log out\n";
    cout << "Enter Your Choice:- ";
    cin >> choice2;
    switch (choice2)
    {
    case 1:
    {

        f[uname].inbox(uname);
        cout << "\npress any number except '0' to go back to main menu\n";
        cin >> choice3;
        if (choice3)
            goto main_menu;

        break;
    }
    case 2:
    {
        string reciepient;
        cout << "\nPlease enter the reciepient's name:\n";
        cin >> reciepient;
        if(reciepient==uname)
           {
            cout<<"You can't sent message to yourself\n";
            goto main_menu;
           }
           int c=0;
         for(auto p:user)
           {
            if(p.first==reciepient)
                 {
                    c++;
                    break;
                 }
           }
           if(c==0)
              {
                cout<<"User "<<reciepient<<" is not exists\n";
                goto main_menu;
              }
        char message[100];
        cout << "\nPlease Type Your message :" << endl;
        cin.ignore();
        cin.getline(message, 100);
        f[reciepient].chat_on(uname, reciepient, message);
        cout << "\nYour message has been sent\n";
        cout << "\npress any number except '0' to go back to main menu\n";
        cin >> choice3;
        if (choice3)
            goto main_menu;

        break;
    }
    case 3:
    {
        f[uname].dispfrnd(uname);
        cout << "\npress any number except '0' to go back to main menu\n";
        cin >> choice3;
        if (choice3)
            goto main_menu;
        break;
    }
    case 4:
    {
        f[uname].addfrnd(uname);
        cout << "\npress any number except '0' to go back to main menu:-- ";
        cin >> choice3;
        if (choice3)
            goto main_menu;
        break;
    }
    case 5:
    {
        f[uname].unfrnd();
        cout << "\npress any number except '0' to go back to main menu\n";
        cin >> choice3;
        if (choice3)
            goto main_menu;
        break;
    }

    case 6:
    {

        char ch;

        vector<string> rec;
        map<string, string>::iterator iuser;
        vector<string>::iterator irec;
    group:
        int flag = 0;
        string reciepient;
        cout << "Enter reciepient";
        cin >> reciepient;
        if(reciepient==uname)
          {
            cout<<"You can't Broadcast YourSelf\n";
            goto group;
          }
        for (iuser = user.begin(); iuser != user.end(); iuser++)
        {
            if (iuser->first == reciepient)
            {
                flag++;
                break;
            }
        }
        if (!flag)
        {
            cout << "\nSorry!! No such user exist\a\a\n";
            goto group;
        }   
        rec.push_back(reciepient);
        cout << "Do you want to add more reciepients (y/n)?\n";
        cin >> ch;

        if (ch == 'y')
            goto group;

        else if (ch == 'n')
        {
            char message[100];
            cout << "\nPlease Type Your message :" << endl;
            cin.ignore();
            cin.getline(message, 100);
            for (irec = rec.begin(); irec != rec.end(); irec++)
            {
                f[*irec].chat_on(uname, *irec, message);
            }
        }
        cout << "\nYour message has been sent\n";
        cout << "\npress any number except '0' to go back to main menu\n";
        cin >> choice3;
        if (choice3)
            goto main_menu;
        break;
    }

    case 7:
    {

        cout << "\nyou have been successfully logged out\n";

        page1();

        break;
    }
    }
}

int main()
{
    page1();
    return 0;
}
