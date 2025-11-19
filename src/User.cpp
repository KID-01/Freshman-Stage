#include"User.h"
#include<string>

User::User(std::string id,const std::string& nk):ID(id),nickname(nk),isOnline(false){}
std::string User::getID() const{return ID;}
std::string User::getNickname() const{return nickname;}
bool User::getOnline() const{return isOnline;}

void User::login(){isOnline=true;}

void User::logout(){isOnline=false;}

