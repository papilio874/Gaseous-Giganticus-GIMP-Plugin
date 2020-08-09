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

// - - - - - ◊ PUT ALL DEFINITIONS HERE ◊ - - - - - //

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

// - - - - - ◊
static gint32
gaseous_giganticus (GimpDrawable *drawable,
                    gint32       *layer_id) //MUST be ordered: generate >> create new images for cubemap faces > apply generated map to cubemap in order to assure seamlessness
}
  gint32 new_image_id_pos_z
  GimpDrawable *new_layer
  //????
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: NEGATIVE Z (SOUTH POLE) ◊ - - - - - ◊ - - - - - // //maps to image "0" in forum post and original image output
  new_image_id_neg_z = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  //...
  return new_image_id_neg_z;
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: POSITIVE X (EQUATOR QUADRANT 1) ◊ - - - - - ◊ - - - - - // //maps to image "1" in forum post and original program output.
  new_image_id_pos_x = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  //...
  return new_image_id_pos_x;
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: POSITIVE Z (NORTH POLE) ◊ - - - - - ◊ - - - - - //  //maps to image "2" in forum post and original program output
  new_image_id_pos_z = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  //...
  return new_image_id_pos_z;
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: NEGATIVE X (EQUATOR QUADRANT 3) ◊ - - - - - ◊ - - - - - // //maps to image "3" in forum post
  new_image_id_neg_x = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  //...
  return new_image_id_neg_x;
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: POSITIVE Y (EQUATOR QUADRANT 2) ◊ - - - - - ◊ - - - - - // //maps to image "4"
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: NEGATIVE Y (EQUATOR QUADRANT 4) ◊ - - - - - ◊ - - - - - // //maps to image "5"
  
}

// - - - - - ◊ - - - - - ◊ GIMP PLUGIN USER INTERFACE ◊ - - - - - ◊ - - - - - //
