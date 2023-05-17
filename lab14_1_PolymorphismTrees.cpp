#include <iostream>

using namespace std;

class Tree {
public:
    virtual void draw() const = 0;
};

// успалковані:
class Tree1 : public Tree {
public:
    void draw() const override {
        cout << "/\\" << endl;
        cout << "//\\\\" << endl;
    }
};

class Tree2 : public Tree {
public:
    void draw() const override {
        cout << "/\\" << endl;
        cout << "/**\\" << endl;
    }
};

class Tree3 : public Tree {
public:
    void draw() const override {
        cout << "/\\" << endl;
        cout << "/++\\" << endl;
    }
};

int main() {
    Tree* treeTable[3]; //вказує на те, що кожен елемент масиву буде вказівником на об'єкт класу Tree. Тобто, treeTable буде масивом, що містить три вказівники на об'єкти типу Tree.
    Tree1 tree1;
    Tree2 tree2;
    Tree3 tree3;

    treeTable[0] = &tree1;
    treeTable[1] = &tree2;
    treeTable[2] = &tree3;

    for (int i = 0; i < 3; i++) {
        cout << "Drawing " << i + 1 << ":" << endl;
        treeTable[i]->draw();
        cout << endl;
    }

    return 0;
}
