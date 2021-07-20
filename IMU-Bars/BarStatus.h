#ifndef BarStatus_h
#define BarStatus_h

#include <M5Stack.h>

class BarStatus {
  public:
    BarStatus(int16_t x, int16_t y, int16_t w, int16_t h, float minV, float maxV, uint32_t _colorBorder, uint32_t _colorLine, uint32_t _colorLeft, uint32_t _colorRight);
    BarStatus(int16_t x, int16_t y, int16_t w, int16_t h, float minV, float maxV);
    void draw(float v);

  private:
    int16_t _x;
    int16_t _y;
    int16_t _w;
    int16_t _h;
    float _minV;
    float _maxV;
    uint32_t _colorBorder;
    uint32_t _colorLine;
    uint32_t _colorLeft;
    uint32_t _colorRight;
    
    float _vRange;
    int16_t _vPos;
};

#endif
