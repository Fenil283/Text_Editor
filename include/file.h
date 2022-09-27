#ifndef FILE_H
#define FILE_H

#include<paragraph.h>

#include<bits/stdc++.h>

using namespace std;


typedef struct node_para
{
    Paragraph *p;
    node_para *next_para;
}node_para;

class file  //for accsessing all files and its data.
{
    node_para *first_para,*last_para;
    public:
        file();
        ~file();
        void push_para(Paragraph *);
        void new_file();
        void find_and_replace(string,string);
        void pop_para();
        bool isEmpty();
        void display_file();
};


#endif // FILE_H
