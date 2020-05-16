#pragma once

class IntervalTimer
{
public:
	IntervalTimer(void)
	{
		m_timestamp = -1.0f;
	}

	void Reset(void)
	{
		m_timestamp = Now();
	}

	void Start(void)
	{
		m_timestamp = Now();
	}

	void Invalidate(void)
	{
		m_timestamp = -1.0f;
	}

	bool HasStarted(void) const
	{
		return (m_timestamp > 0.0f);
	}

	float GetElapsedTime(void) const
	{
		return (HasStarted()) ? (Now() - m_timestamp) : 99999.9f;
	}

	bool IsLessThen(float duration) const
	{
		return (Now() - m_timestamp < duration) ? true : false;
	}

	bool IsGreaterThen(float duration) const
	{
		return (Now() - m_timestamp > duration) ? true : false;
	}

private:
	float m_timestamp;
	float Now(void) const;
};

float IntervalTimer::Now(void) const
{
	return g_pInterfaces->pGlobalVars->curtime;
}