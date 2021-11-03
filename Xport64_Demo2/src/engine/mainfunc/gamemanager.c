#include "gamemanager.h"

//audio test
//#include "audio.h"

/*--------------------------------------------------------------------------*/
/*--------------------------Initiate "gamemain.c"---------------------------*/
/*--------------------------------------------------------------------------*/
extern void gametitle(int pendingGfx);
extern void gamemain(int pendingGfx);
extern void UpdateCameraPosition(Dynamic* dp);

u8 initiate = 0;
float debugTimer;
//lvlGameMain
GameMode gameMode_Main;
WorldTrigger locationInWorld;

int fpsTimer = 1;
int renderTimer = 0;

void InitMode_Main( void ) //formerly InitGame
{	
	initPlayer();
	initMainCamera();
	InitDebug();
	debugTimer = GetSeconds();
	/*
	 DrawMap2Init();
	 initPlayer();

    View = 75; //Starting Camera Angle

    StartTime = osGetTime();
    NowTime = osGetTime();
    NowPauseTime = 0;
    Pause = 0;
    TraceIdx = 0;
    SaveIdx = 0;
    SaveOfsIdx = 0;
    UpTempo = 0;
	*/	
	initiate = 1; //reset only when loading a new level
}

void
gameManagerGFX(unsigned int pendingGfx)
{

    // int tempAnimationTimer = 0;
	// int frameDifference = 0; //in the event of extreme slowdown, check how much time has elapsed
    /* Provide the display process if there is only one task which is processing or waiting for the process. */
    if(pendingGfx < 5)
	{
		CalcSysTime();
			
		//if(initiate == 0)
			//InitGame(); //run this only at the start of each level

	
	// tempAnimationTimer = GetFPS_30(); //animation playback at 30 fps gives the best, most consistent performance
	
	// if (tempAnimationTimer != renderTimer)
	// {
		// frameDifference = tempAnimationTimer-renderTimer;
	
		// renderTimer = tempAnimationTimer;
    
       // // MakeGameDL();	

    // }
		
        MakeGameDL();	
		//Create trigger data 
		nuContDataGetExAll(&ContTriger[0]);		
			UpdateGame();
		
    }
}

void MakeGameDL(void)
{

/*--------------------------Setup---------------------------*/	

    Dynamic* dynamicp;
	Dynamic* dynamicDebugp;

	
	
	// int animationTimer = 0;
// int currentFrameTime = 1;

	
	/*Separate clear and build lists
	
	//possibly useful if display lists begin getting too long
	
	
	glistp = &gfx_clear_glist[gfx_gtask_no][0];
	gfxRCPInit();
	gfxClearCfb(); //clear frame and z buffer
	
	assert((glistp - gfx_clear_glist[gfx_gtask_no]) < GFX_CLEAR_GLIST_LEN);
	
	gDPFullSync(glistp++);
	gSPEndDisplayList(glistp++);
	
    nuGfxTaskStart(&gfx_clear_glist[gfx_gtask_no][0],
	 (s32)(glistp - gfx_clear_glist[gfx_gtask_no]) * sizeof (Gfx),
	 NU_GFX_UCODE_F3DEX , NU_SC_NOSWAPBUFFER);
	*/
	
	
	
	
	
	
	
    dynamicp = &gfx_dynamic[gfx_gtask_no]; //specify dynamic buffer
    glistp = &gfx_glist[gfx_gtask_no][0]; //specify display list (dl) buffer
		
    gfxRCPInit();
    gfxClearCfb(); //clear frame and z buffer
	
	    // Setting the view-matrix 
    SetGameViewMtx( dynamicp );	
	

/*--------------------------END Setup---------------------------*/	

	

/*------------DRAW Game UI, Levels, Player, NPC, etc------------*/		

	//DrawPlayerModel(dynamicp);
	//	gDPPipeSync(glistp++);

	//Level01(dynamicp);	
	//Level01_Enemies_DL(dynamicp);
	//Level01_Objects(dynamicp);
			//UI_Target_Render();
			//lvls[Index]->levelInit();
			
			
			scenes[0]->sceneInit();
			scenes[0]->sceneRender();
			gDPPipeSync(glistp++);
			//DrawPlayerModel(dynamicp);
            render_lvl00_transparent();
			gDPPipeSync(glistp++);

			
	//NOTE: Press the L trigger button to toggle debug mode on and off. (FPS will appear by default)
	if(ContTriger[0].trigger & L_TRIG)
	{
		ToggleDebugMode();
	}
	
		
	/*TO DO NOTE: Hide until region culling is functional------
		Lvl01_Env02(dynamicp);	
	/*END NOTE-------------------------------------------*/

		gDPPipeSync(glistp++);
/*----------END DRAW Game UI, Levels, Player, NPC, etc----------*/	


	FrameCount();

	//dynamicp->posLightValues = getPosLightValues();
	
/*-----------Wrap up display lists / swap frame buffers---------*/	
    gDPFullSync(glistp++); 
    gSPEndDisplayList(glistp++);

   
    assert((glistp - gfx_glist[gfx_gtask_no]) < GFX_GLIST_LEN);
	//assert((glistpDebugp - gfx_glistDebug[gfx_debug_gtask_no]) < GFX_GLIST_LEN);
    /* Activate the RSP task and switch display buffers. */
    nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
		   (s32)(glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
		   NU_GFX_UCODE_F3DEX2_NON  , NU_SC_SWAPBUFFER);
 
		   
    /* Indicate next graphic task number  */
    gfx_gtask_no++;
    gfx_gtask_no %= GFX_GTASK_NUM;
	
	/* Wait for the task to end */
    nuGfxTaskAllEndWait();
	

/*---------END Wrap up display lists / swap frame buffers-------*/	

}


Vector3 tempVector; // for testing local audio loop
void UpdateGame()
{
	Dynamic* dynamicp;
                // PAUSE/UN-PAUSE 
            if(ContTriger[0].trigger & START_BUTTON)
            {	
                if(Pause == 0)
                    Pause = 1;
                    
                else if(Pause == 1)
                    Pause = 0;
                //trigger for pause 
            }

            if(ContTriger[0].trigger & U_CBUTTONS)
            {
                //trigger for debug
            }	
            
            if( Pause == 0 )
            {
                UpdateCameraPosition(dynamicp); 	
                updatePlayer(dynamicp);	
                update_lvl00_DemoScene();

            }
	

	

	//audio
	//PlayAmbientLoop(8, 71);
	//play water at waterfall
	tempVector.x = -95; tempVector.y = -236; tempVector.z = 0;
	//PlayAmbientLoopLocal(9, 1, 91, 3000, tempVector);
	
	//if(ContTriger[0].trigger & B_BUTTON)
	//	PlayAmbientLoopMore(3);
}