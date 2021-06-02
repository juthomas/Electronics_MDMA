#include "../../inc/mdma.h"

void testText()
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_setCursor(0, 0);
    ili9341_println("Hello World!", ILI9341_WHITE, 1, 0);
    ili9341_println("0xDEADBEEF", ILI9341_RED, 3, 0);
    ili9341_println("Groop", ILI9341_GREEN, 5, 0);
    ili9341_println("I implore thee,", ILI9341_GREEN, 2, 0);
    ili9341_println("my foonting turlingdromes.", ILI9341_GREEN, 1, 0);
    ili9341_println("And hooptiously drangle me", ILI9341_GREEN, 1, 0);
    ili9341_println("with crinkly bindlewurdles,", ILI9341_GREEN, 1, 0);
    ili9341_println("Or I will rend thee", ILI9341_GREEN, 1, 0);
    ili9341_println("in the gobberwarts", ILI9341_GREEN, 1, 0);
    ili9341_println("with my blurglecruncheon,", ILI9341_GREEN, 1, 0);
    ili9341_println("see if I don't!", ILI9341_GREEN, 1, 0);
}

void testLines(uint16_t color)
{
    int x1, y1, x2, y2,
        w = width,
        h = height;

    ili9341_fillScreen(ILI9341_BLACK);

    x1 = y1 = 0;
    y2 = h - 1;
    for (x2 = 0; x2 < w; x2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);
    x2 = w - 1;
    for (y2 = 0; y2 < h; y2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);
    ili9341_fillScreen(ILI9341_BLACK);

    x1 = w - 1;
    y1 = 0;
    y2 = h - 1;
    for (x2 = 0; x2 < w; x2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);
    x2 = 0;
    for (y2 = 0; y2 < h; y2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);

    ili9341_fillScreen(ILI9341_BLACK);

    x1 = 0;
    y1 = h - 1;
    y2 = 0;
    for (x2 = 0; x2 < w; x2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);
    x2 = w - 1;
    for (y2 = 0; y2 < h; y2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);

    ili9341_fillScreen(ILI9341_BLACK);

    x1 = w - 1;
    y1 = h - 1;
    y2 = 0;
    for (x2 = 0; x2 < w; x2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);
    x2 = 0;
    for (y2 = 0; y2 < h; y2 += 6)
        ili9341_drawLine(x1, y1, x2, y2, color, 0);
}

void testRects(uint16_t color)
{

    int n, i, i2,
        cx = width / 2,
        cy = height / 2;

    ili9341_fillScreen(ILI9341_BLACK);
    n = MIN(width, height);
    for (i = 2; i < n; i += 6)
    {
        i2 = i / 2;
        ili9341_drawRect(cx - i2, cy - i2, i, i, color);
    }
}

void testFilledRects(uint16_t color1, uint16_t color2)
{
    int n, i, i2,
        cx = width / 2 - 1,
        cy = height / 2 - 1;

    ili9341_fillScreen(ILI9341_BLACK);
    n = MIN(width, height);
    for (i = n; i > 0; i -= 6)
    {
        i2 = i / 2;

        ili9341_drawfillRect(cx - i2, cy - i2, i, i, color1, 0);
        // Outlines are not included in tiMINg results
        ili9341_drawRect(cx - i2, cy - i2, i, i, color2);
    }
}

void testFilledCircles(uint8_t radius, uint16_t color)
{

    int x, y, w = width, h = height, r2 = radius * 2;

    ili9341_fillScreen(ILI9341_BLACK);
    for (x = radius; x < w; x += r2)
    {
        for (y = radius; y < h; y += r2)
        {
            ili9341_drawfillCircle(x, y, radius, color, 0);
        }
    }
}

void testCircles(uint8_t radius, uint16_t color)
{

    int x, y, r2 = radius * 2,
              w = width + radius,
              h = height + radius;

    // Screen is not cleared for this one -- this is
    // intentional and does not affect the reported time.
    for (x = 0; x < w; x += r2)
    {
        for (y = 0; y < h; y += r2)
        {
            ili9341_drawCircle(x, y, radius, color);
        }
    }
}

void testTriangles()
{

    int n, i, cx = width / 2 - 1,
              cy = height / 2 - 1;

    ili9341_fillScreen(ILI9341_BLACK);
    n = MIN(cx, cy);
    for (i = 0; i < n; i += 5)
    {
        ili9341_drawTriangle(
            cx, cy - i,     // peak
            cx - i, cy + i, // bottom left
            cx + i, cy + i, // bottom right
            color565(i, i, i));
    }
}

void graphic_test()
{
    for (;;)
    {
        for (uint8_t rotation = 0; rotation < 4; rotation++)
        {
            ili9341_setRotation(rotation);
            testText();
        }
        testTriangles();
        testCircles(10, ILI9341_MAGENTA);
        testFilledCircles(10, ILI9341_MAGENTA);
        testFilledRects(ILI9341_YELLOW, ILI9341_MAGENTA);
        testRects(ILI9341_GREEN);
        testLines(ILI9341_CYAN);
    }
}