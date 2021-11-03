#include "common.h"
#include "objectDefs.h"
#include "level00.h"

 Vector3 tempObjVectorPos;
 Vector3 tempObjVectorRot;
 Vector3 tempObjVectorScl;

 

 //Test... True

 //Test... 84

 //Test... 48
   Lights1 DefaultSceneLight = gdSPDefLights1(
     84, 114, 69,
     48, 34, 66,     -3, 35, -82
   );

   Lights1 debugLightStruct = gdSPDefLights1(
     0, 255, 146,
     0, 255, 101,     90, 90, 90
   );

   Lights1 debugMatLight = gdSPDefLights1(
     0, 74, 7,
     0, 3, 101,     90, 90, 90
   );

   Lights1 texturedCubeLight = gdSPDefLights1(
     55, 123, 77,
     255, 230, 123,     -1, 6, -89
   );

   Lights1 primLightTest = gdSPDefLights1(
     55, 123, 77,
     255, 230, 123,     -4, 46, -77
   );

//>-- OBJECT 0: START ------------------------------------------ MatteRedCarpet -------------------------------------------------

Vtx MatteRedCarpet_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 0:  105, 11, 0 
//Found a new color! Color Index: 2     Vert 2:  135, 48, 32 
   { -2.05, 384.28, -1.43, 1, 0x01ff, 0x0022, 105, 11, 0, 255}, 
   { -110.80, 384.48, -1.43, 1, 0x0003, 0x001e, 105, 11, 0, 255}, 
   { -110.80, 191.67, -1.43, 1, 0x0003, 0x108e, 135, 48, 32, 255}, 
   { 106.69, 191.67, -1.43, 1, 0x03fc, 0x108e, 135, 48, 32, 255}, 
   { 106.69, 384.48, -1.43, 1, 0x03fc, 0x001e, 105, 11, 0, 255}, 
//Found a new color! Color Index: 3     Vert 0:  166, 85, 64 
//Found a new color! Color Index: 4     Vert 2:  145, 58, 41 
   { -2.05, -1.14, -1.43, 1, 0x01ff, 0x20fe, 166, 85, 64, 255}, 
   { -110.80, -1.14, -1.43, 1, 0x0003, 0x20fe, 166, 85, 64, 255}, 
   { -110.80, -203.52, -1.43, 1, 0x0003, 0x323f, 145, 58, 41, 255}, 
//Found a new color! Color Index: 5     Vert 0:  157, 68, 49 
   { 106.69, -203.52, -1.43, 1, 0x03fc, 0x323f, 157, 68, 49, 255}, 
   { 106.69, -1.14, -1.43, 1, 0x03fc, 0x20fe, 166, 85, 64, 255}, 
   { -2.05, 191.57, -1.43, 1, 0x01ff, 0x1090, 135, 48, 32, 255}, 
//Found a new color! Color Index: 6     Vert 0:  148, 52, 34 
   { 106.69, -405.90, -1.43, 1, 0x03fc, 0x4380, 148, 52, 34, 255}, 
   { -2.05, -203.98, -1.43, 1, 0x01ff, 0x3249, 157, 68, 49, 255}, 
//Found a new color! Color Index: 7     Vert 2:  124, 32, 18 
   { -110.80, -405.90, -1.43, 1, 0x0003, 0x4380, 124, 32, 18, 255}, 
   { -2.05, -406.82, -1.43, 1, 0x01ff, 0x4394, 148, 52, 34, 255}, 
};

void MatteRedCarpet_PolyList(u8 animFrame){ 

   Vtx *MatteRedCarpet_VTXPointer = &MatteRedCarpet_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 2: START ------------------------------------ 'RedMatteCarpet'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_DryWall_32x128,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_DryWall_32x128_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  MatteRedCarpet_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 0, 3  );
     gSP2Triangles(glistp++,   5, 6, 7, 5, 8, 9, 5, 8  );
     gSP2Triangles(glistp++,   9, 3, 10, 9, 10, 2, 6, 10  );
     gSP2Triangles(glistp++,   11, 8, 12, 11, 12, 7, 13, 12  );
     gSP2Triangles(glistp++,   10, 0, 2, 10, 10, 3, 0, 10  );
     gSP2Triangles(glistp++,   12, 5, 7, 12, 12, 8, 5, 12  );
     gSP2Triangles(glistp++,   5, 9, 10, 5, 5, 10, 6, 5  );
     gSP2Triangles(glistp++,   14, 11, 12, 14, 14, 12, 13, 14  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 0: END ------------------------------------------- MatteRedCarpet -------------------------------------------------

 
 
//>-- OBJECT 1: START ------------------------------------------ newLevelObject_transp -------------------------------------------------

Vtx newLevelObject_transp_VertList_0 [] = {
   { -90.00, -30.00, 59.40, 1, 0x0011, 0x0000, 255, 255, 255, 255}, 
   { -90.00, -30.00, -0.60, 1, 0x0012, 0x0ffe, 255, 255, 255, 255}, 
   { 90.00, -30.00, -0.60, 1, 0x3009, 0x0ffe, 255, 255, 255, 255}, 
   { 90.00, -30.00, 59.40, 1, 0x3009, 0x0000, 255, 255, 255, 255}, 
};

void newLevelObject_transp_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_transp_VTXPointer = &newLevelObject_transp_VertList_0[0]; 

// Set Object Light: 
   gSPSetLights1( glistp++,  debugLightStruct );


//>-- MATERIAL 0: START ------------------------------------ 'AlphaTexture'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_AA_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_1bAlphaBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_CLAMP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_1bAlphaBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );

// Set Material Light: 
   gSPSetLights1( glistp++,  debugMatLight );
   gSPVertex(glistp++,  newLevelObject_transp_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 0, 2, 3  );
// Set Object Light: 
   gSPSetLights1( glistp++,  debugLightStruct );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 1: END ------------------------------------------- newLevelObject_transp -------------------------------------------------

 
 
//>-- OBJECT 2: START ------------------------------------------ Xport64_Art_Pedistal_Reflection -------------------------------------------------

Vtx Xport64_Art_Pedistal_Reflection_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 2:  0, 0, 0 
   { -26.85, -36.95, 0.06, 1, 0x98bf, 0x0401, 255, 255, 255, 255}, 
   { -43.44, 14.11, 0.06, 1, 0x6791, 0x0401, 255, 255, 255, 255}, 
   { -49.68, 16.14, -46.19, 1, 0x6791, 0x000d, 0, 0, 0, 0}, 
   { -0.00, 45.67, 0.06, 1, 0x3663, 0x0401, 255, 255, 255, 255}, 
   { 0.00, 52.24, -46.19, 1, 0x3663, 0x000d, 0, 0, 0, 0}, 
   { 26.85, -36.95, 0.06, 1, 0xc9ec, 0x0401, 255, 255, 255, 255}, 
   { -30.71, -42.26, -46.19, 1, 0x98bf, 0x000d, 0, 0, 0, 0}, 
   { 43.44, 14.11, 0.06, 1, 0xfb1a, 0x0401, 255, 255, 255, 255}, 
   { 30.71, -42.26, -46.19, 1, 0xc9ec, 0x000d, 0, 0, 0, 0}, 
   { 49.68, 16.14, -46.19, 1, 0x0536, 0x000d, 0, 0, 0, 0}, 
//Found a new color! Color Index: 2     Vert 0:  219, 219, 219 
   { -41.16, 13.37, 47.84, 1, 0x019e, 0x0081, 219, 219, 219, 219}, 
   { -43.44, 14.11, 39.55, 1, 0x019e, 0x0100, 255, 255, 255, 255}, 
   { -26.85, -36.95, 39.55, 1, 0x0262, 0x0100, 255, 255, 255, 255}, 
   { 0.00, 43.27, 47.84, 1, 0x00d9, 0x0081, 255, 255, 255, 255}, 
   { -0.00, 45.67, 39.55, 1, 0x00d9, 0x0100, 255, 255, 255, 255}, 
   { -25.44, -35.01, 47.84, 1, 0x0262, 0x0081, 255, 255, 255, 255}, 
   { 26.85, -36.95, 39.55, 1, 0x0327, 0x0100, 255, 255, 255, 255}, 
   { 25.44, -35.01, 47.84, 1, 0x0327, 0x0081, 255, 255, 255, 255}, 
   { 43.44, 14.11, 39.55, 1, 0x03ec, 0x0100, 255, 255, 255, 255}, 
   { 41.16, 13.37, 47.84, 1, 0x0014, 0x0081, 255, 255, 255, 255}, 
   { 37.32, 12.13, 61.78, 1, 0x0014, 0x0003, 0, 0, 0, 0}, 
   { 23.06, -31.74, 61.78, 1, 0x0327, 0x0003, 0, 0, 0, 0}, 
   { -23.06, -31.74, 61.78, 1, 0x0262, 0x0003, 0, 0, 0, 0}, 
   { 0.00, 39.24, 61.78, 1, 0x00d9, 0x0003, 0, 0, 0, 0}, 
   { -37.32, 12.13, 61.78, 1, 0x019e, 0x0003, 0, 0, 0, 0}, 
};

void Xport64_Art_Pedistal_Reflection_PolyList(u8 animFrame){ 

   Vtx *Xport64_Art_Pedistal_Reflection_VTXPointer = &Xport64_Art_Pedistal_Reflection_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 2: START ------------------------------------ 'Xport64_PedistalSideReflect_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, SHADE, PRIMITIVE, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_4b_Pedistal_128x32,	G_IM_FMT_CI,	128, 32,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_4b_Pedistal_128x32_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetColorDither(  glistp++,  G_CD_NOISE );
   gDPSetPrimColor(glistp++,  1,255,255,255,255,89  );

   gSPVertex(glistp++,  Xport64_Art_Pedistal_Reflection_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 1, 3, 4, 1  );
     gSP2Triangles(glistp++,   5, 0, 6, 5, 7, 5, 8, 7  );
   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x05360401);  /*New Coords: 10.42, 32.06*/
     gSP2Triangles(glistp++,   3, 7, 9, 3, 6, 0, 2, 6  );
     gSP2Triangles(glistp++,   2, 1, 4, 2, 8, 5, 6, 8  );
   gSPModifyVertex(glistp++,  9,   G_MWO_POINT_ST, 0xfb1a000d);  /*New Coords: 502.21, 0.43*/   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0xfb1a0401);  /*New Coords: 502.21, 32.06*/
     gSP1Triangle(glistp++,   9, 7, 8, 9  );
   gSPModifyVertex(glistp++,  9,   G_MWO_POINT_ST, 0x0536000d);  /*New Coords: 10.42, 0.43*/
     gSP1Triangle(glistp++,   4, 3, 9, 4  );


//>-- MATERIAL 3: START ------------------------------------ 'Xport64_PedistalGlow_16x16'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, SHADE, PRIMITIVE, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_SimpleGlow_16x16,	G_IM_FMT_CI,	16, 16,	0, G_TX_WRAP,G_TX_WRAP, 4,4, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_SimpleGlow_16x16_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetColorDither(  glistp++,  G_CD_NOISE );
   gDPSetPrimColor(glistp++,  1,255,255,242,227,63  );

   gSPVertex(glistp++,  Xport64_Art_Pedistal_Reflection_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   10, 11, 12, 10, 13, 14, 11, 13  );
     gSP2Triangles(glistp++,   15, 12, 16, 15, 17, 16, 18, 17  );
   gSPModifyVertex(glistp++,  18,   G_MWO_POINT_ST, 0x00140100);  /*New Coords: 1.30, 16.03*/
     gSP2Triangles(glistp++,   19, 18, 14, 19, 20, 19, 13, 20  );
   gSPModifyVertex(glistp++,  20,   G_MWO_POINT_ST, 0x03ec0003);  /*New Coords: 62.78, 0.21*/
     gSP2Triangles(glistp++,   20, 21, 17, 20, 21, 22, 15, 21  );
     gSP2Triangles(glistp++,   23, 13, 10, 23, 24, 10, 15, 24  );
     gSP2Triangles(glistp++,   15, 10, 12, 15, 10, 13, 11, 10  );
   gSPModifyVertex(glistp++,  19,   G_MWO_POINT_ST, 0x03ec0081);  /*New Coords: 62.78, 8.12*/   gSPModifyVertex(glistp++,  18,   G_MWO_POINT_ST, 0x03ec0100);  /*New Coords: 62.78, 16.03*/
     gSP2Triangles(glistp++,   17, 15, 16, 17, 19, 17, 18, 19  );
   gSPModifyVertex(glistp++,  19,   G_MWO_POINT_ST, 0x00140081);  /*New Coords: 1.30, 8.12*/   gSPModifyVertex(glistp++,  20,   G_MWO_POINT_ST, 0x00140003);  /*New Coords: 1.30, 0.21*/
     gSP2Triangles(glistp++,   13, 19, 14, 13, 23, 20, 13, 23  );
   gSPModifyVertex(glistp++,  19,   G_MWO_POINT_ST, 0x03ec0081);  /*New Coords: 62.78, 8.12*/   gSPModifyVertex(glistp++,  20,   G_MWO_POINT_ST, 0x03ec0003);  /*New Coords: 62.78, 0.21*/
     gSP2Triangles(glistp++,   19, 20, 17, 19, 17, 21, 15, 17  );
     gSP2Triangles(glistp++,   24, 23, 10, 24, 22, 24, 15, 22  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 2: END ------------------------------------------- Xport64_Art_Pedistal_Reflection -------------------------------------------------

 
 
//>-- OBJECT 3: START ------------------------------------------ Xport64_Art_Pedistal -------------------------------------------------

Vtx Xport64_Art_Pedistal_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 2:  139, 137, 148 
   { -0.00, 50.58, 41.88, 1, 0x472b, 0x000d, 255, 255, 255, 255}, 
   { 48.10, 15.63, 41.88, 1, 0x1e08, 0x000d, 255, 255, 255, 255}, 
   { 43.44, 14.11, 0.06, 1, 0x1e08, 0x040e, 139, 137, 148, 255}, 
//Found a new color! Color Index: 2     Vert 2:  80, 78, 95 
   { 29.73, -40.92, 41.88, 1, 0xc292, 0x000d, 255, 255, 255, 255}, 
   { 26.85, -36.95, 0.06, 1, 0xc292, 0x040e, 80, 78, 95, 255}, 
   { -29.73, -40.92, 41.88, 1, 0x9970, 0x000d, 255, 255, 255, 255}, 
   { -26.85, -36.95, 0.06, 1, 0x9970, 0x040e, 80, 78, 95, 255}, 
//Found a new color! Color Index: 3     Vert 0:  38, 38, 38 
   { -0.44, -0.23, 41.88, 1, 0x0e8b, 0x00cb, 38, 38, 38, 255}, 
   { -48.10, 15.63, 41.88, 1, 0x17fd, 0x100d, 255, 255, 255, 255}, 
   { -0.00, 45.67, 0.06, 1, 0x472b, 0x040e, 80, 78, 95, 255}, 
   { -43.44, 14.11, 0.06, 1, 0x704d, 0x040e, 80, 78, 95, 255}, 
};

void Xport64_Art_Pedistal_PolyList(u8 animFrame){ 

   Vtx *Xport64_Art_Pedistal_VTXPointer = &Xport64_Art_Pedistal_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'Xport64_PedistalSide_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_4b_Pedistal_128x32,	G_IM_FMT_CI,	128, 32,	0, G_TX_WRAP,G_TX_WRAP, 7,5, 2,G_TX_NOLOD );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_4b_Pedistal_128x32_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  Xport64_Art_Pedistal_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0xebb4000d);  /*New Coords: 471.41, 0.43*/
     gSP2Triangles(glistp++,   0, 1, 2, 0, 1, 3, 4, 1  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x704d000d);  /*New Coords: 224.61, 0.43*/
     gSP2Triangles(glistp++,   3, 5, 6, 3, 8, 0, 9, 8  );
     gSP2Triangles(glistp++,   5, 8, 10, 5, 9, 0, 2, 9  );
   gSPModifyVertex(glistp++,  2,   G_MWO_POINT_ST, 0xebb4040e);  /*New Coords: 471.41, 32.47*/
     gSP2Triangles(glistp++,   2, 1, 4, 2, 4, 3, 6, 4  );
     gSP2Triangles(glistp++,   10, 8, 9, 10, 6, 5, 10, 6  );


//>-- MATERIAL 1: START ------------------------------------ 'Xport64_PedistalTop_64x64'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_PedistalTop_64x64,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_PedistalTop_64x64_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  Xport64_Art_Pedistal_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x053c1012);  /*New Coords: 20.95, 64.29*/   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x17fd100d);  /*New Coords: 95.96, 64.21*/   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0x053c1012);  /*New Coords: 20.95, 64.29*/
     gSP2Triangles(glistp++,   7, 8, 5, 7, 3, 1, 7, 3  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x053c1012);  /*New Coords: 20.95, 64.29*/
     gSP2Triangles(glistp++,   0, 8, 7, 0, 3, 7, 5, 3  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x17fd100d);  /*New Coords: 95.96, 64.21*/     gSP1Triangle(glistp++,   1, 0, 7, 1  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 3: END ------------------------------------------- Xport64_Art_Pedistal -------------------------------------------------

 
 
//>-- OBJECT 4: START ------------------------------------------ DebugRoom_Side_Walls -------------------------------------------------

Vtx DebugRoom_Side_Walls_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 0:  202, 201, 206 
//Found a new color! Color Index: 2     Vert 2:  80, 78, 95 
   { -892.73, 33.96, 15.62, 1, 0x303b, 0x295a, 202, 201, 206, 255}, 
   { -892.73, 33.96, -2.97, 1, 0x303b, 0x3a6a, 202, 201, 206, 255}, 
   { -892.73, 389.54, -2.97, 1, 0x508e, 0x3a6a, 80, 78, 95, 255}, 
   { -892.73, 389.54, 15.62, 1, 0x508e, 0x295a, 80, 78, 95, 255}, 
   { -892.73, 389.54, 60.19, 1, 0x508e, 0x0073, 80, 78, 95, 255}, 
   { -892.73, 389.54, 562.78, 1, 0x19e0, 0x0cc5, 80, 78, 95, 255}, 
   { -892.73, 33.96, 60.19, 1, 0x14a4, 0x3a40, 255, 255, 255, 255}, 
   { -892.73, 411.74, 60.19, 1, 0x1a8e, 0x3ea7, 80, 78, 95, 255}, 
   { -892.73, 411.74, -2.97, 1, 0x5293, 0x3a6a, 80, 78, 95, 255}, 
   { -892.73, 411.74, 15.62, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { -892.73, 33.96, 562.78, 1, 0x1456, 0x0847, 202, 201, 206, 255}, 
   { -892.73, -321.61, -2.97, 1, 0x0fe8, 0x3a6a, 80, 78, 95, 255}, 
   { -892.73, -321.61, 15.62, 1, 0x0fe8, 0x295a, 80, 78, 95, 255}, 
   { -892.73, -321.61, 60.19, 1, 0x0fe8, 0x0073, 202, 201, 206, 255}, 
   { -892.73, -321.61, 562.78, 1, 0x0e4d, 0x09bd, 202, 201, 206, 255}, 
   { -892.73, -343.81, 60.19, 1, 0x0e3a, 0x3bcd, 80, 78, 95, 255}, 
   { -892.73, -343.81, -2.97, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { -892.73, -343.81, 15.62, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { 892.73, 389.54, -2.97, 1, 0x508e, 0x3a6a, 80, 78, 95, 255}, 
   { 892.73, 33.96, -2.97, 1, 0x303b, 0x3a6a, 202, 201, 206, 255}, 
   { 892.73, 33.96, 15.62, 1, 0x303b, 0x295a, 202, 201, 206, 255}, 
   { 892.73, 389.54, 15.62, 1, 0x508e, 0x295a, 80, 78, 95, 255}, 
   { 892.73, 389.54, 60.19, 1, 0x508e, 0x0073, 80, 78, 95, 255}, 
   { 892.73, 33.96, 60.19, 1, 0x14a4, 0x3a40, 255, 255, 255, 255}, 
   { 892.73, 389.54, 562.78, 1, 0x19e0, 0x0cc5, 80, 78, 95, 255}, 
   { 892.73, 411.74, 60.19, 1, 0x1a8e, 0x3ea7, 80, 78, 95, 255}, 
   { 892.73, 411.74, -2.97, 1, 0x5293, 0x3a6a, 80, 78, 95, 255}, 
   { 892.73, 411.74, 15.62, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { 892.73, 33.96, 562.78, 1, 0x1456, 0x0847, 202, 201, 206, 255}, 
   { 892.73, -321.61, -2.97, 1, 0x0fe8, 0x3a6a, 80, 78, 95, 255}, 
   { 892.73, -321.61, 15.62, 1, 0x0fe8, 0x295a, 80, 78, 95, 255}, 
   { 892.73, -321.61, 60.19, 1, 0x0fe8, 0x0073, 202, 201, 206, 255}, 
   { 892.73, -321.61, 562.78, 1, 0x0e4d, 0x09bd, 202, 201, 206, 255}, 
   { 892.73, -343.81, 60.19, 1, 0x0e3a, 0x3bcd, 80, 78, 95, 255}, 
   { 892.73, -343.81, -2.97, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { 892.73, -343.81, 15.62, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { -892.73, 411.74, 562.78, 1, 0x1a41, 0x0cad, 80, 78, 95, 255}, 
   { -892.73, 389.54, 562.78, 1, 0x19e0, 0x0cc5, 80, 78, 95, 255}, 
   { -892.73, 411.74, 60.19, 1, 0x1a8e, 0x3ea7, 80, 78, 95, 255}, 
   { -892.73, 411.74, 60.19, 1, 0x5293, 0x0073, 80, 78, 95, 255}, 
   { -892.73, 389.54, 60.19, 1, 0x508e, 0x0073, 80, 78, 95, 255}, 
   { -892.73, 411.74, 15.62, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { -892.73, -343.81, 562.78, 1, 0x0dec, 0x09d4, 80, 78, 95, 255}, 
   { 892.73, 411.74, 562.78, 1, 0x1a41, 0x0cad, 80, 78, 95, 255}, 
   { 892.73, -343.81, 562.78, 1, 0x0dec, 0x09d4, 80, 78, 95, 255}, 
};

void DebugRoom_Side_Walls_PolyList(u8 animFrame){ 

   Vtx *DebugRoom_Side_Walls_VTXPointer = &DebugRoom_Side_Walls_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'Xport64_TileWall_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_TileWall_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_TileWall_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 0, 3  );
     gSP2Triangles(glistp++,   3, 2, 8, 3, 4, 3, 9, 4  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   4, 6, 0, 4, 11, 1, 0, 11  );
     gSP2Triangles(glistp++,   12, 0, 13, 12, 16, 11, 12, 16  );
     gSP2Triangles(glistp++,   17, 12, 13, 17, 13, 0, 6, 13  );
     gSP2Triangles(glistp++,   18, 19, 20, 18, 21, 20, 22, 21  );
     gSP2Triangles(glistp++,   26, 18, 21, 26, 27, 21, 22, 27  );
   gSPModifyVertex(glistp++,  23,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   22, 20, 23, 22, 20, 19, 29, 20  );
   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+20,31,0  );
     gSP2Triangles(glistp++,   10, 11, 0, 10, 10, 9, 14, 10  );
   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   11, 10, 15, 11, 11, 3, 0, 11  );
   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 3, 8, 9  );
   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+30,31,0  );
     gSP1Triangle(glistp++,   9, 10, 11, 9  );
   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+0,31,0  );
     gSP1Triangle(glistp++,   12, 11, 0, 12  );
   gSPModifyVertex(glistp++,  15,   G_MWO_POINT_ST, 0x0de30073);  /*New Coords: 111.12, 0.90*/
     gSP2Triangles(glistp++,   17, 16, 12, 17, 15, 17, 13, 15  );
     gSP2Triangles(glistp++,   21, 18, 20, 21, 27, 26, 21, 27  );
   gSPModifyVertex(glistp++,  25,   G_MWO_POINT_ST, 0x52930073);  /*New Coords: 660.61, 0.90*/
     gSP2Triangles(glistp++,   25, 27, 22, 25, 30, 20, 29, 30  );
   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+30,31,0  );
   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x0de30073);  /*New Coords: 111.12, 0.90*/
     gSP2Triangles(glistp++,   5, 0, 4, 5, 3, 1, 5, 3  );


//>-- MATERIAL 1: START ------------------------------------ 'Prim_White'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_DryWall_32x128,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_DryWall_32x128_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,255,173,150,255  );

   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x1a2e3ebe);  /*New Coords: 209.45, 125.49*/
     gSP2Triangles(glistp++,   4, 5, 6, 4, 5, 4, 7, 5  );
   gSPModifyVertex(glistp++,  13,   G_MWO_POINT_ST, 0x0e9a3bb6);  /*New Coords: 116.84, 119.43*/
     gSP2Triangles(glistp++,   5, 10, 6, 5, 13, 6, 14, 13  );
     gSP2Triangles(glistp++,   15, 13, 14, 15, 14, 6, 10, 14  );
   gSPModifyVertex(glistp++,  22,   G_MWO_POINT_ST, 0x1a2e3ebe);  /*New Coords: 209.45, 125.49*/
     gSP2Triangles(glistp++,   22, 23, 24, 22, 25, 22, 24, 25  );
     gSP1Triangle(glistp++,   24, 23, 28, 24  );
   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+23,31,0  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x0e9a3bb6);  /*New Coords: 116.84, 119.43*/
     gSP1Triangle(glistp++,   8, 9, 0, 8  );
     gSP2Triangles(glistp++,   9, 8, 10, 9, 9, 5, 0, 9  );
     gSP1Triangle(glistp++,   13, 14, 15, 13  );
   gSPVertex(glistp++,  DebugRoom_Side_Walls_VTXPointer+14,31,0  );
     gSP1Triangle(glistp++,   28, 1, 0, 28  );
     gSP2Triangles(glistp++,   29, 11, 10, 29, 30, 18, 19, 30  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 4: END ------------------------------------------- DebugRoom_Side_Walls -------------------------------------------------

 
 
//>-- OBJECT 5: START ------------------------------------------ DebugRoom_Front_Wall -------------------------------------------------

Vtx DebugRoom_Front_Wall_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 0:  80, 78, 95 
   { 333.63, -425.11, -2.67, 1, 0x4a55, 0x3a6a, 80, 78, 95, 255}, 
   { 0.00, -425.11, -2.67, 1, 0x303b, 0x3a6a, 80, 78, 95, 255}, 
   { 0.00, -425.11, 15.92, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
//Found a new color! Color Index: 2     Vert 0:  142, 142, 149 
//Found a new color! Color Index: 3     Vert 2:  202, 201, 206 
   { 333.63, -425.11, 15.92, 1, 0x4a55, 0x295a, 142, 142, 149, 255}, 
   { 333.63, -425.11, 60.49, 1, 0x4a55, 0x0073, 202, 201, 206, 255}, 
//Found a new color! Color Index: 4     Vert 2:  221, 221, 225 
   { 0.00, -425.11, 60.49, 1, 0x14a4, 0x3a40, 255, 255, 255, 255}, 
   { 333.63, -425.11, 563.08, 1, 0x19e0, 0x0cc5, 221, 221, 225, 255}, 
   { 354.46, -425.11, 60.49, 1, 0x1a8e, 0x3ea7, 80, 78, 95, 255}, 
   { 354.46, -425.11, -2.67, 1, 0x4bf6, 0x3a6a, 80, 78, 95, 255}, 
   { 354.46, -425.11, 15.92, 1, 0x4bf6, 0x295a, 80, 78, 95, 255}, 
   { 0.00, -425.11, 563.08, 1, 0x1456, 0x0847, 254, 254, 254, 255}, 
   { -333.63, -425.11, -2.67, 1, 0x1622, 0x3a6a, 80, 78, 95, 255}, 
//Found a new color! Color Index: 5     Vert 1:  173, 172, 180 
   { -333.63, -425.11, 15.92, 1, 0x1622, 0x295a, 142, 142, 149, 255}, 
   { -333.63, -425.11, 60.49, 1, 0x1622, 0x0073, 173, 172, 180, 255}, 
//Found a new color! Color Index: 6     Vert 1:  246, 246, 247 
   { -333.63, -425.11, 563.08, 1, 0x0e4d, 0x09bd, 246, 246, 247, 255}, 
   { -354.46, -425.11, 60.49, 1, 0x0e3a, 0x3bcd, 80, 78, 95, 255}, 
   { -354.46, -425.11, -2.67, 1, 0x1480, 0x3a6a, 80, 78, 95, 255}, 
   { -354.46, -425.11, 15.92, 1, 0x1480, 0x295a, 80, 78, 95, 255}, 
   { -487.87, -340.75, -2.67, 1, 0x508e, 0x3a6a, 80, 78, 95, 255}, 
   { -871.52, -340.75, -2.67, 1, 0x303b, 0x3a6a, 80, 78, 95, 255}, 
   { -871.52, -340.75, 15.92, 1, 0x303b, 0x295a, 173, 172, 180, 255}, 
   { -487.87, -340.75, 15.92, 1, 0x508e, 0x295a, 172, 171, 179, 255}, 
   { -487.53, -340.75, 60.49, 1, 0x508e, 0x0073, 172, 171, 179, 255}, 
   { -871.18, -340.75, 60.49, 1, 0x07bb, 0x3d60, 202, 201, 206, 255}, 
   { -487.53, -340.75, 563.08, 1, 0x0d45, 0x09fc, 172, 171, 179, 255}, 
   { -461.98, -340.75, 60.49, 1, 0x0df3, 0x3bde, 80, 78, 95, 255}, 
   { -462.32, -340.75, -2.67, 1, 0x5293, 0x3a6a, 80, 78, 95, 255}, 
   { -462.32, -340.75, 15.92, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { -871.18, -340.75, 563.08, 1, 0x076d, 0x0b67, 202, 201, 206, 255}, 
   { -896.87, -340.75, 60.49, 1, 0x0de3, 0x0073, 80, 78, 95, 255}, 
   { -897.21, -340.75, -2.67, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { 874.36, -340.50, -2.67, 1, 0x508e, 0x3a6a, 80, 78, 95, 255}, 
   { 478.09, -340.50, -2.67, 1, 0x303b, 0x3a6a, 80, 78, 95, 255}, 
   { 478.09, -340.50, 15.92, 1, 0x303b, 0x295a, 172, 171, 179, 255}, 
//Found a new color! Color Index: 7     Vert 0:  171, 170, 178 
   { 874.36, -340.50, 15.92, 1, 0x508e, 0x295a, 171, 170, 178, 255}, 
   { 874.36, -340.75, 60.49, 1, 0x508e, 0x0073, 203, 202, 207, 255}, 
   { 478.09, -340.75, 60.49, 1, 0x1b32, 0x3e7f, 172, 171, 179, 255}, 
   { 874.36, -340.75, 563.08, 1, 0x20bd, 0x0b1c, 202, 201, 206, 255}, 
   { 899.91, -340.75, 60.49, 1, 0x216b, 0x3cfd, 80, 78, 95, 255}, 
   { 899.91, -340.50, -2.67, 1, 0x5293, 0x3a6a, 80, 78, 95, 255}, 
   { 899.91, -340.50, 15.92, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { 478.09, -340.75, 563.08, 1, 0x1ae4, 0x0c86, 172, 171, 179, 255}, 
   { 452.40, -340.50, 15.92, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { 452.40, -340.50, -2.67, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { 452.40, -340.75, 60.49, 1, 0x1ad1, 0x3e96, 80, 78, 95, 255}, 
   { 354.46, -425.11, 563.08, 1, 0x1a41, 0x0cad, 173, 172, 180, 255}, 
   { 354.46, -425.11, 60.49, 1, 0x1a8e, 0x3ea7, 80, 78, 95, 255}, 
   { 333.63, -425.11, 563.08, 1, 0x19e0, 0x0cc5, 221, 221, 225, 255}, 
   { 354.46, -425.11, 60.49, 1, 0x4bf6, 0x0073, 80, 78, 95, 255}, 
   { 354.46, -425.11, 15.92, 1, 0x4bf6, 0x295a, 80, 78, 95, 255}, 
   { 333.63, -425.11, 60.49, 1, 0x4a55, 0x0073, 202, 201, 206, 255}, 
   { -354.46, -425.11, 563.08, 1, 0x0dec, 0x09d4, 80, 78, 95, 255}, 
   { -333.63, -425.11, 563.08, 1, 0x0e4d, 0x09bd, 246, 246, 247, 255}, 
   { -354.46, -425.11, 60.49, 1, 0x0e3a, 0x3bcd, 80, 78, 95, 255}, 
   { -354.46, -425.11, 60.49, 1, 0x1480, 0x0073, 80, 78, 95, 255}, 
   { -333.63, -425.11, 60.49, 1, 0x1622, 0x0073, 173, 172, 180, 255}, 
   { -354.46, -425.11, 15.92, 1, 0x1480, 0x295a, 80, 78, 95, 255}, 
   { -461.98, -340.75, 563.08, 1, 0x0da6, 0x09e5, 80, 78, 95, 255}, 
   { -461.98, -340.75, 60.49, 1, 0x0df3, 0x3bde, 80, 78, 95, 255}, 
   { -487.53, -340.75, 563.08, 1, 0x0d45, 0x09fc, 172, 171, 179, 255}, 
   { -461.98, -340.75, 60.49, 1, 0x5293, 0x0073, 80, 78, 95, 255}, 
   { -462.32, -340.75, 15.92, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { -487.53, -340.75, 60.49, 1, 0x508e, 0x0073, 172, 171, 179, 255}, 
   { -897.21, -340.75, 15.92, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { -896.87, -340.75, 60.49, 1, 0x0de3, 0x0073, 80, 78, 95, 255}, 
   { -871.52, -340.75, 15.92, 1, 0x0fe8, 0x295a, 173, 172, 180, 255}, 
   { -897.21, -340.75, -2.67, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { -896.87, -340.75, 563.08, 1, 0x070c, 0x0b7e, 80, 78, 95, 255}, 
   { -871.18, -340.75, 563.08, 1, 0x076d, 0x0b67, 202, 201, 206, 255}, 
   { 899.91, -340.75, 563.08, 1, 0x211d, 0x0b04, 80, 78, 95, 255}, 
   { 899.91, -340.75, 60.49, 1, 0x216b, 0x3cfd, 80, 78, 95, 255}, 
   { 874.36, -340.75, 563.08, 1, 0x20bd, 0x0b1c, 202, 201, 206, 255}, 
   { 899.91, -340.75, 60.49, 1, 0x5293, 0x0073, 80, 78, 95, 255}, 
   { 899.91, -340.50, 15.92, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { 874.36, -340.75, 60.49, 1, 0x508e, 0x0073, 203, 202, 207, 255}, 
   { 452.40, -340.75, 563.08, 1, 0x1a83, 0x0c9d, 80, 78, 95, 255}, 
   { 478.09, -340.75, 563.08, 1, 0x1ae4, 0x0c86, 172, 171, 179, 255}, 
   { 452.40, -340.75, 60.49, 1, 0x1ad1, 0x3e96, 80, 78, 95, 255}, 
};

void DebugRoom_Front_Wall_PolyList(u8 animFrame){ 

   Vtx *DebugRoom_Front_Wall_VTXPointer = &DebugRoom_Front_Wall_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'Xport64_TileWall_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_TileWall_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_TileWall_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 2, 4, 3  );
     gSP2Triangles(glistp++,   8, 0, 3, 8, 9, 3, 4, 9  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   4, 2, 5, 4, 2, 1, 11, 2  );
     gSP2Triangles(glistp++,   12, 13, 2, 12, 12, 11, 16, 12  );
     gSP2Triangles(glistp++,   13, 12, 17, 13, 13, 5, 2, 13  );
     gSP2Triangles(glistp++,   18, 19, 20, 18, 21, 20, 22, 21  );
     gSP2Triangles(glistp++,   26, 18, 21, 26, 27, 21, 22, 27  );
   gSPModifyVertex(glistp++,  23,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP1Triangle(glistp++,   22, 20, 23, 22  );
   gSPModifyVertex(glistp++,  23,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/   gSPModifyVertex(glistp++,  20,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/
     gSP1Triangle(glistp++,   29, 23, 20, 29  );
   gSPModifyVertex(glistp++,  19,   G_MWO_POINT_ST, 0x0fe83a6a);  /*New Coords: 127.27, 116.83*/
     gSP1Triangle(glistp++,   20, 19, 30, 20  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+30,31,0  );
     gSP1Triangle(glistp++,   1, 2, 3, 1  );
     gSP2Triangles(glistp++,   4, 3, 5, 4, 9, 1, 4, 9  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   10, 4, 5, 10, 5, 3, 6, 5  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/   gSPModifyVertex(glistp++,  2,   G_MWO_POINT_ST, 0x0fe83a6a);  /*New Coords: 127.27, 116.83*/
     gSP2Triangles(glistp++,   6, 3, 12, 6, 3, 2, 13, 3  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 8, 3, 9  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+30,31,0  );
     gSP1Triangle(glistp++,   18, 19, 20, 18  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+2,31,0  );
     gSP1Triangle(glistp++,   10, 0, 9, 10  );
     gSP1Triangle(glistp++,   15, 10, 14, 15  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+32,31,0  );
     gSP1Triangle(glistp++,   22, 23, 24, 22  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+18,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 8, 3, 9  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+48,31,0  );
     gSP2Triangles(glistp++,   12, 13, 14, 12, 15, 16, 17, 15  );
     gSP1Triangle(glistp++,   15, 17, 18, 15  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+31,31,0  );
     gSP1Triangle(glistp++,   3, 0, 2, 3  );
     gSP1Triangle(glistp++,   9, 8, 3, 9  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+61,31,0  );
     gSP1Triangle(glistp++,   11, 12, 13, 11  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+36,31,0  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x0de30073);  /*New Coords: 111.12, 0.90*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/
     gSP1Triangle(glistp++,   8, 0, 6, 8  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+33,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/
     gSP1Triangle(glistp++,   9, 0, 10, 9  );


//>-- MATERIAL 1: START ------------------------------------ 'Prim_White'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_DryWall_32x128,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_DryWall_32x128_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,255,173,150,255  );

   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x1a2e3ebe);  /*New Coords: 209.45, 125.49*/
     gSP2Triangles(glistp++,   4, 5, 6, 4, 7, 4, 6, 7  );
   gSPModifyVertex(glistp++,  13,   G_MWO_POINT_ST, 0x0e9a3bb6);  /*New Coords: 116.84, 119.43*/
     gSP2Triangles(glistp++,   6, 5, 10, 6, 13, 14, 5, 13  );
     gSP2Triangles(glistp++,   14, 13, 15, 14, 14, 10, 5, 14  );
   gSPModifyVertex(glistp++,  22,   G_MWO_POINT_ST, 0x0d933bf6);  /*New Coords: 108.61, 119.92*/
     gSP2Triangles(glistp++,   22, 23, 24, 22, 25, 22, 24, 25  );
   gSPModifyVertex(glistp++,  29,   G_MWO_POINT_ST, 0x075a3d77);  /*New Coords: 58.81, 122.94*/
     gSP2Triangles(glistp++,   24, 23, 28, 24, 28, 23, 29, 28  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+30,31,0  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x210a3d15);  /*New Coords: 264.34, 122.17*/
     gSP2Triangles(glistp++,   5, 6, 7, 5, 8, 5, 7, 8  );
     gSP2Triangles(glistp++,   7, 6, 11, 7, 11, 6, 14, 11  );
     gSP2Triangles(glistp++,   15, 16, 17, 15, 21, 22, 23, 21  );
     gSP1Triangle(glistp++,   27, 28, 29, 27  );
   gSPVertex(glistp++,  DebugRoom_Front_Wall_VTXPointer+60,31,0  );
   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x075a3d77);  /*New Coords: 58.81, 122.94*/
     gSP1Triangle(glistp++,   7, 8, 4, 7  );
     gSP2Triangles(glistp++,   9, 10, 11, 9, 15, 16, 17, 15  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 5: END ------------------------------------------- DebugRoom_Front_Wall -------------------------------------------------

 
 
//>-- OBJECT 6: START ------------------------------------------ testpillar_reflect -------------------------------------------------

Vtx testpillar_reflect_VertList_0 [] = {
   { -410.76, -312.31, -107.49, 1, 0x1092, 0x2829, 255, 255, 255, 255}, 
   { -411.74, -309.68, -3.04, 1, 0x1092, 0x485e, 255, 255, 255, 255}, 
   { -351.74, -309.68, -3.04, 1, 0x0c9b, 0x485e, 255, 255, 255, 255}, 
   { -350.76, -372.31, -107.50, 1, 0x08a3, 0x282e, 255, 255, 255, 255}, 
   { -351.74, -369.68, -3.04, 1, 0x08a3, 0x485e, 255, 255, 255, 255}, 
   { -351.74, -450.44, -3.04, 1, 0x04ab, 0x485e, 255, 255, 255, 255}, 
   { -350.76, -312.31, -107.50, 1, 0x0c9b, 0x2829, 255, 255, 255, 255}, 
   { -470.76, -312.31, -107.48, 1, 0x148a, 0x282a, 255, 255, 255, 255}, 
   { -471.74, -309.68, -3.04, 1, 0x148a, 0x485e, 255, 255, 255, 255}, 
   { -470.76, -346.90, -107.52, 1, 0x16d4, 0x2825, 255, 255, 255, 255}, 
   { -471.74, -344.26, -3.04, 1, 0x16d4, 0x485e, 255, 255, 255, 255}, 
   { 347.82, -312.31, -109.34, 1, 0x0c9b, 0x27e7, 255, 255, 255, 255}, 
   { 346.84, -309.68, -3.46, 1, 0x0c9b, 0x47d9, 255, 255, 255, 255}, 
   { 406.84, -309.68, -3.46, 1, 0x1092, 0x47d9, 255, 255, 255, 255}, 
   { 347.82, -372.31, -109.34, 1, 0x08a3, 0x27e7, 255, 255, 255, 255}, 
   { 347.82, -453.08, -109.34, 1, 0x04ab, 0x27e7, 255, 255, 255, 255}, 
   { 346.84, -450.44, -3.46, 1, 0x04ab, 0x47d9, 255, 255, 255, 255}, 
   { 346.84, -369.68, -3.46, 1, 0x08a3, 0x47d9, 255, 255, 255, 255}, 
   { 407.82, -312.31, -109.34, 1, 0x1092, 0x27ec, 255, 255, 255, 255}, 
   { 466.84, -309.68, -3.46, 1, 0x148a, 0x47d9, 255, 255, 255, 255}, 
   { 467.82, -312.31, -109.33, 1, 0x148a, 0x27f1, 255, 255, 255, 255}, 
   { 466.84, -344.26, -3.46, 1, 0x16d4, 0x47d9, 255, 255, 255, 255}, 
//Found a new color! Color Index: 1     Vert 1:  253, 253, 253 
   { -892.73, 396.67, -2.92, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { -892.73, 39.30, -2.92, 1, 0x303b, 0x3a6a, 253, 253, 253, 253}, 
   { -892.73, 39.30, -21.51, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { -892.73, 396.67, -21.51, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { -892.73, 396.67, -66.09, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
//Found a new color! Color Index: 2     Vert 2:  3, 3, 4 
   { -892.73, 39.30, -66.09, 1, 0x14a4, 0x3a40, 255, 255, 255, 255}, 
   { -924.94, 408.13, -261.18, 1, 0x19e0, 0x0cc5, 3, 3, 4, 3}, 
   { -892.73, 418.66, -66.09, 1, 0x1a8e, 0x3ea7, 253, 253, 254, 253}, 
   { -892.73, 418.66, -2.92, 1, 0x5293, 0x3a6a, 255, 255, 255, 255}, 
   { -892.73, 418.66, -21.51, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
//Found a new color! Color Index: 3     Vert 2:  0, 0, 0 
   { -924.94, 38.05, -261.18, 1, 0x1456, 0x0847, 0, 0, 0, 0}, 
   { -892.73, -311.06, -2.92, 1, 0x0fe8, 0x3a6a, 255, 255, 255, 255}, 
   { -892.73, -311.06, -21.51, 1, 0x0fe8, 0x295a, 255, 255, 255, 255}, 
   { -892.73, -311.06, -66.09, 1, 0x0fe8, 0x0073, 254, 254, 254, 254}, 
   { -924.94, -325.02, -261.18, 1, 0x0e4d, 0x09bd, 0, 0, 0, 0}, 
   { -892.73, -346.58, -66.09, 1, 0x0e3a, 0x3bcd, 255, 255, 255, 255}, 
   { -892.73, -346.58, -2.92, 1, 0x0de3, 0x3a6a, 255, 255, 255, 255}, 
   { -892.73, -346.58, -21.51, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { 892.73, 39.30, -21.51, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { 892.73, 39.30, -2.92, 1, 0x303b, 0x3a6a, 255, 255, 255, 255}, 
   { 892.73, 396.67, -2.92, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { 892.73, 396.67, -21.51, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 892.73, 396.67, -66.09, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { 924.96, 408.13, -261.18, 1, 0x19e0, 0x0cc5, 0, 0, 0, 0}, 
   { 892.73, 39.30, -66.09, 1, 0x14a4, 0x3a40, 255, 255, 255, 255}, 
   { 892.73, 418.66, -66.09, 1, 0x1a8e, 0x3ea7, 255, 255, 255, 255}, 
   { 892.73, 418.66, -2.92, 1, 0x5293, 0x3a6a, 255, 255, 255, 255}, 
   { 892.73, 418.66, -21.51, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { 924.96, 38.05, -261.18, 1, 0x1456, 0x0847, 0, 0, 0, 0}, 
   { 892.73, -311.06, -2.92, 1, 0x0fe8, 0x3a6a, 255, 255, 255, 255}, 
   { 892.73, -311.06, -21.51, 1, 0x0fe8, 0x295a, 255, 255, 255, 255}, 
   { 892.73, -311.06, -66.09, 1, 0x0fe8, 0x0073, 255, 255, 255, 255}, 
   { 924.96, -325.02, -261.18, 1, 0x0e4d, 0x09bd, 0, 0, 0, 0}, 
   { 892.73, -347.08, -66.09, 1, 0x0e3a, 0x3bcd, 255, 255, 255, 255}, 
   { 892.73, -347.08, -2.92, 1, 0x0de3, 0x3a6a, 255, 255, 255, 255}, 
   { 892.73, -347.08, -21.51, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { 0.00, -429.68, -21.27, 1, 0x1998, 0x0870, 255, 255, 255, 255}, 
   { 0.00, -429.68, -2.68, 1, 0x1998, 0x0665, 255, 255, 255, 255}, 
   { 326.60, -429.68, -3.46, 1, 0x106e, 0x0665, 255, 255, 255, 255}, 
   { 326.60, -429.68, -22.05, 1, 0x106e, 0x0870, 255, 255, 255, 255}, 
   { 326.60, -429.68, -66.62, 1, 0x106e, 0x0d55, 255, 255, 255, 255}, 
   { 328.96, -436.27, -268.34, 1, 0x106e, 0x448c, 0, 0, 0, 0}, 
   { 0.00, -429.68, -65.85, 1, 0x1998, 0x0d55, 255, 255, 255, 255}, 
   { 357.13, -429.68, -66.62, 1, 0x0fdb, 0x0d55, 255, 255, 255, 255}, 
   { 357.13, -429.68, -3.46, 1, 0x0fdb, 0x0665, 255, 255, 255, 255}, 
   { 357.13, -429.68, -22.05, 1, 0x0fdb, 0x0870, 255, 255, 255, 255}, 
//Found a new color! Color Index: 4     Vert 1:  17, 17, 17 
   { 3.41, -436.27, -268.34, 1, 0x1998, 0x448c, 17, 17, 17, 17}, 
   { -331.49, -429.68, -3.04, 1, 0x22c1, 0x0665, 255, 255, 255, 255}, 
   { -331.49, -429.68, -21.63, 1, 0x22c1, 0x0870, 255, 255, 255, 255}, 
   { -331.49, -429.68, -66.20, 1, 0x22c1, 0x0d55, 255, 255, 255, 255}, 
   { -328.96, -436.27, -264.35, 1, 0x22c1, 0x448c, 0, 0, 0, 0}, 
   { -359.54, -436.27, -264.35, 1, 0x2354, 0x448c, 0, 0, 0, 0}, 
   { -362.06, -429.68, -66.20, 1, 0x2354, 0x0d55, 255, 255, 255, 255}, 
   { -362.06, -429.68, -3.04, 1, 0x2354, 0x0665, 255, 255, 255, 255}, 
   { -362.06, -429.68, -21.63, 1, 0x2354, 0x0870, 255, 255, 255, 255}, 
   { -871.52, -345.69, -21.27, 1, 0x3187, 0x0870, 255, 255, 255, 255}, 
   { -871.52, -345.69, -2.68, 1, 0x3187, 0x0665, 255, 255, 255, 255}, 
   { -487.87, -345.69, -2.68, 1, 0x26fe, 0x0665, 255, 255, 255, 255}, 
   { -487.87, -345.69, -21.27, 1, 0x26fe, 0x0870, 255, 255, 255, 255}, 
   { -487.53, -345.69, -65.85, 1, 0x26fb, 0x0d55, 255, 255, 255, 255}, 
   { -495.76, -350.86, -264.40, 1, 0x26fb, 0x448c, 0, 0, 0, 0}, 
   { -871.18, -345.69, -65.85, 1, 0x3185, 0x0d55, 255, 255, 255, 255}, 
   { -469.29, -350.86, -264.40, 1, 0x2648, 0x448c, 0, 0, 0, 0}, 
   { -462.32, -345.69, -2.68, 1, 0x264a, 0x0665, 255, 255, 255, 255}, 
   { -461.98, -345.69, -65.85, 1, 0x2648, 0x0d55, 255, 255, 255, 255}, 
   { -893.26, -350.86, -264.40, 1, 0x3185, 0x448c, 0, 0, 0, 0}, 
   { -907.64, -345.69, -65.85, 1, 0x3239, 0x0d55, 255, 255, 255, 255}, 
   { -907.98, -345.69, -21.27, 1, 0x323c, 0x0870, 255, 255, 255, 255}, 
   { -907.98, -345.69, -2.68, 1, 0x323c, 0x0665, 255, 255, 255, 255}, 
   { 478.09, -340.56, -21.27, 1, 0x0c76, 0x0870, 255, 255, 255, 255}, 
   { 478.09, -340.56, -2.68, 1, 0x0c76, 0x0665, 255, 255, 255, 255}, 
   { 874.36, -340.56, -2.68, 1, 0x0194, 0x0665, 255, 255, 255, 255}, 
   { 874.36, -340.56, -21.27, 1, 0x0194, 0x0870, 255, 255, 255, 255}, 
   { 874.36, -340.81, -65.85, 1, 0x0194, 0x0d55, 255, 255, 255, 255}, 
   { 905.93, -355.55, -256.15, 1, 0x0194, 0x448c, 0, 0, 0, 0}, 
   { 478.09, -340.81, -65.85, 1, 0x0c76, 0x0d55, 255, 255, 255, 255}, 
   { 899.91, -340.81, -65.85, 1, 0x00e0, 0x0d55, 255, 255, 255, 255}, 
   { 899.91, -340.56, -2.68, 1, 0x00e0, 0x0665, 255, 255, 255, 255}, 
   { 899.91, -340.56, -21.27, 1, 0x00e0, 0x0870, 255, 255, 255, 255}, 
   { 495.35, -355.55, -256.15, 1, 0x0c76, 0x448c, 0, 0, 0, 0}, 
   { 452.40, -340.56, -21.27, 1, 0x0d2b, 0x0870, 255, 255, 255, 255}, 
   { 452.40, -340.56, -2.68, 1, 0x0d2b, 0x0665, 255, 255, 255, 255}, 
   { 468.74, -355.55, -256.15, 1, 0x0d2b, 0x448c, 0, 0, 0, 0}, 
   { 452.40, -340.81, -65.85, 1, 0x0d2b, 0x0d55, 255, 255, 255, 255}, 
   { -434.19, 122.85, -22.05, 1, 0x168e, 0x2bc9, 255, 255, 255, 255}, 
   { -456.93, 122.85, -22.05, 1, 0x1510, 0x2bc9, 255, 255, 255, 255}, 
   { -456.93, 122.85, -66.62, 1, 0x1510, 0x0004, 255, 255, 255, 255}, 
//Found a new color! Color Index: 5     Vert 2:  241, 241, 241 
   { -434.19, 398.64, -22.05, 1, 0x2851, 0x2bc9, 255, 255, 255, 255}, 
   { -434.19, 398.64, -66.62, 1, 0x2851, 0x0004, 241, 241, 241, 241}, 
   { -456.93, 398.60, -22.05, 1, 0x034d, 0x2bc9, 255, 255, 255, 255}, 
   { -456.93, 419.85, -22.05, 1, 0x019f, 0x2bc9, 255, 255, 255, 255}, 
   { -456.93, 419.85, -66.62, 1, 0x019f, 0x0004, 255, 255, 255, 255}, 
//Found a new color! Color Index: 6     Vert 1:  230, 230, 232 
   { -473.41, 408.98, -266.40, 1, 0x0cd9, 0x396d, 0, 0, 0, 0}, 
   { -456.93, 398.51, -66.62, 1, 0x0cdf, 0x038b, 230, 230, 232, 230}, 
   { -434.19, 122.85, -66.62, 1, 0x06f2, 0x038b, 255, 255, 255, 255}, 
   { -449.85, 410.18, -266.40, 1, 0x0105, 0x396d, 0, 0, 0, 0}, 
   { -449.85, 126.12, -266.40, 1, 0x0d6f, 0x396d, 0, 0, 0, 0}, 
   { -434.20, 419.85, -66.62, 1, 0x0076, 0x038b, 255, 255, 255, 255}, 
   { -434.19, 419.84, -22.05, 1, 0x29fe, 0x2bc9, 255, 255, 255, 255}, 
   { -473.41, 126.12, -266.40, 1, 0x06f2, 0x396d, 0, 0, 0, 0}, 
//Found a new color! Color Index: 7     Vert 2:  228, 228, 230 
   { 456.93, 122.85, -66.62, 1, 0x1510, 0x0004, 255, 255, 255, 255}, 
   { 456.93, 122.85, -22.05, 1, 0x1510, 0x2bc9, 255, 255, 255, 255}, 
   { 434.19, 122.85, -22.05, 1, 0x168e, 0x2bc9, 255, 255, 255, 255}, 
   { 434.19, 398.64, -22.05, 1, 0x2851, 0x2bc9, 255, 255, 255, 255}, 
   { 434.19, 398.64, -66.62, 1, 0x2851, 0x0004, 255, 255, 255, 255}, 
   { 456.93, 419.87, -66.62, 1, 0x019f, 0x0004, 255, 255, 255, 255}, 
   { 456.93, 419.84, -22.05, 1, 0x019f, 0x2bc9, 255, 255, 255, 255}, 
   { 456.93, 398.60, -22.05, 1, 0x034d, 0x2bc9, 255, 255, 255, 255}, 
   { 449.87, 410.18, -266.40, 1, 0x0105, 0x396d, 0, 0, 0, 0}, 
   { 434.19, 122.85, -66.62, 1, 0x06f2, 0x038b, 255, 255, 255, 255}, 
   { 449.87, 126.12, -266.40, 1, 0x0d6f, 0x396d, 0, 0, 0, 0}, 
   { 473.43, 126.12, -266.40, 1, 0x0dee, 0x396d, 0, 0, 0, 0}, 
   { 434.19, 419.84, -22.05, 1, 0x29fe, 0x2bc9, 255, 255, 255, 255}, 
   { 456.93, 398.51, -66.62, 1, 0x034f, 0x0004, 255, 255, 255, 255}, 
   { 473.43, 408.98, -266.40, 1, 0x0cd9, 0x396d, 0, 0, 0, 0}, 
   { 409.21, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { 0.00, 419.87, -3.46, 1, 0x303b, 0x3a6a, 255, 255, 255, 255}, 
   { 0.00, 419.87, -22.05, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { 409.21, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 409.21, 419.87, -66.62, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { 0.00, 419.87, -66.62, 1, 0x14a4, 0x3a40, 255, 255, 255, 255}, 
   { 423.99, 432.17, -266.40, 1, 0x19e0, 0x0cc5, 0, 0, 0, 0}, 
   { 478.09, 419.87, -66.62, 1, 0x0fe8, 0x0073, 255, 255, 255, 255}, 
   { 478.09, 419.87, -22.05, 1, 0x0fe8, 0x295a, 255, 255, 255, 255}, 
   { 0.01, 432.17, -266.40, 1, 0x1456, 0x0847, 0, 0, 0, 0}, 
   { -409.21, 419.87, -3.46, 1, 0x0fe8, 0x3a6a, 255, 255, 255, 255}, 
   { -409.21, 419.87, -22.05, 1, 0x0fe8, 0x295a, 255, 255, 255, 255}, 
   { -409.21, 419.87, -66.62, 1, 0x0fe8, 0x0073, 255, 255, 255, 255}, 
//Found a new color! Color Index: 8     Vert 1:  10, 10, 12 
   { -423.96, 432.17, -266.40, 1, 0x0e4d, 0x09bd, 10, 10, 12, 10}, 
   { -434.20, 419.85, -66.62, 1, 0x0e3a, 0x3bcd, 255, 255, 255, 255}, 
   { -456.93, 419.85, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { -478.97, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { -478.97, 419.87, -66.62, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { -478.97, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { -875.24, 419.87, -3.46, 1, 0x303b, 0x3a6a, 255, 255, 255, 255}, 
   { -875.24, 419.87, -22.05, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
//Found a new color! Color Index: 9     Vert 2:  2, 2, 2 
   { -875.24, 419.87, -66.62, 1, 0x07bb, 0x3d60, 255, 255, 255, 255}, 
   { -496.24, 432.17, -266.40, 1, 0x0d45, 0x09fc, 2, 2, 2, 2}, 
   { -473.40, 432.16, -266.40, 1, 0x0da6, 0x09e5, 0, 0, 0, 0}, 
   { -456.93, 419.85, -66.62, 1, 0x0df3, 0x3bde, 255, 255, 255, 255}, 
   { -906.82, 432.17, -266.40, 1, 0x076d, 0x0b67, 0, 0, 0, 0}, 
   { -900.93, 419.87, -22.05, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { -900.93, 419.87, -3.46, 1, 0x0de3, 0x3a6a, 255, 255, 255, 255}, 
   { -900.93, 419.87, -66.62, 1, 0x075a, 0x3d77, 255, 255, 255, 255}, 
   { 874.36, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { 478.09, 419.87, -3.46, 1, 0x303b, 0x3a6a, 255, 255, 255, 255}, 
   { 874.36, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 874.36, 419.87, -66.62, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { 905.93, 432.17, -266.40, 1, 0x20bd, 0x0b1c, 0, 0, 0, 0}, 
   { 899.91, 419.87, -66.62, 1, 0x216b, 0x3cfd, 255, 255, 255, 255}, 
   { 899.91, 419.87, -3.46, 1, 0x5293, 0x3a6a, 255, 255, 255, 255}, 
   { 899.91, 419.87, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { 905.93, 432.17, -266.40, 1, 0x20bd, 0x0b1c, 0, 0, 0, 0}, 
   { 478.09, 419.87, -66.62, 1, 0x1b32, 0x3e7f, 255, 255, 255, 255}, 
   { 495.35, 432.17, -266.40, 1, 0x1ae4, 0x0c86, 0, 0, 0, 0}, 
   { 874.36, 419.87, -66.62, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { 478.09, 419.87, -22.05, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { 478.09, 419.87, -66.62, 1, 0x303b, 0x0073, 255, 255, 255, 255}, 
   { 434.19, 419.84, -66.62, 1, 0x5293, 0x0073, 255, 255, 255, 255}, 
   { 434.19, 419.84, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { 409.21, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 434.19, 419.84, -3.46, 1, 0x5293, 0x3a6a, 255, 255, 255, 255}, 
   { 409.21, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { -434.19, 398.64, -22.05, 1, 0x2851, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 398.64, -3.46, 1, 0x2851, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 122.85, -3.46, 1, 0x168e, 0x33c9, 255, 255, 255, 255}, 
   { 456.93, 398.60, -22.05, 1, 0x0345, 0x29c9, 255, 255, 255, 255}, 
   { 456.93, 398.60, -3.46, 1, 0x034d, 0x33c9, 255, 255, 255, 255}, 
   { 456.93, 122.85, -3.46, 1, 0x1510, 0x33c9, 255, 255, 255, 255}, 
   { 456.93, 122.85, -22.05, 1, 0x1508, 0x29c9, 255, 255, 255, 255}, 
   { 434.19, 122.85, -3.46, 1, 0x168e, 0x33c9, 255, 255, 255, 255}, 
//Found a new color! Color Index: 10     Vert 2:  225, 224, 229 
   { -456.93, 122.85, -22.05, 1, 0x1510, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 122.85, -3.46, 1, 0x1510, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 398.60, -3.46, 1, 0x034d, 0x33c9, 225, 224, 229, 226}, 
   { 434.19, 122.85, -22.05, 1, 0x1686, 0x29c9, 255, 255, 255, 255}, 
   { 434.19, 398.64, -3.46, 1, 0x2851, 0x33c9, 255, 255, 255, 255}, 
   { 434.19, 398.64, -22.05, 1, 0x2849, 0x29c9, 255, 255, 255, 255}, 
   { -456.93, 398.60, -22.05, 1, 0x034d, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 419.84, -3.46, 1, 0x019f, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 122.85, -22.05, 1, 0x168e, 0x33c9, 255, 255, 255, 255}, 
   { 449.87, 410.18, -266.40, 1, 0x0105, 0x396d, 0, 0, 0, 0}, 
   { 434.19, 398.64, -66.62, 1, 0x0105, 0x038b, 255, 255, 255, 255}, 
   { 434.19, 419.84, -66.62, 1, 0x0076, 0x038b, 255, 255, 255, 255}, 
   { 473.43, 408.98, -266.40, 1, 0x0cd9, 0x396d, 0, 0, 0, 0}, 
   { 473.43, 432.16, -266.40, 1, 0x0d6f, 0x396d, 0, 0, 0, 0}, 
   { 456.93, 419.87, -66.62, 1, 0x0d6f, 0x038b, 255, 255, 255, 255}, 
   { -456.93, 419.85, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { -456.93, 419.87, -3.46, 1, 0x5293, 0x3a6a, 255, 255, 255, 255}, 
   { -478.97, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { -434.19, 419.84, -22.05, 1, 0x29fe, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 419.84, -3.46, 1, 0x29fe, 0x33c9, 255, 255, 255, 255}, 
   { 434.19, 419.84, -66.62, 1, 0x1a8e, 0x3ea7, 255, 255, 255, 255}, 
   { 409.21, 419.87, -66.62, 1, 0x1a2e, 0x3ebe, 255, 255, 255, 255}, 
   { 423.99, 432.17, -266.40, 1, 0x19e0, 0x0cc5, 0, 0, 0, 0}, 
   { 456.93, 419.84, -22.05, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { 478.09, 419.87, -22.05, 1, 0x0fe8, 0x295a, 255, 255, 255, 255}, 
   { 478.09, 419.87, -3.46, 1, 0x0fe8, 0x3a6a, 255, 255, 255, 255}, 
   { 456.93, 419.84, -22.05, 1, 0x0197, 0x29c9, 255, 255, 255, 255}, 
   { 456.93, 419.84, -3.46, 1, 0x019f, 0x33c9, 255, 255, 255, 255}, 
   { 456.93, 398.60, -3.46, 1, 0x034d, 0x33c9, 255, 255, 255, 255}, 
   { 473.43, 432.16, -266.40, 1, 0x1a83, 0x0c9d, 0, 0, 0, 0}, 
   { 495.35, 432.17, -266.40, 1, 0x1ae4, 0x0c86, 0, 0, 0, 0}, 
   { 478.09, 419.87, -66.62, 1, 0x1b32, 0x3e7f, 255, 255, 255, 255}, 
   { 469.29, -316.27, -268.31, 1, 0x148a, 0x080a, 0, 0, 0, 0}, 
   { 467.82, -312.31, -109.33, 1, 0x148a, 0x27f1, 255, 255, 255, 255}, 
   { 467.82, -346.90, -109.37, 1, 0x16d4, 0x27e2, 255, 255, 255, 255}, 
   { 409.29, -316.27, -268.32, 1, 0x1092, 0x0800, 0, 0, 0, 0}, 
   { 407.82, -312.31, -109.34, 1, 0x1092, 0x27ec, 255, 255, 255, 255}, 
   { 349.29, -316.27, -268.34, 1, 0x0c9b, 0x07f5, 0, 0, 0, 0}, 
   { 349.29, -376.27, -268.34, 1, 0x08a3, 0x07f5, 0, 0, 0, 0}, 
   { 347.82, -372.31, -109.34, 1, 0x08a3, 0x27e7, 255, 255, 255, 255}, 
   { 349.29, -457.03, -268.34, 1, 0x04ab, 0x07f5, 0, 0, 0, 0}, 
   { 347.82, -453.08, -109.34, 1, 0x04ab, 0x27e7, 255, 255, 255, 255}, 
   { 347.82, -312.31, -109.34, 1, 0x0c9b, 0x27e7, 255, 255, 255, 255}, 
   { -469.29, -316.27, -264.32, 1, 0x148a, 0x07f6, 0, 0, 0, 0}, 
   { -469.29, -350.86, -264.40, 1, 0x16d4, 0x07ed, 0, 0, 0, 0}, 
   { -470.76, -346.90, -107.52, 1, 0x16d4, 0x2825, 255, 255, 255, 255}, 
   { -469.29, -316.27, -264.32, 1, 0x148a, 0x07f6, 0, 0, 0, 0}, 
   { -470.76, -312.31, -107.48, 1, 0x148a, 0x282a, 255, 255, 255, 255}, 
   { -410.76, -312.31, -107.49, 1, 0x1092, 0x2829, 255, 255, 255, 255}, 
   { -349.29, -316.27, -264.35, 1, 0x0c9b, 0x07f5, 0, 0, 0, 0}, 
   { -350.76, -312.31, -107.50, 1, 0x0c9b, 0x2829, 255, 255, 255, 255}, 
   { -350.76, -372.31, -107.50, 1, 0x08a3, 0x282e, 255, 255, 255, 255}, 
   { -349.29, -376.27, -264.35, 1, 0x08a3, 0x07fe, 0, 0, 0, 0}, 
   { -350.76, -453.08, -107.50, 1, 0x04ab, 0x282e, 255, 255, 255, 255}, 
   { -409.29, -316.27, -264.33, 1, 0x1092, 0x07f5, 0, 0, 0, 0}, 
   { -470.76, -434.69, -107.52, 1, 0x16d4, 0x2825, 255, 255, 255, 255}, 
   { -471.74, -432.06, -3.04, 1, 0x16d4, 0x485e, 255, 255, 255, 255}, 
   { 469.29, -350.86, -268.39, 1, 0x16d4, 0x07ec, 0, 0, 0, 0}, 
   { 467.82, -434.69, -109.37, 1, 0x16d4, 0x27e2, 255, 255, 255, 255}, 
   { 466.84, -344.26, -3.46, 1, 0x16d4, 0x47d9, 255, 255, 255, 255}, 
   { 466.84, -432.06, -3.46, 1, 0x16d4, 0x47d9, 255, 255, 255, 255}, 
   { -469.29, -438.65, -264.40, 1, 0x16d4, 0x07ed, 0, 0, 0, 0}, 
   { 469.29, -438.65, -268.39, 1, 0x003b, 0x208e, 0, 0, 0, 0}, 
   { -349.29, -457.03, -264.35, 1, 0x03f5, 0x4061, 0, 0, 0, 0}, 
   { -351.74, -450.44, -3.04, 1, 0x03e2, 0x2092, 255, 255, 255, 255}, 
   { -351.74, -309.68, -3.04, 1, 0x0c9b, 0x485e, 255, 255, 255, 255}, 
   { -351.74, -369.68, -3.04, 1, 0x08a3, 0x485e, 255, 255, 255, 255}, 
   { -411.74, -309.68, -3.04, 1, 0x1092, 0x485e, 255, 255, 255, 255}, 
   { -471.74, -309.68, -3.04, 1, 0x148a, 0x485e, 255, 255, 255, 255}, 
   { -470.76, -312.31, -107.48, 1, 0x148a, 0x282a, 255, 255, 255, 255}, 
   { -471.74, -344.26, -3.04, 1, 0x16d4, 0x485e, 255, 255, 255, 255}, 
   { 407.82, -312.31, -109.34, 1, 0x1092, 0x27ec, 255, 255, 255, 255}, 
   { 347.82, -312.31, -109.34, 1, 0x0c9b, 0x27e7, 255, 255, 255, 255}, 
   { 406.84, -309.68, -3.46, 1, 0x1092, 0x47d9, 255, 255, 255, 255}, 
   { 346.84, -369.68, -3.46, 1, 0x08a3, 0x47d9, 255, 255, 255, 255}, 
   { 347.82, -372.31, -109.34, 1, 0x08a3, 0x27e7, 255, 255, 255, 255}, 
   { 346.84, -450.44, -3.46, 1, 0x04ab, 0x47d9, 255, 255, 255, 255}, 
   { 346.84, -309.68, -3.46, 1, 0x0c9b, 0x47d9, 255, 255, 255, 255}, 
   { 467.82, -312.31, -109.33, 1, 0x148a, 0x27f1, 255, 255, 255, 255}, 
   { 407.82, -312.31, -109.34, 1, 0x1092, 0x27ec, 255, 255, 255, 255}, 
   { 466.84, -309.68, -3.46, 1, 0x148a, 0x47d9, 255, 255, 255, 255}, 
   { 467.82, -346.90, -109.37, 1, 0x16d4, 0x27e2, 255, 255, 255, 255}, 
//Found a new color! Color Index: 11     Vert 0:  13, 13, 16 
   { -924.94, 430.92, -261.18, 1, 0x1a41, 0x0cad, 13, 13, 16, 14}, 
   { -892.73, 418.66, -66.09, 1, 0x1a8e, 0x3ea7, 253, 253, 254, 253}, 
   { -924.94, 408.13, -261.18, 1, 0x19e0, 0x0cc5, 3, 3, 4, 3}, 
   { -892.73, 418.66, -66.09, 1, 0x5293, 0x0073, 253, 253, 254, 253}, 
   { -892.73, 418.66, -21.51, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { -892.73, 396.67, -66.09, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { -924.94, -361.33, -261.18, 1, 0x0dec, 0x09d4, 0, 0, 0, 0}, 
   { -924.94, -325.02, -261.18, 1, 0x0e4d, 0x09bd, 0, 0, 0, 0}, 
   { -892.73, -346.58, -66.09, 1, 0x0e3a, 0x3bcd, 255, 255, 255, 255}, 
   { -892.73, -346.58, -66.09, 1, 0x0de3, 0x0073, 255, 255, 255, 255}, 
   { -892.73, -311.06, -66.09, 1, 0x0fe8, 0x0073, 254, 254, 254, 254}, 
   { -892.73, -346.58, -21.51, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { 924.96, 430.92, -261.18, 1, 0x1a41, 0x0cad, 0, 0, 0, 0}, 
   { 924.96, 408.13, -261.18, 1, 0x19e0, 0x0cc5, 0, 0, 0, 0}, 
   { 892.73, 418.66, -66.09, 1, 0x1a8e, 0x3ea7, 255, 255, 255, 255}, 
   { 892.73, 418.66, -66.09, 1, 0x5293, 0x0073, 255, 255, 255, 255}, 
   { 892.73, 396.67, -66.09, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { 892.73, 418.66, -21.51, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { 924.96, -361.84, -261.18, 1, 0x0dec, 0x09d4, 0, 0, 0, 0}, 
   { 892.73, -347.08, -66.09, 1, 0x0e3a, 0x3bcd, 255, 255, 255, 255}, 
   { 924.96, -325.02, -261.18, 1, 0x0e4d, 0x09bd, 0, 0, 0, 0}, 
   { 892.73, -347.08, -66.09, 1, 0x0de3, 0x0073, 255, 255, 255, 255}, 
   { 892.73, -347.08, -21.51, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { 892.73, -311.06, -66.09, 1, 0x0fe8, 0x0073, 255, 255, 255, 255}, 
//Found a new color! Color Index: 12     Vert 0:  4, 4, 4 
   { 359.65, -436.27, -268.34, 1, 0x0fdb, 0x448c, 4, 4, 4, 4}, 
   { 328.96, -436.27, -268.34, 1, 0x106e, 0x448c, 0, 0, 0, 0}, 
   { 357.13, -429.68, -66.62, 1, 0x0fdb, 0x0d55, 255, 255, 255, 255}, 
   { 357.13, -429.68, -66.62, 1, 0x0fdb, 0x0d55, 255, 255, 255, 255}, 
   { 326.60, -429.68, -66.62, 1, 0x106e, 0x0d55, 255, 255, 255, 255}, 
   { 357.13, -429.68, -22.05, 1, 0x0fdb, 0x0870, 255, 255, 255, 255}, 
   { -461.98, -345.69, -65.85, 1, 0x2648, 0x0d55, 255, 255, 255, 255}, 
   { -469.29, -350.86, -264.40, 1, 0x2648, 0x448c, 0, 0, 0, 0}, 
   { -487.53, -345.69, -65.85, 1, 0x26fb, 0x0d55, 255, 255, 255, 255}, 
   { -452.97, -336.12, -29.53, 1, 0x264a, 0x0870, 255, 255, 255, 255}, 
   { -487.87, -345.69, -21.27, 1, 0x26fe, 0x0870, 255, 255, 255, 255}, 
   { -462.32, -345.69, -2.68, 1, 0x264a, 0x0665, 255, 255, 255, 255}, 
   { -930.64, -350.86, -264.40, 1, 0x3239, 0x448c, 0, 0, 0, 0}, 
   { -907.64, -345.69, -65.85, 1, 0x3239, 0x0d55, 255, 255, 255, 255}, 
   { -893.26, -350.86, -264.40, 1, 0x3185, 0x448c, 0, 0, 0, 0}, 
   { 932.40, -355.55, -256.15, 1, 0x00e0, 0x448c, 0, 0, 0, 0}, 
   { 905.93, -355.55, -256.15, 1, 0x0194, 0x448c, 0, 0, 0, 0}, 
   { 899.91, -340.81, -65.85, 1, 0x00e0, 0x0d55, 255, 255, 255, 255}, 
   { 899.91, -340.81, -65.85, 1, 0x00e0, 0x0d55, 255, 255, 255, 255}, 
   { 874.36, -340.81, -65.85, 1, 0x0194, 0x0d55, 255, 255, 255, 255}, 
   { 899.91, -340.56, -21.27, 1, 0x00e0, 0x0870, 255, 255, 255, 255}, 
   { -434.19, 122.85, -66.62, 1, 0x168e, 0x0004, 255, 255, 255, 255}, 
   { -434.19, 122.85, -22.05, 1, 0x168e, 0x2bc9, 255, 255, 255, 255}, 
   { -456.93, 122.85, -66.62, 1, 0x1510, 0x0004, 255, 255, 255, 255}, 
   { -456.93, 398.51, -66.62, 1, 0x034f, 0x0004, 230, 230, 232, 230}, 
   { -456.93, 398.60, -22.05, 1, 0x034d, 0x2bc9, 255, 255, 255, 255}, 
   { -456.93, 419.85, -66.62, 1, 0x019f, 0x0004, 255, 255, 255, 255}, 
   { -473.40, 432.16, -266.40, 1, 0x0d6f, 0x396d, 0, 0, 0, 0}, 
   { -473.41, 408.98, -266.40, 1, 0x0cd9, 0x396d, 0, 0, 0, 0}, 
   { -456.93, 419.85, -66.62, 1, 0x0d6f, 0x038b, 255, 255, 255, 255}, 
   { -473.41, 126.12, -266.40, 1, 0x0dee, 0x396d, 0, 0, 0, 0}, 
   { -449.85, 126.12, -266.40, 1, 0x0d6f, 0x396d, 0, 0, 0, 0}, 
   { -456.93, 122.85, -66.62, 1, 0x0dee, 0x038b, 255, 255, 255, 255}, 
   { -449.86, 432.16, -266.40, 1, 0x0076, 0x396d, 0, 0, 0, 0}, 
   { -434.20, 419.85, -66.62, 1, 0x0076, 0x038b, 255, 255, 255, 255}, 
   { -449.85, 410.18, -266.40, 1, 0x0105, 0x396d, 0, 0, 0, 0}, 
   { -434.20, 419.85, -66.62, 1, 0x29fe, 0x0004, 255, 255, 255, 255}, 
   { -434.19, 419.84, -22.05, 1, 0x29fe, 0x2bc9, 255, 255, 255, 255}, 
   { -434.19, 398.64, -66.62, 1, 0x2851, 0x0004, 241, 241, 241, 241}, 
   { 434.19, 122.85, -66.62, 1, 0x168e, 0x0004, 255, 255, 255, 255}, 
   { 456.93, 122.85, -66.62, 1, 0x1510, 0x0004, 255, 255, 255, 255}, 
   { 434.19, 122.85, -22.05, 1, 0x168e, 0x2bc9, 255, 255, 255, 255}, 
   { 456.93, 398.51, -66.62, 1, 0x034f, 0x0004, 255, 255, 255, 255}, 
   { 456.93, 419.87, -66.62, 1, 0x019f, 0x0004, 255, 255, 255, 255}, 
   { 456.93, 398.60, -22.05, 1, 0x034d, 0x2bc9, 255, 255, 255, 255}, 
   { 449.87, 126.12, -266.40, 1, 0x0d6f, 0x396d, 0, 0, 0, 0}, 
   { 434.19, 419.84, -66.62, 1, 0x29fe, 0x0004, 255, 255, 255, 255}, 
   { 434.19, 398.64, -66.62, 1, 0x2851, 0x0004, 255, 255, 255, 255}, 
   { 434.19, 419.84, -22.05, 1, 0x29fe, 0x2bc9, 255, 255, 255, 255}, 
   { 409.21, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 409.21, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { 0.00, 419.87, -22.05, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { 456.93, 419.87, -66.62, 1, 0x0de3, 0x0073, 255, 255, 255, 255}, 
   { 478.09, 419.87, -66.62, 1, 0x0fe8, 0x0073, 255, 255, 255, 255}, 
   { 456.93, 419.84, -22.05, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { -409.21, 419.87, -22.05, 1, 0x0fe8, 0x295a, 255, 255, 255, 255}, 
   { 0.00, 419.87, -22.05, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { -409.21, 419.87, -3.46, 1, 0x0fe8, 0x3a6a, 255, 255, 255, 255}, 
   { -423.96, 432.17, -266.40, 1, 0x0e4d, 0x09bd, 10, 10, 12, 10}, 
   { -456.93, 419.85, -66.62, 1, 0x5293, 0x0073, 255, 255, 255, 255}, 
   { -456.93, 419.85, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { -478.97, 419.87, -66.62, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { -478.97, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { -478.97, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { -875.24, 419.87, -22.05, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { -496.24, 432.17, -266.40, 1, 0x0d45, 0x09fc, 2, 2, 2, 2}, 
   { -473.40, 432.16, -266.40, 1, 0x0da6, 0x09e5, 0, 0, 0, 0}, 
   { -478.97, 419.87, -66.62, 1, 0x0d93, 0x3bf6, 255, 255, 255, 255}, 
   { -434.20, 419.85, -66.62, 1, 0x0de3, 0x0073, 255, 255, 255, 255}, 
   { -409.21, 419.87, -66.62, 1, 0x0fe8, 0x0073, 255, 255, 255, 255}, 
   { -434.19, 419.84, -22.05, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { -900.93, 419.87, -22.05, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { -875.24, 419.87, -22.05, 1, 0x0fe8, 0x295a, 255, 255, 255, 255}, 
   { -900.93, 419.87, -3.46, 1, 0x0de3, 0x3a6a, 255, 255, 255, 255}, 
   { -933.43, 432.17, -266.40, 1, 0x070c, 0x0b7e, 0, 0, 0, 0}, 
   { -906.82, 432.17, -266.40, 1, 0x076d, 0x0b67, 0, 0, 0, 0}, 
   { -900.93, 419.87, -66.62, 1, 0x075a, 0x3d77, 255, 255, 255, 255}, 
   { 874.36, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 874.36, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { 478.09, 419.87, -22.05, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { 932.40, 432.17, -266.40, 1, 0x211d, 0x0b04, 0, 0, 0, 0}, 
   { 899.91, 419.87, -66.62, 1, 0x216b, 0x3cfd, 255, 255, 255, 255}, 
   { 905.93, 432.17, -266.40, 1, 0x20bd, 0x0b1c, 0, 0, 0, 0}, 
   { 899.91, 419.87, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { 899.91, 419.87, -3.46, 1, 0x5293, 0x3a6a, 255, 255, 255, 255}, 
   { 874.36, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 874.36, 419.87, -66.62, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { 409.21, 419.87, -66.62, 1, 0x508e, 0x0073, 255, 255, 255, 255}, 
   { 434.19, 419.84, -66.62, 1, 0x5293, 0x0073, 255, 255, 255, 255}, 
   { 409.21, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 409.21, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { 434.19, 419.84, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { 409.21, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { -434.19, 122.85, -22.05, 1, 0x168e, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 398.64, -22.05, 1, 0x2851, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 122.85, -3.46, 1, 0x168e, 0x33c9, 255, 255, 255, 255}, 
   { 456.93, 122.85, -22.05, 1, 0x1508, 0x29c9, 255, 255, 255, 255}, 
   { 456.93, 398.60, -22.05, 1, 0x0345, 0x29c9, 255, 255, 255, 255}, 
   { 456.93, 122.85, -3.46, 1, 0x1510, 0x33c9, 255, 255, 255, 255}, 
   { 434.19, 122.85, -22.05, 1, 0x1686, 0x29c9, 255, 255, 255, 255}, 
   { 456.93, 122.85, -22.05, 1, 0x1508, 0x29c9, 255, 255, 255, 255}, 
   { 434.19, 122.85, -3.46, 1, 0x168e, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 398.60, -22.05, 1, 0x034d, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 122.85, -22.05, 1, 0x1510, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 398.60, -3.46, 1, 0x034d, 0x33c9, 225, 224, 229, 226}, 
   { 434.19, 398.64, -22.05, 1, 0x2849, 0x29c9, 255, 255, 255, 255}, 
   { 434.19, 122.85, -22.05, 1, 0x1686, 0x29c9, 255, 255, 255, 255}, 
   { 434.19, 398.64, -3.46, 1, 0x2851, 0x33c9, 255, 255, 255, 255}, 
   { 434.19, 419.84, -3.46, 1, 0x29fe, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 419.85, -22.05, 1, 0x019f, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 398.60, -22.05, 1, 0x034d, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 419.84, -3.46, 1, 0x019f, 0x33c9, 255, 255, 255, 255}, 
   { -456.93, 122.85, -3.46, 1, 0x1510, 0x33c9, 255, 255, 255, 255}, 
   { 449.88, 432.16, -266.40, 1, 0x0076, 0x396d, 0, 0, 0, 0}, 
   { 449.87, 410.18, -266.40, 1, 0x0105, 0x396d, 0, 0, 0, 0}, 
   { 456.93, 398.51, -66.62, 1, 0x0cdf, 0x038b, 255, 255, 255, 255}, 
   { 473.43, 408.98, -266.40, 1, 0x0cd9, 0x396d, 0, 0, 0, 0}, 
   { 456.93, 419.87, -66.62, 1, 0x0d6f, 0x038b, 255, 255, 255, 255}, 
   { -478.97, 419.87, -22.05, 1, 0x508e, 0x295a, 255, 255, 255, 255}, 
   { -456.93, 419.85, -22.05, 1, 0x5293, 0x295a, 255, 255, 255, 255}, 
   { -478.97, 419.87, -3.46, 1, 0x508e, 0x3a6a, 255, 255, 255, 255}, 
   { -434.19, 419.84, -3.46, 1, 0x0de3, 0x3a6a, 255, 255, 255, 255}, 
   { -434.19, 419.84, -22.05, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { -409.21, 419.87, -3.46, 1, 0x0fe8, 0x3a6a, 255, 255, 255, 255}, 
   { -434.19, 398.64, -22.05, 1, 0x2851, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 419.84, -22.05, 1, 0x29fe, 0x33c9, 255, 255, 255, 255}, 
   { -434.19, 398.64, -3.46, 1, 0x2851, 0x33c9, 255, 255, 255, 255}, 
   { 449.88, 432.16, -266.40, 1, 0x1a41, 0x0cad, 0, 0, 0, 0}, 
   { 434.19, 419.84, -66.62, 1, 0x1a8e, 0x3ea7, 255, 255, 255, 255}, 
   { 423.99, 432.17, -266.40, 1, 0x19e0, 0x0cc5, 0, 0, 0, 0}, 
   { 456.93, 419.84, -3.46, 1, 0x0de3, 0x3a6a, 255, 255, 255, 255}, 
   { 456.93, 419.84, -22.05, 1, 0x0de3, 0x295a, 255, 255, 255, 255}, 
   { 478.09, 419.87, -3.46, 1, 0x0fe8, 0x3a6a, 255, 255, 255, 255}, 
   { 456.93, 398.60, -22.05, 1, 0x0345, 0x29c9, 255, 255, 255, 255}, 
   { 456.93, 419.84, -22.05, 1, 0x0197, 0x29c9, 255, 255, 255, 255}, 
   { 456.93, 398.60, -3.46, 1, 0x034d, 0x33c9, 255, 255, 255, 255}, 
   { 456.93, 419.87, -66.62, 1, 0x1ad1, 0x3e96, 255, 255, 255, 255}, 
   { 473.43, 432.16, -266.40, 1, 0x1a83, 0x0c9d, 0, 0, 0, 0}, 
   { 478.09, 419.87, -66.62, 1, 0x1b32, 0x3e7f, 255, 255, 255, 255}, 
   { -328.96, -436.27, -264.35, 1, 0x22c1, 0x448c, 0, 0, 0, 0}, 
   { 3.41, -436.27, -268.34, 1, 0x1998, 0x448c, 17, 17, 17, 17}, 
   { 328.96, -436.27, -268.34, 1, 0x106e, 0x448c, 0, 0, 0, 0}, 
   { 328.96, -436.27, -268.34, 1, 0x106e, 0x448c, 0, 0, 0, 0}, 
   { 359.65, -436.27, -268.34, 1, 0x0fdb, 0x448c, 4, 4, 4, 4}, 
   { -359.54, -436.27, -264.35, 1, 0x0000, 0x4000, 255, 255, 255, 255}, 
   { 469.29, -350.86, -268.39, 1, 0x16d4, 0x07ec, 0, 0, 0, 0}, 
   { 469.29, -316.27, -268.31, 1, 0x148a, 0x080a, 0, 0, 0, 0}, 
   { 467.82, -346.90, -109.37, 1, 0x16d4, 0x27e2, 255, 255, 255, 255}, 
   { 469.29, -316.27, -268.31, 1, 0x148a, 0x080a, 0, 0, 0, 0}, 
   { 409.29, -316.27, -268.32, 1, 0x1092, 0x0800, 0, 0, 0, 0}, 
   { 467.82, -312.31, -109.33, 1, 0x148a, 0x27f1, 255, 255, 255, 255}, 
   { 347.82, -312.31, -109.34, 1, 0x0c9b, 0x27e7, 255, 255, 255, 255}, 
   { 349.29, -316.27, -268.34, 1, 0x0c9b, 0x07f5, 0, 0, 0, 0}, 
   { 347.82, -372.31, -109.34, 1, 0x08a3, 0x27e7, 255, 255, 255, 255}, 
   { 347.82, -372.31, -109.34, 1, 0x08a3, 0x27e7, 255, 255, 255, 255}, 
   { 349.29, -376.27, -268.34, 1, 0x08a3, 0x07f5, 0, 0, 0, 0}, 
   { 347.82, -453.08, -109.34, 1, 0x04ab, 0x27e7, 255, 255, 255, 255}, 
   { 407.82, -312.31, -109.34, 1, 0x1092, 0x27ec, 255, 255, 255, 255}, 
   { 469.29, -438.65, -268.39, 1, 0x16d4, 0x07ec, 0, 0, 0, 0}, 
   { 469.29, -350.86, -268.39, 1, 0x16d4, 0x07ec, 0, 0, 0, 0}, 
   { 467.82, -434.69, -109.37, 1, 0x16d4, 0x27e2, 255, 255, 255, 255}, 
   { 466.84, -432.06, -3.46, 1, 0x16d4, 0x47d9, 255, 255, 255, 255}, 
   { -470.76, -346.90, -107.52, 1, 0x16d4, 0x2825, 255, 255, 255, 255}, 
   { -469.29, -350.86, -264.40, 1, 0x16d4, 0x07ed, 0, 0, 0, 0}, 
   { -470.76, -434.69, -107.52, 1, 0x16d4, 0x2825, 255, 255, 255, 255}, 
   { 346.84, -450.44, -3.46, 1, 0x03e7, 0x0067, 255, 255, 255, 255}, 
   { 349.29, -457.03, -268.34, 1, 0x03e7, 0x2078, 0, 0, 0, 0}, 
   { -470.76, -434.69, -107.52, 1, 0x0043, 0x2d4a, 255, 255, 255, 255}, 
   { -350.76, -453.08, -107.50, 1, 0x03e9, 0x2d49, 255, 255, 255, 255}, 
   { -469.29, -438.65, -264.40, 1, 0x004e, 0x4063, 0, 0, 0, 0}, 
   { -471.74, -432.06, -3.04, 1, 0x003b, 0x2092, 255, 255, 255, 255}, 
   { -351.74, -450.44, -3.04, 1, 0x03e2, 0x2092, 255, 255, 255, 255}, 
   { -470.76, -434.69, -107.52, 1, 0x0043, 0x2d4a, 255, 255, 255, 255}, 
};

void testpillar_reflect_PolyList(u8 animFrame){ 

   Vtx *testpillar_reflect_VTXPointer = &testpillar_reflect_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'Xport64_TileWall_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_TileWall_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_TileWall_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+60,31,0  );
   gSPModifyVertex(glistp++,  13,   G_MWO_POINT_ST, 0x00004000);  /*New Coords: 0.00, 128.00*/
     gSP1Triangle(glistp++,   3, 13, 12, 3  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+420,31,0  );
     gSP1Triangle(glistp++,   18, 19, 20, 18  );
     gSP1Triangle(glistp++,   21, 22, 23, 21  );


//>-- MATERIAL 3: START ------------------------------------ 'Xport64_TileReflect_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, SHADE, PRIMITIVE, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_TileWall_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_TileWall_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetColorDither(  glistp++,  G_CD_NOISE );
   gDPSetPrimColor(glistp++,  1,255,255,255,255,12  );

   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   22, 23, 24, 22, 25, 24, 26, 25  );
     gSP1Triangle(glistp++,   30, 22, 25, 30  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+25,31,0  );
     gSP1Triangle(glistp++,   6, 0, 1, 6  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+24,31,0  );
   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP1Triangle(glistp++,   2, 0, 3, 2  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+23,31,0  );
     gSP1Triangle(glistp++,   1, 0, 10, 1  );
     gSP2Triangles(glistp++,   11, 12, 1, 11, 11, 10, 15, 11  );
   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   12, 11, 16, 12, 12, 4, 1, 12  );
     gSP2Triangles(glistp++,   17, 18, 19, 17, 20, 21, 17, 20  );
     gSP2Triangles(glistp++,   20, 19, 25, 20, 21, 20, 26, 21  );
   gSPModifyVertex(glistp++,  23,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   21, 23, 17, 21, 28, 18, 17, 28  );
     gSP1Triangle(glistp++,   29, 17, 30, 29  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+51,31,0  );
     gSP1Triangle(glistp++,   5, 0, 1, 5  );
     gSP1Triangle(glistp++,   6, 1, 2, 6  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+40,31,0  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP1Triangle(glistp++,   13, 0, 6, 13  );
     gSP2Triangles(glistp++,   18, 19, 20, 18, 21, 22, 18, 21  );
     gSP2Triangles(glistp++,   21, 20, 26, 21, 22, 21, 27, 22  );
     gSP2Triangles(glistp++,   22, 24, 18, 22, 29, 19, 18, 29  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+58,31,0  );
     gSP2Triangles(glistp++,   12, 0, 13, 12, 17, 11, 12, 17  );
     gSP2Triangles(glistp++,   18, 12, 13, 18, 13, 0, 6, 13  );
     gSP2Triangles(glistp++,   19, 20, 21, 19, 22, 23, 19, 22  );
     gSP2Triangles(glistp++,   22, 21, 27, 22, 28, 23, 22, 28  );
     gSP1Triangle(glistp++,   23, 25, 19, 23  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+77,31,0  );
     gSP1Triangle(glistp++,   11, 12, 0, 11  );
     gSP2Triangles(glistp++,   13, 1, 0, 13, 14, 15, 16, 14  );
     gSP2Triangles(glistp++,   17, 18, 14, 17, 17, 16, 22, 17  );
     gSP2Triangles(glistp++,   18, 17, 23, 18, 18, 20, 14, 18  );
     gSP2Triangles(glistp++,   25, 14, 20, 25, 26, 15, 14, 26  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+106,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 0, 4, 3  );
     gSP2Triangles(glistp++,   5, 6, 7, 5, 14, 3, 4, 14  );
   gSPModifyVertex(glistp++,  9,   G_MWO_POINT_ST, 0x034f0004);  /*New Coords: 26.48, 0.04*/
     gSP2Triangles(glistp++,   9, 1, 5, 9, 2, 1, 9, 2  );
   gSPModifyVertex(glistp++,  10,   G_MWO_POINT_ST, 0x168e0004);  /*New Coords: 180.44, 0.04*/
     gSP2Triangles(glistp++,   4, 0, 10, 4, 16, 17, 18, 16  );
     gSP2Triangles(glistp++,   19, 20, 18, 19, 21, 22, 23, 21  );
     gSP2Triangles(glistp++,   20, 19, 28, 20, 29, 23, 17, 29  );
   gSPModifyVertex(glistp++,  25,   G_MWO_POINT_ST, 0x168e0004);  /*New Coords: 180.44, 0.04*/
     gSP2Triangles(glistp++,   16, 29, 17, 16, 20, 25, 18, 20  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+136,31,0  );
     gSP2Triangles(glistp++,   1, 2, 3, 1, 4, 3, 5, 4  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+128,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0de3295a);  /*New Coords: 111.12, 82.71*/   gSPModifyVertex(glistp++,  14,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   16, 17, 0, 16, 13, 11, 14, 13  );
     gSP2Triangles(glistp++,   11, 10, 19, 11, 20, 21, 11, 20  );
     gSP2Triangles(glistp++,   24, 25, 26, 24, 21, 14, 11, 21  );
     gSP2Triangles(glistp++,   27, 28, 29, 27, 25, 29, 26, 25  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+120,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0de3295a);  /*New Coords: 111.12, 82.71*/
     gSP1Triangle(glistp++,   29, 28, 0, 29  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+150,31,0  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP1Triangle(glistp++,   4, 7, 8, 4  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x0fe83a6a);  /*New Coords: 127.27, 116.83*/
     gSP2Triangles(glistp++,   8, 7, 13, 8, 7, 6, 14, 7  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+145,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x303b295a);  /*New Coords: 385.86, 82.71*/
     gSP2Triangles(glistp++,   21, 22, 0, 21, 23, 0, 24, 23  );
     gSP2Triangles(glistp++,   27, 21, 23, 27, 28, 23, 24, 28  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+175,31,0  );
     gSP2Triangles(glistp++,   2, 3, 4, 2, 5, 6, 7, 5  );
     gSP2Triangles(glistp++,   6, 8, 9, 6, 10, 11, 12, 10  );
     gSP2Triangles(glistp++,   13, 14, 15, 13, 16, 15, 17, 16  );
     gSP2Triangles(glistp++,   18, 19, 20, 18, 21, 17, 22, 21  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x29fe33c9);  /*New Coords: 335.95, 103.58*/
     gSP2Triangles(glistp++,   23, 22, 8, 23, 24, 20, 25, 24  );
     gSP1Triangle(glistp++,   26, 12, 19, 26  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+205,31,0  );
     gSP1Triangle(glistp++,   3, 4, 5, 3  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+120,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0de3295a);  /*New Coords: 111.12, 82.71*/
     gSP1Triangle(glistp++,   0, 28, 27, 0  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+186,31,0  );
     gSP1Triangle(glistp++,   25, 26, 0, 25  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+216,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 5, 3  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+22,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 8, 3, 9  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+262,31,0  );
     gSP1Triangle(glistp++,   16, 17, 18, 16  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+24,31,0  );
     gSP1Triangle(glistp++,   10, 0, 9, 10  );
     gSP1Triangle(glistp++,   15, 10, 14, 15  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+264,31,0  );
     gSP1Triangle(glistp++,   20, 21, 22, 20  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+40,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 3, 8, 9  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+280,31,0  );
     gSP1Triangle(glistp++,   10, 11, 12, 10  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+40,31,0  );
     gSP1Triangle(glistp++,   12, 11, 0, 12  );
     gSP1Triangle(glistp++,   17, 16, 12, 17  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+280,31,0  );
     gSP1Triangle(glistp++,   16, 17, 18, 16  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+58,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 3, 8, 9  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+298,31,0  );
     gSP1Triangle(glistp++,   4, 5, 6, 4  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+58,31,0  );
     gSP1Triangle(glistp++,   12, 11, 0, 12  );
     gSP2Triangles(glistp++,   18, 17, 12, 18, 16, 18, 13, 16  );
     gSP1Triangle(glistp++,   22, 19, 21, 22  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+298,31,0  );
     gSP1Triangle(glistp++,   10, 11, 12, 10  );
     gSP1Triangle(glistp++,   10, 7, 11, 10  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+77,31,0  );
     gSP1Triangle(glistp++,   6, 11, 0, 6  );
     gSP2Triangles(glistp++,   12, 13, 0, 12, 17, 14, 16, 17  );
     gSP1Triangle(glistp++,   23, 17, 22, 23  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+317,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+97,31,0  );
     gSP1Triangle(glistp++,   8, 5, 0, 8  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+91,31,0  );
     gSP1Triangle(glistp++,   11, 12, 0, 11  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+301,31,0  );
     gSP2Triangles(glistp++,   19, 20, 21, 19, 22, 23, 24, 22  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+331,31,0  );
     gSP2Triangles(glistp++,   4, 5, 6, 4, 7, 8, 9, 7  );
     gSP2Triangles(glistp++,   10, 11, 12, 10, 14, 15, 16, 14  );
     gSP2Triangles(glistp++,   17, 18, 19, 17, 20, 21, 22, 20  );
     gSP2Triangles(glistp++,   23, 24, 25, 23, 27, 28, 29, 27  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+361,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 6, 7, 8, 6  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+158,31,0  );
   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x0de30073);  /*New Coords: 111.12, 0.90*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/
     gSP1Triangle(glistp++,   7, 0, 5, 7  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+368,31,0  );
     gSP1Triangle(glistp++,   2, 3, 4, 2  );
     gSP2Triangles(glistp++,   8, 9, 10, 8, 14, 15, 16, 14  );
   gSPModifyVertex(glistp++,  12,   G_MWO_POINT_ST, 0x52930073);  /*New Coords: 660.61, 0.90*/
     gSP2Triangles(glistp++,   12, 14, 17, 12, 18, 19, 20, 18  );
     gSP2Triangles(glistp++,   21, 22, 23, 21, 24, 25, 26, 24  );
     gSP1Triangle(glistp++,   27, 28, 29, 27  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+398,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
     gSP2Triangles(glistp++,   3, 4, 5, 3, 6, 7, 8, 6  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+390,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x29f629c9);  /*New Coords: 335.70, 83.58*/
     gSP2Triangles(glistp++,   0, 14, 17, 0, 18, 19, 20, 18  );
     gSP2Triangles(glistp++,   12, 2, 21, 12, 27, 28, 29, 27  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+420,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 5, 3  );
     gSP2Triangles(glistp++,   9, 10, 11, 9, 12, 13, 14, 12  );


//>-- MATERIAL 4: START ------------------------------------ 'Wall_White_Transparent'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, SHADE, PRIMITIVE, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_DryWall_32x128,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_DryWall_32x128_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetColorDither(  glistp++,  G_CD_NOISE );
   gDPSetPrimColor(glistp++,  1,255,255,255,255,89  );

   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  26,   G_MWO_POINT_ST, 0x1a2e3ebe);  /*New Coords: 209.45, 125.49*/
     gSP2Triangles(glistp++,   26, 27, 28, 26, 29, 26, 28, 29  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+27,31,0  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x0e9a3bb6);  /*New Coords: 116.84, 119.43*/
     gSP2Triangles(glistp++,   1, 0, 5, 1, 8, 9, 0, 8  );
     gSP2Triangles(glistp++,   9, 8, 10, 9, 9, 5, 0, 9  );
   gSPModifyVertex(glistp++,  17,   G_MWO_POINT_ST, 0x1a2e3ebe);  /*New Coords: 209.45, 125.49*/
     gSP2Triangles(glistp++,   17, 18, 19, 17, 18, 17, 20, 18  );
   gSPModifyVertex(glistp++,  26,   G_MWO_POINT_ST, 0x0e9a3bb6);  /*New Coords: 116.84, 119.43*/
     gSP2Triangles(glistp++,   18, 23, 19, 18, 26, 19, 27, 26  );
     gSP2Triangles(glistp++,   28, 26, 27, 28, 27, 19, 23, 27  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+57,31,0  );
     gSP2Triangles(glistp++,   5, 6, 7, 5, 6, 5, 8, 6  );
     gSP2Triangles(glistp++,   6, 11, 7, 6, 14, 7, 15, 14  );
     gSP2Triangles(glistp++,   16, 17, 14, 16, 15, 7, 11, 15  );
     gSP2Triangles(glistp++,   24, 25, 26, 24, 27, 25, 24, 27  );
     gSP1Triangle(glistp++,   25, 30, 26, 25  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+83,31,0  );
     gSP1Triangle(glistp++,   5, 0, 4, 5  );
     gSP2Triangles(glistp++,   12, 13, 14, 12, 13, 12, 15, 13  );
     gSP2Triangles(glistp++,   13, 18, 14, 13, 21, 22, 14, 21  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+113,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/
     gSP1Triangle(glistp++,   1, 2, 0, 1  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+110,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0105038b);  /*New Coords: 8.17, 7.09*/
     gSP1Triangle(glistp++,   0, 6, 7, 0  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+108,31,0  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0dee038b);  /*New Coords: 111.46, 7.09*/   gSPModifyVertex(glistp++,  2,   G_MWO_POINT_ST, 0x0105038b);  /*New Coords: 8.17, 7.09*/
     gSP2Triangles(glistp++,   10, 8, 0, 10, 11, 2, 9, 11  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x06f2038b);  /*New Coords: 55.59, 7.09*/
     gSP2Triangles(glistp++,   13, 0, 6, 13, 6, 0, 7, 6  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x06f2038b);  /*New Coords: 55.59, 7.09*/   gSPModifyVertex(glistp++,  10,   G_MWO_POINT_ST, 0x06f2396d);  /*New Coords: 55.59, 114.85*/   gSPModifyVertex(glistp++,  18,   G_MWO_POINT_ST, 0x0105038b);  /*New Coords: 8.17, 7.09*/
     gSP2Triangles(glistp++,   9, 8, 10, 9, 18, 22, 23, 18  );
   gSPModifyVertex(glistp++,  14,   G_MWO_POINT_ST, 0x0dee038b);  /*New Coords: 111.46, 7.09*/
     gSP1Triangle(glistp++,   24, 25, 14, 24  );
   gSPModifyVertex(glistp++,  25,   G_MWO_POINT_ST, 0x06f2396d);  /*New Coords: 55.59, 114.85*/   gSPModifyVertex(glistp++,  14,   G_MWO_POINT_ST, 0x06f2038b);  /*New Coords: 55.59, 7.09*/
     gSP1Triangle(glistp++,   25, 28, 14, 25  );
   gSPModifyVertex(glistp++,  27,   G_MWO_POINT_ST, 0x0cdf038b);  /*New Coords: 102.98, 7.09*/   gSPModifyVertex(glistp++,  24,   G_MWO_POINT_ST, 0x06f2396d);  /*New Coords: 55.59, 114.85*/
     gSP2Triangles(glistp++,   28, 27, 14, 28, 22, 24, 23, 22  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+138,31,0  );
   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x1a2e3ebe);  /*New Coords: 209.45, 125.49*/
     gSP2Triangles(glistp++,   3, 4, 5, 3, 5, 4, 8, 5  );
   gSPModifyVertex(glistp++,  11,   G_MWO_POINT_ST, 0x0e9a3bb6);  /*New Coords: 116.84, 119.43*/
     gSP2Triangles(glistp++,   11, 12, 4, 11, 12, 11, 13, 12  );
   gSPModifyVertex(glistp++,  16,   G_MWO_POINT_ST, 0x0d933bf6);  /*New Coords: 108.61, 119.92*/
     gSP2Triangles(glistp++,   12, 8, 4, 12, 16, 20, 21, 16  );
     gSP2Triangles(glistp++,   22, 23, 16, 22, 21, 20, 24, 21  );
     gSP1Triangle(glistp++,   24, 20, 27, 24  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+144,31,0  );
   gSPModifyVertex(glistp++,  25,   G_MWO_POINT_ST, 0x210a3d15);  /*New Coords: 264.34, 122.17*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x1b323e7f);  /*New Coords: 217.57, 125.00*/
     gSP1Triangle(glistp++,   25, 0, 26, 25  );
     gSP1Triangle(glistp++,   27, 25, 26, 27  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+174,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
     gSP1Triangle(glistp++,   28, 29, 30, 28  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+204,31,0  );
     gSP1Triangle(glistp++,   1, 2, 3, 1  );
     gSP2Triangles(glistp++,   9, 10, 11, 9, 18, 19, 20, 18  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+264,31,0  );
     gSP2Triangles(glistp++,   11, 12, 13, 11, 17, 18, 19, 17  );
     gSP1Triangle(glistp++,   23, 24, 25, 23  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+293,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
     gSP1Triangle(glistp++,   6, 7, 8, 6  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+71,31,0  );
     gSP1Triangle(glistp++,   1, 2, 0, 1  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+281,31,0  );
     gSP1Triangle(glistp++,   24, 25, 26, 24  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+311,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
     gSP1Triangle(glistp++,   3, 4, 5, 3  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+97,31,0  );
     gSP1Triangle(glistp++,   4, 7, 0, 4  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+307,31,0  );
     gSP2Triangles(glistp++,   19, 20, 21, 19, 22, 23, 24, 22  );
     gSP1Triangle(glistp++,   25, 26, 27, 25  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+337,31,0  );
   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/   gSPModifyVertex(glistp++,  2,   G_MWO_POINT_ST, 0x0dee038b);  /*New Coords: 111.46, 7.09*/
     gSP1Triangle(glistp++,   1, 7, 2, 1  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+332,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0dec09d4);  /*New Coords: 111.40, 19.66*/   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x0e3a3bcd);  /*New Coords: 113.82, 119.61*/
     gSP1Triangle(glistp++,   0, 25, 3, 0  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+362,31,0  );
     gSP1Triangle(glistp++,   2, 3, 4, 2  );
     gSP2Triangles(glistp++,   11, 12, 13, 11, 17, 18, 19, 17  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+387,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0076038b);  /*New Coords: 3.70, 7.09*/
     gSP2Triangles(glistp++,   25, 26, 0, 25, 27, 28, 29, 27  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+417,31,0  );
     gSP2Triangles(glistp++,   9, 10, 11, 9, 18, 19, 20, 18  );


//>-- MATERIAL 6: START ------------------------------------ 'MarbleTileSet1_Transparent'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, SHADE, PRIMITIVE, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_Marble_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_Marble_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetColorDither(  glistp++,  G_CD_NOISE );
   gDPSetPrimColor(glistp++,  1,255,255,255,255,89  );

   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 5, 3  );
     gSP2Triangles(glistp++,   6, 2, 4, 6, 7, 8, 1, 7  );
     gSP2Triangles(glistp++,   7, 9, 10, 7, 11, 12, 13, 11  );
     gSP2Triangles(glistp++,   14, 15, 16, 14, 11, 14, 17, 11  );
     gSP2Triangles(glistp++,   18, 13, 19, 18, 20, 19, 21, 20  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+210,31,0  );
     gSP2Triangles(glistp++,   15, 16, 17, 15, 18, 19, 16, 18  );
     gSP2Triangles(glistp++,   20, 21, 22, 20, 21, 23, 24, 21  );
     gSP2Triangles(glistp++,   20, 25, 19, 20, 26, 27, 28, 26  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+239,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 5, 3  );
     gSP2Triangles(glistp++,   6, 5, 7, 6, 8, 2, 4, 8  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+238,31,0  );
     gSP1Triangle(glistp++,   0, 10, 11, 0  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+227,31,0  );
     gSP1Triangle(glistp++,   23, 0, 24, 23  );
     gSP2Triangles(glistp++,   0, 25, 26, 0, 10, 27, 21, 10  );
   gSPModifyVertex(glistp++,  26,   G_MWO_POINT_ST, 0x003b007c);  /*New Coords: 1.86, 0.97*/   gSPModifyVertex(glistp++,  24,   G_MWO_POINT_ST, 0x003b0d4e);  /*New Coords: 1.86, 26.61*/   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x03e70d39);  /*New Coords: 31.24, 26.45*/   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x03e72078);  /*New Coords: 31.24, 64.94*/
     gSP2Triangles(glistp++,   26, 24, 7, 26, 24, 28, 6, 24  );
   gSPModifyVertex(glistp++,  19,   G_MWO_POINT_ST, 0x03e92d49);  /*New Coords: 31.31, 90.58*/   gSPModifyVertex(glistp++,  27,   G_MWO_POINT_ST, 0x004e4063);  /*New Coords: 2.45, 128.78*/   gSPModifyVertex(glistp++,  21,   G_MWO_POINT_ST, 0x00432d4a);  /*New Coords: 2.09, 90.58*/
     gSP2Triangles(glistp++,   19, 29, 27, 19, 30, 19, 21, 30  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+241,31,0  );
   gSPModifyVertex(glistp++,  16,   G_MWO_POINT_ST, 0x04ab485e);  /*New Coords: 37.37, 144.74*/
     gSP2Triangles(glistp++,   2, 0, 17, 2, 5, 3, 16, 5  );
     gSP1Triangle(glistp++,   3, 2, 18, 3  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+240,31,0  );
     gSP1Triangle(glistp++,   1, 0, 20, 1  );
     gSP2Triangles(glistp++,   21, 22, 23, 21, 24, 25, 26, 24  );
     gSP2Triangles(glistp++,   27, 28, 29, 27, 30, 25, 27, 30  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+270,31,0  );
     gSP1Triangle(glistp++,   1, 2, 3, 1  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+252,31,0  );
     gSP1Triangle(glistp++,   22, 19, 0, 22  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+432,31,0  );
     gSP2Triangles(glistp++,   12, 13, 14, 12, 15, 16, 17, 15  );
     gSP2Triangles(glistp++,   18, 19, 20, 18, 21, 22, 23, 21  );
     gSP1Triangle(glistp++,   16, 19, 24, 16  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+238,31,0  );
     gSP1Triangle(glistp++,   24, 1, 0, 24  );
     gSP2Triangles(glistp++,   9, 1, 3, 9, 7, 4, 6, 7  );
   gSPModifyVertex(glistp++,  18,   G_MWO_POINT_ST, 0x04ab07fe);  /*New Coords: 37.37, 15.99*/
     gSP2Triangles(glistp++,   18, 7, 8, 18, 4, 9, 5, 4  );
     gSP1Triangle(glistp++,   25, 0, 11, 25  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+448,31,0  );
     gSP1Triangle(glistp++,   9, 10, 11, 9  );
   gSPVertex(glistp++,  testpillar_reflect_VTXPointer+446,31,0  );
     gSP2Triangles(glistp++,   13, 0, 14, 13, 15, 16, 17, 15  );
   gSPModifyVertex(glistp++,  14,   G_MWO_POINT_ST, 0x003b007c);  /*New Coords: 1.86, 0.97*/   gSPModifyVertex(glistp++,  9,   G_MWO_POINT_ST, 0x03e70d39);  /*New Coords: 31.24, 26.45*/   gSPModifyVertex(glistp++,  13,   G_MWO_POINT_ST, 0x003b0d4e);  /*New Coords: 1.86, 26.61*/
     gSP2Triangles(glistp++,   18, 14, 9, 18, 9, 13, 19, 9  );
     gSP2Triangles(glistp++,   20, 21, 22, 20, 23, 24, 25, 23  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 6: END ------------------------------------------- testpillar_reflect -------------------------------------------------

 
 
//>-- OBJECT 7: START ------------------------------------------ DebugRoom_Wall -------------------------------------------------

Vtx DebugRoom_Wall_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 1:  80, 78, 95 
   { 0.00, 406.43, 13.44, 1, 0x303b, 0x295a, 255, 255, 255, 255}, 
   { 0.00, 406.43, -5.15, 1, 0x303b, 0x3a6a, 80, 78, 95, 255}, 
   { 409.21, 406.43, -5.15, 1, 0x508e, 0x3a6a, 80, 78, 95, 255}, 
//Found a new color! Color Index: 2     Vert 1:  173, 172, 180 
   { 409.21, 406.43, 13.44, 1, 0x508e, 0x295a, 80, 78, 95, 255}, 
   { 409.21, 406.43, 58.01, 1, 0x508e, 0x0073, 173, 172, 180, 255}, 
   { 409.21, 406.43, 560.60, 1, 0x19e0, 0x0cc5, 173, 172, 180, 255}, 
   { 0.00, 406.43, 58.01, 1, 0x14a4, 0x3a40, 255, 255, 255, 255}, 
   { 434.75, 406.43, 58.01, 1, 0x1a8e, 0x3ea7, 80, 78, 95, 255}, 
   { 434.75, 406.43, -5.15, 1, 0x5293, 0x3a6a, 80, 78, 95, 255}, 
   { 434.75, 406.43, 13.44, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { 0.00, 406.43, 560.60, 1, 0x1456, 0x0847, 173, 172, 180, 255}, 
   { -409.21, 406.43, -5.15, 1, 0x0fe8, 0x3a6a, 80, 78, 95, 255}, 
   { -409.21, 406.43, 13.44, 1, 0x0fe8, 0x295a, 80, 78, 95, 255}, 
   { -409.21, 406.43, 58.01, 1, 0x0fe8, 0x0073, 173, 172, 180, 255}, 
   { -409.21, 406.43, 560.60, 1, 0x0e4d, 0x09bd, 173, 172, 180, 255}, 
   { -434.75, 406.43, 58.01, 1, 0x0e3a, 0x3bcd, 80, 78, 95, 255}, 
   { -434.75, 406.43, -5.15, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { -434.75, 406.43, 13.44, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { -875.24, 406.43, 13.44, 1, 0x303b, 0x295a, 80, 78, 95, 255}, 
   { -875.24, 406.43, -5.15, 1, 0x303b, 0x3a6a, 80, 78, 95, 255}, 
   { -478.97, 406.43, -5.15, 1, 0x508e, 0x3a6a, 80, 78, 95, 255}, 
   { -478.97, 406.43, 13.44, 1, 0x508e, 0x295a, 80, 78, 95, 255}, 
   { -478.97, 406.43, 58.01, 1, 0x508e, 0x0073, 80, 78, 95, 255}, 
//Found a new color! Color Index: 3     Vert 1:  82, 80, 97 
   { -478.97, 406.43, 560.60, 1, 0x0d45, 0x09fc, 82, 80, 97, 255}, 
   { -875.24, 406.43, 58.01, 1, 0x07bb, 0x3d60, 173, 172, 180, 255}, 
   { -453.42, 406.43, 58.01, 1, 0x0df3, 0x3bde, 80, 78, 95, 255}, 
   { -453.42, 406.43, -5.15, 1, 0x5293, 0x3a6a, 80, 78, 95, 255}, 
   { -453.42, 406.43, 13.44, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
//Found a new color! Color Index: 4     Vert 1:  202, 201, 206 
   { -875.24, 406.43, 560.60, 1, 0x076d, 0x0b67, 202, 201, 206, 255}, 
   { -900.93, 406.43, 13.44, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { -900.93, 406.43, -5.15, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { -900.93, 406.43, 58.01, 1, 0x075a, 0x3d77, 80, 78, 95, 255}, 
   { 478.09, 406.43, 13.44, 1, 0x303b, 0x295a, 80, 78, 95, 255}, 
   { 478.09, 406.43, -5.15, 1, 0x303b, 0x3a6a, 80, 78, 95, 255}, 
   { 874.36, 406.43, -5.15, 1, 0x508e, 0x3a6a, 80, 78, 95, 255}, 
//Found a new color! Color Index: 5     Vert 0:  171, 170, 178 
   { 874.36, 406.43, 13.44, 1, 0x508e, 0x295a, 171, 170, 178, 255}, 
   { 874.36, 406.43, 58.01, 1, 0x508e, 0x0073, 173, 172, 180, 255}, 
   { 478.09, 406.43, 58.01, 1, 0x1b32, 0x3e7f, 80, 78, 95, 255}, 
   { 478.09, 406.43, 560.60, 1, 0x1ae4, 0x0c86, 80, 78, 95, 255}, 
//Found a new color! Color Index: 6     Vert 0:  200, 199, 204 
   { 874.36, 406.43, 560.60, 1, 0x20bd, 0x0b1c, 200, 199, 204, 255}, 
   { 899.91, 406.43, 58.01, 1, 0x216b, 0x3cfd, 80, 78, 95, 255}, 
   { 899.91, 406.43, -5.15, 1, 0x5293, 0x3a6a, 80, 78, 95, 255}, 
   { 899.91, 406.43, 13.44, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { 452.40, 406.43, 13.44, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { 452.40, 406.43, -5.15, 1, 0x0de3, 0x3a6a, 80, 78, 95, 255}, 
   { 452.40, 406.43, 58.01, 1, 0x1ad1, 0x3e96, 80, 78, 95, 255}, 
   { 434.75, 406.43, 560.60, 1, 0x1a41, 0x0cad, 173, 172, 180, 255}, 
   { 409.21, 406.43, 560.60, 1, 0x19e0, 0x0cc5, 173, 172, 180, 255}, 
   { 434.75, 406.43, 58.01, 1, 0x1a8e, 0x3ea7, 80, 78, 95, 255}, 
   { 434.75, 406.43, 58.01, 1, 0x5293, 0x0073, 80, 78, 95, 255}, 
   { 409.21, 406.43, 58.01, 1, 0x508e, 0x0073, 173, 172, 180, 255}, 
   { 434.75, 406.43, 13.44, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { -434.75, 406.43, 560.60, 1, 0x0dec, 0x09d4, 80, 78, 95, 255}, 
   { -434.75, 406.43, 58.01, 1, 0x0e3a, 0x3bcd, 80, 78, 95, 255}, 
   { -409.21, 406.43, 560.60, 1, 0x0e4d, 0x09bd, 173, 172, 180, 255}, 
   { -434.75, 406.43, 58.01, 1, 0x0de3, 0x0073, 80, 78, 95, 255}, 
   { -434.75, 406.43, 13.44, 1, 0x0de3, 0x295a, 80, 78, 95, 255}, 
   { -409.21, 406.43, 58.01, 1, 0x0fe8, 0x0073, 173, 172, 180, 255}, 
   { -453.42, 406.43, 560.60, 1, 0x0da6, 0x09e5, 80, 78, 95, 255}, 
   { -478.97, 406.43, 560.60, 1, 0x0d45, 0x09fc, 82, 80, 97, 255}, 
   { -453.42, 406.43, 58.01, 1, 0x0df3, 0x3bde, 80, 78, 95, 255}, 
   { -453.42, 406.43, 58.01, 1, 0x5293, 0x0073, 80, 78, 95, 255}, 
   { -478.97, 406.43, 58.01, 1, 0x508e, 0x0073, 80, 78, 95, 255}, 
   { -453.42, 406.43, 13.44, 1, 0x5293, 0x295a, 80, 78, 95, 255}, 
   { -900.93, 406.43, 560.60, 1, 0x070c, 0x0b7e, 80, 78, 95, 255}, 
   { -900.93, 406.43, 58.01, 1, 0x075a, 0x3d77, 80, 78, 95, 255}, 
   { -875.24, 406.43, 560.60, 1, 0x076d, 0x0b67, 202, 201, 206, 255}, 
   { 899.91, 406.43, 560.60, 1, 0x211d, 0x0b04, 80, 78, 95, 255}, 
   { 452.40, 406.43, 560.60, 1, 0x1a83, 0x0c9d, 80, 78, 95, 255}, 
   { 452.40, 406.43, 58.01, 1, 0x1ad1, 0x3e96, 80, 78, 95, 255}, 
   { 478.09, 406.43, 560.60, 1, 0x1ae4, 0x0c86, 80, 78, 95, 255}, 
};

void DebugRoom_Wall_PolyList(u8 animFrame){ 

   Vtx *DebugRoom_Wall_VTXPointer = &DebugRoom_Wall_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'Xport64_TileWall_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_TileWall_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_TileWall_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 0, 3  );
     gSP2Triangles(glistp++,   3, 2, 8, 3, 4, 3, 9, 4  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   4, 6, 0, 4, 11, 1, 0, 11  );
     gSP2Triangles(glistp++,   12, 0, 13, 12, 16, 11, 12, 16  );
     gSP2Triangles(glistp++,   17, 12, 13, 17, 13, 0, 6, 13  );
     gSP2Triangles(glistp++,   18, 19, 20, 18, 21, 22, 18, 21  );
     gSP2Triangles(glistp++,   21, 20, 26, 21, 22, 21, 27, 22  );
   gSPModifyVertex(glistp++,  24,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP1Triangle(glistp++,   22, 24, 18, 22  );
   gSPModifyVertex(glistp++,  18,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/   gSPModifyVertex(glistp++,  24,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/
     gSP1Triangle(glistp++,   29, 18, 24, 29  );
   gSPModifyVertex(glistp++,  19,   G_MWO_POINT_ST, 0x0fe83a6a);  /*New Coords: 127.27, 116.83*/
     gSP1Triangle(glistp++,   30, 19, 18, 30  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+30,31,0  );
     gSP1Triangle(glistp++,   2, 3, 4, 2  );
     gSP2Triangles(glistp++,   5, 6, 2, 5, 5, 4, 11, 5  );
   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x303b0073);  /*New Coords: 385.86, 0.90*/
     gSP2Triangles(glistp++,   6, 5, 12, 6, 6, 7, 2, 6  );
   gSPModifyVertex(glistp++,  2,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x0fe83a6a);  /*New Coords: 127.27, 116.83*/
     gSP2Triangles(glistp++,   13, 2, 7, 13, 14, 3, 2, 14  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 3, 8, 9  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+30,31,0  );
     gSP1Triangle(glistp++,   19, 20, 21, 19  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+0,31,0  );
     gSP1Triangle(glistp++,   12, 11, 0, 12  );
     gSP1Triangle(glistp++,   17, 16, 12, 17  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+30,31,0  );
     gSP1Triangle(glistp++,   25, 26, 27, 25  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+18,31,0  );
     gSP2Triangles(glistp++,   3, 0, 2, 3, 9, 3, 8, 9  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+48,31,0  );
     gSP1Triangle(glistp++,   13, 14, 15, 13  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+24,31,0  );
   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x0de30073);  /*New Coords: 111.12, 0.90*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/
     gSP1Triangle(glistp++,   7, 5, 0, 7  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+18,31,0  );
   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/
     gSP2Triangles(glistp++,   11, 12, 0, 11, 17, 14, 16, 17  );
   gSPModifyVertex(glistp++,  22,   G_MWO_POINT_ST, 0x52930073);  /*New Coords: 660.61, 0.90*/
     gSP2Triangles(glistp++,   24, 17, 23, 24, 22, 18, 24, 22  );
   gSPModifyVertex(glistp++,  27,   G_MWO_POINT_ST, 0x0de30073);  /*New Coords: 111.12, 0.90*/   gSPModifyVertex(glistp++,  19,   G_MWO_POINT_ST, 0x0fe80073);  /*New Coords: 127.27, 0.90*/   gSPModifyVertex(glistp++,  14,   G_MWO_POINT_ST, 0x0fe8295a);  /*New Coords: 127.27, 82.71*/
     gSP2Triangles(glistp++,   27, 25, 19, 27, 25, 26, 14, 25  );


//>-- MATERIAL 1: START ------------------------------------ 'Prim_White'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_DryWall_32x128,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_DryWall_32x128_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,255,173,150,255  );

   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x1a2e3ebe);  /*New Coords: 209.45, 125.49*/
     gSP2Triangles(glistp++,   4, 5, 6, 4, 5, 4, 7, 5  );
   gSPModifyVertex(glistp++,  13,   G_MWO_POINT_ST, 0x0e9a3bb6);  /*New Coords: 116.84, 119.43*/
     gSP2Triangles(glistp++,   5, 10, 6, 5, 13, 6, 14, 13  );
     gSP2Triangles(glistp++,   15, 13, 14, 15, 14, 6, 10, 14  );
   gSPModifyVertex(glistp++,  22,   G_MWO_POINT_ST, 0x0d933bf6);  /*New Coords: 108.61, 119.92*/
     gSP2Triangles(glistp++,   22, 23, 24, 22, 23, 22, 25, 23  );
     gSP1Triangle(glistp++,   23, 28, 24, 23  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+24,31,0  );
     gSP1Triangle(glistp++,   7, 0, 4, 7  );
   gSPModifyVertex(glistp++,  12,   G_MWO_POINT_ST, 0x210a3d15);  /*New Coords: 264.34, 122.17*/
     gSP2Triangles(glistp++,   13, 12, 14, 13, 15, 12, 16, 15  );
     gSP2Triangles(glistp++,   21, 13, 14, 21, 12, 15, 14, 12  );
     gSP2Triangles(glistp++,   22, 23, 24, 22, 28, 29, 30, 28  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+54,31,0  );
     gSP2Triangles(glistp++,   4, 5, 6, 4, 10, 11, 12, 10  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+39,31,0  );
     gSP1Triangle(glistp++,   28, 0, 1, 28  );
   gSPVertex(glistp++,  DebugRoom_Wall_VTXPointer+68,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 7: END ------------------------------------------- DebugRoom_Wall -------------------------------------------------

 
 
//>-- OBJECT 8: START ------------------------------------------ LargePillars -------------------------------------------------

Vtx LargePillars_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 0:  103, 101, 116 
//Found a new color! Color Index: 2     Vert 1:  81, 79, 92 
//Found a new color! Color Index: 3     Vert 2:  80, 78, 95 
   { -469.29, -310.07, 23.51, 1, 0x140a, 0x76c1, 103, 101, 116, 255}, 
   { -469.29, -344.66, 23.51, 1, 0x1654, 0x76c1, 81, 79, 92, 255}, 
   { -469.29, -344.66, 264.88, 1, 0x1654, 0x41ce, 80, 78, 95, 255}, 
//Found a new color! Color Index: 4     Vert 0:  172, 171, 179 
   { -349.29, -370.07, 563.16, 1, 0x0823, 0x00a4, 172, 171, 179, 255}, 
   { -349.29, -370.07, 264.88, 1, 0x0823, 0x41ce, 172, 171, 179, 255}, 
   { -349.29, -310.07, 264.88, 1, 0x0c1b, 0x41ce, 255, 255, 255, 255}, 
   { -469.29, -310.07, 264.88, 1, 0x140a, 0x41ce, 172, 171, 179, 255}, 
   { -469.29, -344.66, 563.16, 1, 0x1654, 0x00a4, 80, 78, 95, 255}, 
   { -349.29, -430.07, 563.16, 1, 0x042b, 0x00a4, 80, 78, 95, 255}, 
   { -349.29, -430.07, 264.88, 1, 0x042b, 0x41ce, 80, 78, 95, 255}, 
   { -349.29, -310.07, 563.16, 1, 0x0c1b, 0x00a4, 255, 255, 255, 255}, 
   { -409.29, -310.07, 264.88, 1, 0x1012, 0x41ce, 255, 255, 255, 255}, 
   { -409.29, -310.07, 563.16, 1, 0x1012, 0x00a4, 255, 255, 255, 255}, 
   { -349.29, -370.07, 22.05, 1, 0x0823, 0x7713, 172, 171, 179, 255}, 
   { -349.29, -370.07, -3.65, 1, 0x0823, 0x7cb6, 81, 79, 92, 255}, 
   { -349.29, -310.07, -3.65, 1, 0x0c1b, 0x7cb6, 81, 79, 92, 255}, 
   { -349.29, -430.07, 22.05, 1, 0x042b, 0x7713, 80, 78, 95, 255}, 
   { -349.29, -430.07, -3.65, 1, 0x042b, 0x7cb6, 81, 79, 92, 255}, 
//Found a new color! Color Index: 5     Vert 2:  180, 179, 186 
   { -349.29, -310.07, 22.05, 1, 0x0c1b, 0x7713, 255, 255, 255, 255}, 
   { -409.29, -310.07, 22.83, 1, 0x1012, 0x76e7, 180, 179, 186, 255}, 
//Found a new color! Color Index: 6     Vert 2:  74, 72, 85 
   { 469.29, -310.07, 17.78, 1, 0x140a, 0x7803, 102, 100, 115, 255}, 
   { 469.29, -344.66, 17.78, 1, 0x1654, 0x7803, 80, 78, 95, 255}, 
   { 469.29, -344.66, -3.58, 1, 0x1654, 0x7cb2, 74, 72, 85, 255}, 
   { 349.29, -310.07, 264.88, 1, 0x0c1b, 0x41ce, 255, 255, 255, 255}, 
   { 349.29, -370.07, 264.88, 1, 0x0823, 0x41ce, 172, 171, 179, 255}, 
   { 349.29, -370.07, 563.16, 1, 0x0823, 0x00a4, 172, 171, 179, 255}, 
   { 469.29, -344.66, 563.16, 1, 0x1654, 0x00a4, 80, 78, 95, 255}, 
   { 469.29, -344.66, 264.88, 1, 0x1654, 0x41ce, 80, 78, 95, 255}, 
   { 469.29, -310.07, 264.88, 1, 0x140a, 0x41ce, 172, 171, 179, 255}, 
   { 349.29, -430.07, 264.88, 1, 0x042b, 0x41ce, 80, 78, 95, 255}, 
   { 349.29, -430.07, 563.16, 1, 0x042b, 0x00a4, 80, 78, 95, 255}, 
   { 409.29, -310.07, 264.88, 1, 0x1012, 0x41ce, 255, 255, 255, 255}, 
   { 349.29, -310.07, 563.16, 1, 0x0c1b, 0x00a4, 255, 255, 255, 255}, 
   { 409.29, -310.07, 563.16, 1, 0x1012, 0x00a4, 255, 255, 255, 255}, 
   { 349.29, -310.07, 17.93, 1, 0x0c1b, 0x77fa, 255, 255, 255, 255}, 
   { 349.29, -370.07, 17.93, 1, 0x0823, 0x77fa, 172, 171, 179, 255}, 
   { 349.29, -430.07, 17.93, 1, 0x042b, 0x77fa, 80, 78, 95, 255}, 
//Found a new color! Color Index: 7     Vert 1:  178, 177, 185 
   { 409.29, -310.07, 17.54, 1, 0x1012, 0x7810, 178, 177, 185, 255}, 
   { -409.29, -310.07, -3.66, 1, 0x1012, 0x7cb7, 81, 79, 92, 255}, 
   { -469.29, -310.07, -3.68, 1, 0x140a, 0x7cb8, 81, 79, 92, 255}, 
   { -469.29, -310.07, 23.51, 1, 0x140a, 0x76c1, 103, 101, 116, 255}, 
   { -469.29, -344.66, -3.58, 1, 0x1654, 0x7cb2, 81, 79, 92, 255}, 
   { 409.29, -310.07, -3.66, 1, 0x1012, 0x7cb7, 74, 72, 85, 255}, 
   { 349.29, -310.07, -3.65, 1, 0x0c1b, 0x7cb6, 74, 72, 85, 255}, 
//Found a new color! Color Index: 8     Vert 1:  65, 63, 76 
   { 349.29, -370.07, -3.65, 1, 0x0823, 0x7cb6, 65, 63, 76, 255}, 
   { 469.29, -310.07, -3.68, 1, 0x140a, 0x7cb8, 74, 72, 85, 255}, 
   { 349.29, -430.07, -3.65, 1, 0x042b, 0x7cb6, 74, 72, 85, 255}, 
   { -469.29, -310.07, 264.88, 1, 0x140a, 0x41ce, 172, 171, 179, 255}, 
   { -469.29, -310.07, 23.51, 1, 0x140a, 0x76c1, 103, 101, 116, 255}, 
   { -469.29, -344.66, 264.88, 1, 0x1654, 0x41ce, 80, 78, 95, 255}, 
   { -469.29, -310.07, 563.16, 1, 0x140a, 0x00a4, 172, 171, 179, 255}, 
   { -469.29, -344.66, 563.16, 1, 0x1654, 0x00a4, 80, 78, 95, 255}, 
   { -409.29, -310.07, 563.16, 1, 0x1012, 0x00a4, 255, 255, 255, 255}, 
   { -409.29, -310.07, 264.88, 1, 0x1012, 0x41ce, 255, 255, 255, 255}, 
//Found a new color! Color Index: 9     Vert 0:  67, 66, 78 
   { 469.29, -310.07, 563.16, 1, 0x140a, 0x00a4, 172, 171, 179, 255}, 
   { -469.29, -344.66, 23.51, 1, 0x1654, 0x76c1, 81, 79, 92, 255}, 
};

void LargePillars_PolyList(u8 animFrame){ 

   Vtx *LargePillars_VTXPointer = &LargePillars_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 3: START ------------------------------------ 'MarbleTileSet2_NoTransp'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_Marble_32x128_2,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_Marble_32x128_2_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,255,255,255,255  );

   gSPVertex(glistp++,  LargePillars_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   3, 4, 5, 3, 6, 2, 7, 6  );
     gSP2Triangles(glistp++,   12, 11, 6, 12, 13, 14, 15, 13  );
     gSP2Triangles(glistp++,   23, 24, 25, 23, 26, 27, 28, 26  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+28,31,0  );
     gSP1Triangle(glistp++,   0, 3, 5, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+24,31,0  );
     gSP1Triangle(glistp++,   10, 11, 0, 10  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+4,31,0  );
     gSP1Triangle(glistp++,   0, 9, 14, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+34,31,0  );
     gSP1Triangle(glistp++,   9, 10, 1, 9  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+3,31,0  );
     gSP1Triangle(glistp++,   7, 0, 2, 7  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+33,31,0  );
     gSP1Triangle(glistp++,   17, 14, 18, 17  );
     gSP1Triangle(glistp++,   17, 19, 14, 17  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+13,31,0  );
     gSP1Triangle(glistp++,   5, 0, 2, 5  );
     gSP1Triangle(glistp++,   19, 10, 12, 19  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+26,31,0  );
     gSP1Triangle(glistp++,   28, 0, 2, 28  );
     gSP1Triangle(glistp++,   28, 2, 7, 28  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+23,31,0  );
     gSP1Triangle(glistp++,   0, 11, 1, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+4,31,0  );
     gSP1Triangle(glistp++,   1, 0, 14, 1  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+34,31,0  );
     gSP1Triangle(glistp++,   0, 9, 1, 0  );


//>-- MATERIAL 5: START ------------------------------------ 'MarbleTileSet1_NoTransp'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_Marble_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_Marble_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,255,255,255,255  );

   gSPVertex(glistp++,  LargePillars_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 8, 9, 4, 8  );
     gSP2Triangles(glistp++,   10, 5, 11, 10, 16, 17, 14, 16  );
     gSP2Triangles(glistp++,   5, 18, 19, 5, 11, 19, 0, 11  );
     gSP2Triangles(glistp++,   20, 21, 22, 20, 24, 29, 30, 24  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+23,31,0  );
     gSP2Triangles(glistp++,   8, 0, 9, 8, 12, 13, 6, 12  );
     gSP1Triangle(glistp++,   8, 14, 11, 8  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+20,31,0  );
     gSP1Triangle(glistp++,   0, 17, 11, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+19,31,0  );
     gSP1Triangle(glistp++,   0, 19, 20, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+9,31,0  );
     gSP1Triangle(glistp++,   0, 7, 4, 0  );
     gSP1Triangle(glistp++,   9, 6, 29, 9  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+39,31,0  );
     gSP1Triangle(glistp++,   1, 0, 2, 1  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+37,31,0  );
     gSP1Triangle(glistp++,   0, 5, 6, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+20,31,0  );
     gSP1Triangle(glistp++,   7, 1, 0, 7  );
     gSP2Triangles(glistp++,   25, 22, 17, 25, 24, 26, 16, 24  );
     gSP1Triangle(glistp++,   27, 28, 29, 27  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+3,31,0  );
     gSP1Triangle(glistp++,   0, 5, 1, 0  );
     gSP2Triangles(glistp++,   9, 7, 8, 9, 10, 13, 11, 10  );
     gSP1Triangle(glistp++,   8, 2, 16, 8  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+33,31,0  );
     gSP1Triangle(glistp++,   14, 20, 15, 14  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+20,31,0  );
     gSP2Triangles(glistp++,   25, 0, 2, 25, 5, 4, 10, 5  );
     gSP2Triangles(glistp++,   13, 11, 12, 13, 4, 15, 9, 4  );
     gSP2Triangles(glistp++,   3, 11, 14, 3, 8, 0, 11, 8  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+19,31,0  );
     gSP1Triangle(glistp++,   29, 0, 20, 29  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+4,31,0  );
     gSP1Triangle(glistp++,   0, 5, 9, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+18,31,0  );
     gSP1Triangle(glistp++,   1, 0, 20, 1  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+41,31,0  );
     gSP1Triangle(glistp++,   14, 7, 0, 14  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+34,31,0  );
     gSP1Triangle(glistp++,   0, 3, 9, 0  );
   gSPVertex(glistp++,  LargePillars_VTXPointer+20,31,0  );
     gSP1Triangle(glistp++,   8, 7, 0, 8  );
     gSP2Triangles(glistp++,   0, 25, 17, 0, 15, 24, 16, 15  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 8: END ------------------------------------------- LargePillars -------------------------------------------------

 
 
//>-- OBJECT 9: START ------------------------------------------ testpillar -------------------------------------------------

Vtx testpillar_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 0:  80, 78, 95 
   { -456.93, 419.09, 13.77, 1, 0x019f, 0x2bc9, 80, 78, 95, 255}, 
   { -456.93, 419.09, -4.82, 1, 0x019f, 0x3e0b, 80, 78, 95, 255}, 
   { -456.93, 393.54, -4.82, 1, 0x034d, 0x3e0b, 80, 78, 95, 255}, 
   { -434.19, 122.85, 13.77, 1, 0x168e, 0x2bc9, 255, 255, 255, 255}, 
   { -434.19, 122.85, -4.82, 1, 0x168e, 0x3e0b, 80, 78, 95, 255}, 
   { -434.19, 393.54, -4.82, 1, 0x2851, 0x3e0b, 80, 78, 95, 255}, 
//Found a new color! Color Index: 2     Vert 0:  176, 175, 182 
   { -456.93, 122.85, 13.77, 1, 0x1510, 0x2bc9, 176, 175, 182, 255}, 
   { -456.93, 122.85, -4.82, 1, 0x1510, 0x3e0b, 80, 78, 95, 255}, 
   { -456.93, 122.85, 58.34, 1, 0x1510, 0x0004, 176, 175, 182, 255}, 
   { -434.19, 393.54, 13.77, 1, 0x2851, 0x2bc9, 80, 78, 95, 255}, 
   { -434.19, 393.54, 58.34, 1, 0x2851, 0x0004, 255, 255, 255, 255}, 
   { -456.93, 419.09, 58.34, 1, 0x019f, 0x0004, 80, 78, 95, 255}, 
   { -456.93, 393.51, 13.77, 1, 0x034d, 0x2bc9, 80, 78, 95, 255}, 
   { -456.93, 419.09, 560.93, 1, 0x0d6f, 0x396d, 80, 78, 95, 255}, 
   { -456.93, 393.41, 58.34, 1, 0x0cdf, 0x038b, 80, 78, 95, 255}, 
   { -434.19, 393.54, 560.93, 1, 0x0105, 0x396d, 255, 255, 255, 255}, 
   { -434.19, 122.85, 58.34, 1, 0x06f2, 0x038b, 255, 255, 255, 255}, 
   { -456.93, 122.85, 560.93, 1, 0x0dee, 0x396d, 176, 175, 182, 255}, 
   { -434.19, 419.09, 58.34, 1, 0x0076, 0x038b, 80, 78, 95, 255}, 
   { -434.19, 419.09, -4.82, 1, 0x29fe, 0x3e0b, 80, 78, 95, 255}, 
   { -434.19, 419.09, 13.77, 1, 0x29fe, 0x2bc9, 80, 78, 95, 255}, 
//Found a new color! Color Index: 3     Vert 1:  95, 93, 108 
   { -456.93, 392.39, 560.93, 1, 0x0cd9, 0x396d, 95, 93, 108, 255}, 
   { -434.19, 122.85, 560.93, 1, 0x06f2, 0x396d, 255, 255, 255, 255}, 
   { 456.93, 393.54, -4.82, 1, 0x034d, 0x3e0b, 80, 78, 95, 255}, 
   { 456.93, 419.09, -4.82, 1, 0x019f, 0x3e0b, 80, 78, 95, 255}, 
   { 456.93, 419.09, 13.77, 1, 0x019f, 0x2bc9, 80, 78, 95, 255}, 
   { 434.19, 393.54, -4.82, 1, 0x2851, 0x3e0b, 80, 78, 95, 255}, 
   { 434.19, 122.85, -4.82, 1, 0x168e, 0x3e0b, 80, 78, 95, 255}, 
   { 434.19, 122.85, 13.77, 1, 0x168e, 0x2bc9, 255, 255, 255, 255}, 
   { 456.93, 122.85, -4.82, 1, 0x1510, 0x3e0b, 80, 78, 95, 255}, 
   { 456.93, 122.85, 13.77, 1, 0x1510, 0x2bc9, 176, 175, 182, 255}, 
   { 456.93, 122.85, 58.34, 1, 0x1510, 0x0004, 176, 175, 182, 255}, 
   { 434.19, 393.54, 13.77, 1, 0x2851, 0x2bc9, 80, 78, 95, 255}, 
   { 434.19, 393.54, 58.34, 1, 0x2851, 0x0004, 255, 255, 255, 255}, 
   { 456.93, 393.51, 13.77, 1, 0x034d, 0x2bc9, 80, 78, 95, 255}, 
   { 456.93, 419.09, 58.34, 1, 0x019f, 0x0004, 80, 78, 95, 255}, 
   { 456.93, 393.41, 58.34, 1, 0x0cdf, 0x038b, 80, 78, 95, 255}, 
   { 456.93, 419.09, 560.93, 1, 0x0d6f, 0x396d, 80, 78, 95, 255}, 
   { 434.19, 122.85, 58.34, 1, 0x06f2, 0x038b, 255, 255, 255, 255}, 
   { 434.19, 393.54, 560.93, 1, 0x0105, 0x396d, 255, 255, 255, 255}, 
   { 456.93, 122.85, 560.93, 1, 0x0dee, 0x396d, 176, 175, 182, 255}, 
   { 434.19, 419.09, 58.34, 1, 0x0076, 0x038b, 80, 78, 95, 255}, 
   { 434.19, 419.09, -4.82, 1, 0x29fe, 0x3e0b, 80, 78, 95, 255}, 
   { 434.19, 419.09, 13.77, 1, 0x29fe, 0x2bc9, 80, 78, 95, 255}, 
   { 456.93, 392.39, 560.93, 1, 0x0cd9, 0x396d, 95, 93, 108, 255}, 
   { 434.19, 122.85, 560.93, 1, 0x06f2, 0x396d, 255, 255, 255, 255}, 
   { -434.19, 419.09, 560.93, 1, 0x0076, 0x396d, 80, 78, 95, 255}, 
   { -434.19, 393.54, 560.93, 1, 0x0105, 0x396d, 255, 255, 255, 255}, 
   { 434.19, 419.09, 560.93, 1, 0x0076, 0x396d, 80, 78, 95, 255}, 
};

void testpillar_PolyList(u8 animFrame){ 

   Vtx *testpillar_VTXPointer = &testpillar_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'Xport64_TileWall_32x128'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_TileWall_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_TileWall_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  testpillar_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 5, 3  );
     gSP2Triangles(glistp++,   6, 7, 4, 6, 8, 6, 3, 8  );
     gSP2Triangles(glistp++,   9, 10, 3, 9, 11, 0, 12, 11  );
     gSP2Triangles(glistp++,   9, 5, 19, 9, 10, 9, 20, 10  );
   gSPModifyVertex(glistp++,  14,   G_MWO_POINT_ST, 0x034f0004);  /*New Coords: 26.48, 0.04*/
     gSP2Triangles(glistp++,   14, 12, 6, 14, 12, 2, 7, 12  );
   gSPModifyVertex(glistp++,  16,   G_MWO_POINT_ST, 0x168e0004);  /*New Coords: 180.44, 0.04*/
     gSP2Triangles(glistp++,   8, 14, 6, 8, 10, 16, 3, 10  );
     gSP2Triangles(glistp++,   23, 24, 25, 23, 26, 27, 28, 26  );
     gSP1Triangle(glistp++,   27, 29, 30, 27  );
   gSPVertex(glistp++,  testpillar_VTXPointer+28,31,0  );
     gSP1Triangle(glistp++,   0, 2, 3, 0  );
     gSP1Triangle(glistp++,   4, 0, 5, 4  );
   gSPVertex(glistp++,  testpillar_VTXPointer+25,31,0  );
     gSP1Triangle(glistp++,   9, 0, 10, 9  );
     gSP2Triangles(glistp++,   17, 1, 7, 17, 18, 7, 8, 18  );
   gSPModifyVertex(glistp++,  11,   G_MWO_POINT_ST, 0x034f0004);  /*New Coords: 26.48, 0.04*/
     gSP1Triangle(glistp++,   11, 5, 9, 11  );
   gSPVertex(glistp++,  testpillar_VTXPointer+23,31,0  );
     gSP1Triangle(glistp++,   6, 0, 11, 6  );
   gSPModifyVertex(glistp++,  13,   G_MWO_POINT_ST, 0x034f0004);  /*New Coords: 26.48, 0.04*/   gSPModifyVertex(glistp++,  15,   G_MWO_POINT_ST, 0x168e0004);  /*New Coords: 180.44, 0.04*/
     gSP2Triangles(glistp++,   8, 7, 13, 8, 10, 5, 15, 10  );
   gSPVertex(glistp++,  testpillar_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   12, 0, 2, 12, 9, 3, 5, 9  );
   gSPModifyVertex(glistp++,  16,   G_MWO_POINT_ST, 0x168e0004);  /*New Coords: 180.44, 0.04*/
     gSP2Triangles(glistp++,   3, 6, 4, 3, 16, 8, 3, 16  );
   gSPModifyVertex(glistp++,  14,   G_MWO_POINT_ST, 0x034f0004);  /*New Coords: 26.48, 0.04*/
     gSP2Triangles(glistp++,   14, 11, 12, 14, 20, 9, 19, 20  );
   gSPModifyVertex(glistp++,  18,   G_MWO_POINT_ST, 0x29fe0004);  /*New Coords: 335.95, 0.04*/
     gSP2Triangles(glistp++,   18, 10, 20, 18, 6, 12, 7, 6  );
   gSPVertex(glistp++,  testpillar_VTXPointer+23,31,0  );
     gSP2Triangles(glistp++,   11, 0, 2, 11, 9, 3, 5, 9  );
   gSPModifyVertex(glistp++,  15,   G_MWO_POINT_ST, 0x168e0004);  /*New Coords: 180.44, 0.04*/
     gSP2Triangles(glistp++,   5, 4, 7, 5, 15, 5, 8, 15  );
   gSPModifyVertex(glistp++,  13,   G_MWO_POINT_ST, 0x034f0004);  /*New Coords: 26.48, 0.04*/
     gSP2Triangles(glistp++,   13, 11, 12, 13, 20, 19, 9, 20  );
   gSPModifyVertex(glistp++,  18,   G_MWO_POINT_ST, 0x29fe0004);  /*New Coords: 335.95, 0.04*/
     gSP2Triangles(glistp++,   18, 20, 10, 18, 7, 6, 11, 7  );


//>-- MATERIAL 1: START ------------------------------------ 'Prim_White'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_DryWall_32x128,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_DryWall_32x128_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,255,173,150,255  );

   gSPVertex(glistp++,  testpillar_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  11,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/   gSPModifyVertex(glistp++,  10,   G_MWO_POINT_ST, 0x0105038b);  /*New Coords: 8.17, 7.09*/
     gSP2Triangles(glistp++,   13, 11, 14, 13, 10, 15, 16, 10  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x0dee038b);  /*New Coords: 111.46, 7.09*/   gSPModifyVertex(glistp++,  16,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/
     gSP2Triangles(glistp++,   17, 8, 16, 17, 15, 10, 18, 15  );
   gSPModifyVertex(glistp++,  17,   G_MWO_POINT_ST, 0x06f2396d);  /*New Coords: 55.59, 114.85*/   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x06f2038b);  /*New Coords: 55.59, 7.09*/
     gSP2Triangles(glistp++,   17, 21, 8, 17, 21, 14, 8, 21  );
   gSPModifyVertex(glistp++,  16,   G_MWO_POINT_ST, 0x06f2038b);  /*New Coords: 55.59, 7.09*/
     gSP1Triangle(glistp++,   15, 22, 16, 15  );
   gSPVertex(glistp++,  testpillar_VTXPointer+30,31,0  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/
     gSP1Triangle(glistp++,   6, 5, 7, 6  );
   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x0105038b);  /*New Coords: 8.17, 7.09*/   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0x0dee038b);  /*New Coords: 111.46, 7.09*/
     gSP2Triangles(glistp++,   3, 8, 9, 3, 8, 1, 10, 8  );
   gSPModifyVertex(glistp++,  10,   G_MWO_POINT_ST, 0x06f2396d);  /*New Coords: 55.59, 114.85*/   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0x06f2038b);  /*New Coords: 55.59, 7.09*/
     gSP2Triangles(glistp++,   11, 3, 9, 11, 10, 1, 14, 10  );
   gSPModifyVertex(glistp++,  8,   G_MWO_POINT_ST, 0x06f2038b);  /*New Coords: 55.59, 7.09*/
     gSP2Triangles(glistp++,   14, 1, 6, 14, 9, 8, 15, 9  );
   gSPVertex(glistp++,  testpillar_VTXPointer+13,31,0  );
   gSPModifyVertex(glistp++,  9,   G_MWO_POINT_ST, 0x0d6f396d);  /*New Coords: 107.48, 114.85*/   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/
     gSP2Triangles(glistp++,   8, 0, 1, 8, 9, 4, 3, 9  );
   gSPVertex(glistp++,  testpillar_VTXPointer+18,31,0  );
     gSP2Triangles(glistp++,   28, 29, 0, 28, 26, 18, 19, 26  );
   gSPModifyVertex(glistp++,  27,   G_MWO_POINT_ST, 0x0d6f396d);  /*New Coords: 107.48, 114.85*/   gSPModifyVertex(glistp++,  20,   G_MWO_POINT_ST, 0x0d6f038b);  /*New Coords: 107.48, 7.09*/
     gSP2Triangles(glistp++,   27, 20, 22, 27, 30, 23, 21, 30  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 9: END ------------------------------------------- testpillar -------------------------------------------------

 
 
//>-- OBJECT 10: START ------------------------------------------ Tile_Floor -------------------------------------------------

Vtx Tile_Floor_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 0:  102, 98, 111 
//Found a new color! Color Index: 2     Vert 1:  108, 105, 117 
   { -900.95, 414.77, -3.46, 1, 0x1fff, 0x0026, 102, 98, 111, 255}, 
   { -900.95, 383.72, -3.46, 1, 0x1fff, 0x04e6, 108, 105, 117, 255}, 
   { -860.37, 383.65, -3.46, 1, 0x1e8f, 0x04e9, 102, 98, 111, 255}, 
//Found a new color! Color Index: 3     Vert 0:  88, 85, 102 
//Found a new color! Color Index: 4     Vert 2:  184, 182, 188 
   { -112.19, 414.77, -3.46, 1, 0x0407, 0x0026, 88, 85, 102, 255}, 
   { -224.87, 414.77, -3.46, 1, 0x0806, 0x0026, 87, 84, 101, 255}, 
   { -224.87, 382.55, -3.46, 1, 0x0806, 0x0514, 184, 182, 188, 255}, 
   { -337.55, 414.77, -3.46, 1, 0x0c05, 0x0026, 87, 84, 101, 255}, 
   { -425.05, 414.77, -3.46, 1, 0x0f4d, 0x0063, 87, 84, 101, 255}, 
   { -425.04, 382.90, -3.46, 1, 0x0f4d, 0x0543, 184, 182, 188, 255}, 
   { -562.91, 414.77, -3.46, 1, 0x1403, 0x0026, 102, 98, 111, 255}, 
   { -675.59, 414.77, -3.46, 1, 0x1802, 0x0026, 102, 98, 111, 255}, 
   { -675.59, 383.33, -3.46, 1, 0x1802, 0x04f5, 103, 99, 111, 255}, 
   { -337.55, -292.67, -3.46, 1, 0x0c05, 0x13b9, 255, 255, 255, 255}, 
   { -337.55, -3.25, -3.46, 1, 0x0c05, 0x4014, 255, 255, 255, 255}, 
   { -450.23, -3.25, -3.46, 1, 0x1004, 0x4014, 255, 255, 255, 255}, 
//Found a new color! Color Index: 5     Vert 2:  75, 72, 86 
   { -112.19, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { -224.87, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { -224.87, -426.81, -3.46, 1, 0x0806, 0x0002, 75, 72, 86, 255}, 
   { -788.27, 414.77, -3.46, 1, 0x1c01, 0x0026, 102, 98, 111, 255}, 
   { -788.27, 383.53, -3.46, 1, 0x1c01, 0x04ed, 102, 98, 111, 255}, 
//Found a new color! Color Index: 6     Vert 0:  95, 91, 107 
   { -450.23, 414.77, -3.46, 1, 0x1004, 0x0026, 95, 91, 107, 255}, 
   { -475.49, 414.77, -3.46, 1, 0x1117, 0x0063, 102, 98, 111, 255}, 
   { -475.50, 382.99, -3.46, 1, 0x1117, 0x053f, 102, 98, 111, 255}, 
   { -337.55, 382.75, -3.46, 1, 0x0c05, 0x050c, 184, 182, 188, 255}, 
   { -2.05, -408.94, -3.46, 1, 0x0008, 0x0214, 255, 255, 255, 255}, 
   { -112.19, -426.81, -3.46, 1, 0x0407, 0x0002, 75, 72, 86, 255}, 
   { -2.05, 414.77, -3.46, 1, 0x0008, 0x0026, 87, 84, 101, 255}, 
   { -112.19, 382.36, -3.46, 1, 0x0407, 0x051b, 184, 182, 188, 255}, 
//Found a new color! Color Index: 7     Vert 0:  190, 188, 194 
   { -2.05, 382.16, -3.46, 1, 0x0008, 0x0523, 190, 188, 194, 255}, 
   { -112.19, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { -788.27, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { -224.87, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
//Found a new color! Color Index: 8     Vert 0:  239, 239, 240 
   { -424.90, 98.09, -3.46, 1, 0x0f4c, 0x30d1, 239, 239, 240, 255}, 
   { -450.23, 98.37, -3.46, 1, 0x1032, 0x30c6, 255, 255, 255, 255}, 
//Found a new color! Color Index: 9     Vert 2:  229, 229, 231 
   { -562.91, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { -475.58, 98.65, -3.46, 1, 0x1118, 0x30bb, 229, 229, 231, 255}, 
   { -562.91, 383.14, -3.46, 1, 0x1403, 0x04fd, 102, 98, 111, 255}, 
   { -675.59, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { -880.88, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { -860.37, 383.65, -3.46, 1, 0x1e8f, 0x04e9, 102, 98, 111, 255}, 
   { -900.95, 383.72, -3.46, 1, 0x1fff, 0x04e6, 108, 105, 117, 255}, 
//Found a new color! Color Index: 10     Vert 0:  120, 118, 129 
   { -880.78, -313.76, -3.46, 1, 0x1f48, 0x1062, 120, 118, 129, 255}, 
   { -900.95, -3.25, -3.46, 1, 0x1fff, 0x4014, 102, 98, 111, 255}, 
   { -450.23, 116.47, -3.46, 1, 0x1004, 0x2dc5, 102, 98, 111, 255}, 
   { -450.23, 122.13, -3.46, 1, 0x1032, 0x2d24, 102, 98, 111, 255}, 
   { -425.05, 414.77, -3.46, 1, 0x0f4d, 0x0063, 87, 84, 101, 255}, 
   { -450.23, 382.94, -3.46, 1, 0x1004, 0x0504, 102, 98, 111, 255}, 
   { -425.04, 382.90, -3.46, 1, 0x0f4d, 0x0543, 184, 182, 188, 255}, 
   { 856.27, 383.65, -3.46, 1, 0x1e8f, 0x04e9, 102, 98, 111, 255}, 
   { 896.84, 414.77, -3.46, 1, 0x1fff, 0x0026, 102, 98, 111, 255}, 
   { 784.16, 414.77, -3.46, 1, 0x1c01, 0x0026, 102, 98, 111, 255}, 
   { 220.76, 382.55, -3.46, 1, 0x0806, 0x0514, 184, 182, 188, 255}, 
   { 220.76, 414.77, -3.46, 1, 0x0806, 0x0026, 87, 84, 101, 255}, 
   { 108.08, 414.77, -3.46, 1, 0x0407, 0x0026, 87, 84, 101, 255}, 
   { 420.93, 382.90, -3.46, 1, 0x0f4d, 0x0543, 185, 183, 189, 255}, 
   { 420.94, 414.77, -3.46, 1, 0x0f4d, 0x0063, 88, 85, 102, 255}, 
   { 333.44, 414.77, -3.46, 1, 0x0c05, 0x0026, 87, 84, 101, 255}, 
   { 671.48, 383.33, -3.46, 1, 0x1802, 0x04f5, 103, 99, 111, 255}, 
   { 671.48, 414.77, -3.46, 1, 0x1802, 0x0026, 102, 98, 111, 255}, 
   { 558.80, 414.77, -3.46, 1, 0x1403, 0x0026, 102, 98, 111, 255}, 
   { 220.76, -426.81, -3.46, 1, 0x0806, 0x0002, 75, 72, 86, 255}, 
   { 220.76, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { 108.08, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { 784.16, 383.53, -3.46, 1, 0x1c01, 0x04ed, 102, 98, 111, 255}, 
   { 471.39, 382.99, -3.46, 1, 0x1117, 0x053f, 102, 98, 111, 255}, 
   { 471.38, 414.77, -3.46, 1, 0x1117, 0x0063, 89, 86, 103, 255}, 
   { 446.12, 414.77, -3.46, 1, 0x1004, 0x0026, 89, 86, 103, 255}, 
   { 333.44, 382.75, -3.46, 1, 0x0c05, 0x050c, 184, 182, 188, 255}, 
   { 333.44, -3.25, -3.46, 1, 0x0c05, 0x4014, 255, 255, 255, 255}, 
   { 108.08, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { 108.08, 382.36, -3.46, 1, 0x0407, 0x051b, 184, 182, 188, 255}, 
   { -2.05, 382.16, -3.46, 1, 0x0008, 0x0523, 190, 188, 194, 255}, 
   { 784.16, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { 876.77, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { 220.76, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
   { 420.79, 98.09, -3.46, 1, 0x0f4c, 0x30d1, 239, 239, 240, 255}, 
   { 446.12, -3.25, -3.46, 1, 0x1004, 0x4014, 255, 255, 255, 255}, 
   { 446.12, 98.37, -3.46, 1, 0x1032, 0x30c6, 255, 255, 255, 255}, 
   { 558.80, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { 471.47, 98.65, -3.46, 1, 0x1118, 0x30bb, 229, 229, 231, 255}, 
   { 671.48, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { 558.80, 383.14, -3.46, 1, 0x1403, 0x04fd, 102, 98, 111, 255}, 
   { 896.84, -3.25, -3.46, 1, 0x1fff, 0x4014, 102, 98, 111, 255}, 
   { 896.84, 383.72, -3.46, 1, 0x1fff, 0x04e6, 108, 105, 117, 255}, 
   { 446.12, 122.13, -3.46, 1, 0x1032, 0x2d24, 102, 98, 111, 255}, 
   { 446.12, 116.47, -3.46, 1, 0x1004, 0x2dc5, 102, 98, 111, 255}, 
   { 446.12, 382.94, -3.46, 1, 0x1004, 0x0504, 102, 98, 111, 255}, 
   { 420.94, 414.77, -3.46, 1, 0x0f4d, 0x0063, 88, 85, 102, 255}, 
   { 420.79, 98.09, -3.46, 1, 0x0f4c, 0x30d1, 239, 239, 240, 255}, 
   { 446.12, 122.13, -3.46, 1, 0x1032, 0x2d24, 102, 98, 111, 255}, 
   { 420.93, 382.90, -3.46, 1, 0x0f4d, 0x0543, 185, 183, 189, 255}, 
//Found a new color! Color Index: 11     Vert 0:  162, 161, 170 
   { 893.21, -313.45, -3.46, 1, 0x1fde, 0x1068, 162, 161, 170, 255}, 
   { 558.80, -313.45, -3.46, 1, 0x1403, 0x1089, 162, 161, 170, 255}, 
   { 492.12, -292.67, -3.46, 1, 0x11a5, 0x13b9, 254, 254, 254, 255}, 
   { 446.12, -292.67, -3.46, 1, 0x1004, 0x13b9, 254, 254, 254, 255}, 
   { 333.44, -292.67, -3.46, 1, 0x0c05, 0x13b9, 254, 254, 254, 255}, 
   { 352.39, -313.22, -3.46, 1, 0x0c85, 0x1092, 75, 72, 86, 255}, 
//Found a new color! Color Index: 12     Vert 0:  83, 80, 93 
//Found a new color! Color Index: 13     Vert 2:  77, 74, 88 
   { 894.89, -345.21, -3.46, 1, 0x1fee, 0x0b86, 83, 80, 93, 255}, 
   { 879.27, -345.21, -3.46, 1, 0x1f60, 0x0b8e, 77, 74, 88, 255}, 
   { -2.05, -3.25, -3.46, 1, 0x0008, 0x4014, 255, 255, 255, 255}, 
   { -112.19, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { -112.19, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { -562.91, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { -675.59, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { -675.59, -313.70, -3.46, 1, 0x1802, 0x107f, 162, 161, 170, 255}, 
//Found a new color! Color Index: 14     Vert 2:  124, 123, 133 
   { -788.27, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { -788.27, -313.70, -3.46, 1, 0x1c01, 0x107f, 124, 123, 133, 255}, 
//Found a new color! Color Index: 15     Vert 1:  105, 101, 114 
   { -880.78, -313.76, -3.46, 1, 0x1f48, 0x1062, 120, 118, 129, 255}, 
   { -880.77, -345.46, -3.46, 1, 0x1f48, 0x0b85, 105, 101, 114, 255}, 
   { -873.24, -345.46, -3.46, 1, 0x1f04, 0x0b89, 105, 101, 114, 255}, 
   { 671.48, -313.45, -3.46, 1, 0x1802, 0x1089, 162, 161, 170, 255}, 
   { 671.48, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { 558.80, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
//Found a new color! Color Index: 16     Vert 0:  164, 163, 172 
   { 784.16, -313.45, -3.46, 1, 0x1c01, 0x1089, 164, 163, 172, 255}, 
   { 784.16, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { -112.19, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { -224.87, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
   { -224.87, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { 333.44, -402.00, -3.46, 1, 0x0c05, 0x02f7, 255, 255, 255, 255}, 
   { 879.04, -313.45, -3.46, 1, 0x1f5e, 0x106c, 162, 161, 170, 255}, 
   { 876.77, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
//Found a new color! Color Index: 17     Vert 0:  202, 202, 207 
//Found a new color! Color Index: 18     Vert 2:  86, 83, 96 
   { -562.91, -313.70, -3.46, 1, 0x1403, 0x107f, 202, 202, 207, 255}, 
   { -675.59, -345.46, -3.46, 1, 0x1802, 0x0ba1, 86, 83, 96, 255}, 
   { 671.48, -346.49, -3.46, 1, 0x1802, 0x0b79, 75, 72, 86, 255}, 
   { 558.80, -313.45, -3.46, 1, 0x1403, 0x1089, 162, 161, 170, 255}, 
   { 466.00, -347.81, -3.46, 1, 0x10b8, 0x0b45, 75, 72, 86, 255}, 
   { 558.80, -347.21, -3.46, 1, 0x1403, 0x0b5c, 75, 72, 86, 255}, 
   { 492.12, -313.45, -3.46, 1, 0x11a5, 0x1089, 254, 254, 254, 255}, 
   { -788.27, -345.46, -3.46, 1, 0x1c01, 0x0ba1, 105, 101, 114, 255}, 
   { -900.95, -313.78, -3.46, 1, 0x1fff, 0x105b, 105, 101, 114, 255}, 
   { -899.02, -345.45, -3.46, 1, 0x1fee, 0x0b7d, 105, 101, 114, 255}, 
   { 333.44, -426.81, -3.46, 1, 0x0c05, 0x0002, 75, 72, 86, 255}, 
   { 352.39, -421.28, -3.46, 1, 0x0c85, 0x0002, 75, 72, 86, 255}, 
   { 784.16, -345.77, -3.46, 1, 0x1c01, 0x0b95, 75, 72, 86, 255}, 
   { -880.88, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { -496.23, -313.70, -3.46, 1, 0x11a5, 0x107f, 202, 202, 207, 255}, 
   { -496.23, -292.67, -3.46, 1, 0x11a5, 0x13b9, 255, 255, 255, 255}, 
   { 492.12, -292.67, -3.46, 1, 0x11a5, 0x13b9, 254, 254, 254, 255}, 
   { 558.80, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { 446.12, -3.25, -3.46, 1, 0x1004, 0x4014, 255, 255, 255, 255}, 
//Found a new color! Color Index: 19     Vert 0:  79, 76, 90 
   { -562.91, -345.46, -3.46, 1, 0x1403, 0x0ba1, 79, 76, 90, 255}, 
   { -470.11, -344.80, -3.46, 1, 0x10b8, 0x0b45, 75, 72, 86, 255}, 
   { 333.44, -402.00, -3.46, 1, 0x0c05, 0x02f7, 255, 255, 255, 255}, 
   { 333.44, -292.67, -3.46, 1, 0x0c05, 0x13b9, 254, 254, 254, 255}, 
   { 220.76, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { -470.11, -313.70, -3.46, 1, 0x10b8, 0x107f, 75, 72, 86, 255}, 
   { -450.23, -292.67, -3.46, 1, 0x1004, 0x13b9, 255, 255, 255, 255}, 
   { -450.23, -3.25, -3.46, 1, 0x1004, 0x4014, 255, 255, 255, 255}, 
   { -450.23, -313.22, -3.46, 1, 0x1004, 0x1092, 75, 72, 86, 255}, 
   { -357.39, -313.22, -3.46, 1, 0x0c85, 0x1092, 75, 72, 86, 255}, 
   { -336.99, -407.44, -3.46, 1, 0x0bff, 0x02eb, 254, 254, 254, 255}, 
   { -224.87, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { -337.55, -292.67, -3.46, 1, 0x0c05, 0x13b9, 255, 255, 255, 255}, 
   { 466.00, -313.45, -3.46, 1, 0x10b8, 0x1089, 75, 72, 86, 255}, 
   { 446.12, -292.67, -3.46, 1, 0x1004, 0x13b9, 254, 254, 254, 255}, 
   { -359.19, -428.02, -3.46, 1, 0x0c7f, 0x002f, 104, 100, 113, 255}, 
   { 220.76, -426.81, -3.46, 1, 0x0806, 0x0002, 75, 72, 86, 255}, 
   { 333.44, -292.67, -3.46, 1, 0x0c05, 0x13b9, 254, 254, 254, 255}, 
   { 333.44, -3.25, -3.46, 1, 0x0c05, 0x4014, 255, 255, 255, 255}, 
   { 220.76, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
   { -224.87, -426.81, -3.46, 1, 0x0806, 0x0002, 75, 72, 86, 255}, 
   { 108.08, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { 108.08, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { -2.05, -3.25, -3.46, 1, 0x0008, 0x4014, 255, 255, 255, 255}, 
   { 108.08, 382.36, -3.46, 1, 0x0407, 0x051b, 184, 182, 188, 255}, 
   { 108.08, 414.77, -3.46, 1, 0x0407, 0x0026, 87, 84, 101, 255}, 
   { -2.05, 414.77, -3.46, 1, 0x0008, 0x0026, 87, 84, 101, 255}, 
//Found a new color! Color Index: 20     Vert 0:  88, 85, 98 
   { 108.08, -426.81, -3.46, 1, 0x0407, 0x0002, 88, 85, 98, 255}, 
   { -2.05, -408.94, -3.46, 1, 0x0008, 0x0214, 255, 255, 255, 255}, 
   { 784.16, -313.45, -3.46, 1, 0x1c01, 0x1089, 164, 163, 172, 255}, 
   { 784.16, -345.77, -3.46, 1, 0x1c01, 0x0b95, 75, 72, 86, 255}, 
   { 872.31, -345.21, -3.46, 1, 0x1f21, 0x0b91, 75, 72, 86, 255}, 
   { -788.27, 414.77, -3.46, 1, 0x1c01, 0x0026, 102, 98, 111, 255}, 
   { -900.95, 414.77, -3.46, 1, 0x1fff, 0x0026, 102, 98, 111, 255}, 
   { -860.37, 383.65, -3.46, 1, 0x1e8f, 0x04e9, 102, 98, 111, 255}, 
   { -337.55, 382.75, -3.46, 1, 0x0c05, 0x050c, 184, 182, 188, 255}, 
   { -337.55, 414.77, -3.46, 1, 0x0c05, 0x0026, 87, 84, 101, 255}, 
   { -425.04, 382.90, -3.46, 1, 0x0f4d, 0x0543, 184, 182, 188, 255}, 
   { -112.19, -426.81, -3.46, 1, 0x0407, 0x0002, 75, 72, 86, 255}, 
   { -112.19, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { -224.87, -426.81, -3.46, 1, 0x0806, 0x0002, 75, 72, 86, 255}, 
   { -224.87, 382.55, -3.46, 1, 0x0806, 0x0514, 184, 182, 188, 255}, 
   { -224.87, 414.77, -3.46, 1, 0x0806, 0x0026, 87, 84, 101, 255}, 
   { -337.55, 382.75, -3.46, 1, 0x0c05, 0x050c, 184, 182, 188, 255}, 
   { -2.05, -426.81, -3.46, 1, 0x0008, 0x0002, 75, 72, 86, 255}, 
   { -2.05, 382.16, -3.46, 1, 0x0008, 0x0523, 190, 188, 194, 255}, 
   { -2.05, 414.77, -3.46, 1, 0x0008, 0x0026, 87, 84, 101, 255}, 
   { -112.19, 382.36, -3.46, 1, 0x0407, 0x051b, 184, 182, 188, 255}, 
   { -224.87, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
   { -224.87, 382.55, -3.46, 1, 0x0806, 0x0514, 184, 182, 188, 255}, 
   { -337.55, -3.25, -3.46, 1, 0x0c05, 0x4014, 255, 255, 255, 255}, 
   { -112.19, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { -880.88, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { -788.27, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { -860.37, 383.65, -3.46, 1, 0x1e8f, 0x04e9, 102, 98, 111, 255}, 
   { -675.59, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { -675.59, 383.33, -3.46, 1, 0x1802, 0x04f5, 103, 99, 111, 255}, 
   { -788.27, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { -562.91, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { -562.91, 383.14, -3.46, 1, 0x1403, 0x04fd, 102, 98, 111, 255}, 
   { -675.59, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { -900.95, -3.25, -3.46, 1, 0x1fff, 0x4014, 102, 98, 111, 255}, 
   { -880.88, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { -900.95, 383.72, -3.46, 1, 0x1fff, 0x04e6, 108, 105, 117, 255}, 
   { -900.95, -313.78, -3.46, 1, 0x1fff, 0x105b, 105, 101, 114, 255}, 
   { -880.78, -313.76, -3.46, 1, 0x1f48, 0x1062, 120, 118, 129, 255}, 
   { -900.95, -3.25, -3.46, 1, 0x1fff, 0x4014, 102, 98, 111, 255}, 
   { -424.90, 98.09, -3.46, 1, 0x0f4c, 0x30d1, 239, 239, 240, 255}, 
   { -475.58, 98.65, -3.46, 1, 0x1118, 0x30bb, 229, 229, 231, 255}, 
   { -475.50, 382.99, -3.46, 1, 0x1117, 0x053f, 102, 98, 111, 255}, 
   { -475.49, 414.77, -3.46, 1, 0x1117, 0x0063, 102, 98, 111, 255}, 
   { -562.91, 383.14, -3.46, 1, 0x1403, 0x04fd, 102, 98, 111, 255}, 
   { -450.23, 98.37, -3.46, 1, 0x1032, 0x30c6, 255, 255, 255, 255}, 
   { -424.90, 98.09, -3.46, 1, 0x0f4c, 0x30d1, 239, 239, 240, 255}, 
   { -450.23, 116.47, -3.46, 1, 0x1004, 0x2dc5, 102, 98, 111, 255}, 
   { -425.04, 382.90, -3.46, 1, 0x0f4d, 0x0543, 184, 182, 188, 255}, 
   { -425.05, 414.77, -3.46, 1, 0x0f4d, 0x0063, 87, 84, 101, 255}, 
   { -450.23, 382.94, -3.46, 1, 0x1004, 0x0504, 102, 98, 111, 255}, 
   { 856.27, 383.65, -3.46, 1, 0x1e8f, 0x04e9, 102, 98, 111, 255}, 
   { 896.84, 383.72, -3.46, 1, 0x1fff, 0x04e6, 108, 105, 117, 255}, 
   { 896.84, 414.77, -3.46, 1, 0x1fff, 0x0026, 102, 98, 111, 255}, 
   { 108.08, 382.36, -3.46, 1, 0x0407, 0x051b, 184, 182, 188, 255}, 
   { 220.76, 382.55, -3.46, 1, 0x0806, 0x0514, 184, 182, 188, 255}, 
   { 108.08, 414.77, -3.46, 1, 0x0407, 0x0026, 87, 84, 101, 255}, 
   { 333.44, 382.75, -3.46, 1, 0x0c05, 0x050c, 184, 182, 188, 255}, 
   { 420.93, 382.90, -3.46, 1, 0x0f4d, 0x0543, 185, 183, 189, 255}, 
   { 333.44, 414.77, -3.46, 1, 0x0c05, 0x0026, 87, 84, 101, 255}, 
   { 220.76, 414.77, -3.46, 1, 0x0806, 0x0026, 87, 84, 101, 255}, 
   { 220.76, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
   { 333.44, -3.25, -3.46, 1, 0x0c05, 0x4014, 255, 255, 255, 255}, 
   { 220.76, 382.55, -3.46, 1, 0x0806, 0x0514, 184, 182, 188, 255}, 
   { 784.16, 383.53, -3.46, 1, 0x1c01, 0x04ed, 102, 98, 111, 255}, 
   { 784.16, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { 856.27, 383.65, -3.46, 1, 0x1e8f, 0x04e9, 102, 98, 111, 255}, 
   { 671.48, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { 784.16, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { 671.48, 383.33, -3.46, 1, 0x1802, 0x04f5, 103, 99, 111, 255}, 
   { 108.08, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { 558.80, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { 671.48, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { 558.80, 383.14, -3.46, 1, 0x1403, 0x04fd, 102, 98, 111, 255}, 
   { 876.77, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { 420.79, 98.09, -3.46, 1, 0x0f4c, 0x30d1, 239, 239, 240, 255}, 
   { 471.39, 382.99, -3.46, 1, 0x1117, 0x053f, 102, 98, 111, 255}, 
   { 471.47, 98.65, -3.46, 1, 0x1118, 0x30bb, 229, 229, 231, 255}, 
   { 558.80, 383.14, -3.46, 1, 0x1403, 0x04fd, 102, 98, 111, 255}, 
   { 471.38, 414.77, -3.46, 1, 0x1117, 0x0063, 89, 86, 103, 255}, 
   { 446.12, 98.37, -3.46, 1, 0x1032, 0x30c6, 255, 255, 255, 255}, 
   { 446.12, 116.47, -3.46, 1, 0x1004, 0x2dc5, 102, 98, 111, 255}, 
   { 420.79, 98.09, -3.46, 1, 0x0f4c, 0x30d1, 239, 239, 240, 255}, 
   { 420.93, 382.90, -3.46, 1, 0x0f4d, 0x0543, 185, 183, 189, 255}, 
   { 446.12, 382.94, -3.46, 1, 0x1004, 0x0504, 102, 98, 111, 255}, 
   { 420.94, 414.77, -3.46, 1, 0x0f4d, 0x0063, 88, 85, 102, 255}, 
   { 876.77, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { 879.04, -313.45, -3.46, 1, 0x1f5e, 0x106c, 162, 161, 170, 255}, 
   { 893.21, -313.45, -3.46, 1, 0x1fde, 0x1068, 162, 161, 170, 255}, 
   { 896.84, -313.45, -3.46, 1, 0x1fff, 0x1068, 162, 161, 170, 255}, 
   { 896.84, -3.25, -3.46, 1, 0x1fff, 0x4014, 102, 98, 111, 255}, 
   { -224.87, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { -224.87, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
   { -337.55, -292.67, -3.46, 1, 0x0c05, 0x13b9, 255, 255, 255, 255}, 
   { 446.12, -313.22, -3.46, 1, 0x1004, 0x1092, 75, 72, 86, 255}, 
   { 446.12, -292.67, -3.46, 1, 0x1004, 0x13b9, 254, 254, 254, 255}, 
   { 352.39, -313.22, -3.46, 1, 0x0c85, 0x1092, 75, 72, 86, 255}, 
//Found a new color! Color Index: 21     Vert 1:  98, 96, 108 
   { 894.89, -345.21, -3.46, 1, 0x1fee, 0x0b86, 83, 80, 93, 255}, 
   { 896.84, -345.21, -3.46, 1, 0x1fff, 0x0b86, 98, 96, 108, 255}, 
   { 879.27, -345.21, -3.46, 1, 0x1f60, 0x0b8e, 77, 74, 88, 255}, 
   { -562.91, -313.70, -3.46, 1, 0x1403, 0x107f, 202, 202, 207, 255}, 
   { -562.91, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { -675.59, -313.70, -3.46, 1, 0x1802, 0x107f, 162, 161, 170, 255}, 
   { -675.59, -313.70, -3.46, 1, 0x1802, 0x107f, 162, 161, 170, 255}, 
   { -675.59, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { -788.27, -313.70, -3.46, 1, 0x1c01, 0x107f, 124, 123, 133, 255}, 
   { 333.44, -292.67, -3.46, 1, 0x0c05, 0x13b9, 254, 254, 254, 255}, 
   { 446.12, -292.67, -3.46, 1, 0x1004, 0x13b9, 254, 254, 254, 255}, 
   { 333.44, -3.25, -3.46, 1, 0x0c05, 0x4014, 255, 255, 255, 255}, 
   { -873.24, -345.46, -3.46, 1, 0x1f04, 0x0b89, 105, 101, 114, 255}, 
   { -788.27, -345.46, -3.46, 1, 0x1c01, 0x0ba1, 105, 101, 114, 255}, 
   { -788.27, -313.70, -3.46, 1, 0x1c01, 0x107f, 124, 123, 133, 255}, 
   { -880.78, -313.76, -3.46, 1, 0x1f48, 0x1062, 120, 118, 129, 255}, 
   { 558.80, -313.45, -3.46, 1, 0x1403, 0x1089, 162, 161, 170, 255}, 
   { 671.48, -313.45, -3.46, 1, 0x1802, 0x1089, 162, 161, 170, 255}, 
   { 558.80, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { 671.48, -313.45, -3.46, 1, 0x1802, 0x1089, 162, 161, 170, 255}, 
   { 784.16, -313.45, -3.46, 1, 0x1c01, 0x1089, 164, 163, 172, 255}, 
   { 671.48, -3.25, -3.46, 1, 0x1802, 0x4014, 255, 255, 255, 255}, 
   { -112.19, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { -112.19, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { -224.87, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { 108.08, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { 220.76, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { 108.08, -3.25, -3.46, 1, 0x0407, 0x4014, 255, 255, 255, 255}, 
   { 352.39, -401.26, -3.46, 1, 0x0c85, 0x0314, 75, 72, 86, 255}, 
   { 352.39, -313.22, -3.46, 1, 0x0c85, 0x1092, 75, 72, 86, 255}, 
   { 333.44, -402.00, -3.46, 1, 0x0c05, 0x02f7, 255, 255, 255, 255}, 
   { 784.16, -3.25, -3.46, 1, 0x1c01, 0x4014, 255, 255, 255, 255}, 
   { 784.16, -313.45, -3.46, 1, 0x1c01, 0x1089, 164, 163, 172, 255}, 
   { 876.77, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { -562.91, -345.46, -3.46, 1, 0x1403, 0x0ba1, 79, 76, 90, 255}, 
   { -562.91, -313.70, -3.46, 1, 0x1403, 0x107f, 202, 202, 207, 255}, 
   { -675.59, -345.46, -3.46, 1, 0x1802, 0x0ba1, 86, 83, 96, 255}, 
   { 558.80, -347.21, -3.46, 1, 0x1403, 0x0b5c, 75, 72, 86, 255}, 
   { 671.48, -346.49, -3.46, 1, 0x1802, 0x0b79, 75, 72, 86, 255}, 
   { 558.80, -313.45, -3.46, 1, 0x1403, 0x1089, 162, 161, 170, 255}, 
   { -675.59, -345.46, -3.46, 1, 0x1802, 0x0ba1, 86, 83, 96, 255}, 
   { -675.59, -313.70, -3.46, 1, 0x1802, 0x107f, 162, 161, 170, 255}, 
   { -788.27, -345.46, -3.46, 1, 0x1c01, 0x0ba1, 105, 101, 114, 255}, 
   { -880.77, -345.46, -3.46, 1, 0x1f48, 0x0b85, 105, 101, 114, 255}, 
   { -880.78, -313.76, -3.46, 1, 0x1f48, 0x1062, 120, 118, 129, 255}, 
   { -899.02, -345.45, -3.46, 1, 0x1fee, 0x0b7d, 105, 101, 114, 255}, 
   { 352.39, -421.28, -3.46, 1, 0x0c85, 0x0002, 75, 72, 86, 255}, 
   { 784.16, -345.77, -3.46, 1, 0x1c01, 0x0b95, 75, 72, 86, 255}, 
   { -880.78, -313.76, -3.46, 1, 0x1f48, 0x1062, 120, 118, 129, 255}, 
   { -788.27, -313.70, -3.46, 1, 0x1c01, 0x107f, 124, 123, 133, 255}, 
   { -880.88, -3.25, -3.46, 1, 0x1f49, 0x4014, 255, 255, 255, 255}, 
   { -562.91, -3.25, -3.46, 1, 0x1403, 0x4014, 255, 255, 255, 255}, 
   { -562.91, -313.70, -3.46, 1, 0x1403, 0x107f, 202, 202, 207, 255}, 
   { -496.23, -292.67, -3.46, 1, 0x11a5, 0x13b9, 255, 255, 255, 255}, 
   { 446.12, -292.67, -3.46, 1, 0x1004, 0x13b9, 254, 254, 254, 255}, 
   { 492.12, -292.67, -3.46, 1, 0x11a5, 0x13b9, 254, 254, 254, 255}, 
   { 446.12, -3.25, -3.46, 1, 0x1004, 0x4014, 255, 255, 255, 255}, 
   { -496.23, -313.70, -3.46, 1, 0x11a5, 0x107f, 202, 202, 207, 255}, 
   { -470.11, -344.80, -3.46, 1, 0x10b8, 0x0b45, 75, 72, 86, 255}, 
   { -470.11, -313.70, -3.46, 1, 0x10b8, 0x107f, 75, 72, 86, 255}, 
   { -496.23, -313.70, -3.46, 1, 0x11a5, 0x107f, 202, 202, 207, 255}, 
   { -450.23, -3.25, -3.46, 1, 0x1004, 0x4014, 255, 255, 255, 255}, 
   { -337.55, -292.67, -3.46, 1, 0x0c05, 0x13b9, 255, 255, 255, 255}, 
   { -450.23, -292.67, -3.46, 1, 0x1004, 0x13b9, 255, 255, 255, 255}, 
   { -357.39, -313.22, -3.46, 1, 0x0c85, 0x1092, 75, 72, 86, 255}, 
   { 446.12, -292.67, -3.46, 1, 0x1004, 0x13b9, 254, 254, 254, 255}, 
   { 446.12, -313.22, -3.46, 1, 0x1004, 0x1092, 75, 72, 86, 255}, 
   { 466.00, -313.45, -3.46, 1, 0x10b8, 0x1089, 75, 72, 86, 255}, 
   { 492.12, -313.45, -3.46, 1, 0x11a5, 0x1089, 254, 254, 254, 255}, 
   { -359.19, -428.02, -3.46, 1, 0x0c7f, 0x002f, 104, 100, 113, 255}, 
   { -336.89, -427.82, -3.46, 1, 0x0bf2, 0x0028, 105, 101, 114, 255}, 
   { -336.99, -407.44, -3.46, 1, 0x0bff, 0x02eb, 254, 254, 254, 255}, 
   { 333.44, -402.00, -3.46, 1, 0x0c05, 0x02f7, 255, 255, 255, 255}, 
   { 220.76, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { 333.44, -426.81, -3.46, 1, 0x0c05, 0x0002, 75, 72, 86, 255}, 
   { 220.76, -407.86, -3.46, 1, 0x0806, 0x0211, 255, 255, 255, 255}, 
   { 333.44, -292.67, -3.46, 1, 0x0c05, 0x13b9, 254, 254, 254, 255}, 
   { 220.76, -3.25, -3.46, 1, 0x0806, 0x4014, 255, 255, 255, 255}, 
   { -224.87, -426.81, -3.46, 1, 0x0806, 0x0002, 75, 72, 86, 255}, 
   { -2.05, -408.94, -3.46, 1, 0x0008, 0x0214, 255, 255, 255, 255}, 
   { 108.08, -408.02, -3.46, 1, 0x0407, 0x0208, 255, 255, 255, 255}, 
   { -2.05, -3.25, -3.46, 1, 0x0008, 0x4014, 255, 255, 255, 255}, 
   { -2.05, 382.16, -3.46, 1, 0x0008, 0x0523, 190, 188, 194, 255}, 
   { 108.08, 382.36, -3.46, 1, 0x0407, 0x051b, 184, 182, 188, 255}, 
   { -2.05, 414.77, -3.46, 1, 0x0008, 0x0026, 87, 84, 101, 255}, 
   { -2.05, -426.81, -3.46, 1, 0x0008, 0x0002, 75, 72, 86, 255}, 
   { 108.08, -426.81, -3.46, 1, 0x0407, 0x0002, 88, 85, 98, 255}, 
   { -2.05, -408.94, -3.46, 1, 0x0008, 0x0214, 255, 255, 255, 255}, 
   { 872.31, -345.21, -3.46, 1, 0x1f21, 0x0b91, 75, 72, 86, 255}, 
   { 879.27, -345.21, -3.46, 1, 0x1f60, 0x0b8e, 77, 74, 88, 255}, 
   { 879.04, -313.45, -3.46, 1, 0x1f5e, 0x106c, 162, 161, 170, 255}, 
   { 784.16, -313.45, -3.46, 1, 0x1c01, 0x1089, 164, 163, 172, 255}, 
};

void Tile_Floor_PolyList(u8 animFrame){ 

   Vtx *Tile_Floor_VTXPointer = &Tile_Floor_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'MarbleTileSet1'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_AA_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_Marble_32x128_1,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_Marble_32x128_1_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetPrimColor(glistp++,  1,255,159,190,137,165  );

   gSPVertex(glistp++,  Tile_Floor_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 5, 3  );
     gSP2Triangles(glistp++,   9, 10, 11, 9, 4, 6, 23, 4  );
     gSP2Triangles(glistp++,   24, 15, 25, 24, 5, 23, 13, 5  );
     gSP1Triangle(glistp++,   30, 19, 2, 30  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+5,31,0  );
     gSP1Triangle(glistp++,   22, 0, 26, 22  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+11,31,0  );
     gSP2Triangles(glistp++,   25, 0, 26, 25, 27, 28, 29, 27  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+38,31,0  );
     gSP2Triangles(glistp++,   3, 0, 4, 3, 10, 11, 12, 10  );
     gSP2Triangles(glistp++,   13, 14, 15, 13, 19, 20, 21, 19  );
     gSP2Triangles(glistp++,   29, 18, 14, 29, 30, 29, 13, 30  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+48,31,0  );
     gSP2Triangles(glistp++,   24, 25, 0, 24, 26, 3, 22, 26  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+57,31,0  );
     gSP2Triangles(glistp++,   23, 0, 24, 23, 16, 25, 26, 16  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+73,31,0  );
     gSP1Triangle(glistp++,   18, 9, 0, 18  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+12,31,0  );
     gSP1Triangle(glistp++,   19, 1, 0, 19  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+72,31,0  );
     gSP2Triangles(glistp++,   20, 6, 21, 20, 22, 23, 24, 22  );
     gSP2Triangles(glistp++,   25, 19, 26, 25, 27, 28, 29, 27  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+102,31,0  );
     gSP1Triangle(glistp++,   5, 6, 7, 5  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+95,31,0  );
     gSP1Triangle(glistp++,   1, 0, 23, 1  );
     gSP1Triangle(glistp++,   18, 24, 25, 18  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+125,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+124,31,0  );
     gSP1Triangle(glistp++,   2, 0, 3, 2  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+107,31,0  );
     gSP1Triangle(glistp++,   0, 22, 23, 0  );
     gSP1Triangle(glistp++,   11, 24, 25, 11  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+105,31,0  );
     gSP1Triangle(glistp++,   1, 0, 29, 1  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+121,31,0  );
     gSP2Triangles(glistp++,   0, 14, 15, 0, 16, 17, 18, 16  );
     gSP2Triangles(glistp++,   19, 20, 14, 19, 21, 22, 23, 21  );
     gSP2Triangles(glistp++,   24, 15, 14, 24, 15, 25, 26, 15  );
     gSP1Triangle(glistp++,   25, 27, 28, 25  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+150,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+137,31,0  );
     gSP2Triangles(glistp++,   16, 0, 17, 16, 8, 11, 9, 8  );
     gSP1Triangle(glistp++,   13, 12, 18, 13  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+131,31,0  );
     gSP1Triangle(glistp++,   13, 25, 0, 13  );
     gSP2Triangles(glistp++,   26, 27, 28, 26, 29, 20, 19, 29  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+161,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 6, 0, 7, 6  );
     gSP1Triangle(glistp++,   8, 9, 10, 8  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+18,31,0  );
     gSP1Triangle(glistp++,   21, 1, 0, 21  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+168,31,0  );
     gSP1Triangle(glistp++,   4, 5, 6, 4  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+3,31,0  );
     gSP1Triangle(glistp++,   24, 0, 2, 24  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+9,31,0  );
     gSP1Triangle(glistp++,   27, 0, 2, 27  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+159,31,0  );
     gSP1Triangle(glistp++,   22, 23, 24, 22  );
     gSP1Triangle(glistp++,   25, 9, 19, 25  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+188,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
     gSP1Triangle(glistp++,   4, 5, 6, 4  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+187,31,0  );
     gSP1Triangle(glistp++,   4, 0, 1, 4  );
     gSP2Triangles(glistp++,   11, 12, 13, 11, 14, 15, 16, 14  );
     gSP1Triangle(glistp++,   17, 18, 19, 17  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+48,31,0  );
     gSP1Triangle(glistp++,   2, 15, 0, 2  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+198,31,0  );
     gSP2Triangles(glistp++,   20, 21, 22, 20, 23, 24, 25, 23  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+57,31,0  );
     gSP1Triangle(glistp++,   24, 0, 2, 24  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+207,31,0  );
     gSP1Triangle(glistp++,   15, 17, 20, 15  );
     gSP2Triangles(glistp++,   21, 22, 23, 21, 24, 25, 26, 24  );
     gSP1Triangle(glistp++,   30, 21, 14, 30  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+237,31,0  );
     gSP1Triangle(glistp++,   1, 2, 3, 1  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+219,31,0  );
     gSP1Triangle(glistp++,   14, 22, 0, 14  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+249,31,0  );
     gSP1Triangle(glistp++,   4, 5, 6, 4  );
     gSP2Triangles(glistp++,   6, 7, 8, 6, 9, 10, 11, 9  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+124,31,0  );
     gSP1Triangle(glistp++,   3, 0, 13, 3  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+244,31,0  );
     gSP1Triangle(glistp++,   17, 18, 19, 17  );
     gSP2Triangles(glistp++,   20, 21, 12, 20, 10, 22, 11, 10  );
     gSP1Triangle(glistp++,   12, 11, 20, 12  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+163,31,0  );
     gSP1Triangle(glistp++,   5, 0, 16, 5  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+253,31,0  );
     gSP2Triangles(glistp++,   23, 24, 25, 23, 25, 26, 23, 25  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+283,31,0  );
     gSP2Triangles(glistp++,   9, 10, 11, 9, 12, 13, 14, 12  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+125,31,0  );
     gSP1Triangle(glistp++,   28, 0, 2, 28  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+305,31,0  );
     gSP1Triangle(glistp++,   2, 3, 4, 2  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+292,31,0  );
     gSP2Triangles(glistp++,   0, 2, 18, 0, 20, 21, 22, 20  );
     gSP2Triangles(glistp++,   23, 24, 25, 23, 26, 27, 28, 26  );
     gSP1Triangle(glistp++,   24, 6, 29, 24  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+322,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+315,31,0  );
     gSP2Triangles(glistp++,   0, 2, 10, 0, 11, 12, 13, 11  );
     gSP2Triangles(glistp++,   14, 15, 16, 14, 16, 17, 4, 16  );
     gSP2Triangles(glistp++,   2, 8, 12, 2, 18, 19, 20, 18  );
     gSP2Triangles(glistp++,   20, 11, 13, 20, 21, 22, 23, 21  );
     gSP2Triangles(glistp++,   24, 25, 26, 24, 19, 27, 20, 19  );
     gSP1Triangle(glistp++,   28, 29, 30, 28  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+345,31,0  );
     gSP1Triangle(glistp++,   4, 5, 6, 4  );
     gSP2Triangles(glistp++,   7, 8, 9, 7, 9, 10, 7, 9  );


//>-- MATERIAL 1: START ------------------------------------ 'MarbleTileSet2'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_AA_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64_Marble_32x128_2,	G_IM_FMT_CI,	32, 128,	0, G_TX_WRAP,G_TX_WRAP, 5,7, G_TX_NOLOD,2 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64_Marble_32x128_2_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetPrimColor(glistp++,  1,255,159,190,137,178  );

   gSPVertex(glistp++,  Tile_Floor_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   6, 7, 8, 6, 12, 13, 14, 12  );
     gSP2Triangles(glistp++,   15, 16, 17, 15, 10, 18, 19, 10  );
     gSP2Triangles(glistp++,   20, 21, 22, 20, 26, 3, 27, 26  );
     gSP2Triangles(glistp++,   28, 27, 29, 28, 11, 19, 30, 11  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+14,31,0  );
     gSP2Triangles(glistp++,   18, 19, 0, 18, 20, 0, 21, 20  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+8,31,0  );
     gSP2Triangles(glistp++,   15, 0, 24, 15, 6, 25, 27, 6  );
     gSP1Triangle(glistp++,   6, 5, 24, 6  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+35,31,0  );
     gSP1Triangle(glistp++,   8, 9, 0, 8  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+22,31,0  );
     gSP1Triangle(glistp++,   13, 0, 14, 13  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+9,31,0  );
     gSP1Triangle(glistp++,   12, 0, 27, 12  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+32,31,0  );
     gSP1Triangle(glistp++,   0, 12, 11, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+20,31,0  );
     gSP1Triangle(glistp++,   25, 0, 26, 25  );
     gSP2Triangles(glistp++,   24, 26, 2, 24, 12, 27, 24, 12  );
     gSP2Triangles(glistp++,   27, 26, 24, 27, 15, 24, 2, 15  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+50,31,0  );
     gSP2Triangles(glistp++,   4, 5, 6, 4, 10, 11, 12, 10  );
     gSP2Triangles(glistp++,   13, 0, 8, 13, 14, 15, 16, 14  );
     gSP2Triangles(glistp++,   19, 20, 21, 19, 22, 13, 7, 22  );
     gSP2Triangles(glistp++,   25, 26, 27, 25, 28, 29, 26, 28  );
     gSP2Triangles(glistp++,   25, 4, 17, 25, 26, 29, 27, 26  );
     gSP1Triangle(glistp++,   26, 25, 18, 26  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+79,31,0  );
     gSP1Triangle(glistp++,   0, 5, 6, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+78,31,0  );
     gSP1Triangle(glistp++,   1, 0, 3, 1  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+59,31,0  );
     gSP1Triangle(glistp++,   22, 0, 6, 22  );
     gSP2Triangles(glistp++,   26, 25, 16, 26, 27, 7, 28, 27  );
     gSP1Triangle(glistp++,   25, 5, 27, 25  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+88,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+86,31,0  );
     gSP1Triangle(glistp++,   4, 3, 0, 4  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+64,31,0  );
     gSP1Triangle(glistp++,   15, 0, 25, 15  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+94,31,0  );
     gSP2Triangles(glistp++,   8, 9, 10, 8, 9, 11, 12, 9  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+68,31,0  );
     gSP1Triangle(glistp++,   26, 8, 0, 26  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+98,31,0  );
     gSP1Triangle(glistp++,   12, 13, 14, 12  );
     gSP2Triangles(glistp++,   15, 16, 13, 15, 17, 18, 19, 17  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+61,31,0  );
     gSP1Triangle(glistp++,   0, 13, 8, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+104,31,0  );
     gSP1Triangle(glistp++,   17, 0, 18, 17  );
     gSP2Triangles(glistp++,   19, 6, 20, 19, 0, 2, 24, 0  );
     gSP1Triangle(glistp++,   29, 9, 6, 29  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+164,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
     gSP1Triangle(glistp++,   11, 12, 13, 11  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+146,31,0  );
     gSP1Triangle(glistp++,   0, 6, 1, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+176,31,0  );
     gSP1Triangle(glistp++,   2, 3, 4, 2  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+10,31,0  );
     gSP1Triangle(glistp++,   1, 0, 9, 1  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+20,31,0  );
     gSP1Triangle(glistp++,   26, 0, 2, 26  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+170,31,0  );
     gSP1Triangle(glistp++,   15, 16, 17, 15  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+163,31,0  );
     gSP1Triangle(glistp++,   0, 22, 28, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+193,31,0  );
     gSP1Triangle(glistp++,   2, 3, 4, 2  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+183,31,0  );
     gSP1Triangle(glistp++,   7, 0, 24, 7  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+33,31,0  );
     gSP1Triangle(glistp++,   0, 10, 2, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+183,31,0  );
     gSP2Triangles(glistp++,   15, 25, 16, 15, 26, 27, 28, 26  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+212,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 5, 3  );
     gSP1Triangle(glistp++,   12, 13, 14, 12  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+156,31,0  );
     gSP1Triangle(glistp++,   11, 0, 5, 11  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+57,31,0  );
     gSP2Triangles(glistp++,   0, 6, 1, 0, 29, 7, 9, 29  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+162,31,0  );
     gSP1Triangle(glistp++,   1, 0, 23, 1  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+222,31,0  );
     gSP1Triangle(glistp++,   12, 13, 14, 12  );
     gSP1Triangle(glistp++,   7, 20, 2, 7  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+77,31,0  );
     gSP1Triangle(glistp++,   0, 2, 8, 0  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+227,31,0  );
     gSP2Triangles(glistp++,   16, 17, 18, 16, 16, 18, 19, 16  );
     gSP2Triangles(glistp++,   20, 21, 22, 20, 23, 24, 25, 23  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+257,31,0  );
     gSP2Triangles(glistp++,   10, 11, 12, 10, 13, 14, 15, 13  );
     gSP2Triangles(glistp++,   16, 17, 18, 16, 23, 24, 25, 23  );
     gSP1Triangle(glistp++,   26, 27, 28, 26  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+286,31,0  );
     gSP1Triangle(glistp++,   0, 1, 2, 0  );
     gSP2Triangles(glistp++,   3, 4, 5, 3, 12, 13, 14, 12  );
     gSP2Triangles(glistp++,   15, 16, 17, 15, 18, 19, 20, 18  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+283,31,0  );
     gSP1Triangle(glistp++,   19, 28, 0, 19  );
   gSPVertex(glistp++,  Tile_Floor_VTXPointer+343,31,0  );
     gSP1Triangle(glistp++,   3, 4, 5, 3  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 10: END ------------------------------------------- Tile_Floor -------------------------------------------------

 
 
//>-- OBJECT 11: START ------------------------------------------ TextureSample_16bRGBA_32x64 -------------------------------------------------

Vtx TextureSample_16bRGBA_32x64_VertList_0 [] = {
   { -60.00, 0.00, -0.23, 1, 0x03ff, 0x0fff, 255, 255, 255, 255}, 
   { -60.00, 0.00, 119.77, 1, 0x03ff, 0x0000, 255, 255, 255, 255}, 
   { 0.00, -0.00, 119.77, 1, 0x0000, 0x0000, 255, 255, 255, 255}, 
   { 0.00, -0.00, -0.23, 1, 0x03ff, 0x0fff, 255, 255, 255, 255}, 
   { 60.00, -0.00, 119.77, 1, 0x0000, 0x0000, 255, 255, 255, 255}, 
   { 60.00, -0.00, -0.23, 1, 0x0000, 0x0fff, 255, 255, 255, 255}, 
};

void TextureSample_16bRGBA_32x64_PolyList(u8 animFrame){ 

   Vtx *TextureSample_16bRGBA_32x64_VTXPointer = &TextureSample_16bRGBA_32x64_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 1: START ------------------------------------ 'MatSample_16bRGBA_32x64_1'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPTileSync(glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH | G_CULL_BACK  );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_NONE );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, TEXEL0, 0, TEXEL0, 0, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2  );
   gDPLoadTextureBlock(  glistp++,  Xport64_16bRGBA_32x64_1,	G_IM_FMT_RGBA, G_IM_SIZ_16b,	32, 64,	0, G_TX_CLAMP,G_TX_CLAMP, 5,6, G_TX_NOLOD,1 );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  TextureSample_16bRGBA_32x64_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  2,   G_MWO_POINT_ST, 0x03ff0000);  /*New Coords: 32.00, 0.01*/
     gSP2Triangles(glistp++,   3, 2, 4, 3, 5, 3, 4, 5  );


//>-- MATERIAL 2: START ------------------------------------ 'MatSample_16bRGBA_32x64_2'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPTileSync(glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH | G_CULL_BACK  );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_NONE );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, TEXEL0, 0, TEXEL0, 0, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2  );
   gDPLoadTextureBlock(  glistp++,  Xport64_16bRGBA_32x64_2,	G_IM_FMT_RGBA, G_IM_SIZ_16b,	32, 64,	0, G_TX_CLAMP,G_TX_CLAMP, 5,6, G_TX_NOLOD,1 );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  TextureSample_16bRGBA_32x64_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  3,   G_MWO_POINT_ST, 0x00000fff);  /*New Coords: 0.00, 63.99*/
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 0, 2, 3  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 11: END ------------------------------------------- TextureSample_16bRGBA_32x64 -------------------------------------------------

 
 
//>-- OBJECT 12: START ------------------------------------------ TextureSample_16bRGBA_32x32 -------------------------------------------------

Vtx TextureSample_16bRGBA_32x32_VertList_0 [] = {
   { -60.00, 0.00, -0.23, 1, 0x03ff, 0x03ff, 255, 255, 255, 255}, 
   { -60.00, 0.00, 119.77, 1, 0x03ff, 0x0000, 255, 255, 255, 255}, 
   { 60.00, -0.00, 119.77, 1, 0x0000, 0x0000, 255, 255, 255, 255}, 
   { 60.00, -0.00, -0.23, 1, 0x0000, 0x03ff, 255, 255, 255, 255}, 
};

void TextureSample_16bRGBA_32x32_PolyList(u8 animFrame){ 

   Vtx *TextureSample_16bRGBA_32x32_VTXPointer = &TextureSample_16bRGBA_32x32_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'MatSample_16bRGBA_32x32'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPTileSync(glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH | G_CULL_BACK  );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_NONE );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, TEXEL0, 0, TEXEL0, 0, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2  );
   gDPLoadTextureBlock(  glistp++,  Xport64_16bRGBA_32x32,	G_IM_FMT_RGBA, G_IM_SIZ_16b,	32, 32,	0, G_TX_CLAMP,G_TX_CLAMP, 5,5, G_TX_NOLOD,G_TX_NOLOD );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  TextureSample_16bRGBA_32x32_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 0, 2, 3  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 12: END ------------------------------------------- TextureSample_16bRGBA_32x32 -------------------------------------------------

 
 
//>-- OBJECT 13: START ------------------------------------------ newLevelObject_edgeTransp -------------------------------------------------

Vtx newLevelObject_edgeTransp_VertList_0 [] = {
   { -90.00, -30.00, 59.40, 1, 0x000b, 0x0008, 255, 255, 255, 255}, 
   { -90.00, -30.00, -0.60, 1, 0x000b, 0x1005, 255, 255, 255, 255}, 
   { 90.00, -30.00, -0.60, 1, 0x3003, 0x1005, 255, 255, 255, 255}, 
   { 90.00, -30.00, 59.40, 1, 0x3002, 0x0008, 255, 255, 255, 255}, 
};

void newLevelObject_edgeTransp_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_edgeTransp_VTXPointer = &newLevelObject_edgeTransp_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'EdgeTexture'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_1CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGBDECALA, G_CC_MODULATERGBDECALA );
   gDPSetRenderMode(  glistp++,  G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_1bAlphaBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_CLAMP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_1bAlphaBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );

   gSPVertex(glistp++,  newLevelObject_edgeTransp_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 0, 2, 3  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 13: END ------------------------------------------- newLevelObject_edgeTransp -------------------------------------------------

 
 
//>-- OBJECT 14: START ------------------------------------------ newLevelObject_prim_uv -------------------------------------------------

Vtx newLevelObject_prim_uv_VertList_0 [] = {
   { -30.00, 30.00, 59.40, 1, 0x0001, 0x0001, 255, 255, 255, 255}, 
   { -30.00, 30.00, -0.60, 1, 0x0001, 0x0001, 255, 255, 255, 255}, 
   { -30.00, -30.00, -0.60, 1, 0x0002, 0x0001, 255, 255, 255, 255}, 
   { 30.00, 30.00, 59.40, 1, 0x0001, 0x0001, 255, 255, 255, 255}, 
   { 30.00, 30.00, -0.60, 1, 0x0001, 0x0001, 255, 255, 255, 255}, 
   { 30.00, -30.00, 59.40, 1, 0x0000, 0x0001, 255, 255, 255, 255}, 
   { 30.00, -30.00, -0.60, 1, 0x0000, 0x0001, 255, 255, 255, 255}, 
   { -30.00, -30.00, 59.40, 1, 0x0002, 0x0000, 255, 255, 255, 255}, 
};

void newLevelObject_prim_uv_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_prim_uv_VTXPointer = &newLevelObject_prim_uv_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 3: START ------------------------------------ 'PrimColor'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_1CYCLE );
   gSPClearGeometryMode( glistp++,  (G_SHADE|G_SHADING_SMOOTH|G_LIGHTING|G_TEXTURE_GEN|G_TEXTURE_GEN_LINEAR|G_CULL_BOTH|G_FOG) );
   gSPSetGeometryMode( glistp++,  G_ZBUFFER | G_CULL_BACK | G_SHADE | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF  );
   gDPSetCombineMode(  glistp++,  G_CC_PRIMITIVE, G_CC_PRIMITIVE );
   gDPSetRenderMode(  glistp++,  G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2  );
   gDPSetColorDither(  glistp++,  G_CD_BAYER );
   gDPSetPrimColor(glistp++,  1,255,22,43,255,255  );

   gSPVertex(glistp++,  newLevelObject_prim_uv_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 1, 3  );
     gSP2Triangles(glistp++,   5, 6, 4, 5, 7, 2, 6, 7  );
     gSP2Triangles(glistp++,   1, 4, 6, 1, 3, 0, 7, 3  );
     gSP2Triangles(glistp++,   7, 0, 2, 7, 0, 3, 1, 0  );
     gSP2Triangles(glistp++,   3, 5, 4, 3, 5, 7, 6, 5  );
     gSP2Triangles(glistp++,   2, 1, 6, 2, 5, 3, 7, 5  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 14: END ------------------------------------------- newLevelObject_prim_uv -------------------------------------------------

 
 
//>-- OBJECT 15: START ------------------------------------------ newLevelObject_normals -------------------------------------------------

Vtx newLevelObject_normals_VertList_0 [] = {
   { -12.36, 50.47, 30.79, 1, 0x1ffe, 0x1000, -30, 123, 1, 255},  
   { -12.36, 15.36, -17.87, 1, 0x1ffe, 0x1ffd, -30, 37, -117, 255},  
   { -40.59, -27.57, 13.10, 1, 0x2ffb, 0x1ffd, -99, -67, -41, 255},  
   { 40.59, 27.57, 47.30, 1, 0x1001, 0x1000, 99, 67, 41, 255},  
   { 40.59, -7.53, -1.36, 1, 0x1001, 0x1ffd, 99, -18, -77, 255},  
   { 12.36, -15.36, 78.28, 1, 0x0004, 0x1000, 30, -37, 117, 255},  
   { 12.36, -50.47, 29.62, 1, 0x0004, 0x1ffd, 30, -123, -1, 255},  
   { -40.59, 7.53, 61.76, 1, 0x2ffb, 0x0fff, -99, 18, 77, 255},  
};

void newLevelObject_normals_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_normals_VTXPointer = &newLevelObject_normals_VertList_0[0]; 

// Set Object Light: 
   gSPSetLights1( glistp++,  texturedCubeLight );


//>-- MATERIAL 0: START ------------------------------------ 'Material'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_BlueBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_BlueBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  newLevelObject_normals_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 1, 3  );
     gSP1Triangle(glistp++,   5, 6, 4, 5  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x3ff91ffd);  /*New Coords: 255.89, 127.95*/
     gSP1Triangle(glistp++,   7, 2, 6, 7  );
     gSP2Triangles(glistp++,   7, 0, 2, 7, 0, 3, 1, 0  );
     gSP1Triangle(glistp++,   3, 5, 4, 3  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x3ff80fff);  /*New Coords: 255.89, 64.00*/
     gSP1Triangle(glistp++,   5, 7, 6, 5  );


//>-- MATERIAL 1: START ------------------------------------ 'Material2'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_AmberBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_AmberBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,86  );

   gSPVertex(glistp++,  newLevelObject_normals_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0x2ffc2ffa);  /*New Coords: 191.94, 191.91*/   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x3ff92ffa);  /*New Coords: 255.89, 191.91*/   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x3ff91ffd);  /*New Coords: 255.89, 127.95*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x10010003);  /*New Coords: 64.02, 0.05*/   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x00030003);  /*New Coords: 0.06, 0.05*/
     gSP2Triangles(glistp++,   1, 4, 6, 1, 3, 0, 7, 3  );
     gSP2Triangles(glistp++,   2, 1, 6, 2, 5, 3, 7, 5  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 15: END ------------------------------------------- newLevelObject_normals -------------------------------------------------

 
 
//>-- OBJECT 16: START ------------------------------------------ newLevelObject_PrimShaded -------------------------------------------------

Vtx newLevelObject_PrimShaded_VertList_0 [] = {
   { -48.37, 7.33, 11.90, 1, 0x0001, 0x0001, -118, 17, -42, 255},  
   { -4.94, -21.81, -17.51, 1, 0x0001, 0x0001, -12, -53, -114, 255},  
   { 9.63, -50.94, 32.88, 1, 0x0002, 0x0001, 23, -124, 8, 255},  
   { -9.63, 50.94, 25.91, 1, 0x0001, 0x0001, -23, 124, -8, 255},  
   { 33.81, 21.81, -3.49, 1, 0x0001, 0x0001, 82, 53, -80, 255},  
   { 4.94, 21.81, 76.30, 1, 0x0000, 0x0001, 12, 53, 114, 255},  
   { 48.37, -7.33, 46.89, 1, 0x0000, 0x0001, 118, -17, 42, 255},  
   { -33.81, -21.81, 62.28, 1, 0x0002, 0x0000, -82, -53, 80, 255},  
};

void newLevelObject_PrimShaded_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_PrimShaded_VTXPointer = &newLevelObject_PrimShaded_VertList_0[0]; 

// Set Object Light: 
   gSPSetLights1( glistp++,  primLightTest );


//>-- MATERIAL 5: START ------------------------------------ 'PrimColor_Shaded'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  (G_SHADE|G_SHADING_SMOOTH|G_LIGHTING|G_TEXTURE_GEN|G_TEXTURE_GEN_LINEAR|G_CULL_BOTH|G_FOG) );
   gSPSetGeometryMode( glistp++,  G_ZBUFFER | G_CULL_BACK | G_SHADE| G_FOG | G_SHADING_SMOOTH | G_LIGHTING );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF  );
   gDPSetCombineLERP(  glistp++, 	PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2  );
   gDPSetColorDither(  glistp++,  G_CD_BAYER );
   gDPSetPrimColor(glistp++,  1,255,0,255,0,255  );

   gSPVertex(glistp++,  newLevelObject_PrimShaded_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 1, 3  );
     gSP2Triangles(glistp++,   5, 6, 4, 5, 7, 2, 6, 7  );
     gSP2Triangles(glistp++,   1, 4, 6, 1, 3, 0, 7, 3  );
     gSP2Triangles(glistp++,   7, 0, 2, 7, 0, 3, 1, 0  );
     gSP2Triangles(glistp++,   3, 5, 4, 3, 5, 7, 6, 5  );
     gSP2Triangles(glistp++,   2, 1, 6, 2, 5, 3, 7, 5  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 16: END ------------------------------------------- newLevelObject_PrimShaded -------------------------------------------------

 
 
//>-- OBJECT 17: START ------------------------------------------ newLevelObject_lightShaft -------------------------------------------------

//Test Primative Color Storage = 255, 255, 255 
Vtx newLevelObject_lightShaft_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 0:  253, 255, 159 
//Vertex Check: 5  Index: 0  Count: 0  
 //Vert 5, Loop 0, Redirect 0 Index+Offset: 0      //Vertex Check: 1  Index: 0  Count: 0  
 //Vert 1, Loop 1, Redirect 1 Index+Offset: 1      //Vertex Check: 0  Index: 0  Count: 0  
 //Vert 0, Loop 2, Redirect 2 Index+Offset: 2      //Adjusting redirectValueCheck
   { -30.01, -30.39, 355.05, 1, 0x2001, 0x2ffa, 253, 255, 159, 255}, 
//This usedUVValue(0) is 0x0080, 0x00bf 
   { -64.67, 145.82, -69.38, 1, 0x2001, 0x5ff2, 253, 255, 159, 0}, 
//This usedUVValue(1) is 0x0080, 0x017f 
   { -64.67, -35.94, -132.47, 1, 0x2fff, 0x5ff1, 253, 255, 159, 0}, 
//This usedUVValue(2) is 0x00bf, 0x017f 
//Vertex Check: 6  Index: 3  Count: 3  
 //Vert 6, Loop 3, Redirect 3 Index+Offset: 3      //Vertex Check: 2  Index: 3  Count: 3  
 //Vert 2, Loop 4, Redirect 4 Index+Offset: 4      //Vertex Check: 1  Index: 3  Count: 3  
 //Vert 1, Loop 5, Redirect 1 Index+Offset: 4      //Adjusting redirectValueCheck
   { 29.99, -30.39, 355.05, 1, 0x1004, 0x2ffb, 253, 255, 159, 255}, 
//This usedUVValue(3) is 0x0040, 0x00bf 
   { 64.67, 145.82, -69.38, 1, 0x1004, 0x5ff2, 253, 255, 159, 0}, 
//This usedUVValue(4) is 0x0040, 0x017f 
//This Vertex(5) is already in memory... SKIP...! 
//Vertex Check: 7  Index: 5  Count: 5  
 //Vert 7, Loop 6, Redirect 5 Index+Offset: 5      //Vertex Check: 3  Index: 5  Count: 5  
 //Vert 3, Loop 7, Redirect 6 Index+Offset: 6      //Vertex Check: 2  Index: 5  Count: 5  
 //Vert 2, Loop 8, Redirect 4 Index+Offset: 6      //Adjusting redirectValueCheck
   { 29.99, -71.07, 304.86, 1, 0x0007, 0x2ffb, 253, 255, 159, 255}, 
//This usedUVValue(5) is 0x0000, 0x00bf 
   { 64.67, -35.94, -132.47, 1, 0x0007, 0x5ff3, 253, 255, 159, 0}, 
//This usedUVValue(6) is 0x0000, 0x017f 
//This Vertex(8) is already in memory... SKIP...! 
//Vertex Check: 4  Index: 7  Count: 7  
 //Vert 4, Loop 9, Redirect 7 Index+Offset: 7      //Vertex Check: 0  Index: 7  Count: 7  
 //Vert 0, Loop 10, Redirect 2 Index+Offset: 7      //Vertex Check: 3  Index: 7  Count: 7  
 //Vert 3, Loop 11, Redirect 6 Index+Offset: 7      //Adjusting redirectValueCheck
   { -30.01, -71.07, 304.86, 1, 0x2ffe, 0x2ffa, 253, 255, 159, 255}, 
//This usedUVValue(7) is 0x00bf, 0x00bf 
//This Vertex(10) is already in memory... SKIP...! 
//This Vertex(11) is already in memory... SKIP...! 
//Vertex Check: 4  Index: 8  Count: 8  
 //Vert 4, Loop 12, Redirect 7 Index+Offset: 7      //Vertex Check: 5  Index: 8  Count: 8  
 //Vert 5, Loop 13, Redirect 0 Index+Offset: 7      //Vertex Check: 0  Index: 8  Count: 8  
 //Vert 0, Loop 14, Redirect 2 Index+Offset: 7      //Adjusting redirectValueCheck
//This Vertex(12) is already in memory... SKIP...! 
//This Vertex(13) is already in memory... SKIP...! 
//This Vertex(14) is already in memory... SKIP...! 
//Vertex Check: 5  Index: 8  Count: 8  
 //Vert 5, Loop 15, Redirect 0 Index+Offset: 7      //Vertex Check: 6  Index: 8  Count: 8  
 //Vert 6, Loop 16, Redirect 3 Index+Offset: 7      //Vertex Check: 1  Index: 8  Count: 8  
 //Vert 1, Loop 17, Redirect 1 Index+Offset: 7      //Adjusting redirectValueCheck
//This Vertex(15) is already in memory... SKIP...! 
//This Vertex(16) is already in memory... SKIP...! 
//This Vertex(17) is already in memory... SKIP...! 
//Vertex Check: 6  Index: 8  Count: 8  
 //Vert 6, Loop 18, Redirect 3 Index+Offset: 7      //Vertex Check: 7  Index: 8  Count: 8  
 //Vert 7, Loop 19, Redirect 5 Index+Offset: 7      //Vertex Check: 2  Index: 8  Count: 8  
 //Vert 2, Loop 20, Redirect 4 Index+Offset: 7      //Adjusting redirectValueCheck
//This Vertex(18) is already in memory... SKIP...! 
//This Vertex(19) is already in memory... SKIP...! 
//This Vertex(20) is already in memory... SKIP...! 
//Vertex Check: 7  Index: 8  Count: 8  
 //Vert 7, Loop 21, Redirect 5 Index+Offset: 7      //Vertex Check: 4  Index: 8  Count: 8  
 //Vert 4, Loop 22, Redirect 7 Index+Offset: 7      //Vertex Check: 3  Index: 8  Count: 8  
 //Vert 3, Loop 23, Redirect 6 Index+Offset: 7      //Adjusting redirectValueCheck
//This Vertex(21) is already in memory... SKIP...! 
//This Vertex(22) is already in memory... SKIP...! 
//This Vertex(23) is already in memory... SKIP...! 
};

void newLevelObject_lightShaft_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_lightShaft_VTXPointer = &newLevelObject_lightShaft_VertList_0[0]; 

//Test Primitive Color Storage = 255, 255, 255 
//Found a new color! 
//Vertex Check: 5 
//Vertex Check: 0 
//Vertex Check: 0 
//Vert 5, Loop 0, Redirect 0 Index+Offset: 0 
//This color is already indexed! 
//Vertex Check: 1 
//Vertex Check: 0 
//Vertex Check: 0 
//Vert 1, Loop 1, Redirect 1 Index+Offset: 1 
//This color is already indexed! 
//Vertex Check: 0 
//Vertex Check: 0 
//Vertex Check: 0 
//Vert 0, Loop 2, Redirect 2 Index+Offset: 2 
//This color is already indexed! 
//Vertex Check: 6 
//Vertex Check: 3 
//Vertex Check: 0 
//Vert 6, Loop 3, Redirect 3 Index+Offset: 3 
//This color is already indexed! 
//Vertex Check: 2 
//Vertex Check: 3 
//Vertex Check: 0 
//Vert 2, Loop 4, Redirect 4 Index+Offset: 4 
//This color is already indexed! 
//Vertex Check: 1 
//Vertex Check: 3 
//Vertex Check: 0 
//Vert 1, Loop 5, Redirect 1 Index+Offset: 4 
//This color is already indexed! 
//Vertex Check: 7 
//Vertex Check: 5 
//Vertex Check: 0 
//Vert 7, Loop 6, Redirect 5 Index+Offset: 5 
//This color is already indexed! 
//Vertex Check: 3 
//Vertex Check: 5 
//Vertex Check: 0 
//Vert 3, Loop 7, Redirect 6 Index+Offset: 6 
//This color is already indexed! 
//Vertex Check: 2 
//Vertex Check: 5 
//Vertex Check: 0 
//Vert 2, Loop 8, Redirect 4 Index+Offset: 6 
//This color is already indexed! 
//Vertex Check: 4 
//Vertex Check: 7 
//Vertex Check: 0 
//Vert 4, Loop 9, Redirect 7 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 0 
//Vertex Check: 7 
//Vertex Check: 0 
//Vert 0, Loop 10, Redirect 2 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 3 
//Vertex Check: 7 
//Vertex Check: 0 
//Vert 3, Loop 11, Redirect 6 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 4 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 4, Loop 12, Redirect 7 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 5 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 5, Loop 13, Redirect 0 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 0 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 0, Loop 14, Redirect 2 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 5 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 5, Loop 15, Redirect 0 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 6 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 6, Loop 16, Redirect 3 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 1 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 1, Loop 17, Redirect 1 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 6 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 6, Loop 18, Redirect 3 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 7 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 7, Loop 19, Redirect 5 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 2 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 2, Loop 20, Redirect 4 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 7 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 7, Loop 21, Redirect 5 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 4 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 4, Loop 22, Redirect 7 Index+Offset: 7 
//This color is already indexed! 
//Vertex Check: 3 
//Vertex Check: 8 
//Vertex Check: 0 
//Vert 3, Loop 23, Redirect 6 Index+Offset: 7 
// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 2: START ------------------------------------------ LightShaft -------------------------------------------------
//Material: 2 'LightShaft'
//4b Color Index Palette:  Custom: False  Name: Xport64Debug_AmberBrew_tlut 
//Primitive Color: [1.00] [0.96] [0.42] [0.25] 
//Environment Color: [0.00] [0.17] [0.29] [1.00] 
//Texture Image Name: 2 'Xport64Debug_AmberBrew'
//Texture Image Size: 64 x 64


//>-- MATERIAL END ------------------------------------------ LightShaft -------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gDPSetCycleType( glistp++,  G_CYC_2CYCLE );
   gSPClearGeometryMode( glistp++,  0xFFFFFFFF );
   gSPSetGeometryMode( glistp++,   G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, SHADE, PRIMITIVE, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_AmberBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_AmberBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetColorDither(  glistp++,  G_CD_NOISE );
   gDPSetPrimColor(glistp++,  1,255,255,245,107,64  );


//Testing for use1Triangle
//NOTE ---- Combine both UVCoords updates into 2Triangles commands 

//Tri 1 of 2: faceOptions[0] 1
//Tri 2 of 2: faceOptions[1] 0
// OptionSet1...
   gSPVertex(glistp++,  newLevelObject_lightShaft_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 1, 3  );

//modifyVertexCompare[1][6]

//Testing for use1Triangle
//NOTE ---- tri1:(5, 6, 4) 
//NOTE ---- tri2:(6) is modifying a value used in tri1:(5, 6, 4) 
//NOTE ---- Split into separate 1Triangle commands 

//Tri 1 of 2: faceOptions[0] -1
//Tri 2 of 2: faceOptions[1] 2
// OptionSet4 1/2...
     gSP1Triangle(glistp++,   5, 6, 4, 5  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x3ffc5ff1);  /*New Coords: 255.94, 383.77*/
     gSP1Triangle(glistp++,   7, 2, 6, 7  );

//Testing for use1Triangle
//NOTE ---- Combine both UVCoords updates into 2Triangles commands 

//Tri 1 of 2: faceOptions[0] 0
//Tri 2 of 2: faceOptions[1] 0
// OptionSet3...
     gSP2Triangles(glistp++,   7, 0, 2, 7, 0, 3, 1, 0  );

//modifyVertexCompare[1][5]

//Testing for use1Triangle
//NOTE ---- tri1:(3, 5, 4) 
//NOTE ---- tri2:(5) is modifying a value used in tri1:(3, 5, 4) 
//NOTE ---- Split into separate 1Triangle commands 

//Tri 1 of 2: faceOptions[0] -1
//Tri 2 of 2: faceOptions[1] 2
// OptionSet4 1/2...
     gSP1Triangle(glistp++,   3, 5, 4, 3  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x3ffc2ff9);  /*New Coords: 255.94, 191.90*/
     gSP1Triangle(glistp++,   5, 7, 6, 5  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 17: END ------------------------------------------- newLevelObject_lightShaft -------------------------------------------------

 
 
//>-- OBJECT 18: START ------------------------------------------ newLevelObject_transpCube -------------------------------------------------

Vtx newLevelObject_transpCube_VertList_0 [] = {
   { -30.00, 30.00, 59.40, 1, 0x1ffe, 0x1000, 255, 255, 255, 255}, 
   { -30.00, 30.00, -0.60, 1, 0x1ffe, 0x1ffd, 255, 255, 255, 255}, 
   { -30.00, -30.00, -0.60, 1, 0x2ffb, 0x1ffd, 255, 255, 255, 255}, 
   { 30.00, 30.00, 59.40, 1, 0x1001, 0x1000, 255, 255, 255, 255}, 
   { 30.00, 30.00, -0.60, 1, 0x1001, 0x1ffd, 255, 255, 255, 255}, 
   { 30.00, -30.00, 59.40, 1, 0x0004, 0x1000, 255, 255, 255, 255}, 
   { 30.00, -30.00, -0.60, 1, 0x0004, 0x1ffd, 255, 255, 255, 255}, 
   { -30.00, -30.00, 59.40, 1, 0x2ffb, 0x0fff, 255, 255, 255, 255}, 
};

void newLevelObject_transpCube_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_transpCube_VTXPointer = &newLevelObject_transpCube_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 1: START ------------------------------------ 'Material2'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_AmberBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_AmberBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,86  );

   gSPVertex(glistp++,  newLevelObject_transpCube_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0x2ffc2ffa);  /*New Coords: 191.94, 191.91*/   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x3ff92ffa);  /*New Coords: 255.89, 191.91*/   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x3ff91ffd);  /*New Coords: 255.89, 127.95*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x10010003);  /*New Coords: 64.02, 0.05*/   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x00030003);  /*New Coords: 0.06, 0.05*/
     gSP2Triangles(glistp++,   1, 4, 6, 1, 3, 0, 7, 3  );
     gSP2Triangles(glistp++,   2, 1, 6, 2, 5, 3, 7, 5  );


//>-- MATERIAL 2: START ------------------------------------ 'AlphaTexture'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineLERP(  glistp++, 	TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A,G_RM_AA_ZB_XLU_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_1bAlphaBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_CLAMP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_1bAlphaBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_BILERP );
   gDPSetPrimColor(glistp++,  1,255,125,255,204,229  );

   gSPVertex(glistp++,  newLevelObject_transpCube_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 1, 3  );
     gSP1Triangle(glistp++,   5, 6, 4, 5  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x3ff91ffd);  /*New Coords: 255.89, 127.95*/
     gSP1Triangle(glistp++,   7, 2, 6, 7  );
     gSP2Triangles(glistp++,   7, 0, 2, 7, 0, 3, 1, 0  );
     gSP1Triangle(glistp++,   3, 5, 4, 3  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x3ff80fff);  /*New Coords: 255.89, 64.00*/
     gSP1Triangle(glistp++,   5, 7, 6, 5  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 18: END ------------------------------------------- newLevelObject_transpCube -------------------------------------------------

 
 
//>-- OBJECT 19: START ------------------------------------------ newLevelObject -------------------------------------------------

Vtx newLevelObject_VertList_0 [] = {
//Found a new color! Color Index: 1     Vert 2:  149, 3, 103 
   { -30.00, 30.00, 60.20, 1, 0x1ffe, 0x1000, 255, 255, 255, 255}, 
   { -30.00, 30.00, 0.20, 1, 0x1ffe, 0x1ffd, 255, 255, 255, 255}, 
   { -30.00, -30.00, 0.20, 1, 0x2ffb, 0x1ffd, 149, 3, 103, 255}, 
//Found a new color! Color Index: 2     Vert 0:  0, 148, 22 
//Found a new color! Color Index: 3     Vert 2:  164, 216, 172 
   { 30.00, 30.00, 60.20, 1, 0x1001, 0x1000, 0, 148, 22, 255}, 
   { 30.00, 30.00, 0.20, 1, 0x1001, 0x1ffd, 0, 148, 22, 255}, 
   { 30.00, -30.00, 60.20, 1, 0x0004, 0x1000, 255, 255, 255, 255}, 
   { 30.00, -30.00, 0.20, 1, 0x0004, 0x1ffd, 255, 255, 255, 255}, 
//Found a new color! Color Index: 4     Vert 0:  148, 0, 101 
   { -30.00, -30.00, 60.20, 1, 0x2ffb, 0x0fff, 148, 0, 101, 255}, 
};

void newLevelObject_PolyList(u8 animFrame){ 

   Vtx *newLevelObject_VTXPointer = &newLevelObject_VertList_0[0]; 

// Set Scene Light: 
   gSPSetLights1( glistp++,  DefaultSceneLight );


//>-- MATERIAL 0: START ------------------------------------ 'Material'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_BlueBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_BlueBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,255  );

   gSPVertex(glistp++,  newLevelObject_VTXPointer+0,31,0  );
     gSP2Triangles(glistp++,   0, 1, 2, 0, 3, 4, 1, 3  );
     gSP1Triangle(glistp++,   5, 6, 4, 5  );
   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x3ff91ffd);  /*New Coords: 255.89, 127.95*/
     gSP1Triangle(glistp++,   7, 2, 6, 7  );
     gSP2Triangles(glistp++,   7, 0, 2, 7, 0, 3, 1, 0  );
     gSP1Triangle(glistp++,   3, 5, 4, 3  );
   gSPModifyVertex(glistp++,  5,   G_MWO_POINT_ST, 0x3ff80fff);  /*New Coords: 255.89, 64.00*/
     gSP1Triangle(glistp++,   5, 7, 6, 5  );


//>-- MATERIAL 1: START ------------------------------------ 'Material2'-------------------------------------------------
//NOTE ---- IN LINE commands is a WIP and more commands will be added. 
   gDPPipeSync( glistp++ );
   gSPTexture(  glistp++,  0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  );
   gDPSetTextureLUT(  glistp++,  G_TT_RGBA16 );
   gDPSetCombineMode(  glistp++,  G_CC_MODULATERGB, G_CC_PASS2 );
   gDPSetRenderMode(  glistp++,  G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  );
   gDPLoadTextureBlock_4b(  glistp++,  Xport64Debug_AmberBrew,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP,G_TX_WRAP, 6,6, 1,1 );
   gDPLoadTLUT_pal16(  glistp++,  0, Xport64Debug_AmberBrew_tlut );
   gDPSetTextureFilter(  glistp++,  G_TF_AVERAGE );
   gDPSetPrimColor(glistp++,  1,255,239,0,255,86  );

   gSPVertex(glistp++,  newLevelObject_VTXPointer+0,31,0  );
   gSPModifyVertex(glistp++,  1,   G_MWO_POINT_ST, 0x2ffc2ffa);  /*New Coords: 191.94, 191.91*/   gSPModifyVertex(glistp++,  4,   G_MWO_POINT_ST, 0x3ff92ffa);  /*New Coords: 255.89, 191.91*/   gSPModifyVertex(glistp++,  6,   G_MWO_POINT_ST, 0x3ff91ffd);  /*New Coords: 255.89, 127.95*/   gSPModifyVertex(glistp++,  0,   G_MWO_POINT_ST, 0x10010003);  /*New Coords: 64.02, 0.05*/   gSPModifyVertex(glistp++,  7,   G_MWO_POINT_ST, 0x00030003);  /*New Coords: 0.06, 0.05*/
     gSP2Triangles(glistp++,   1, 4, 6, 1, 3, 0, 7, 3  );
     gSP2Triangles(glistp++,   2, 1, 6, 2, 5, 3, 7, 5  );
   gDPPipeSync(  glistp++  );
} 

//>-- OBJECT 19: END ------------------------------------------- newLevelObject -------------------------------------------------

 
 