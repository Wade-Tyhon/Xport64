bl_info = {
  "name": "export",
  "description": "Export to N64 Display List",
  "author": "WadeMalone",
  "version": (1, 0, 1),
  "blender": (2, 70, 0),
  "warning": "",
  "location": "View3D > Tool",
  "wiki_url": "",
  "tracker_url": "",
  "support": "COMMUNITY",
  "category": "N64 Model Editing" }

import bpy
import os
import random
import string
import math
import bpy
import mathutils
import copy

from .gbicom import TEXTURE_4B_TLUT, PRE_BUILT_SETTINGS, GBI_Xport64

#import settings
#from __init__ import roundtoquarter, isclose, roundtohalf

#---------------------------------------------------------------------------------------------------------
#IN PROGRESS 10/15/2021:
#
#PRIORITY    
#       - THOROUGHLY TEST ALL EXPORTS 
#       - Add Scene lights, object lights and material light settings
#       - Support for custom external display lists for materials and objects
#           - Object level display lists is complete#
#       - Continue improving UI for ease of use
#---------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------
#TO DO NOTES 10/19/2021:        
#       - Improve ease of use by adding debug material and textures to model with a single button click on setup    
#       - Work on the fully customizable GBI commands
#       - Print most debug messages in the debug console
#            - To open python console to view debug messages, go to Window -> Toggle System Console
#            - See if it's possible to open the system console from script when user toggles debug mode...           
#       - Support negative U/V (S/T) values when converting from int to hexidecimal          
#---------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------
#RECENT UPDATES 10/19/2021: 
#       - Added some guidance to plug-in on what is needed to properly use this plug-in
#       - Support for Scene, Object and Material lights
#       - Some debug messages have been moved to print
#       - Fixed edge case where Tri1 and Tri2 both needed to modify the same vertex - this now uses gSP1Triangle
#       - Fixed edge case where both Tri1 and Tri2 use modify vertex but Tri1 does not use any of the vertex used in Tri 2 - this now uses gSP2Triangles
#       - Clean up ModifyVertex to group modified vertexes together when creating gSP1Triangle
#       - Flesh our UI for ease of use
#           - If there is no object in scene, no material object in the scene, and blender render is being used, place an error message to guide the user
#           - Created a handful of test dictionary entries for Pre-Built Commands
#       - Update Texture + VTX Lighting to use the same method of material calls as Texture + VTX Colors
#       - Improve export method for obj rotations while using 1:1 bones 
#       - New Sort methods in place to reduce the number of gSP1Triangle and ModifyVertex calls#
#           - Fix export _vertexlist numbering
#       - Add support for gSP2Triangle on PRIM Colors as a first test  
#                   - Cleaned up this code to make it less convoluted
#       - Add support for static and dynamic display lists
#                   - Adding functionality for this now...
#       - Transfer all textures, prim colors, and other commands from Materials panel
#       - Move all rendering over to Cycles
#---------------------------------------------------------------------------------------------------------

class Obj_Properties_Xport64(bpy.types.PropertyGroup):
    bl_label = "Xport64 Object Export Properties"
    totalUVValues = [[[]]] #This stores the UV values actually used in the VTXlist. It is used for comparison in the polylist

class exportTest(bpy.types.PropertyGroup):
    bl_label = "Export Class"    
    
#   **********************************************************************************************************************************************
# 1 ***************************************************************** EXPORT VERT ****************************************************************
#   **********************************************************************************************************************************************
              
class VTX_Xport64(bpy.types.Operator):
    bl_idname = "export.xport64"
    bl_label = "Xport64 - Display List"

#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Many of the most used variables in VTX_Xport64 are defined in __init__.py 
#---------------------------------------------------------------------------------------------------------     
    
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES: exportVert sorts through the vertices of the current object and tries to reduce the 
#               number of vertices required to render the model on the N64.
#--------------------------------------------------------------------------------------------------------- 
        
    def exportVert(self, o, obj, objCounter):
        print("Exporting Vertices from export.py -> exportVert(self, o, obj, objCounter):")
        bitshift = 6 # Bitshift mod
        loadlim = 30     # Amount of verts the system will load at a time 32 max limit
        exportPolyList = True
        DEBUG = obj.obj_props.debug_DL #NOTE: User can debug script and look for problem areas
        SHOWTIPS = obj.obj_props.guide_DL #NOTE: User can view tips and guidance on how to utilize this tool
    #TEST Exporting C files 
        path = 'Users\micha\Documents\Game Design'
        filename = path + obj.name + '.c'
        name = self.clean_name(obj.name)

        self.uvValue.append([]) #Set up for each new object [object][vertex][u,v]
        self.usedUVValues.append([]) ##Set up for each new object [object][vertex][u,v]
        self.usedUVValues[objCounter].append([])                
        self.allVertexColors.append([]) #Set up for each new object [object][vertex][r,g,b]                
        self.materials.append([]) #object number objCounter for material checks
        self.definitionsFile.append([])
        
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES: clean_name removes invalid characters and sets name of file that will be exported
#---------------------------------------------------------------------------------------------------------
        
    #ANIMATION Test for animations in scene...
        scene = bpy.context.scene
        sceneprops = scene.scene_props
        
        frame_current = scene.frame_current
        r = range(scene.frame_start, scene.frame_end + 1)
        l = len(str(len(r)))
        #TO_REMOVE#obs = []

       # bones["upper_arm.R"].name
        #print("Name of bone... %s" % obj.modifiers["Armature"].name)        
        
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES: Export any #include files at the top of the file. Currently, up to 10 can be included. 
#---------------------------------------------------------------------------------------------------------
        o.write("\n//>-- OBJECT %i: START ------------------------------------------ %s -------------------------------------------------\n\n" % (objCounter, name))
        if sceneprops.create_header_file == True:  #NOTE ----- Save these commands in a string for later use in .h file for defintions and declarations:            
              self.definitionsFile[self.commandCount] = ("\n//>-- OBJECT %i: START ------------------------------------------ %s -------------------------------------------------\n\n" % (objCounter, name))
              self.definitionsFile.append([])
              self.commandCount +=1
              
        for f in r:
          
          if obj.obj_props.anim_Method == "VTX DL":
            scene.frame_set(f)
            scene.update() 
            mod_obj = obj
            mod_mesh = mod_obj.to_mesh(scene, True, 'RENDER') # creates duplicated mesh used for animation capture

          if obj.obj_props.anim_Method == "VTX DL":
            vert = mod_mesh.vertices
          else:
            vert = obj.data.vertices
          poly = obj.data.polygons
          uv = obj.data.uv_layers.active      

          vertexList = []

          redirectPointer = 0

      # Choose vertex---[number][redirect]
          redirectValue = []      
          
          uvCount = 0
          index = 0
          redirect = 0
          count = 0
          allPrimColors = [[]]
          primColorCount = 0
          mesh = obj.data 
          counter = 0
          
#---------------------------------------------------------------------------------------------------------
#VER_NOTES:  'for face in mesh.polygons:' No longer used, this will be removed provided it causes no errors
#---------------------------------------------------------------------------------------------------------   
          for face in mesh.polygons:
              material = face.material_index
              polygon = face.index  
              self.materials[objCounter].append([])
              self.materials[objCounter][counter].append(polygon) #polygon ID
              self.materials[objCounter][counter].append(material) #material slot  
              
              #if self.debugCheck == True:
                #o.write("face: %i  material index: %i \n" %(self.materials[objCounter][counter][0], self.materials[objCounter][counter][1])) 
              
              counter +=1
            
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:  Check for polygons w/ 4 or more vertices. If found, split them into tris
#---------------------------------------------------------------------------------------------------------     
          for p in poly:
              if len(p.vertices) > 3:
                  o.write("//WARNING: Triangulate before exporting. \n")
                  break      

                  
                  
#---------------------------------------------------------------------------------------------------------
#VER_NOTES: 'allPrimColors[0]' No longer needed, this will be removed provided it causes no errors. 
#           Still needs to be removed from collision exporter first.
#---------------------------------------------------------------------------------------------------------  
      #Set up List for storing Primative Colors and assign allPrimColors[0] as 255,255,255
          allPrimColors[0].append(255.0)
          allPrimColors[0].append(255.0)
          allPrimColors[0].append(255.0)
          allPrimColors.append([])
                   
          primColorCount += 1

          if obj.obj_props.debug_DL == True: #DEBUG CHECK VALUES:---
            o.write("//Test Primative Color Storage = %i, %i, %i \n" % (allPrimColors[0][0], allPrimColors[0][1], allPrimColors[0][2]))
          

#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    'if obj.obj_props.sort_Method == "COLLISION":'  
#                   If object is tagged as a collision object, begin collider object structure.
#---------------------------------------------------------------------------------------------------------     
          if obj.obj_props.sort_Method == "COLLISION":      
            o.write("MeshCollider %s_MeshVtx_%i [] = {\n" % (name, f))       
          else:
            o.write("Vtx %s_VertList_%i [] = {\n" % (name, f))
            
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:  'sceneprops.create_header_file == True:' If user selects to export definitions / declarations to a header file:
#---------------------------------------------------------------------------------------------------------                  
          if sceneprops.create_header_file == True: #NOTE ----- Save these commands in a string for later use in .h file for defintions and declarations:          
              if obj.obj_props.sort_Method == "COLLISION":      
                self.definitionsFile[self.commandCount] = ("extern MeshCollider %s_MeshVtx_%i [];\n" % (name, f)) 
              else:
                self.definitionsFile[self.commandCount] = ("extern Vtx %s_VertList_%i [];\n" % (name, f)) 
                
              self.definitionsFile.append([])
              self.commandCount +=1
                
          print("\n\n\n-------- Output start frame: %i    Start Frame: %i    End Frame: %i --------\n\n\n" % (f, scene.frame_start, scene.frame_end))
          
          allVertIndex = 0
          redirectPointer = 0
          count = 0

          for face in poly:

            currentActiveVertex = [0,0,0]
            currentActiveLoop = [0,0,0]
            redirectValueCheck = [0,0,0] #checks verts of each polygon. If attempting to re-direct but the difference between the highest and lower polygon is too great, create a new vertex listing
            vertexListCheck = [0,0,0] #set as true or false whether this is a duplicate      
            vertCheck = 0
            redirectDifference = 0
            tempList = [0,0,0]
            offsetDuplicates = 0
            debugCounter = 0
            matTextureSize = [0,0]
            
            objMaterials = obj.data.materials
            materialCounter = 0                        
            
            materialCounter = face.material_index
            activeMat = objMaterials[materialCounter]
            matProperties = objMaterials[materialCounter].mat_props
            
            if 'Image Texture' in activeMat.node_tree.nodes:
                textureImage = activeMat.node_tree.nodes["Image Texture"].image
                textureName = textureImage.name
                
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:  The following splits the image name from an extension such as: removeExtension[0] = name (ex. debugTexture) removeExtension[1] = extension (ex .png)
#---------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------
#TO_DO_NOTE:  Check to make sure that new materials method uses the same extension removal function.
#---------------------------------------------------------------------------------------------------------                             
                removeExtension = os.path.splitext(textureName) #splits extension and file name
                textureName = removeExtension[0] #assigns file name to textureName without the extension

#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:  Get texture image resolution if a texture is being used.
#---------------------------------------------------------------------------------------------------------                           
                if matProperties.custom_tex_res == True:
                    matTextureSize[0] = matProperties.texture_res_w
                    matTextureSize[1] = matProperties.texture_res_h
                else:
                    matTextureSize = textureImage.size
                    
            else:
                    matTextureSize = [1,1]
            
            for vert, loop in zip(face.vertices, face.loop_indices):              
                
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:  Gather temporary Vertex data- For each poly, grab the coordinates, uv, and vertex color information. This will repeat 3 times per face/poly: 
#---------------------------------------------------------------------------------------------------------                  
              if vertCheck < 3:                
                if obj.obj_props.anim_Method == "VTX DL":
                    coord = mod_mesh.vertices[vert].co * obj.matrix_world                
                else:
                    coord = obj.data.vertices[vert].co * obj.matrix_world
                    
                uv = obj.data.uv_layers.active.data[loop].uv if obj.data.uv_layers.active else (0,0)
                vcol = obj.data.vertex_colors.active.data[loop].color if obj.data.vertex_colors.active else (1,1,1,1)

#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    A second Vertex Color layer needs to be set to gather alpha information. Alpha can be denoted from Black to White.
#                   This needs to be set from 0-255 with 255 (white) being solid and 0(black) being transparent. Then store it as a single value by dividing the RGB total by 3. 
#---------------------------------------------------------------------------------------------------------                  
                if "Alpha" in obj.data.vertex_colors: 
                    valpha = (obj.data.vertex_colors["Alpha"].data[loop].color[0] + obj.data.vertex_colors["Alpha"].data[loop].color[1] + obj.data.vertex_colors["Alpha"].data[loop].color[2])/3                    
                else: 
                    valpha = 1.0
                
                self.uvValue[objCounter].append([])
                self.uvValue[objCounter][uvCount].append(uv[0]*(matTextureSize[0]*self.sttile))
                self.uvValue[objCounter][uvCount].append((1-uv[1])*(matTextureSize[1]*self.sttile))
                           
                self.allVertexColors[objCounter].append([])
                self.allVertexColors[objCounter][uvCount].append(vcol[0]*255)
                self.allVertexColors[objCounter][uvCount].append(vcol[1]*255)
                self.allVertexColors[objCounter][uvCount].append(vcol[2]*255)                
                self.allVertexColors[objCounter][uvCount].append(valpha*255) #assign
                
                debugCounter +=1
                uvCount+=1

#---------------------------------------------------------------------------------------------------------
#VER_NOTES:  allPrimColors[0] and associated functions need to be removed since this method is no longer used.  
#---------------------------------------------------------------------------------------------------------                   
                check = 0
                colorIndex = 0          

                while colorIndex < primColorCount:            
                  if check == 0 and isclose(vcol[0]*255, allPrimColors[colorIndex][0], abs_tol=1) and isclose(vcol[1]*255, allPrimColors[colorIndex][1], abs_tol=1) and isclose(vcol[2]*255, allPrimColors[colorIndex][2], abs_tol=1):  

                    check = 1
                    colorIndex = primColorCount

                  else:
                    colorIndex += 1           
                if check == 0:          
                  o.write("//Found a new color! Color Index: %i     Vert %i:  %i, %i, %i \n" % (colorIndex, vertCheck, vcol[0]*255, vcol[1]*255, vcol[2]*255)) #Found a new color to add to index
                  allPrimColors[colorIndex].append(vcol[0]*255)
                  allPrimColors[colorIndex].append(vcol[1]*255)
                  allPrimColors[colorIndex].append(vcol[2]*255)
                  allPrimColors.append([])
                  primColorCount += 1
              
                if DEBUG == True: #DEBUG CHECK VALUES:--- 
                  o.write("//Vertex Check: %i  Index: %i  Count: %i  \n " % (vert, index, count ))
                dup = 0
                for i, compare in enumerate(vertexList):
                  if vertexList[i][0] == coord.x*self.scale:
                      if vertexList[i][1] == coord.y*self.scale:
                        if vertexList[i][2] == coord.z*self.scale:                          
                            dup = 1                                             
                            redirectValueCheck[vertCheck] = i
                            vertexListCheck[vertCheck] = 1
                if dup == 1:
                   offsetDuplicates += 1              
                if dup ==0:
                  redirectValueCheck[vertCheck] = (index+vertCheck)-offsetDuplicates            
                  vertexListCheck[vertCheck] = 0  

                if DEBUG == True: #DEBUG CHECK VALUES:--- 
                  o.write("//Vert %i, Loop %i, Redirect %i Index+Offset: %i      " % (vert, loop, redirectValueCheck[vertCheck], (index+vertCheck)-offsetDuplicates))

              currentActiveVertex[vertCheck] = vert
              vertCheck += 1

#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    After loading 3 vertices for checking, we check to see which can reused to avoid duplicates and re-direct later vertices to use earlier ones already loaded.
#---------------------------------------------------------------------------------------------------------               
              if vertCheck >= 3:
                tempList = sorted(redirectValueCheck) #sort temp redirect  numbers from lowest to highest
                redirectDifference = tempList[0] - tempList[2] #find difference of highest and lowest redirect value
                redirectDifference = abs(redirectDifference)

              if vertCheck >= 3:                    
                vertCheck = 0
                adjusted = 0
                offsetDuplicates = 0
                while vertCheck < 3 and redirectDifference > loadlim:
                  if vertexListCheck[vertCheck] == 1:
                    offsetDuplicates+=1

                  if tempList[0] == redirectValueCheck[vertCheck] and adjusted == 0:
                    offsetDuplicates -=1
                    adjusted = 1
                    redirectValueCheck[vertCheck] = (index+vertCheck)-offsetDuplicates               
                    vertexListCheck[vertCheck] = 0

                    if DEBUG == True: #DEBUG CHECK VALUES:--- 
                      o.write("//UPDATED LOWEST REDIRECT Vert %i, Loop %i, Redirect %i Index+vertCheck: %i \n" % (vert, loop, redirectValueCheck[vertCheck], (index+vertCheck)-offsetDuplicates))

                    while vertCheck < 2:
                    
                      if DEBUG == True: #DEBUG CHECK VALUES:--- 
                        o.write("//UPDATED OTHER REDIRECT Vert %i, Loop %i, Redirect %i Index+vertCheck: %i \n" % (vert+vertCheck, loop+vertCheck, redirectValueCheck[vertCheck], (index+vertCheck)-offsetDuplicates))

                      vertCheck +=1 
                      if vertexListCheck[vertCheck] == 0:                  
                        redirectValueCheck[vertCheck] += 1
                  vertCheck += 1
                tempList = sorted(redirectValueCheck) #sort temp redirect  numbers from lowest to highest
                redirectDifference = tempList[0] - tempList[2] #find difference of highest and lowest redirect value
                redirectDifference = abs(redirectDifference)
                  
                if DEBUG == True: #DEBUG CHECK VALUES:---   
                  o.write("//Adjusting redirectValueCheck\n")        
                  
                vertCheck = 0
                uvCount -= 3 #reduce uvCount back 3 so it can be looped again for printing uvCoordinates
                while vertCheck < 3:                 
                  if obj.obj_props.anim_Method == "VTX DL":                
                    coord = mod_mesh.vertices[(currentActiveVertex[vertCheck])].co * obj.matrix_world                
                  else:             
                    coord = obj.data.vertices[(currentActiveVertex[vertCheck])].co * obj.matrix_world  
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Check to make sure that the current redirected value is less than the load limit that the N64 microcode can use (max 32)
#---------------------------------------------------------------------------------------------------------   
                  if redirectDifference < loadlim: #if the difference is less than the max load lim...
                    redirectValue.append(redirectValueCheck[vertCheck])

                    if vertexListCheck[vertCheck] == 0: #if this is false(0), then a new vertex needs to be added
                      vertexList.append([coord.x*self.scale,coord.y*self.scale,coord.z*self.scale])
                     
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Print the VTX data into a format usable by the N64. For compatibility with ModifyVertex, UV Coords are stored as hex.
#                   Vertex data can be exported with vertex colors for baked lighting, normals for real time lighting, or a custom normals struct for collisions
#---------------------------------------------------------------------------------------------------------                      
                      if obj.obj_props.sort_Method == "VTX COLOR":
                          o.write("   { %.2f, %.2f, %.2f, %i, 0x%0004x, 0x%0004x, %i, %i, %i, %i}, \n" 
                            % (coord.x*self.scale, coord.y*self.scale, coord.z*self.scale, 1,                               
                               int(self.uvValue[objCounter][uvCount][0]*matTextureSize[0]), int(self.uvValue[objCounter][uvCount][1]*matTextureSize[1]), 
                               self.allVertexColors[objCounter][uvCount][0], self.allVertexColors[objCounter][uvCount][1], self.allVertexColors[objCounter][uvCount][2], self.allVertexColors[objCounter][uvCount][3]))
                      
                      elif obj.obj_props.sort_Method == "COLLISION":
                        o.write("   { %.2f, %.2f, %.2f, %i, %i, %i}, \n" #Export HEX value
                          % (coord.x*self.scale, coord.y*self.scale, coord.z*self.scale, #Export float or HEX value
                             obj.data.vertices[(currentActiveVertex[vertCheck])].normal.x*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.y*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.z*127))     
                      
                      else:
                        o.write("   { %.2f, %.2f, %.2f, %i, 0x%0004x, 0x%0004x, %i, %i, %i, %i},  \n" 
                          % (coord.x*self.scale, coord.y*self.scale, coord.z*self.scale, 1,                             
                             int(self.uvValue[objCounter][uvCount][0]*matTextureSize[0]), int(self.uvValue[objCounter][uvCount][1]*matTextureSize[1]), 
                             obj.data.vertices[(currentActiveVertex[vertCheck])].normal.x*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.y*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.z*127, 255))     
  
                      index+=1
                      
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Add to uvCount any uv coordinate actually used
#---------------------------------------------------------------------------------------------------------    
                      self.usedUVValues[objCounter][count].append(self.uvValue[objCounter][uvCount][0])
                      self.usedUVValues[objCounter][count].append(self.uvValue[objCounter][uvCount][1])
                      self.usedUVValues[objCounter].append([]) 
                                           
                      if DEBUG == True: #DEBUG CHECK VALUES:--- 
                          o.write("//This usedUVValue(%i) is 0x%0004x, 0x%0004x \n" % (count, self.usedUVValues[objCounter][count][0], self.usedUVValues[objCounter][count][1]))
                      count +=1

                    else: #This coordinate is already in memory so skip it!
                      if DEBUG == True: #DEBUG CHECK VALUES:--- 
                        o.write("//This Vertex(%i) is already in memory... SKIP...! \n" % uvCount)
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    If greater than the load limit, then a new vertex needs to be added. 
#---------------------------------------------------------------------------------------------------------   
                  else:               
                    redirectValue.append(index)

                    vertexList.append([coord.x*self.scale,coord.y*self.scale,coord.z*self.scale])
                    
                    if obj.obj_props.sort_Method == "VTX COLOR":
                      o.write("   { %.2f, %.2f, %.2f, %i, 0x%0004x, 0x%0004x, %i, %i, %i, %i}, \n" #Export HEX value
                        % (coord.x*self.scale, coord.y*self.scale, coord.z*self.scale, 1,
                           int(self.uvValue[objCounter][uvCount][0]*matTextureSize[0]), int(self.uvValue[objCounter][uvCount][1]*matTextureSize[1]), 
                           self.allVertexColors[objCounter][uvCount][0], self.allVertexColors[objCounter][uvCount][1], self.allVertexColors[objCounter][uvCount][2], self.allVertexColors[objCounter][uvCount][3]))

                    elif obj.obj_props.sort_Method == "COLLISION":
                        o.write("   { %.2f, %.2f, %.2f, %i, %i, %i}, \n" #Export HEX value
                          % (coord.x*self.scale, coord.y*self.scale, coord.z*self.scale, #Export float or HEX value
                             obj.data.vertices[(currentActiveVertex[vertCheck])].normal.x*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.y*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.z*127))     
                            
                    else:
                        o.write("   { %.2f, %.2f, %.2f, %i, 0x%0004x, 0x%0004x, %i, %i, %i, %i}, \n" #Export HEX value
                          % (coord.x*self.scale, coord.y*self.scale, coord.z*self.scale, 1,
                             int(self.uvValue[objCounter][uvCount][0]*matTextureSize[0]), int(self.uvValue[objCounter][uvCount][1]*matTextureSize[1]), 
                             obj.data.vertices[(currentActiveVertex[vertCheck])].normal.x*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.y*127, obj.data.vertices[(currentActiveVertex[vertCheck])].normal.z*127, 255))     
             
                    index+=1
                    
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Add to uvCount any uv coordinate actually used
#---------------------------------------------------------------------------------------------------------   
                    self.usedUVValues[objCounter][count].append(self.uvValue[objCounter][uvCount][0])
                    self.usedUVValues[objCounter][count].append(self.uvValue[objCounter][uvCount][1])
                    self.usedUVValues[objCounter].append([])     
                    count +=1    
                    
                  vertCheck += 1
                  uvCount += 1
                  redirectPointer += 1
                vertCheck = 0
                
          o.write("};\n\n")
          if obj.obj_props.anim_Method == "VTX DL":
            bpy.data.meshes.remove(mod_mesh) #removes duplicated mesh used for animation capture   
          if obj.obj_props.anim_Method == "NO ANIM" or obj.obj_props.anim_Method == "OBJ VARIABLES":          
            break      
          
#   ********************************************************************************************************************************************** 
# 2 ***************************************************************** EXPORT POLY*****************************************************************
#   **********************************************************************************************************************************************    
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Export Poly - this is the set of display list commands such as:
#                   Loading vertices, loading triangles, setting GBI commands, loading textures, and more...
#---------------------------------------------------------------------------------------------------------  

    
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    The following are used when writing commands to our final .c script. The program user can set their display list to be 
#                   dynamic or static. 'dynamic_DL_start' through 'static_VertList' are used in the final strings that are outputted based 
#                   on the choice by the user to have a static display list or not. 
#---------------------------------------------------------------------------------------------------------   
dynamic_DL_start = "g"
static_DL_start = "gs"

dynamic_DL_name = "glistp++" 
static_DL_name = ""

dynamic_DL_end = ");"
static_DL_end = "),"

dynamic_VertList = "_VTXPointer"
static_VertList = "_VertList_[0]"
    
class Poly_Xport64(bpy.types.Operator):
    bl_idname = "poly.xport64"
    bl_label = "Xport64 - Polygon/Tri export"    
        
    def exportPoly(self, o, obj, objCounter):    
#---------------------------------------------------------------------------------------------------------
#TO_DO_NOTE:    User can enable DEBUG or SHOWTIPS on each object to help new users. This will be fleshed out in future updates. 
#---------------------------------------------------------------------------------------------------------          
        DEBUG = obj.obj_props.debug_DL #NOTE: User can set to debug this script and look for problem areas
        SHOWTIPS = obj.obj_props.guide_DL #NOTE: User can view tips and guidance on how to utilize this tool        
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    The Static option is reset here that way the user can change the setting for static/dynamic on each object.
#---------------------------------------------------------------------------------------------------------              
#START------------------------------------------Static/Dynamic Display List Settings-------------------------------------------
        DL_start_setting = ""
        DL_name_setting = ""
        DL_name = ""
        DL_end_setting = ""
        VertList_setting = ""       
        
        if obj.obj_props.static_DL == False:
            DL_start_setting = dynamic_DL_start            
            DL_name = ("%s++" % obj.obj_props.set_dl_name) #NOTE: Use for single argument function / macros calls                        
            DL_name_setting = DL_name #NOTE: Use DL_name_setting for multi-argument function / macros calls
            DL_name_setting += ", "             
            DL_end_setting = dynamic_DL_end
            VertList_setting = dynamic_VertList
            
        elif obj.obj_props.static_DL == True:
            DL_start_setting = static_DL_start
            DL_name_setting = static_DL_name
            DL_end_setting = static_DL_end
            VertList_setting = static_VertList #default... if there are multiple frames or states, this will need to update
#END------------------------------------------Static/Dynamic Display List Settings------------------------------------------- 
        #testString = obj.obj_props.sort_Method
        
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Many of the most used variables in Poly_Xport64 are defined in __init__.py 
#---------------------------------------------------------------------------------------------------------  
        bitshift = 6 # Bitshift mod
        loadlim = 30     # Ammount of verts the sytem will load at a time 32 max limit
        exportPolyList = True
    
        path = 'Users\micha\Documents\Game Design' #TEST Exporting C files 
        #TO_REMOVE#filename = path + obj.name + '.c' 
        
        #TO_REMOVE#textureCounter = 0
        
    #ANIMATION Test for animations in scene...
        scene = bpy.context.scene
        sceneprops = scene.scene_props
        frame_current = scene.frame_current
        r = range(scene.frame_start, scene.frame_end + 1)
        l = len(str(len(r)))
        #TO_REMOVE#obs = []
        #TO_REMOVE#trans = bpy.context.object.matrix_world
        
        name = self.clean_name(obj.name)
        vert = obj.data.vertices
        poly = obj.data.polygons
        uv = obj.data.uv_layers.active      

#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    obj.obj_props.anim_Method == "OBJ VARIABLES" checks for whether the user has chosen the Pos, Rot, Scl option for animation export
#--------------------------------------------------------------------------------------------------------- 
        if obj.obj_props.anim_Method == "OBJ VARIABLES":         
            o.write("RigAnimation %s_anim[] = { \n \n" % name) #NOTE ----- begin animation structure in .c file:
            
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    Certain functions and variables can be defined/declared in a .h script if the user enables it with 'sceneprops.create_header_file'
#TO_DO_NOTE:        This functionality will be fleshed out in future updates.
#---------------------------------------------------------------------------------------------------------  
            if sceneprops.create_header_file == True: #NOTE ----- Save these commands in a string for later use in .h file for defintions and declarations:  
                self.definitionsFile[self.commandCount] = ("extern RigAnimation %s_anim[];\n" % name)
                self.definitionsFile.append([])                
                self.commandCount +=1    
                
            for f in r:        
                scene.update()                
                scene.frame_set(f)           
                objPos = obj.matrix_world.to_translation() #records position of bone to the object
                objRot = obj.matrix_world.to_euler() #records rotation of bone to the object
                objScale = obj.matrix_world.to_scale() #records scale of bone to the object
                rot_angles_X = math.degrees(objRot[0]) #converts to degrees
                rot_angles_Y = math.degrees(objRot[1]) #converts to degrees
                rot_angles_Z = math.degrees(objRot[2]) #converts to degrees
                
                o.write("%2f, %2f, %2f,\n    %2f, %2f, %2f,\n       %2f, %2f, %2f,\n " % (objPos.x*self.scale, objPos.y*self.scale, objPos.z*self.scale, rot_angles_X, rot_angles_Y, rot_angles_Z, objScale.x, objScale.y, objScale.z))
            o.write("\n};\n\n")

#---------------------------------------------------------------------------------------------------------
#TO_DO_NOTE:        Part of the "OBJ VARIABLES" is commented out as this is version. Right now user must use their own method for rigging.
#                   However, a simple rigging template is going to be available with the next version of the exporter and demo game.
#---------------------------------------------------------------------------------------------------------  
            
#START------------------------------------------WIP Animation Rig Settings-------------------------------------------
            # o.write("void %s_animation()\n { \n" % name)        
            # o.write("   tempObjVectorPos = %s_anim[animFrame].pos;\n" % name)
            # o.write("   tempObjVectorRot = %s_anim[animFrame].rot;\n" % name)  
            # o.write("   tempObjVectorScl = %s_anim[animFrame].scl;\n\n" % name)         
            # o.write("   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );\n")
            # o.write("       //NOTE: Assign values to your rig here. For instance: \n")
            # o.write("       //SetVector3(&playerAvatar.animRig.joint.armR[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z);\n")            
            # o.write("\n } \n")
#END--------------------------------------------WIP Animation Rig Settings--------------------------------------------
            
            if SHOWTIPS == True or DEBUG == True:
                o.write("//>-- ALERT ------------------------------------------- RigAnimation includes objects pos, rot, and scl each frame. Rig template is coming in next version. --<\n")
                o.write("//>-- ALERT ------------------------------------------- Right, now user must provide their own method for rigging and animating in their application. --<\n\n")
                
        if obj.obj_props.sort_Method == "COLLISION" :
            o.write("MeshColliderTri %s_MeshTri[] = \n { \n" % (name))
            
#START------------------------------------------Begin structure of polylist function (display list commands)-------------------------------------------         
        elif obj.obj_props.static_DL != True:
            o.write("void %s_PolyList(u8 animFrame){ \n\n   Vtx *%s_VTXPointer = &%s_VertList_%i[0]; \n\n" % (name, name, name, scene.frame_start))             
            if sceneprops.create_header_file == True: #NOTE ----- If user selects to export definitions / declarations to a header file: 
                self.definitionsFile[self.commandCount] = ("extern void %s_PolyList(u8 animFrame);\n" % name)                
                self.definitionsFile.append([])
                self.commandCount +=1 
#START------------------------------------------Begin structure of polylist function (display list commands)-------------------------------------------  
                
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    The following switch statement is used inside of a dynamic display list if the user selects the 'VTX DL' option for animation at export.
#                   This creates a unique VTX list for each frame of animation and the switch statement cycles through that list based on the current frame of
#                   animation that is given to it. It is up to the application to provide the correct frame to the struct for animation.
#---------------------------------------------------------------------------------------------------------        
#START-------------------------------------------------------SWITCH STATEMENT------------------------------------------------------------------
        if obj.obj_props.anim_Method == "VTX DL" and obj.obj_props.static_DL == False and obj.obj_props.sort_Method != "COLLISION":
            o.write("   switch(animFrame)\n     {\n")        
        
        modifiedUVValues = [[[]]] #make note of an update to a UV value using modifyVertex command. Reset 
        modifiedUVValues = copy.deepcopy(self.usedUVValues)
        for f in r:        
          scene.update() #NOTE ----- each cycle, update the scene to the next animation frame          
          if obj.obj_props.static_DL == False and obj.obj_props.sort_Method != "COLLISION":          
              if obj.obj_props.anim_Method == "OBJ VARIABLES" or obj.obj_props.anim_Method == "VTX DL":       
                scene.frame_set(f)                
                if obj.obj_props.anim_Method == "VTX DL":
                    o.write("     case %i:\n" % f)
              else:
                f = frame_current      
             
              if obj.obj_props.anim_Method == "VTX DL":
                o.write("       %s_VTXPointer = &%s_VertList_%i[0]; \n        break;\n" % (name, name, f))
              if obj.obj_props.anim_Method == "NO ANIM":
                break           

        if obj.obj_props.anim_Method == "VTX DL" and obj.obj_props.static_DL == False and obj.obj_props.sort_Method != "COLLISION":
            o.write("   }\n\n\n ")
#END-------------------------------------------------------SWITCH STATEMENT------------------------------------------------------------------
    
        vertexList = []
        redirectPointer = 0

    # Choose vertex---[number][redirect]
        redirectValue = []
        uvCount = 0
        index = 0
        redirect = 0
        count = 0
        allPrimColors = [[]]
        primColorCount = 0
        
        textureNameCount = 0    
        allTextureNames = [[]] #for storing textureNames 
        allTextureNames[0].append("DebugTexture")
        allTextureNames[0].append(".png")
        allTextureNames.append([])
        textureNameCount += 1
        
    # Check for polygons w/ 4 or more vertices. If found, split them into tris:
        for p in poly:
            if len(p.vertices) > 3:
                o.write("//WARNING: Triangulate before exporting. \n")
                break

    #Set up List for storing Primative Colors and assign allPrimColors[0] as 255,255,255
        allPrimColors[0].append(255.0)
        allPrimColors[0].append(255.0)
        allPrimColors[0].append(255.0)
        allPrimColors.append([])
        primColorCount += 1
        
    #Set up List for storing UV coordinates and assign uvValue[0] os 0,0

      #DEBUG CHECK VALUES:----------------------------------------------------------------------
        if DEBUG == True: #DEBUG CHECK VALUES:--- 
          o.write("//Test Primitive Color Storage = %i, %i, %i \n" % (allPrimColors[0][0], allPrimColors[0][1], allPrimColors[0][2]))
      #DEBUG CHECK VALUES:----------------------------------------------------------------------

    # Vertex List
        allVertIndex = 0
        redirectPointer = 0
        count = 0
        faceCount = 0
        for face in poly:

          currentActiveVertex = [0,0,0]
          currentActiveLoop = [0,0,0]
          redirectValueCheck = [0,0,0] #checks verts of each polygon. If attempting to re-direct but the difference between the highest and lower polygon is too great, create a new vertex listing
          vertexListCheck = [0,0,0] #set as true or false whether this is a duplicate      
          vertCheck = 0
          redirectDifference = 0
          tempList = [0,0,0]
          offsetDuplicates = 0
          #textureName = os.path.splitext(obj.data.uv_textures["UVMap"].data[loop].image.name)

          for vert, loop in zip(face.vertices, face.loop_indices):
            
    #Gather temporary Vertex data- For each poly, grab the coordinates, uv, and vertex color information. This will repeat 3 times per face/poly:       
            if vertCheck < 3:  
              coord = obj.data.vertices[vert].co * obj.matrix_world
              uv = obj.data.uv_layers.active.data[loop].uv if obj.data.uv_layers.active else (0,0)
              vcol = obj.data.vertex_colors.active.data[loop].color if obj.data.vertex_colors.active else (1,1,1,1)
              
    #Gather Primative Color Information:
              check = 0
              colorIndex = 0          

              while colorIndex < primColorCount:            
                if check == 0 and isclose(vcol[0]*255, allPrimColors[colorIndex][0], abs_tol=1) and isclose(vcol[1]*255, allPrimColors[colorIndex][1], abs_tol=1) and isclose(vcol[2]*255, allPrimColors[colorIndex][2], abs_tol=1):  
                #DEBUG CHECK VALUES:----------------------------------------------------------------------
                  if DEBUG == True: #DEBUG CHECK VALUES:---               
                    o.write("//This color is already indexed! \n") #This color is already indexed 
                #DEBUG CHECK VALUES:----------------------------------------------------------------------
                  check = 1
                  colorIndex = primColorCount

                else:
                  colorIndex += 1           
              if check == 0:

              #DEBUG CHECK VALUES:----------------------------------------------------------------------            
                if DEBUG == True: #DEBUG CHECK VALUES:--- 
                  o.write("//Found a new color! \n") #Found a new color to add to index
              #DEBUG CHECK VALUES:----------------------------------------------------------------------              

                allPrimColors[colorIndex].append(vcol[0]*255)
                allPrimColors[colorIndex].append(vcol[1]*255)
                allPrimColors[colorIndex].append(vcol[2]*255)
                allPrimColors.append([])
                primColorCount += 1
    #End gathering Primative Color
            
    #DEBUG CHECKS:
              if DEBUG == True: #DEBUG CHECK VALUES:--- 
                o.write("//Vertex Check: %i \n" % vert )
                o.write("//Vertex Check: %i \n" % index )
                o.write("//Vertex Check: %i \n" % count )
              dup = 0
              for i, compare in enumerate(vertexList):
                if vertexList[i][0] == coord.x*self.scale:
                    if vertexList[i][1] == coord.y*self.scale:
                      if vertexList[i][2] == coord.z*self.scale:                          
                          dup = 1                                             
                          redirectValueCheck[vertCheck] = i
                          vertexListCheck[vertCheck] = 1
                          #break  
              if dup == 1:
                 offsetDuplicates += 1 
              if dup ==0:
                redirectValueCheck[vertCheck] = (index+vertCheck)-offsetDuplicates            
                vertexListCheck[vertCheck] = 0    

    #DEBUG CHECK VALUES:----------------------------------------------------------------------
              if DEBUG == True: #DEBUG CHECK VALUES:--- 
                o.write("//Vert %i, Loop %i, Redirect %i Index+Offset: %i \n" % (vert, loop, redirectValueCheck[vertCheck], (index+vertCheck)-offsetDuplicates))
    #DEBUG CHECK VALUES:----------------------------------------------------------------------
            currentActiveVertex[vertCheck] = vert
            vertCheck += 1

            if vertCheck >= 3:
              tempList = sorted(redirectValueCheck) #sort temp redirect  numbers from lowest to highest
              redirectDifference = tempList[0] - tempList[2] #find difference of highest and lowest redirect value
              redirectDifference = abs(redirectDifference)

            #DEBUG LINE -------------------

            if vertCheck >= 3:                    
              vertCheck = 0
              adjusted = 0
              offsetDuplicates = 0
              while vertCheck < 3 and redirectDifference > loadlim:
                if vertexListCheck[vertCheck] == 1:
                  offsetDuplicates+=1

                if tempList[0] == redirectValueCheck[vertCheck] and adjusted == 0:
                  offsetDuplicates -=1
                  adjusted = 1
                  redirectValueCheck[vertCheck] = (index+vertCheck)-offsetDuplicates               
                  vertexListCheck[vertCheck] = 0

                  while vertCheck < 2:
    #DEBUG CHECK VALUES:----------------------------------------------------------------------                          
                    if DEBUG == True: #DEBUG CHECK VALUES:--- 
                      o.write("//UPDATED OTHER REDIRECT Vert %i, Loop %i, Redirect %i Index+vertCheck: %i \n" % (vert+vertCheck, loop+vertCheck, redirectValueCheck[vertCheck], (index+vertCheck)-offsetDuplicates))
    #DEBUG CHECK VALUES:----------------------------------------------------------------------              

                    vertCheck +=1 
                    if vertexListCheck[vertCheck] == 0:                  
                      redirectValueCheck[vertCheck] += 1
                vertCheck += 1
              tempList = sorted(redirectValueCheck) #sort temp redirect  numbers from lowest to highest
              redirectDifference = tempList[0] - tempList[2] #find difference of highest and lowest redirect value
              redirectDifference = abs(redirectDifference)

              vertCheck = 0
              while vertCheck < 3:
                coord = obj.data.vertices[(currentActiveVertex[vertCheck])].co * obj.matrix_world
                uv = obj.data.uv_layers.active.data[(currentActiveLoop[vertCheck])].uv if obj.data.uv_layers.active else (0,0)
                vcol = obj.data.vertex_colors.active.data[(currentActiveLoop[vertCheck])].color if obj.data.vertex_colors.active else (1,1,1,1)

                if redirectDifference < loadlim: #if the difference is less than the max load lim...
                  redirectValue.append(redirectValueCheck[vertCheck])

                  if vertexListCheck[vertCheck] == 0: #if this is false(0), then a new vertex needs to be added
                    vertexList.append([coord.x*self.scale,coord.y*self.scale,coord.z*self.scale])
                    index+=1

                else:               
                  redirectValue.append(index)                          

                  vertexList.append([coord.x*self.scale,coord.y*self.scale,coord.z*self.scale])
                  index+=1              

                vertCheck += 1
                redirectPointer += 1

              vertCheck = 0
  
          faceCount += 1
        uvCount = 0 #Return to 0 for cycling again
        
#WIP2----------------------TO DO: Clean up code, currently is a mess---------------------------------------------------------------------                               
          
        gSP2TriangleHold = [[0 for x in range(4)] for y in range(2)]
        gSP2TriangleCheck = 0
        gSP2TriangleBool = 0
        
        if exportPolyList == True:          
            
            for f in r:
              scene.update()
              
              i = 0
              offset = 0
              count = 0

              activePrimativeColors = [0,0,0,0]
              offsetAdjust = 0
              primColorCheck = 0
              faceCounter = 1
              
              
              if obj.obj_props.static_DL == True:
              
                if obj.obj_props.anim_Method == "VTX DL":
                    scene.frame_set(f)
                    
                    
                o.write("Gfx %s_Static_PolyList_%i[] = { \n\n" % (name, f))
              
                if sceneprops.create_header_file == True: #NOTE ----- Save these commands in a string for later use in .h file for defintions and declarations:
                   # self.definitionsFile[self.commandCount].append([])
                    self.definitionsFile[self.commandCount] = ("extern Gfx %s_Static_PolyList_%i[];\n" % (name, f))
                    #hfile.write("extern Gfx %s_Static_PolyList_%i[]; \n\n" % (name, f))
                    self.definitionsFile.append([])
                    self.commandCount += 1
    
                VertList_setting = ("_VertList_%i" %f)

              else: 
                scene.frame_set(0)               

              
              
              
              if obj.obj_props.sort_Method == "COLLISION":
                  while primColorCheck < primColorCount:
                    
                    modifiedUVValues = copy.deepcopy(self.usedUVValues) #reset modified UV values since there is a new gSPVertex call
                    # if self.debugCheck == True:
                        # o.write("//MODIFIED UV VALUES RESET \n")          
                    
                    correctMaterial = False
                    delayVertexCall = False
                    usedMaterial = False            

                    delayVertexCall = True
                    modifiedUVValues = copy.deepcopy(self.usedUVValues)
                    
                    for face in poly:
                      for vert, loop in zip(face.vertices, face.loop_indices):
                            vcol = obj.data.vertex_colors.active.data[loop].color if obj.data.vertex_colors.active else (1,1,1,1)
                            uv = obj.data.uv_layers.active.data[loop].uv if obj.data.uv_layers.active else (0,0)
                            coord = obj.data.vertices[vert].co * obj.matrix_world              

                      tempA = i*3
                      tempB = i*3+1
                      tempC = i*3+2 
                      
                      if vcol[0]*255 == allPrimColors[primColorCheck][0] and vcol[1]*255 == allPrimColors[primColorCheck][1] and vcol[2]*255 == allPrimColors[primColorCheck][2]:  
                        correctMaterial = True
                        # if self.debugCheck == True:
                          # o.write("//COLLISION TYPE - Set collision type by color (Need to set this up later) \n")
                            
                        if vcol[0]*255 == activePrimativeColors[0] and vcol[1]*255 == activePrimativeColors[1] and vcol[2]*255 == activePrimativeColors[2]:
                          if DEBUG == True: #DEBUG CHECK VALUES:--- 
                            o.write("//Color Already Set \n")
                        else:  #If current color is different than existing primitive color, assign new colors to active colors 
                          activePrimativeColors[0] = vcol[0]*255 
                          activePrimativeColors[1] = vcol[1]*255
                          activePrimativeColors[2] = vcol[2]*255
                          o.write("//COLLISION TYPE - Set collision type by color: collision type %i \n" %(primColorCount))
                        
                      else:
                        correctMaterial = False #If sorting by material slot
                        # if self.debugCheck == True:
                          # o.write("//MATERIAL SKIP \n") 
                    
                        
                      if correctMaterial == True or correctMaterial == False: 
                        if redirectValue[tempA] > offset+loadlim or redirectValue[tempB] > offset+loadlim or redirectValue[tempC] > offset+loadlim:
                          offset += loadlim 
                          count = 0   
                          while redirectValue[tempA] > offset+loadlim or redirectValue[tempB] > offset+loadlim or redirectValue[tempC] > offset+loadlim:         
                              offset += loadlim      

                          offsetAdjust = 0       

                          for x in range(offset, offset+loadlim):
                            if redirectValue[tempA]-offset < offsetAdjust:
                              offsetAdjust = redirectValue[tempA]-offset
                            if redirectValue[tempB]-offset < offsetAdjust:
                              offsetAdjust = redirectValue[tempB]-offset
                            if redirectValue[tempC]-offset < offsetAdjust:
                              offsetAdjust = redirectValue[tempC]-offset            

                          offset += offsetAdjust
                          
                          delayVertexCall = True #if the next polygon has the correct material and needs an offset... 
                        
                        
                          modifiedUVValues = copy.deepcopy(self.usedUVValues) #reset modified UV values since there is a new gSPVertex call   
                          
                        if redirectValue[tempA]-offset < 0 or redirectValue[tempB]-offset < 0 or redirectValue[tempC]-offset < 0:
                          numCheck = redirectValue[tempA]-offset
                          if redirectValue[tempB]-offset < numCheck:
                            numCheck = redirectValue[tempB]-offset
                          if redirectValue[tempC]-offset < numCheck: 
                            numCheck = redirectValue[tempC]-offset

                          offset += numCheck              
            #Compare UV value against redirect value. If they have different UV values, use gSPModifyVertex
                          delayVertexCall = True #if the next polygon has the correct material and needs an offset... 

                          modifiedUVValues = copy.deepcopy(self.usedUVValues) #reset modified UV values since there is a new gSPVertex call                            
                      if correctMaterial == True: #Check whether looking for sort by material or sort by primitive color                
                        
                        if delayVertexCall == True:                    
                            delayVertexCall = False                     

                        o.write("   {%d, %d, %d}, \n" % (redirectValue[tempA], redirectValue[tempB], redirectValue[tempC])) 
                      
                      i += 1        
                        
                    i = 0
                    offset = 0
                    count = 0

                    primColorCheck += 1
                    i = 0
                    offset = 0
                    offsetAdjust = 0  

              

                    
#NOTE:NewMaterials-----------------------------------------
                    
              if obj.obj_props.sort_Method == "VTX COLOR" or obj.obj_props.sort_Method == "VTX LIGHTING" or obj.obj_props.sort_Method == "PRIM COLOR":
                
                modifiedUVValues = copy.deepcopy(self.usedUVValues) #reset modified UV values since there is a new gSPVertex call
                #if self.debugCheck == True:
                    #o.write("//MODIFIED UV VALUES RESET \n")   
                
                correctMaterial = False
                delayVertexCall = False
                materialCounter = 0
                objMaterials = obj.data.materials
                matLights = objMaterials[materialCounter].mat_lights
                objLights = obj.obj_lights
                scnLights = scene.scene_lights
                
                correctMaterial = False
                nextMaterial = True #each time the loop occurs, this is re-set to False allowing the material macros/GBI commands to re-print      
                usedMaterial = False

                class OutputOptions:   
                    FORCE_1TRIANGLE = -1
                    UPDATE_NONE = 0
                    UPDATE_GSPVERTEX = 1
                    UPDATE_UVCOORDS = 2
                    UPDATE_GSPVERTEX_AND_UVCOORDS = 3
                
                faceOptions = [OutputOptions.UPDATE_NONE, OutputOptions.UPDATE_NONE]
                modifyVertexCommands = ["",""] #stores modifyvertex commands for later printing
                gSPVertexCommands = ["",""] #stores vertex commands for later printing
                primColorCommands = ["",""]                
                vertexOffsetCompare = [0,0] #used to compare offset of triangle 1 and triangle 2

                
#NOTE: ---- If both an Object light and Scene light are defined, the Object light will be printed in place of the scene light ----   
                if scnLights.custom_lights == True and scnLights.qty_lights > 0:                
                    if objLights.custom_lights == True and objLights.qty_lights > 0:
                        #o.write("\n//Print OBJECT light... \n")           
                        o.write("// Set Object Light: \n")                        
                        o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, obj.obj_lights.qty_lights, DL_name_setting, obj.obj_lights.light_struct_name, DL_end_setting))                       
                    else:
                        #o.write("\n//Print SCENE light... \n")
                        o.write("// Set Scene Light: \n")
                        o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, scnLights.qty_lights, DL_name_setting, scnLights.light_struct_name, DL_end_setting))
                        
                elif objLights.custom_lights == True and objLights.qty_lights > 0:
                    #o.write("\n//Print OBJECT light... \n")
                    o.write("// Set Object Light: \n")
                    o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, objLights.qty_lights, DL_name_setting, objLights.light_struct_name, DL_end_setting))                    
                    
                while materialCounter < len(objMaterials): #Cycle through each material on the current object
#NOTE: ---- Check "Xport64 Object Export Properties" to see if user has indicated they want GBI commands exported and if so, which ones. ----                   
                    objGBICommands = obj.obj_props.gbi_com_settings
                    objExportPrinting = obj.obj_props.gbi_com_settings_method
                    objExportTextureCoords = obj.obj_props.gbi_com_textures #See if the user 
                    objExportPrimColor = obj.obj_props.gbi_prim_color
                    objExportEnvColor = obj.obj_props.gbi_env_color
                    
#NOTE: ---- Check "Xport64 Material/Lighting GBI Commands" for the Material, Lighting, and Color settings set up by the user. ---- 
                    activeMat = objMaterials[materialCounter]                    
                    matProperties = objMaterials[materialCounter].mat_props

                    matPrimColor = matProperties.prim_color
                    matEnvColor = matProperties.env_color
                    
#NOTE: ---- Check "Xport64 Material/Lighting GBI Commands" for the Material, Lighting, and Color settings set up by the user. ----                     
                    matWrapSettings = [matProperties.wrap_commands_w,matProperties.wrap_commands_h]
                    matMaskSettings = [matProperties.mask_commands_w,matProperties.mask_commands_h]
                    matShiftSettings = [matProperties.shift_commands_w,matProperties.shift_commands_h]                       

#NOTE: ---- Check the active material's node tree to see if the user has included a texture for this material ----
#IMPORTANT NOTE: ---- TEXTURE USE REQUIRES CYCLES RENDER ---- 
                    textureSize = [0,0]                        
                    if 'Image Texture' in activeMat.node_tree.nodes:
                        textureImage = activeMat.node_tree.nodes["Image Texture"].image
                        textureName = textureImage.name
                        
#NOTE ---- The following splits the image name from an extension such as: removeExtension[0] = name (ex. debugTexture) removeExtension[1] = extension (ex .png)
                        removeExtension = os.path.splitext(textureName) #splits extension and file name
                        textureName = removeExtension[0] #assigns file name to textureName without the extension
                
#NOTE: Get texture image resolution if texture is being used    
                        if matProperties.custom_tex_res == True:
                            textureSize[0] = matProperties.texture_res_w
                            textureSize[1] = matProperties.texture_res_h
                        else:
                            textureSize = textureImage.size
                        
#NOTE: ---- Check "Xport64 Material/Lighting GBI Commands" to see if the user has specified a custom 4b Color Index Palette, or use the default ----                        
                        if matProperties.custom_tlut_name == True:
                            tlutName = matProperties.texture_tlut_name
                        else:
                            tlutName = ("%s_tlut" % textureName)
                            
                        textureFilter = matProperties.filtering_commands
                            
                    else:
                        objExportTextureCoords = False
                       
                    delayVertexCall = True
                    startMaterial = False
                    modifiedUVValues = copy.deepcopy(self.usedUVValues)            
                    faceCount = 0
                    i = 0
                    offset = 0
                    count = 0
                    faceCounter = 0
                    
#NOTE ---- waitingToPrint is used for checking to see if there is a value ready to go for tri1 and tri2 for catching an odd number of triangles requiring a single gSP1Triangle command
                    waitingToPrint = [False, False]
                    gSP2TriangleCheck = 0     

#NOTE ---- Face counter is checked to see the total number of faces on the current object. 
#          This will catch the loop when we've checked all faces for a specific material and push a gSP1Triangle if we end on an odd number of faces                
                    for face in poly:
                        faceCounter+=1

                    for face in poly:                      
                        
                        use1Triangle = False
                        
                        if  gSP2TriangleCheck <= 0:
                            modifyVertexCompare = [[]]
                            modifyVertexCompare.append([])

                        if face.material_index == materialCounter:

                            waitingToPrint[gSP2TriangleCheck] = True
                           
                            
                            if(startMaterial == False): 
                                startMaterial = True                

                            
#NOTE: ---- START printing GBI/Material commands based on the user's settings from "Xport64 Object Export Settings" including:
    # 1) "Export GBI/Material Commands" (obj_props.gbi_com_settings)
    # 2) "GBI Command Printing" (obj_props.gbi_com_settings_method)
    # 3) "Export ST and Texture Commands" (obj_props.gbi_com_textures)
    # 4) "Export Primative Color" (obj_props.gbi_prim_color)
    # 5) "Export Environment Color" (obj_props.gbi_env_color)    
                                
 #NOTE: Write a series of GBI commands, Display List calls or MACROS if user has set "Export GBI/Material Commands" (obj_props.gbi_com_settings) to True
    #How these commands appear in the user's static or dynamic display list is dictated by "GBI Command Printing" (obj_props.gbi_com_settings_method)
    #('IN LINE', "In-Line Commands", "", 1), ('MACROS', "Pre-Built Macros", "", 2),  ('DL GENERATE', "Generate Display List", "", 3),  ('DL CALL', "Existing Display List", "", 4),
                                #GBIDictionary = PRE_BUILT_SETTINGS["TEXTURE_4B"]
                                GBIDictionary = PRE_BUILT_SETTINGS[matProperties.prebuilt_commands]
                                #GBIDictionary = matProperties.prebuilt_commands

                                
                                if SHOWTIPS == True or DEBUG == True:
                                    o.write("\n\n//>-- MATERIAL %i: START ------------------------------------------ %s -------------------------------------------------\n" % (materialCounter, objMaterials[materialCounter].name))
                                    o.write("//Material: %i '%s'\n" % (materialCounter, objMaterials[materialCounter].name))
                                    o.write("//4b Color Index Palette:  Custom: %s  Name: %s \n" % (matProperties.custom_tlut_name, tlutName))
                                    o.write("//Primitive Color: [%.2f] [%.2f] [%.2f] [%.2f] \n" % (matPrimColor[0], matPrimColor[1], matPrimColor[2], matPrimColor[3]))
                                    o.write("//Environment Color: [%.2f] [%.2f] [%.2f] [%.2f] \n" % (matEnvColor[0], matEnvColor[1], matEnvColor[2], matEnvColor[3]))                    
                                    o.write("//Texture Image Name: %i '%s'\n" % (materialCounter, textureName))
                                    o.write("//Texture Image Size: %i x %i\n" % (textureSize[0], textureSize[1]))
                                    o.write("\n\n//>-- MATERIAL END ------------------------------------------ %s -------------------------------------------------\n" % objMaterials[materialCounter].name)
                                    
                                else:
                                    o.write("\n\n//>-- MATERIAL %i: START ------------------------------------ '%s'-------------------------------------------------\n" % (materialCounter, objMaterials[materialCounter].name))
                                    
                                if objExportTextureCoords == False and (SHOWTIPS == True or DEBUG == True):
                                    o.write("\n\n//>-- TIP START -------------------------------------- Exporting GBI/Material Commands ---------------------------------------------\n")
                                    o.write("//If you intended to include texture commands, be sure that:\n")
                                    o.write("   //1)'Export GBI/Material Commands' is set to True in the 'Xport64 Object Export Settings' panel in 3D View.\n")
                                    o.write("    //2)'Export ST and Texture Coordinates' is set to True in the 'Xport64 Object Export Settings' panel in 3D View.\n")
                                    o.write("     //3)You are using 'Cycles Render' not 'Blender Render' and have attached an image texture node.\n")
                                    o.write("//>-- TIP END --------------------------------------- Exporting GBI/Material Commands ----------------------------------------------\n")   
                                
                                
                                # if matLights.custom_lights == True and matLights.qty_lights > 0:
                                    # #o.write("\n//Print light... \n") 
                                    # o.write("//   Set Material Light: \n")
                                    # o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, matLights.qty_lights, DL_name_setting, matLights.light_struct_name, DL_end_setting))   
                                
                                if objGBICommands == True:                        
                                      
                                    #if objExportTextureCoords == True:                                        
                                    if objExportPrinting == 'IN LINE':
                                        entry = 0 #dictionary entry
                                        o.write("//NOTE ---- IN LINE commands is a WIP and more commands will be added. \n")  
                                        
                                        if "PipeSync" in GBIDictionary:
                                            o.write(GBIDictionary["PipeSync"]% (DL_start_setting, DL_name, DL_end_setting))
                                        
                                        if "TileSync" in GBIDictionary:
                                            o.write(GBIDictionary["TileSync"]% (DL_start_setting, DL_name, DL_end_setting))
                                        
                                        if "CycleType" in GBIDictionary:     
                                            o.write(GBIDictionary["CycleType"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "ClearGeometryMode" in GBIDictionary:     
                                            o.write(GBIDictionary["ClearGeometryMode"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "SetGeometryMode" in GBIDictionary:     
                                            o.write(GBIDictionary["SetGeometryMode"]% (DL_start_setting, DL_name_setting, DL_end_setting))                                                
   
                                        if "Texture" in GBIDictionary:
                                            o.write(GBIDictionary["Texture"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "TextureLUT" in GBIDictionary:
                                            o.write(GBIDictionary["TextureLUT"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "SetCombineMode" in GBIDictionary: #Export with pre-existing combiner settings
                                            o.write(GBIDictionary["SetCombineMode"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "SetCombineLERP" in GBIDictionary: #Export with a custom combiner setting
                                            o.write(GBIDictionary["SetCombineLERP"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                        
                                        if "SetRenderMode" in GBIDictionary:
                                            o.write(GBIDictionary["SetRenderMode"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "LoadTextureBlock_4b" in GBIDictionary:
                                            o.write(GBIDictionary["LoadTextureBlock_4b"]% (DL_start_setting, DL_name_setting, textureName, 
                                                textureSize[0],textureSize[1], matWrapSettings[0], matWrapSettings[1], matMaskSettings[0], matMaskSettings[1], 
                                                matShiftSettings[0], matShiftSettings[1], DL_end_setting))
                                        
                                        if "LoadTextureBlock" in GBIDictionary:
                                            o.write(GBIDictionary["LoadTextureBlock"]% (DL_start_setting, DL_name_setting, textureName, 
                                                textureSize[0],textureSize[1], matWrapSettings[0], matWrapSettings[1], matMaskSettings[0], matMaskSettings[1], 
                                                matShiftSettings[0], matShiftSettings[1], DL_end_setting))
                                                
                                        if "LoadTLUT" in GBIDictionary:    
                                            o.write(GBIDictionary["LoadTLUT"]% (DL_start_setting, DL_name_setting, tlutName, DL_end_setting))
                                        
                                        if "SetTextureFilter" in GBIDictionary:     
                                            o.write(GBIDictionary["SetTextureFilter"]% (DL_start_setting, DL_name_setting, textureFilter, DL_end_setting))
                                            
                                        if "ForceBilerpFilter" in GBIDictionary:     
                                            o.write(GBIDictionary["ForceBilerpFilter"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "SetColorDither" in GBIDictionary:     
                                            o.write(GBIDictionary["SetColorDither"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                            
                                        if "sDPSetAlphaDither" in GBIDictionary:     
                                            o.write(GBIDictionary["sDPSetAlphaDither"]% (DL_start_setting, DL_name_setting, DL_end_setting))
                                        
                                    elif objExportPrinting == 'MACROS':
                                        o.write("\n   %s(%s %s, %s, RES_%ix%i, %s,%s, %s,%s, %s,%s  %s\n\n" % (matProperties.prebuilt_commands, DL_name_setting, textureName, tlutName, 
                                            textureSize[0],textureSize[1], matWrapSettings[0], matWrapSettings[1], matMaskSettings[0], matMaskSettings[1], 
                                            matShiftSettings[0], matShiftSettings[1], DL_end_setting))
                                    
                                    elif objExportPrinting == 'DL GENERATE':
                                        o.write("//NOTE ---- Generate new GBI Display List not yet supported.\n")  
                                        
                                    elif objExportPrinting == 'DL CALL':
                                        o.write("   %sSPDisplayList(  %s %s %s\n" % (DL_start_setting, DL_name_setting, obj.obj_props.gbi_com_existing_DL, DL_end_setting) )
                                             
                                    if objExportPrimColor: 
                                        o.write("   %sDPSetPrimColor(%s %i,%i,%i,%i,%i,%i  %s\n" % (DL_start_setting, DL_name_setting, 1,255,matPrimColor[0]*255, matPrimColor[1]*255, matPrimColor[2]*255, matPrimColor[3]*255, DL_end_setting))
                                        
                                    if objExportEnvColor: 
                                        o.write("   %sDPSetEnvColor(%s %i,%i,%i,%i  %s\n" % (DL_start_setting, DL_name_setting, matEnvColor[0]*255, matEnvColor[1]*255, matEnvColor[2]*255, matEnvColor[3]*255, DL_end_setting))
                                    
                                    o.write("\n")

                                    
                                if matLights.custom_lights == True and matLights.qty_lights > 0:
                                    #o.write("\n//Print MATERIAL light... \n")
                                    o.write("// Set Material Light: \n")
                                    o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, matLights.qty_lights, DL_name_setting, matLights.light_struct_name, DL_end_setting))                                    
                               
                            for vert, loop in zip(face.vertices, face.loop_indices):
                                vcol = obj.data.vertex_colors.active.data[loop].color if obj.data.vertex_colors.active else (1,1,1,1)
                                uv = obj.data.uv_layers.active.data[loop].uv if obj.data.uv_layers.active else (0,0)
                                coord = obj.data.vertices[vert].co * obj.matrix_world                                           
                          
                            tempA = i*3
                            tempB = i*3+1
                            tempC = i*3+2
                            
                            if redirectValue[tempA] > offset+loadlim or redirectValue[tempB] > offset+loadlim or redirectValue[tempC] > offset+loadlim:
                                offset += loadlim 
                                count = 0
                                
                                while redirectValue[tempA] > offset+loadlim or redirectValue[tempB] > offset+loadlim or redirectValue[tempC] > offset+loadlim:         
                                    offset += loadlim
                                    
                                offsetAdjust = 0
                                
                                for x in range(offset, offset+loadlim):
                                    if redirectValue[tempA]-offset < offsetAdjust:
                                      offsetAdjust = redirectValue[tempA]-offset
                                    if redirectValue[tempB]-offset < offsetAdjust:
                                      offsetAdjust = redirectValue[tempB]-offset
                                    if redirectValue[tempC]-offset < offsetAdjust:
                                      offsetAdjust = redirectValue[tempC]-offset

                                if DEBUG == True: #DEBUG CHECK VALUES:---                                
                                    o.write("\n//Offset: %i += OffsetAdjust: %i" % (offset, offsetAdjust ))
                                
                                offset += offsetAdjust  #artificially reduce offsetAdjust by 3 to minimize the number of back-to-back gSPVertex calls                    
                                delayVertexCall = True #if the next polygon has the correct material and needs an offset...
                                modifiedUVValues = copy.deepcopy(self.usedUVValues) #reset modified UV values since there is a new gSPVertex call
                                
                                vertexOffsetCompare[gSP2TriangleCheck] = offsetAdjust #store for later comparison for each triangle
                            
                            
                            # If redirected variable is below the current offset, reduce offset    
                            if redirectValue[tempA]-offset < 0 or redirectValue[tempB]-offset < 0 or redirectValue[tempC]-offset < 0:                   
                                numCheck = redirectValue[tempA]-offset
                                if redirectValue[tempB]-offset < numCheck:
                                    numCheck = redirectValue[tempB]-offset
                                if redirectValue[tempC]-offset < numCheck: 
                                    numCheck = redirectValue[tempC]-offset
                                
                                if DEBUG == True: #DEBUG CHECK VALUES:---                                
                                    o.write("\n//Offset: %i += numCheck: %i" % (offset, numCheck ))
                                
                                offset += numCheck
                                
                                delayVertexCall = True  #Compare UV value against redirect value. If they have different UV values, use gSPModifyVertex
                                modifiedUVValues = copy.deepcopy(self.usedUVValues) #reset modified UV values since there is a new gSPVertex call
                            
                                vertexOffsetCompare[gSP2TriangleCheck] = numCheck #store for later comparison for each triangle

                            if delayVertexCall == True:
                                #o.write("//Setting gSP2TriangleCheck %i to OutputOptions.UPDATE_GSPVERTEX \n" % gSP2TriangleCheck) 
                                gSPVertexCommands[gSP2TriangleCheck] = ""
                                gSPVertexCommands[gSP2TriangleCheck] += ("   %sSPVertex(%s %s%s+%d,%d,0  %s\n" % (DL_start_setting, DL_name_setting, name, VertList_setting, offset, loadlim+1, DL_end_setting)) #load the first x number of vertices
                                faceOptions[gSP2TriangleCheck] = OutputOptions.UPDATE_GSPVERTEX

                            gSP2TriangleHold[gSP2TriangleCheck] = [redirectValue[tempA]-offset, redirectValue[tempB]-offset, redirectValue[tempC]-offset, redirectValue[tempA]-offset]

    #NOTE: Check UV coordinates of the currently used UV Values for the current Vertex and see if ModifyVertex is needed
    #NOTE: If user has set "Export ST and Texture Commands" (obj_props.gbi_com_textures) to false then no ModifyVertex commands will be used. 
    #This is useful if rendering the object with primitive colors. It will save texture commands, UV commands, and allow for more gSP2Triangles commands
    #matTextureSize[0]textureSize
                            if objExportTextureCoords == True:
                                if redirectValue[tempA]-offset >= 0 and redirectValue[tempB]-offset >= 0 and redirectValue[tempC]-offset >= 0:
                                    modify = False
                                    if roundtoquarter(self.uvValue[objCounter][tempA][0]) != roundtoquarter(modifiedUVValues[objCounter][redirectValue[tempA]][0]) or roundtoquarter(self.uvValue[objCounter][tempA][1]) != roundtoquarter(modifiedUVValues[objCounter][redirectValue[tempA]][1]):  
                                        modify = True 
                                        modifyVertexCommands[gSP2TriangleCheck] += ("   %sSPModifyVertex(%s %d,   G_MWO_POINT_ST, 0x%0004x%0004x%s  /*New Coords: %.2f, %.2f*/" % (DL_start_setting, DL_name_setting,redirectValue[tempA]-offset, int((self.uvValue[objCounter][tempA][0])*textureSize[0]), int((self.uvValue[objCounter][tempA][1])*textureSize[1]), DL_end_setting, self.uvValue[objCounter][tempA][0], self.uvValue[objCounter][tempA][1]))
                                        modifiedUVValues[objCounter][redirectValue[tempA]][0] = self.uvValue[objCounter][tempA][0] #update modifiedUVValues 
                                        modifiedUVValues[objCounter][redirectValue[tempA]][1] = self.uvValue[objCounter][tempA][1]
                                        modifyVertexCompare[gSP2TriangleCheck].append(redirectValue[tempA]) #to see if both tri1 and tri2 are using and modifying the same vertex                                       
                                      
                                    if roundtoquarter(self.uvValue[objCounter][tempB][0]) != roundtoquarter(modifiedUVValues[objCounter][redirectValue[tempB]][0]) or roundtoquarter(self.uvValue[objCounter][tempB][1]) != roundtoquarter(modifiedUVValues[objCounter][redirectValue[tempB]][1]):    
                                        modify = True
                                        modifyVertexCommands[gSP2TriangleCheck] += ("   %sSPModifyVertex(%s %d,   G_MWO_POINT_ST, 0x%0004x%0004x%s  /*New Coords: %.2f, %.2f*/" % (DL_start_setting, DL_name_setting, redirectValue[tempB]-offset, int((self.uvValue[objCounter][tempB][0])*textureSize[0]), int((self.uvValue[objCounter][tempB][1])*textureSize[1]), DL_end_setting, self.uvValue[objCounter][tempB][0], self.uvValue[objCounter][tempB][1]))
                                        modifiedUVValues[objCounter][redirectValue[tempB]][0] = self.uvValue[objCounter][tempB][0]
                                        modifiedUVValues[objCounter][redirectValue[tempB]][1] = self.uvValue[objCounter][tempB][1]
                                        modifyVertexCompare[gSP2TriangleCheck].append(redirectValue[tempB]) #to see if both tri1 and tri2 are using and modifying the same vertex
                                      
                                    if roundtoquarter(self.uvValue[objCounter][tempC][0]) != roundtoquarter(modifiedUVValues[objCounter][redirectValue[tempC]][0]) or roundtoquarter(self.uvValue[objCounter][tempC][1]) != roundtoquarter(modifiedUVValues[objCounter][redirectValue[tempC]][1]):  
                                        modify = True
                                        modifyVertexCommands[gSP2TriangleCheck] += ("   %sSPModifyVertex(%s %d,   G_MWO_POINT_ST, 0x%0004x%0004x%s  /*New Coords: %.2f, %.2f*/" % (DL_start_setting, DL_name_setting, redirectValue[tempC]-offset, int((self.uvValue[objCounter][tempC][0])*textureSize[0]), int((self.uvValue[objCounter][tempC][1])*textureSize[1]), DL_end_setting, self.uvValue[objCounter][tempC][0], self.uvValue[objCounter][tempC][1]))
                                        modifiedUVValues[objCounter][redirectValue[tempC]][0] = self.uvValue[objCounter][tempC][0] 
                                        modifiedUVValues[objCounter][redirectValue[tempC]][1] = self.uvValue[objCounter][tempC][1]
                                        modifyVertexCompare[gSP2TriangleCheck].append(redirectValue[tempC]) #to see if both tri1 and tri2 are using and modifying the same vertex
                                    
                                    if modify == True:
                                        if faceOptions[gSP2TriangleCheck] == OutputOptions.UPDATE_GSPVERTEX:
                                            faceOptions[gSP2TriangleCheck] = OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS
                                        else: 
                                            faceOptions[gSP2TriangleCheck] = OutputOptions.UPDATE_UVCOORDS
                                        
                                        #use1Triangle = False

                            if  gSP2TriangleCheck >= 1: #after gathering commands, compare them for optimization...
                                # compareSort = [[0 for x in range(4)] for y in range(2)] 
                                # compareSort[0] = [gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3]]
                                # compareSort[1] = [gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3]]
                                #o.write("\n//modifyVertexCompare[0][%i,%i,%i]: \n" %(modifyVertexCompare[0][0],modifyVertexCompare[0][1],modifyVertexCompare[0][2]) )
                                loop = 0
                                while loop < len(modifyVertexCompare[0]):
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("\n//modifyVertexCompare[0][%i]\n" %(modifyVertexCompare[0][loop]))
                                    loop +=1
                                loop = 0
                                while loop < len(modifyVertexCompare[1]):
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("\n//modifyVertexCompare[1][%i]\n" %(modifyVertexCompare[1][loop]))
                                    loop +=1

                                if DEBUG == True: #DEBUG CHECK VALUES:---  
                                    o.write("\n//Testing for use1Triangle\n" )
                                    
                                loopOuter = 0
                                loopInner = 0
                                
#NOTE ---- Make sure that tri1 and tri2 are not modifying the same vertex
                                while loopOuter < len(modifyVertexCompare[0]):
                                    while loopInner < len(modifyVertexCompare[1]):                                            
                                        if faceOptions[0] != OutputOptions.FORCE_1TRIANGLE:
                                            if DEBUG == True: #DEBUG CHECK VALUES:---  
                                                o.write("//Outer: %i  Inner: %i\n" % (redirectValue[loopOuter]-offset, redirectValue[loopInner]-offset) )
                                            if modifyVertexCompare[0][loopOuter] == modifyVertexCompare[1][loopInner]:
                                                use1Triangle = True
                                                #faceOptions[0] = OutputOptions.FORCE_1TRIANGLE
                                                if DEBUG == True: #DEBUG CHECK VALUES:---  
                                                    o.write("//Split into 2 separate 1Triangle Calls\n" )
                                                loopOuter = tempC+3
                                                loopInnter = tempA
                                                break                                               
                                            
                                            loopInner += 1
                                    loopOuter += 1
                                    loopInner = 0 
                                    
#NOTE ---- Make sure that tri2 is not modifying a vertex used in tri1  
                                loopOuter = 0
                                
                                if use1Triangle == False:
                                    while loopOuter < len(modifyVertexCompare[1]):
                                        if DEBUG == True: #DEBUG CHECK VALUES:---     
                                            o.write("//NOTE ---- tri1:(%i, %i, %i) \n" % (gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2]))
                                        if (modifyVertexCompare[1][loopOuter] == gSP2TriangleHold[0][0]) or  (modifyVertexCompare[1][loopOuter] == gSP2TriangleHold[0][1]) or  (modifyVertexCompare[1][loopOuter] == gSP2TriangleHold[0][2]) :
                                            if DEBUG == True: #DEBUG CHECK VALUES:--- 
                                                o.write("//NOTE ---- tri2:(%i) is modifying a value used in tri1:(%i, %i, %i) \n" % (modifyVertexCompare[1][loopOuter], gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2]))
                                            use1Triangle = True
                                        loopOuter +=1                                    
                                    
                                if use1Triangle == True:
                                    if SHOWTIPS == True or DEBUG == True:
                                        o.write("//NOTE ---- Split into separate 1Triangle commands \n")
                                    if faceOptions[0] == OutputOptions.UPDATE_NONE and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS:
                                        faceOptions[0] = OutputOptions.FORCE_1TRIANGLE
                                    modifyVertexCommands[0] += ("\n")
                                    modifyVertexCommands[1] += ("\n")
                                        
                                elif use1Triangle == False:
                                    if SHOWTIPS == True or DEBUG == True:
                                        o.write("//NOTE ---- Combine both UVCoords updates into 2Triangles commands \n")
                                    if (faceOptions[0] == OutputOptions.UPDATE_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS) or (faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS):
                                        modifyVertexCommands[0] += modifyVertexCommands[1]
                                        faceOptions[1] = OutputOptions.UPDATE_NONE
                                        modifyVertexCommands[0] += ("\n")
                                    else: 
                                        modifyVertexCommands[0] += ("\n")
                                        modifyVertexCommands[1] += ("\n")

                            #NOTE: The following section beginning with 'if  gSP2TriangleCheck >= 2: ' is the previous working version...
                            if  gSP2TriangleCheck >= 1: #after gathering information on 2 triangle commands...     
                                #o.write("//Testing current gSP2TriangleCheck... %i \n" % gSP2TriangleCheck)  
                            #after setting both faceOptions:      
                                
                                if DEBUG == True: #DEBUG CHECK VALUES:---  
                                    o.write("\n//Tri 1 of 2: faceOptions[0] %s\n" % faceOptions[0]) 
                                    o.write("//Tri 2 of 2: faceOptions[1] %s\n" % faceOptions[1])

                                if faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX and faceOptions[1] == OutputOptions.UPDATE_NONE:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet1...\n") 
                                    o.write("%s" % gSPVertexCommands[0])
                                    #o.write("   %sSPVertex(%s %s%s+%d,%d,0  %s\n" % (DL_start_setting, DL_name_setting, name, VertList_setting, offset, loadlim+1, DL_end_setting)) #load the first x number of vertices
                                    o.write("     %sSP2Triangles(%s  %i, %i, %i, %i, %i, %i, %i, %i  %s\n" % 
                                    (
                                        DL_start_setting, DL_name_setting,
                                        gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3],
                                        gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3],
                                        DL_end_setting)                            
                                    )
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_NONE and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet2...\n")
                                        
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                                                                                          
                                elif faceOptions[0] == OutputOptions.UPDATE_NONE and faceOptions[1] == OutputOptions.UPDATE_NONE:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet3...\n") 
                                    o.write("     %sSP2Triangles(%s  %i, %i, %i, %i, %i, %i, %i, %i  %s\n" % 
                                    (
                                        DL_start_setting, DL_name_setting,
                                        gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3],
                                        gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3],
                                        DL_end_setting)                            
                                    )
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_NONE and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet4...\n")
   
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP2Triangles(%s  %i, %i, %i, %i, %i, %i, %i, %i  %s\n" % 
                                    (
                                        DL_start_setting, DL_name_setting,
                                        gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3],
                                        gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3],
                                        DL_end_setting)                            
                                    )
                                    
                                #FORCE_1TRIANGLE
                                
                                elif faceOptions[0] == OutputOptions.FORCE_1TRIANGLE and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet4 1/2...\n")
                                        
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_NONE and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                            o.write("// OptionSet9...\n")                                 
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_NONE:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet5...\n")
                                    o.write("%s" % modifyVertexCommands[0] )
                                    o.write("     %sSP2Triangles(%s  %i, %i, %i, %i, %i, %i, %i, %i  %s\n" % 
                                    (
                                        DL_start_setting, DL_name_setting,
                                        gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3],
                                        gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3],
                                        DL_end_setting)                            
                                    )
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet6...\n" )
                                    o.write("%s" % modifyVertexCommands[0] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))

                                elif faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS:  
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet7...\n")
                                    o.write("%s" % gSPVertexCommands[0])                                    
                                    o.write("%s" % modifyVertexCommands[0] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX:  
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet8...\n")
                                    o.write("%s" % gSPVertexCommands[0])                                    
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False
                                
                                elif faceOptions[0] == OutputOptions.UPDATE_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                            o.write("// OptionSet9...\n")
                                    o.write("%s" % modifyVertexCommands[0] )                                    
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX:
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                            o.write("// OptionSet9...\n")
                                    o.write("%s" % modifyVertexCommands[0] )                                    
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False
                                    
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_NONE:  
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet10...\n")
                                    o.write("%s" % gSPVertexCommands[0])
                                    o.write("%s" % modifyVertexCommands[0] )        
                                    o.write("     %sSP2Triangles(%s  %i, %i, %i, %i, %i, %i, %i, %i  %s\n" % 
                                    (
                                        DL_start_setting, DL_name_setting,
                                        gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3],
                                        gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3],
                                        DL_end_setting)                            
                                    )   
                                    
                                elif faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS:  
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet11...\n")
                                    o.write("%s" % gSPVertexCommands[0])
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP2Triangles(%s  %i, %i, %i, %i, %i, %i, %i, %i  %s\n" % 
                                    (
                                        DL_start_setting, DL_name_setting,
                                        gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3],
                                        gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3],
                                        DL_end_setting)                            
                                    )
                                elif faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS:  
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet12...\n")
                                    o.write("%s" % gSPVertexCommands[0] )                                    
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False
                                elif faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_GSPVERTEX:  
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet13...\n")
                                    o.write("%s" % gSPVertexCommands[0] )
                                    o.write("%s" % modifyVertexCommands[0] )                                    
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % gSPVertexCommands[1])
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False
                                elif faceOptions[0] == OutputOptions.UPDATE_GSPVERTEX_AND_UVCOORDS and faceOptions[1] == OutputOptions.UPDATE_UVCOORDS:  
                                    if DEBUG == True: #DEBUG CHECK VALUES:---  
                                        o.write("// OptionSet13...\n")
                                    o.write("%s" % gSPVertexCommands[0] )
                                    o.write("%s" % modifyVertexCommands[0] )                                    
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting))
                                    o.write("%s" % modifyVertexCommands[1] )
                                    o.write("     %sSP1Triangle(%s  %d, %d, %d, %d  %s\n" % (DL_start_setting, DL_name_setting, gSP2TriangleHold[1][0], gSP2TriangleHold[1][1], gSP2TriangleHold[1][2], gSP2TriangleHold[1][3], DL_end_setting))
                                    #delayVertexCall = False     

                                else:
                                    o.write("\n// ERROR: 2 triangles did not print due to not meeting faceOption parameters. \n" )
    
                            #increment counters        
                            if gSP2TriangleCheck < 1: 
                                gSP2TriangleCheck += 1
                                delayVertexCall = False #re-set this each cycle 
                            
                            #reset counter, strings, and other values
                            else:
                                gSP2TriangleCheck = 0
                                modifyVertexCommands[0] = "" #re-set back to a blank string
                                modifyVertexCommands[1] = "" #re-set back to a blank string   
                                gSPVertexCommands[0] = "" #re-set back to a blank string
                                gSPVertexCommands[1] = "" #re-set back to a blank string
                                faceOptions[0] = OutputOptions.UPDATE_NONE
                                faceOptions[1] = OutputOptions.UPDATE_NONE
                                vertexOffsetCompare[0] = 0
                                vertexOffsetCompare[1] = 0
                                delayVertexCall = False
                                waitingToPrint = [False, False] #Resets waiting to print until there are new confirmed commands

                        #NOTE ---- if we reach the end with an odd number of faces, push a single triangle command. 
                        
                        
                        i+=1
                        faceCount += 1  
                    
                    #o.write("\n//TESTING LOOP: %i" % i)
                    if waitingToPrint[0] == True and waitingToPrint[1] == False:
                        #o.write("//NOTE ---- End of faces for this material, pushing a single gSP1Triangle.")
                        o.write("%s" % gSPVertexCommands[0])
                        o.write("%s" % modifyVertexCommands[0] )        
                        o.write("     %sSP1Triangle(%s  %i, %i, %i, %i  %s\n" % 
                        (
                            DL_start_setting, DL_name_setting,
                            gSP2TriangleHold[0][0], gSP2TriangleHold[0][1], gSP2TriangleHold[0][2], gSP2TriangleHold[0][3], DL_end_setting)                            
                        )   
                    materialCounter += 1
                    
#NOTE: ---- At the end of this material, reset the currently used light to be the object or scene light ----   
                    if matLights.custom_lights == True and matLights.qty_lights > 0: 
                        if scnLights.custom_lights == True and scnLights.qty_lights > 0:                
                            if objLights.custom_lights == True and objLights.qty_lights > 0:
                                o.write("// Set Object Light: \n")
                                o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, obj.obj_lights.qty_lights, DL_name_setting, obj.obj_lights.light_struct_name, DL_end_setting))                       
                            else:
                                o.write("// Set Scene Light: \n")
                                o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, scnLights.qty_lights, DL_name_setting, scnLights.light_struct_name, DL_end_setting))
                                
                        elif objLights.custom_lights == True and objLights.qty_lights > 0:
                            o.write("// Set Object Light: \n")
                            o.write("   %sSPSetLights%i( %s %s %s\n" % (DL_start_setting, objLights.qty_lights, DL_name_setting, objLights.light_struct_name, DL_end_setting))

                if usedMaterial == True: #If at least one polygon used this material, separate it from the next material...
                    o.write("\n")
                    usedMaterial = False
        
                i = 0
                offset = 0
                count = 0

                primColorCheck += 1
                i = 0
                offset = 0
                offsetAdjust = 0  
                      
                    
    #WIP3------------------------------------------Static Display List Setting-------------------------------------------
              #if self.textureType != "COLLISION":
              if obj.obj_props.sort_Method != "COLLISION":
                if obj.obj_props.static_DL == False:
                    o.write("   %sDPPipeSync(  %s  %s\n" %(DL_start_setting, DL_name, DL_end_setting))
                if obj.obj_props.static_DL == True:
                    o.write("   %sSPEndDisplayList()\n " % DL_start_setting)

              exportPolyList = False

              if obj.obj_props.sort_Method == "COLLISION" or obj.obj_props.static_DL == True:
                o.write("}; \n")
              else:
                o.write("} \n")
              
              if obj.obj_props.static_DL == False or obj.obj_props.anim_Method == "OBJ VARIABLES" or obj.obj_props.anim_Method == "NO ANIM": 
                break
        
        o.write("\n//>-- OBJECT %i: END ------------------------------------------- %s -------------------------------------------------\n\n" % (objCounter, name))
        if sceneprops.create_header_file == True:  #NOTE ----- Save these commands in a string for later use in .h file for defintions and declarations:
            self.definitionsFile[self.commandCount] = ("\n//>-- OBJECT %i: END ------------------------------------------- %s -------------------------------------------------\n\n" % (objCounter, name))
            self.definitionsFile.append([])
            self.commandCount +=1

        o.write(" \n ")

class Lights_Xport64(bpy.types.Operator):
    bl_idname = "lights.xport64"
    bl_label = "Xport64 - N64Lights Export"
    
#---------------------------------------------------------------------------------------------------------
#EXPORTER_NOTES:    For now this is only for grabbing and printing scn, obj, and mat light structures for this scene. 
#                   Eventually this should include an option for "baked" lighting where actual blender lights can bake to a model's VTX colors...
#                   This is a ways away though, so for now "baked" lighting must be done manually with Blender's Vertex Paint mode.
#---------------------------------------------------------------------------------------------------------   

    def exportSCNLights(self, objsFileC):
        scene = bpy.context.scene
        obj = bpy.context.object
        sceneprops = scene.scene_props
        scenelights = scene.scene_lights
        amblight = scenelights.amb_light
        scnLightStruct = [[1.0,1.0,1.0]]
        
        if scenelights.custom_lights == True and scenelights.qty_lights > 0:
            #objsFileC.write("\n\n //----- PRINT SCN LIGHTS ----- \n")
#NOTE: ---- If a s light is set, grab the ambient light color and the 1st directional light color/angle. ----   
#           ambLight structure - [R,G,B] Color is from 0-255, ambient lights have no direction
#           DirLight structure - [R,G,B,X,Y,Z] Color is from 0-255, angle is from -90 to 90 and currently assumes Z-up but this may be adjustable in the future
                    
            scnLightStruct[0] = [scene.scene_lights.amb_light[0],scene.scene_lights.amb_light[1],scene.scene_lights.amb_light[2]]
            scnLightStruct.append([])                        
            scnLightStruct[1] = [scene.scene_lights.dir_lights[0],scene.scene_lights.dir_lights[1],scene.scene_lights.dir_lights[2], scene.scene_lights.light_dir[0],scene.scene_lights.light_dir[2],scene.scene_lights.light_dir[1]] 
            scnLightStruct.append([])
            if scene.scene_lights.qty_lights >=2:
                scnLightStruct[2] = [scene.scene_lights.dir_lights2[0],scene.scene_lights.dir_lights2[1],scene.scene_lights.dir_lights2[2], scene.scene_lights.light_dir2[0],scene.scene_lights.light_dir2[2],scene.scene_lights.light_dir2[1]]
                scnLightStruct.append([])
                if scene.scene_lights.qty_lights ==3:
                    scnLightStruct[3] = [scene.scene_lights.dir_lights3[0],scene.scene_lights.dir_lights3[1],scene.scene_lights.dir_lights3[2], scene.scene_lights.light_dir3[0],scene.scene_lights.light_dir3[2],scene.scene_lights.light_dir3[1]]
            
            objsFileC.write("\n   Lights%i %s = gdSPDefLights%i(\n" %(scene.scene_lights.qty_lights, scene.scene_lights.light_struct_name, scene.scene_lights.qty_lights))
            objsFileC.write("     %i, %i, %i,\n" %(int(scnLightStruct[0][0]*255),int(scnLightStruct[0][1]*255),int(scnLightStruct[0][2]*255) ))

            objsFileC.write("     %i, %i, %i,     %i, %i, %i" %(int(scnLightStruct[1][0]*255),int(scnLightStruct[1][1]*255),int(scnLightStruct[1][2]*255),int(scnLightStruct[1][3]*90),int(scnLightStruct[1][4]*90),int(scnLightStruct[1][5]*90) ))                        
            if scene.scene_lights.qty_lights >=2:
                objsFileC.write(",\n     %i, %i, %i,     %i, %i, %i" %(int(scnLightStruct[2][0]*255),int(scnLightStruct[2][1]*255),int(scnLightStruct[2][2]*255),int(scnLightStruct[2][3]*90),int(scnLightStruct[2][4]*90),int(scnLightStruct[2][5]*90) ))
                if scene.scene_lights.qty_lights ==3:
                    objsFileC.write(",\n     %i, %i, %i,     %i, %i, %i"%(int(scnLightStruct[3][0]*255),int(scnLightStruct[3][1]*255),int(scnLightStruct[3][2]*255),int(scnLightStruct[3][3]*90),int(scnLightStruct[3][4]*90),int(scnLightStruct[3][5]*90) ))
            objsFileC.write("\n   );\n")
            
            self.N64LightNames[self.N64LightCount] = scene.scene_lights.light_struct_name
            self.N64LightNames.append([])
            self.N64LightCount += 1
           
    def exportOBJLights(self, objsFileC, obj):

        objLightStruct = [[1.0,1.0,1.0]]
        matLightStruct = [[1.0,1.0,1.0]]
        unusedLight = True
        tempCounter = 0
        DEBUG = obj.obj_props.debug_DL #NOTE: User can debug script and look for problem areas
        SHOWTIPS = obj.obj_props.guide_DL #NOTE: User can view tips and guidance on how to utilize this tool
        
        objMaterials = obj.data.materials
        
        if obj.obj_lights.custom_lights == True and obj.obj_lights.qty_lights > 0:
            
            for light in self.N64LightNames:
                if obj.obj_lights.light_struct_name == light:
                    if DEBUG == True:
                        objsFileC.write("\n//WARNING: Light Structure Name %s on object %s already defined! Will use existing structure. If you need a new light, re-name this object's light struct.\n" % (obj.obj_lights.light_struct_name, obj.name))
                    unusedLight = False
                                        
            if unusedLight == True:
                #objsFileC.write("\n\n //----- PRINT OBJ LIGHTS ----- \n")
#NOTE: ---- If an object light is set, grab the ambient light color and the 1st directional light color/angle. ----                       
                objLightStruct[0] = [obj.obj_lights.amb_light[0],obj.obj_lights.amb_light[1],obj.obj_lights.amb_light[2]]
                objLightStruct.append([])                        
                objLightStruct[1] = [obj.obj_lights.dir_lights[0],obj.obj_lights.dir_lights[1],obj.obj_lights.dir_lights[2], obj.obj_lights.light_dir[0],obj.obj_lights.light_dir[2],obj.obj_lights.light_dir[1]] 
                objLightStruct.append([])
                if obj.obj_lights.qty_lights >=2:
                    objLightStruct[2] = [obj.obj_lights.dir_lights2[0],obj.obj_lights.dir_lights2[1],obj.obj_lights.dir_lights2[2], obj.obj_lights.light_dir2[0],obj.obj_lights.light_dir2[2],obj.obj_lights.light_dir2[1]]
                    objLightStruct.append([])
                    if obj.obj_lights.qty_lights ==3:
                        objLightStruct[3] = [obj.obj_lights.dir_lights3[0],obj.obj_lights.dir_lights3[1],obj.obj_lights.dir_lights3[2], obj.obj_lights.light_dir3[0],obj.obj_lights.light_dir3[2],obj.obj_lights.light_dir3[1]]
                
                objsFileC.write("\n   Lights%i %s = gdSPDefLights%i(\n" %(obj.obj_lights.qty_lights, obj.obj_lights.light_struct_name, obj.obj_lights.qty_lights))
                objsFileC.write("     %i, %i, %i,\n" %(int(objLightStruct[0][0]*255),int(objLightStruct[0][1]*255),int(objLightStruct[0][2]*255) ))

                objsFileC.write("     %i, %i, %i,     %i, %i, %i" %(int(objLightStruct[1][0]*255),int(objLightStruct[1][1]*255),int(objLightStruct[1][2]*255),int(objLightStruct[1][3]*90),int(objLightStruct[1][4]*90),int(objLightStruct[1][5]*90) ))                        
                if obj.obj_lights.qty_lights >=2:
                    objsFileC.write(",\n     %i, %i, %i,     %i, %i, %i" %(int(objLightStruct[2][0]*255),int(objLightStruct[2][1]*255),int(objLightStruct[2][2]*255),int(objLightStruct[2][3]*90),int(objLightStruct[2][4]*90),int(objLightStruct[2][5]*90) ))
                    if obj.obj_lights.qty_lights ==3:
                        objsFileC.write(",\n     %i, %i, %i,     %i, %i, %i"%(int(objLightStruct[3][0]*255),int(objLightStruct[3][1]*255),int(objLightStruct[3][2]*255),int(objLightStruct[3][3]*90),int(objLightStruct[3][4]*90),int(objLightStruct[3][5]*90) ))
                objsFileC.write("\n   );\n")
                            
                self.N64LightNames[self.N64LightCount] = obj.obj_lights.light_struct_name
                self.N64LightNames.append([])
                self.N64LightCount += 1
                
        for mat in objMaterials:
            if mat.mat_lights.custom_lights == True and mat.mat_lights.qty_lights > 0:
                #objsFileC.write("\n//Material Name: %s Light Struct Name: %s \n" % (material.name, material.mat_lights.light_struct_name))
                
                for light in self.N64LightNames:
                    if mat.mat_lights.light_struct_name == light:
                        if DEBUG == True:
                            objsFileC.write("\n//WARNING: Light Structure Name %s on object %s already defined! Will use existing structure. If you need a new light, re-name this object's light struct.\n" % (mat.mat_lights.light_struct_name, obj.name))
                        unusedLight = False
                                            
                if unusedLight == True:
                    #objsFileC.write("\n\n //----- PRINT OBJ LIGHTS ----- \n")
#NOTE: ---- If an object light is set, grab the ambient light color and the 1st directional light color/angle. ----                       
                    matLightStruct[0] = [mat.mat_lights.amb_light[0],mat.mat_lights.amb_light[1],mat.mat_lights.amb_light[2]]
                    matLightStruct.append([])                        
                    matLightStruct[1] = [mat.mat_lights.dir_lights[0],mat.mat_lights.dir_lights[1],mat.mat_lights.dir_lights[2], mat.mat_lights.light_dir[0],mat.mat_lights.light_dir[2],mat.mat_lights.light_dir[1]] 
                    matLightStruct.append([])
                    if mat.mat_lights.qty_lights >=2:
                        matLightStruct[2] = [mat.mat_lights.dir_lights2[0],mat.mat_lights.dir_lights2[1],mat.mat_lights.dir_lights2[2], mat.mat_lights.light_dir2[0],mat.mat_lights.light_dir2[2],mat.mat_lights.light_dir2[1]]
                        matLightStruct.append([])
                        if mat.mat_lights.qty_lights ==3:
                            matLightStruct[3] = [mat.mat_lights.dir_lights3[0],mat.mat_lights.dir_lights3[1],mat.mat_lights.dir_lights3[2], mat.mat_lights.light_dir3[0],mat.mat_lights.light_dir3[2],mat.mat_lights.light_dir3[1]]
                    
                    objsFileC.write("\n   Lights%i %s = gdSPDefLights%i(\n" %(mat.mat_lights.qty_lights, mat.mat_lights.light_struct_name, mat.mat_lights.qty_lights))
                    objsFileC.write("     %i, %i, %i,\n" %(int(matLightStruct[0][0]*255),int(matLightStruct[0][1]*255),int(matLightStruct[0][2]*255) ))

                    objsFileC.write("     %i, %i, %i,     %i, %i, %i" %(int(matLightStruct[1][0]*255),int(matLightStruct[1][1]*255),int(matLightStruct[1][2]*255),int(matLightStruct[1][3]*90),int(matLightStruct[1][4]*90),int(matLightStruct[1][5]*90) ))                        
                    if mat.mat_lights.qty_lights >=2:
                        objsFileC.write(",\n     %i, %i, %i,     %i, %i, %i" %(int(matLightStruct[2][0]*255),int(matLightStruct[2][1]*255),int(matLightStruct[2][2]*255),int(matLightStruct[2][3]*90),int(matLightStruct[2][4]*90),int(matLightStruct[2][5]*90) ))
                        if mat.mat_lights.qty_lights ==3:
                            objsFileC.write(",\n     %i, %i, %i,     %i, %i, %i"%(int(matLightStruct[3][0]*255),int(matLightStruct[3][1]*255),int(matLightStruct[3][2]*255),int(matLightStruct[3][3]*90),int(matLightStruct[3][4]*90),int(matLightStruct[3][5]*90) ))
                    objsFileC.write("\n   );\n")
                                
                    self.N64LightNames[self.N64LightCount] = mat.mat_lights.light_struct_name
                    self.N64LightNames.append([])
                    self.N64LightCount += 1   

class Header_Xport64(bpy.types.Operator):
    bl_idname = "poly.xport64"
    bl_label = "Xport64 - Polygon/Tri export"
    
    def exportDefs(self, hfile):
        #print("\n//cool .h file bro\n")        
        tempCount = 0
        #for command in self.definitionsFile:         
        while tempCount < self.commandCount:
            hfile.write("%s" % self.definitionsFile[tempCount])
            tempCount +=1


def roundtohalf(a): #rounds to nearest .5
    return round(a*2.0)/2.0
    
def roundtoquarter(a): #rounds to nearest .25
    return round(a*4.0)/4.0    
        
def isclose(a,b,rel_tol=1e-09, abs_tol = 0.0): #checks if numbers are approximately equal 
    return abs(a-b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)