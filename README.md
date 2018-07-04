![Screenshot](Social_Network.jpg)

### Content
* [Overview](#overview)
* [Specifications](#specifications)
* [General Design](#general-design)
* [CLI Design](#cli-design)
* [How to use?](#how-to-use-)
* [Our Team](#our-team)
* [Contribution](#contribution)
* [Author](#author)
* [Licence](#licence)
___

## Overview
Academic project based on applying Data Structures concepts by making a social network and being able to analyze frequent trends in it using C++ as a progrmmaning language.

___

## Specifications

___

## General Design:
- Interactive command line interface that support both admin and users’ functions
- Admin Roles:
  * Add/Delete User
  * Browse User Profile/Friends
  * Full Control of the system
  
- User Roles:
  * Add Friend
  * Send friend requests
  * Accept/Reject friend requests
  * Create a post
  * Like posts
  * Browse user profile/friends
  * Edit his/her profile
  * Login/Logout
  * Switch roles
  
- The ability to change from user mode to admin mode and vice versa
- Databases contain all information about users and used for social network analysis.
- Repository is created for each user to save his basic data and profile.
- Dat files are used to hold, save and load objects and data structures like xml files

___

## CLI Design
### Structure to parse
```shell
<command> <mail> <additional_arguements>
(must)  (optional)  (optional)

```

### Examples:
### Notes:
- "-"    stands for command
- "="    stands for system interaction
- "( )"  stands for an update in the data
    
```shell
- Register
= please, register your info:
Name: Mohamed Yehia
Age: 23
Mail: mohamedyehia@gmail.com
Password: 1234


- Login
= please, write your e-mail and password:
Mail: mohamedyehia@gmail.com
Password: hakuna_matata

- Logout
(accout is logged out and we are redirected to home page)


- ViewProfile <mail>
- ViewProfile mody_nokta@yahoo.com
(screen is cleared and profile pops up)


- EditProfile
= please, enter your password first: 123456
= what do you want to change ?
- age
= Enter the new age:
- 27
(profile is updated then pops up again)


- ViewRequests
= name: Mostafa Tarek
  mail: mostafatarek@gmail.com
  
  name: Ahmed Mahmoud
  mailL ahmedmamhoud@yahoo.com
  

- BrowseFriends
= name: Mostafa Tarek
  mail: mostafatarek@gmail.com
  
  name: Ahmed Mahmoud
  mail: ahmedmahmoud@yahoo.com
  

- ViewPosts
  (all user's posts and his friends are printed)


- Add <mail> <name>
- Add mostafatarek@gmail.com Mostafa Tarek


- Accept <mai> <name>
- Accept mohamedyehia@gmail.com Mohamed Yehia


- Reject <mail> <name>
- Reject mohamedyehia@gmail.com Mohamed Yehia


- Post
= What's in your mind ?
- Know me no pain, no me know pain.
  (all users posts pops up with the new post and each post is drawn in a frame)


- Like <mail> <ID>
= Like mohamedyehia@gmail.com 5
  (post is liked and all posts are updated with the new likes)


- Switch <role>
- Switch Admin
- Swtich User
  (switching roles automatically logout from any logged in user)

- home
  (screen is cleared and all posts of the user and his friends appear on screen)


- help
  (all system commands are printed on the screen)


- quit
- exit
  (software is closed)


```
___

## How to use?


___

## Our Team


___

## Contribution


___

## Author
* [Mahmoud Hamdy](https://github.com/SuperMoody)

___

## Licence

This project is licensed under the Apache 2.0 License - see the [LICENSE.md](https://github.com/SuperMoody/Social-Network/blob/master/LICENSE) file for details


