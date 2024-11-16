#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    Shape* next;
public:
    Shape() : next(nullptr) {}
    virtual ~Shape() {}
    virtual void draw() = 0;
    void setNext(Shape* nextShape) { next = nextShape; }
    Shape* getNext() { return next; }
};

class Line : public Shape {
public:
    void draw() override {
        cout << "Line" << endl;
    }
};

class Rect : public Shape {
public:
    void draw() override {
        cout << "Rectangle" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Circle" << endl;
    }
};

class GraphicEditor {
private:
    Shape* start;
    Shape* last;

public:
    GraphicEditor() : start(nullptr), last(nullptr) {}
    ~GraphicEditor() {
        while (start != nullptr) {
            Shape* temp = start;
            start = start->getNext();
            delete temp;
        }
    }

    void insertShape() {
        int choice;
        cout << "선: 1, 원: 2, 사각형: 3 >> ";
        cin >> choice;

        Shape* newShape = nullptr;
        switch (choice) {
        case 1:
            newShape = new Line();
            break;
        case 2:
            newShape = new Circle();
            break;
        case 3:
            newShape = new Rect();
            break;
        default:
            cout << "잘못된 선택입니다." << endl;
            return;
        }

        if (start == nullptr) {
            start = newShape;
            last = newShape;
        }
        else {
            last->setNext(newShape);
            last = newShape;
        }
    }

    void eraseShape() {
        int index;
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        cin >> index;

        if (start == nullptr) {
            cout << "삭제할 도형이 없습니다." << endl;
            return;
        }

        Shape* prev = nullptr;
        Shape* current = start;
        int count = 0;

        while (current != nullptr && count < index) {
            prev = current;
            current = current->getNext();
            count++;
        }

        if (current == nullptr) {
            cout << "잘못된 인덱스입니다." << endl;
            return;
        }

        if (prev == nullptr) {
            start = current->getNext();
        }
        else {
            prev->setNext(current->getNext());
        }

        if (current == last) {
            last = prev;
        }

        delete current;
    }

    void viewShapes() {
        if (start == nullptr) {
            cout << "저장된 도형이 없습니다." << endl;
            return;
        }

        Shape* current = start;
        int index = 0;

        while (current != nullptr) {
            cout << index << ": ";
            current->draw();
            current = current->getNext();
            index++;
        }
    }

    void run() {
        cout << "그래픽 에디터입니다." << endl;

        while (true) {
            int choice;
            cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
            cin >> choice;

            switch (choice) {
            case 1:
                insertShape();
                break;
            case 2:
                eraseShape();
                break;
            case 3:
                viewShapes();
                break;
            case 4:
                return;
            default:
                cout << "잘못된 입력입니다." << endl;
            }
        }
    }
};

int main() {
    GraphicEditor editor;
    editor.run();
    return 0;
}
