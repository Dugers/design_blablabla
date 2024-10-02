#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/gregorian/greg_month.hpp>
#include <string>

using Date = boost::gregorian::date;

class Gain {
private:
  boost::gregorian::date local_date;
  const std::string local_source;
  const unsigned int local_sum;

public:
  Gain(const Date &date, const std::string &source, const unsigned int sum)
      : local_date{date}, local_source{source}, local_sum{sum} {}

  const std::string &source() const { return local_source; }

  unsigned int sum() { return local_sum; }
};

int main() {}
