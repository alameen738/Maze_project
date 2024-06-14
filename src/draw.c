#include "../headers/header.h"

/**
 * drawRect - Draws a rectangle on the screen.
 *
 * @x: x coordinate of the top-left corner of the rectangle
 * @y: y coordinate of the top-left corner of the rectangle
 * @width: width of the rectangle
 * @height: height of the rectangle
 * @color: color of the rectangle
 */

void drawRect(int x, int y, int width, int height, color_t color)
{
	int i, j;

	for (i = x; i <= (x + width); i++)
		for (j = y; j <= (y + height); j++)
			drawPixel(i, j, color);
}

/**
 * drawLine - Draws a line on the screen using Bresenham's algorithm.
 *
 * x0: x coordinate of the starting point of the line
 * @y0: y coordinate of the starting point of the line
 * @x1: x coordinate of the ending point of the line
 * @y1: coordinate of the ending point of the line
 * @color: color of the line
*/

void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	float xIncrement, yIncrement, currentX, currentY;
	int i, longestSideLength, deltaX,  deltaY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);

	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;

	currentX = x0;
	currentY = y0;

	for (i = 0; i < longestSideLength; i++)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
	}
}
