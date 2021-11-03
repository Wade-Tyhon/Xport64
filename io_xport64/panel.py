bl_info = {
  "name": "panel",
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
 
#---------------------------------------------------------------------------------------------------------
#IN PROGRESS:
#WIP2       - In-Line GBI Commands 
#               - Add additional pre-built options for lit objects, effects, etc
#---------------------------------------------------------------------------------------------------------

#---------------------------------------------------------------------------------------------------------
#TO DO NOTES:
#           - Add secondary external display list call options to Material Properties window so that each material can have its own setup if needed
#           - 
#---------------------------------------------------------------------------------------------------------

#---------------------------------------------------------------------------------------------------------
#RECENT UPDATES:
#           - Create a dictionary to hold GBI commands to use for in-line command printing
#           - Allow user to call an external display list for 
#           - Add support for static and dynamic display lists
#           - 
#---------------------------------------------------------------------------------------------------------  
  
  
import bpy
import os

# class Properties_Xport64(bpy.types.PropertyGroup):
    # bl_label = "Xport64 Properties"
    # my_string = bpy.props.StringProperty(name = "Enter Text")
    # isStatic = bpy.props.StringProperty(name = "Enter Text")
    # #my_float = bpy.props.FloatProperty(name = "Enter a Float", soft_min = 0, soft_max = 10)

    # my_float = bpy.props.FloatProperty(name = "Enter a Float", min = 0, max = 10)

    # my_enum = bpy.props.EnumProperty(
        # name = "Choose One",
        # description = "choose this cuz u need to",
        # items = [('OPTION1', "This is Option1", ""),
                # ('OPTION2', "This is Option2", ""),
                # ('OPTION3', "This is Option3", ""),
        # ]
    # )
    
    
    
class LightProp_Xport64(bpy.types.PropertyGroup):  
    bl_label = "Xport64 N64 Light Structure"
    
    custom_lights = bpy.props.BoolProperty(name = "Custom Light",  default = False  )
    qty_lights = bpy.props.IntProperty(name = "Number of Lights", min = 1, max = 3, default = 1)
    
    light_struct_name = bpy.props.StringProperty(name = "Light Structure Name", default = "debugLightStruct")
    amb_light = bpy.props.FloatVectorProperty(name = "Ambient Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.002,0.292,0.030))
    dir_lights = bpy.props.FloatVectorProperty(name = "Light 1 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.0,0.012,0.397))
    light_dir = bpy.props.FloatVectorProperty(name = "Light 1 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    dir_lights2 = bpy.props.FloatVectorProperty(name = "Light 2 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.991,0.014,0.0))
    light_dir2 = bpy.props.FloatVectorProperty(name = "Light 2 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    dir_lights3 = bpy.props.FloatVectorProperty(name = "Light 3 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (1.0,0.527,0.0))
    light_dir3 = bpy.props.FloatVectorProperty(name = "Light 3 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    
class SceneProp_Xport64(bpy.types.PropertyGroup):
    bl_label = "Xport64 Scene Properties"
    current_scene_id = bpy.props.StringProperty(name = "Scene ID", default = "scn00")
    create_header_file = bpy.props.BoolProperty(name = "Create a Scene Header File",  default = False  )
    scene_header_id = bpy.props.StringProperty(name = "Header ID", default = "scn00")
        
    custom_scene_includes = bpy.props.BoolProperty(name = "Print #Includes",  default = False  )
    scene_Includes0 = bpy.props.StringProperty(name = "Scene Includes 0", default = "")
    scene_Includes1 = bpy.props.StringProperty(name = "Scene Includes 1", default = "xport64.h")
    scene_Includes2 = bpy.props.StringProperty(name = "Scene Includes 2", default = "")
    scene_Includes3 = bpy.props.StringProperty(name = "Scene Includes 3", default = "")
    scene_Includes4 = bpy.props.StringProperty(name = "Scene Includes 4", default = "")
    scene_Includes5 = bpy.props.StringProperty(name = "Scene Includes 5", default = "")
    scene_Includes6 = bpy.props.StringProperty(name = "Scene Includes 6", default = "")
    scene_Includes7 = bpy.props.StringProperty(name = "Scene Includes 7", default = "")
    scene_Includes8 = bpy.props.StringProperty(name = "Scene Includes 8", default = "")
    scene_Includes9 = bpy.props.StringProperty(name = "Scene Includes 9", default = "")
    scene_Includes10 = bpy.props.StringProperty(name = "Scene Includes 10", default = "")
    
class MaterialProp_Xport64(bpy.types.PropertyGroup):

    name = bpy.props.StringProperty(
        name = "Name",
        description="Test...",
        default="Default Test..."
    )

    custom_commands = bpy.props.BoolProperty(name = "Custom GBI Commands",  default = False  )
    #image_name = "No Image"
    mat_image_name = bpy.props.StringProperty(name = "Image Name", default = "No Image")
    
#START---------------------------------Pre-built macros and settings------------------------------------------------>
    prebuilt_commands = bpy.props.EnumProperty(
        name = "Pre-Built Commands",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('TEXTURE_4B', "TEXTURE_4B - Standard 4B Color Index(CI) Texture w/ TLUT.", "For use with standard textured surfaces using Vertex Colors or Vertex Lighting.", 1),
                ('ALPHA_TEXTURE_4B', "ALPHA_TEXTURE_4B - 4B CI Texture w/ TLUT and PrimColor alpha.", "For use with textured surfaces with alpha set by PrimColor", 2),
                ('TEXTURE_16B_RGBA_LIT', "TEXTURE_16B_RGBA_LIT - 16b RGBA Texture w/ lighting.", "For use with textured surfaces with Vertex colors or real time lighting.", 3),
                ('TEXTURE_16B_RGBA_UNLIT', "TEXTURE_16B_RGBA_UNLIT - 16b RGBA Texture 'Emissive' object with no lighting.", "For use with textured surfaces with Vertex colors or real time lighting.", 4),                    
                ('PRIM_COLORS_SHADED', "PRIM_COLORS_SHADED - Color determined primitive color and shaded.", "For use with un-textured meshes using primitive colors", 5),
                ('PRIM_COLORS_UNLIT', "PRIM_COLORS_UNLIT - Color determined by primitive color.", "For use with un-textured, unlit meshes", 6),
                ('TEX_4B_I_EFFECT', "TEX_4B_I_EFFECT - Intensity texture for effects such as shadows.", "For use with intensity effects such as decal shadows", 7),                      
                ('TEX_4B_CI_LIQUID', "TEX_4B_CI_LIQUID - 4B CI Texture for liquid surfaces.", "For use with liquid surfaces that use a texture", 8),      
                ('TEX_4B_CI_LIGHTSHAFT', "TEX_4B_CI_LIGHTSHAFT - 4B CI Texture w/ alpha for light rays.", "For use with light shafts/rays or other glowing objects", 9), 
                ('TEXTURE_4B_EDGE', "TEXTURE_4B_EDGE - 4B CI Texture w/ 1 bit alpha.", "For use with decal textures and 2D elements", 10), 
                ]
    )
        
    custom_tlut_name = bpy.props.BoolProperty(name = "Custom TLUT Name",  default = False  )

    texture_name = bpy.props.StringProperty(
        name = "Texture",
        description="Material texture name",
        default="Texture_Name"
    )
    

    
    texture_tlut_name = bpy.props.StringProperty(
        name = "TLUT",
        description="4bit texture color palette name",
        default="*_tlut"
    )
    
    
    prim_color = bpy.props.FloatVectorProperty(name = "Material - Primitive Color", subtype = "COLOR", size = 4, min = 0.0, max = 1.0, default = (0.938,0.0,1.0,1.0))
    env_color = bpy.props.FloatVectorProperty(name = "Scene - Environment Color", subtype = "COLOR", size = 4, min = 0.0, max = 1.0, default = (0.0,0.174,0.292,1.0))
    
    custom_mat_lights = bpy.props.BoolProperty(name = "Custom Material Light",  default = False  )
    qty_mat_lights = bpy.props.IntProperty(name = "Number of Lights", min = 1, max = 3, default = 1)
    
    mat_light_struct_name = bpy.props.StringProperty(name = "Light Structure Name", default = "debugLightStruct")
    mat_amb_light = bpy.props.FloatVectorProperty(name = "Ambient Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.002,0.292,0.030))
    mat_dir_lights = bpy.props.FloatVectorProperty(name = "Light 1 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.0,0.012,0.397))
    light_dir = bpy.props.FloatVectorProperty(name = "Light 1 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    mat_dir_lights2 = bpy.props.FloatVectorProperty(name = "Light 2 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.991,0.014,0.0))
    light_dir2 = bpy.props.FloatVectorProperty(name = "Light 2 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    mat_dir_lights3 = bpy.props.FloatVectorProperty(name = "Light 3 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (1.0,0.527,0.0))
    light_dir3 = bpy.props.FloatVectorProperty(name = "Light 3 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    
#NOTE: By default, Xport64 will use the image file's resolution for texture commands. But this can be overridden using custom_tex_res.
    custom_tex_res = bpy.props.BoolProperty(name = "Override Texture Resolution", default = False)
    
    texture_res_w = bpy.props.IntProperty(
        name = "Texture Width",
        description="Texture resolution (Width)",
        default=64
    )
   
    texture_res_h = bpy.props.IntProperty(
        name = "Texture Height",
        description="Texture resolution (Height)",
        default=64
    )
    
    filtering_commands = bpy.props.EnumProperty(
        name = "Texture Filtering",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('G_TF_AVERAGE', "Average - Suitable for most textures.", "", 1),
                ('G_TF_BILERP', "Bilinear Filtering - A 'higher quality' texture filter.", "", 2),                
                ('G_TF_POINT', "Point Sampling - No filter, better for sprite graphics.", "", 3),
                ]
    )
    
    wrap_commands_w = bpy.props.EnumProperty(
        name = "Wrap S (Horizontal)",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('G_TX_WRAP', "Wrap Texture - Repeat texture across the object outside the UV map.", "", 1),
                ('G_TX_CLAMP', "Clamp Texture - The edge texel repeats outside the UV map.", "", 2),                
                ('G_TX_MIRROR', "Mirror Texture - Repeats the current texture but mirrored.", "", 3),
                ]
    )
    
    wrap_commands_h = bpy.props.EnumProperty(
        name = "Wrap T (Vertical)",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('G_TX_WRAP', "Wrap Texture - Texture repeats outside the sample map.", "", 1),
                ('G_TX_CLAMP', "Clamp Texture - Edge texel repeats outside the sample map.", "", 2),                
                ('G_TX_MIRROR', "Mirror Texture - Texture repeats and is mirrored.", "Calculate lighting in real time, ideal for character models.", 3),
                ]
    )
    
    mask_commands_w = bpy.props.EnumProperty(
        name = "Mask S (Horizontal)",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('G_TX_NOMASK', "No Mask", "", 0),
                ('1', "1: 1<<1", "", 1),
                ('2', "2: 1<<2", "", 2),
                ('3', "3: 1<<3", "", 3),                
                ('4', "4: 1<<4", "", 4),
                ('5', "5: 1<<5", "", 5),                
                ('6', "6: 1<<6", "", 6),
                ('7', "7: 1<<7", "", 7),
                ('8', "8: 1<<8", "", 8),
                ('9', "9: 1<<9", "", 9),                
                ('10', "10: 1<<10", "", 10),
                ('11', "11: 1<<11", "", 11),
                ('12', "12: 1<<12", "", 12),
                ('13', "13: 1<<13", "", 13),                
                ('14', "14: 1<<14", "", 14),
                ('15', "15: 1<<15", "", 15),
                ]
    )
    
    mask_commands_h = bpy.props.EnumProperty(
        name = "Mask T (Vertical)",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('G_TX_NOMASK', "No Mask", "", 0),
                ('1', "1: 1<<1", "", 1),
                ('2', "2: 1<<2", "", 2),
                ('3', "3: 1<<3", "", 3),                
                ('4', "4: 1<<4", "", 4),
                ('5', "5: 1<<5", "", 5),                
                ('6', "6: 1<<6", "", 6),
                ('7', "7: 1<<7", "", 7),
                ('8', "8: 1<<8", "", 8),
                ('9', "9: 1<<9", "", 9),                
                ('10', "10: 1<<10", "", 10),
                ('11', "11: 1<<11", "", 11),
                ('12', "12: 1<<12", "", 12),
                ('13', "13: 1<<13", "", 13),                
                ('14', "14: 1<<14", "", 14),
                ('15', "15: 1<<15", "", 15),
                ]
    )
    
    shift_commands_w = bpy.props.EnumProperty(
        name = "Shift S (Horizontal)",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('G_TX_NOLOD', "No level of detail shift", "", 0),
                ('1', "1: 1>>1", "", 1),
                ('2', "2: 1>>2", "", 2),
                ('3', "3: 1>>3", "", 3),                
                ('4', "4: 1>>4", "", 4),
                ('5', "5: 1>>5", "", 5),                
                ('6', "6: 1>>6", "", 6),
                ('7', "7: 1>>7", "", 7),
                ('8', "8: 1>>8", "", 8),
                ('9', "9: 1>>9", "", 9),                
                ('10', "10: 1>>10", "", 10),
                ('11', "11: 1<<5", "", 11),
                ('12', "12: 1<<4", "", 12),
                ('13', "13: 1<<3", "", 13),                
                ('14', "14: 1<<2", "", 14),
                ('15', "15: 1<<1", "", 15),
                ]
    )
    
    shift_commands_h = bpy.props.EnumProperty(
        name = "Shift T (Vertical)",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('G_TX_NOLOD', "No level of detail shift", "", 0),
                ('1', "1: 1>>1", "", 1),
                ('2', "2: 1>>2", "", 2),
                ('3', "3: 1>>3", "", 3),                
                ('4', "4: 1>>4", "", 4),
                ('5', "5: 1>>5", "", 5),                
                ('6', "6: 1>>6", "", 6),
                ('7', "7: 1>>7", "", 7),
                ('8', "8: 1>>8", "", 8),
                ('9', "9: 1>>9", "", 9),                
                ('10', "10: 1>>10", "", 10),
                ('11', "11: 1<<5", "", 11),
                ('12', "12: 1<<4", "", 12),
                ('13', "13: 1<<3", "", 13),                
                ('14', "14: 1<<2", "", 14),
                ('15', "15: 1<<1", "", 15),
                ]
    )
    

#END-----------------------------------Pre-built macros and settings------------------------------------------------<
    
    
    
    
    shading_commands = bpy.props.EnumProperty(
        name = "Shading Commands",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('VTX COLORS', "VTX Colors - Light static objects your scene.", "Manually set VTX colors in vertex paint for more detailed and control.", 1),
                ('VTX LIGHTING', "VTX Lighting - Objects that need to be lit in real time.", "Calculate lighting in real time, ideal for character models.", 2),
                ('UNLIT', "UNLIT - Color determined by texture or primitive color.", "Color and brightness is determined by texture or primitive color.", 3),                
                ]
    )
    
    texture_commands = bpy.props.EnumProperty(
        name = "Texture Commands",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('OPAQUE TEXTURE', "Opaque Texture - Light does not pass through object.", "Manually set VTX colors in vertex paint for more detailed and control.", 1),
                ('DECAL TEXTURE', "Decal / Cut-Out - Single bit of transparency, visibility is on or off.", "Color and brightness is determined by texture or primitive color.", 2),                
                ('TRANSPARENT TEXTURE', "Transparent Texture - Texel alpha determines object's transparency.", "Calculate lighting in real time, ideal for character models.", 3),
                ('NONE', "No texture, use primitive color.", "Calculate lighting in real time, ideal for character models.", 4),
                ]
    )
    
    primitive_commands = bpy.props.EnumProperty(
        name = "Texture Commands",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('PRIMITIVE COLOR W ALPHA', "Primitive Color - Color and alpha settings.", "Manually set VTX colors in vertex paint for more detailed and control.", 1),
                ('PRIMITIVE ALPHA ONLY', "Primitive Alpha - Only use primitive alpha settings.", "Color and brightness is determined by texture or primitive color.", 2),                
                ('ENVIRONMENT COLOR', "Transparent Texture - Texel alpha determines object's transparency.", "Calculate lighting in real time, ideal for character models.", 3),
                ('ENVIRONMENT COLOR W ALPHA', "Transparent Texture - Texel alpha determines object's transparency.", "Calculate lighting in real time, ideal for character models.", 3),
                ]
    )
    
class ObjectProp_Xport64(bpy.types.PropertyGroup):
    bl_label = "Xport64 Object Properties"
    object_id = bpy.props.StringProperty(name = "object00")
    static_DL = bpy.props.BoolProperty(name = "Static Display List",  default = False  )
    debug_DL = bpy.props.BoolProperty(name = "Print Debug / Warning Comments",  default = False  )
    guide_DL = bpy.props.BoolProperty(name = "Print Tip / Suggestion Comments",  default = False  )

#START<------------------------------------------------- GBI/Material settings ----------------------------------------------------------------------    
    gbi_com_settings = bpy.props.BoolProperty(name = "Export GBI/Material Commands",  default = True  )
    gbi_com_textures = bpy.props.BoolProperty(name = "Export Modify Vertex Commands",  default = True  )
    gbi_prim_color = bpy.props.BoolProperty(name = "Export Primitive Color",  default = True  )
    gbi_env_color = bpy.props.BoolProperty(name = "Export Environment Color",  default = False  )
    
    gbi_com_settings_method = bpy.props.EnumProperty(
        name = "GBI Command Printing",
        description = "Choose the method for printing graphics commands.\n If none is chosen, then a comment will be printed where new material settings would go.",
        items = [
                ('IN LINE', "In-Line Commands", "", 1),
                ('DL GENERATE', "Generate Display List", "", 2),
                ('DL CALL', "Existing Display List", "", 3),
                ]
    )    
    
    gbi_com_existing_DL = bpy.props.StringProperty(name = "Existing Display List", default = "externDisplayList")
#START------------------------------------------------- GBI/Material settings --------------------------------------------------------------------->        
    
    set_dl_name = bpy.props.StringProperty(name = "Display List Pointer", default = "glistp")
    sort_Method = bpy.props.EnumProperty(
        name = "VTX Export Method",
        description = "Choose the method for vertex sorting and texture.",
        items = [
                ('VTX COLOR', "VTX Colors-Static Object", "", 1),
                ('VTX LIGHTING', "VTX Normals-Vertex Lit Object", "", 2),                
                ('COLLISION', "Collision Mesh", "", 3),          
                ]
    )    
    anim_Method = bpy.props.EnumProperty(
        name = "Animation Method",
        description = "Export your model to a series of vertex display lists frames or the object's rotation/position per frame.",
        items = [
                ("NO ANIM", "No Animation Frames", "", 1),
                ("VTX DL", "Weighted - VTX Display Lists", "", 2),
                ("OBJ VARIABLES", "Object - Rot, Pos, and Scl", "", 3),          
                ]
    )
    
    rig_Template = bpy.props.BoolProperty(name = "Include Rig Template",  default = False  )
    rig_Template_Name = bpy.props.StringProperty(name = "object00")

    
    #texture_list = bpy.props.StringProperty(name = "Name") #for storing textureNames
    
    
class PolyProp_Xport64(bpy.types.PropertyGroup):
    bl_label = "Xport64 Polygon Properties"
    

class Scene_Xport64(bpy.types.Panel):
    bl_label = "Xport64 Scene Settings"
    bl_idname = "PT_TestPanel"
    bl_space_type = 'VIEW_3D'
    bl_region_type = 'UI'
    bl_category = 'NewTab'

    def draw(self, context):
        layout = self.layout
        scene = context.scene
        sceneprops = scene.scene_props
        scenelights = scene.scene_lights
        obj = context.object
        
        row = layout.row()
        row.label(text = "Set N64 Scene Data", icon= 'IMAGE_DATA')
        
        row = layout.row()
        row.prop(sceneprops, "current_scene_id")
        
        
#   **********************************************************************************************************************************************
#   ************************************************************ Custom Header File **************************************************************
#   ********************************************************************************************************************************************** 
        row = layout.row()        
        row.prop(sceneprops, "create_header_file")

        if sceneprops.create_header_file == True:
            row.label(text = "ENABLED: Definitions/Declarations to .h File")
            row = layout.row()
            row.prop(sceneprops, "scene_header_id")
            row = layout.row()
        else:
            row.label(text = "DISABLED: Don't Create a .h File")
            row = layout.row()
            row.prop(sceneprops, "scene_header_id")
            row.active = False            
            
#   **********************************************************************************************************************************************
#   ******************************************************** Print #includes in C file ***********************************************************
#   **********************************************************************************************************************************************     
        
        row = layout.row()
        row.prop(sceneprops, "custom_scene_includes")
        #row = layout.row()              
        
        if sceneprops.custom_scene_includes == True:
            #row.label(text = "Object Export Properties", icon= 'IMAGE_DATA')
            row.label(text = "ENABLED: Print .h Includes")
            row = layout.row()            
            row.prop(sceneprops, "scene_Includes1")
            row = layout.row()
            
            if sceneprops.scene_Includes1 != None and sceneprops.scene_Includes1 != "":
                row.prop(sceneprops, "scene_Includes2")
                row = layout.row()
            if sceneprops.scene_Includes2 != None and sceneprops.scene_Includes2 != "":
                row.prop(sceneprops, "scene_Includes3")
                row = layout.row()                    
            if sceneprops.scene_Includes3 != None and sceneprops.scene_Includes3 != "":
                row.prop(sceneprops, "scene_Includes4")
                row = layout.row()
            if sceneprops.scene_Includes4 != None and sceneprops.scene_Includes4 != "":
                row.prop(sceneprops, "scene_Includes5")
                row = layout.row()
            if sceneprops.scene_Includes5 != None and sceneprops.scene_Includes5 != "":
                row.prop(sceneprops, "scene_Includes6")
                row = layout.row()
            if sceneprops.scene_Includes6 != None and sceneprops.scene_Includes6 != "":
                row.prop(sceneprops, "scene_Includes7")
                row = layout.row()
            if sceneprops.scene_Includes7 != None and sceneprops.scene_Includes7 != "":
                row.prop(sceneprops, "scene_Includes8")
                row = layout.row()                    
            if sceneprops.scene_Includes8 != None and sceneprops.scene_Includes8 != "":
                row.prop(sceneprops, "scene_Includes9")
                row = layout.row()
            if sceneprops.scene_Includes9 != None and sceneprops.scene_Includes9 != "":
                row.prop(sceneprops, "scene_Includes10")
                row = layout.row()
                    
        elif sceneprops.custom_scene_includes == False:
            #row.label(text = "Object Export Properties", icon= 'IMAGE_DATA')     
            row.label(text = "DISABLED: Do not print .h includes")
            row = layout.row()
            row.prop(sceneprops, "scene_Includes1")           
            row.active = False
        
#   **********************************************************************************************************************************************
#   ********************************************************* Set Up Default Scene Lights ********************************************************
#   **********************************************************************************************************************************************         
        
        renderBox = layout.box()            
        row = renderBox.row()
        renderBox.label(text = "Scene Lights: Set the default scene lights.")
        
        row = renderBox.row()     
        row.prop(scenelights, "custom_lights")        
        
        if scenelights.custom_lights == True:
            row.prop(scenelights, "qty_lights")
        else:
            row.label(text = "DISABLED: Will not export custom scene light structures.")        
        
        if scenelights.custom_lights == True and scenelights.qty_lights > 0:
           
            if scenelights.qty_lights >= 1:
                row = renderBox.row()     
                row.prop(scenelights, "light_struct_name")
                row = renderBox.row()                            
                row.prop(scenelights, "amb_light")     
                
                split = renderBox.split()
                col = split.column()                            
                col.prop(scenelights, "dir_lights")
                col.prop(scenelights, "light_dir")
                row = col.row()
                row.label(text = "Color: R. %i  G. %i, B. %i" % (scenelights.dir_lights[0]*255, scenelights.dir_lights[1]*255,scenelights.dir_lights[2]*255))
                row = col.row()
                row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (scenelights.light_dir[0]*90, scenelights.light_dir[2]*90, scenelights.light_dir[1]*90))
                
                if scenelights.qty_lights >= 2:                      
                    col = split.column()    
                    col.prop(scenelights, "dir_lights2")
                    col.prop(scenelights, "light_dir2")   
                    row = col.row()
                    row.label(text = "Color: R. %i  G. %i, B. %i" % (scenelights.dir_lights2[0]*255, scenelights.dir_lights2[1]*255,scenelights.dir_lights2[2]*255))
                    row = col.row()
                    row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (scenelights.light_dir2[0]*90, scenelights.light_dir2[2]*90, scenelights.light_dir2[1]*90))                               
                    
                    if scenelights.qty_lights == 3:                      
                        col = split.column()    
                        col.prop(scenelights, "dir_lights3")
                        col.prop(scenelights, "light_dir3")
                        row = col.row()
                        row.label(text = "Color: R. %i  G. %i, B. %i" % (scenelights.dir_lights3[0]*255, scenelights.dir_lights3[1]*255,scenelights.dir_lights3[2]*255))
                        row = col.row()
                        row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (scenelights.light_dir3[0]*90, scenelights.light_dir3[2]*90, scenelights.light_dir3[1]*90))
            
        elif scenelights.custom_mat_lights == False or scenelights.qty_lights == 0:
            row = renderBox.row()     
            row.prop(scenelights, "light_struct_name")
            row.enabled = False
            row = renderBox.row()  
            row.prop(scenelights, "amb_light")
            row.enabled = False
            row = renderBox.row()
            row.prop(scenelights, "dir_lights")
            row.enabled = False        

        row = layout.row()
        
        
class Object_Xport64(bpy.types.Panel):
    bl_label = "Xport64 Object Settings"
    bl_idname = "PT_PanelA"
    bl_space_type = 'VIEW_3D'
    bl_region_type = 'UI'
    bl_category = 'NewTab'
    #  bl_parent_id = 'PT_TestPanel'

    def draw(self, context):
        layout = self.layout
        obj = context.object
        #objmat = obj.data.uv_textures["UVMap"].data[0].image.name
        
        #if 'obj_props' in obj:
        objprops = obj.obj_props
        objlights = obj.obj_lights
        

        row = layout.row()                  
        col = layout.column()
        
        
        renderBox = layout.box()
        row = renderBox.row() 
        row.label(text = "Xport64 Helper Functions", icon= 'IMAGE_DATA')
        row = renderBox.row()        
        row.prop(objprops, "debug_DL")
        row.prop(objprops, "guide_DL")
        
        layout.separator()#----------------------------------------------
        renderBox = layout.box()
        row = renderBox.row() 
        row.label(text = "Xport64 Object Export Settings", icon= 'IMAGE_DATA')   
        

        row.separator()#----------------------------------------------
        row = renderBox.row()
        row.prop(objprops, "static_DL")     
        if objprops.static_DL == False:
            #row.label(text = "Object Export Properties", icon= 'IMAGE_DATA')
            row.label(text = "DYNAMIC: Type Display List Pointer Below")
            row = renderBox.row()            
            row.prop(objprops, "set_dl_name")
            row = renderBox.row()
        elif objprops.static_DL == True:
            #row.label(text = "Object Export Properties", icon= 'IMAGE_DATA')     
            row.label(text = "STATIC: No Pointer Needed")
            row = renderBox.row()
            row.prop(objprops, "set_dl_name")            
            row.active = False

        
        row.separator()#----------------------------------------------
        row = renderBox.row() 
        #row.label(text = "Object Export Settings", icon= 'IMAGE_DATA')
        row = renderBox.row()        
        row.prop(objprops, "gbi_com_settings")

        #row.label(text = "gfx_settings_method", icon= 'IMAGE_DATA') 
        if objprops.gbi_com_settings == True:           
            row.label(text = "ENABLED: Choose Method for GBI Commands")
            row = renderBox.row() 
            row.prop(objprops, "gbi_com_settings_method")
            row = renderBox.row()
            
            if objprops.gbi_com_settings_method == "DL CALL":            
                row = renderBox.row()
                row.prop(objprops, "gbi_com_existing_DL")
            else:            
                row = renderBox.row()
                row.prop(objprops, "gbi_com_existing_DL")
                row.active = False           
            # row.separator()#----------------------------------------------
            # row = renderBox.row()            
            # row.prop(objprops, "gbi_com_textures")
            # row = renderBox.row()
            # row.prop(objprops, "gbi_prim_color")
            # row.prop(objprops, "gbi_env_color")
            
        elif objprops.gbi_com_settings == False:            
            row.label(text = "DISABLED: In-Line Comment Only")
            row = renderBox.row()            
            row.prop(objprops, "gbi_com_settings_method")            
            row.active = False
            
            # row.separator()#----------------------------------------------
            # row = renderBox.row()            
            # row.prop(objprops, "gbi_com_textures")
            # row.active = False
            # row = renderBox.row()
            # row.prop(objprops, "gbi_prim_color")
            # row.prop(objprops, "gbi_env_color")
            # row.active = False
            
        row.separator()#----------------------------------------------
        row = renderBox.row()            
        row.prop(objprops, "gbi_com_textures")
        row = renderBox.row()
        row.prop(objprops, "gbi_prim_color")
        row.prop(objprops, "gbi_env_color")
                
        row = renderBox.row() 
        #row.separator()#----------------------------------------------
        row.label(text = "______________________________________________________________________________________________________________________________________")            
      
        row.separator()#----------------------------------------------
        row = renderBox.row()
        row.label(text = "Xport64 Object Export Type", icon= 'IMAGE_DATA')        
        renderBox.prop(objprops, "sort_Method")         
        row = renderBox.row()
        
        row.label(text = "______________________________________________________________________________________________________________________________________")
        
        row.separator()#----------------------------------------------

        row = renderBox.row()
        row.label(text = "Xport64 Animation Method", icon= 'IMAGE_DATA')        
        renderBox.prop(objprops, "anim_Method")
        row = renderBox.row()                   
        
        row.label(text = "______________________________________________________________________________________________________________________________________")
        row.separator()#----------------------------------------------
        
        #   **********************************************************************************************************************************************
#   ********************************************************* Set Up Default Object Lights ********************************************************
#   **********************************************************************************************************************************************         
        
        renderBox = layout.box()            
        row = renderBox.row()
        renderBox.label(text = "Object Lights: If used, will override scene lights.")
        
        row = renderBox.row()     
        row.prop(objlights, "custom_lights")        
        
        if objlights.custom_lights == True:
            row.prop(objlights, "qty_lights")
        else:
            row.label(text = "DISABLED: Will not export light structures for this object.")        
        
        if objlights.custom_lights == True and objlights.qty_lights > 0:
           
            if objlights.qty_lights >= 1:
                row = renderBox.row()     
                row.prop(objlights, "light_struct_name")
                row = renderBox.row()                            
                row.prop(objlights, "amb_light")     
                
                split = renderBox.split()
                col = split.column()                            
                col.prop(objlights, "dir_lights")
                col.prop(objlights, "light_dir")
                row = col.row()
                row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.dir_lights[0]*255, objlights.dir_lights[1]*255,objlights.dir_lights[2]*255))
                row = col.row()
                row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (objlights.light_dir[0]*90, objlights.light_dir[2]*90, objlights.light_dir[1]*90))
                
                if objlights.qty_lights >= 2:                      
                    col = split.column()    
                    col.prop(objlights, "dir_lights2")
                    col.prop(objlights, "light_dir2")   
                    row = col.row()
                    row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.dir_lights2[0]*255, objlights.dir_lights2[1]*255,objlights.dir_lights2[2]*255))
                    row = col.row()
                    row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (objlights.light_dir2[0]*90, objlights.light_dir2[2]*90, objlights.light_dir2[1]*90))                               
                    
                    if objlights.qty_lights == 3:                      
                        col = split.column()    
                        col.prop(objlights, "dir_lights3")
                        col.prop(objlights, "light_dir3")
                        row = col.row()
                        row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.dir_lights3[0]*255, objlights.dir_lights3[1]*255,objlights.dir_lights3[2]*255))
                        row = col.row()
                        row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (objlights.light_dir3[0]*90, objlights.light_dir3[2]*90, objlights.light_dir3[1]*90))
            
        elif objlights.custom_lights == False or objlights.qty_lights == 0:
            row = renderBox.row()     
            row.prop(objlights, "light_struct_name")
            row.enabled = False
            row = renderBox.row()  
            row.prop(objlights, "amb_light")
            row.enabled = False
            row = renderBox.row()
            row.prop(objlights, "dir_lights")
            row.enabled = False

            
class Setup_Xport64(bpy.types.Operator):
    bl_label = "Let's-a-go!"
    bl_idname = "object.setup_xport64"
    
    
    #debug_Textures = "/assets/DebugTexture_Orange.png"
    
    def execute(self, context):
        bpy.context.scene.render.engine = 'CYCLES'
        bpy.context.object.active_material.use_nodes = True
        #nodeTree = bpy.context.scene.node_tree
        #debug_Texture_Path = ["C:\Program Files\Blender Foundation\Blender\2.70\scripts\addons\io_Xport64\assets\DebugTexture_Orange.png","\assets\DebugTexture_Blue.png"] 
        
        #if Path(debug_Texture_Path).is_file()
        #texture = bpy.data.images.load(debug_Texture_Path[0])
        #image_comp_node = nodeTree.nodes.new(type='CompositorNodeImage')
        
        #if image_comp_node:
        #    img_comp_node.image = texture
        
        return {'FINISHED'}
        
            
class Object_Tabs_Xport64(bpy.types.Panel):            
        
    bl_label = "Xport64 Texture Settings"
    bl_idname = "PT_Texture"
    #bl_space_type = 'IMAGE_EDITOR'
    bl_space_type = 'PROPERTIES'
    bl_region_type = 'WINDOW'
    bl_category = 'object'            

    def draw(self, context):
        layout = self.layout
        obj = context.object
        row = layout.row()    
        col = layout.column()
        scene = context.scene
        
        # Because Python and blender are stupid, check to make sure that a Material is attached 
        # and Nodes are enabled to avoid a NoneType error
        
        if obj != None:
        
            checkForMaterial = getattr(obj, "active_material", False)        
            
            if checkForMaterial != None: #Make sure object has a material assigned
                activeMat = obj.active_material
                print(checkForMaterial)            
                
                checkForNodes = getattr(activeMat, "node_tree", False)            
                if checkForNodes != None: # make sure object has nodes enabled
                    print(checkForNodes)

                if checkForNodes == None:
                    row.label(text = "To use Xport64 on this object, you must:")                    
                    row = layout.row()
                    row.label(text = "  [OK] Have at least one Mesh object in your scene.")
                    row.active = False
                    row = layout.row()                                        
                    row.label(text = "  [OK] Assign at least one object material.")
                    row.active = False
                    row = layout.row()                    
                    row.label(text = "  - Enable Cycles Mode.")
                    row = layout.row()   
                    row.label(text = "  - Enable nodes on this object.")    
                    row.operator('object.setup_Xport64')
            
            else:
                checkForNodes = None
                row.label(text = "To use Xport64 on this object, you must:")
                row = layout.row()
                row.label(text = "  [OK] Have at least one Mesh object in your scene.")
                row.active = False
                row = layout.row()                
                row.label(text = "  - Assign at least one object material.")
                row = layout.row() 
                row.label(text = "  - Enable Cycles Mode.")
                row = layout.row()   
                row.label(text = "  - Enable nodes on this object.")                
                row = layout.row()                       
           
            if checkForNodes != None:
                if 'Material Output' in activeMat.node_tree.nodes:        
                    matProps = activeMat.mat_props
                    prim_color = activeMat.diffuse_color
                    matlights = obj.active_material.mat_lights

                    
                    if 'Image Texture' in activeMat.node_tree.nodes:
                        image_name = activeMat.node_tree.nodes["Image Texture"].image
                    
                        if image_name != None:                
                            image_name = activeMat.node_tree.nodes["Image Texture"].image.name
                            removeExtension = os.path.splitext(image_name) #This removes the extension (.png, .bmp etc) from a file name (if there is one)
                            image_name = removeExtension[0]
                            print("Testing image_name: %s " % image_name)
                        else:
                            image_name = 'NO_IMAGE'
                        
                    else: 
                        image_name = 'NO_IMAGE'
                    
#   **********************************************************************************************************************************************
# 1 ************************************************************ GBI Command Settings ************************************************************
#   **********************************************************************************************************************************************  
                    
                    #layout.separator()#----------------------------------------------
                    renderBox = layout.box()
                    row = renderBox.row()
                    row.label(text = "Xport64 Material/Lighting GBI Commands", icon= 'IMAGE_DATA')
                    
                    #row = layout.row()
                    row = renderBox.row()            
                    row.prop(matProps, "custom_commands")
                    row.enabled = False
                    
                    
                    if matProps.custom_commands == False:  
                        row.label(text = "Use Pre-Built GBI Commands")
                        renderBox.prop(matProps, "prebuilt_commands")
                        row = renderBox.row()        
                        
                    else:    
                        row.label(text = "Generate Custom GBI Commands")
                        #row.label(text = "Xport64 CUSTOM Material/Lighting GBI Commands", icon= 'IMAGE_DATA')        
                        renderBox.prop(matProps, "shading_commands")
                        row = renderBox.row()
                        
                        layout.separator()#----------------------------------------------
                        row = renderBox.row()
                        renderBox.prop(matProps, "texture_commands")
                        row = renderBox.row()
                    
#   **********************************************************************************************************************************************
# 1 ************************************************************** Texture Settings **************************************************************
#   **********************************************************************************************************************************************                    
                    renderBox = layout.box()
                    row = renderBox.row()
                    row.label(text = "Xport64 Texture Settings", icon= 'IMAGE_DATA')
                    row = renderBox.row()
                    
                    

                    layout.separator()#----------------------------------------------
                    row.label(text = "Texture Name: %s" % image_name)
                    #row.prop(matProps, "texture_name")
                    row = renderBox.row()
                    #if 'open' in activeMat.node_tree.nodes["Image Texture"]:
                    #row.prop(activeMat.node_tree.nodes["Image Texture"], "open")
                 
                    layout.separator()#----------------------------------------------
                    
                    row.prop(matProps, "custom_tex_res")
                    
                    if matProps.custom_tex_res == True:                    
                        row.label("WARNING - Can break tiling or lock up.")
                        row = renderBox.row()
                        row.prop(matProps, "texture_res_w")
                        row.prop(matProps, "texture_res_h")
                        row = renderBox.row()            
                    else:
                        row = renderBox.row()     
                        row.prop(matProps, "texture_res_w")
                        row.prop(matProps, "texture_res_h")
                        row.active = False
                        row = renderBox.row()
                        
                    #row.label(text = "_____________________________________________________________________________________________________________________________________________")        
                    #renderBox.label(text = "Texture Display:")
                    row = renderBox.row()     
                    row.prop(matProps, "filtering_commands")  
                    row = renderBox.row()         
                    row.label(text = "_____________________________________________________________________________________________________________________________________________")    
                    
                    #renderBox.label(text = "Texture Display:")
                    row = renderBox.row()     
                    row.prop(matProps, "wrap_commands_w")  
                    row.prop(matProps, "wrap_commands_h")
                    row = renderBox.row()         
                    row.label(text = "_____________________________________________________________________________________________________________________________________________")    
                    
                    #renderBox.label(text = "Texture Mask:")
                    row = renderBox.row()     
                    row.prop(matProps, "mask_commands_w")  
                    row.prop(matProps, "mask_commands_h")
                    row = renderBox.row()
                    
                    row.label(text = "_____________________________________________________________________________________________________________________________________________")           
                    #renderBox.label(text = "Texture Mask:")
                    row = renderBox.row()     
                    row.prop(matProps, "shift_commands_w")  
                    row.prop(matProps, "shift_commands_h")
                    row = renderBox.row()
                    #row.label(text = "_____________________________________________________________________________________________________________________________________________")  
                    
                    
#   **********************************************************************************************************************************************
# 1 ********************************************************** Lights and Color Settings *********************************************************
#   **********************************************************************************************************************************************  
                 
                    renderBox = layout.box()            
                    row = renderBox.row()
                    row.label(text = "Xport64 CUSTOM Material/Lighting GBI Commands", icon= 'IMAGE_DATA')
                    row = renderBox.row()
                    row.prop(matProps, "custom_tlut_name")
                    
                    if matProps.custom_tlut_name == False:
                        row.label(text = "DEFAULT 4B CI TLUT Name")
                        row = renderBox.row()
                        row.label(text = "4b CI Palette (TLUT):")
                        row.label(text = "%s_tlut" %image_name)
                        row = renderBox.row()            
                    else:
                        row.label(text = "CUSTOM 4B CI TLUT Name")
                        row = renderBox.row()
                        row.label(text = "4b CI Palette (TLUT):")
                        row.prop(matProps, "texture_tlut_name")
                        row = renderBox.row()
                    
                    row.label(text = "_____________________________________________________________________________________________________________________________________________")  
                    renderBox.label(text = "Color: Set GBI internal color registers for blending.")
                    split = renderBox.split()
                    col = split.column()                     
                    col.prop(matProps, "prim_color")
                    #row = renderBox.row()   

                    #row.label(text = "_____________________________________________________________________________________________________________________________________________")  
                    col = split.column()      
                    col.prop(matProps, "env_color")
                    row = renderBox.row()         

                    
#   **********************************************************************************************************************************************
#   ******************************************************** Set Up Custom Material Lights *******************************************************
#   **********************************************************************************************************************************************         
        
                    renderBox = layout.box()            
                    row = renderBox.row()
                    renderBox.label(text = "Material Lights: If used, will override scene and object lights for this material.")
                    
                    row = renderBox.row()     
                    row.prop(matlights, "custom_lights")        
                    
                    if matlights.custom_lights == True:
                        row.prop(matlights, "qty_lights")
                    else:
                        row.label(text = "DISABLED: Will not export custom material light structures.")        
                    
                    if matlights.custom_lights == True and matlights.qty_lights > 0:
                       
                        if matlights.qty_lights >= 1:
                            row = renderBox.row()     
                            row.prop(matlights, "light_struct_name")
                            row = renderBox.row()                            
                            row.prop(matlights, "amb_light")     
                            
                            split = renderBox.split()
                            col = split.column()                            
                            col.prop(matlights, "dir_lights")
                            col.prop(matlights, "light_dir")
                            row = col.row()
                            row.label(text = "Color: R. %i  G. %i, B. %i" % (matlights.dir_lights[0]*255, matlights.dir_lights[1]*255,matlights.dir_lights[2]*255))
                            row = col.row()
                            row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matlights.light_dir[0]*90, matlights.light_dir[2]*90, matlights.light_dir[1]*90))
                            
                            if matlights.qty_lights >= 2:                      
                                col = split.column()    
                                col.prop(matlights, "dir_lights2")
                                col.prop(matlights, "light_dir2")   
                                row = col.row()
                                row.label(text = "Color: R. %i  G. %i, B. %i" % (matlights.dir_lights2[0]*255, matlights.dir_lights2[1]*255,matlights.dir_lights2[2]*255))
                                row = col.row()
                                row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matlights.light_dir2[0]*90, matlights.light_dir2[2]*90, matlights.light_dir2[1]*90))                               
                                
                                if matlights.qty_lights == 3:                      
                                    col = split.column()    
                                    col.prop(matlights, "dir_lights3")
                                    col.prop(matlights, "light_dir3")
                                    row = col.row()
                                    row.label(text = "Color: R. %i  G. %i, B. %i" % (matlights.dir_lights3[0]*255, matlights.dir_lights3[1]*255,matlights.dir_lights3[2]*255))
                                    row = col.row()
                                    row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matlights.light_dir3[0]*90, matlights.light_dir3[2]*90, matlights.light_dir3[1]*90))
                        
                    elif matlights.custom_mat_lights == False or matlights.qty_lights == 0:
                        row = renderBox.row()     
                        row.prop(matlights, "light_struct_name")
                        row.enabled = False
                        row = renderBox.row()  
                        row.prop(matlights, "amb_light")
                        row.enabled = False
                        row = renderBox.row()
                        row.prop(matlights, "dir_lights")
                        row.enabled = False   
                    
                    
                    # row.label(text = "_____________________________________________________________________________________________________________________________________________")  
                    # row = renderBox.row()     
                    # row.prop(matProps, "custom_mat_lights")
                    
                    
                    # if matProps.custom_mat_lights == True:
                        # row.prop(matProps, "qty_mat_lights")
                    # else:
                        # row.label(text = "DISABLED: Will not export custom light structures.")
                    
                    
                    # if matProps.custom_mat_lights == True and matProps.qty_mat_lights > 0:
                       
                        # if matProps.qty_mat_lights >= 1:
                            # row = renderBox.row()     
                            # row.prop(matProps, "mat_light_struct_name")
                            # row = renderBox.row()                            
                            # row.prop(matProps, "mat_amb_light")     
                            
                            # split = renderBox.split()
                            # col = split.column()                            
                            # col.prop(matProps, "mat_dir_lights")
                            # col.prop(matProps, "light_dir")
                            # row = col.row()
                            # row.label(text = "Color: R. %i  G. %i, B. %i" % (matProps.mat_dir_lights[0]*255, matProps.mat_dir_lights[1]*255,matProps.mat_dir_lights[2]*255))
                            # row = col.row()
                            # row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matProps.light_dir[0]*90, matProps.light_dir[2]*90, matProps.light_dir[1]*90))
                            
                            # if matProps.qty_mat_lights >= 2:                      
                                # col = split.column()    
                                # col.prop(matProps, "mat_dir_lights2")
                                # col.prop(matProps, "light_dir2")   
                                # row = col.row()
                                # row.label(text = "Color: R. %i  G. %i, B. %i" % (matProps.mat_dir_lights2[0]*255, matProps.mat_dir_lights2[1]*255,matProps.mat_dir_lights2[2]*255))
                                # row = col.row()
                                # row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matProps.light_dir2[0]*90, matProps.light_dir2[2]*90, matProps.light_dir2[1]*90))                               
                                
                                # if matProps.qty_mat_lights == 3:                      
                                    # col = split.column()    
                                    # col.prop(matProps, "mat_dir_lights3")
                                    # col.prop(matProps, "light_dir3")
                                    # row = col.row()
                                    # row.label(text = "Color: R. %i  G. %i, B. %i" % (matProps.mat_dir_lights3[0]*255, matProps.mat_dir_lights3[1]*255,matProps.mat_dir_lights3[2]*255))
                                    # row = col.row()
                                    # row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matProps.light_dir3[0]*90, matProps.light_dir3[2]*90, matProps.light_dir3[1]*90))
                        
                    # elif matProps.custom_mat_lights == False or matProps.qty_mat_lights == 0:
                        # row = renderBox.row()     
                        # row.prop(matProps, "mat_light_struct_name")
                        # row.enabled = False
                        # row = renderBox.row()  
                        # row.prop(matProps, "mat_amb_light")
                        # row.enabled = False
                        # row = renderBox.row()
                        # row.prop(matProps, "mat_dir_lights")
                        # row.enabled = False
                        
                    
                        # mat_amb_lights = bpy.props.FloatVectorProperty(name = "Ambient Color", subtype = "COLOR", size = 3, min = 0, max = 255, default = (255, 255, 255))
    # mat_dir_lights = bpy.props.FloatVectorProperty(name = "Directional Color", subtype = "COLOR", size = 3, min = 0, max = 255, default = (255, 255, 255))
    # mat_light_direction = bpy.props.IntVectorProperty(name = "Light Direction", size = 3, min = 0, max = 255, default = (255, 255, 255))                    
          
                             
                    

    
        else:            
            row.label(text = "To use Xport64 on this object, you must:")
            row = layout.row()
            row.label(text = "  - Have at least one Mesh object in your scene.")
            row = layout.row()              
            row.label(text = "  - Assign at least one object material.")
            row = layout.row() 
            row.label(text = "  - Enable Cycles Mode.")
            row = layout.row()   
            row.label(text = "  - Enable nodes on this object.")                         
            row = layout.row()