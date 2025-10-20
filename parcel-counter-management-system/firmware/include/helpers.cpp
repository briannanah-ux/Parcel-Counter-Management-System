#ifndef HELPERS_H
#define HELPERS_H

#include <Arduino.h>

struct LockerState {
  bool occupied;
  int userId;
  unsigned long startAt;
  unsigned long allowedMs;
};

String escapeJsonString(const String &s);
String createStatusJson(int lockerIndex, const LockerState &s);


