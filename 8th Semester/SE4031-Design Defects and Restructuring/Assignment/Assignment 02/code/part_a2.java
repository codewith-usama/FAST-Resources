// Application with encapsulating what varies

interface Sender {
    void send(String content);
}

class EmailSender implements Sender {
    @Override
    public void send(String content) {
        System.out.println("Sending email: " + content);
    }
}

class SMSSender implements Sender {
    @Override
    public void send(String content) {
        System.out.println("Sending SMS: " + content);
    }
}

class PushSender implements Sender {
    @Override
    public void send(String content) {
        System.out.println("Sending push notification: " + content);
    }
}

class Message {
    private String content;
    private Sender sender;

    public Message(String content, Sender sender) {
        this.content = content;
        this.sender = sender;
    }

    public void send() {
        sender.send(content);
    }
}

public class Main {
    public static void main(String[] args) {
        Sender emailSender = new EmailSender();
        Sender smsSender = new SMSSender();
        Sender pushSender = new PushSender();

        Message emailMessage = new Message("Hello, this is an email message!", emailSender);
        Message smsMessage = new Message("Hello, this is an SMS message!", smsSender);
        Message pushMessage = new Message("Hello, this is a push notification message!", pushSender);

        emailMessage.send();
        smsMessage.send();
        pushMessage.send();
    }
}
