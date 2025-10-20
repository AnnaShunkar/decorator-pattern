#include <iostream>
using namespace std;

class IMessage {
public:
    virtual void send() const = 0;
    virtual ~IMessage() = default;
};

// конкретний компонент //
class SimpleMessage : public IMessage {
public:
    void send() const override {
        cout << "Sending basic message." << endl;
    }
};

// декоратор, який додає шифрування повідомлення //
class EncryptionDecorator : public IMessage {
private:
    IMessage* wrapped;
public:
    EncryptionDecorator(IMessage* msg) : wrapped(msg) {}

    void send() const override {
        cout << "[Encryption] Encrypting message..." << endl;
        wrapped->send();
        cout << "[Encryption] Message encrypted." << endl;
    }

    ~EncryptionDecorator() {
        delete wrapped;
    }
};

int main() {
    IMessage* message = new SimpleMessage();

    IMessage* encrypted = new EncryptionDecorator(message);

    encrypted->send();

    return 0;
}