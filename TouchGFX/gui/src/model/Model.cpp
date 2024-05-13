#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "cmsis_os2.h" // Include for osMessageQueueGet


typedef struct {
    int x;
    int y;
} Position;

extern "C"{
 extern osMessageQueueId_t stickQue1Handle;
 extern osMessageQueueId_t stickQue2Handle;
 extern osMessageQueueId_t BallQueueHandle;
 extern osMessageQueueId_t scoreQueHandle;
}



Model::Model() : modelListener(0)
{

}

void Model::tick()
{

	// Step 2: Call osMessageQueueGet with the queue handle, the message variable, a NULL pointer for message priority (if you don't need it), and a timeout value.
	Position receivedPos;
	osStatus_t status = osMessageQueueGet(BallQueueHandle, &receivedPos, NULL, 0);
	// Check the status to see if a message was successfully received
	if (status == osOK) {

		modelListener->updateBall(receivedPos.x,receivedPos.y);
	}
	Position score;
	status = osMessageQueueGet(scoreQueHandle, &score, NULL, 0);
	// Check the status to see if a message was successfully received
	if (status == osOK) {
		left+=score.x;
		right+=score.y;
		modelListener->updateScore(left,right);
	}

	Position rightB;
	status = osMessageQueueGet(stickQue2Handle, &rightB, NULL, 0);
	// Check the status to see if a message was successfully received
	if (status == osOK) {
		modelListener->updateRightBrick(rightB.x,rightB.y);
	}

	Position leftB;
	status = osMessageQueueGet(stickQue1Handle, &leftB, NULL, 0);
	// Check the status to see if a message was successfully received
	if (status == osOK) {
		modelListener->updateLeftBrick(leftB.x,leftB.y);
	}

}
