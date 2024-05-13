#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateRightScore(int num);
	virtual void updateLeftScore(int num);

	virtual void updateRightBrick(int x,int y);
	virtual void updateLeftBrick(int x,int y);
	virtual void updateBall(int x,int y);

protected:
};

#endif // SCREEN2VIEW_HPP
