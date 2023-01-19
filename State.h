#ifndef STATE_H								
#define STATE_H

class State
{
public:
	virtual void Init() = 0;				// Initialize the state 

	virtual void HandleInput() = 0;			// Handle input on state 
	virtual void Update(float dt) = 0;		// Update users input 
	virtual void Draw(float dt) = 0;		// Draw application with time difference beetween frames

	virtual void Pause() { }				// Pause state - Put your game on standby
	virtual void Resume() { }				// Resume your game
};

#endif // STATE_H