bl_info = {
  "name": "Xport64 v1.0",
  "description": "Export to N64 Display List",
  "author": "WadeMalone",
  "version": (1, 0, 0),
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

#-------------------------------------------------------------------------------------------------
#NOTES: The following external scripts/modules should be placed in the same directory as this one
#-------------------------------------------------------------------------------------------------


#If this is not first start up and you need to reload the script, press F8 in the blender window. This will force reload all __init__. 
#If you have done this reload process, then the following if statement will run:
if "bpy" in locals():
    import imp
    imp.reload(panel)
    imp.reload(export)
    imp.reload(gbicom)

#if you have not loaded your scripts yet, the following lines of code will run:    
from .panel import ObjectProp_Xport64, MaterialProp_Xport64, SceneProp_Xport64, LightProp_Xport64, Setup_Xport64, Object_Tabs_Xport64, Scene_Xport64, Object_Xport64
from .export import VTX_Xport64, Lights_Xport64, Poly_Xport64, Header_Xport64
from .gbicom import GBI_Xport64, TEXTURE_4B_TLUT
    
externclasses = [ ObjectProp_Xport64, MaterialProp_Xport64, GBI_Xport64, SceneProp_Xport64, LightProp_Xport64, Setup_Xport64, Object_Tabs_Xport64, Scene_Xport64, Object_Xport64, VTX_Xport64, Lights_Xport64, Poly_Xport64, Header_Xport64]

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
    precision   = 2)
  
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
        
    file.write("\n Vector3 tempObjVectorPos;\n Vector3 tempObjVectorRot;\n Vector3 tempObjVectorScl;\n\n ")
    
    
    Lights_Xport64.exportSCNLights(self, file)
    for obj in bpy.context.scene.objects:
        if obj.type == 'MESH' and descends(bpy.context.selected_objects, obj):
            Lights_Xport64.exportOBJLights(self, file, obj)
    
    for obj in bpy.context.scene.objects:
      if obj.type == 'MESH' and descends(bpy.context.selected_objects, obj):
        bpy.context.scene.frame_set(0)
        
        #In order to render the object properly, we need to triangulate any quads.        
        originalMesh = obj.to_mesh(bpy.context.scene, True, 'PREVIEW') #duplicate Mesh at the time of export
        tempMesh = obj.to_mesh(bpy.context.scene, True, 'PREVIEW') #create a duplicate of the Mesh for triangulating
        mesh_triangulate(tempMesh) #triangulate this temporary mesh
        obj.data = tempMesh #set objects current mesh to temporary mesh
        
        objectName = self.clean_name(obj.name)
        
        VTX_Xport64.exportVert(self, file, obj,objCounter)
        
        Poly_Xport64.exportPoly(self, file, obj,objCounter)
        objCounter +=1
        bpy.context.scene.frame_set(0)
        obj.data = originalMesh #return original, un-triangulated mesh
    
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
    
    for cls in externclasses:
        bpy.utils.register_class(cls)        
    bpy.types.Scene.scene_props = bpy.props.PointerProperty(type = SceneProp_Xport64)
    bpy.types.Scene.scene_lights = bpy.props.PointerProperty(type = LightProp_Xport64)
    bpy.types.Object.obj_props = bpy.props.PointerProperty(type = ObjectProp_Xport64)
    bpy.types.Object.obj_lights = bpy.props.PointerProperty(type = LightProp_Xport64)
    bpy.types.Material.mat_props = bpy.props.PointerProperty(type = MaterialProp_Xport64)
    bpy.types.Material.mat_lights = bpy.props.PointerProperty(type = LightProp_Xport64)
  
      
def unregister():
    bpy.utils.unregister_class(ExportN64DisplayList)
    bpy.types.INFO_MT_file_export.remove(menu_func)

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

   