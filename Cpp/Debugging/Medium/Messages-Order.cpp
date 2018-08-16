class Message {
private:
    string message;
    static int id;
    int currId;
public: 
    Message() {
        currId++;
    }
    Message(string text) {
        currId++;
        message = text;
    }
    const string& get_text() {
        return message;
    }
    bool operator < (const Message& M2) {
        return currId < M2.currId;
    }
};

int Message::id = 0;

class MessageFactory {
public:
    MessageFactory() {
        
    }
    Message create_message(const string& text) {
        Message temp(text);
        return temp;
    }
};
