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

// TODO: typedef struct???

// - - - - - ◊ - - - - - ◊ GIMP PLUGIN PREREQUISITES ◊ - - - - - ◊ - - - - - //
static void query (void);
static void run (@@@)

static void (???)
    
    
GimpPlugInInfo PLUG_IN_INFO =
{
    NULL,
    NULL,
    query,
    run
}
// - - - - - ◊ - - - - - ◊ GIMP PLUGIN CODE ◊ - - - - - ◊ - - - - - //
MAIN()


// - - - - - ◊ TODO: static struct osn_context?? and definitions through magic_fluid_flow go here ◊ - - - - - //

// - - - - - ◊ Output Cubemap Dimensions Definitions ◊ - - - - - //
#define DIM 2048    // This is the dimension in pixels (hence the name DIM) of each of the edges of the output cubemap faces. For a final texture that is 8192 pixels wide by 4096 pixels tall, the input number here should ideally be 2048, 1/4th the desired width of the final texture.
#define VFDIM 4096    // This is the dimension of the velocity field (hence VF in VFDIM) used to simulate fluid flow. It is recommended that this value be equal to 2 × DIM.

static int vfdim = VFDIM;    // This line creates an integer value variable named "vfdim" with the same value as VFDIM has been defined as for ease of use in the code.

#define FDIM ((float) (DIM))    // This line creates another variable, this time a floating-point one, that has the same numerical value as DIM, so that it can be used where a floating-point variable is requiored
