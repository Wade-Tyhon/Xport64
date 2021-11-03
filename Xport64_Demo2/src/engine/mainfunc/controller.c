#include "controllerDefs.h"

CONT_OPTIONS contPrefs = CONT_STICK;



void PlayerMovement_Stick();
void PlayerMovement_DPad();
void PlayerMovement_CButtons();

void CameraControl_Stick();
void CameraControl_CButtons();

Vector2 input_Stick = {0,0};
Vector2 input_DPad = {0,0};
Vector2 input_CButtons = {0,0};

Vector2 player_Input = {0,0}; //D-pad, Analog Stick, C-Buttons for player and camera control
Vector3 player_FaceButtons = {0,0,0}; //A, B and Down D-pad or Down C-button for jump/action buttons based on player settings. D-pad and C-button settings will be used based on control stick
Vector3 player_Triggers = {0,0,0}; //L, R, Z for shoot / lock on trigger
//float cameraOrbit = 0.0f;

#define CONT_SENSE_MAX 6.0f
#define CONT_SENSE_MIN 20.0f
float move_sensitivity = 12.0f;
float cam_sensitivity = 12.0f;

/*--------------------------------------------------------------------------*/
/*---------------------------Player Control Functions-----------------------*/
/*--------------------------------------------------------------------------*/





Vector2 Player_Input()
{
	switch(contPrefs)
     {
		case 0:
			PlayerMovement_Stick(); 
        break;
		
		case 1:
			PlayerMovement_DPad(); 
        break;
		
		case 2:
			PlayerMovement_CButtons(); 
        break;
	}
	
	return player_Input;
}

void PlayerMovement_Stick()
{
	float tempUserInput_X = 0;
	float tempUserInput_Y = 0;
	
	if(nuContData[0].stick_x >= move_sensitivity || nuContData[0].stick_x <= -move_sensitivity)
		tempUserInput_X = nuContData[0].stick_x;
		
	if(nuContData[0].stick_y >= move_sensitivity || nuContData[0].stick_y <= -move_sensitivity)
		tempUserInput_Y = nuContData[0].stick_y;
		
	player_Input.x = tempUserInput_X;
	player_Input.y = tempUserInput_Y;	
	
}

void PlayerMovement_DPad()
{

}

void PlayerMovement_CButtons()
{

}



/*END------------------------Player Control Functions-----------------------*/


/*--------------------------------------------------------------------------*/
/*---------------------------Camera Control Functions-----------------------*/
/*--------------------------------------------------------------------------*/

	//float tempCamInput_X = 0;
	//float tempCamInput_Y = 0;
	//float tempCamInputOrbit = 0;
	
	float tempUserInput_X = 0;
	float tempUserInput_Y = 0;
	float tempCameraOrbit = 0;


Vector2 Camera_Input()
{
	switch(contPrefs)
     {
		case 0:
			CameraControl_CButtons(); 
        break;
		
		case 1:
			CameraControl_Stick(); 
        break;
		
		case 2:
			CameraControl_Stick(); 
        break;
	}
}




void CameraControl_Stick()
{
	float tempUserInput_X = 0;
	float tempUserInput_Y = 0;
	float tempCameraOrbit = 0;
	
	//tempCameraOrbit = 1;
	
	if(nuContData[0].stick_x >= cam_sensitivity || nuContData[0].stick_x <= -cam_sensitivity)
		tempUserInput_X = nuContData[0].stick_x;
		
	if(nuContData[0].stick_y >= cam_sensitivity || nuContData[0].stick_y <= -cam_sensitivity)
		tempUserInput_Y = nuContData[0].stick_y;	
		
	if(tempUserInput_X >= 12.0f || tempUserInput_X <= -12.0f)
		{			
			tempCameraOrbit += tempUserInput_X*.04f;
			if(tempCameraOrbit > 360.0f)
				tempCameraOrbit = 0.0f;
			if(tempCameraOrbit < 0.0f)
				tempCameraOrbit = 360.0f;			
		}		
}

void CameraControl_CButtons()
{

/*
		//NOTE: Get L and R C button input for horizontal/orbital movement around player character			
			if(ContTriger[0].button & R_CBUTTONS)
				tempUserInput_X = lerp(tempUserInput_X, 3.0f, 0.01f);		
		//NOTE: Only allow user to press one of the L or R buttons	
			else if(ContTriger[0].button & L_CBUTTONS)		
				tempUserInput_X = lerp(tempUserInput_X, -3.0f, 0.01f);
		//NOTE: When user depresses the C button, quickly lerp down camera movement
			else if(tempUserInput_X >= 0.2f || tempUserInput_X <= -0.2f )
				tempUserInput_X = lerp(tempUserInput_X, 0.0f, 0.2f);		
		//NOTE: Once userInput_Y movement speed is below |.2f|, set it to 0.0f to avoid drift
			else
				tempUserInput_X = 0.0f;
				
		//NOTE: Apply tempUserInput_X to tempCamera Orbit and keep it in the 0-360 degree range			
			tempCameraOrbit += tempUserInput_X;					
			if(tempCameraOrbit >= 360.0f)
				tempCameraOrbit = 0.0f;
			if(tempCameraOrbit < 0.0f)
				tempCameraOrbit = 360.0f;		
				*/
}


/*END------------------------Camera Control Functions-----------------------*/
