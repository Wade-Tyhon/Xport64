# Xport64
A Blender plug-in for exporting models as N64 display lists. Supports Blender 2.70-2.79 using Cycles Renderer. 2.8+ compatability coming soon. 

*READ BEFORE USING:* This is a BRAND NEW add-on and thus has not been thoroughly tested by other users yet. It is highly recommended that you initially work with a duplicate of your project to make sure nothing in this add-on breaks your project.

## Enabling on Blender 2.70-2.79 w/ Windows:

1) If Blender is currently running, close it before beginning this process. 

2) Once Blender is closed, drop the root folder of this project *io_xport64* into the addons folder of any 2.7 version of blender. 
*Ex. on Windows: C:\Program Files\Blender Foundation\blender-2.79b-windows64\2.79\scripts\addons*

3) Once *io_xport64* is placed the add ons folder, open up Blender. Navigate to *File > User Preferences > Add-ons*.

4) From the search bar at the top of the preferences window, search for *xport64*. Once it appears, hit the checkbox to enable the plug-in 



## Tips on Utilizing This Add-On:

*READ BEFORE USING:* This is a BRAND NEW add-on and thus has not been thoroughly tested by other users yet. It is highly recommended that you initially work with a duplicate of your project to make sure nothing in this add-on breaks your project.

1) To work properly, this project must:
  - Use Cycles Mode and use Nodes and Materials to properly export.
  - Have at least one Mesh object in your scene.
  - Have at least one assigned material on your object.
  - Have nodes enabled.
2) Currently, negative S,T values are not supported due to limitations with ModifyVertex. But I am looking into a solution for this. 
3) When texturing, keep in mind that S,T coordinates on N64 work slightly differently than UV coordinates in Blender. The Y value is flipped so that +1 becomes -1 on N64. Just keep this in mind when texturing.
4) Greatest compatability is with Blender 2.79 since it is the most fully featured when it comes to using Vertex Colors (very important with N64 development!) If you are using Windows 10, I recommend 2.79. If you are developing in Windows XP, I recommend 2.76.

## Known errors addressed in the most recent version:
- Negative UV coordinates are not currently supported becaues of the use of Modify Vertex requiring hex values.
- Fixed error where obj light name was triggering a duplicate light name for material lights, unusedLight variable is now re-set with every material check. 
- Added some guidance to plug-in on what is needed to properly export. If no material or node is present, an error should be thrown. 
- Fixed collision export bug caused by old code not being completely scrubbed. In previous build, some faces in a collision object would not export.

## New Features Added:
- Added new UI updates 
- Added new DEBUG and error messages
- Added new object rig options to use default Xport64 rig or to include your own command
- Updated Scene/Obj/Mat light interface to optionally enter your values manually

## Known errors soon to be addressed:

