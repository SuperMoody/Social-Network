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

using namespace std;
/*----------------------------------------------------*/

class Post
{
public:
	char mail[70]  ;
	char text[1000];
	int likes  ;
	int id     ;
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

	void Search(string name)      ;          // i think it should be added to the System class

	void PostText(string)         ;

	void ViewUserProfile(string mail)        ;

	void EditUserProfile(string mail)        ;

	void BrowseUserFriends(string mail)      ;

	void Login(string name , string password);

	void Register(string,string,string,int)  ;
/*utilities to deal with files */
	void Load(string KeyWord , string mail)  ;
	void Load_Post(char* mail=NULL,vector<Post>*vec=NULL);
	void Load_Friends(char* mail=NULL,vector<Friend>*vec=NULL);
	void Load_Requests(char* mail=NULL) ;
	void Save(string KeyWord , string mail)  ;
	void Save_Post(char* mail=NULL,vector<Post>*vec=NULL);
	void Save_Friends(char* mail=NULL,vector<Friend>*vec=NULL);
	void Save_Requests(char* mail=NULL) ;
};




#endif /* SNA_H_ */

