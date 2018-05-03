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
	vector<string> Requests; //new member added to handle friend requests for each user
				 //(one may have multiple requests)
public:
	User(string name, string mail, string password, int age);   //constructor added for possible purposes
	~User(string name, string mail, string password, int age);  //destructor added for possible purposes
	
	void Like_Post(int id);		 //Fiky

	void Mutual_Friends();          //Fiky // i think it should be added to the System class 

	void Add_Friend(string mail);		 //Fiky

	void Accept_Friend(string mail);		 //Fiky

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
	
};




#endif /* SNA_H_ */
