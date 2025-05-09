import smtplib
import sys
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Gmail credentials
EMAIL_ADDRESS = "malakkalaabiadd@gmail.com"
EMAIL_PASSWORD = "umce hplw fftf twjw"

def send_email(recipient, date):
    subject = "Iftar Invitation Reminder"

    body = f"""Dear Guest,

We hope this message finds you well.

This is a kind reminder that you are cordially invited to our upcoming Iftar gathering scheduled for {date}. 
We would be honored by your presence.

Event Details:
- 📅 Date: {date}
- 🕠 Time: 5:45 PM (Maghrib)
- 📍 Location: FCAI-CU

Please confirm your attendance at your earliest convenience so we can make the necessary arrangements accordingly.

Should you have any questions or require assistance, feel free to reach out to us.

Warm regards,  
Iftar Management Team  
📧 malakkalaabiadd@gmail.com@  
"""

    msg = MIMEMultipart()
    msg["From"] = EMAIL_ADDRESS
    msg["To"] = recipient
    msg["Subject"] = subject
    msg.attach(MIMEText(body, "plain"))

    try:
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls()
        server.login(EMAIL_ADDRESS, EMAIL_PASSWORD)
        server.sendmail(EMAIL_ADDRESS, recipient, msg.as_string())
        server.quit()
        print(f"Email successfully sent to {recipient}")
    except Exception as e:
        print(f"Failed to send email: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python send_email.py recipient_email date")
    else:
        send_email(sys.argv[1], sys.argv[2])
