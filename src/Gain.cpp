#include "Gain.h"

Gain::Gain(const Date &date, const std::string &source, const unsigned int sum)
    : local_date{date}, local_source{source}, local_sum{sum} {}

const std::string &Gain::source() const { return local_source; }

unsigned int Gain::sum() { return local_sum; }
