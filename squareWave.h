#ifndef squareWave_h
#define squareWave_h


// squareWave: Square waves are very common in the digital world. Things that blink, blink
// square waves. Motor controllers and lamp dimmers run on square waves. So many things
// use this model that it seemed like a good idea to have a base, theoretical square wave
// class to use as a foundation of all these things we'd like to use them for.
//
// This class begins dormant. You need to explicitly call setOnOff() with a value of true
// to start it running.
//
// NOTE : If you never call setOnOff() you will never be hooked up into the idler queue.
// This in itself is not really an issue. BUT, if you inherit this and you need the idle
// loop no matter what, just call hookup() in something like a begin() method or something.
// Then everything will be fine.


#include	"timeObj.h"
#include	"idlers.h"

class squareWave : public idler {
	
	enum waveState { sittinIdle, ridingHi, ridingLow };
	
	public:
				squareWave(void);
				squareWave(float periodMs,float pulseMs, bool blocking=false);
	virtual	~squareWave(void);
				
				bool	running(void);
	virtual	void	setPeriod(float ms);
	virtual	void	setPulse(float ms);
	virtual	void	setPercent(float perc);
	virtual	void	setBlocking(bool onOff);
	virtual	void	setOnOff(bool onOff);
	
	virtual	void	pulseOn(void);
	virtual	void	pulseOff(void);
	virtual	void	idle(void);
	
	protected:
	
	virtual	void	block(void);
	virtual	void	startWave(void);
				void	ourPulseOn(void);
				void	ourPulseOff(void);
				
				waveState	mState;
				bool			mSignal;
				timeObj		mPeriod;
				bool			mPeriodChange;
				float			mNextPeriod;
				timeObj		mPulse;
				bool			mPulseChange;
				float			mNextPulse;
				bool			mBlocking;
};

#endif
				