#include <iostream>
#include <vector>
class Contact{
    std::string name = "";
    std::string number = "";
public:
    std::string getName()
    {
        return name;
    }
    std::string getNumber()
    {
        return number;
    }
    void setName(std::string newName){
        name = newName;
    }
    void setNumber(std::string newNumber){
        number = newNumber;
    }
};

class MobilePhone{
    std::vector<Contact> contacts;
    bool isNumber(std::string text){
        for (int i = 0; i < text.length(); i++)
        {
            if (!(text[i] == '+' || (text[i] >= '0' && text[i] <= '9'))) return false;
        }
        return true;
    }
public:
    void add(){
        Contact newContact;
        std::string tmp;
        std::cout << "Name: ";
        std::cin >> tmp;
        newContact.setName(tmp);
        //contacts[contacts.size() - 1].setName(tmp);
        std::cout << "Number: ";
        std::cin >> tmp;
        newContact.setNumber(tmp);
        contacts.push_back(newContact);
        //contacts[contacts.size() - 1].setNumber(tmp);
    }

    void call(){
        std::string userInput;
        std::cin >> userInput;
        if (isNumber(userInput)) {
            for (int i = 0; i < contacts.size(); i++){
                if (contacts[i].getNumber() == userInput) std::cout << "CALL " <<  contacts[i].getName();
            }
        } else {
            for (int i = 0; i < contacts.size(); i++){
                if (contacts[i].getName() == userInput) std::cout << "CALL " <<  contacts[i].getNumber();
            }
        }
    }

    void sms(){
        std::string userInput;
        std::string message;
        std::cin >> userInput;
        std::cin >> message;
        if (isNumber(userInput)) {
            for (int i = 0; i < contacts.size(); i++){
                if (contacts[i].getNumber() == userInput) std::cout << "SMS " <<  contacts[i].getName() << " " << message;
            }
        } else {
            for (int i = 0; i < contacts.size(); i++){
                if (contacts[i].getName() == userInput) std::cout << "SMS " <<  contacts[i].getNumber() << " " << message;
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
        else if (cmd == "exit") break;
        else std::cout << "Invalid command";
    }

    delete mobilePhone;
    return 0;
}

