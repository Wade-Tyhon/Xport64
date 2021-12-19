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

#NOTES: While this version shares almost none of the original code, this project was kick started by using Blen64 by GCaldL, an early N64 Blender plug in. 
#Thanks to him for taking that first step! 

#NOTES Revision 1.1 from 9.26.2021 - updated from n64exp v2.1 to Xport64 v1.0. This build will be made available for public use and is more generalized.
#TO DO: gSP2Triangle, clean up and comment code
#TO-DO NOTES - export.py: Completely re-do export process from scratch - simplify and clean up process

#---------------------------------------------------------------------------------------------------------
#--------------------------------------------NEXT UPDATES-------------------------------------------------
#---------------------------------------------------------------------------------------------------------
#                   - Add settings for fully customized GBI Commands
#                   - Add setting for printing Macros GBI Commands (that take arguments)
#                   - 
#---------------------------------------------------------------------------------------------------------

#---------------------------------------------------------------------------------------------------------
#-----------------------------------------MOST RECENT UPDATES---------------------------------------------
#---------------------------------------------------------------------------------------------------------
#UPDATE 12/18/2021: 
#                   - Multiple animations now supported with the action editor
#                   - Xport64 Animation rig basics now included, should be completed in next update
#                   - Fixed error in naming where "SetAlphaDither" lines were not being called
#                   - Added additional checks for UV coordinates to make sure that a vertex modified in tri2 (modifyVertexCompare[1][*]) is not altering an unmodified vertex in tri1 (gSP2TriangleHold[0][*]+offset)                                        
#                   - Fix collision export bug where collision tri's were exporting multiple times (once for each vertex color)
#                   - Support negative U/V (S/T) values when converting from int to hexidecimal   
#                           - Begins on 1425 and uses checknegativehex to check and convert values and store them in S_Coordinates and T_Coordinate
#                   - Added DEBUG message for material light
#                   - General bug fixes and UI improvements
#UPDATE 11/30/2021: 
#                   - Fixed error with negative S/T variables
#                   - Added new UI updates  
#                   - Added DEBUG message for material light
#                   - Fixed collision export bug caused by old code not being completely scrubbed. In previous build, some faces in a collision object would not export if UV colors or texture were different on some faces.
#                   - Added new object rig options to use default Xport64 rig or to include your own command
#                   - Updated Scene/Obj/Mat light to optionally enter your values manually
#                   - Fixed error where obj light name was triggering a duplicate light name for material lights, unusedLight variable is now re-set with every material check. 
#                   - Added some guidance to plug-in on what is needed to properly use this plug-in
#UPDATE 11/5/2021:  - Fixed error where material and object lights were not printing if set to ambient only with no directional(aka diffuse) lights.
#                   - Added optional animFrame parameter for dynamic display lists as an option for updating the current frame of an animation. Enable as needed for each object.
#                   - Added TEXTURE_4B_UNLIT to pre-built commands for "emmissive" unlit textured objects. 
#UPDATE 11/4/2021:  - Several error checks added to __init__.py export.py and panel.py and fixes in case user 
#                   attempts to export an object with no material or uses attempts to use a texture material on 
#                   an object lacking an Image Texture node and image.
#---------------------------------------------------------------------------------------------------------

#If this is not first start up and you need to reload the script, press F8 in the blender window. This will force reload all __init__. 
#If you have done this reload process, then the following if statement will run:
if "bpy" in locals():
    import imp
    imp.reload(panel)
    imp.reload(export)
    imp.reload(gbicom)

#if you have not loaded your scripts yet, the following lines of code will run:    
from .panel import ObjectProp_Xport64, MaterialProp_Xport64, SceneProp_Xport64, LightProp_Xport64, Setup_Xport64, Object_Tabs_Xport64, Scene_Xport64, AssignTexture_Xport64, Object_Xport64
from .export import VTX_Xport64, Lights_Xport64, Poly_Xport64, Header_Xport64
from .gbicom import GBI_Xport64, TEXTURE_4B_TLUT
    
externclasses = [ ObjectProp_Xport64, MaterialProp_Xport64, GBI_Xport64, SceneProp_Xport64, LightProp_Xport64, Setup_Xport64, AssignTexture_Xport64, Object_Tabs_Xport64, Scene_Xport64, Object_Xport64, VTX_Xport64, Lights_Xport64, Poly_Xport64, Header_Xport64]

#-------------------------------------------------------------------------------------------------

    
#from . import panel    
#import panel as myModule   

import bpy
import os
import random
import string
import math
import bpy
import mathutils
import copy
import bpy.utils.previews


#---------------------------------------------------------------------------------------
#TO-DO NOTES: Begin editing here to change the Xport64 Object Settings Window in Blender
#---------------------------------------------------------------------------------------

from bpy.props import(
    BoolProperty,
    IntProperty,
    FloatProperty,
    FloatVectorProperty,
    PointerProperty,
    StringProperty,
)

from bpy.types import (
    Panel,
    Menu,
    Operator,
    PropertyGroup,
)

xport64_icons = None
#from panel import MyProperties

def descends(parents, child):
  while child and child not in parents:
    child = child.parent
  return child != None
  
class ExportN64DisplayList(bpy.types.Operator):
  bl_idname = "export.xport_64"
  bl_label = "Xport 64"

  scale = bpy.props.FloatProperty(
    name        = "Scale",
    description = "Scalar multiplier.",
    default     = 1.0,
    min         = 0.01,
    max         = 1000.0,
    precision   = 4)
    
  skipDupFrames = bpy.props.BoolProperty(
    name        = "Skip Duplicate Frames",
    description = "If exporting animations, skip any duplicate frames.",
    default     = True,
  )
  
  sttile = bpy.props.FloatProperty(
    name        = "Texture Tiling",
    description = "Set as 1 for 1:1 scaling with no tiling, increase for tiling. (ex. 2 will tile twice)",
    default     = 1.0,
    min         = 1.0,
    max         = 10.0,
    precision   = 1
  )
  debugCheck = bpy.props.BoolProperty(
    name        = "Print Debug Data",
    description = "If export is not working, this will provide some data that might help diagnose",
    default = False,
    )    

  
  filepath = bpy.props.StringProperty(subtype="FILE_PATH")
  directory = bpy.props.StringProperty(subtype = "DIR_PATH")
  filename = bpy.props.StringProperty(subtype = "FILE_PATH")
  #filename = ""
  headerFileName = ""

  exportPolyList = True
  usedUVValues = [[[]]] #This stores the UV values actually used in the VTXlist. It is used for comparison in the polylist
  uvValue = [[[]]]#for storing UV coordinates  [object][vertex][u,v]  
  allVertexColors = [[[]]]
  materials = [[[]]]
  matPrimColors = [[[]]]
  
#NOTE ----- scnLights, objLights, and matLights store all light structures that need to be used by this scene

  N64LightNames = [[]]  #Material specific light source, this overwrites the object light source (objLights). At the end of the material, re-assign (objLights) if applicable. - matLights[ObjectID][LightName][Commands]
  N64LightCount = 0
#NOTE ----- stores all definitions/declarations that needed to be printed in header file for use in external functions
  definitionsFile = [] 
  commandCount = 0
  names = {}
  
  
  def clean_name(self, name):
    # Only take the characters from the name that are valid for C identifiers.
    # Note that this makes it possible to have a duplicate, so we test against all
    # previous names before using.
    
    name = "".join(c for c in name if
      c in string.ascii_letters or
      c in string.digits or
      c == '_')
    if len(name) == 0 or name[0] in string.digits:
      name = "_" + name

    return name
    
  def testLights(self, object):
        object.write("//Test lighting def...\n")
        
  def printIncludes(self, file):
        scene = bpy.context.scene
        sceneprops = scene.scene_props
        if self.headerFileName != "": #Main header file for this scene defined by the file name + the header ID in Xport64 Scene Settings
            file.write('//NOTE ----- Definitions and Declarations for this script are in: "%s.h"\n'% self.headerFileName)  
        if sceneprops.scene_Includes1 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes1)              
        if sceneprops.scene_Includes2 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes2)
        if sceneprops.scene_Includes3 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes3)
        if sceneprops.scene_Includes4 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes4)
        if sceneprops.scene_Includes5 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes5)
        if sceneprops.scene_Includes6 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes6)
        if sceneprops.scene_Includes7 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes7)
        if sceneprops.scene_Includes8 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes8)
        if sceneprops.scene_Includes9 != "":
            file.write('#include "%s"\n'%sceneprops.scene_Includes9)
        if sceneprops.scene_Includes10 != "":    
            file.write('#include "%s"\n'%sceneprops.scene_Includes10)
            
            

  def execute(self, context):
    self.usedUVValues = [[[]]] #This stores the UV values actually used in the VTXlist. It is used for comparison in the polylist
    self.uvValue = [[[]]]#for storing UV coordinates  [object][vertex][u,v]
    self.allVertexColors = [[[]]] #for storing all vertex colors [obj][vertex][x,y,z]
    self.materials = [[[]]] #VER NOTE - DEPRECIATED (No longer needed, will likely be removed in next version)
    self.matPrimColors = [[[]]] #VER NOTE - DEPRECIATED (No longer needed, will likely be removed in next version)
    self.N64LightNames = [[]] #Material specific light source, this overrides the object light source (objLights). At the end of the material, re-assign (objLights) if applicable.

    self.definitionsFile = [] #store all lines that need to be printed in definitions/declarations header file
    self.commandCount = 0
    
    names = {}
    objCounter = 0
    bpy.ops.object.mode_set(mode='OBJECT')
    
    sceneProps = bpy.context.scene.scene_props
    
#NOTE ----- This is the main .c file that will be exported
    file = open(self.directory + self.filename + '_%s_objs.c'% sceneProps.current_scene_id, 'w')
        
    exportFrame = bpy.context.scene.frame_current
    
    self.printIncludes(file) #print scene includes
    
#NOTE ----- Before beginning each object's Export Vert/Poly, create temp variables that are shared between them (lights, pos/rot/scl, etc):
    
    
#NOTE ----- For each scene, check to see if any of the objects use the "OBJ VARIABLES" animation method.
#           If so, then after checking all lights in each object, print temp variable initializing
    
    tempObjVariables = False    
    Lights_Xport64.exportSCNLights(self, file)
    
    for obj in bpy.context.scene.objects:    
        if obj.type == 'MESH' and descends(bpy.context.selected_objects, obj):
            if obj.data.materials != None and obj.active_material != None:
                Lights_Xport64.exportOBJLights(self, file, obj)
                
            else:
                #print("Make sure all objects contain a material.")
                print("Object %s does not have a material assigned!" % obj.name)
                self.report({'WARNING'}, "Xport64 WARNING ----- Object %s does not have a material assigned and could not be exported." % obj.name)
                return {'FINISHED'}
                
            if obj.obj_props.anim_Method == "OBJ VARIABLES":
                tempObjVariables = True
    
    if tempObjVariables == True:
        file.write("\n   //NOTE ----- One or more objects is animated with a rig, so include Pos, Rot, Scl variables: \n")
        file.write("   Vector3 %s_TempVectorPos = {0,0,0}; \n" % sceneProps.current_scene_id)
        file.write("   Vector3 %s_TempVectorRot = {0,0,0}; \n" % sceneProps.current_scene_id)
        file.write("   Vector3 %s_TempVectorScl = {0,0,0}; \n\n" % sceneProps.current_scene_id)
    
    
    
    startingAnimFrame = bpy.context.scene.frame_current
    #bpy.context.object.animation_data.action = bpy.data.action['playerStartJump']
    for obj in bpy.context.scene.objects:
    
    #  bpy.context.area.type = 'DOPESHEET_EDITOR'
    #  bpy.context.space_data.mode = 'ACTION'
    #  bpy.context.object.animation_data.action = bpy.data.actions['playerStartJump']    
      
      if obj.type == 'MESH' and descends(bpy.context.selected_objects, obj):
        bpy.context.scene.frame_set(0)
        
        #In order to render the object properly, we need to triangulate any quads.        
        originalMesh = obj.to_mesh(bpy.context.scene, True, 'PREVIEW') #duplicate Mesh at the time of export

        if obj.data.materials != None and obj.active_material != None:
            tempMesh = obj.to_mesh(bpy.context.scene, True, 'PREVIEW') #create a duplicate of the Mesh for triangulating 
            mesh_triangulate(tempMesh) #triangulate this temporary mesh
            obj.data = tempMesh #set objects current mesh to temporary mesh
            tempAnimAction = "" #for storing the animation action that was active when exported
            
            
            objectName = self.clean_name(obj.name)
            
            VTX_Xport64.exportVert(self, file, obj,objCounter)
            
            
            
            Poly_Xport64.exportPoly(self, file, obj,objCounter)
            objCounter +=1
            bpy.context.area.type = 'INFO'
           # self.tempAnimAction = bpy.context.object.animation_data.action
            
            
            # self.tempAnimAction = bpy.context.object.animation_data.action
            if tempAnimAction != "": #if this object has been animated...
                bpy.context.object.animation_data.action = tempAnimAction
            
            
            bpy.context.scene.frame_set(startingAnimFrame)            
            obj.data = originalMesh #return original, un-triangulated mesh
        else:
            print("Object %s does not have a material assigned!" % obj.name)
            self.report({'WARNING'}, "Xport64 WARNING ----- Object %s does not have a material assigned and could not be exported." % obj.name)
            return {'FINISHED'}
            
    
        
      #elif obj.type == 'BONE':
        #bpy.context.object.animation_data.action = bpy.data.action['playerStartJump']
        
    if sceneProps.create_header_file == True:        
        fileH = open(self.directory + self.filename + '_%s_defs.h'% sceneProps.scene_header_id, 'w')
        self.headerFileName = (self.filename + '_%s_defs'% sceneProps.scene_header_id)
        fileH.write("#ifndef %s_H \n#define %s_H \n\n" %(self.headerFileName.upper(), self.headerFileName.upper() ))
        Header_Xport64.exportDefs(self, fileH)
        fileH.write("\n\n#endif")

    return {'FINISHED'}
    
  def invoke(self, context, event):
    context.window_manager.fileselect_add(self)
    return {'RUNNING_MODAL'}

    
def menu_func(self, context):
    self.layout.operator_context = 'INVOKE_DEFAULT'
    self.layout.operator(ExportN64DisplayList.bl_idname, text="N64 Display List exporter V1.1")
    

    

    
def register():
    bpy.utils.register_class(ExportN64DisplayList)
    bpy.types.INFO_MT_file_export.append(menu_func)
    
    
# ----- NOTE: Custom xport64 icons coming in future update ---------------------------------------------------------                        
    # global custom_icons
    # custom_icons = bpy.utils.previews.new()
    # #xport64_dir = bpy.props.StringProperty(subtype = "DIR_PATH")
    # xport64_dir = os.path.dirname(__file__)
    # print("Print directory %s" % xport64_dir)
    # xport64_icon_dir = ("%s\icons" %(xport64_dir))
    # print("Print icons directory %s" % xport64_icon_dir)
    # loadIcon = ("%s\%s" %(xport64_icon_dir, "xport64-logo-icons32x32.png"))
    # xport64_icons.load("xport64_Logo", loadIcon, 'IMAGE')
# ----- NOTE: Custom xport64 icons coming in future update ---------------------------------------------------------                    

    
    for cls in externclasses:
        bpy.utils.register_class(cls)        
    bpy.types.Scene.scene_props = bpy.props.PointerProperty(type = SceneProp_Xport64)
    bpy.types.Scene.scene_lights = bpy.props.PointerProperty(type = LightProp_Xport64)    
    bpy.types.Scene.image_name = bpy.props.StringProperty(name = '', subtype = "FILE_PATH")
    bpy.types.Object.obj_props = bpy.props.PointerProperty(type = ObjectProp_Xport64)
    bpy.types.Object.obj_lights = bpy.props.PointerProperty(type = LightProp_Xport64)
    bpy.types.Material.mat_props = bpy.props.PointerProperty(type = MaterialProp_Xport64)
    bpy.types.Material.mat_lights = bpy.props.PointerProperty(type = LightProp_Xport64)   
    

  
      
def unregister():
    bpy.utils.unregister_class(ExportN64DisplayList)
    bpy.types.INFO_MT_file_export.remove(menu_func)

    # global xport64_icons
    # bpy.utils.previews.remove(xport64_icons)
    
    for cls in externclasses:
        bpy.utils.unregister_class(cls)
  

def isclose(a,b,rel_tol=1e-09, abs_tol = 0.0): #checks if numbers are approximately equal 
  return abs(a-b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)
  
def mesh_triangulate(me):
    import bmesh
    bm = bmesh.new()
    bm.from_mesh(me)
    bmesh.ops.triangulate(bm, faces=bm.faces)
    bm.to_mesh(me)
    bm.free()
  
def roundtohalf(a): #rounds to nearest .5
    return round(a*2.0)/2.0
    
def roundtoquarter(a): #rounds to nearest .25
   print("Test global roundtoquarter")
   return round(a*4.0)/4.0 

   