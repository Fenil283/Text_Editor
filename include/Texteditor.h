#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include<bits/stdc++.h>

#include<paragraph.h>
#include<file.h>

using namespace std;

typedef struct file_node
{
    string filename;
    file *f;
    file_node *next_file;
}file_node;


class Texteditor // for managing files and all its operations.
{
    file_node *first_file,*last_file;
    public:
        Texteditor();
        ~Texteditor();
        bool ifExist(string);
        void push_file(string,file *);
        void delete_file(string);
        void display_files();
        void edit_file(string,Paragraph *);
        void find_and_replace(string,string,string);
        bool isEmpty();
        void open_file(string);
};
#endif // TEXTEDITOR_H
