// Application without encapsulating what varies

class Message {
    private String content;
    private String recipient;

    public Message(String content, String recipient) {
        this.content = content;
        this.recipient = recipient;
    }

    public void send() {
        if (recipient.equals("email")) {
            // Send email
            System.out.println("Sending email to " + recipient + ": " + content);
        } else if (recipient.equals("sms")) {
            // Send SMS
            System.out.println("Sending SMS to " + recipient + ": " + content);
        } else if (recipient.equals("push")) {
            // Send push notification
            System.out.println("Sending push notification to " + recipient + ": " + content);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Message emailMessage = new Message("Hello, this is an email message!", "email");
        Message smsMessage = new Message("Hello, this is an SMS message!", "sms");
        Message pushMessage = new Message("Hello, this is a push notification message!", "push");

        emailMessage.send();
        smsMessage.send();
        pushMessage.send();
    }
}