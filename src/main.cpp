#include <stdexcept>

class Date {
public:
  enum Months {
    January = 1,
    Februray,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
  };

private:
  int local_year;
  int local_month;
  int local_day;

  static void year_validate(const int year) {
    if (year < 0)
      throw std::range_error{"years lesser than 0 isn't supported"};
  }

  static void day_validate(const int year, const Months month, const int day) {
    if (day < 1)
      throw std::range_error{"day can't be lesser than 1"};
    if (day > 31)
      throw std::range_error{"day can't be greater than 31"};
    if (day > days_in_month(month, year))
      throw std::range_error{"count of days and month aren't compatible"};
  }

public:
  Date(const int year, const Months month, const int day)
      : local_year{year}, local_month{month}, local_day{day} {
    Date::validate(year, month, day);
  }

  static void validate(const int year, const Months month, const int day) {
    Date::year_validate(year);
    Date::day_validate(year, month, day);
  }

  static const bool is_leap_year(const int year) {
    Date::year_validate(year);
    return !(year % 4) && ((!(year % 100) && !(year % 400)) || (year % 100));
  }

  static const int days_in_month(const Months month, const int year) {
    switch (month) {
    case (Februray):
      return 28 + Date::is_leap_year(year);
    case (January || March || May || July || August || October || December):
      return 31;
    default:
      return 30;
    }
  }
};

class Gain {
private:
  Date local_date;
  std::string local_source;
  int local_sum;

public:
  Gain(const Date &date, const std::string &source, const int sum)
      : local_date{date}, local_source{source}, local_sum{sum} {}
};

int main() {}
