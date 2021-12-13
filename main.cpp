#include <iostream>
#include <vector>
class Contact{
public:
    std::string name = "";
    std::string number = "";
};

class MobilePhone{

    //std::vector<Contact> contacts;
    int count = 0;
    bool isNumber(std::string text){
        return (text[0] == '+' || (text[0] >= '0' && text[0] <= '9'));
    }
public:
    Contact contacts[100];
    void add(){
        //contacts.push_back(1);
        if (count <= 99) {
            std::cout << "Name: ";
            std::cin >> contacts[count].name;
            std::cout << "Number: ";
            std::cin >> contacts[count].number;
            count++;
        } else std::cerr << "Not enough storage place!";
    }

    void call(){
        std::string userInput;
        std::cin >> userInput;
        if (isNumber(userInput)) {
            for (int i = 0; i < count; i++){
                if (contacts[i].number == userInput) std::cout << "CALL " <<  contacts[i].number;
                else std::cout << "Contact hasn't been found.";
            }
        } else {
            for (int i = 0; i < count; i++){
                if (contacts[i].name == userInput) std::cout << "CALL " <<  contacts[i].number;
                else std::cout << "Contact hasn't been found.";
            }
        }
    }

    void sms(){
        std::string userInput;
        std::string message;
        std::cin >> userInput;
        std::cin >> message;
        if (isNumber(userInput)) {
            for (int i = 0; i < count; i++){
                if (contacts[i].number == userInput) std::cout << "SMS " <<  contacts[i].number << " " << message;
            }
        } else {
            for (int i = 0; i < count; i++){
                if (contacts[i].name == userInput) std::cout << "SMS " <<  contacts[i].number << " " << message;
            }
        }
    }


};

int main() {
    MobilePhone *mobilePhone = new MobilePhone();
    std::string cmd;
    while (true) {
        std::cin >> cmd;
        if (cmd == "add") mobilePhone->add();
        else if (cmd == "call") mobilePhone->call();
        else if (cmd == "sms") mobilePhone->sms();
        else if (cmd == "exit") return 0;
        else std::cout << "Invalid command";
       //for (int i = 0; i < 100; i++){
       //     std::cout << mobilePhone[i].contacts->name << " " << mobilePhone[i].contacts->number << std::endl;
      //  }
    }
}

