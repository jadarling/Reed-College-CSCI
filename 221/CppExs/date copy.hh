/*
 * A class to store valid dates
 */

#pragma once // Don't include me more than once

class Date {
  public:
    Date(unsigned y, unsigned m, unsigned d);

    Date()
      : Date(2018, 10, 26)
    {
    }

    Date& operator=(const Date& other)
    {
      y_ = other.y_;
      m_ = other.m_;
      d_ = other.d_;
      return *this;
    }


    Date(const Date& other) = delete;

    ~Date() = default;

    bool operator<(const Date& other)
    {
      return m_ < other.m_ or (m_ == other.m_ && ...)
    }


    if(d1 < d2) { ...}


    unsigned year() const { return y_; }
    unsigned month() const { return m_; }
    unsigned day() const { return d_; }


    friend bool operator<(const Date& d1, const Date& d2);

  private:
    unsigned y_;
    unsigned m_;
    unsigned d_;

    bool is_valid() const;

    std::osteam& operator<<(std::ostream& out)
    {
      out << y_ << "-" << m_ << "-" << d_;
      return out;
    }

    void operator()(unsigned days)
    {
      y_ += days;
      assert(is_valid());
    }
};

Date d;

d(6);
d.operator()(6);

bool operator<(const Date& d1, const Date& d2)
{
  return d1.y_ < d2.y_;
}
