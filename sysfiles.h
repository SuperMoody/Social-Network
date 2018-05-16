#ifndef _SYSFILES_H_
#define _SYSFILES_H_



/** database.txt **/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void database_init();
void database_update(string Mail, string Password);
bool database_search(string Mail, string Password);
void system_help();



#endif // _SYSFILES_H_

