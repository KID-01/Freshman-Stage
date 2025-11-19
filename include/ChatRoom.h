#ifndef CHATROOM_H
#define CHATROOM_H


#include<vector>
#include<string>
#include<memory>

class User;
class Message;

class ChatRoom{
private:
    std::string roomName;
    std::vector<std::shared_ptr<User>> m_users;
    std::vector<Message> m_messages;
public:
    ChatRoom(const std::string& name);
    
    // 基础功能
    void addUser(std::shared_ptr<User> user);
    void sendMessage(std::shared_ptr<User> sender,const std::string& content);
    void displayMessages()const;
    bool userLogin(const std::string& userID);
    bool userLogout(const std::string& userID);
    void displayOnlineUsers() const;
};


#endif
