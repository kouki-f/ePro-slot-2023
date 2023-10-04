#pragma once

class Photointerrupter{
private:
  int m_photoPin;
public:
  Photointerrupter(int photoPin);
  bool readPhoto();
};