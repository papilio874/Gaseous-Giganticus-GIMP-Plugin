// GASEOUS-GIGANTICUS PLUGIN-PORT FOR GIMP

// - - - - - ◊ - - - - - ◊ - - - - - ◊ INCLUDE NECESSARY LIBRARIES ◊ - - - - - ◊ - - - - - ◊ - - - - - //
// - - - - - ◊ C-language Universal Libraries ◊ - - - - - //
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

// - - - - - ◊ GIMP Plug-in Required Libraries ◊ - - - - - //
#include <libgimp/gimp.h>
#include <libgimp/gimpui.h>

#include "libgimp/stdplugins-intl.h"
#include "config.h"

// - - - - - ◊ Local Required Libraries ◊ - - - - - //
#include "mtwist.h"
#include "mathutils.h"
#include "quat.h"
#include "open-simplex-noise.h"
#include "png_utils.h"
#include "pthread_util.h"


// - - - - - ◊ - - - - - ◊ - - - - - ◊ DEFINE PLUG-IN DESCRIPTORS ◊ - - - - - ◊ - - - - - ◊ - - - - - //
#define PLUG_IN_PROC   "plug-in-gaseous-giganticus"
#define PLUG_IN_BINARY "gaseous-giganticus"
#define PLUG_IN_ROLE   "gimp-gaseous-giganticus"


// - - - - - ◊ - - - - - ◊ - - - - - ◊ DECLARE LOCAL FUNCTIONS ◊ - - - - - ◊ - - - - - ◊ - - - - - //
static void     query              (void);

static void     run                (const gchar      *name,
                                    gint              nparams,
                                    const GimpParam  *param,
                                    gint             *nreturn_vals,
                                    GimpParam       **return_vals);

static gboolean dialog             (GimpDrawable     *drawable);

static gint32   gaseous_giganticus (GimpDrawable     *drawable,
                                    gint32           *layer_id);


// - - - - - ◊ - - - - - ◊ - - - - - ◊ PLUG-IN EXECUTION INFORMATION ◊ - - - - - ◊ - - - - - ◊ - - - - - //
const GimpPlugInInfo PLUG_IN_INFO =
{
  NULL,  //This is where any sub-program that needs to be executed upon startup of the GIMP application would be called for.
  NULL,  //This is where any sub-probram that needs to be executed upon quitting the GIMP application would be called for.
  query, //This instructs the computer to execute the "query" sub-program when the plug-in is being "loaded" into the GIMP application on startup. The "query" sub-program instructs the computer where to make the plug-in available to be selected in the primary GIMP application user interface, provides flavor text that describes the plug-in in question, and allocates names to be used in the UI. 
  run,   //This instructs the computer to execute the "run" sub-program when the plug-in is selected by the user. The "run" sub-program details the steps the computer will take to achieve the desired end result and builds the framework for the pop-up UI window that allows for configuration of the program's input parameters.
};

// - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ MAIN ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - //
MAIN ()

// - - - - - ◊ - - - - - ◊ - - - - - ◊ DEFINE SUB-PROGRAM "QUERY" ◊ - - - - - ◊ - - - - - ◊ - - - - - //
static void
query (void)
{
  static const GimpParamDef args[] =
  {
    { GIMP_PDB_INT32,    "run-mode", ~ "The run mode { RUN-INTERACTIVE (0), RUN-NONINTERACTIVE (1) }" },
    { GIMP_PDB_IMAGE,    "image", ~ "Input image (unused)"            },
    { GIMP_PDB_DRAWABLE, "drawable", ~ "Input drawable"              },
    { GIMP_PDB_INT32,    "cubemap-dimension", ~ "Cubemap Face Edge Length (pixels)"   },
    { GIMP_PDB_INT32,    "pole-attenuation", ~ "Pole-Attenuation Factor" },
    { GIMP_PDB_INT32,    "bands", ~ "Number of Counter-Rotating Bands" }
    { GIMP_PDB_INT32,    "", ~ "
    { //COME BACK TO HERE
  };
    
  static const GimpParamDef return_vals[]
  {
    { GIMP_PDB_IMAGE, 
    //COME BACK TO HERE
  };
  
  // - - - - - ◊ GIMP INSTALLATION PROCEDURE ◊ - - - - - //
  gimp_install_procedure (PLUG_IN_PROC,
                          N_("Apply a curl noise-based fluid flow simulation velocity field to the image to generate the 6 faces of a cubemap of a gas planet."),
                          "help!",
                          "Stephen M. Cameron, ported to GIMP by Douglas Wallwey",
                          "Stephen M. Cameron, ported to GIMP by Douglas Wallwey",
                          "2020"
                          N_("Gaseous Giganticus..."),
                          "RGB*"
                          G_N_ELEMENTS (args), G_N_ELEMENTS (return_vals),
                          args, return_vals);
  
  // - - - - - ◊ PLUGIN LOCATION IN TOOLBAR MENU ◊ - - - - - //
  gimp_plugin_menu_register (PLUG_IN_PROC, "<Image>/Filters/Map"//
}
