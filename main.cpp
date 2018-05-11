#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

string extract_command(string text);
string trim_input(string text);

int main()
{
    string user_input;
    string command;
    //string command;//(extract_command(user_input));
    do
    {
        cout << "$ ";
        getline(cin, user_input);
        user_input = trim_input(user_input);
        command = extract_command(user_input);

        cout << " ";
        cout << command << endl;

        if(command == "Register")
        {
            string ss(user_input);
            cout << user_input << endl;
            cout << "Hello, Hamdy!" << endl;
        }
        else if(command == "Login")
        {
            cout << user_input[2] << endl;
        }
        else if(command == "Search")
        {
            cout << "Hello, Madboly!" << endl;
        }
        else if(command == "ViewProfile")
        {

        }
        else if(command == "EditProfile")
        {

        }
        else if(command == "BrowseFriends")
        {

        }
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
        else if(command == "Switch")
        {

        }

        cout << "\n";


    }while(!(user_input == "quit") && !(user_input == "exit"));

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

    string trimmed_text = text.substr(i, new_length);

    return trimmed_text;
}


string extract_command(string text)
{
    int i = 0;
    while(!(text[i] == ' '))
    {
        i++;
    }
    //command_length = text.find(" ");
    string command = text.substr(0, i);
    return command;
}
