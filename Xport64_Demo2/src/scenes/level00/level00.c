//#include "levelDefs.h"
#include "common.h"
#include "objectDefs.h"
#include "level00.h"
#include "collisionDefs.h"
#include "lvl00_scn00_defs.h"
#include "lvl00_scn01_defs.h"


// extern void newLevelObject_PolyList(u8 animFrame); 
// extern void newLevelObject_transp_PolyList(u8 animFrame); 
// extern void newLevelObject_lightShaft_PolyList(u8 animFrame);




/*--------------------------------------------------------------------------*/
/*-----------------------------CAVE1 SCENE------------------------------*/
/*--------------------------------------------------------------------------*/
EnvObject lvl00_tile_floor;
EnvObject lvl00_tile_floor_flip;
EnvObject lvl00_red_matte_carpet;

EnvObject lvl00_wall_divider;
EnvObject lvl00_wall_divider_reflect;
EnvObject lvl00_wall_back;

EnvObject lvl00_wall_front;
EnvObject lvl00_large_pillars;

EnvObject lvl00_wall_sides;
EnvObject lvl00_art_pedistal;
EnvObject lvl00_art_pedistal_reflect;
EnvObject lvl00_art_pedistal2;
EnvObject lvl00_art_pedistal_reflect2;
EnvObject lvl00_art_pedistal3;
EnvObject lvl00_art_pedistal_reflect3;
EnvObject lvl00_art_pedistal4;
EnvObject lvl00_art_pedistal_reflect4;

//EnvObject lvl00_wall_back_reflect;


//EnvObject lvl00_wall_divider_flip;

EnvObject lvl00_texture_vtxcolor;
EnvObject lvl00_texture_shaded;
EnvObject lvl00_texture_transp;
EnvObject lvl100_texture_edgetransp;
EnvObject lvl00_prim_shaded;
EnvObject lvl00_prim_vtxcolor;
EnvObject lvl00_light_shaft;

EnvObject lvl00_16bRGBA_32x32;
EnvObject lvl00_16bRGBA_32x64;

EnvObject lvl00_vtx_animate;

EnvObject lvl00_prs_animate_1;
EnvObject lvl00_prs_animate_2;
EnvObject lvl00_prs_animate_3;



int currentObjFrame = 0;
int counterFrame = 0;

	//This is the lighting 
	Lights2 debug_lighting = gdSPDefLights2(  	100, 100, 60, // amb col 
	//side reflect light
	255, 255, 255, // col 1  
	0,   0,  90, // dir 1
	//ground reflect light
	10, 20, 25, // col 2   
	45,   0,  -90 // dir 2
	);
    
    Lights2 debug_lighting_2 = gdSPDefLights2(  	75, 75, 45, // amb col 
	//side reflect light
	255, 255, 255, // col 1  
	0,   45,  65, // dir 1
	//ground reflect light
	10, 20, 25, // col 2   
	45,   0,  -90 // dir 2
	);
/*--------------------------------------------------------------------------*/
/*-----------------------------COURTYARD SCENE------------------------------*/
/*--------------------------------------------------------------------------*/

SceneManager scene_Courtyard;

//TO DO NOTE: Set up "Material" types in blender for exporting different materials to call different combiner modes
//update scene / level managers to include triggers and lighting information
//update collision and re-export with less triangles and cut into smaller segments

// //TO DO NOTE: Set up collision to store in each scene...
// void set_collision_scenes(); //set up array of pointers that contain colliders for determining region
// void set_collision_sectors();

// void init_lvl00_Cave1();


// TriggerBox env01_courtyard_geom_trigger00 =
// {
	// -2675, -462, -284, 2511, 689, 997, 0 //courtyard scene collision
// };

// TriggerBox env01_courtyard_geom_trigger01 =
// {
	// -1024, -3785, -285, 1024,-302,997, 0 //courtyard scene collision
// };

// TriggerBox lvl00_courtyard_geom_triggers[2] =
// {
	// {-2675, -462, -284, 2511, 689, 997, 0}, //courtyard scene collision
	// {-1024, -3785, -285, 1024,-302,997, 0}  //courtyard scene collision
// };


// SectorTrigger lvl00_CourtyardSectorTrig[3] = {
// //NOTE ON USE: {	(sector)isActive,	(sector)trigBox		}
// //Sectors in Courtyard scene: courtyard entrance, courtyard main, courtyard exit
	// //-----Sector00: Courtyard Entrance-----
	// {	0, 	&lvl00_courtyard_col_wall01_TrigBox }, //----lvl00SectorTrig[0] Courtyard Entrance----
	// {	0, 	&lvl00_courtyard_col_wall02_TrigBox }, //----lvl00SectorTrig[0] Courtyard Entrance----
	// {	0, 	&lvl00_courtyard_col_wall03_TrigBox } //----lvl00SectorTrig[0] Courtyard Entrance----
	// //-----Sector01:  Courtyard Main 	-----
	// //{	0, 	1, &lvl00_courtyard_col_wall01_TrigBox } //----lvl00SectorTrig[0] Courtyard Main----
// };		

// SceneTrigger lvl00_SceneTrig[1] = {	
// //NOTE ON USE: {	(scene)isActive,	(scene)trigBox,	sectorCount(in scene),	sectorTrig(in scene)		}	
// //Scenes in level: courtyard, landing zone
	// //-----Scene [0]: Courtyard-----
	// {0,	lvl00_courtyard_geom_triggers,	3, lvl00_CourtyardSectorTrig},  //scene00----lvl00SceneTrig[0] Courtyard----
	
	// //-----Scene [1]:  Landing Zone 	-----
	// //{0,	&lvl00_courtyard_col_wall01_TrigBox,	1, lvl00SectorTrig}  //----lvl00SceneTrig[1] LandingZone----
// };

// LevelTrigger lvl00Triggers[] = {
// //NOTE ON USE: {	(level)isActive,	(level)trigBox,		sceneCount(in level),	SceneTrigArray(in level)		}		
	// //-----Level [0]: Courtyard-----
	// 0, &lvl00_courtyard_col_wall01_TrigBox,	1,	lvl00_SceneTrig	
// };

//Initiate Courtyard Environment
void init_lvl00_Courtyard() 
{
 	SetVector3(&lvl00_tile_floor.obj.pos, 0,0,0); 
	SetVector3(&lvl00_tile_floor.obj.rot, 0,0,0);
	SetVector3(&lvl00_tile_floor.obj.scl, 1,1,1);
	SetAnimator(&lvl00_tile_floor.animator, &Tile_Floor_PolyList, 0,0);	
    
    SetVector3(&lvl00_red_matte_carpet.obj.pos, 0,0,1); 
	SetVector3(&lvl00_red_matte_carpet.obj.rot, 0,0,0);
	SetVector3(&lvl00_red_matte_carpet.obj.scl, 1,1,1);
	SetAnimator(&lvl00_red_matte_carpet.animator, &MatteRedCarpet_PolyList, 0,0);	
       
    
    
//>-- Object 1 Demonstration: START --------------------------------------Primitive Color with Vertex Shading -------------------------------------------------    
    SetVector3(&lvl00_art_pedistal.obj.pos, -800,300,-2); 
	SetVector3(&lvl00_art_pedistal.obj.rot, 0,0,0);
	SetVector3(&lvl00_art_pedistal.obj.scl, 1,1,1);
	SetAnimator(&lvl00_art_pedistal.animator, &Xport64_Art_Pedistal_PolyList, 0,0);	
     
    SetVector3(&lvl00_art_pedistal_reflect.obj.pos, -800,300,-2); 
	SetVector3(&lvl00_art_pedistal_reflect.obj.rot, 0,0,0);
	SetVector3(&lvl00_art_pedistal_reflect.obj.scl, 1,1,1);
	SetAnimator(&lvl00_art_pedistal_reflect.animator, &Xport64_Art_Pedistal_Reflection_PolyList, 0,0);	
     
    SetVector3(&lvl00_prim_shaded.obj.pos, -800,300, 75);
	SetVector3(&lvl00_prim_shaded.obj.rot, 0,0,0);
	SetVector3(&lvl00_prim_shaded.obj.scl, 1,1,1);
	SetAnimator(&lvl00_prim_shaded.animator, &newLevelObject_PrimShaded_PolyList, 0,0);	 
//>-- Object 1 Demonstration: END -------------------------------------- Primitive Color with Vertex Shading -------------------------------------------------

     
     
     
//>-- Object 2 Demonstration: START --------------------------------------Primitive Color Unlit (Emissive) -------------------------------------------------    
     SetVector3(&lvl00_art_pedistal2.obj.pos, -580,300,-2); 
	 SetVector3(&lvl00_art_pedistal2.obj.rot, 0,0,0);
	 SetVector3(&lvl00_art_pedistal2.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_art_pedistal2.animator, &Xport64_Art_Pedistal_PolyList, 0,0);	
     
     SetVector3(&lvl00_art_pedistal_reflect2.obj.pos, -580,300,-2); 
	 SetVector3(&lvl00_art_pedistal_reflect2.obj.rot, 0,0,0);
	 SetVector3(&lvl00_art_pedistal_reflect2.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_art_pedistal_reflect2.animator, &Xport64_Art_Pedistal_Reflection_PolyList, 0,0);	
     
    SetVector3(&lvl00_prim_vtxcolor.obj.pos, -580,300,75);  
	SetVector3(&lvl00_prim_vtxcolor.obj.rot, 0,0,0);
	SetVector3(&lvl00_prim_vtxcolor.obj.scl, 1,1,1);
	SetAnimator(&lvl00_prim_vtxcolor.animator, &newLevelObject_prim_uv_PolyList, 0,0);	  
//>-- Object 2 Demonstration: END --------------------------------------Primitive Color Unlit (Emissive) -------------------------------------------------    
    
    
    
    
//>-- Object 3 Demonstration: START -------------------------------------- Textured with Vertex Shading -------------------------------------------------    
    SetVector3(&lvl00_art_pedistal3.obj.pos, 800,300,-2); 
	SetVector3(&lvl00_art_pedistal3.obj.rot, 0,0,0);
	SetVector3(&lvl00_art_pedistal3.obj.scl, 1,1,1);
	SetAnimator(&lvl00_art_pedistal3.animator, &Xport64_Art_Pedistal_PolyList, 0,0);	
     
    SetVector3(&lvl00_art_pedistal_reflect3.obj.pos, 800,300,-2); 
	SetVector3(&lvl00_art_pedistal_reflect3.obj.rot, 0,0,0);
	SetVector3(&lvl00_art_pedistal_reflect3.obj.scl, 1,1,1);
	SetAnimator(&lvl00_art_pedistal_reflect3.animator, &Xport64_Art_Pedistal_Reflection_PolyList, 0,0);	
     
	SetVector3(&lvl00_texture_vtxcolor.obj.pos, 800,300, 75);
	SetVector3(&lvl00_texture_vtxcolor.obj.rot, 0,0,0);
	SetVector3(&lvl00_texture_vtxcolor.obj.scl, 1,1,1);
	SetAnimator(&lvl00_texture_vtxcolor.animator, &newLevelObject_PolyList, 0,0);	
//>-- Object 3 Demonstration: END -------------------------------------- Textured with Vertex Shading -------------------------------------------------

     
     
     
//>-- Object 4 Demonstration: START -------------------------------------- Textured w/ VTX Colors -------------------------------------------------    
     SetVector3(&lvl00_art_pedistal4.obj.pos, 580,300,-2); 
	 SetVector3(&lvl00_art_pedistal4.obj.rot, 0,0,0);
	 SetVector3(&lvl00_art_pedistal4.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_art_pedistal4.animator, &Xport64_Art_Pedistal_PolyList, 0,0);	
     
     SetVector3(&lvl00_art_pedistal_reflect4.obj.pos, 580,300,-2); 
	 SetVector3(&lvl00_art_pedistal_reflect4.obj.rot, 0,0,0);
	 SetVector3(&lvl00_art_pedistal_reflect4.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_art_pedistal_reflect4.animator, &Xport64_Art_Pedistal_Reflection_PolyList, 0,0);	
     
    SetVector3(&lvl00_texture_shaded.obj.pos, 580,300,75); 
	SetVector3(&lvl00_texture_shaded.obj.rot, 0,0,0);
	SetVector3(&lvl00_texture_shaded.obj.scl, 1,1,1);
	SetAnimator(&lvl00_texture_shaded.animator, &newLevelObject_normals_PolyList, 0,0);	
//>-- Object 2 Demonstration: END -------------------------------------- Textured w/ VTX Colors -------------------------------------------------    
        
    
    
     SetVector3(&lvl00_wall_divider.obj.pos, 0,0,0); 
	 SetVector3(&lvl00_wall_divider.obj.rot, 0,0,0);
	 SetVector3(&lvl00_wall_divider.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_wall_divider.animator, &testpillar_PolyList, 0,0);	
     
     SetVector3(&lvl00_wall_divider_reflect.obj.pos, 0,0,0); 
	 SetVector3(&lvl00_wall_divider_reflect.obj.rot, 0,0,0);
	 SetVector3(&lvl00_wall_divider_reflect.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_wall_divider_reflect.animator, &testpillar_reflect_PolyList, 0,0);	
          
     SetVector3(&lvl00_wall_back.obj.pos, 0,0,0); 
	 SetVector3(&lvl00_wall_back.obj.rot, 0,0,0);
	 SetVector3(&lvl00_wall_back.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_wall_back.animator, &DebugRoom_Wall_PolyList, 0,0);	
     
     SetVector3(&lvl00_wall_front.obj.pos, 0,0,0); 
	 SetVector3(&lvl00_wall_front.obj.rot, 0,0,0);
	 SetVector3(&lvl00_wall_front.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_wall_front.animator, &DebugRoom_Front_Wall_PolyList, 0,0);	
     
     SetVector3(&lvl00_large_pillars.obj.pos, 0,0,0); 
	 SetVector3(&lvl00_large_pillars.obj.rot, 0,0,0);
	 SetVector3(&lvl00_large_pillars.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_large_pillars.animator, &LargePillars_PolyList, 0,0);	
     
     SetVector3(&lvl00_wall_sides.obj.pos, 0,0,0); 
	 SetVector3(&lvl00_wall_sides.obj.rot, 0,0,0);
	 SetVector3(&lvl00_wall_sides.obj.scl, 1,1,1);
	 SetAnimator(&lvl00_wall_sides.animator, &DebugRoom_Side_Walls_PolyList, 0,0);	  
     

    
    SetVector3(&lvl00_16bRGBA_32x32.obj.pos, -210,-400,120); 
	SetVector3(&lvl00_16bRGBA_32x32.obj.rot, 0,0,0);
	SetVector3(&lvl00_16bRGBA_32x32.obj.scl, 1,1,1);
	SetAnimator(&lvl00_16bRGBA_32x32.animator, &TextureSample_16bRGBA_32x32_PolyList, 0,0);	
    
    SetVector3(&lvl00_16bRGBA_32x64.obj.pos, 210,-400,120); 
	SetVector3(&lvl00_16bRGBA_32x64.obj.rot, 0,0,0);
	SetVector3(&lvl00_16bRGBA_32x64.obj.scl, 1,1,1);
	SetAnimator(&lvl00_16bRGBA_32x64.animator, &TextureSample_16bRGBA_32x64_PolyList, 0,0);	   
    

    
    SetVector3(&lvl00_light_shaft.obj.pos, 0,240,0); 
	SetVector3(&lvl00_light_shaft.obj.rot, 0,0,0);
	SetVector3(&lvl00_light_shaft.obj.scl, 1,1,1);
	SetAnimator(&lvl00_light_shaft.animator, &newLevelObject_lightShaft_PolyList, 0,0);	
    
    SetVector3(&lvl00_texture_transp.obj.pos, 690,-360,150);
	SetVector3(&lvl00_texture_transp.obj.rot, 0,0,180);
	SetVector3(&lvl00_texture_transp.obj.scl, 1,1,1);
	SetAnimator(&lvl00_texture_transp.animator, &newLevelObject_transp_PolyList, 0,0);	
    
    SetVector3(&lvl100_texture_edgetransp.obj.pos, 690,-360,75);
	SetVector3(&lvl100_texture_edgetransp.obj.rot, 0,0,180);
	SetVector3(&lvl100_texture_edgetransp.obj.scl, 1,1,1);
	SetAnimator(&lvl100_texture_edgetransp.animator, &newLevelObject_edgeTransp_PolyList, 0,0);	
    

    
    SetVector3(&lvl00_vtx_animate.obj.pos, -690,-250,2); 
	SetVector3(&lvl00_vtx_animate.obj.rot, 0,0,0);
	SetVector3(&lvl00_vtx_animate.obj.scl, 1,1,1);
	SetAnimator(&lvl00_vtx_animate.animator, &exportAnimation_Vtx_DL_PolyList, 0 ,currentObjFrame);	    
    
    SetVector3(&lvl00_prs_animate_1.obj.pos, -120,120,0); 
    
	SetAnimator(&lvl00_prs_animate_1.animator, &exportAnimation_Pos_Rot_Scl_1_PolyList, 0 ,currentObjFrame);	    
    
    SetAnimator(&lvl00_prs_animate_2.animator, &exportAnimation_Pos_Rot_Scl_2_PolyList, 0 ,currentObjFrame);	   
    
    SetAnimator(&lvl00_prs_animate_3.animator, &exportAnimation_Pos_Rot_Scl_3_PolyList, 0 ,currentObjFrame);	    
}

   int localAnimationTimer = 0;
   
void update_lvl00_DemoScene()
{
	
    int globalAnimationTimer = 0;
	int animFrameDifference = 0; //in the event of extreme slowdown, check how much time has elapsed

    globalAnimationTimer = GetFPS_30(); //animation playback at 30 fps gives the best, most consistent performance
	
	if (globalAnimationTimer != localAnimationTimer)
	{
		animFrameDifference = globalAnimationTimer-localAnimationTimer;
	
        localAnimationTimer = globalAnimationTimer;
    
        if(currentObjFrame <= 30)		
            currentObjFrame += animFrameDifference;
            
        else
        {
            currentObjFrame = 0;
        }
    }    
    
}

void render_lvl00_Courtyard()
{
	int level = 0;
	int scene = 0;
	int sector = 0;
    
//NOTE ----- Draw non-transparent objects first   


//>-- Environment: START ------------------------------------------ Non-Transparent walls, floor, pillars, etc -------------------------------------------------

     //RenderEnvObj(&lvl00_tile_floor_flip);
   TEXTURE_FOG_VTXCOL(glistp, 50, 45, 40, 255,965,1010);   

   gDPSetColorDither(  glistp++,  G_CD_BAYER );   
   gDPSetAlphaDither(  glistp++,  G_CD_BAYER );  

   RenderEnvObj(&lvl00_wall_divider);
   
   RenderEnvObj(&lvl00_art_pedistal);
   RenderEnvObj(&lvl00_art_pedistal2);
   RenderEnvObj(&lvl00_art_pedistal3);
   RenderEnvObj(&lvl00_art_pedistal4);
   
   RenderEnvObj(&lvl00_wall_back);
   RenderEnvObj(&lvl00_large_pillars);
   RenderEnvObj(&lvl00_wall_front);   
   
   RenderEnvObj(&lvl00_wall_sides);  
 

   
   
//>-- Environment: END ------------------------------------------ Non-Transparent walls, floor, pillars, etc -------------------------------------------------

   

//>-- GFX Demonstration: START ------------------------------------------ Non-Transparent "Artwork" in the scene to demonstrate GFX effects -------------------------------------------------
   
    RenderEnvObj(&lvl00_texture_vtxcolor);
    RenderEnvObj(&lvl00_prim_vtxcolor); 

    RenderEnvObj(&lvl00_16bRGBA_32x64);               

    RenderEnvObj(&lvl00_16bRGBA_32x32);
    
    
    TEXTURE_FOG_VTXCOL(glistp, 195, 160, 100, 0,925,800);    
    RenderEnvObj(&lvl00_red_matte_carpet); 
        
    TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,800,980);	

    gSPSetLights2(glistp++, debug_lighting);
    RenderEnvObj(&lvl00_texture_shaded);
    RenderEnvObj(&lvl00_prim_shaded);            
        // gSPSetLights2(glistp++, debug_lighting_2);
    RenderEnvObj(&lvl00_vtx_animate);
       // RenderEnvObj(&lvl00_prs_animate_1);
       //// RenderEnvObj(&lvl00_prs_animate_2);
       // RenderEnvObj(&lvl00_prs_animate_3);
       
//>-- GFX Demonstration: END ------------------------------------------ Non-Transparent "Artwork" in the scene to demonstrate GFX effects -------------------------------------------------
        
            
        
        
        
            
}

void render_lvl00_transparent()
{         
//NOTE ----- Draw edge transparency second 

//>-- 1b Cut-out Objects: START --------------------------------------Render 1b alpha objects after solid objects -------------------------------------------------
    TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,800,980);	
    
       gDPSetColorDither(  glistp++,  G_CD_BAYER );   
   gDPSetAlphaDither(  glistp++,  G_CD_BAYER ); 
     RenderEnvObj(&lvl100_texture_edgetransp);
    
//>-- 1b Cut-out Objects: END --------------------------------------Render 1b alpha objects after solid objects -------------------------------------------------




//>-- Translucent Objects: START --------------------------------------Render Translucent objects after 1b cut-out transparency objects -------------------------------------------------
    TEXTURE_FOG_VTXCOL(glistp, 75, 75, 75, 0,1010,980);    
     
    //Render the "reflected" objects first since the transparent tile floor is "between" the camera and the reflection
    RenderEnvObj(&lvl00_wall_divider_reflect);
    

    TEXTURE_FOG_VTXCOL(glistp, 175, 175, 170, 175,970,990);     
    RenderEnvObj(&lvl00_art_pedistal_reflect); 
    RenderEnvObj(&lvl00_art_pedistal_reflect2); 
    RenderEnvObj(&lvl00_art_pedistal_reflect3); 
    RenderEnvObj(&lvl00_art_pedistal_reflect4); 
   
    
    TEXTURE_FOG_VTXCOL(glistp, 255, 255, 255, 255,950,992);    
       gDPSetColorDither(  glistp++,  G_CD_BAYER );   
   gDPSetAlphaDither(  glistp++,  G_CD_BAYER ); 
     RenderEnvObj(&lvl00_texture_transp);
    //RenderEnvObj(&lvl00_light_shaft);   
    RenderEnvObj(&lvl00_tile_floor);
//>-- Translucent Objects: END --------------------------------------Render Translucent objects after 1b cut-out transparency objects -------------------------------------------------
   

    


}
	

//NOTE ABOUT USAGE: 'collision_scenes' Scenes within a region would be such as the courtyard scene or the landing zone scene. 
//This will be a series of medium sized TriggerBox objects to determine the scenes that the player is near
//Used to determine what display lists to render in the current scene. 
//Used to narrow down what collision might be checked 

void lvl00_collision_scenes() 
{

}

void lvl00_collision_walls() 
{

	
}
