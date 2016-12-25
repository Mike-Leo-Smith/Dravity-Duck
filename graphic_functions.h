#ifndef _GRAPHIC_FUNCTIONS
#define _GRAPHIC_FUNCTIONS

#define LCD_WIDTH_PX 384
#define LCD_HEIGHT_PX 216

void *GetVRAMAdress(void);
void FillVRAM(short color);
void Fade();
void FillScreen(unsigned short color);
void HorizontalLine(int y, int x1, int y2, short color);
void Rectangle(int x, int y, int w, int h, short color);
void FilledCircle(int x, int y, int radius, short color);
void CopySpriteMasked(char *bitmap, short *palette, int x, int y, int width, int height, short mask);
void CopySpriteClippingMasked(char *bitmap, short *palette, int x, int y, int width, int height, short mask);
void CopySpriteClippingMaskedAlpha(char *bitmap, short *palette, int x, int y, int width, int height, short mask, char alpha);
void Shadow(char *bitmap, short *palette, int x, int y, int width, int height, short mask);

#endif //_GRAPHIC_FUNCTIONS
