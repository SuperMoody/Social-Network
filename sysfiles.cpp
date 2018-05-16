#include "sysfiles.h"

void database_init()
{
	ofstream Database("database.txt");
	for (int i = 0; i < 20; i++)
	{
		Database << "=";
	}
	Database << endl << "      Database      " << endl;
	for (int i = 0; i < 20; i++)
	{
		Database << "=";
	}
	Database << "\n\n";
}
void database_update(string Mail, string Password)
{
	ofstream Database;
	Database.open("database.txt", ios::out | ios::app);
	Database << "    Mail: " << Mail << endl;
	Database << "Password: " << Password << endl << endl;
	cout << "Data saved successfully" << endl;
}

bool database_search(string Mail, string Password)
{
	ifstream inf("database.txt");
	bool mail_flag = false, pass_flag = false;
	string mail_text, pass_text;
	inf.ignore(63);
	inf.ignore(11);
	while (inf >> mail_text)
	{
		if (mail_text == Mail)
		{
			inf.ignore(10);
			inf >> pass_text;
			mail_flag = true;
			if (pass_text == Password)
			{
				pass_flag = true;
				return true;
			}
		}
		else
		{
			inf.ignore(11);
		}
	}
	return false;
}

void system_help()
{
	ifstream sys_commands("commands.txt");
	string line;
	cout << "system commands are:\n";
	while (sys_commands >> line)
	{
		cout << "- " << line << endl;
	}
	cout << endl;
}