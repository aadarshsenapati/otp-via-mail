#ifndef EMAIL_SENDER_H
#define EMAIL_SENDER_H

#include <string>

class EmailSender {
public:
    EmailSender(const std::string& username, const std::string& password, const std::string& smtpServer, int port = 587);
    bool sendEmail(const std::string& to, const std::string& subject, const std::string& message);

private:
    std::string m_username;
    std::string m_password;
    std::string m_smtpServer;
    int m_port;
};

#endif // EMAIL_SENDER_H
