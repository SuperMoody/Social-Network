#include"SNA.h"
/*-----------------------------------------------*/
/*TEST1: ADDING and accepting a friend request*/

int main()
{
/*scenario  1 ::::3 users :::: passed*/

//User UserA;
//UserA.Age=25;
//UserA.Mail="mohamedyehia@gmail.com";
//UserA.Name="Mohamed Yehia";


//User UserB;
//UserB.Age=29;
//UserB.Mail="mostafatarek@gmail.com";
//UserB.Name="Mostafa Tarek";


//User UserC;
//UserC.Age=24;
//UserC.Mail="ahmedmahmoud@yahoo.com";
//UserC.Name="Ahmed Mahmoud";
/*-------------------------------------------------------------------*/
/*testing add fiend : passed1,passed2*/
/*
UserA.Add_Friend("mostafatarek@gmail.com","Mostafa Tarek");
UserC.Add_Friend("mostafatarek@gmail.com","Mostafa Tarek");
*/
/*UserB.Load_Requests();
for(int i =0 ; i<UserB.Requests.size(); i++)
	{
	cout<<UserB.Requests[i].name<<endl;

	cout<<UserB.Requests[i].mail<<endl;
	}
*/
/*-------------------------------------------------------------------*/
/*testing the accepting friends:passed1,passed2*/
/*
UserB.Accept_Friend("ahmedmahmoud@yahoo.com","Ahmed Mahmoud");
UserB.Accept_Friend("mohamedyehia@gmail.com","Mohamed Yehia");
*/
/*
UserB.Load_Friends();
UserA.Load_Friends();
UserC.Load_Friends();

for(int i =0 ; i<UserB.Friends.size(); i++)
	{
	cout<<UserB.Friends[i].Name<<endl;

	cout<<UserB.Friends[i].Mail<<endl;
	}

cout<<endl;
cout<<endl;
cout<<endl;

for(int i =0 ; i<UserC.Friends.size(); i++)
	{
	cout<<UserC.Friends[i].Name<<endl;

	cout<<UserC.Friends[i].Mail<<endl;
	}

cout<<endl;
cout<<endl;
cout<<endl;

for(int i =0 ; i<UserA.Friends.size(); i++)
	{
	cout<<UserA.Friends[i].Name<<endl;

	cout<<UserA.Friends[i].Mail<<endl;
	}
*/
/*
cout<<UserB.Friends[0].Mail<<endl;
cout<<UserB.Friends[0].Name<<endl;

cout<<endl;

cout<<UserB.Friends[1].Mail<<endl;
cout<<UserB.Friends[1].Name<<endl;

cout<<endl<<endl;

cout<<UserA.Friends[0].Mail<<endl;
cout<<UserA.Friends[0].Name<<endl;

cout<<endl<<endl;

cout<<UserC.Friends[0].Mail<<endl;
cout<<UserC.Friends[0].Name<<endl;
*/

/*-----------------------------------------------------------------*/

/*testing posting:passed2*/


/*
UserB.Post_Text((char*)"hello ");
UserA.Post_Text((char*)"tmaam ");
UserC.Post_Text( (char*)"hello can you hear me ");
*/
/*
UserB.Load_Post();
UserA.Load_Post();
UserC.Load_Post();

for(int i =0 ; i<UserB.Posts.size();i++)
{
	cout<<UserB.Posts[i].id<<endl;
	cout<<UserB.Posts[i].mail<<endl;
	cout<<UserB.Posts[i].text<<endl;
}

cout<<endl;
cout<<endl;
cout<<endl;

for(int i =0 ; i<UserC.Posts.size();i++)
{
	cout<<UserC.Posts[i].id<<endl;
	cout<<UserC.Posts[i].mail<<endl;
	cout<<UserC.Posts[i].text<<endl;
}

cout<<endl;
cout<<endl;
cout<<endl;

for(int i =0 ; i<UserA.Posts.size();i++)
{
	cout<<UserA.Posts[i].id<<endl;
	cout<<UserA.Posts[i].mail<<endl;
	cout<<UserA.Posts[i].text<<endl;
}

/*
cout<<UserB.Posts[0].id<<endl;
cout<<UserB.Posts[0].mail<<endl;
cout<<UserB.Posts[0].text<<endl;

cout<<UserB.Posts[1].id<<endl;
cout<<UserB.Posts[1].mail<<endl;
cout<<UserB.Posts[1].text<<endl;

cout<<UserB.Posts[2].id<<endl;
cout<<UserB.Posts[2].mail<<endl;
cout<<UserB.Posts[2].text<<endl;

cout<<endl<<endl;

cout<<UserA.Posts[0].id<<endl;
cout<<UserA.Posts[0].mail<<endl;
cout<<UserA.Posts[0].text<<endl;

cout<<endl<<endl;

cout<<UserC.Posts[0].id<<endl;
cout<<UserC.Posts[0].mail<<endl;
cout<<UserC.Posts[0].text<<endl;;
*/
/**--------------------------------------------------------------------------/
/*testing post liking:passed*/
/*
UserB.Like_Post(2,"mohamedyehia@gmail.com");
UserB.Like_Post(3,"ahmedmahmoud@yahoo.com");
*/


//UserA.Like_Post(1,(char*)"mostafatarek@gmail.com");

//UserC.Like_Post(1,(char*)"mostafatarek@gmail.com");



/*
UserB.Load_Post();
//UserA.Load_Post();
UserC.Load_Post();

for(int i =0 ; i<UserB.Posts.size();i++)
{
	cout<<UserB.Posts[i].id<<endl;
	cout<<UserB.Posts[i].mail<<endl;
	cout<<UserB.Posts[i].text<<endl;
	cout<<UserB.Posts[i].likes<<endl;
}

cout<<endl;
cout<<endl;
cout<<endl;

for(int i =0 ; i<UserC.Posts.size();i++)
{
	cout<<UserC.Posts[i].id<<endl;
	cout<<UserC.Posts[i].mail<<endl;
	cout<<UserC.Posts[i].text<<endl;
	cout<<UserC.Posts[i].likes<<endl;
}

cout<<endl;
cout<<endl;
cout<<endl;

for(int i =0 ; i<UserA.Posts.size();i++)
{
	cout<<UserA.Posts[i].id<<endl;
	cout<<UserA.Posts[i].mail<<endl;
	cout<<UserA.Posts[i].text<<endl;
	cout<<UserA.Posts[i].likes<<endl;
}

*/
/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/
/*scenario 2 ::::normal flow ::::pssed */
/*
UNI_ID=3; //later must be saved and loaded

User UserB;
UserB.Age=29;
UserB.Mail="mostafatarek@gmail.com";
UserB.Name="Mostafa Tarek";

UserB.Load_Friends();
UserB.Load_Post();
UserB.Load_Requests();

UserB.Post_Text("Hello World!!!!");

UserB.Like_Post(3,"ahmedmahmoud@yahoo.com");

*/



/*---------------------------------------------------*/
/*
cout<<"Posts_Loaded"<<endl;

for(int i =0 ; i<UserB.Posts.size();i++)
{
	cout<<UserB.Posts[i].id<<endl;
	cout<<UserB.Posts[i].mail<<endl;
	cout<<UserB.Posts[i].text<<endl;
	cout<<UserB.Posts[i].likes<<endl;
}

cout<<endl;
cout<<endl;
cout<<endl;
*/
/*----------------------------------------------------*/
/*
cout<<"Friends_Loaded"<<endl;

for(int i =0 ; i<UserB.Friends.size();i++)
{
	cout<<UserB.Friends[i].Name<<endl;
	cout<<UserB.Friends[i].Mail<<endl;


}

cout<<endl;
cout<<endl;
cout<<endl;
*/
/*------------------------------------------------------*/
/*
cout<<"Requests_loaded"<<endl;

for(int i =0 ; i<UserB.Requests.size();i++)
{
	cout<<UserB.Requests[i].name<<endl;
	cout<<UserB.Requests[i].mail<<endl;


}

cout<<endl;
cout<<endl;
cout<<endl;
*/
/*--------------------------------------------------------*/


return 0;

}





















