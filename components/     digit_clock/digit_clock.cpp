#include "digit_clock.h"

namespace esphome {
namespace digit_clock {

static const uint8_t DIGITS[10][14] = {
    {1,1,1,1,1,1,0, 1,1,1,1,1,1,0},  // 0
    {0,1,1,0,0,0,0, 0,1,1,0,0,0,0},  // 1
    {1,1,0,1,1,0,1, 1,1,0,1,1,0,1},  // 2
    {1,1,1,1,0,0,1, 1,1,1,1,0,0,1},  // 3
    {0,1,1,1,0,1,1, 0,1,1,1,0,1,1},  // 4
    {1,0,1,1,0,1,1, 1,0,1,1,0,1,1},  // 5
    {1,0,1,1,1,1,1, 1,0,1,1,1,1,1},  // 6
    {1,1,1,0,0,0,0, 1,1,1,0,0,0,0},  // 7
    {1,1,1,1,1,1,1, 1,1,1,1,1,1,1},  // 8
    {1,1,1,1,0,1,1, 1,1,1,1,0,1,1}   // 9
};

static const int OFF[4] = {0, 14, 30, 44};

void DigitClock::draw_digits(int d1, int d2, int d3, int d4) {
  if (this->strip_ == nullptr)
    return;

  auto addr = this->strip_->get_addressable();

  int ds[4] = {d1, d2, d3, d4};

  for (int d = 0; d < 4; d++) {
    int base = OFF[d];
    int num = ds[d];
    if (num < 0 || num > 9)
      num = 0;

    for (int i = 0; i < 14; i++) {
      if (DIGITS[num][i])
        addr->set_pixel_color(base + i, Color(255, 255, 255));
      else
        addr->set_pixel_color(base + i, Color(0, 0, 0));
    }
  }

  this->strip_->publish_state();
}

void DigitClock::show_time(int h, int m) {
  if (h < 0) h = 0;
  if (h > 99) h = 99;
  if (m < 0) m = 0;
  if (m > 99) m = 99;

  draw_digits(h/10, h%10, m/10, m%10);
}

void DigitClock::show_countdown(int seconds) {
  if (seconds < 0) seconds = 0;
  if (seconds > 5999) seconds = 5999;

  int mm = seconds / 60;
  int ss = seconds % 60;

  draw_digits(mm/10, mm%10, ss/10, ss%10);
}

}  // namespace digit_clock
}  // namespace esphome
