#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
class admin
{
 protected:
            string book_name[100];
            int price[100],id[100];
 public:
        int i;
        void add_book(int n,ofstream &b)
       {
         for(i=0;i<n;i++)
         {
         cout<<"enter the book "<<i+1<<" id"<<endl;
         cin>>id[i];
         cout<<"enter book  "<<i+1<<" name to be added"<<endl;
         getline(cin>> std::ws,book_name[i]);
         cout<<"enter the price of  "<<book_name[i]<<"book"<<endl;
         cin>>price[i];
         }
         for(i=0;i<n;i++)
          b<<id[i]<<" "<<book_name[i]<<" "<<price[i]<<endl;

     }
};
class user:public admin
{
public :
         int c1,c3,last1,last3,i,choice,flag;
         string name1[100],name2[100],sea;

          user()
         {
             c1=0;
             c3=0;
             last1=0;
             last3=0;
             i=0;
             choice=0;
             flag=0;
         }
          void display_user(ifstream &b)
         {
            cout<<"1: search\n2: display books"<<endl;
            cin>>choice;
            switch(choice)
            {
             case 1: cout<<"enter the name for book to be search"<<endl;
                     getline(cin>> std::ws,sea);
                     while(!b.eof())
                     {
                         getline(b>> std::ws,name1[c1]);
                         c1++;
                     }
                     b.close();
                     last1=c1;
                     for(i=0;i<last1;i++)
                     {  if(name1[i].find(sea)!=string::npos)
                        {
                          cout<<"book id  book name book price \n";
                          cout<<name1[i]<<"\t"<<endl;
                          flag=true;
                        }
                     }
                     if(flag==false)
                         cout<<"sorry book not found"<<endl;
                     break;

             case 2: while(!b.eof())
                     {
                         getline(b>> std::ws,name2[c3]);
                         c3++;
                     }
                     last3=c3;
                     cout<<"book id | book name | book price \n"<<endl;
                     for(i=0;i<last3;i++)
                          cout<<name2[i]<<"\t"<<endl;
                     break;
            }
        }
};
int main()
{
    user b1;
    int choice,n,answer=0;
    string username,password,user,pass;
    ofstream bok;
    ifstream pas,rev;
    pas.open("pass.txt");
    pas>>user>>pass;
    pas.close();
    while(answer==0)
    {
        cout<<"enter your choice"<<endl;
        cout<<"1 : ADMIN \n2 : USER \n";
        cin>>choice;
        switch(choice)
        {
            case 1:  cout<<"enter the user_name and password"<<endl;
                     cin>>username>>password;
                     if(username==user&& password==pass)
                     {
                        cout<<"enter the number of books to be added"<<endl;
                        cin>>n;
                        bok.open("book.txt",ios::app);
                        b1.add_book(n,bok);
                        bok.close();
                     }
                     else
                        cout<<"invalid user_name or password"<<endl;
                     break;

            case 2:  rev.open("book.txt",ios::out);
                     b1.display_user(rev);
                     rev.close();
                     break;
            default: cout<<"incorrect choice,pls try again"<<endl;
        }
        cout<<"do want quit answer with yes=1 or no=0"<<endl;
        cin>>answer;
    }
    getchar();
    return 0;
}
