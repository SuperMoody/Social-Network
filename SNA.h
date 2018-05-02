#ifndef SNA_H_
#define SNA_H_
/*----------------------------------------------------*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
/*----------------------------------------------------*/

typedef struct
{
	string text;
	int likes;
	int id;
}Post;
/*----------------------------------------------------*/
class User
{
protected:
	string Name;
	string Mail;
	string Password;
	int Age;
	vector<Post> Posts;
	vector<string> Friends;
public:
	//User(string,string,string,int);
	void Like_Post(int id);		 //Fiky

	void Mutual_Friends();          //Fiky // i think it should be added to the System class 

	void Add_Friend(string mail);		 //Fiky

	void Accept_Friend(string mail);		 //Fiky

	void Search(string name);          // i think it should be added to the System class

	void Post_Text(string);

	void Delete_Profile();          //assuming he is o his profile page   

	void View_User_Profile(string mail);

	void Edit_User_Profile(string, string);

	void Browse_User_Friends(string mail);

	void Login(string name, string password);

	void Register(string name, string mail, string password, int age);
	
};




#endif /* SNA_H_ */
