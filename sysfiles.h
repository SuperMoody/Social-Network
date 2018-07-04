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
int database_count();
void system_help();
int load_ID();
void save_ID(int id);


// Command specific functions
string extract_command(string text);
string trim_input(string text); //still buggy so it's not used for now
void parse_command(string Input, string& Command, string& Mail, string& Name);

// drawing specific functions
void draw_post(string name, string text, int ID, int likes = 0);
void draw_top_side(string name);
void draw_bottom_side(int ID, int likes);
int end_line(string text, int start_pos = 0);





#endif // _SYSFILES_H_

