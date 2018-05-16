#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include "SNA2.h"
#include "sysfiles.h"

using namespace std;


// System States
bool profile_viewed = false;  string profile_viewed_name;
bool admin_mode = false;
bool logged_in = false;
// false: Logged in and staying in home.txt
//  true: viewed a profile
// This is useful to be used as a condition in writing specefic commands
/////////////////////////////


string extract_command(string text);
string trim_input(string text); //still buggy so it's not used for now



int main(int argc, char* argv[])
{
    //Database.open("database.txt");
    database_init();
    User current_user;
    string user_input;
    string command;
    //string command;//(extract_command(user_input));
    do
    {
        cout << "$ ";
        getline(cin, user_input);
		command = extract_command(user_input);
		cout << "\n";
        //user_input.assign(trim_input(user_input));
        //if(user_input.find(' '))
        //    command.assign(extract_command(user_input));
        //else
        //    command.assign(user_input);

        //cout << " ";
        //cout << command << endl;
        //cout << command.length() << endl;



        if(command == "Register")
        {
			if ((!logged_in) || (admin_mode && (!profile_viewed)))
			{
				cout << "\nPlease, register your info: " << endl;
				string Name, Mail, Password;
				int Age;
				cout << "Name: ";
				getline(cin, Name);
				cout << "Age: ";
				cin >> Age;
				cout << "Mail: ";
				cin >> Mail;
				cout << "Password: ";
				cin >> Password;
				database_update(Mail, Password);
				current_user.Register(Name, Mail, Password, Age);
			}
			else
			{
				cout << "you must logout first!" << endl << endl;
			}
        }
        else if(command == "Login")
        {
			if (admin_mode)
			{
				cout << "you are already logged-in as admin" << endl << endl;
			}
			else if (!logged_in)
			{
				string Mail, Password;
				cout << "\nPlease, write your mail and password\nMail: ";
				cin >> Mail;
				cout << "Password: ";
				cin >> Password;
				current_user.Login(Mail, Password);
				logged_in = true;
			}
			else
			{
				cout << "you are already logged-in!" << endl << endl;
			}
        }
        /*
        else if(command == "Search")
        {
            cout << "Hello, Madboly!" << endl;
        }
        else if(command == "ViewProfile")
        {

        }
        */
        else if(command == "EditProfile")
        {
			if (profile_viewed && (!admin_mode))
			{
				cout << "please, enter your password first: ";
				string user_pass;
				cin >> user_pass;
				if (user_pass == current_user.get_password())
				{
					current_user.Edit_User_Profile();
				}
				else
				{
					cout << "wrong password!" << endl << endl;
				}
			}
			else if (profile_viewed && admin_mode)
			{
				current_user.Edit_User_Profile();
			}
			else if ((!admin_mode) && (!logged_in))
			{
				cout << "you must login first!" << endl << endl;
			}
			else
			{
				cout << "you are not in anyone's profile!" << endl << endl;
			}
        }
	else if (command == "ViewProfile")
	{
		if (!profile_viewed)
		{
			profile_viewed_name.clear();
		}

		if (logged_in || admin_mode)
		{
			string Mail = user_input.substr(user_input.find(" ") + 1);
			current_user.View_User_Profile(Mail);
			profile_viewed_name = Mail;
		}
		else
		{
			cout << "you must login first!" << endl << endl;
		}
	}
        else if(command == "BrowseFriends")
        {
			if (profile_viewed)
			{
				current_user.Browse_User_Friends(profile_viewed_name);
			}
			else
			{
				cout << "you are not in anyone's profile!" << endl << endl;
			}
        }
		/*
        else if(command == "Add")
        {

        }
        else if(command == "Reject")
        {

        }
        else if(command == "DeleteProfile")
        {

        }
        else if(command == "Post")
        {

        }
        else if(command == "Like")
        {

        }
		*/
        else if(command == "Switch")
        {
			string role = user_input.substr(user_input.find(" ") + 1);
			if (role == "Admin")
			{
				admin_mode = true;
				logged_in = false;
				cout << "you are now in Admin Mode" << endl << endl;
			}
			else if(role == "User")
			{
				admin_mode = false;
				logged_in = false;
				cout << "you are now in User Mode" << endl << endl;
			}
			else
			{
				cout << "Invalid Role!\nhint: write Admin or User." << endl << endl;
			}
        }
        else if((command == "exit") || (command =="quit"))
        {
            break;
        }
		else if (command == "help")
		{
			system_help();
		}
		else
		{
			cout << "Invalid Command!\nhint: if you are stuck, type help\n" << endl;
		}

    }while(1);

    return 0;
}


string trim_input(string text)
{
    int new_length = text.length();
    int i = new_length - 1;
    while(text[i] == ' ')
    {
        new_length--;
        i--;
    }
    i = 0;
    while(text[i] == ' ')
    {
        //text[i] = '\0';
        new_length--;
        i++;
    }

    string trimmed_text(text.substr(i, new_length));

    return trimmed_text;
}


string extract_command(string text)
{
	int text_len = text.length();
	int i;
	for (i = 0; i < text_len; i++)
	{
		if (text[i] == ' ')
			break;
	}
    //command_length = text.find(" ");
    string command = text.substr(0, i);
    return command;
}

