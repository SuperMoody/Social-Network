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
