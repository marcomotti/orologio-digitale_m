#pragma once

#include "esphome/core/component.h"
#include "esphome/components/light/addressable_light.h"

namespace esphome {
namespace digit_clock {

using light::AddressableLightWrapper;

class DigitClock : public Component {
 public:
  explicit DigitClock(AddressableLightWrapper *strip) : strip_(strip) {}

  void setup() override {}
  void loop() override {}

  void show_time(int h, int m);
  void show_countdown(int seconds);

 protected:
  void draw_digits(int d1, int d2, int d3, int d4);
  AddressableLightWrapper *strip_;
};

}  // namespace digit_clock
}  // namespace esphome

using esphome::digit_clock::DigitClock;
