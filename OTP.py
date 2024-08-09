# yqcn cbbg wdqg egor
import smtplib
import maskpass
smtp_object = smtplib.SMTP('smtp.gmail.com',587)
smtp_object.ehlo()
smtp_object.starttls()
mail=email = input("Enter your email: ")
password= maskpass.askpass("Enter app password: ")
print(smtp_object.login(email,password))
from_e='noreply@gmail.com'
to_e= input("Enter reciver's mail ID: ")
subject="OTP"
import random
number = random.randint(1111, 9999)
text="Your OTP is: "
msg = f"Subject: {subject}\n\n{text}{number}"
smtp_object.sendmail(from_e,to_e,msg)


print("Enter the password: ")
li=maskpass.askpass(mask="*")
li=int(li)
if(li==number):
    print("Login suceessful!")
