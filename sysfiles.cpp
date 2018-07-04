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

int database_count()
{
	int count = 0;
	ifstream Database("database.txt");
	string mail_text;
	Database.ignore(63);
	Database.ignore(11);
	while (Database >> mail_text)
	{
		int fount_at = mail_text.find('@');
		if (fount_at > 0)
		{
			count++;
		}
		Database.ignore(11);
	}
	return count;
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

int load_ID()
{
	ifstream ID_count("ID.txt");
	int ID;
	ID_count >> ID;
	return ID;
}

void save_ID(int id)
{
	ofstream ID_count("ID.txt");
	ID_count << id;
}


string trim_input(string text)
{
	int new_length = text.length();
	int i = new_length - 1;
	while (text[i] == ' ')
	{
		new_length--;
		i--;
	}
	i = 0;
	while (text[i] == ' ')
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

void parse_command(string Input, string& Command, string& Mail, string& Name)
{
	int i = 0;
	int j = Input.find(" ", i);
	Command = Input.substr(0, j);
	//Mail = Command.substr(0,j);
	i = j + 1;
	j = Input.find(" ", i);
	Mail = Input.substr(i, j - i);
	i = j + 1;
	j = Input.find(" ", i);
	Name = Input.substr(i);
}

void draw_post(string name, string text, int ID, int likes)
{
	int text_len = text.length();
	int lines_num = (text_len + 50) / 50;
	int lines_num_div = (lines_num + 50) % 50;
	if (lines_num_div == 0)
	{
		lines_num--;
	}
	/** top side **/
	draw_top_side(name);

	/** body **/
	int start_of_line = 0;
	int end_of_line = end_line(text);

	while (lines_num > 0)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << " ";
		}
		cout << "| ";
		cout << text.substr(start_of_line, end_of_line);
		for (int i = 0; i < 50 - end_of_line; i++)
		{
			cout << " ";
		}
		start_of_line += end_of_line + 1;
		end_of_line = end_line(text, start_of_line);
		cout << " |";
		cout << endl;
		lines_num--;
	}

	/** bottom side **/
	draw_bottom_side(ID, likes);

	cout << endl << endl;
}

void draw_top_side(string name)
{
	for (int i = 0; i < 8; i++)
	{
		cout << " ";
	}
	cout << "> " << name << " <" << endl;


	for (int i = 0; i < 8; i++)
	{
		cout << " ";
	}
	cout << " ";
	for (int i = 0; i < 52; i++)
	{
		cout << "_";
	}
	cout << " ";
	cout << endl;
}

void draw_bottom_side(int ID, int likes)
{
	for (int i = 0; i < 8; i++)
	{
		cout << " ";
	}
	cout << "|";
	for (int i = 0; i < 52; i++)
	{
		cout << "_";
	}
	cout << "|";
	cout << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << " ";
	}
	cout << "| " << likes << " likes" << " | ID: " << ID << " |" << endl;

}

int end_line(string text, int start_pos)
{
	int offset = 48;
	int len = text.find(" ", start_pos + offset) - start_pos;
	while ((len >= 50) || (len < 0))
	{
		if (len < 0)
		{
			len = text.substr(start_pos).length() - 1;
			break;
		}
		else
		{
			offset = offset - 5;
			len = text.find(" ", start_pos + offset) - start_pos;
		}
	}
	return len;
}

