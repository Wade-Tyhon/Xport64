bl_info = {
  "name": "Xport64 v1.0",
  "description": "Export to N64 Display List",
  "author": "WadeMalone",
  "version": (1, 0, 1),
  "blender": (2, 76, 0),
  "warning": "",
  "location": "File > Import-Export",
  "wiki_url": "",
  "tracker_url": "",
  "support": "COMMUNITY",
  "category": "Import-Export" }  

import bpy
import string

PRE_BUILT_SETTINGS = {

    "TEXTURE_4B" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n", 
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_RGBA16 %s\n",                            
        "SetCombineMode" : "   %sDPSetCombineMode(  %s G_CC_MODULATERGB, G_CC_PASS2 %s\n",        
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  %s\n",
        "LoadTextureBlock_4b" : "   %sDPLoadTextureBlock_4b(  %s %s,	G_IM_FMT_CI,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "SetTextureFilter" : "   %sDPSetTextureFilter(  %s %s %s\n",
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",
    },
    
    "ALPHA_TEXTURE_4B" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n",
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_RGBA16 %s\n",
        "SetCombineLERP" : "   %sDPSetCombineLERP(  %s	TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED %s\n",        
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A,G_RM_AA_ZB_XLU_SURF2  %s\n", #AA should be turned on for transparent textures
        "LoadTextureBlock_4b" : "   %sDPLoadTextureBlock_4b(  %s %s,	G_IM_FMT_CI,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "ForceBilerpFilter" : "   %sDPSetTextureFilter(  %s G_TF_BILERP %s\n",  #For best alpha quality, BILERP needs to be used     
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",
    },

#NOTE ----- TEXTURE_16B_RGBA_LIT - For use with objects using 16b RGBA textures and being lit using "real time" lighting or "baked" vertex color lighting   
    "TEXTURE_16B_RGBA_LIT" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "TileSync" : "   %sDPTileSync(%s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_2CYCLE %s\n",
        "ClearGeometryMode" : "   %sSPClearGeometryMode( %s 0xFFFFFFFF %s\n",
        "SetGeometryMode" : "   %sSPSetGeometryMode( %s  G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_CULL_BACK  %s\n",
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n",        
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_NONE %s\n",
        "SetCombineLERP" : "   %sDPSetCombineLERP(  %s	TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED %s\n",
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2  %s\n", #AA should be turned on for transparent textures
        "LoadTextureBlock" : "   %sDPLoadTextureBlock(  %s %s,	G_IM_FMT_RGBA, G_IM_SIZ_16b,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "SetTextureFilter" : "   %sDPSetTextureFilter(  %s %s %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",        
    },    
    
#NOTE ----- TEXTURE_16B_RGBA_UNLIT - For use with "emissive" objects that are NOT shaded by "real time" or "baked" vertex color lighting
    "TEXTURE_16B_RGBA_UNLIT" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "TileSync" : "   %sDPTileSync(%s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_2CYCLE %s\n",
        "ClearGeometryMode" : "   %sSPClearGeometryMode( %s 0xFFFFFFFF %s\n",
        "SetGeometryMode" : "   %sSPSetGeometryMode( %s  G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH | G_CULL_BACK  %s\n",        
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n",        
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_NONE %s\n",
        "SetCombineLERP" : "   %sDPSetCombineLERP(  %s	TEXEL0, 0, TEXEL0, 0, TEXEL0, 0, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED %s\n",
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2  %s\n", #AA should be turned on for transparent textures
        "LoadTextureBlock" : "   %sDPLoadTextureBlock(  %s %s,	G_IM_FMT_RGBA, G_IM_SIZ_16b,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "SetTextureFilter" : "   %sDPSetTextureFilter(  %s %s %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",        
    },

    "PRIM_COLORS_SHADED" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_2CYCLE %s\n",
        "ClearGeometryMode" : "   %sSPClearGeometryMode( %s (G_SHADE|G_SHADING_SMOOTH|G_LIGHTING|G_TEXTURE_GEN|G_TEXTURE_GEN_LINEAR|G_CULL_BOTH|G_FOG) %s\n",
        "SetGeometryMode" : "   %sSPSetGeometryMode( %s G_ZBUFFER | G_CULL_BACK | G_SHADE| G_FOG | G_SHADING_SMOOTH | G_LIGHTING %s\n",        
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF  %s\n", 
        "SetColorDither" : "   %sDPSetColorDither(  %s G_CD_BAYER %s\n",
        "SetCombineLERP" : "   %sDPSetCombineLERP(  %s	PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED %s\n",            
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2  %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",
    },
    
    "PRIM_COLORS_UNLIT" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_1CYCLE %s\n",
        "ClearGeometryMode" : "   %sSPClearGeometryMode( %s (G_SHADE|G_SHADING_SMOOTH|G_LIGHTING|G_TEXTURE_GEN|G_TEXTURE_GEN_LINEAR|G_CULL_BOTH|G_FOG) %s\n",
        "SetGeometryMode" : "   %sSPSetGeometryMode( %s G_ZBUFFER | G_CULL_BACK | G_SHADE | G_SHADING_SMOOTH %s\n",        
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF  %s\n", 
        "SetColorDither" : "   %sDPSetColorDither(  %s G_CD_BAYER %s\n",                            
        "SetCombineMode" : "   %sDPSetCombineMode(  %s G_CC_PRIMITIVE, G_CC_PRIMITIVE %s\n",        
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2  %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",
    },
    
    "TEX_4B_I_EFFECT" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_2CYCLE %s\n",
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n",       
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_IA16 %s\n",
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n",
        "SetCombineLERP" : "   %sDPSetCombineLERP(  %s	TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, 1, 0, 0, COMBINED, TEXEL0, 0, 0, COMBINED %s\n",
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A,G_RM_AA_ZB_XLU_SURF2  %s\n", #AA should be turned on for transparent textures
        "LoadTextureBlock_4b" : "   %sDPLoadTextureBlock_4b(  %s %s,	G_IM_FMT_I,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "ForceBilerpFilter" : "   %sDPSetTextureFilter(  %s G_TF_BILERP %s\n",  #For best alpha quality, BILERP needs to be used
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",        
    },
    
    "TEX_4B_CI_LIQUID" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_2CYCLE %s\n",
        "ClearGeometryMode" : "   %sSPClearGeometryMode( %s 0xFFFFFFFF %s\n",
        "SetGeometryMode" : "   %sSPSetGeometryMode( %s G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH %s\n",
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n",        
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_RGBA16 %s\n",
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n",
        "SetCombineLERP" : "   %sDPSetCombineLERP(  %s	TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED %s\n",
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  %s\n", #AA should be turned on for transparent textures
        "LoadTextureBlock_4b" : "   %sDPLoadTextureBlock_4b(  %s %s,	G_IM_FMT_CI,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "ForceBilerpFilter" : "   %sDPSetTextureFilter(  %s G_TF_BILERP %s\n",  #For best alpha quality, BILERP needs to be used     
        "SetColorDither" : "   %sDPSetColorDither(  %s G_CD_NOISE %s\n", 
        "SetAlphaDither" : "   %sDPSetAlphaDither(  %s G_CD_NOISE %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",        
    },
    
    "TEX_4B_CI_LIGHTSHAFT" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_2CYCLE %s\n",
        "ClearGeometryMode" : "   %sSPClearGeometryMode( %s 0xFFFFFFFF %s\n",
        "SetGeometryMode" : "   %sSPSetGeometryMode( %s  G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH %s\n",
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n",        
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_RGBA16 %s\n",
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n",
        "SetCombineLERP" : "   %sDPSetCombineLERP(  %s	TEXEL0, 0, SHADE, 0, SHADE, PRIMITIVE, 1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED %s\n",
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2  %s\n", #AA should be turned on for transparent textures
        "LoadTextureBlock_4b" : "   %sDPLoadTextureBlock_4b(  %s %s,	G_IM_FMT_CI,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "ForceBilerpFilter" : "   %sDPSetTextureFilter(  %s G_TF_BILERP %s\n",  #For best alpha quality, BILERP needs to be used  
        "SetColorDither" : "   %sDPSetColorDither(  %s G_CD_NOISE %s\n", 
        "SetAlphaDither" : "   %sDPSetAlphaDither(  %s G_CD_NOISE %s\n",
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",        
    },
    
    "TEXTURE_4B_EDGE" : {
        "PipeSync" : "   %sDPPipeSync( %s %s\n",
        "CycleType" : "   %sDPSetCycleType( %s G_CYC_1CYCLE %s\n",
        "ClearGeometryMode" : "   %sSPClearGeometryMode( %s 0xFFFFFFFF %s\n",
        "SetGeometryMode" : "   %sSPSetGeometryMode( %s  G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH %s\n",
        "Texture" : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n",        
        "TextureLUT" : "   %sDPSetTextureLUT(  %s G_TT_RGBA16 %s\n",
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n",
        "SetCombineMode" : "   %sDPSetCombineMode(  %s G_CC_MODULATERGBDECALA, G_CC_MODULATERGBDECALA %s\n",
        "SetRenderMode" : "   %sDPSetRenderMode(  %s G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2  %s\n", #AA should be turned on for transparent textures
        "LoadTextureBlock_4b" : "   %sDPLoadTextureBlock_4b(  %s %s,	G_IM_FMT_CI,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "ForceBilerpFilter" : "   %sDPSetTextureFilter(  %s G_TF_BILERP %s\n",  #For best alpha quality, BILERP needs to be used
        "UsageTip" : "//>-- SHOWTIPS -- Place Holder... \n",
        "Debug" : "//>-- DEBUG -- Place Holder... \n",        
    },

}

TEXTURE_4B_TLUT = {
        0 : "   %sDPPipeSync( %s %s\n",
        1 : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n", 
        2 : "   %sDPSetTextureLUT(  %s G_TT_RGBA16 %s\n",                            
        3 : "   %sDPSetCombineMode(  %s G_CC_MODULATERGB, G_CC_PASS2 %s\n",        
        4 : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  %s\n",
        "LoadTexture" : "   %sDPLoadTextureBlock_4b(  %s %s	G_IM_FMT_CI,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "TextureFilter" : "   %sDPSetTextureFilter(  %s %s %s\n",
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n"
    }

class GBI_Xport64(bpy.types.Operator):
    bl_idname = "gbidictionary.xport64"
    bl_label = "Xport64 - GBI Dictionary"
    
    TEXTURE_4B_TLUT_V3 = {
        0 : "   %sDPPipeSync( %s %s\n",
        1 : "   %sSPTexture(  %s 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON  %s\n", 
        2 : "   %sDPSetTextureLUT(  %s G_TT_RGBA16 %s\n",                            
        3 : "   %sDPSetCombineMode(  %s G_CC_MODULATERGB, G_CC_PASS2 %s\n",
        4 : "   %sDPSetTextureFilter(  %s G_TF_AVERAGE %s\n",
        5 : "   %sDPSetRenderMode(  %s G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2  %s\n",
        "LoadTexture" : "   %sDPLoadTextureBlock_4b(  %s %s	G_IM_FMT_CI,	%i, %i,	0, %s,%s, %s,%s, %s,%s %s\n",
        "LoadTLUT" : "   %sDPLoadTLUT_pal16(  %s 0, %s %s\n\n"
    }
