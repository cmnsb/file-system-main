#pragma once
#include "AbstractParsingStrategy.h"
#include <vector>
#include <string>

class TcdParsingStrategy : public AbstractParsingStrategy {
public:
    virtual std::vector<std::string> parse(std::string input) override;
};
