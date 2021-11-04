# Xport64
A Blender plug-in for exporting models as N64 display lists. Supports Blender 2.70-2.79 using Cycles Renderer. 2.8+ compatability coming soon. 

*READ BEFORE USING:* This is a BRAND NEW add-on and thus has not been thoroughly tested with multiple workflows. It is highly suggested that you initially work with a duplicate of your project to make sure nothing in this add-on breaks your project.

**Enabling on Blender 2.70-2.79 w/ Windows:**

1) If Blender is currently running, close it before beginning this process. 

2) Once Blender is closed, drop the root folder of this project *io_xport67* into the addons folder of any 2.7 version of blender. 
*Ex. on Windows: C:\Program Files\Blender Foundation\blender-2.79b-windows64\2.79\scripts\addons*

3) Once in the add ons folder, open up Blender. Navigate to *File > User Preferences > Add-ons*.

4) From the search bar at the top of the preferences window, search for *xport64*. Once it appears, hit the checkbox to enable the plug-in 

**Tips on Utilizing This Add-On:**

*READ BEFORE USING:* This is a BRAND NEW add-on and thus has not been thoroughly tested with multiple workflows. It is highly suggested that you initially work with a duplicate of your project to make sure nothing in this add-on breaks your project.

1) To work properly, this project must:
  - Use Cycles Mode and use Nodes and Materials to properly export.
  - Have at least one Mesh object in your scene.
  - Have at least one assigned material on your object.
  - Have nodes enabled.
2) When texturing, keep in mind that S,T coordinates on N64 work slightly differently than UV coordinates in Blender. The Y value is flipped so that +1 becomes -1 on N64. Just keep this in mind when texturing.
3) Currently, negative S,T values are not supported due to limitations with ModifyVertex. But I am looking into a solution for this. 

**Known errors soon to be addressed: **
1) Trying to export before project is fully set up with a material and nodes, the plug-in will stop the export process. I'll be adding a warning to the next build to avoid this happening. 
Temporary solution: If either of these happen to you, it should not harm your project. But it might have 'triangulated' your project already if your model was in quads. *If this does happen to you, simply 'undo' after the exporter exits early.* 
Perminate solution: This will be addressed in the next commit to check before triangulation and finish the export before it begins.
3) Negative UV coordinates are not currently supported becaues of the use of Modify Vertex requiring hex values.
Temporary solution: While your Blender project will export correctly, it will not compile in your N64 project. Simply return to your Blender project, adjust the coordinates and re-export.
Perminate solution: I am looking into updating this with a solution or a warning in the next version. 
