#ifndef USER_H
#define USER_H

#include<string>
#include<memory>


class User{
public:
    User(std::string Id,const std::string& Nickname);
    std::string getID() const;
    std::string getNickname() const;
    bool getOnline() const;
    void login();
    void logout();

private:
    std::string ID;
    std::string nickname;
    bool isOnline;
};

#endif

