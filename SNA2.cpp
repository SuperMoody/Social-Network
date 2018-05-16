#include"SNA2.h"
/*under testing*/


///////////////////////////////////////////////////////////////////
/////////////         Madboly's Part           ////////////////////
///////////////////////////////////////////////////////////////////


void User::Load(string KeyWord , string mail){}
void User::Save(string KeyWord , string mail){}



void User::Load_Post(char* mail,vector<Post>*vec){
	char file_name[70];
	if(mail==NULL){
		string temp=Mail.substr(0,Mail.find('@'))+"Posts.Dat";
		strcpy_s(file_name,temp.c_str());
		fstream file;
		file.open(file_name,ios::out | ios::in | ios::binary);
		Post post;
		file.seekg(0);
		Posts.push_back(post);
		int i =0;
		while( !file.eof() ){
			file.read( reinterpret_cast<char*>(&Posts[i]), sizeof(Posts[i]) );
			i++;
			Post post;
			Posts.push_back(post);
		}


	}
	else{
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Posts.Dat";
		strcpy_s(file_name,temp.c_str());
		fstream file;
		file.open(file_name,ios::out | ios::in | ios::binary);
		Post post;
		file.seekg(0);
		(*vec).push_back(post);
		int i =0;
		while( !file.eof() ){
			file.read( reinterpret_cast<char*>(&((*vec)[i])), sizeof((*vec)[i]) );
			i++;
			Post post;
			(*vec).push_back(post);
		}

	}

}

void User::Load_Friends(char* mail,vector<Friend>*vec){
	char file_name[70];
		if(mail==NULL){
			string temp=Mail.substr(0,Mail.find('@'))+"Friends.Dat";
			strcpy_s(file_name,temp.c_str());
			fstream file;
			file.open(file_name,ios::out | ios::in | ios::binary);
			Friend  friend1;
			file.seekg(0);
			Friends.push_back(friend1);
			int i =0;
			while( !file.eof() ){
				file.read( reinterpret_cast<char*>(&Friends[i]), sizeof(Friends[i]) );
				i++;
				Friend  friend1;
				Friends.push_back(friend1);
			}


		}
		else{
			string temp(mail);
			temp=temp.substr(0,temp.find('@'))+"Friends.Dat";
			strcpy_s(file_name,temp.c_str());
			fstream file;
			file.open(file_name,ios::out | ios::in | ios::binary);
			Friend friend1;
			file.seekg(0);
			(*vec).push_back(friend1);
			int i =0;
			while( !file.eof() ){
				file.read( reinterpret_cast<char*>(&((*vec)[i])), sizeof((*vec)[i]) );
				i++;
				Friend friend1;
				(*vec).push_back(friend1);
			}

		}
}

void User::Load_Requests(char* mail){
	char file_name[70];
	if(mail==NULL)
	{
		string temp=Mail.substr(0,Mail.find('@'))+"Requests.Dat";
		strcpy_s(file_name,temp.c_str());

	}
	else{
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Requests.Dat";
		strcpy_s(file_name,temp.c_str());
	}
	fstream file;
	file.open(file_name,ios::out | ios::in | ios::binary);
	Request request;
	file.seekg(0);

	Requests.push_back(request);
	int i =0;
	while( !file.eof() ){
		file.read( reinterpret_cast<char*>(&Requests[i]), sizeof(Requests[i]) );
		i++;
		Request friend1;
		Requests.push_back(friend1);
		}
}



void User::Save_Post(char* mail,vector<Post>*vec){
	char file_name[70];
	if(mail==NULL){
		string temp=Mail.substr(0,Mail.find('@'))+"Posts.Dat";
		strcpy_s(file_name,temp.c_str());
		fstream file;
		file.open(file_name,ios::out | ios::in| ios::app | ios::binary);
		for(unsigned int i =0 ; i< Posts.size();i++ ){
			file.write( reinterpret_cast<char*>(&Posts[i]), sizeof(Posts[i]) );
		}

	}
	else{
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Posts.Dat";
		strcpy_s(file_name,temp.c_str());
		fstream file;
		file.open(file_name,ios::out | ios::in| ios::app | ios::binary);
		for(unsigned int i =0 ; i< (*vec).size();i++ ){
			file.write( reinterpret_cast<char*>(&((*vec)[i])), sizeof((*vec)[i]) );
		}
	}



}

void User::Save_Friends(char* mail,vector<Friend>*vec){
	char file_name[70];
		if(mail==NULL){
			string temp=Mail.substr(0,Mail.find('@'))+"Friend.Dat";
			strcpy_s(file_name,temp.c_str());
			fstream file;
			file.open(file_name,ios::out | ios::in| ios::app | ios::binary);
			for(unsigned int i =0 ; i< Posts.size();i++ ){
				file.write( reinterpret_cast<char*>(&Friends[i]), sizeof(Friends[i]) );
			}

		}
		else{
			string temp(mail);
			temp=temp.substr(0,temp.find('@'))+"Friend.Dat";
			strcpy_s(file_name,temp.c_str());
			fstream file;
			file.open(file_name,ios::out | ios::in| ios::app | ios::binary);
			for(unsigned int i =0 ; i< (*vec).size();i++ ){
				file.write( reinterpret_cast<char*>(&((*vec)[i])), sizeof((*vec)[i]) );
			}
		}
}

void User::Save_Requests(char* mail){
	char file_name[70];
		if(mail==NULL)
		{
			string temp=Mail.substr(0,Mail.find('@'))+"Requests.Dat";
			strcpy_s(file_name,temp.c_str());

		}
		else{
			string temp(mail);
			temp=temp.substr(0,temp.find('@'))+"Requests.Dat";
			strcpy_s(file_name,temp.c_str());
		}
		fstream file;
		file.open(file_name,ios::out |ios::app| ios::in | ios::binary);
		for(unsigned int i =0 ; i< Requests.size();i++ ){
				file.write( reinterpret_cast<char*>(&Requests[i]), sizeof(Requests[i]) );
		}
}



void User::Like_Post(int id,char * mail){
	Load_Post();
	unsigned int i;
	for(i =0 ; i< Posts.size();i++)
	{
		if(Posts[i].id==id){break;}
	}
	Posts[i].id+=1;
	Save_Post();
	//===============================================
	vector<Post>vecp;
	Load_Post(mail,&vecp);
	for(i =0 ; i< vecp.size();i++)
	{
		if(vecp[i].id==id){break;}
	}
	vecp[i].id+=1;
	Save_Post(mail,&vecp);
	vecp.clear();
	//================================================
	vector<Friend>vecf;
	Load_Friends(mail,&vecf);
	for(unsigned int i =0 ; i< vecf.size();i++)
	{
		vector<Post>vecp;
		Load_Post(vecf[i].Mail,&vecp);
		unsigned int j;
		for(j=0 ; j <vecp.size();j++)
		{
			if(vecp[j].id==id){break;}
		}
		vecp[j].id+=1;
		Save_Post(mail,&vecp);
		vecp.clear();
	}

}

void User::Add_Friend(char* mail,char*name) {
	char file_name[70];
	string temp(mail);
	temp=temp.substr(0,temp.find('@'))+"Requests.Dat";
	strcpy_s(file_name,temp.c_str());
	fstream file;
	file.open(file_name,ios::out |ios::app| ios::in | ios::binary);
	Request request(mail,name);
	file.write( reinterpret_cast<char*>(&request), sizeof(request) );

}

void User::Accept_Friend(char* mail,char*name){

	char file_name[70];
	string temp(mail);
	temp=temp.substr(0,temp.find('@'))+"Friends.Dat";
	strcpy_s(file_name,temp.c_str());
	fstream file,file1;
	file.open(file_name,ios::out |ios::app| ios::in | ios::binary);

	char NameTemp [50];
	char MailTemp [70];

	strcpy_s(MailTemp,this->Mail.c_str());
	strcpy_s(NameTemp,this->Name.c_str());

	Friend friend1(NameTemp,MailTemp);
	file.write( reinterpret_cast<char*>(&friend1), sizeof(friend1) );
	//====================================================================


	char file_name1[70];
	string temp1=Mail.substr(0,Mail.find('@'))+"Friends.Dat";

	strcpy_s(file_name1,temp1.c_str());

	file1.open(file_name1,ios::out |ios::app| ios::in | ios::binary);


	Friend friend2(name,mail);
	file1.write( reinterpret_cast<char*>(&friend1), sizeof(friend1) );



}

///////////////////////////////////////////////////////////////////
/////////////           Hamdy's Part           ////////////////////
///////////////////////////////////////////////////////////////////

User::User()
{

}
User::~User()
{

}

void User::set_name(string name)
{
    this->Name = name;
}

void User::set_age(int age)
{
    this->Age = age;
}

void User::set_mail(string mail)
{
    this->Mail = mail;
}

void User::set_password(string password)
{
    this->Password = password;
}

string User::get_name()
{
    return this->Name;
}

int User::get_age()
{
    return this->Age;
}

string User::get_mail()
{
    return this->Mail;
}

string User::get_password()
{
    return this->Password;
}

void User::Register(string name, string mail, string password, int age)
{
    this->Name = name;
    this->Mail = mail;
    this->Password = password;
    this->Age = age;

	Update_User_Profile();
}

void User::Login(string mail, string password)
{
	bool exists = database_search(mail, password);
	if (exists)
	{
		cout << "Logged in successfully" << endl << endl;
	}
	else
	{
		cout << "wrong mail or password, try again" << endl << endl;
	}
}

void User::View_User_Profile(string mail)
{
	string each_line;
	ifstream line_reader(mail.substr(0, mail.find("@")) + ".txt");
	while (getline(line_reader, each_line))
	{
		cout << each_line << endl;
	}
}


void User::Edit_User_Profile()
{
	string property;
	bool property_fulfilled = false;
	do
	{
		cout << "\nwhat you want to change: ";
		cin >> property;
		if (property == "name" || property == "password" || property == "mail" || property == "age")
		{
			property_fulfilled = true;
		}
		else
		{
			cout << "wrong property, write a valid one!" << endl;
		}
	} while (!property_fulfilled);

    cout << "Enter the new" + property + ": ";
    if(property == "name")
    {
        string new_name;
        getline(cin, new_name);
        set_name(new_name);
		Update_User_Profile();
    }
    else if(property == "age")
    {
        int new_age;
        cin >> new_age;
        set_age(new_age);
		Update_User_Profile();
    }
    else if(property == "mail")
    {
        string new_mail;
        cin >> new_mail;
        set_mail(new_mail);
		Update_User_Profile();
    }
    else
    {
        string new_password;
        cin >> new_password;
        set_password(new_password);
    }
	cout << property + "changed successfully" << endl << endl;
}

void User::Update_User_Profile()
{
	ofstream profile;
	profile.open(this->Mail.substr(0, this->Mail.find("@")));
	for (int i = 0; i < 20; i++)
	{
		profile << "=";
	}
	profile << endl << "      Database      " << endl;
	for (int i = 0; i < 20; i++)
	{
		profile << "=";
	}
	profile << "\n\n";
	profile << " (info)\n  ";
	profile << "______________________________________\n";
	profile << "|                                      |\n";
	profile << "| Name: " + this->Name;
	int sec_line_len = 40 - 8 - this->Name.length();
	for (int i = 0; i < sec_line_len - 1; i++)
	{
		profile << " ";
	}
	profile << "|\n";
	profile << "|  Age: " + to_string(this->Age);
	int thrd_line_len = 40 - 8 - to_string(this->Age).length();
	for (int i = 0; i < thrd_line_len - 1; i++)
	{
		profile << " ";
	}
	profile << "|\n";
	profile << "| Mail: " + this->Mail;
	int forth_line_len = 40 - 8 - this->Mail.length();
	for (int i = 0; i < forth_line_len; i++)
	{
		profile << " ";
	}
	profile << "|\n\n";
	profile << " (Posts)\n";

	/** posts layout implementation : undone **/
}

void User::Browse_User_Friends(string mail)
{
	string each_line;
	ifstream line_reader(mail.substr(0, mail.find("@")) + "_friends.txt");
	while (getline(line_reader, each_line))
	{
		cout << each_line << endl;
	}
}

