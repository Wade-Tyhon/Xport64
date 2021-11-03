#include "common.h"
//#include <math.h>
#include "transformDefs.h" //header file for function declarations


/*--------------------------------------------------------------------------*/
/*-----------------------------GameObject Functions-------------------------*/
/*--------------------------------------------------------------------------*/

void SetAnimator(Animaton *setAnim, void (*setAnimFunc)(u8), u8 defaultAnimID, u8 defaultAnimFrame)
{	//NOTE: For frame by frame animation, morphing, etc 
	setAnim->animate = setAnimFunc;
	setAnim->animID = defaultAnimID;
	setAnim->animFrame = defaultAnimFrame;
}

void SetRigAnimator(AnimRig *setAnimRig, void (*setAnimFunc)(), u8 defaultAnimID, u8 defaultAnimFrame)
{	//NOTE: For rigged animations such as player, npcs, enemies, etc
	setAnimRig->controller = setAnimFunc;
	setAnimRig->animID = defaultAnimID;
	setAnimRig->animFrame = defaultAnimFrame;
}

/*END--------------------------GameObject Functions-------------------------*/


/*--------------------------------------------------------------------------*/
/*-------------------------------Vector Functions---------------------------*/
/*--------------------------------------------------------------------------*/

void SetVector3(Vector3 *setVector, float x, float y, float z)
{
	setVector->x = x;
	setVector->y = y;
	setVector->z = z;
}

void SetVector2(Vector2 *setVector, float x, float y)
{
	setVector->x = x;
	setVector->y = y;
}

float vectorDot(Vector3 vectorA, Vector3 vectorB)
{
	float sum;
	
	sum += vectorA.x * vectorB.x;
	sum += vectorA.y * vectorB.y;
	sum += vectorA.z * vectorB.z;
	
	return sum;
}

Vector3 vectorCross(Vector3 vectorA, Vector3 vectorB)
{
	Vector3 sum;
	
	sum.x = (vectorA.y * vectorB.z) - (vectorA.z * vectorB.y);
		sum.y = (vectorA.z * vectorB.x) - (vectorA.x * vectorB.z);
			sum.z = (vectorA.x * vectorB.y) - (vectorA.y * vectorB.x);
		
	return sum;
}

float vectorScalarTriple(Vector3 vectorA, Vector3 vectorB, Vector3 vectorC)
{
	float sum;
	
	sum = vectorDot(vectorA, vectorCross(vectorB,vectorC));
	
	return sum;
}

u8 vectorCompare(Vector3 vectorA, Vector3 vectorB)
{
	if( ((vectorA.x - vectorB.x) + (vectorA.y - vectorB.y) + (vectorA.z - vectorB.z)) == 0)
		return 1;
		
	else
		return 0;
}

Vector3 vectorAdd(Vector3 vectorA, Vector3 vectorB)
{
	Vector3 newVector = {(vectorA.x + vectorB.x),(vectorA.y + vectorB.y),(vectorA.z + vectorB.z)};	
	return newVector;	
}

Vector3 vectorSubtract(Vector3 vectorA, Vector3 vectorB)
{
	Vector3 newVector = {(vectorA.x - vectorB.x),(vectorA.y - vectorB.y),(vectorA.z - vectorB.z)};	
	return newVector;	
}

Vector3 vectorScale(Vector3 vectorA, float scaler)
{

	Vector3 newVector = {(vectorA.x * scaler),(vectorA.y * scaler),(vectorA.z * scaler)};
	
	return newVector;	
}

float tempFloat = 0;
 void VectorNormalize(Vector3 *vector)
{
	float length = sqrtf(vector->x*vector->x + vector->y*vector->y + vector->z*vector->z);

	if (length > 0.0f) 
	{
		//vector->x /= length;
		//vector->y /= length;
		//vector->z /= length;
		tempFloat = 1.0f/length;
		vector->x *= tempFloat;
		vector->y *= tempFloat;
		vector->z *= tempFloat;
	}
}


void VectorAdd(Vector3 *vectorSum, Vector3 vectorA, Vector3 vectorB)
{
	vectorSum->x = vectorA.x + vectorB.x;
	vectorSum->y = vectorA.y + vectorB.y;
	vectorSum->z = vectorA.z + vectorB.z;

}

void VectorScale(Vector3 *vectorToScale,float scaler)
{
	vectorToScale->x = vectorToScale->x * scaler;
	vectorToScale->y = vectorToScale->y * scaler;
	vectorToScale->z = vectorToScale->z * scaler;
}

/*END----------------------------Vector Functions---------------------------*/

 
 

/*--------------------------------------------------------------------------*/
/*------------------------------Physics Functions---------------------------*/
/*--------------------------------------------------------------------------*/

Vector3 RotateAround(Vector3 basePosition, Vector3 centerPoint, double angleInDegrees)
{
	//double angleInRadians = ((angleInDegrees) * 3.14f/180.0f);
	double angleInRadians = ((angleInDegrees) * 0.01744f);
    double cosTheta = cosf(angleInRadians);
    double sinTheta = sinf(angleInRadians);
		
	Vector3 calculatePosition;
	
	calculatePosition.x = (cosTheta * (basePosition.x - centerPoint.x) - sinTheta * (basePosition.y - centerPoint.y) + centerPoint.x);
	calculatePosition.y = (sinTheta * (basePosition.x - centerPoint.x) + cosTheta * (basePosition.y - centerPoint.y) + centerPoint.y);
	calculatePosition.z = basePosition.z;
	
	return calculatePosition;
}

Vector3 RotatePlayerMovement(Vector3 basePosition, Vector3 centerPoint, double angleInDegrees)
{
	//double angleInRadians = ((angleInDegrees) * 3.14f/180.0f);
	double angleInRadians = ((angleInDegrees) * 0.01744f);
    double cosTheta = cosf(angleInRadians);
    double sinTheta = sinf(angleInRadians);
		
	Vector3 calculatePosition;
	
	calculatePosition.x = (cosTheta * (basePosition.x - centerPoint.x) - sinTheta * (basePosition.y - centerPoint.y) + centerPoint.x);
	calculatePosition.y = (sinTheta * (basePosition.x - centerPoint.x) + cosTheta * (basePosition.y - centerPoint.y) + centerPoint.y);
	calculatePosition.z = basePosition.z;
	
	return calculatePosition;
}

Vector3 RotateCameraAround(Vector3 basePosition, Vector3 centerPoint, double angleInDegrees)
{
	
	//double angleInRadians = ((angleInDegrees) * 3.14f/180.0f);
	double angleInRadians = ((angleInDegrees) * 0.01744f);
    double cosTheta = cosf(angleInRadians);
    double sinTheta = sinf(angleInRadians);
		
	Vector3 calculatePosition;
	
	calculatePosition.x = (cosTheta * (basePosition.x - centerPoint.x) - sinTheta * (basePosition.y - centerPoint.y) + centerPoint.x);
	calculatePosition.y = (sinTheta * (basePosition.x - centerPoint.x) + cosTheta * (basePosition.y - centerPoint.y) + centerPoint.y);
	calculatePosition.z = basePosition.z;
	
	return calculatePosition;
	
}

Vector3 Normalize(Vector3 *vectorToNormalize) //normalize vector to between -1 and 1
{
	Vector3 normal = *vectorToNormalize;
	
	float xN = normal.x; //for calculating normalized version of x
	float yN = normal.y; //for calculating normalized version of y
	float zN = normal.z; //for calculating normalized version of z
	
	guNormalize(&xN, &yN, &zN );
	
	normal.x = xN;
	normal.y = yN;
	normal.z = zN;	
	
	*vectorToNormalize = normal;
}

float vectorDistance(Vector3 pointA, Vector3 pointB)
{
	/*
	float vecDistance = 0.0f;
	double compX = (pointA.x - pointB.x) * (pointA.x - pointB.x); // 55000-57000
	double compY = (pointA.y - pointB.y) * (pointA.y - pointB.y);  
	double compZ = (pointA.z - pointB.z) * (pointA.z - pointB.z); 
	
	vecDistance = sqrtf((float)compX + (float)compY + (float)compZ);
	
	return vecDistance;
	
	*/
	
	
	return (
		(pointA.x - pointB.x) * (pointA.x - pointB.x)
	+	(pointA.y - pointB.y) * (pointA.y - pointB.y)
	+	(pointA.z - pointB.z) * (pointA.z - pointB.z)
	);
}

float vectorSquareDistance(Vector3 Billy, Vector3 Bob)
{
	return	((Billy.x - Bob.x) * (Billy.x - Bob.x)
	+		(Billy.y - Bob.y) * (Billy.y - Bob.y)
	+		(Billy.z - Bob.z) * (Billy.z - Bob.z));
}


int absDistance(Vector3 pointA, Vector3 pointB)
{	//simplified distance calculation when precision is not needed
	int tempAbsDistance = 	abs((pointA.x - pointB.x)) + abs((pointA.y - pointB.y)) + 	abs((pointA.z - pointB.z));
	return 	tempAbsDistance;						
}

float vectorAngleTriangle(Vector3 pointA, Vector3 pointB,Vector3 pointC)
{
	//We are solving for the angle of the point *pointA
	float num = ((pointB.x-pointA.x)*(pointC.x-pointA.x))+
		((pointB.y-pointA.y)*(pointC.y-pointA.y))+
		((pointB.z-pointA.z)*(pointC.z-pointA.z));
		
	float den = sqrtf(powf((pointB.x-pointA.x), 2) + powf((pointB.y-pointA.y),2) + powf((pointB.z-pointA.z),2))/
		sqrtf(powf((pointC.x-pointA.x), 2) + powf((pointC.y-pointA.y),2) + powf((pointC.z-pointA.z),2));
		
	float angle = acosf(num / den)*(180.0/ PI);
	return angle;

}

Vector3 Falling()
{	
	Vector3 fallingDirection;
	fallingDirection.x = 0.0;
	fallingDirection.y = 0.0;
	fallingDirection.z = -7.0;
	
	return fallingDirection;
}
/*END--------------------Physics and Collision Functions--------------------*/