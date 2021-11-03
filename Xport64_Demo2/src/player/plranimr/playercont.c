//#include "common.h"
//#include "objectDefs.h"
#include "playerDefs.h"

//audio test
#include "audio.h"

Player playerAvatar;
u8 animFrame = 1; 

#define PLAYER_MAX_SPEED 300.0f
#define PLAYER_MID_SPEED 100.5f
#define PLAYER_MIN_SPEED 60.5f

#define PLAYER_MAX_JUMP_SPEED 300.0f

static void updatePlayerAnim();


void PlayerJump();
void PlayerJumpV2();


extern int GetFPS();


void initPlayer()
{
	u8 tempCounter;

	//SetVector3(&playerAvatar.obj.pos, 3258,-2500,5); //spawn in ship area
	SetVector3(&playerAvatar.obj.pos, 75,-300,5); //spawn in courtyard area
	SetVector3(&playerAvatar.obj.rot, 0,0,0); 
	SetVector3(&playerAvatar.obj.scl, 1,1,1); 
	SetVector3(&playerAvatar.rigidBody.velocity, 0,0,0); 
	SetVector3(&playerAvatar.playerNormal, 0,-1,0); 
	SetVector3(&playerAvatar.rigidBody.centerMass, 0,0,0); 
	playerAvatar.rigidBody.speed = 3.0f;	
	playerAvatar.rigidBody.gravityStrength = 60.0f;
	playerAvatar.isJumping = 0;
	playerAvatar.isFalling = 0;

	SetRigAnimator(&playerAvatar.animRig, &DrawPlayerModel, 0,0);
		
	playerAvatar.sphereCollider.enabled = 1;	
	playerAvatar.sphereCollider.radius = 15.0f;
	SetVector3(&playerAvatar.sphereCollider.center, 		playerAvatar.obj.pos.x,playerAvatar.obj.pos.y,playerAvatar.obj.pos.z + (playerAvatar.sphereCollider.radius));
	SetVector3(&playerAvatar.rigidBody.nextPos, playerAvatar.obj.pos.x,playerAvatar.obj.pos.y,playerAvatar.obj.pos.z); 
	
}

u8 currentFrame = 0;
u8 frameCounter = 0;

/*--------------------------------------------------------------------------*/
/*---------------------------Player Control Functions-----------------------*/
/*--------------------------------------------------------------------------*/

void PlayerMovement();

Vector2 userInput_Player; 
Vector3 playerTempPos;
u8 playerState = 0; //TO DO: temporarily used for "in motion" but will flesh this out with a state machine later

float shootingCooldownTimer = 0.0f;
int lowerArmTimerStart = 0; //after 3 seconds with no input, lower arm
int lowerArmTimer = 0;  //after 3 seconds with no input, lower arm
int lowerArm = 1; //after 1 second with no input, lower arm

u8 shotCycle = 0;
ProjectileObject projectileSpawns[8]; //maximum of 4 projectiles from player at a time
u8 maxShot = 8;
u8 recentShot = 0; //used for debugging
u8 shotCounter = 0; //used for iterating array

void updatePlayer(Dynamic* dp)
{	
	updatePlayerAnim(); //NOTE: Update current animation frame based on player inputs from the previous frame and current frame of animation
	userInput_Player = Player_Input(); //NOTE: calls Player_Input() function in controller.c which returns the X, Y inputs in a Vector2. The Player_Input function will grab values based on the controller settings set by the player
	SetVector3(&playerAvatar.rigidBody.velocity, 0,0,0);  //NOTE: resets the playerAvatar rigidBody velocity to 0,0,0 each frame
		
	if(userInput_Player.y >= 0.1f || userInput_Player.y <= -0.1f || userInput_Player.x >= 0.1f || userInput_Player.x <= -0.1f) 
	{		
		//NOTE: 	userInput_Player.x and .y are determined by player sensitivity settings. 
		//NOTE:  If the inputs do not meet the minimum player sensitivity, the userInput_Player.x and userInput_Player.y will be set to 0.0f in the Player_Input function. 
		playerAvatar.rotation = atan2(userInput_Player.y, userInput_Player.x); //NOTE: get angle with atan2 and x, y inputs
		playerAvatar.rotation = (playerAvatar.rotation * 57.29577); //NOTE: convert angle from radians to degrees 
		playerAvatar.rotation += 90.0f;
		playerAvatar.rotation = playerAvatar.rotation + mainCamera.cameraOrbit;
		if(playerAvatar.rotation >360.0f)
					playerAvatar.rotation = playerAvatar.rotation - 360.0f;				

		//NOTE: Replace later with smoother motion  
			playerAvatar.obj.rot.z = playerAvatar.rotation;
				
		if(abs(userInput_Player.y) + abs(userInput_Player.x) > 60.0f)	
		{
			playerAvatar.rigidBody.speed = lerp(playerAvatar.rigidBody.speed, PLAYER_MAX_SPEED, 0.1f ); //increase speed from current speed to max speed if x+y inputs pass a threshold
			playerState = 1;
		}
		else
		{
			playerAvatar.rigidBody.speed = lerp(playerAvatar.rigidBody.speed, PLAYER_MIN_SPEED, 0.1f ); //increase speed from current speed to max speed if x+y inputs remain below a "max speed" threshold
			playerState = 2;
		}	
		playerAvatar.obj.pos = playerAvatar.rigidBody.currentPos; //if no collision is found, apply to player character as currentPosition

	//NOTE: calculate next movement and store it in playerAvatar.rigidBody.nextPos
		PlayerMovement(); 
		
		VectorAdd(&playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.velocity );	
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;
		
	//NOTE: calculate the updated collider position based off of playerAvatar.rigidBody.nextPos but offset on the Z-axis by the radius of the sphere
		SetVector3(&playerAvatar.sphereCollider.center, 	playerAvatar.rigidBody.nextPos.x,playerAvatar.rigidBody.nextPos.y,playerAvatar.rigidBody.nextPos.z + (playerAvatar.sphereCollider.radius));

		
	//NOTE: set playerAvatar.rigidBody.currentPos as playerAvatar.rigidBody.nextPos for updating player position and collision checks in the next frame
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;
		
	//NOTE: after horizontal movement is done, check for vertical movement (gravity) 
	//and collision, then update playerAvatar.rigidBody.currentPos.z
	// - RAY/LINE COLLISION from center of player to a tri. 
	// - The ray/line will go straight down on the z axis only

		playerAvatar.playerNormal = playerAvatar.rigidBody.velocity;
		VectorNormalize(&playerAvatar.playerNormal);	

	}
	

	else
	{	
		playerAvatar.obj.pos = playerAvatar.rigidBody.currentPos; //if no collision is found, apply to player character as currentPosition

		playerAvatar.rigidBody.speed = lerp(playerAvatar.rigidBody.speed, 0.0f, 0.4f ); //slowd own to a stop
				
		VectorAdd(&playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.velocity );				
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;

		SetVector3(&playerAvatar.sphereCollider.center, 	playerAvatar.rigidBody.nextPos.x,playerAvatar.rigidBody.nextPos.y,playerAvatar.rigidBody.nextPos.z + (playerAvatar.sphereCollider.radius));
			
		if(playerAvatar.rigidBody.speed < PLAYER_MIN_SPEED)
			playerState = 0;			

		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;

	}
	

	
}

void PlayerMovement()
{
	SetVector3(&playerAvatar.rigidBody.velocity, userInput_Player.x, userInput_Player.y, playerAvatar.rigidBody.velocity.z);	//begins velocity calculation based on userInput_player set in updatePlayer function
	playerAvatar.rigidBody.velocity = RotateAround(playerAvatar.rigidBody.velocity, playerAvatar.rigidBody.centerMass, mainCamera.cameraOrbit);
	
	VectorNormalize(&playerAvatar.rigidBody.velocity);
	VectorScale(&playerAvatar.rigidBody.velocity, (playerAvatar.rigidBody.speed * (float)GetDeltaTime()));
	
}

float jumpingForce = 60.0f;
float resetJumpingForce = 60.0f;
float jumpingForceMultiplyer = 10.0f;
float resetJumpingMultiplyer = 10.0f;
u8 canJump;


/*END------------------------Player Control Functions-----------------------*/

/*--------------------------------------------------------------------------*/
/*------------------------Player Rendering and Animating--------------------*/
/*--------------------------------------------------------------------------*/

void DrawPlayerModel()
{	
//NOTE ---- Coming in a future tutorial 
}

int playerAnimationTimer = 0;
	

static void updatePlayerAnim()
{

	int tempAnimationTimer = 0;
	int frameDifference = 0; //in the event of extreme slowdown, check how much time has elapsed

	tempAnimationTimer = GetFPS_2(); //animation playback at 30 fps gives the best, most consistent performance
	
	if (tempAnimationTimer != playerAnimationTimer)
	{
		frameDifference = tempAnimationTimer-playerAnimationTimer;
	
		playerAnimationTimer = tempAnimationTimer;
        
        if(playerAvatar.rigidBody.speed >= 50.0f)        
            PlaySfx_Footstep(6);
            
		
	}
	
}

/*END---------------------Player Rendering and Animating--------------------*/



