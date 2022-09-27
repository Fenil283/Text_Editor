#include "Paragraph.h"

Paragraph::Paragraph()
{
    first=NULL;
    last=NULL;
    first_undo=NULL;
    last_undo=NULL;
}
Paragraph::~Paragraph()
{
    word *w1=first,*w2=first_undo;
    while(first!=NULL)
    {
        first=first->next_word;
        delete w1;
        w1=first;
    }
    while(first_undo!=NULL)
    {
        first_undo=first_undo->next_word;
        delete w2;
        w2=first_undo;
    }
}

void Paragraph::new_para()
{
    first=NULL;
    last=NULL;
    first_undo=NULL;
    last_undo=NULL;
}

void Paragraph::push_word(string s1)
{
    word *w1=new word;
    w1->s=s1;
    w1->next_word=NULL;
    if(first==NULL)
    {
        first=w1;
        last=w1;
        return;
    }
    last->next_word=w1;
    last=w1;
}

//for undo operation
void Paragraph::pop_word()
{
    word *w=first;
    if(w==NULL)
    {
        cout<<"Nothing to undo"<<endl;
        return;
    }
    string pop=last->s;
    if(w==last)
    {
        first=NULL;
        last=NULL;
        push_undo(pop);
        return;
    }
    while(w->next_word!=last)
    {
        w=w->next_word;
    }
    delete last;
    w->next_word=NULL;
    last=w;
    push_undo(pop);
    return;
}

void Paragraph::push_undo(string s1)
{
    word *w1=new word;
    w1->s=s1;
    w1->next_word=NULL;
    if(first_undo==NULL)
    {
        first_undo=w1;
        last_undo=w1;
        return;
    }
    last_undo->next_word=w1;
    last_undo=w1;
}
void Paragraph::pop_undo()
{
    word *w=first_undo;
    if(w==NULL)
    {
        cout<<"Nothing to redo"<<endl;
        return;
    }
    string redo=last_undo->s;
    if(w==last_undo)
    {
        first_undo=NULL;
        last_undo=NULL;
        push_word(redo);
        return;
    }
    while(w->next_word!=last_undo)
    {
        w=w->next_word;
    }
    delete last_undo;
    w->next_word=NULL;
    last_undo=w;
    push_word(redo);
    return;
}
void Paragraph::find_and_replace(string sf,string sr)
{
    int l;
    string st;
    word *w=first;
    while(w!=NULL)
    {
        st=w->s;
        l=st.length();
        if(st==sf)
        {
            w->s=sr;
        }
        else if(st.substr(0,l-1)==sf && st[l-1]=='.')
        {
            sr=sr+".";
            w->s=sr;
        }
        w=w->next_word;
    }
}

void Paragraph :: find(string fi)
{
    int count = 0;
    int flag = 0;
    word *dh = first;

    while(dh!=NULL)
    {
        count++;

        if(dh->s == fi)
        {
            if(count == 1)
            cout << "Your word is presnt at " << count << "st position." << endl;
            else if(count == 2)
            cout << "Your word is presnt at " << count << "nd position." << endl;
            else if(count == 3)
            cout << "Your word is presnt at " << count << "rd position." << endl;
            else
            cout << "Your word is presnt at " << count << "th position." << endl;
            flag = 1;
            break;
        }

        dh = dh->next_word;

    }

    if(flag == 0)
    {
        cout << "your word is not present in this file." << endl;
    }
}

void Paragraph::display_paragraph()
{
    word *w=first;
    while(w!=NULL)
    {
        cout<<w->s<<" ";
        w=w->next_word;
    }
}
bool Paragraph::isEmpty()
{
    if(first==NULL)
        return true;
    return false;
}





