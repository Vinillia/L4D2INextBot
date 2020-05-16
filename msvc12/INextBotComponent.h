#pragma once

class INextBot;

class INextBotComponent : INextBotEventResponder
{
public:
	virtual void Reset(void) = 0;
	virtual void pad00() = 0;
	virtual void Upkeep(void) { };
	virtual INextBot *GetBot(void) const { return m_bot; };

private:
	float m_lastUpdateTime;
	float m_curInterval;

	friend class INextBot;

	INextBot *m_bot;
	INextBotComponent *m_nextComponent;
};