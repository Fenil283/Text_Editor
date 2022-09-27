#include "file.h"

file::file()
{
    first_para=NULL;
    last_para=NULL;
}
file::~file()
{
    node_para *np1=first_para;
    while(first_para!=NULL)
    {
        first_para=first_para->next_para;
        delete np1;
        np1=first_para;
    }
}
void file::new_file()
{
    first_para=NULL;
    last_para=NULL;
}
void file::push_para(Paragraph *p_temp)
{
    node_para *np1=new node_para;
    np1->p=p_temp;
    np1->next_para=NULL;
    if(first_para==NULL)
    {
        first_para=np1;
        last_para=np1;
        return;
    }
    last_para->next_para=np1;
    last_para=np1;
}
void file::pop_para()
{
    if(last_para->p->isEmpty())
    {
        if(first_para==last_para)
        {
            first_para=NULL;
            last_para=NULL;
            return;
        }
        node_para *np1=first_para;
        while(np1->next_para!=last_para)
        {
            np1=np1->next_para;
        }
        delete last_para;
        last_para=np1;
    }
}
void file::find_and_replace(string sf,string sr)
{
    node_para *np1=first_para;
    while(np1!=NULL)
    {
        np1->p->find_and_replace(sf,sr);
        np1=np1->next_para;
    }
}
bool file::isEmpty()
{
    if(first_para==NULL)
        return true;
    return false;
}
void file::display_file()
{
    cout << "The content of file is given below." << endl<<endl;
    cout << "     ";
    node_para *np1=first_para;
    while(np1!=NULL)
    {
        np1->p->display_paragraph();
        np1=np1->next_para;
    }
    cout << endl << endl;
    cout<<"END OF FILE"<<endl<<endl;
}


