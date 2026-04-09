#pragma once
#include "AbstractFileVisitor.h"
#include <iostream>
#include <cmath>
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_TextFile(TextFile*) override;
    void visit_ImageFile(ImageFile*) override;
};