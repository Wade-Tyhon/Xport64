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

  
import bpy
import os
import string
    
class LightProp_Xport64(bpy.types.PropertyGroup):  
    bl_label = "Xport64 N64 Light Structure"
    
    expand = bpy.props.BoolProperty(name = "Expand Xport64 Light Settings",  default = False  )
    custom_lights = bpy.props.BoolProperty(name = "Export Light Structure",  default = False  )
    expand_diffuse = bpy.props.BoolProperty(name = "Expand Diffuse/Direction Light Settings",  default = True  )
    diffuse_lights = bpy.props.BoolProperty(name = "Export Diffuse/Direction Lights",  default = False  )
    manual_entry = bpy.props.BoolProperty(name = "Manually Enter Values",  default = False  )
    qty_lights = bpy.props.IntProperty(name = "Dir Lights Qty", min = 0, max = 3, default = 1)
        
    light_struct_name = bpy.props.StringProperty(name = "Light Structure Name", default = "debugLightStruct")
    amb_light = bpy.props.FloatVectorProperty(name = "Ambient Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.002,0.292,0.030))
    dir_lights = bpy.props.FloatVectorProperty(name = "Light 1 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.0,0.012,0.397))
    light_dir = bpy.props.FloatVectorProperty(name = "Light 1 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    dir_lights2 = bpy.props.FloatVectorProperty(name = "Light 2 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (0.991,0.014,0.0))
    light_dir2 = bpy.props.FloatVectorProperty(name = "Light 2 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    dir_lights3 = bpy.props.FloatVectorProperty(name = "Light 3 Color", subtype = "COLOR", size = 3, min = 0, max = 1.0, default = (1.0,0.527,0.0))
    light_dir3 = bpy.props.FloatVectorProperty(name = "Light 3 Angle", subtype = "DIRECTION", size = 3, min = 0, max = 1.0, default = (1.0,1.0,1.0))
    
    amb_light_int = bpy.props.IntVectorProperty(name = "Int Ambient Color", size = 3, min = 0, max = 255, default = (0,74,7))
    dir_lights_int = bpy.props.IntVectorProperty(name = "Int Light 1 Color", size = 3, min = 0, max = 255, default = (0,3,101))
    light_dir_int = bpy.props.IntVectorProperty(name = "Int Light 1 Angle", size = 3, min = -90, max = 90, default = (90,90,90))
    dir_lights2_int = bpy.props.IntVectorProperty(name = "Int Light 2 Color", size = 3, min = 0, max = 255, default = (252,3,0))
    light_dir2_int = bpy.props.IntVectorProperty(name = "Int Light 2 Angle", size = 3, min = -90, max = 90, default = (190,90,90))
    dir_lights3_int = bpy.props.IntVectorProperty(name = "Int Light 3 Color", size = 3, min = 0, max = 255, default = (255,134,0))
    light_dir3_int = bpy.props.IntVectorProperty(name = "Int Light 3 Angle", size = 3, min = -90, max = 90, default = (90,90,90))
    
    
class SceneProp_Xport64(bpy.types.PropertyGroup):
    bl_label = "Xport64 Scene Properties"
    expand_header = bpy.props.BoolProperty(name = "Expand Xport64 .H/Inc Settings",  default = False  )
    current_scene_id = bpy.props.StringProperty(name = "Scene ID", default = "scn00")
    create_header_file = bpy.props.BoolProperty(name = "Export Header File",  default = False  )
    scene_header_id = bpy.props.StringProperty(name = "Header ID", default = "scn00")
        
    custom_scene_includes = bpy.props.BoolProperty(name = "Export #Includes",  default = False  )
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
    expand_material = bpy.props.BoolProperty(name = "Expand Xport64 Material Settings",  default = False  )
    expand_texture = bpy.props.BoolProperty(name = "Expand Xport64 Texture Settings",  default = False  )    
    #image_select = bpy.props.PointerProperty(name = "Image", type = Image)
    custom_commands = bpy.props.BoolProperty(name = "Custom GBI Commands",  default = False  )
    #image_name = "No Image"
    mat_image_name = bpy.props.StringProperty(name = "Image Name", default = "No Image")
    
#START---------------------------------Pre-built macros and settings------------------------------------------------>
    prebuilt_commands = bpy.props.EnumProperty(
        name = "Pre-Built Commands",
        description = "Choose from a series of pre-built GBI commands for setting up your texture, lighting, and other GBI commands on the N64.",
        items = [
                ('TEXTURE_4B', "TEXTURE_4B - Standard 4B Color Index(CI) Texture w/ TLUT.", "For use with standard textured surfaces using Vertex Colors or Vertex Lighting."),
                ('TEXTURE_4B_UNLIT', "TEXTURE_4B_UNLIT - 'Emmissive' 4B Color Index(CI) Texture w/ TLUT.", "For use with standard textured surfaces that are emmissive and use no lighting."),
                ('ALPHA_TEXTURE_4B', "ALPHA_TEXTURE_4B - 4B CI Texture w/ TLUT and PrimColor alpha.", "For use with textured surfaces with alpha set by PrimColor"),
                ('TEXTURE_16B_RGBA_LIT', "TEXTURE_16B_RGBA_LIT - 16b RGBA Texture w/ lighting.", "For use with textured surfaces with Vertex colors or real time lighting."),
                ('TEXTURE_16B_RGBA_UNLIT', "TEXTURE_16B_RGBA_UNLIT - 16b RGBA Texture 'Emissive' object with no lighting.", "For use with textured surfaces that do not use Vertex colors or real time lighting."),                    
                ('PRIM_COLORS_SHADED', "PRIM_COLORS_SHADED - Color determined primitive color and shaded.", "For use with un-textured meshes using primitive colors"),
                ('PRIM_COLORS_UNLIT', "PRIM_COLORS_UNLIT - 'Emmissive' Color determined by primitive color only.", "For use with un-textured, unlit meshes"),
                ('TEX_4B_I_EFFECT', "TEX_4B_I_EFFECT - Intensity texture for effects such as shadows.", "For use with intensity effects such as decal shadows"),                      
                ('TEX_4B_CI_LIQUID', "TEX_4B_CI_LIQUID - 4B CI Texture for liquid surfaces.", "For use with liquid surfaces that use a texture"),      
                ('TEX_4B_CI_LIGHTSHAFT', "TEX_4B_CI_LIGHTSHAFT - 4B CI Texture w/ alpha for light rays.", "For use with light shafts/rays or other glowing objects"), 
                ('TEXTURE_4B_EDGE', "TEXTURE_4B_EDGE - 4B CI Texture w/ 1 bit alpha.", "For use with decal textures and 2D elements"), 
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

    expand = bpy.props.BoolProperty(name = "Expand Xport64 Model Settings",  default = False  )
    expand_gbi = bpy.props.BoolProperty(name = "Expand Xport64 GBI Settings",  default = False  )
    
    gbi_com_settings = bpy.props.BoolProperty(name = "Export GBI/Material Commands",  default = True  )
    gbi_com_textures = bpy.props.BoolProperty(name = "Export Modify Vertex Commands",  default = True  )
    gbi_prim_color = bpy.props.BoolProperty(name = "Export Primitive Color",  default = True  )
    gbi_env_color = bpy.props.BoolProperty(name = "Export Environment Color",  default = False  )
    
#START------------------------------------------------- Object Model settings --------------------------------------------------------------------->        
    
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
    
    set_dl_name = bpy.props.StringProperty(name = "DYNAMIC: Display List Pointer", default = "glistp")
    sort_Method = bpy.props.EnumProperty(
        name = "VTX Export Method",
        description = "Choose the method for vertex sorting and texture.",
        items = [
                ('VTX COLOR', "VTX Colors-Static Object", "", 1),
                ('VTX LIGHTING', "VTX Normals-Vertex Lit Object", "", 2),                
                ('COLLISION', "Collision Mesh", "", 3),          
                ]
    )

    pass_animframe = bpy.props.BoolProperty(name = "'animFrame' DL Parameter", default = True)    
    update_frame_function = bpy.props.BoolProperty(name = "*update_frame() Function", default = False)
    
    anim_Method = bpy.props.EnumProperty(
        name = "Animation Method",
        description = "Export your model to a series of vertex display lists frames or the object's rotation/position per frame.",
        items = [
                ("NO ANIM", "No Animation Frames", "", 1),
                ("VTX DL", "Weighted - VTX Display Lists", "", 2),
                ("OBJ VARIABLES", "Object - Rot, Pos, and Scl", "", 3),          
                ]
    )
    
    #export_rig_info =  bpy.props.BoolProperty(name = "Static Display List",  default = False  )
    
    #rig_Template = bpy.props.BoolProperty(name = "Include Default Rig Template",  default = False  )
    
    
    #If user chooses 'OBJ VARIABLES' then give some options on managing the rig of the object
    rig_Method = bpy.props.EnumProperty(
        name = "Rig Update Method",
        description = "Export your model using a rig for an animated character using Xport64 default rig or your own command",
        items = [
                ("NO RIG", "None - Don't Include Rig Update", ""),
                ("XPORT64 RIG", "Xport64 - Rig Update", ""),
                ("CUSTOM FUNCTION", "Custom - Call An External Rig Function ", ""),          
                ]
    )
    
#NOTE ----- If using a default Xport64 rig:
    rig_Template_Name = bpy.props.StringProperty(name = "Rig Name", default = "object00")
    joint_Template_Name = bpy.props.StringProperty(name = "Joint Name", default = "joint00")
    
#NOTE ----- If using a custom rig function:
    custom_Rig_Function = bpy.props.StringProperty(name = "Custom Rig Command", default = "//Replace this with your command such as: yourFunctionName(var1,var2);")
    #joint_Template_Name = bpy.props.StringProperty(name = "Joint Assignment", default = "joint00")


    
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
        row.label(text = "Set N64 Scene Data", icon= 'IMAGE_COL')
        
        row = layout.row()
        row.prop(sceneprops, "current_scene_id")
        
        
#   **********************************************************************************************************************************************
#   ************************************************************ Custom Header File **************************************************************
#   ********************************************************************************************************************************************** 
        renderBox = layout.box()            
        row = renderBox.row() 
        
        row.prop(sceneprops, "expand_header", icon = 'WORDWRAP_ON')
        row.label("Expand to set up header file and #includes.")

        
        if sceneprops.expand_header == True:  
            row = renderBox.row()        
            row.prop(sceneprops, "create_header_file")
            row.prop(sceneprops, "custom_scene_includes")
            if sceneprops.create_header_file == True:
                #row.label(text = "ENABLED: Definitions/Declarations to .h File")
                row = renderBox.row()
                row.prop(sceneprops, "scene_header_id")
                row = renderBox.row()
            else:
                #row.label(text = "DISABLED: Don't Create a .h File")
                row = renderBox.row()
                row.prop(sceneprops, "scene_header_id")
                row.active = False            
                
    #   **********************************************************************************************************************************************
    #   ******************************************************** Print #includes in C file ***********************************************************
    #   **********************************************************************************************************************************************     
            
            row = renderBox.row()            
            #row = layout.row()              
            
            if sceneprops.custom_scene_includes == True:
                #row.label(text = "Object Export Properties", icon= 'IMAGE_DATA')
                row.label(text = "ENABLED: Print .h Includes")
                row = renderBox.row()            
                row.prop(sceneprops, "scene_Includes1")
                row = renderBox.row()
                
                if sceneprops.scene_Includes1 != None and sceneprops.scene_Includes1 != "":
                    row.prop(sceneprops, "scene_Includes2")
                    row = renderBox.row()
                if sceneprops.scene_Includes2 != None and sceneprops.scene_Includes2 != "":
                    row.prop(sceneprops, "scene_Includes3")
                    row = renderBox.row()                    
                if sceneprops.scene_Includes3 != None and sceneprops.scene_Includes3 != "":
                    row.prop(sceneprops, "scene_Includes4")
                    row = renderBox.row()
                if sceneprops.scene_Includes4 != None and sceneprops.scene_Includes4 != "":
                    row.prop(sceneprops, "scene_Includes5")
                    row = renderBox.row()
                if sceneprops.scene_Includes5 != None and sceneprops.scene_Includes5 != "":
                    row.prop(sceneprops, "scene_Includes6")
                    row = renderBox.row()
                if sceneprops.scene_Includes6 != None and sceneprops.scene_Includes6 != "":
                    row.prop(sceneprops, "scene_Includes7")
                    row = renderBox.row()
                if sceneprops.scene_Includes7 != None and sceneprops.scene_Includes7 != "":
                    row.prop(sceneprops, "scene_Includes8")
                    row = renderBox.row()                    
                if sceneprops.scene_Includes8 != None and sceneprops.scene_Includes8 != "":
                    row.prop(sceneprops, "scene_Includes9")
                    row = renderBox.row()
                if sceneprops.scene_Includes9 != None and sceneprops.scene_Includes9 != "":
                    row.prop(sceneprops, "scene_Includes10")
                    row = renderBox.row()
                        
            elif sceneprops.custom_scene_includes == False:
                #row.label(text = "Object Export Properties", icon= 'IMAGE_DATA')     
                #row.label(text = "DISABLED: Do not print .h includes")
                row = renderBox.row()
                row.prop(sceneprops, "scene_Includes1")           
                row.active = False
        
        else:
            row = renderBox.row()
            row.label(text = "Header ID: %s" % sceneprops.scene_header_id)
            row.label(text = "Export Header File: %s" % sceneprops.create_header_file)
            row.label(text = "Export #includes: %s" % sceneprops.custom_scene_includes)
            row.enabled = False
            row = renderBox.row()
            row.label(text = "#Includes: %s   %s   %s ..." %(sceneprops.scene_Includes1,sceneprops.scene_Includes2, sceneprops.scene_Includes3 ))
            row.enabled = False
#   **********************************************************************************************************************************************
#   ********************************************************* Set Up Default Scene Lights ********************************************************
#   **********************************************************************************************************************************************         
        
        renderBox = layout.box()            
        #row = renderBox.row()
        #renderBox.label(text = "Scene Lights: Set the default scene lights.", icon = 'LAMP')
        
        row = renderBox.row()     
        row.prop(scenelights, "expand", icon = 'LAMP_SUN')        
        row.prop(scenelights, "custom_lights")
        

        if scenelights.expand == True:
            row = renderBox.row()
            if scenelights.custom_lights == True:
                #row.prop(scenelights, "qty_lights")
                #row.label(text = "ENABLED: Will export custom scene light structures.")
                row.prop(scenelights, "manual_entry")
                
                
            else:
                row.label(text = "DISABLED: Will not export custom scene light structures.")        
            
            if scenelights.custom_lights == True:
                if scenelights.manual_entry == False: #NOTE ----- use color and direction picker objects.
                    row = renderBox.row()     
                    row.prop(scenelights, "light_struct_name")
                    row = renderBox.row()
                    split = renderBox.split()
                    col = split.column()                 
                    col.prop(scenelights, "amb_light")
                    row = col.row() 
                    
                    #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                    scenelights.amb_light_int[0] = scenelights.amb_light[0]*255
                    scenelights.amb_light_int[1] = scenelights.amb_light[1]*255
                    scenelights.amb_light_int[2] = scenelights.amb_light[2]*255
                    row.label(text = "Ambient Light Color: R. %i  G. %i, B. %i" % (scenelights.amb_light_int[0], scenelights.amb_light_int[1],scenelights.amb_light_int[2]))
                    
                    row = renderBox.row()
                    
                    #expand_diffuse
                    row.prop(scenelights, "expand_diffuse", icon = 'LAMP_SPOT')
                    row.label(text = "Click to edit up to 3 Diffuse/Direction lights.") 
                    #row.prop(scenelights, "diffuse_lights")
                    
                    if scenelights.expand_diffuse == True:
                        
                        #row.prop(scenelights, "qty_lights")
                        #row.label(text = "ENABLED: Include diffuse/direction lights.") 

                        row = renderBox.row()
                        row.prop(scenelights, "qty_lights")

                    
                        if scenelights.qty_lights >= 1:   
                            split = renderBox.split()
                            col = split.column()                            
                            col.prop(scenelights, "dir_lights")
                            col.prop(scenelights, "light_dir")                                                       
                            
                            #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                            scenelights.dir_lights_int[0] = scenelights.dir_lights[0]*255
                            scenelights.dir_lights_int[1] = scenelights.dir_lights[1]*255
                            scenelights.dir_lights_int[2] = scenelights.dir_lights[2]*255
                            #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                            #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                            scenelights.light_dir_int[0] = scenelights.light_dir[0]*90
                            scenelights.light_dir_int[1] = scenelights.light_dir[2]*90
                            scenelights.light_dir_int[2] = scenelights.light_dir[1]*90
                            
                            row = col.row()
                            row.label(text = "Color: R. %i  G. %i, B. %i" % (scenelights.dir_lights_int[0], scenelights.dir_lights_int[1],scenelights.dir_lights_int[2]))
                            row = col.row()
                            row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (scenelights.light_dir_int[0], scenelights.light_dir_int[1],scenelights.light_dir_int[2]))
                            
                            if scenelights.qty_lights >= 2:                      
                                col = split.column()    
                                col.prop(scenelights, "dir_lights2")
                                col.prop(scenelights, "light_dir2")   
                                
                                #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                scenelights.dir_lights2_int[0] = scenelights.dir_lights2[0]*255
                                scenelights.dir_lights2_int[1] = scenelights.dir_lights2[1]*255
                                scenelights.dir_lights2_int[2] = scenelights.dir_lights2[2]*255
                                #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                scenelights.light_dir2_int[0] = scenelights.light_dir2[0]*90
                                scenelights.light_dir2_int[1] = scenelights.light_dir2[2]*90
                                scenelights.light_dir2_int[2] = scenelights.light_dir2[1]*90
                                
                                row = col.row()
                                row.label(text = "Color: R. %i  G. %i, B. %i" % (scenelights.dir_lights2_int[0], scenelights.dir_lights2_int[1],scenelights.dir_lights2_int[2]))
                                row = col.row()
                                row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (scenelights.light_dir2_int[0], scenelights.light_dir2_int[1],scenelights.light_dir2_int[2]))

                                if scenelights.qty_lights == 3:                      
                                    col = split.column()    
                                    col.prop(scenelights, "dir_lights3")
                                    col.prop(scenelights, "light_dir3")
                                    
                                    #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                    scenelights.dir_lights3_int[0] = scenelights.dir_lights3[0]*255
                                    scenelights.dir_lights3_int[1] = scenelights.dir_lights3[1]*255
                                    scenelights.dir_lights3_int[2] = scenelights.dir_lights3[2]*255
                                    #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                    #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                    scenelights.light_dir3_int[0] = scenelights.light_dir3[0]*90
                                    scenelights.light_dir3_int[1] = scenelights.light_dir3[2]*90
                                    scenelights.light_dir3_int[2] = scenelights.light_dir3[1]*90
                                    
                                    row = col.row()
                                    row.label(text = "Color: R. %i  G. %i, B. %i" % (scenelights.dir_lights3_int[0], scenelights.dir_lights3_int[1],scenelights.dir_lights3_int[2]))
                                    row = col.row()
                                    row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (scenelights.light_dir3_int[0], scenelights.light_dir3_int[1],scenelights.light_dir3_int[2]))

                    else:
                        if scenelights.qty_lights >= 1:
                            row = renderBox.row()
                            row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (scenelights.dir_lights_int[0], scenelights.dir_lights_int[1],scenelights.dir_lights_int[2]))
                            row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir_int[0], scenelights.light_dir_int[1],scenelights.light_dir_int[2]))
                            row.enabled = False
                            if scenelights.qty_lights >= 2:
                                row = renderBox.row()
                                row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (scenelights.dir_lights2_int[0], scenelights.dir_lights2_int[1],scenelights.dir_lights2_int[2]))
                                row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir2_int[0], scenelights.light_dir2_int[1],scenelights.light_dir2_int[2]))
                                row.enabled = False
                                if scenelights.qty_lights >= 3:
                                    row = renderBox.row()
                                    row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (scenelights.dir_lights3_int[0], scenelights.dir_lights3_int[1],scenelights.dir_lights3_int[2]))
                                    row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir3_int[0], scenelights.light_dir3_int[1],scenelights.light_dir3_int[2]))
                                    row.enabled = False
                                    
                elif scenelights.manual_entry == True: #NOTE ----- use color and direction picker objects.
                    row = renderBox.row()     
                    row.prop(scenelights, "light_struct_name")
                    row = renderBox.row()
                    split = renderBox.split()
                    col = split.column()                 
                    col.prop(scenelights, "amb_light_int")  
                    row = col.row()  
                    #row.label(text = "Ambient Light Color: R. %i  G. %i, B. %i" % (scenelights.amb_light[0]*255, scenelights.amb_light[1]*255,scenelights.amb_light[2]*255))
                    
                    row = renderBox.row()
                    row.prop(scenelights, "expand_diffuse", icon = 'LAMP_SPOT')
                    row.label(text = "Click to edit up to 3 Diffuse/Direction lights.") 
                    #row.prop(scenelights, "diffuse_lights")
                    
                    if scenelights.expand_diffuse == True:
                    
                        #row.prop(scenelights, "qty_lights")
                        row = renderBox.row()
                        #row.label(text = "ENABLED: Include diffuse/direction lights in export.")

                        row = renderBox.row()
                        row.prop(scenelights, "qty_lights")
                    
                        if scenelights.qty_lights >= 1:
                            split = renderBox.split()
                            col = split.column()                            
                            col.prop(scenelights, "dir_lights_int")
                            col.prop(scenelights, "light_dir_int")

                            if scenelights.qty_lights >= 2:                      
                                col = split.column()    
                                col.prop(scenelights, "dir_lights2_int")
                                col.prop(scenelights, "light_dir2_int")   

                                if scenelights.qty_lights == 3:                      
                                    col = split.column()    
                                    col.prop(scenelights, "dir_lights3_int")
                                    col.prop(scenelights, "light_dir3_int")                
                    
                    else:
                        if scenelights.qty_lights >= 1:
                            row = renderBox.row()
                            row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (scenelights.dir_lights_int[0], scenelights.dir_lights_int[1],scenelights.dir_lights_int[2]))
                            row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir_int[0], scenelights.light_dir_int[1],scenelights.light_dir_int[2]))
                            row.enabled = False
                            if scenelights.qty_lights >= 2:
                                row = renderBox.row()
                                row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (scenelights.dir_lights2_int[0], scenelights.dir_lights2_int[1],scenelights.dir_lights2_int[2]))
                                row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir2_int[0], scenelights.light_dir2_int[1],scenelights.light_dir2_int[2]))
                                row.enabled = False
                                if scenelights.qty_lights >= 3:
                                    row = renderBox.row()
                                    row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (scenelights.dir_lights3_int[0], scenelights.dir_lights3_int[1],scenelights.dir_lights3_int[2]))
                                    row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir3_int[0], scenelights.light_dir3_int[1],scenelights.light_dir3_int[2]))
                                    row.enabled = False
            elif scenelights.custom_lights == False:
                row = renderBox.row()     
                row.prop(scenelights, "light_struct_name")
                row.enabled = False   

            row = layout.row()
        
        elif scenelights.custom_lights == True:
            row = renderBox.row()            
            row.label(text = "%s" % scenelights.light_struct_name)
            row.label(text = "Ambient: R %i, G %i, B %i" % (scenelights.amb_light_int[0], scenelights.amb_light_int[1],scenelights.amb_light_int[2]))
            row.enabled = False                        
            if scenelights.qty_lights >= 1:
                row = renderBox.row()
                row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (scenelights.dir_lights_int[0], scenelights.dir_lights_int[1],scenelights.dir_lights_int[2]))
                row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir_int[0], scenelights.light_dir_int[1],scenelights.light_dir_int[2]))
                row.enabled = False
                if scenelights.qty_lights >= 2:
                    row = renderBox.row()
                    row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (scenelights.dir_lights2_int[0], scenelights.dir_lights2_int[1],scenelights.dir_lights2_int[2]))
                    row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir2_int[0], scenelights.light_dir2_int[1],scenelights.light_dir2_int[2]))
                    row.enabled = False
                    if scenelights.qty_lights >= 3:
                        row = renderBox.row()
                        row.label(text = "Diffuse Light 3: R. %i,  G. %i, B. %i" % (scenelights.dir_lights3_int[0], scenelights.dir_lights3_int[1],scenelights.dir_lights3_int[2]))
                        row.label(text = "Light Angle 3:   X. %i,  Y. %i, Z. %i" % (scenelights.light_dir3_int[0], scenelights.light_dir3_int[1],scenelights.light_dir3_int[2]))
                        row.enabled = False
        
        elif scenelights.custom_lights == False:
                row = renderBox.row()
                row.label(text = "DISABLED: Will not exportcustom scene light structures.")
                row.enabled = False
        
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
        
        if obj != None:
            objprops = obj.obj_props
            objlights = obj.obj_lights
            
            row = layout.row()                  
            col = layout.column()
            row.label(text = "Xport64 Object Export Settings", icon= 'OBJECT_DATAMODE')               
            row = layout.row()        
            row.prop(objprops, "debug_DL")
            row.prop(objprops, "guide_DL")            
            row = layout.row() 

            row.prop(objprops, "static_DL")     
            if objprops.static_DL == False:
                row = layout.row()            
                row.prop(objprops, "set_dl_name")
                row = layout.row()
            elif objprops.static_DL == True:
                row = layout.row()
                #row.prop(objprops, "set_dl_name")
                row.label(text = "STATIC: No Pointer Needed")    
                row.active = False

            
            row.separator()#----------------------------------------------

            #row.label(text = "Object Export Settings", icon= 'IMAGE_DATA')
            # row = renderBox.row()
            
            renderBox = layout.box()
            row = renderBox.row() 
            row.prop(objprops, "expand_gbi", icon = 'SEQ_SPLITVIEW')
            row.prop(objprops, "gbi_com_settings")
            
            if objprops.expand_gbi == True:            
                #row.label(text = "gfx_settings_method", icon= 'IMAGE_DATA') 
                if objprops.gbi_com_settings == True:           
                    #row.label(text = "ENABLED: Choose Method for GBI Commands")
                    row = renderBox.row() 
                    row.prop(objprops, "gbi_com_settings_method")
                    row = renderBox.row()
                    
                    if objprops.gbi_com_settings_method == "DL CALL":            
                        row = renderBox.row()
                        row.prop(objprops, "gbi_com_existing_DL")
                    else:            
                        row = renderBox.row()
                        row.label(text = "DISABLED: No Existing Display List")
                        #row.prop(objprops, "gbi_com_existing_DL")
                        row.active = False           
                    
                elif objprops.gbi_com_settings == False:            
                    #row.label(text = "DISABLED: In-Line Comment Only")
                    row = renderBox.row()            
                    row.prop(objprops, "gbi_com_settings_method")            
                    row.active = False
                    
                row.separator()#----------------------------------------------
                row = renderBox.row()            
                row.prop(objprops, "gbi_com_textures")
                row = renderBox.row()
                row.prop(objprops, "gbi_prim_color")
                row.prop(objprops, "gbi_env_color")
                    
            
            else:
                row = renderBox.row()
                if objprops.gbi_com_settings == True:
                    row.label(text = "GBI Format = %s" % objprops.gbi_com_settings_method)
                    #row.label(text = "GBI Format =")
                    if objprops.gbi_com_settings_method == "DL CALL":
                        row.label(text = "External DL Name: %s" % objprops.gbi_com_existing_DL)
                        row.label(text = "")
                    row.enabled = False
                    row = renderBox.row() 
                    row.label(text = "Modify VTX = %s" % objprops.gbi_com_textures )
                    row.label(text = "PrimColor = %s" % objprops.gbi_prim_color)
                    row.label(text = "EnvColor = %s" % objprops.gbi_env_color)
                    row.enabled = False
                else:
                    row.label(text = "DISABLED: Will not export GBI Commands.")
                    row.enabled = False
            
            row.separator()#----------------------------------------------
            row = renderBox.row()
            #BRUSH_VERTEXDRAW  #MOD_SOLIDIFY 
            #SNAP_NORMAL #COLOR
            
                            # ('VTX COLOR', "VTX Colors-Static Object", "", 1),
                # ('VTX LIGHTING', "VTX Normals-Vertex Lit Object", "", 2),                
                # ('COLLISION', "Collision Mesh", "", 3),     
            
            #MOD_DYNAMICPAINT #MATCUBE
            
            renderBox = layout.box()
            row = renderBox.row() 
                        
            if objprops.sort_Method == 'VTX COLOR':
                row.prop(objprops, "expand", icon= 'MOD_DYNAMICPAINT')
                row.label(text = "Xport64 Vertex and Animation Settings.")   
            elif objprops.sort_Method == 'VTX LIGHTING':
                row.prop(objprops, "expand", icon= 'SCENE_DATA')
                row.label(text = "Xport64 Object Export Type")  
            elif objprops.sort_Method == 'COLLISION':
                row.prop(objprops, "expand", icon= 'MOD_LATTICE')
                row.label(text = "Xport64 Object Export Type")
            
            
            
            if objprops.expand == True:    
                #row.label(text = "Xport64 Object Export Type", icon= 'IMAGE_DATA')        
                renderBox.prop(objprops, "sort_Method")         
                row = renderBox.row()
                
                row.label(text = "______________________________________________________________________________________________________________________________________")
                
                row.separator()#----------------------------------------------
                    
                row = renderBox.row()
                
                if objprops.anim_Method == 'NO ANIM':
                    row.label(text = "Xport64 Animation Method", icon= 'NDOF_DOM')   
                elif objprops.anim_Method == 'VTX DL':
                    row.label(text = "Xport64 Animation Method", icon= 'MOD_SIMPLEDEFORM')  
                elif objprops.anim_Method == 'OBJ VARIABLES':
                    row.label(text = "Xport64 Animation Method", icon= 'MOD_ARRAY')
                
                                # ("NO ANIM", "No Animation Frames", "", 1),
                    # ("VTX DL", "Weighted - VTX Display Lists", "", 2),
                    # ("OBJ VARIABLES", "Object - Rot, Pos, and Scl", "", 3),    
                
                #row.label(text = "Xport64 Animation Method", icon= 'RENDER_ANIMATION')        
                renderBox.prop(objprops, "anim_Method")
                
                if objprops.static_DL == False:
                    row = renderBox.row()                
                    row.prop(objprops, "pass_animframe") #include a function parameter called animFrame for switching display lists or updating animation
                    if objprops.pass_animframe == True:
                        row.label(text = "ENABLED: void %s_PolyList(u8 animFrame);" % obj.name)
                    else:    
                        row.label(text = "DISABLED: void %s_PolyList();" % obj.name)
                    row = renderBox.row()
                    row.prop(objprops, "update_frame_function") #include an example function for updating this object's current animation frame
                    
                    if objprops.update_frame_function == True:
                        row.label(text = "ENABLED: %s_updateFrame();" % obj.name)
                    else:    
                        row.label(text = "DISABLED: No Function")
                
                renderBox.prop(objprops, "rig_Method")
                
                if objprops.rig_Method == "XPORT64 RIG":
                    row = renderBox.row()  
                    renderBox.prop(objprops, "rig_Template_Name") 
                    renderBox.prop(objprops, "joint_Template_Name") 
                
                if objprops.rig_Method == "CUSTOM FUNCTION":
                    row = renderBox.row()
                    renderBox.prop(objprops, "custom_Rig_Function") 

                
                
                                # ("NO RIG", "No Rig Update.", ""),
                # ("XPORT64 RIG", "Xport64 - Rig Update", ""),
                # ("CUSTOM FUNCTION", "Custom - Call An External Rig Function ", ""),   
                
                    # rig_Method
# rig_Template_Name    
# joint_Template_Name
# custom_Rig_Function
                
                
            else:
                row = renderBox.row() 
                row.label(text = "VTX Export Method: %s" % objprops.sort_Method)  
                row.label(text = "VTX Export Method: %s" % objprops.anim_Method)
                row.enabled = False
            #void Player_Head_animation(u8 animFrame)    
                
            row = renderBox.row()            
            
            # row.label(text = "______________________________________________________________________________________________________________________________________")
            # row.separator()#----------------------------------------------
            
            #   **********************************************************************************************************************************************
    #   ********************************************************* Set Up Default Object Lights ********************************************************
    #   **********************************************************************************************************************************************         
            
            renderBox = layout.box()            
            #row = renderBox.row()
            #renderBox.label(text = "Object Lights: If used, will override scene lights.", icon = 'OUTLINER_OB_LAMP')
            
            # row = renderBox.row()     
            # row.prop(objlights, "custom_lights", icon = 'LAMP_SUN')

            row = renderBox.row()     
            row.prop(objlights, "expand", icon = 'LAMP_SUN')        
            row.prop(objlights, "custom_lights")
                        
            
            if objlights.expand == True:
                row = renderBox.row()
                if objlights.custom_lights == True:
                    #row.prop(objlights, "qty_lights")
                    row.prop(objlights, "manual_entry")
                else:
                    row.label(text = "DISABLED: Will not export light structures for this object.")        
                
                if objlights.custom_lights == True:               

                    if objlights.manual_entry == False: #NOTE ----- use color and direction picker objects.
                        row = renderBox.row()     
                        row.prop(objlights, "light_struct_name")
                        row = renderBox.row()                            

                        split = renderBox.split()
                        col = split.column()                 
                        col.prop(objlights, "amb_light")  
                        row = col.row()
                        
                        #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                        objlights.amb_light_int[0] = objlights.amb_light[0]*255
                        objlights.amb_light_int[1] = objlights.amb_light[1]*255
                        objlights.amb_light_int[2] = objlights.amb_light[2]*255
                        row.label(text = "Ambient Light Color: R. %i  G. %i, B. %i" % (objlights.amb_light_int[0], objlights.amb_light_int[1],objlights.amb_light_int[2]))
                                        
                        row = renderBox.row()
                        # row.prop(objlights, "diffuse_lights", icon = 'LAMP_SPOT')
                        
                        row.prop(objlights, "expand_diffuse", icon = 'LAMP_SPOT')
                        row.label(text = "Click to edit up to 3 Diffuse/Direction lights.") 
                        #row.prop(objlights, "diffuse_lights")
                        
                        if objlights.expand_diffuse == True:
                            row = renderBox.row()
                            row.prop(objlights, "qty_lights")
                            #row.label(text = "ENABLED: Include diffuse/direction lights.") 

                            if objlights.qty_lights >= 1:   
                                split = renderBox.split()
                                col = split.column()                            
                                col.prop(objlights, "dir_lights")
                                col.prop(objlights, "light_dir")                                                       
                                
                                #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                objlights.dir_lights_int[0] = objlights.dir_lights[0]*255
                                objlights.dir_lights_int[1] = objlights.dir_lights[1]*255
                                objlights.dir_lights_int[2] = objlights.dir_lights[2]*255
                                #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                objlights.light_dir_int[0] = objlights.light_dir[0]*90
                                objlights.light_dir_int[1] = objlights.light_dir[2]*90
                                objlights.light_dir_int[2] = objlights.light_dir[1]*90
                                
                                row = col.row()
                                row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.dir_lights_int[0], objlights.dir_lights_int[1],objlights.dir_lights_int[2]))
                                row = col.row()
                                row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (objlights.light_dir_int[0], objlights.light_dir_int[1],objlights.light_dir_int[2]))
                                
                                if objlights.qty_lights >= 2:                      
                                    col = split.column()    
                                    col.prop(objlights, "dir_lights2")
                                    col.prop(objlights, "light_dir2")   
                                    
                                    #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                    objlights.dir_lights2_int[0] = objlights.dir_lights2[0]*255
                                    objlights.dir_lights2_int[1] = objlights.dir_lights2[1]*255
                                    objlights.dir_lights2_int[2] = objlights.dir_lights2[2]*255
                                    #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                    #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                    objlights.light_dir2_int[0] = objlights.light_dir2[0]*90
                                    objlights.light_dir2_int[1] = objlights.light_dir2[2]*90
                                    objlights.light_dir2_int[2] = objlights.light_dir2[1]*90
                                    
                                    row = col.row()
                                    row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.dir_lights2_int[0], objlights.dir_lights2_int[1],objlights.dir_lights2_int[2]))
                                    row = col.row()
                                    row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (objlights.light_dir2_int[0], objlights.light_dir2_int[1],objlights.light_dir2_int[2]))
                                    # row = col.row()
                                    # row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.dir_lights2[0]*255, objlights.dir_lights2[1]*255,objlights.dir_lights2[2]*255))
                                    # row = col.row()
                                    # row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (objlights.light_dir2[0]*90, objlights.light_dir2[2]*90, objlights.light_dir2[1]*90))                               
                                    
                                    if objlights.qty_lights == 3:                      
                                        col = split.column()    
                                        col.prop(objlights, "dir_lights3")
                                        col.prop(objlights, "light_dir3")
                                        
                                        #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                        objlights.dir_lights3_int[0] = objlights.dir_lights3[0]*255
                                        objlights.dir_lights3_int[1] = objlights.dir_lights3[1]*255
                                        objlights.dir_lights3_int[2] = objlights.dir_lights3[2]*255
                                        #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                        #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                        objlights.light_dir3_int[0] = objlights.light_dir3[0]*90
                                        objlights.light_dir3_int[1] = objlights.light_dir3[2]*90
                                        objlights.light_dir3_int[2] = objlights.light_dir3[1]*90
                                        
                                        row = col.row()
                                        row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.dir_lights3_int[0], objlights.dir_lights3_int[1],objlights.dir_lights3_int[2]))
                                        row = col.row()
                                        row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (objlights.light_dir3_int[0], objlights.light_dir3_int[1],objlights.light_dir3_int[2]))
                
                        else:
                            if objlights.qty_lights >= 1:
                                row = renderBox.row()
                                row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (objlights.dir_lights_int[0], objlights.dir_lights_int[1],objlights.dir_lights_int[2]))
                                row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir_int[0], objlights.light_dir_int[1],objlights.light_dir_int[2]))
                                row.enabled = False
                                if objlights.qty_lights >= 2:
                                    row = renderBox.row()
                                    row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (objlights.dir_lights2_int[0], objlights.dir_lights2_int[1],objlights.dir_lights2_int[2]))
                                    row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir2_int[0], objlights.light_dir2_int[1],objlights.light_dir2_int[2]))
                                    row.enabled = False
                                    if objlights.qty_lights >= 3:
                                        row = renderBox.row()
                                        row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (objlights.dir_lights3_int[0], objlights.dir_lights3_int[1],objlights.dir_lights3_int[2]))
                                        row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir3_int[0], objlights.light_dir3_int[1],objlights.light_dir3_int[2]))
                                        row.enabled = False
                
                    if objlights.manual_entry == True: #NOTE ----- manually enter values for light color and direction
                        row = renderBox.row()     
                        row.prop(objlights, "light_struct_name")
                        row = renderBox.row()                            
                        # row.prop(objlights, "amb_light")
                        # row = col.row()
                        # row.label(text = "Color: R. %i  G. %i, B. %i" % (objlights.amb_light[0]*255, objlights.amb_light[1]*255,objlights.amb_light[2]*255))
                        
                        split = renderBox.split()
                        col = split.column()                 
                        col.prop(objlights, "amb_light_int")  
                        # row = col.row()  
                        # row.label(text = "Ambient Light Color: R. %i  G. %i, B. %i" % (objlights.amb_light[0]*255, objlights.amb_light[1]*255,objlights.amb_light[2]*255))
                    
                        row = renderBox.row()
                        # row.prop(objlights, "diffuse_lights", icon = 'LAMP_SPOT')
                        
                        row.prop(objlights, "expand_diffuse", icon = 'LAMP_SPOT')
                        row.label(text = "Click to edit up to 3 Diffuse/Direction lights.") 
                        #row.prop(objlights, "diffuse_lights")
                        
                        if objlights.expand_diffuse == True:                        
                            row = renderBox.row()
                            #row.label(text = "ENABLED: Include diffuse/direction lights.") 
                            row = renderBox.row()
                            row.prop(objlights, "qty_lights")                        

                            if objlights.qty_lights >= 1:   
                                split = renderBox.split()
                                col = split.column()                            
                                col.prop(objlights, "dir_lights_int")
                                col.prop(objlights, "light_dir_int")

                                if objlights.qty_lights >= 2:                      
                                    col = split.column()    
                                    col.prop(objlights, "dir_lights2_int")
                                    col.prop(objlights, "light_dir2_int")   

                                    if objlights.qty_lights == 3:                      
                                        col = split.column()    
                                        col.prop(objlights, "dir_lights3_int")
                                        col.prop(objlights, "light_dir3_int")                
                
                        else:
                            if objlights.qty_lights >= 1:
                                row = renderBox.row()
                                row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (objlights.dir_lights_int[0], objlights.dir_lights_int[1],objlights.dir_lights_int[2]))
                                row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir_int[0], objlights.light_dir_int[1],objlights.light_dir_int[2]))
                                row.enabled = False
                                if objlights.qty_lights >= 2:
                                    row = renderBox.row()
                                    row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (objlights.dir_lights2_int[0], objlights.dir_lights2_int[1],objlights.dir_lights2_int[2]))
                                    row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir2_int[0], objlights.light_dir2_int[1],objlights.light_dir2_int[2]))
                                    row.enabled = False
                                    if objlights.qty_lights >= 3:
                                        row = renderBox.row()
                                        row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (objlights.dir_lights3_int[0], objlights.dir_lights3_int[1],objlights.dir_lights3_int[2]))
                                        row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir3_int[0], objlights.light_dir3_int[1],objlights.light_dir3_int[2]))
                                        row.enabled = False
                
                elif objlights.custom_lights == False:
                    row = renderBox.row()     
                    row.prop(objlights, "light_struct_name")
                    row.enabled = False
                    
            elif objlights.custom_lights == True:
                row = renderBox.row()
                row.label(text = "Object Light Structure: %s" % objlights.light_struct_name)
                row.label(text = "Ambient: R %i, G %i, B %i" % (objlights.amb_light_int[0], objlights.amb_light_int[1],objlights.amb_light_int[2]))
                row.enabled = False                        
                if objlights.qty_lights >= 1:
                    row = renderBox.row()
                    row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (objlights.dir_lights_int[0], objlights.dir_lights_int[1],objlights.dir_lights_int[2]))
                    row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir_int[0], objlights.light_dir_int[1],objlights.light_dir_int[2]))
                    row.enabled = False
                    if objlights.qty_lights >= 2:
                        row = renderBox.row()
                        row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (objlights.dir_lights2_int[0], objlights.dir_lights2_int[1],objlights.dir_lights2_int[2]))
                        row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir2_int[0], objlights.light_dir2_int[1],objlights.light_dir2_int[2]))
                        row.enabled = False
                        if objlights.qty_lights >= 3:
                            row = renderBox.row()
                            row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (objlights.dir_lights3_int[0], objlights.dir_lights3_int[1],objlights.dir_lights3_int[2]))
                            row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (objlights.light_dir3_int[0], objlights.light_dir3_int[1],objlights.light_dir3_int[2]))
                            row.enabled = False
                            
            elif objlights.custom_lights == False:
                row = renderBox.row()
                row.label(text = "DISABLED: Will not export light structures for this object.")
                row.enabled = False

class AssignTexture_Xport64(bpy.types.Operator):
    bl_label = "Update Texture"
    bl_idname = "object.assign_texture_xport64"
    
    def execute(self, context):
        print("\nTest Texture\n")
        obj = bpy.context.object
        imgName = bpy.context.scene.image_name
        print("PRINT %s " % imgName)
        img = bpy.data.images.get(imgName)
        print("PRINT img %s " % img)
        
        
        
        
        #TO DO NOTE: FIGURE OUT WHERE ERROR IS IN LOADING IMAGE
        
        
        
        
        
        obj.active_material.node_tree.nodes["Image Texture"].image = img
        # bpy.context.scene.render.engine = 'CYCLES'
        # bpy.context.object.active_material.use_nodes = True
        
        return {'FINISHED'}
    
                
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
    bl_space_type = 'PROPERTIES'
    bl_region_type = 'WINDOW'
    bl_category = 'object'   
    bl_context = 'material'

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
                    
                    #nodes["Mix"].inputs[1].show_expanded
                    #nodes["Image Texture"].color_space
                    
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
# 1 ************************************************************ GBI Material Command Settings ************************************************************
#   **********************************************************************************************************************************************  
                    #renderBox = layout.box()
                    row = layout.row()
                    row.label(text = "Xport64 Material/Lighting GBI Commands", icon= 'IMAGE_COL')
                    row.label(text = "Use Pre-Built or Custom GBI Commands")
          
# ----- NOTE: Custom xport64 icons coming in future update ---------------------------------------------------------                    
                    #row.label(text = "Xport64 Material/Lighting GBI Commands", icon= 'IMAGE_DATA')
                    #row.label(text = "Xport64 Material/Lighting GBI Commands", icon_value=self.xport64_icons["xport64_Logo"].icon_id)
                    # xport64_icons = None
                    # xport64_icons = "testtest"
                    # xport64_icons = "/xport64logoicons32x32.png"
                    # xport64_icons = "C:\blender-2.76b-windows32\2.76\scripts\addons\io_xport64\icons"
                    # custom_icons.load("xport64_Logo", xport64_icons, 'IMAGE')
                    #row.label(text = "Xport64 Material/Lighting GBI Commands", icon_value=self.xport64_icons["xport64_Logo"].icon_id)
# ----- NOTE: Custom xport64 icons coming in future update ---------------------------------------------------------                    

                    renderBox = layout.box()
                    row = renderBox.row()
                    row.prop(matProps, "expand_material", icon = 'MATERIAL_DATA')
                    row.prop(matProps, "custom_commands")
                    
                    if matProps.expand_material == True:
                        row = renderBox.row() 
                        if matProps.custom_commands == False:   
                            #row = renderBox.row()
                            renderBox.prop(matProps, "prebuilt_commands")
                            #row = renderBox.row()        
                            
                        else:    
                            #row.label(text = "Generate Custom GBI Commands")
                            #row.label(text = "Xport64 CUSTOM Material/Lighting GBI Commands", icon= 'IMAGE_DATA')        
                            row = renderBox.row()
                            row.label(text = "More Custom Xport64 Material Settings Coming Soon")   
                            #renderBox.prop(matProps, "shading_commands")
                            row.enabled = False
                            #row = renderBox.row()                          
                            
                            #renderBox.prop(matProps, "texture_commands")
                            row.enabled = False
                            # row = renderBox.row()
                            
                        #row = renderBox.row()
                        #row.label(text = "Xport64 CUSTOM Material/Lighting GBI Commands", icon= 'IMAGE_DATA')
                        row = renderBox.row()
                        row.prop(matProps, "custom_tlut_name")
                        
                        if matProps.custom_tlut_name == False:
                            row.label(text = "%s_tlut" %image_name)
                            row = renderBox.row()            
                        else:
                            row.prop(matProps, "texture_tlut_name")
                            row = renderBox.row()
                        
                        renderBox.label(text = "Color: Set internal color registers for blending.")
                        split = renderBox.split()
                        col = split.column()                     
                        col.prop(matProps, "prim_color")
                        #row = renderBox.row()   

                        #row.label(text = "_____________________________________________________________________________________________________________________________________________")  
                        col = split.column()      
                        col.prop(matProps, "env_color")
                        row = renderBox.row() 
#   **********************************************************************************************************************************************
# 1 ************************************************************** Texture Settings **************************************************************
#   **********************************************************************************************************************************************                    
                    renderBox = layout.box()
                    row = renderBox.row()
                    row.prop(matProps, "expand_texture", icon= 'IMAGE_DATA')
                    #bpy.props.PointerProperty(name = "Image", type = Image)
                    row.prop_search(context.scene, 'image_name', bpy.data, 'images')
                    #row.operator("image.open", icon = "FILE_FOLDER", text = "Assign")
                    #obj.active_material.node_tree.nodes["Image Texture"].image.name = context.scene.image_name
                    row.operator("object.assign_texture_xport64", icon = 'MESH_CUBE', text = "Assign")
                    #VTX_Xport64.exportVert(self, file, obj,objCounter)
                    
                    row = renderBox.row()
                    
                    if matProps.prebuilt_commands != 'PRIM_COLORS_SHADED' and matProps.prebuilt_commands != 'PRIM_COLORS_UNLIT' :                    
                        if matProps.expand_texture == True:                    
                            row.label(text = "Texture Name: %s" % image_name)
                            row = renderBox.row()
                        
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
                        
                        else: 
                            row.label(text = "Texture Name: %s" % image_name)
                            row.label(text = "Resolution   X: %s   Y: %s   " % (matProps.texture_res_w, matProps.texture_res_h ))
                            row.label(text = "Texture Filter: %s" % matProps.filtering_commands)
                            row.enabled = False
                            row = renderBox.row()
                            row.label(text = "Wrap   S: %s   T: %s" % (matProps.wrap_commands_w, matProps.wrap_commands_h))
                            row.label(text = "Mask   S: %s   T: %s" % (matProps.mask_commands_w, matProps.mask_commands_h))
                            row.label(text = "Shift   S: %s   T: %s" % (matProps.shift_commands_w, matProps.shift_commands_h))
                            row.enabled = False
                    else:
                        row.label(text = "DISABLED: Choose texture based commands in Expand Xport64 Material Settings.")
                        row.enabled = False
                            #row.label(text = "_____________________________________________________________________________________________________________________________________________")  
                            
                            
#   **********************************************************************************************************************************************
# 1 ********************************************************** Lights and Color Settings *********************************************************
#   **********************************************************************************************************************************************  
                 
#   **********************************************************************************************************************************************
#   ******************************************************** Set Up Custom Material Lights *******************************************************
#   **********************************************************************************************************************************************         
        
                    renderBox = layout.box()            
                    row = renderBox.row()

                    row = renderBox.row()     
                    row.prop(matlights, "expand", icon = 'LAMP_SUN')        
                    row.prop(matlights, "custom_lights")

                    if matlights.expand == True:
                        row = renderBox.row()
                        if matlights.custom_lights == True:
                            #row.prop(matlights, "qty_lights")
                            row.prop(matlights, "manual_entry")
                        else:
                            row.label(text = "DISABLED: Will not export custom material light structures.")        
                        

                        if matlights.custom_lights == True:                       
                            
                            if matlights.manual_entry == False:
                                row = renderBox.row()                                 
                                row.prop(matlights, "light_struct_name")
                                #matlights.light_struct_name.default_value = "debugMaterialLight"
                                row = renderBox.row()
                                split = renderBox.split()
                                col = split.column()                            
                                col.prop(matlights, "amb_light")
                                row = col.row()
                                
                                #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                matlights.amb_light_int[0] = matlights.amb_light[0]*255
                                matlights.amb_light_int[1] = matlights.amb_light[1]*255
                                matlights.amb_light_int[2] = matlights.amb_light[2]*255
                                row.label(text = "Ambient Light Color: R. %i  G. %i, B. %i" % (matlights.amb_light_int[0], matlights.amb_light_int[1],matlights.amb_light_int[2]))
                                
                                            
                                #row.label(text = "Color: R. %i  G. %i, B. %i" % (matlights.amb_light[0]*255, matlights.amb_light[1]*255,matlights.amb_light[2]*255))
                                
                                row = renderBox.row()
                                #row.prop(matlights, "diffuse_lights", icon = 'LAMP_SPOT')
                                
                                row.prop(matlights, "expand_diffuse", icon = 'LAMP_SPOT')
                                row.label(text = "Click to edit up to 3 Diffuse/Direction lights.") 
                                #if matlights.diffuse_lights == True:
                                if matlights.expand_diffuse == True:
                                    row = renderBox.row()
                                    row.prop(matlights, "qty_lights")                   
                        
                                    if matlights.qty_lights >= 1:   
                                        split = renderBox.split()
                                        col = split.column()                            
                                        col.prop(matlights, "dir_lights")
                                        col.prop(matlights, "light_dir")                                                       
                                        
                                        #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                        matlights.dir_lights_int[0] = matlights.dir_lights[0]*255
                                        matlights.dir_lights_int[1] = matlights.dir_lights[1]*255
                                        matlights.dir_lights_int[2] = matlights.dir_lights[2]*255
                                        #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                        #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                        matlights.light_dir_int[0] = matlights.light_dir[0]*90
                                        matlights.light_dir_int[1] = matlights.light_dir[2]*90
                                        matlights.light_dir_int[2] = matlights.light_dir[1]*90
                                        
                                        row = col.row()
                                        row.label(text = "Color: R. %i  G. %i, B. %i" % (matlights.dir_lights_int[0], matlights.dir_lights_int[1],matlights.dir_lights_int[2]))
                                        row = col.row()
                                        row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matlights.light_dir_int[0], matlights.light_dir_int[1],matlights.light_dir_int[2]))
                                        
                                        if matlights.qty_lights >= 2:                      
                                            col = split.column()    
                                            col.prop(matlights, "dir_lights2")
                                            col.prop(matlights, "light_dir2")   
                                            
                                            #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                            matlights.dir_lights2_int[0] = matlights.dir_lights2[0]*255
                                            matlights.dir_lights2_int[1] = matlights.dir_lights2[1]*255
                                            matlights.dir_lights2_int[2] = matlights.dir_lights2[2]*255
                                            #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                            #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                            matlights.light_dir2_int[0] = matlights.light_dir2[0]*90
                                            matlights.light_dir2_int[1] = matlights.light_dir2[2]*90
                                            matlights.light_dir2_int[2] = matlights.light_dir2[1]*90
                                            
                                            row = col.row()
                                            row.label(text = "Color: R. %i  G. %i, B. %i" % (matlights.dir_lights2_int[0], matlights.dir_lights2_int[1],matlights.dir_lights2_int[2]))
                                            row = col.row()
                                            row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matlights.light_dir2_int[0], matlights.light_dir2_int[1],matlights.light_dir2_int[2]))

                                            if matlights.qty_lights == 3:                      
                                                col = split.column()    
                                                col.prop(matlights, "dir_lights3")
                                                col.prop(matlights, "light_dir3")
                                                
                                                #NOTE ----- The color picker saves these values as floats from 0.0 - 1.0. Convert to int from 0-255 for use with N64.
                                                matlights.dir_lights3_int[0] = matlights.dir_lights3[0]*255
                                                matlights.dir_lights3_int[1] = matlights.dir_lights3[1]*255
                                                matlights.dir_lights3_int[2] = matlights.dir_lights3[2]*255
                                                #NOTE ----- The angle picker saves these values as floats from 0.0 - 1.0. Convert to int from -90 to 90 for use with N64.
                                                #NOTE ----- Export formatting uses is Z up so [1] and [2] are swapped when converted to N64 formatting
                                                matlights.light_dir3_int[0] = matlights.light_dir3[0]*90
                                                matlights.light_dir3_int[1] = matlights.light_dir3[2]*90
                                                matlights.light_dir3_int[2] = matlights.light_dir3[1]*90
                                                
                                                row = col.row()
                                                row.label(text = "Color: R. %i  G. %i, B. %i" % (matlights.dir_lights3_int[0], matlights.dir_lights3_int[1],matlights.dir_lights3_int[2]))
                                                row = col.row()
                                                row.label(text = "Angle: X. %i  Y. %i, Z. %i" % (matlights.light_dir3_int[0], matlights.light_dir3_int[1],matlights.light_dir3_int[2]))

                                else:
                                    if matlights.qty_lights >= 1:
                                        row = renderBox.row()
                                        row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (matlights.dir_lights_int[0], matlights.dir_lights_int[1],matlights.dir_lights_int[2]))
                                        row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir_int[0], matlights.light_dir_int[1],matlights.light_dir_int[2]))
                                        row.enabled = False
                                        if matlights.qty_lights >= 2:
                                            row = renderBox.row()
                                            row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (matlights.dir_lights2_int[0], matlights.dir_lights2_int[1],matlights.dir_lights2_int[2]))
                                            row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir2_int[0], matlights.light_dir2_int[1],matlights.light_dir2_int[2]))
                                            row.enabled = False
                                            if matlights.qty_lights >= 3:
                                                row = renderBox.row()
                                                row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (matlights.dir_lights3_int[0], matlights.dir_lights3_int[1],matlights.dir_lights3_int[2]))
                                                row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir3_int[0], matlights.light_dir3_int[1],matlights.light_dir3_int[2]))
                                                row.enabled = False
                            if matlights.manual_entry == True:
                                row = renderBox.row()                                 
                                row.prop(matlights, "light_struct_name")
                                #matlights.light_struct_name.default_value = "debugMaterialLight"
                                row = renderBox.row()
                                split = renderBox.split()
                                col = split.column()                            
                                col.prop(matlights, "amb_light_int")
                                
                                row = renderBox.row()
                                #row.prop(matlights, "diffuse_lights", icon = 'LAMP_SPOT')
                                
                                row.prop(matlights, "expand_diffuse", icon = 'LAMP_SPOT')
                                row.label(text = "Click to edit up to 3 Diffuse/Direction lights.")                                 

                                if matlights.expand_diffuse == True:
                                    row = renderBox.row()
                                    row.prop(matlights, "qty_lights")                    
                        
                                    if matlights.qty_lights >= 1:                                
                                        split = renderBox.split()
                                        col = split.column()                            
                                        col.prop(matlights, "dir_lights_int")
                                        col.prop(matlights, "light_dir_int")

                                        if matlights.qty_lights >= 2:                      
                                            col = split.column()    
                                            col.prop(matlights, "dir_lights2_int")
                                            col.prop(matlights, "light_dir2_int")   

                                            if matlights.qty_lights == 3:                      
                                                col = split.column()    
                                                col.prop(matlights, "dir_lights3_int")
                                                col.prop(matlights, "light_dir3_int")

                                else:
                                    if matlights.qty_lights >= 1:
                                        row = renderBox.row()
                                        row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (matlights.dir_lights_int[0], matlights.dir_lights_int[1],matlights.dir_lights_int[2]))
                                        row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir_int[0], matlights.light_dir_int[1],matlights.light_dir_int[2]))
                                        row.enabled = False
                                        if matlights.qty_lights >= 2:
                                            row = renderBox.row()
                                            row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (matlights.dir_lights2_int[0], matlights.dir_lights2_int[1],matlights.dir_lights2_int[2]))
                                            row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir2_int[0], matlights.light_dir2_int[1],matlights.light_dir2_int[2]))
                                            row.enabled = False
                                            if matlights.qty_lights >= 3:
                                                row = renderBox.row()
                                                row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (matlights.dir_lights3_int[0], matlights.dir_lights3_int[1],matlights.dir_lights3_int[2]))
                                                row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir3_int[0], matlights.light_dir3_int[1],matlights.light_dir3_int[2]))
                                                row.enabled = False
                                                
                        elif matlights.custom_lights == False:
                            row = renderBox.row()     
                            row.prop(matlights, "light_struct_name")
                            row.enabled = False
  
                    elif matlights.custom_lights == True:
                        row = renderBox.row()
                        row.label(text = "Material Light Structure: %s" % matlights.light_struct_name)
                        row.label(text = "Ambient: R %i, G %i, B %i" % (matlights.amb_light_int[0], matlights.amb_light_int[1],matlights.amb_light_int[2]))
                        row.enabled = False                        
                        if matlights.qty_lights >= 1:
                            row = renderBox.row()
                            row.label(text = "Diffuse Light 1: R. %i,  G. %i, B. %i" % (matlights.dir_lights_int[0], matlights.dir_lights_int[1],matlights.dir_lights_int[2]))
                            row.label(text = "Light Angle 1:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir_int[0], matlights.light_dir_int[1],matlights.light_dir_int[2]))
                            row.enabled = False
                            if matlights.qty_lights >= 2:
                                row = renderBox.row()
                                row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (matlights.dir_lights2_int[0], matlights.dir_lights2_int[1],matlights.dir_lights2_int[2]))
                                row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir2_int[0], matlights.light_dir2_int[1],matlights.light_dir2_int[2]))
                                row.enabled = False
                                if matlights.qty_lights >= 3:
                                    row = renderBox.row()
                                    row.label(text = "Diffuse Light 2: R. %i,  G. %i, B. %i" % (matlights.dir_lights3_int[0], matlights.dir_lights3_int[1],matlights.dir_lights3_int[2]))
                                    row.label(text = "Light Angle 2:   X. %i,  Y. %i, Z. %i" % (matlights.light_dir3_int[0], matlights.light_dir3_int[1],matlights.light_dir3_int[2]))
                                    row.enabled = False    
                    
                    elif matlights.custom_lights == False:
                        row = renderBox.row()
                        row.label(text = "DISABLED: Will not export custom material light structures.")
                        row.enabled = False
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