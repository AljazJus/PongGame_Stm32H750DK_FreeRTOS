#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Unicode.hpp> // Include for Unicode::snprintf

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}


void Screen2View::updateRightScore(int num)
{
	Unicode::snprintf(rughtScoreBuffer, 3, "%u", num);
	rightScore.invalidate();

}

void Screen2View::updateLeftScore(int num)
{
	Unicode::snprintf(leftScoreBuffer, 3, "%u", num);
	leftScore.invalidate();

}

void Screen2View::updateRightBrick(int x,int y)
{
	// Move the image to a new position
	rightBrick.invalidate();
	rightBrick.setXY(x, y);
	// Redraw the image at the new position
	rightBrick.invalidate();

}
void Screen2View::updateLeftBrick(int x,int y)
{
	// Move the image to a new position
	leftBrick.invalidate();
	leftBrick.setXY(x, y);
	// Redraw the image at the new position
	leftBrick.invalidate();

}

void Screen2View::updateBall(int x,int y)
{
	// Move the image to a new position
	circle1.invalidate();
	circle1.setPosition(x, y, 20, 20);	// Redraw the image at the new position
	circle1.invalidate();

}

