#include "EmailSender.h"
#include <iostream>
int main() {
    EmailSender sender("your@email.com", "yourpassword", "smtp.gmail.com");

    if (sender.sendEmail("recipient@example.com", "Test Subject", "Hello from C++!")) {
        std::cout << "Email sent successfully.\n";
    } else {
        std::cout << "Failed to send email.\n";
    }

    return 0;
}