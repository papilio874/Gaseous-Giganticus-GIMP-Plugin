// - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - //
//
//
//
// - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - //
//
// - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - //

// - - - - - ◊ Gimp-Derived Required Libraries ◊ - - - - - //
#include <libgimp/gimp.h>
#include <libgimp/gimpui.h>

// - - - - - ◊ Ubuntu-Derived Required Libraries ◊ - - - - - // // TODO: find Ubuntu sources for all necessary, extract and copy libraries to this repository, then come back here and replace the greater-than and less-than symbols with quotation marks.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <getopt.h>
#include <locale.h>
#include <sys/time.h>

// - - - - - ◊ XYZ Required Libraries ◊ - - - - - // // TODO: clone-add these to the source folder.
#include "mtwist.h"
#include "mathutils.h"
#include "quat.h"
#include "open-simplex-noise.h"
#include "png_utils.h"
#include "pthread_util.h"

// - - - - - ◊ - - - - - ◊ GIMP PLUGIN PREREQUISITES ◊ - - - - - ◊ - - - - - //

// - - - - - ◊ Delare local functions ◊ - - - - - //
static void


// - - - - - ◊ GIMP Plugin Information ◊ - - - - - //
const GimpPlugInInfo PLUG_IN_INFO =
{
  NULL,    // Initialization Procedure
  NULL,    // Quit Procedure
  query,   // On-Plugin-Startup Procedure
  run,     // Actual Program Procedure
};

// - - - - - ◊ - - - - - ◊ GIMP PLUGIN PROGRAM ◊ - - - - - ◊ - - - - - //

// - - - - - ◊ - - - - - ◊ GIMP PLUGIN USER INTERFACE ◊ - - - - - ◊ - - - - - //
