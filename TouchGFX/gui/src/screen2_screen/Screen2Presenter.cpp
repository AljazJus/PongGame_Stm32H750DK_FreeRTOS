#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{
}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::updateScore(int left,int right)
{
	view.updateRightScore(right);
	view.updateLeftScore(left);
}

void Screen2Presenter::updateRightBrick(int x,int y)
{
	view.updateRightBrick(x,y);
}


void Screen2Presenter::updateLeftBrick(int x,int y)
{
	view.updateLeftBrick(x,y);
}

void Screen2Presenter::updateBall(int x,int y)
{
	view.updateBall(x,y);
}
