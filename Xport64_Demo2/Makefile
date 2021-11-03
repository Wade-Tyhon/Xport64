include $(ROOT)/usr/include/make/PRdefs

N64KITDIR   = C:\nintendo\n64kit
NUSYSINCDIR = $(N64KITDIR)/nusys/include
NUSYSLIBDIR = $(N64KITDIR)/nusys/lib

NUSTDINCDIR = $(N64KITDIR)/nustd/include
NUSTDLIBDIR = $(N64KITDIR)/nustd/lib

LIB = $(ROOT)/usr/lib
LPR = $(LIB)/PR
INC = $(ROOT)/usr/include
CC  = gcc
LD  = ld
MAKEROM = mild

OBJDIR    := bin

DIRS = sprites

INCDIR = include
HFILES = $(foreach DIR,$(DIRS), $(wildcard $(INCDIR)/$(DIR)/*.h) $(wildcard $(INCDIR)/*.h))

SRCDIR = src
CODEFILES = $(foreach DIR,$(DIRS), $(wildcard $(SRCDIR)/$(DIR)/*.c)) $(wildcard $(SRCDIR)/*.c) 

PLAYERDIR := src/player
PLAYERDIRS := plrmesh plranimr plrtex
PLAYERFILES := $(foreach DIR,$(PLAYERDIRS),$(wildcard $(PLAYERDIR)/$(DIR)/*.c))

ENGINEDIR := src/engine
ENGINEDIRS := tools gfxsettings debug mainfunc collisions
ENGINEFILES := $(foreach DIR,$(ENGINEDIRS),$(wildcard $(ENGINEDIR)/$(DIR)/*.c))

SCENEDIR := src/scenes
SCENEDIRS := level00
SCENEFILES := $(foreach DIR,$(SCENEDIRS),$(wildcard $(SCENEDIR)/$(DIR)/*.c))

# ENEMYDIR := src/enemies
# ENEMYDIRS := spikeyspawn
# ENEMYFILES := $(foreach DIR,$(ENEMYDIRS),$(wildcard $(ENEMYDIR)/$(DIR)/*.c))

TEXTUREDIR = src/textures
TEXTUREFILES = $(foreach DIR,$(DIRS), $(wildcard $(TEXTUREDIR)/$(DIR)/*.c)) $(wildcard $(TEXTUREDIR)/*.c) 

AUDIODIR = src/audio
AUDIODIRS = controller
AUDIOFILES = $(foreach DIR,$(AUDIODIRS),$(wildcard $(AUDIODIR)/$(DIR)/*.c))

SUBDIR = src/scenes/level00/testsubfolder
SUBFILES = $(foreach DIR,$(DIRS),$(wildcard $(SUBDIR)/$(DIR)/*.c)) $(wildcard $(SUBDIR)/*.c) 

LCDEFS = -DNU_DEBUG -DF3DEX_GBI_2
LCINCS = -I$(NUSYSINCDIR) -I$(ROOT)/usr/include/PR -I$(INCDIR)
#LCOPTS = -G 0 -o $@
LCOPTS = -G 0 -O3 -ffast-math -o $@
#LCOPTS = -G 0 -O1 -o $@

NUAUDIOLIB = -lnualstl_n_d -ln_gmus_d -ln_gaudio_sc

LDFLAGS = $(MKDEPOPT) -L$(LIB) -L$(NUSTDLIBDIR) -L$(NUSYSLIBDIR) $(NUAUDIOLIB) -lnusys_d -lnustd_d -lgultra_d -L$(GCCDIR)/mipse/lib -lkmc

OPTIMIZER =	-g

BIN_PATH := bin/
OBJ_PATH = bin/objects/

APP = $(BIN_PATH)3rdPersonDemo.out

TARGETS = $(BIN_PATH)3rdPersonDemo.n64

CODEOBJECTS:= $(PLAYERFILES:.c=.o) $(ENGINEFILES:.c=.o) $(SCENEFILES:.c=.o) $(ENEMYFILES:.c=.o) $(TEXTUREFILES:.c=.o) $(AUDIOFILES:.c=.o) $(SUBFILES:.c=.o) $(NUSYSLIBDIR)/nusys.o

CODESEGMENT = codesegment.o
CODESEGMENT_B = $(BIN_PATH)codesegment.o

default: $(TARGETS)

include $(COMMONRULES)

$(CODESEGMENT):	$(CODEOBJECTS) Makefile		
		$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(TARGETS):	$(CODESEGMENT) 
		$(MAKEROM) spec -I$(NUSYSINCDIR) -s 32 -r $(TARGETS) -e $(APP)
		makemask $(TARGETS)
