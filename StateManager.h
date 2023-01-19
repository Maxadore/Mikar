#ifndef STATEMANAGER_H											// If isn't define, then define it
#define STATEMANAGER_H


typedef std::unique_ptr<State> StateRef;

class StateManager
{
public:

	// Constructors & Destructors
	StateManager() { }											// Handle every state 
	~StateManager() { }

	// Functions 
	void AddState(StateRef newState, bool isReplacing = true);	// Add state on the stack (state running and replacing)
	void RemoveState();											// Manually remove the top state
	void ProcessStateChanges();									// Run at start of each loop in Game.cpp

	StateRef& GetActiveState();

private:
	stack<StateRef> m_states;									// For every states 
	StateRef m_newState;										// Last state to add

	bool m_isRemoving;											// Boolean for removing, adding, replacing a state
	bool m_isAdding, m_isReplacing;
};

#endif // STATEMANAGER_H