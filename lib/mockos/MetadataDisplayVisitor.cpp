#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iomanip>
#include <iostream>

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
    cout << left << setw(20) << file->getName();
    cout << left << setw(10) << "text";
    cout << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
    cout << left << setw(20) << file->getName();
    cout << left << setw(10) << "image";
    cout << file->getSize() << endl;
}