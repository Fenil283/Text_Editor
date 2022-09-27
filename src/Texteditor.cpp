#include "Texteditor.h"

Texteditor::~Texteditor()
{
    file_node *nf1=first_file;
    while(first_file!=NULL)
    {
        first_file=first_file->next_file;
        nf1->f->~file();
        nf1=first_file;
    }
}
Texteditor::Texteditor()
{
    first_file=NULL;
    last_file=NULL;
}
void Texteditor::push_file(string fname,file *ftemp)
{
    file_node *nf1=new file_node;
    nf1->filename=fname;
    nf1->f=ftemp;
    nf1->next_file=NULL;
    if(first_file==NULL)
    {
        first_file=nf1;
        last_file=nf1;
        return;
    }
    last_file->next_file=nf1;
    last_file=nf1;
}
void Texteditor::delete_file(string fname)
{
    file_node *nf1=first_file,*nf2;
    if(nf1->filename==fname)
    {
        first_file=first_file->next_file;
        delete nf1;
        cout<<"File "<<fname<<" is deleted."<<endl;
        return;
    }
    while(nf1!=last_file && nf1->next_file->filename!=fname)
    {
        nf1=nf1->next_file;
    }
    if(nf1==last_file)
    {
        cout<<"The file doesn't exist"<<endl;
        return;
    }
    else
    {
        nf2=nf1->next_file;
        nf1->next_file=nf1->next_file->next_file;
        delete nf2;
    }
    cout<<"File "<<fname<<" is deleted."<<endl;
}
bool Texteditor::isEmpty()
{
    if(first_file==NULL)
        return true;
    return false;
}
void Texteditor::open_file(string fname)
{
    file_node *nf1=first_file;
    while(nf1!=NULL)
    {
        if(nf1->filename==fname)
        {
            nf1->f->display_file();
            return;
        }
        nf1=nf1->next_file;
    }
}
void Texteditor::display_files()
{
    if(first_file==NULL)
    {
        cout<<"No files to display"<<endl;
        return;
    }
    file_node *nf1=first_file;
    while(nf1!=NULL)
    {
        cout<<nf1->filename<<endl;
        nf1=nf1->next_file;
    }
    cout<<endl;
}
void Texteditor::edit_file(string fname,Paragraph *p1)
{
    file_node *nf1=first_file;
    while(nf1!=NULL)
    {
        if(nf1->filename==fname)
        {
            nf1->f->push_para(p1);
            return;
        }
        nf1=nf1->next_file;
    }
}
void Texteditor::find_and_replace(string fname,string sf,string sr)
{
    file_node *nf1=first_file;
    while(nf1!=NULL)
    {
        if(nf1->filename==fname)
        {
            nf1->f->find_and_replace(sf,sr);
            break;
        }
        nf1=nf1->next_file;
    }
}
bool Texteditor::ifExist(string fname)
{
    file_node *nf1=first_file;
    while(nf1!=NULL)
    {
        if(nf1->filename==fname)
        {
            return true;
        }
        nf1=nf1->next_file;
    }
    return false;
}




