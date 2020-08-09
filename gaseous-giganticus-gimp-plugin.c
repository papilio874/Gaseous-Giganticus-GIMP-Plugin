// - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - //
//
//
//
// - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - //
//
// - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - ◊ - - - - - //

#include <libgimp/gimp.h>
#include <libgimp/gimpui.h>

// TODO: add remaining necessary included file callups here

// TODO: add remaining necessary include file callups here

//typedef struct

// - - - - - ◊ beep-boop idk ◊ - - - - - //
MAIN()

static void query (void)
{
    static GimpParamDef args[] =
    {
        {
            GIMP_PDB_INT32,
            "run-mode",
            "Run mode"
        },
        
        {
            GIMP_PDB_IMAGE,
            "image",
            "Input image"
        },
    }
    
    //gimp install procedure
    
    // - - - - - ◊ LOCATION IN TOOLBAR MENU ◊ - - - - - //
    gimp_plugin_menu_register("plug-in-gaseous-giganticus-simple", "<Image>/Filters/@)
    
} // come back to
