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


//Universal
int uni_ID = load_ID();

int main()
{
    //database_init();
    User current_user;
	User target_user;
	cout << "Welcome our guest ^_^" << endl << endl;
    do
    {
        cout << "$ ";
		string user_input;
		string command;
        getline(cin, user_input);
		command = extract_command(user_input);
		cout << "\n";

        if(command == "Register")
        {
			//for (int i = 0; i < 1000000; i++);
			if ((!logged_in) || (admin_mode && (!profile_viewed)))
			{
				cout << "Please, register your info: " << endl;
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
				system("cls");
				database_update(Mail, Password);
				current_user.Register(Name, Mail, Password, Age);
				cin.ignore();
				//string crap;
				//cin >> crap;
			}
			else
			{
				cout << "you must logout first!";
			}
        }
        else if(command == "Login")
        {
			if (admin_mode)
			{
				cout << "you are already logged-in as admin";
			}
			else if (!logged_in)
			{
				string Mail, Password;
				cout << "Please, write your mail and password\nMail: ";
				cin >> Mail;
				cout << "Password: ";
				cin >> Password;
				system("cls");
				current_user.Login(Mail, Password, logged_in);
				cin.ignore();
				if(logged_in)
				{ 
					current_user.Import_User(Mail);
					current_user.Load_Requests();
					current_user.Load_Friends();
					current_user.Load_Post();
					uni_ID = load_ID();

					int user_requests = current_user.Requests.size();
					if (user_requests > 0)
					{
						cout << endl << "you have " << user_requests << " new requests";
					}
				}
			}
			else
			{
				cout << "you are already logged-in!";
			}
        }
		else if (command == "Logout")
		{
			admin_mode = false;
			profile_viewed = false;
			logged_in = false;
			current_user.Delete_Profile();
			current_user.Save_Requests();
			current_user.Save_Friends();
			current_user.Save_Post();
			current_user.Requests.clear();
			current_user.Friends.clear();
			current_user.Posts.clear();
			save_ID(uni_ID);
			system("cls");
			cout << "Loggged out successfully!";
		}
		/*
        else if(command == "Search")
        {
			if (logged_in)
			{
				system("cls");
				string Name = user_input.substr(user_input.find(" ") + 1);
			}
			else
			{
				cout << "you must login first!";
			}
        }*/
        else if(command == "EditProfile")
        {
			string current_mail = current_user.get_mail();
			string target_mail = target_user.get_mail();
			if (profile_viewed && (!admin_mode) && (current_mail == target_mail))
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
					cout << "wrong password!";
				}
			}
			else if (profile_viewed && admin_mode)
			{
				current_user.Edit_User_Profile();
			}
			else if ((!admin_mode) && (!logged_in))
			{
				cout << "you must login first!";
			}
			else if (current_mail != target_mail)
			{
				cout << "Access Denied: This is not your profile";
			}
			else
			{
				cout << "you are not in anyone's profile!";
			}
        }
		else if (command == "ViewProfile")
		{
			if (logged_in)
			{
				system("cls");
				string Mail = user_input.substr(user_input.find(" ") + 1);
				target_user.Import_User(Mail);
				current_user.View_User_Profile(Mail);
				profile_viewed_name = Mail;
				profile_viewed = true;
			}
			else
			{
				cout << "you must login first!";
			}
		}
        else if(command == "BrowseFriends")
        {
			if (profile_viewed)
			{
				int user_friends = current_user.Friends.size();
				cout << "(Friends)" << endl << endl;
				for (int i = 0; i < user_friends; i++)
				{
					cout << "name: " << current_user.Friends[i].Name << endl;
					cout << "mail: " << current_user.Friends[i].Mail << endl;
					cout << endl;
				}
			}
			else
			{
				cout << "you are not in anyone's profile!";
			}
        }
        else if(command == "Add")
        {
			if (logged_in && (!profile_viewed))
			{
				string mail, name;

				//passing   
				parse_command(user_input, command, mail, name);
				char MAIL[70];
				char NAME[50];

				strcpy_s(MAIL, mail.c_str());
				strcpy_s(NAME, name.c_str());

				current_user.Add_Friend(MAIL, NAME);
				system("cls");
				cout << "you sent a request to " << name;
			}
        }
		else if (command == "ViewRequests")
		{
			if (profile_viewed)
			{
				//current_user.Load_Requests();
				int requests = current_user.Requests.size();
				cout << " (Requests)" << endl << endl;
				for (int i = 0; i < requests; i++)
				{
					cout << "name: " << current_user.Requests[i].name << endl;
					cout << "mail: " << current_user.Requests[i].mail << endl;
					cout << endl;
				}
			}
		}
		else if(command == "Accept")
		{	
			if (profile_viewed)
			{
				string mail, name;

				//passing   
				parse_command(user_input, command, mail, name);
				char MAIL[70];
				char NAME[50];

				strcpy_s(MAIL, mail.c_str());
				strcpy_s(NAME, name.c_str());

				current_user.Accept_Friend(MAIL, NAME);
				cout << "You and " << name << " are now friends";
			}
		}
        else if(command == "Reject")
        {
			if (profile_viewed)
			{
				string mail, name;

				//passing   
				parse_command(user_input, command, mail, name);
				current_user.Reject_Friend(mail, name);
			}
			else
			{
				cout << "You are not in anyone's profile!";
			}
        }
		/*
        else if(command == "DeleteProfile")
        {

        }
		*/
        else if(command == "Post")
        {
			if (logged_in && (!admin_mode) && (!profile_viewed))
			{
				char post[1000];
				cout << "what's on you mind ?" << endl;
				string text;
				getline(cin, text);
				strcpy_s(post, text.c_str());
				current_user.Post_Text(post);
				system("cls");
				int num_of_posts = current_user.Posts.size();
				for (int i = 0; i < num_of_posts; i++)
				{
					string name = current_user.Posts[i].name;
					int likes = current_user.Posts[i].likes;
					int ID = current_user.Posts[i].id;
					string text(current_user.Posts[i].text);
					draw_post(name, text, ID, likes);
				}
			}
        }
        else if(command == "Like")
        {
			string mail, name;
			parse_command(user_input, command, mail, name);
			char ID_c[4];
			char MAIL[70];
			strcpy_s(MAIL, mail.c_str());
			strcpy_s(ID_c, name.c_str());
			int ID = atoi(ID_c);
			current_user.Like_Post(ID, MAIL);

			/* updating posts on screen */
			system("cls");
			int num_of_posts = current_user.Posts.size();
			for (int i = 0; i < num_of_posts; i++)
			{
				string name = current_user.Posts[i].name;
				int likes = current_user.Posts[i].likes;
				int ID = current_user.Posts[i].id;
				string text(current_user.Posts[i].text);
				draw_post(name, text, ID, likes);
			}
        }
        
		else if (command == "ViewPosts") 
		{
			if (logged_in && (!admin_mode) && profile_viewed) 
			{
				int num_posts = current_user.Posts.size();
				for (int i = 0; i < num_posts; i++)
				{
					draw_post(string(current_user.Posts[i].name),
						string(current_user.Posts[i].text), 
						current_user.Posts[i].id,
						current_user.Posts[i].likes);
				}
			}
			else 
			{
				cout << "you must be in a profile to view posts" << endl;
			}
		
		}
		else if(command == "Switch")
        {
			string role = user_input.substr(user_input.find(" ") + 1);
			if (role == "Admin")
			{
				system("cls");
				profile_viewed = false;
				admin_mode = true;
				logged_in = false;
				cout << "you are now in Admin Mode";
			}
			else if(role == "User")
			{
				system("cls");
				profile_viewed = false;
				admin_mode = false;
				logged_in = false;
				cout << "you are now in User Mode";
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
		else if (command == "home")
		{
			system("cls");
			profile_viewed = false;
			int num_posts = current_user.Posts.size();
			for (int i = 0; i < num_posts; i++)
			{
				draw_post(string(current_user.Posts[i].name),
					string(current_user.Posts[i].text),
					current_user.Posts[i].id,
					current_user.Posts[i].likes);
			}
		}
		else
		{
			cout << "Invalid Command!\nhint: if you are stuck, type help";
		}
		cout << "\n\n";

    }while(1);

    return 0;
}

