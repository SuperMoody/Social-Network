#ifndef SNA_H_
#define SNA_H_
/*----------------------------------------------------*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include <fstream>
#include<iomanip>
#include <string.h>
#include<stdio.h>   //added to use remove and rename system calls (file handling)
using namespace std;
/*----------------------------------------------------*/
extern int UNI_ID;           //universal post id number
/*-----------------------------------------------------*/
class Post
{
public:                                      //added constructors
	char mail[70]  ;
	char text[1000];
	int likes  ;
	int id     ;
	Post(){ }                  
	Post(char* ma,char* te,int li , int i){

		strcpy(mail,ma);
		strcpy(text,te);
		likes=li;
		id=i;
	}
};
/*----------------------------------------------------*/
class Friend
{
public:
	Friend(){}
	char Name [50];
	char Mail [70];
	Friend(char* name,char* mail){
		strcpy(Mail,mail);
		strcpy(Name,name);
		}
};
/*----------------------------------------------------*/
class Request
{
public:
	Request(){};
	char mail[70]  ;
	char name[50]  ;
	char text[70] ="would like to be your friend" ;
	Request(char*Mail,char*Name){
		strcpy(mail,Mail);
		strcpy(name,Name);
	}
};
/*----------------------------------------------------*/
class User
{
public:

	string Name    ;

	string Mail    ;

	string Password;

	int    Age     ;

	vector<Post>Posts     ;

	vector<Friend>Friends ;

	vector<Request>Requests;
//public:
	//User(string,string,string,int);
	void Like_Post(int id,char * mail)       ;

	void Mutual_Friends()          ;          // i think it should be added to the System class

	void Add_Friend(char* mail,char*name)   ;

	void Accept_Friend(char* mail,char*name);

	void Search(string name);          // i think it should be added to the System class

	void Post_Text(string);

	void Delete_Profile();          //assuming he is o his profile page   

	void View_User_Profile(string mail); //hamdy

	void Edit_User_Profile(string, string); //hamdy

	//void Browse_User_Friends(string mail); //We should pass a user to get his friends not an e-mail
	
	void Browse_User_Friends(User current_profile_opened); // we pass a user and import his friends //hamdy

	void Login(string name, string password);   //hamdy

	void Register(string name, string mail, string password, int age); //hamdy
	
	// getters just in case
	string get_name();
	
	string get_mail();
	
	string get_password();
	
	int get_age();
	
	string get_post(); 
	
	string get_friends();
	
	string get_requests();
/*utilities to deal with files */
	void Load(string KeyWord , string mail)  ;
	void Load_Post(char* mail=NULL,vector<Post>*vec=NULL);
	void Load_Friends(char* mail=NULL,vector<Friend>*vec=NULL);
	void Load_Requests(char* mail=NULL) ;
	void Save(string KeyWord , string mail)  ;
	void Save_Post(char* mail=NULL,vector<Post>*vec=NULL);
	void Save_Friends(char* mail=NULL,vector<Friend>*vec=NULL);
	void Save_Requests(char* mail=NULL) ;
	void Clear_Data(char* mail,char*keyword)    ;
};




#endif /* SNA_H_ */

