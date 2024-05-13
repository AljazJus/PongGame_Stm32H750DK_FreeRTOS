#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateScore(int left,int right){}
	virtual void updateRightBrick(int x,int y){}
	virtual void updateLeftBrick(int x,int y){}
	virtual void updateBall(int x,int y){}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
