#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string username, email, password,pwd;
    fstream file;
    public:
    void login();
    void signup();
    void forgot();
}obj;

int main(){
    char choice;
    cout<<"\n1 - Login";
    cout<<"\n2 - Sign Up";
    cout<<"\n3 - Forget Password";
    cout<<"\n4 - Exit";
    cout<<"\n Enter your choice :: ";
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.login();
        break;
        case '2':
            cin.ignore();
            obj.signup();
        break;
        case '3':
            cin.ignore();
            obj.forgot();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<" \n Invalid Selection! ";
    }
}

void temp::signup(){
    cout<<"\n Enter your username";
    getline(cin,username);
    cout<<"\n Enter email address";
    getline(cin,email);
    cout<<"\n Enter pwd";
    getline(cin,pwd);

    file.open("loginData.txt",ios::out|ios::app);
    file<<username<<"*"<<email<<"*"<<pwd<<endl;
    file.close();
}
void temp::login(){
    string searchname,searchpass;

    cout<<"\nenter your username: ";
    getline(cin,searchname);
    cout<<"\nenter your password: ";
    getline(cin,searchpass);

    file.open("loginData.txt",ios::in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        
        if (username == searchname){
            if (password == searchpass){
                cout<<"\n Login successful";
                cout<<"\n Email:: "<< email;
            }
            else{
                cout<<"\nincorrect pwd: ";
            }
        }
    
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    }
    file.close();
}

void temp::forgot(){
    string searchname,newpass;
    cout<<"\nenter username: \n";
    getline(cin,searchname);
    file.open("loginData.txt",ios::in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while (!file.eof()){
        if (searchname == username){
            cout<<"password is: "<<password;
        }
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    
    }
}
