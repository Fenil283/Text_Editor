#include <bits/stdc++.h>
#include<paragraph.h>
#include<file.h>
#include<Texteditor.h>

using namespace std;


int main()
{
    Texteditor t;

    int n,i,index;

    char ch;

    bool flag_te=true,flag;

    string s,s1,s2;

    cout<<"!!! WELCOME TO TEXTEDITOR !!!"<<endl;
    cout<<"Press 1 for new file"<<endl;
    cout<<"Press 2 for list of files"<<endl;
    cout<<"Press 3 for opening a file"<<endl;
    cout<<"Press 4 for appending in a file"<<endl;
    cout<<"Press 5 for deleting a file"<<endl;
    cout<<"Press 0 for exiting the editor"<<endl<<endl;

    while(flag_te)
    {
        cout<<"Enter your choice: ";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                cout<<"Enter the name of file: ";
                cin>>s;
                if(!t.ifExist(s))
                {
                    file *f=new file;
                    Paragraph *p=new Paragraph;
                    flag=true;
                    cout<<"Enter the data for file(give ** for ending of file)"<<endl;
                    while(flag)
                    {
                        cin>>s1;
                        i=s1.length();
                        if(i>=2 && s1[i-2]=='*' && s1[i-1]=='*')
                        {
                            p->push_word(s1.substr(0,i-2));
                            flag=false;
                            break;
                        }
                        index=s1.find('.');
                        if(index<=(i-1) && index>=0)
                        {
                            p->push_word(s1.substr(0,index+1));
                            p->push_word(s1.substr(index+1));
                        }
                        else
                        {
                            p->push_word(s1);
                        }
                    }
                    ch='_';

                    //for oprations of text editor
                    while(ch!='s' && ch!='S')
                    {
                        cout<<"Do you want to (u=undo   r=redo   f= find  p=replace   c=enter another data    s=save)?:"<<endl;
                        cin>>ch;
                        if(ch=='u' || ch=='U')
                        {
                            p->pop_word();
                            p->display_paragraph();
                        }
                        else if(ch=='r' ||  ch=='R')
                        {
                            p->pop_undo();
                            p->display_paragraph();
                        }
                        else if(ch=='p' || ch=='P')
                        {
                            cout<<"Enter the string to find: ";
                            cin>>s1;
                            cout<<"Enter the string to replace: ";
                            cin>>s2;
                            p->find_and_replace(s1,s2);
                            p->display_paragraph();
                        }
                        else if(ch=='f' || ch=='F')
                        {
                            cout << "Enter the sting you want to find: ";
                            cin >> s1;
                            p->find(s1);
                        }
                        else if(ch=='c' || ch=='C')
                        {
                            flag=true;
                            cout<<"Enter the data for file(give ** for ending of file)"<<endl;
                            while(flag)
                            {
                                cin>>s1;
                                i=s1.length();
                                if(i>=2 && s1[i-2]=='*' && s1[i-1]=='*')
                                {
                                    p->push_word(s1.substr(0,i-2));
                                    flag=false;
                                    break;
                                }
                                index=s1.find('.');
                                if(index<=(i-1) && index>=0)
                                {
                                p->push_word(s1.substr(0,index+1));
                                p->push_word(s1.substr(index+1));
                                }
                                else
                                {
                                    p->push_word(s1);
                                }
                            }
                        }

                        cout << endl;
                    }
                    cout<<"File is saved."<<endl;
                    f->push_para(p);
                    t.push_file(s,f);
                    f->display_file();
                }
                else
                {
                    cout<<"The file already exists, try different name."<<endl;
                }


                break;
            }
            case 2:
            {
                cout<<"Files: " << endl;
                t.display_files();
                break;
            }
            case 3:
            {
                cout<<"Enter the name of file to open: ";
                cin>>s;
                if(t.ifExist(s))
                    t.open_file(s);
                else
                    cout<<"The file doesn't exist"<<endl;
                break;
            }
            case 4:
            {
                cout<<"Enter the name of file to append: ";
                cin>>s;
                if(t.ifExist(s))
                {
                    flag=true;
                    Paragraph *p=new Paragraph;
                    cout<<"Enter the data for file(give ** for ending of file)"<<endl;
                    while(flag)
                    {
                        cin>>s1;
                        i=s1.length();
                        if(s1[i-2]=='*' && s1[i-1]=='*')
                        {
                            p->push_word(s1.substr(0,i-2));
                            flag=false;
                            break;
                        }
                        index=s1.find('.');
                        if(index<=(i-1) && index>=0)
                        {
                            p->push_word(s1.substr(0,index+1));
                            p->push_word(s1.substr(index+1));
                        }
                        else
                        {
                            p->push_word(s1);
                        }
                    }
                    ch='_';

                //for oprations of text editor
                   while(ch!='s' && ch!='S')
                    {
                        cout<<"Do you want to (u=undo   r=redo   f= find  p=replace   c=enter another data    s=save)?:"<<endl;
                        cin>>ch;
                        if(ch=='u' || ch=='U')
                        {
                            p->pop_word();
                            p->display_paragraph();
                        }
                        else if(ch=='r' ||  ch=='R')
                        {
                            p->pop_undo();
                            p->display_paragraph();
                        }
                        else if(ch=='p' || ch=='P')
                        {
                            cout<<"Enter the string to find: ";
                            cin>>s1;
                            cout<<"Enter the string to replace: ";
                            cin>>s2;
                            p->find_and_replace(s1,s2);
                            p->display_paragraph();
                        }
                        else if(ch=='f' || ch=='F')
                        {
                            cout << "Enter the sting you want to find: ";
                            cin >> s1;
                            p->find(s1);
                        }
                        else if(ch=='c' || ch=='C')
                        {
                            flag=true;
                            cout<<"Enter the data for file(give ** for ending of file)"<<endl;
                            while(flag)
                            {
                                cin>>s1;
                                i=s1.length();
                                if(i>=2 && s1[i-2]=='*' && s1[i-1]=='*')
                                {
                                    p->push_word(s1.substr(0,i-2));
                                    flag=false;
                                    break;
                                }
                                index=s1.find('.');
                                if(index<=(i-1) && index>=0)
                                {
                                p->push_word(s1.substr(0,index+1));
                                p->push_word(s1.substr(index+1));
                                }
                                else
                                {
                                    p->push_word(s1);
                                }
                            }
                        }
                    }
                    cout<<"File is saved."<<endl;
                    t.edit_file(s,p);
                }
                else
                {
                    cout<<"The file doesn't exist, create a new one"<<endl;
                }
                break;
            }
            case 5:
            {
                cout<<"Enter the name of file to delete: ";
                cin>>s;
                t.delete_file(s);
                break;
            }
            case 0:
            {
                flag_te=false;
                break;
            }
            default:
                cout<<"Enter valid choice"<<endl;
        }
    }
    t.~Texteditor();

    return 0;
}
