#include "mockos/BasicDisplayVisitor.h"

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
    vector<char> data = file->read();
    int dim = static_cast<int>(sqrt(data.size()));
    for (int y = dim - 1; y >= 0; --y) {
        for (int x = 0; x < dim; ++x) {
            cout << data[y * dim + x];
        }
        cout << endl;
    }
}

void BasicDisplayVisitor::visit_TextFile(TextFile *file) {
    vector<char> contents = file->read();
    for (char c : contents) {
        cout << c;
    }
    cout << endl;
}
