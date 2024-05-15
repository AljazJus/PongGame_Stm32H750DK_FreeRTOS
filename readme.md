# Pong Game on STM32H750-DK

This project was created for a class on embedded systems and FreeRTOS. The goal was to develop a simple application using FreeRTOS and the display on the STM32H750-DK. 

The final program is a Pong game with Single-player and Multiplayer modes. In Single-player mode, you play against the computer, controlling the left paddle with a joystick. In Multiplayer mode, you can control both paddles using two separate joysticks. There is also a buzzer that makes a sound when the ball bounces off the walls or when a player scores. [Watch the video](https://youtube.com/shorts/5wfePZIGrSA?feature=share).

The program was created using TouchGFX and STM32CubeIDE. The layout of the elements on the screen was designed with TouchGFX, and the pins and tasks were configured in STM32CubeIDE.

## Setup

You load the program onto the board like any other, using the USB connection and loading it through STM32CubeIDE.

![Connected Pins](https://github.com/AljazJus/PongGame_Stm32H750DK_FreeRTOS/blob/main/pins.png)


### Joysticks

To connect the joysticks, use the pins at the back of the device. For power, use the 3.3V pin and ground pin, then wire them accordingly. The program only uses one axis of movement from the joystick, so to play the game, you only need to connect one axis for each joystick. Connect the pins to the analog ports A2 and A3. A2 will move the left paddle, and A3 will move the right.

### Buzzer

The buzzer is not essential for the program to work. If you wish to connect it, use the ground pin and pin D5 for the signal.

## Program

In the program, there are four main tasks that run. The "myCollisionHandle" task is the primary one, controlling the ball, wall bounces, and score count. It functions as the main game logic. Additionally, there are two tasks that read the values of the joysticks: "readStick1Handle" and "readStick2Handle." The last task, "myBotHandle," controls the computer player when you play against the computer. 

The "readStick2Handle" and "myBotHandle" tasks are activated based on the game mode you select, which is handled in Screen1ViewBase.hpp. All movement of the elements on the screen occurs using queues. The tasks in main.c send the movement data into these queues, which are then read in gui/Model.cpp. Each movable element has its own queue. When the queue is read in Model.cpp, the data is sent to the Screen2Presenter and Screen2View, where it is finally displayed on the screen.

