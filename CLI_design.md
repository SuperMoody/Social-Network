# CLI Design
## Structure to parse
```shell
<command> <name> <additional_arguements>
(must)  (optional)  (optional)

```

## Examples:
### Notes:
- "-"    stands for command
- "="    stands for system interaction
- "( )"  stands for an immediate action taken by the user
    
```shell
- Register
= please, register your info:
Name: Mahmoud Hamdy
Age: 23
Mail: mahmoudhamdy.eeng@gmail.com
Password: hakuna_matata


- Login
= please, write your e-mail and password:
Mail: mahmoudhamdy.eeng@gmail.com
Password: hakuna_matata


- Search <name>
- Search Mahmoud Hamdy


- ViewProfile <mail>
- ViewProfile mody_nokta@yahoo.com


- EditProfile <mail>
- EditProfile mody_nokta@yahoo.com

= Edit the info you want:
Name: Amal Maher
Mail: sekket_el_salama@yahoo.com
Password: et2y_rbna_fya
(pressing q to quit from edit mode)


- BrowseFriends <user>
- BrowseFriends current_profile_opened


- ADD <mail>
- ADD mody_nokta@yahoo.com


- Accept <mail>
- Accept mody_nokta@yahoo.com


- Reject <mail>
- Reject mody_nokta@yahoo.com


- DeleteProfile
= profile is deleted successfully

- Post
= What's in your mind ?
Know me no pain, no me know pain
(pressing enter to quit text editing)


- Switch <role>
- Switch Admin
= Enter mail and password:
Mail: mahmoudhamdy.eeng@gmail.com
password: hakuna_msh_matata


```
