<?php
//Import PHPMailer classes into the global namespace
//These must be at the top of your script, not inside a function
// use PHPMailer\PHPMailer\PHPMailer;
// use PHPMailer\PHPMailer\SMTP;
// use PHPMailer\PHPMailer\Exception;
include("includes/connection.php");
include("php-mailer/PHPMailer.php");
include("php-mailer/SMTP.php");
include("php-mailer/Exception.php");

use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\SMTP;
use PHPMailer\PHPMailer\Exception;

$mail = new PHPMailer(true);

$OTP = rand(100000, 999999);
$_SESSION['otp'] = $OTP;
$name = $_SESSION['signup']['owner_name'];// Replace with the actual session variable for owner name 
$user_email = $_SESSION['user_email'] ?? null;
if (!$user_email) {
    echo "User email not set. Go back to sign up.";
    exit();
}

$msg = "The text you want to send";

try {
    $mail->isSMTP();
    $mail->Host = 'mail.your-provider.com'; // Replace with your SMTP server
    $mail->SMTPAuth = true;
    $mail->Username = 'your@email.com'; // Replace with your SMTP username
    $mail->Password = 'password'; // Replace with your SMTP password
    $mail->SMTPSecure = PHPMailer::ENCRYPTION_SMTPS;
    $mail->Port = 566; // Replace with your SMTP port

    $mail->setFrom('your@email.com', 'Name'); // Replace with your email and name
    $mail->addAddress($user_email); 

    $mail->isHTML(true);
    $mail->Subject = 'Email Verification OTP';
    $mail->Body = $msg;
    $mail->AltBody = "Hi {$user_email},\nYour OTP is {$OTP}\nThis OTP is valid for 10 minutes. Do not share it with anyone.\n\nRegards";

    $mail->send();
    header("Location: next.php"); //Redirect to the next page after sending the email
    exit();
} catch (Exception $e) {
    echo "Mailer Error: {$mail->ErrorInfo}";
}
?>