
#include <vector>
#include <string>
using std::vector;
using std::string;

struct Message {
    string name;
    string text;
};

class Chat {
    string name;
    static vector<Message> messages;
public:

    Chat(string name) : name{name} {};

    void say(string text){
        Message mes;
        mes.name = name;
        mes.text =  text;
        messages.push_back(mes);
    }

    static int size(){
        return messages.size();
    }

    static Message get(int i){
        return messages[i];
    }
};


vector<Message> Chat::messages;

int main( ){
    //vector<Message> Chat::messages;
    Chat c("B");
    //Message m;

    Chat::get(0).name;
}

