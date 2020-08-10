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
// add static "run" at top,

//add process definitions here (each of the "static void xyz()" parsers)
static struct osn_context *ctx;

#define NPARTICLES 8000000
static int particle_count = NPARTICLES;

static int nthreads = 4;
//TODO: add what is necessary here

// COMMENTED OUT BECAUSE DEFINITION IS RECEIVED FROM THE INPUTS GIVEN TO THE UI
//#define DIM 1024 /* dimensions of cubemap face images */ //This is replaced by "config.cubemap_dimension" to make this property available to change in the user interface.
//#define VFDIM 2048 /* dimension of velocity field. (2*DIM) is reasonable */ //This will also be dealt with later once we know where "config.cubemap_dimension" is defined.
//static int vfdim = VFDIM; commented out due to dependency on above
//#define FDIM ((float) (DIM)) see above
//#define XDIM DIM same
//#define YDIM DIM same again

static int niterations = 1000;
//add what you need

// INPUT IMAGE PARAMETER-FINDER?
//static char *start_image
//

// - - - - - ◊ define color

// - - - - - ◊ Cubemap Coordinate System (face, i, j) ◊ - - - - - //
struct fij {
  int f, i, j;
};

// - - - - - ◊ Define what a particle is, that it has color, and that it exists on the surface of a sphere ◊ - - - - - //
static struct particle {
  union vec3 pos;
  struct color c;
  struct fij fij;
} *particle



//?

// - - - - - ◊ - - - - - ◊ ACTUAL PROGRAM DOODAD
// PAINT PARTICLE

static void paint_particle(int face, int i, int j, struct color *c, const int octaves)
{
  unsigned char *pixel;
  int p;
  struct color old_color, new_color; //replace "oc" and "nc" with "old_color" and "new_"color" respectively for ease of use
  float (*const noise)(float x, float y, float z, float w) = fbmnoise4[octaves];
  
  // first "if" statement goes here
  
  //define p, pixel
#if 0


#else
  // maybe find more efficient method
  old_color.red = (float) pixel[0] / 255.0f; //convert the old-colored-pixel's red value (specified in *pixel as pixel[0]) from 255-based to percentage-based
  old_color.green = (float) pixel[1] / 255.0f; // convert the old-colored-pixel's green value (specified in *pixel as pixel[1]) from 255-based to percentage-based
}

// - - - - - ◊ run the process in order on the input image, then create the blank cubemap face images, then paint the generated cubemap faces on their requisite images. ◊
static gint32
gaseous_giganticus (GimpDrawable *drawable,
                    gint32       *layer_id) // these probably refence the input image. //MUST be ordered: generate >> create new images for cubemap faces > apply generated map to cubemap in order to assure seamlessness
{
  gint32 new_image_id_neg_z;
  GimpDrawable *new_layer_neg_z;
  //add rest of neg-z specific declarations here
  gint32 new_image_id_pos_x;
  GimpDrawable *new_layer_pos_x;
  //add rest of positive x specific declarations here
  gint32 new_image_id_pos_z;
  GimpDrawable *new_layer_pos_z;
  //add rest of positive z specific declarations here
  gint32 new_image_id_neg_x;
  GimpDrawable *new_layer_neg_x;
  //add rest of negative x specific declarations here
  gint32 new_image_id_pos_y;
  GimpDrawable *new_layer_pos_y;
  //add rest of positive y specific declarations here
  gint32 new_image_id_neg_y;
  GimpDrawable *new_layer_neg_y
  // add rest of necessary declarations here  
  
    
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: NEGATIVE Z (SOUTH POLE) ◊ - - - - - ◊ - - - - - // //maps to image "0" in forum post and original image output
  // - - - - - ◊ Create new blank image for this face of the cubemap ◊ - - - - - //
  new_image_id_neg_z = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  gimp_image_undo_disable (new_image_id_neg_z);
  *layer_id_neg_z = gimp_layer_new (new_image_id_neg_z, _("Cubemap Face: Negative Z (South Pole)"),
                                    config.cubemap_dimension, config.cubemap_dimension,
                                    gimp_drawable_type (drawable->drawable_id),
                                    100, GIMP_NORMAL_MODE);
  gimp_image_insert_layer (new_image_id_neg_z, *layer_id_neg_z, -1, 0);
  new_layer_neg_z = gimp_drawable_get (*layer_id_neg_z);
  
  // - - - - - ◊ Apply the requisite generated cubemap face (generate vortices ahead of this step and apply them to the cubemap first) to the layer ◊ - - - - - //
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
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: NEGATIVE X (EQUATOR QUADRANT 3) ◊ - - - - - ◊ - - - - - // //maps to image "3" in forum post and original program output
  new_image_id_neg_x = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  //...
  return new_image_id_neg_x;
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: POSITIVE Y (EQUATOR QUADRANT 2) ◊ - - - - - ◊ - - - - - // //maps to image "4" in forum post and original program output
  new_image_id_pos_y = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  //...
  return new_image_id_pos_y;
  
  // - - - - - ◊ - - - - - ◊ CREATE CUBEMAP FACE: NEGATIVE Y (EQUATOR QUADRANT 4) ◊ - - - - - ◊ - - - - - // //maps to image "5" in forum post and original program output
  new_image_id_neg_y = gimp_image_new (config.cubemap_dimension, config.cubemap_dimension, GIMP_RGB);
  //...
  return new_image_id_neg_y;
}//?
// - - - - - ◊ - - - - - ◊ GIMP PLUGIN USER INTERFACE ◊ - - - - - ◊ - - - - - //
static gboolean
dialog (GimpDrawable *drawable)
{
  // put declarations here
  //...
  
  run = (gimp_dialog_run (GIMP_DIALOG (dlg)) == GTK_RESPONSE_OK);
  
  if (run)
  {
    config.cubemap_dimension = gimp_size_entry_get_refval (GIMP_SIZE_ENTRY ( TODO ),
                                                           0);
  }

  gtk_widget_destroy (dlg);
  
  return run;
}
