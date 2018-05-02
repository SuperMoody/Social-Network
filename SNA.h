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
	int likes  ;
	int id     ;
}Post;
/*----------------------------------------------------*/
class User
{
protected:
	string Name    ;
	string Mail    ;
	string Password;
	int    Age     ;
	vector<Post>Posts     ;
	vector<string>Friends ;
public:
	//User(string,string,string,int);
	void LikePost(int id)         ;

	void MutualFriends()          ;          // i think it should be added to the System class

	void AddFriend(string mail)   ;

	void AcceptFriend(string mail);

	void Search(string name)      ;          // i think it should be added to the System class

	void PostText(string)         ;

	void DeleteProfile()          ;          //assuming he is o his profile page   

	void ViewUserProfile(string mail)        ;

	void EditUserProfile(string ,string )    ;

	void BrowseUserFriends(string mail)      ;

	void Login(string name , string password);

	void Register(string,string,string,int)  ;
	
};




#endif /* SNA_H_ */
