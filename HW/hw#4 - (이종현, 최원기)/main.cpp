#include <iostream>
#include <string>

class Printer {
protected:
    std::string model;
    std::string manufacturer;
    int availableCount;

public:
    Printer(const std::string& mdl, const std::string& mfr, int availCount)
        : model(mdl), manufacturer(mfr), availableCount(availCount) {}

    virtual ~Printer() {}

    virtual void print(int pages) = 0;

    virtual void displayStatus() const {
        std::cout << model << ", " << manufacturer << ", 남은종이 " << availableCount;
    }

    int getAvailableCount() const { return availableCount; }
};

class InkjetPrinter : public Printer {
private:
    int availableInk;

public:
    InkjetPrinter(const std::string& mdl, const std::string& mfr, int availCount, int ink)
        : Printer(mdl, mfr, availCount), availableInk(ink) {}

    void print(int pages) override {
        if (pages <= availableCount && pages <= availableInk) {
            availableCount -= pages;
            availableInk -= pages;
            std::cout << "프린트하였습니다.\n";
        }
        else {
            std::cout << "용지 또는 잉크가 부족하여 프린트할 수 없습니다.\n";
        }
    }

    void displayStatus() const override {
        Printer::displayStatus();
        std::cout << ", 남은 잉크 " << availableInk << std::endl;
    }

    int getAvailableInk() const { return availableInk; }
};

class LaserPrinter : public Printer {
private:
    int availableToner;

public:
    LaserPrinter(const std::string& mdl, const std::string& mfr, int availCount, int toner)
        : Printer(mdl, mfr, availCount), availableToner(toner) {}

    void print(int pages) override {
        if (pages <= availableCount) {
            availableCount -= pages;
            availableToner -= pages;
            std::cout << "프린트하였습니다.\n";
        }
        else {
            std::cout << "용지가 부족하여 프린트할 수 없습니다.\n";
        }
    }

    void displayStatus() const override {
        Printer::displayStatus();
        std::cout << ", 남은 토너 " << availableToner << std::endl;
    }

    int getAvailableToner() const { return availableToner; }
};

int main() {
    InkjetPrinter inkjet("Office jet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6X45", "삼성전자", 3, 20);

    std::cout << "현재 작동중인 2 대의 프린터는 아래와 같다\n";
    inkjet.displayStatus();
    laser.displayStatus();

    char continuePrinting = 'y';
    int printerChoice, pages;

    while (continuePrinting == 'y') {
        std::cout << "\n프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        std::cin >> printerChoice >> pages;

        if (printerChoice == 1) {
            inkjet.print(pages);
        }
        else if (printerChoice == 2) {
            laser.print(pages);
        }

        inkjet.displayStatus();
        laser.displayStatus();

        std::cout << "계속 프린트 하시겠습니까(y/n)>>";
        std::cin >> continuePrinting;
    }

    return 0;
}
