import smtplib
import sys
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Gmail credentials
EMAIL_ADDRESS = "malakkalaabiadd@gmail.com"
EMAIL_PASSWORD = "umce hplw fftf twjw"

def send_email(recipient, date):
    subject = "Iftar Invitation Reminder"
    body = f"Dear guest,\n\nThis is a reminder that your Iftar invitation is scheduled for {date}.\n\nBest regards,\nIftar Manager"

    # Email message setup
    msg = MIMEMultipart()
    msg["From"] = EMAIL_ADDRESS
    msg["To"] = recipient
    msg["Subject"] = subject
    msg.attach(MIMEText(body, "plain"))

    try:
        # Connect to Gmail SMTP server
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls()
        server.login(EMAIL_ADDRESS, EMAIL_PASSWORD)
        server.sendmail(EMAIL_ADDRESS, recipient, msg.as_string())
        server.quit()
        print(f"Email sent to {recipient}")
    except Exception as e:
        print(f"Failed to send email: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python send_email.py recipient_email date")
    else:
        send_email(sys.argv[1], sys.argv[2])