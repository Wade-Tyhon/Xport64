#include "engineTools.h"

float lerp(float val_1, float val_2, float time)
{
    return (1-time)*val_1 + time*val_2;
}


/*--------------------------------------------------------------------------*/
/*-----------------------------FPS and DeltaTime----------------------------*/
/*--------------------------------------------------------------------------*/

s32 cpuCount = 0;
u32 microsec = 0;
int sec = 0;
int FPS_2 = 0;
int FPS_6 = 0;
int FPS_12 = 0;
int FPS_24 = 0;
int FPS_20 = 0;
int FPS_30 = 0;
int FPS_40 = 0;
int FPS_60 = 0;

int lastSec = 0;
int min = 0;
int frames = 0;
int lastFPS = 0;

f32	PreviousTime;		/* The time in previous frame time */
f32	DeltaTime;		/* The time passed since last frame time */
float inverseDeltaTime;


OSTime	StartTime;		/* Start time of the game */
OSTime	NowTime;		/* The current time */

OSTime	NowPauseTime;	/* For keeping time at the pause */
OSTime	LapTime;		/* Elapsed time */

#define START_TIME 100

void FrameCount()
{
    frames +=1;
}

void FPSCalc()
{
    lastFPS = frames;
    frames = 0;
}

int GetFPS()
{
    return lastFPS;
}

void CalcSysTime()
{	
    // Update time
    NowTime = osGetTime();
    NowPauseTime = NowTime - StartTime;
    LapTime = START_TIME + OS_CYCLES_TO_USEC(NowTime - StartTime);
    LapTime *= 0.001;
    sec = (LapTime*0.001)-(min*60);
    FPS_2 = ((LapTime*0.001)-(min*60))*2;  //NOTE: this is for animation and will update 6 times per second
	FPS_6 = ((LapTime*0.001)-(min*60))*6;  //NOTE: this is for animation and will update 6 times per second
	FPS_12 = ((LapTime*0.001)-(min*60))*12; //NOTE: this is for animation and will update 12 times per second
	FPS_20 = ((LapTime*0.001)-(min*60))*20; //NOTE: this is for animation and will update 20 times per second
	FPS_24 = ((LapTime*0.001)-(min*60))*24; //NOTE: this is for animation and will update 24 times per second
	FPS_30 = ((LapTime*0.001)-(min*60))*30; //NOTE: this is for animation and will update 30 times per second
	FPS_40 = ((LapTime*0.001)-(min*60))*40; //NOTE: this is for animation and will update 40 times per second
	FPS_60 = ((LapTime*0.001)-(min*60))*60; //NOTE: this is for animation and will update 60 times per second

    //-(min*60)

    if(sec > 59)
        min += 1;

    if(lastSec != sec)
    {
        lastSec = sec;
        FPSCalc();
    }

    //DeltaTime = (osGetTime() - PreviousTime)/45752803.40349305;
	DeltaTime = (osGetTime() - PreviousTime);
	
	if(DeltaTime >= 0.00)
	{
		DeltaTime = DeltaTime/45752803.40349305;
		inverseDeltaTime = 1/(DeltaTime);
	}

    PreviousTime = osGetTime();
}

void initTimer()
{
    StartTime = osGetTime();
    NowTime = osGetTime();
}

int GetSeconds()
{
    return sec;
}

int GetFPS_2() // animation, physics check, or event occuring at 6 fps
{
	return FPS_2;
}


int GetFPS_6() // animation, physics check, or event occuring at 6 fps
{
	return FPS_6;
}

int GetFPS_12() // animation, physics check, or event occuring at  12 fps
{
	return FPS_12;
}

int GetFPS_20() // animation, physics check, or event occuring at 24 fps
{
	return FPS_20;
}

int GetFPS_24() // animation, physics check, or event occuring at 24 fps
{
	return FPS_24;
}

int GetFPS_30() // animation, physics check, or event occuring at 24 fps
{
	return FPS_30;
}

int GetFPS_40() // animation, physics check, or event occuring at 24 fps
{
	return FPS_40;
}

int GetFPS_60() // animation, physics check, or event occuring at 24 fps
{
	return FPS_60;
}



f32 GetDeltaTime()
{
    return DeltaTime; // return the amount of time since hte previous frame
}

float getInvDeltaTime(void)
{
    return inverseDeltaTime;
}

OSTime getLapTime(void)
{
    return LapTime;
}

OSTime GetNowTime()
{
    //return OS_CYCLES_TO_USEC(NowTime) /= 1000;
}

/*
int randomRange(int low, int high)
{
	int randomInt = guRandom();
	
	
	
	//if(randomInt <= high && randomInt >= low)
		//return randomInt;
	
	if(randomInt > high)
}*/



/*END--------------------------FPS and DeltaTime----------------------------*/

