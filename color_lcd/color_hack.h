/* 
Modified to workaround defected module.
*/
#define ST77XX_BLACK 0x0000
#define ST77XX_WHITE 0xFFFF
#define ST77XX_BLUE 0xF800
#define ST77XX_GREEN 0x07E0
#define ST77XX_RED 0x001F
#define ST77XX_YELLOW 0x07FF
#define ST77XX_MAGENTA 0xF81F
#define ST77XX_CYAN 0xFFE0
#define ST77XX_ORANGE 0x053F

uint16_t color565_mod(uint8_t blue, uint8_t green, uint8_t red) {
  return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
}

uint16_t color565_mod_hex(uint32_t hex) {
  return color565_mod((hex >> 16) & 0x0000ff, (hex >> 8) & 0x0000ff, hex & 0x0000ff);
}
