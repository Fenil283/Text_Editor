#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include<bits/stdc++.h>

using namespace std;


typedef struct word
{
    string s;
    word *next_word;
}word;


class Paragraph //for managing paras in file.
{
    word *first,*last;
    word *first_undo,*last_undo;
    string store;
    public:
        Paragraph();
        ~Paragraph();
        bool isEmpty();
        void new_para();
        void push_word(string);
        void pop_word();
        void push_undo(string);
        void pop_undo();
        void find_and_replace(string,string);
        void find(string);
        void display_paragraph();
};

#endif // PARAGRAPH_H
