#include "../include/EmailSender.h"
#include <curl/curl.h>
#include <iostream>

EmailSender::EmailSender(const std::string& username, const std::string& password, const std::string& smtpServer, int port)
    : m_username(username), m_password(password), m_smtpServer(smtpServer), m_port(port) {}

bool EmailSender::sendEmail(const std::string& to, const std::string& subject, const std::string& message) {
    CURL *curl = curl_easy_init();
    if (!curl) return false;

    std::string url = "smtp://" + m_smtpServer + ":" + std::to_string(m_port);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_USERNAME, m_username.c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, m_password.c_str());
    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, ("<" + m_username + ">").c_str());

    struct curl_slist *recipients = nullptr;
    recipients = curl_slist_append(recipients, ("<" + to + ">").c_str());
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    std::string fullMessage = "To: " + to + "\r\nSubject: " + subject + "\r\n\r\n" + message;
    const char *payload = fullMessage.c_str();

    curl_easy_setopt(curl, CURLOPT_READFUNCTION, [](char *ptr, size_t size, size_t nmemb, void *userp) -> size_t {
        std::string* data = static_cast<std::string*>(userp);
        size_t len = data->copy(ptr, size * nmemb);
        data->erase(0, len);
        return len;
    });

    std::string msgCopy = fullMessage;
    curl_easy_setopt(curl, CURLOPT_READDATA, &msgCopy);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

    CURLcode res = curl_easy_perform(curl);
    curl_slist_free_all(recipients);
    curl_easy_cleanup(curl);

    return res == CURLE_OK;
}
