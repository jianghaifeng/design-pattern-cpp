#include <iostream>

using namespace std;

class UsbCable {
private:
    bool plugged;
public:
    UsbCable() : plugged(false) {}
    
    void plugUsb() {
        plugged = true;
    }

    void status() {
        cout << "plugged: " << plugged << endl;
    }
};
    
class UsbPort {
private:
    bool portAvailable;
public:
    UsbPort() : portAvailable(true) {}

    void plug(UsbCable& cable) {
        cable.plugUsb();
        portAvailable = false;
    }
    
    void status() {
        cout << "available: " << portAvailable << endl;
    }
};

class MicroUsbCable {
private:
    bool plugged;
public:
    MicroUsbCable() : plugged(false) {}

    void plug() {
        plugged = true;
    }
};

class MicroToUsbAdapter : public UsbCable {
private:
    MicroUsbCable microUsbCable;
public:
    MicroToUsbAdapter(MicroUsbCable cable) {
        this->microUsbCable = cable;
    }
};

int main() {
    UsbPort port1;
    UsbPort port2;
    UsbCable cable;
    MicroUsbCable microUsbCable;
    MicroToUsbAdapter microToUsbAdapter(microUsbCable);

    port1.status();
    port2.status();
    cable.status();
    microToUsbAdapter.status();

    port1.plug(cable);
    port2.plug(microToUsbAdapter);

    port1.status();
    port2.status();
    cable.status();
    microToUsbAdapter.status();
}



