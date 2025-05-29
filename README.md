# **Python**

---

### Requirements:

1. Python 3  
2. `smtplib` – For Gmail connection  
3. `maskpass` – To mask password

---

### Description:

This Python script sends an OTP (One-Time Password) via email using the `smtplib` library.  
The script takes the user's email credentials and recipient's email, generates a random OTP,  
and sends it in an email.

---

### Usage:

- **Run the Script:** Execute the script in a Python environment.  
- **Enter Email Details:** Input your email, app-specific password, and the recipient's email when prompted.  
- **Receive OTP:** The recipient will receive an email with the OTP.

---

# **PhP**

---

### Requirements:

- PHP 7 or later  
- Access to a mail server (e.g., SMTP with Gmail)  
- Internet connection

---

### Description:

This PHP script uses PHPMailer to send a secure, SMTP-authenticated email containing a randomly generated 6-digit OTP to the user's email address retrieved from session data. The OTP is stored in the session for verification purposes, and the email includes both an HTML body and a plain-text fallback, with proper error handling to notify if sending fails. SMTP server credentials and settings must be configured correctly for successful delivery, and after sending the email, the user is redirected to the next step in the workflow.

---

### Usage:

1. Ensure PHPMailer library files are included and properly configured in your project.  
2. Set user email and name in PHP session variables before running the script.  
3. Configure SMTP settings (host, username, password, port) in the script to match your email provider.  
4. Run the script to generate and send the OTP email; after successful sending, the user will be redirected to the next page.

---

### Note:

Download the PHPMailer from [PHPMailer](https://github.com/PHPMailer/PHPMailer).  
Copy the `src` folder and paste it in your project folder.  
Execute the `OTP.php` for this repository.

---

## **C++**

---

### **Requirements:**

- C++17 or later  
- [`libcurl`](https://curl.se/libcurl/) installed (can be installed via [vcpkg](https://github.com/microsoft/vcpkg))  
- Access to an SMTP mail server (e.g., Gmail SMTP)  
- Internet connection  
- CMake (recommended for building the project)  

---

### **Description:**

This C++ program uses `libcurl` to send a secure, SMTP-authenticated email containing a randomly generated 6-digit OTP to the user's email address. The OTP is stored in a local variable (can be extended to file or DB for validation). The email includes a plain text message and is sent via an SMTP server (e.g., Gmail, Outlook). The program is modular, using a custom `EmailSender` class to encapsulate email-sending logic. SMTP credentials must be provided correctly, and `libcurl` must be linked properly for successful delivery.

---

### **Usage:**

1. **Install libcurl using vcpkg:**
   ```bash
   vcpkg install curl
   ```
2. **Create the project folder structure:**
   ```sql
   EmailSenderCPP/
    ├── CMakeLists.txt
    ├── main.cpp
    ├── include/
    │   └── EmailSender.h
    ├── src/
    │   └── EmailSender.cpp
    └── vcpkg/ (optional if using local clone)
    ```
3. **Configure SMTP settings in EmailSender.cpp with your SMTP host, username, and password.**
4. **Build and run the project using CMake:**
   ```bash
   mkdir build
    cd build
    cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
    cmake --build .
    ./EmailSenderCPP
    ```
### **Note:**
- Install and configure vcpkg if not already available.
- Use Gmail's App Passwords or another provider’s SMTP credentials.
- For Gmail, make sure "Allow less secure apps" or App Password is enabled for sending mail.
- Customize the OTP logic or store it as needed for your use case.
