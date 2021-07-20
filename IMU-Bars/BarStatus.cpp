#include "BarStatus.h"

BarStatus::BarStatus(int16_t x, int16_t y, int16_t w, int16_t h, float minV, float maxV, uint32_t colorBorder, uint32_t colorLine, uint32_t colorLeft, uint32_t colorRight) {
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  _minV = minV;
  _maxV = maxV;
  _colorBorder = colorBorder;
  _colorLine = colorLine;
  _colorLeft = colorLeft;
  _colorRight = colorRight;
  
  _vRange = maxV - minV; // Values in range
  _vPos = 0;
}

BarStatus::BarStatus(int16_t x, int16_t y, int16_t w, int16_t h, float minV, float maxV) {
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  _minV = minV;
  _maxV = maxV;
  _colorBorder = TFT_WHITE;
  _colorLine = TFT_WHITE;
  _colorLeft = TFT_WHITE;
  _colorRight = TFT_BLACK;
  _vRange = maxV - minV; // Values in range
  _vPos = 0;
}

void BarStatus::draw(float v) {
  M5.Lcd.drawFastHLine(_x, _y, _w + 1, _colorBorder);
  M5.Lcd.drawFastHLine(_x, _y + _h + 1, _w + 1, _colorBorder);

  M5.Lcd.drawFastVLine(_x, _y, _h + 1, _colorBorder);
  M5.Lcd.drawFastVLine(_x + _w, _y, _h + 1, _colorBorder);

  _vPos = round(((v - _minV) / _vRange) * _w);

  M5.Lcd.drawFastVLine(_x + _vPos, _y + 1, _h, _colorLine);

  for(int16_t yy = _y + 1; yy < (_y + _h + 1); yy++){
    M5.Lcd.drawFastHLine(_x + 1, yy, _vPos - 1, _colorLeft);
    M5.Lcd.drawFastHLine(_x + _vPos + 1, yy, _w - _vPos - 1, _colorRight);
  }
  
}
