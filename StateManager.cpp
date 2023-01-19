#include "Framework.h"

void StateManager::AddState(StateRef newState, bool isReplacing)
{
	this->m_isAdding = true;
	this->m_isReplacing = isReplacing;
		  
	this->m_newState = move(newState);
}

void StateManager::RemoveState()
{
	this->m_isRemoving = true;
}

void StateManager::ProcessStateChanges()
{
	if (this->m_isRemoving && !this->m_states.empty())		 // Check if the state is removing or empty 
	{
		this->m_states.pop();								 // If not it's appear

		if (!this->m_states.empty())						 // Check again if it's not empty
		{
			this->m_states.top()->Resume();					 // If not, it's resume
		}

		this->m_isRemoving = false;
	}

	if (this->m_isAdding)
	{
		if (!this->m_states.empty())						 // If it's not empty, it's replacing
		{
			if (this->m_isReplacing)
			{
				this->m_states.pop();
			}
			else
			{
				this->m_states.top()->Pause();
			}
		}

		this->m_states.push(std::move(this->m_newState));	// Move this state on a new state
		this->m_states.top()->Init();						// Init the state
		this->m_isAdding = false;
	}
}

StateRef& StateManager::GetActiveState()
{
	return this->m_states.top();
}

