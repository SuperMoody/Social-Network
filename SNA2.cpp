#include"SNA.h"


///////////////////////////////////////////////////////////////////
/////////////         Madboly's Part           ////////////////////
///////////////////////////////////////////////////////////////////

//tested 
void User::Load(string KeyWord , string mail){}
void User::Save(string KeyWord , string mail){}

int UNI_ID;    //should be saved in file common for all usuers

void User::Load_Post(char* mail,vector<Post>*vec){
	char file_name[70];
	if(mail==NULL){
		string temp=Mail.substr(0,Mail.find('@'))+"Posts.Dat";
		strcpy(file_name,temp.c_str());
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
		Posts.pop_back();
		Posts.pop_back();
	}
	else{
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Posts.Dat";
		strcpy(file_name,temp.c_str());
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
		(*vec).pop_back();
		(*vec).pop_back();
	}

}

void User::Load_Friends(char* mail,vector<Friend>*vec){
	char file_name[70];
		if(mail==NULL){
			string temp=Mail.substr(0,Mail.find('@'))+"Friends.Dat";
			strcpy(file_name,temp.c_str());
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
			Friends.pop_back();
			Friends.pop_back();
		}
		else{
			string temp(mail);
			temp=temp.substr(0,temp.find('@'))+"Friends.Dat";
			strcpy(file_name,temp.c_str());
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
			(*vec).pop_back();
			(*vec).pop_back();
		}
}

void User::Load_Requests(char* mail){
	char file_name[70];
	if(mail==NULL)
	{
		string temp=Mail.substr(0,Mail.find('@'))+"Requests.Dat";
		strcpy(file_name,temp.c_str());

	}
	else{
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Requests.Dat";
		strcpy(file_name,temp.c_str());
	}
	fstream file;
	file.open(file_name,ios::out | ios::in | ios::binary);
	Request request;
	file.seekg(0);

	Requests.push_back(request);
	int i =0;
	while( !file.eof() ){
		file.read( reinterpret_cast<char*>(&Requests[i]), sizeof(Requests[i]));
		i++;
		Request request1;
		Requests.push_back(request1);
		}
	if(mail==NULL){
		Requests.pop_back();
		Requests.pop_back();
	}
}



void User::Save_Post(char* mail,vector<Post>*vec){
	char file_name[70];
	if(mail==NULL){


		string temp=Mail.substr(0,Mail.find('@'))+"Posts.Dat";
		strcpy(file_name,temp.c_str());
		fstream file;
		file.open(file_name,ios::out|ios::trunc| ios::binary);
		file.seekg(0);
		for(unsigned int i =0 ; i< Posts.size();i++ ){
			file.write( reinterpret_cast<char*>(&Posts[i]), sizeof(Posts[i]) );
		}

	}
	else{
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Posts.Dat";
		strcpy(file_name,temp.c_str());
		fstream file;
		file.open(file_name,ios::out | ios::trunc |ios::binary);
		for(unsigned int i =0 ; i< (*vec).size();i++ ){
			file.write( reinterpret_cast<char*>(&((*vec)[i])), sizeof((*vec)[i]) );
		}
	}



}

void User::Save_Friends(char* mail,vector<Friend>*vec){
	char file_name[70];
		if(mail==NULL){
			string temp=Mail.substr(0,Mail.find('@'))+"Friend.Dat";
			strcpy(file_name,temp.c_str());
			fstream file;
			file.open(file_name,ios::out | ios::in| ios::binary);
			for(unsigned int i =0 ; i< Posts.size();i++ ){
				file.write( reinterpret_cast<char*>(&Friends[i]), sizeof(Friends[i]) );
			}

		}
		else{
			string temp(mail);
			temp=temp.substr(0,temp.find('@'))+"Friend.Dat";
			strcpy(file_name,temp.c_str());
			fstream file;
			file.open(file_name,ios::out | ios::in| ios::binary);
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
			strcpy(file_name,temp.c_str());

		}
		else{
			string temp(mail);
			temp=temp.substr(0,temp.find('@'))+"Requests.Dat";
			strcpy(file_name,temp.c_str());
		}
		fstream file;
		file.open(file_name,ios::out| ios::in | ios::binary);
		for(unsigned int i =0 ; i< Requests.size();i++ ){
				file.write( reinterpret_cast<char*>(&Requests[i]), sizeof(Requests[i]) );
		}
}



void User::Like_Post(int id,char * mail){
	//Load_Post();                           //added for testing only

	unsigned int i;
	string stru(this->Mail);
	/*modify my posts*/

	for(i =0 ; i< Posts.size();i++)
	{
		if(Posts[i].id==id){break;}
	}
	Posts[i].likes+=1;


	Save_Post();

	/*/////////////////////*/
	/*modify the owner posts*/

	vector<Post>vecp;
	Load_Post(mail,&vecp);
	for(i =0 ; i< vecp.size();i++)
	{
		if(vecp[i].id==id){break;}
	}
	vecp[i].likes+=1;
	Save_Post(mail,&vecp);
	vecp.clear();

	/*/////////////////////*/
	/*modify the owner's friend's posts */

	vector<Friend>vecf;
	Load_Friends(mail,&vecf);
	for(unsigned int i =0 ; i< vecf.size();i++)
	{

		string strf(vecf[i].Mail);
		if(strf==stru)
			continue;


		vector<Post>vecp;
		Load_Post(vecf[i].Mail,&vecp);
		unsigned int j;
		for(j=0 ; j <vecp.size();j++)
		{
			if(vecp[j].id==id){break;}
		}
		vecp[j].likes+=1;
		Save_Post(vecf[i].Mail,&vecp);
		vecp.clear();
	}

}

void User::Add_Friend(char* mail,char*name) {
	char file_name[70];
	string temp(mail);
	temp=temp.substr(0,temp.find('@'))+"Requests.Dat";
	strcpy(file_name,temp.c_str());
	fstream file;
	file.open(file_name,ios::out |ios::app| ios::in | ios::binary);

	char MAIL[70];
	char NAME[50];

	strcpy(MAIL,this->Mail.c_str());
	strcpy(NAME,this->Name.c_str());

	Request request(MAIL,NAME);
	file.write( reinterpret_cast<char*>(&request), sizeof(request) );

}
void User::Accept_Friend(char* mail,char*name){

	char file_name[70];
	string temp(mail);
	temp=temp.substr(0,temp.find('@'))+"Friends.Dat";
	strcpy(file_name,temp.c_str());
	fstream file,file1;
	file.open(file_name,ios::out |ios::app| ios::in | ios::binary);

	char NameTemp [50];
	char MailTemp [70];

	strcpy(MailTemp,this->Mail.c_str());
	strcpy(NameTemp,this->Name.c_str());

	Friend friend1(NameTemp,MailTemp);
	file.write( reinterpret_cast<char*>(&friend1), sizeof(friend1) );
	/*-------------------------------------------------------------------*/


	char file_name1[70];
	string temp1=Mail.substr(0,Mail.find('@'))+"Friends.Dat";

	strcpy(file_name1,temp1.c_str());

	file1.open(file_name1,ios::out |ios::app| ios::in | ios::binary);


	Friend friend2(name,mail);

	file1.write( reinterpret_cast<char*>(&friend2), sizeof(friend2) );
	Friends.push_back(friend2);
	/*-------------------------------------------------------------------*/
	/*REMOVE THE REQUEST FROM THE MY REQUESTS*/
	string target(mail);
	for(int i =0 ; i<Requests.size();i++){
		string str(Requests[i].mail);
		if(str==target){
			Requests.erase(Requests.begin() + i);
			break;
		}

	}
	Save_Requests();
}

void User::Post_Text(char* text){

	/*CREATE A  POST && and add it to your posts*/

	// i should add  the post to the vector:::done

	char mail[70];
	string str=this->Mail;
	strcpy(mail,str.c_str());
	Post NewPost(mail,text,0,++ UNI_ID);
	Posts.push_back(NewPost);
	char file_name[70];
	str=str.substr(0,str.find('@'))+"Posts.Dat";
	strcpy(file_name,str.c_str());

	fstream file;
	file.open(file_name,ios::out |ios::app| ios::in | ios::binary);
	file.write( reinterpret_cast<char*>(&NewPost), sizeof(NewPost) );


	/*--------------------------------------------------------*/
	/*send post to friends*/
	//Load_Friends();									//for testing only

	for(unsigned int i = 0 ; i<Friends.size(); i++ ){
			char file_name1[70];
			string temp(Friends[i].Mail);
			temp=temp.substr(0,temp.find('@'))+"Posts.Dat";
			strcpy(file_name1,temp.c_str());

			fstream file1;
			file1.open(file_name1,ios::out |ios::app| ios::in | ios::binary);
			file1.write( reinterpret_cast<char*>(&NewPost), sizeof(NewPost) );
	}
}
/*-------------------------------------------------------------------*/

void User::Delete_Profile(){
		char MAIL[70];
		strcpy(MAIL,Mail.c_str());
		Clear_Data(MAIL,(char*)"Posts");
		Clear_Data(MAIL,(char*)"Friends");
		Clear_Data(MAIL,(char*)"Requests");
		Clear_Data(MAIL,(char*)"Authenticate");

}


/*--------------------------------------------------------------------*/

void User::Clear_Data(char*mail,char*keyword){
	string key(keyword);
	if(key== "Friends"){
		char file_name[70];
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Friends.Dat";
		strcpy(file_name,temp.c_str());
		remove(file_name);

	}

	else if(key== "Posts"){
		char file_name[70];
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Postss.Dat";
		strcpy(file_name,temp.c_str());
		remove(file_name);

	}
	else if(key== "Requests"){
		char file_name[70];
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Requests.Dat";
		strcpy(file_name,temp.c_str());
		remove(file_name);
		;

	}

	else if(key== "Authenticate"){
		char file_name[70];
		string temp(mail);
		temp=temp.substr(0,temp.find('@'))+"Authenticate.Dat";
		strcpy(file_name,temp.c_str());
		remove(file_name);
	}
}

void User::Reject(char* mail,char*name){
/*REMOVE THE REQUEST FROM THE MY REQUESTS*/
	string target(mail);
	for(int i =0 ; i<Requests.size();i++){
		string str(Requests[i].mail);
		if(str==target){
			Requests.erase(Requests.begin() + i);
			break;
		}

	}
	Save_Requests();
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

void User::Login(string mail, string password, bool& login_flag)
{
	bool exists = database_search(mail, password);
	if (exists)
	{
		cout << "Logged in successfully";
		login_flag = true;
	}
	else
	{
		cout << "wrong mail or password, try again";
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
		if ((property == "name") || (property == "password") 
			|| (property == "mail") || (property == "age"))
		{
			property_fulfilled = true;
		}
		else
		{
			cout << "wrong property, write a valid one!";
		}
	} while (!property_fulfilled);

	cout << "Enter the new" + property + ": " << endl;
    if(property == "name")
    {
		cin.ignore();
        string new_name;
		//cin >> new_name;
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
		cin.ignore();
    }
    else if(property == "mail")
    {
        string new_mail;
        cin >> new_mail;
        set_mail(new_mail);
		Update_User_Profile();
		cin.ignore();
    }
    else
    {
        string new_password;
        cin >> new_password;
        set_password(new_password);
		cin.ignore();
    }
	system("cls");
	View_User_Profile(this->Mail);
	//cout << property + "changed successfully" << endl << endl;
}

void User::Update_User_Profile()
{
	ofstream profile;
	profile.open(this->Mail.substr(0, this->Mail.find("@"))+".txt");
	int name_frame = this->Name.length() + 2;
	profile << " ";
	for (int i = 0; i < name_frame; i++)
	{
		profile << "=";
	}
	profile << endl << "  "+ this->Name +" " << endl;
	profile << " ";
	for (int i = 0; i < name_frame; i++)
	{
		profile << "=";
	}
	profile << "\n\n";
	profile << " (info)\n  ";
	profile << "______________________________________\n ";
	profile << "|                                      |\n ";
	profile << "| Name: " + this->Name;
	int sec_line_len = 40 - 8 - this->Name.length();
	for (int i = 0; i < sec_line_len - 1; i++)
	{
		profile << " ";
	}
	profile << "|\n ";
	profile << "|  Age: " + to_string(this->Age);
	int thrd_line_len = 40 - 8 - to_string(this->Age).length();
	for (int i = 0; i < thrd_line_len - 1; i++)
	{
		profile << " ";
	}
	profile << "|\n ";
	profile << "| Mail: " << this->Mail;
	int forth_line_len = 40 - 8 - this->Mail.length() - 1;
	for (int i = 0; i < forth_line_len; i++)
	{
		profile << " ";
	}
	profile << "|\n ";
	profile << "|______________________________________|\n\n";
	profile << " \n\n";

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











