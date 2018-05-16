#include"SNA.h"

void User::Load(string KeyWord , string mail){}
void User::Save(string KeyWord , string mail){}

int UNI_ID;

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














