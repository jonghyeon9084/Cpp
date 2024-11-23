#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

using namespace std;

void displayMenu() {
    cout << "삽입: 1, 삭제: 2, 모두보기: 3, 종료: 4 >> ";
}

int main() {
    vector<Shape*> shapes;
    int choice;
    cout << "그래픽 에디터입니다." << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "선:1, 원:2, 사각형:3 >> ";
            cin >> type;

            if (type == 1) {
                shapes.push_back(new Line());
            }
            else if (type == 2) {
                shapes.push_back(new Circle());
            }
            else if (type == 3) {
                shapes.push_back(new Rect());
            }
            else {
                cout << "잘못된 입력입니다." << endl;
            }
        }
        else if (choice == 2) {
            int index;
            cout << "삭제하고자 하는 도형의 인덱스 >> ";
            cin >> index;

            if (index >= 0 && index < shapes.size()) {
                delete shapes[index];
                shapes.erase(shapes.begin() + index);
            }
            else {
                cout << "잘못된 인덱스입니다." << endl;
            }
        }
        else if (choice == 3) {
            if (shapes.empty()) {
                cout << "저장된 도형이 없습니다." << endl;
            }
            else {
                for (int i = 0; i < shapes.size(); ++i) {
                    cout << i << ": ";
                    shapes[i]->paint();
                }
            }
        }
        else if (choice == 4) {
            for (Shape* shape : shapes) {
                delete shape;
            }
            shapes.clear();

            break;
        }
        else {
            cout << "잘못된 선택입니다. 다시 입력해주세요." << endl;
        }
    }

    return 0;
}
