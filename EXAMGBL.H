/* file : Examgbl.h


        Created: 21:55:38 Mon Jun 19 1989

        Description:  Definitions of global external data identifiers
                      used in ExamplPM.rc

        Skeleton by:  WINPRO/PM a product from Louis J. Cutrona, Jr.
                      Skeleton.pm (Revision 2.5)  

*/

/* To actually define the variables, the preprocessor symbol EXTGEN   */
/* is defined.  This is only done in one routine: Examext.c.  Do not  */
/* define it in any other routine.  Other routines should #include    */
/* this header file but should not define EXTGEN                      */ 

#ifdef EXTGEN
#define EXT     /* */
#else
#define EXT     extern
#endif

/* Note that when EXTGEN is defined, the preprocessor symbol EXT      */
/* becomes null and the variable it precedes is actually defined.     */
/* When EXTGEN is not defined, the preprocessor symbol EXT becomes    */
/* the "extern" keyword and the variable it precedes is declared, but */
/* not defined.  Thus, external symbols need only be described once   */
/* in this file and you don't have to worry about maintaining two     */
/* separate files (one with definitions and one with declarations)    */
/* for your globals.                                                  */

/* Define array of pointers to resource strings read in by InitStrings */
EXT NPSZ     gbl_pszStrings[ CSTRINGS ];

/* Define macro to enable reference to gbl_pszStrings via string id */
#define gbl_psz(n) gbl_pszStrings[ n - IDS_FIRSTSTRING ]

/* Within the application, to reference a string from the resource    */
/* file, use the above-defined macro.  If the symbol referring to the */
/* string is MYSTRING, the expression "gbl_psz( MYSTRING )" will give */
/* you a pointer to the string you want.                              */

EXT HAB      gbl_hab;             /* Anchor block handle */
EXT HMQ      gbl_hmqExamplPM;      /* Message queue handle */
EXT HHEAP    gbl_hheap;           /* handle to local heap */
EXT HWND     gbl_hwndApp;         /* Application's main window */
EXT HWND     gbl_hwndAppFrame;    /* Window frame handle */
EXT HWND     gbl_hwndMenu;        /* Window's action bar window handle */
EXT HSWITCH  gbl_hswitch;         /* Handle to Task Manager switch list entry */
EXT QMSG     gbl_qmsg;            /* Current message in the queue */   
EXT HPOINTER gbl_curArrow;        /* Arrow cursor */
EXT HPOINTER gbl_curWait;         /* Hourglass cursor */
EXT HPOINTER gbl_hptrStd;         /* Default icon */
EXT HACCEL   gbl_hAccelTable;     /* Application's accelerator table */
EXT HWND     gbl_hDlg;            /* Currently active dialog window */


/* The following global variables are used to record    */
/* the state of all of the controls in the dialog boxes */
/* defined in the .RC file.  When the dialogs are       */
/* activated, these values initialize the controls.     */


/* Entry text */
EXT   CHAR    gbl_szIDD_PATH[ 40 ]
#if defined( EXTGEN )
= ""
#endif
;

/* Entry text */
EXT   CHAR    gbl_szIDD_FILEEDIT[ 40 ]
#if defined( EXTGEN )
= "*.img"
#endif
;

/* Entry text */
EXT   CHAR    gbl_szGP_SIFNAME[ 40 ]
#if defined( EXTGEN )
= "TEMP.SIF"
#endif
;

/* Entry text */
EXT   CHAR    gbl_szGP_LOFFSET[ 40 ]
#if defined( EXTGEN )
= "0.00"
#endif
;

/* Entry text */
EXT   CHAR    gbl_szGP_TOFFSET[ 40 ]
#if defined( EXTGEN )
= "0.00"
#endif
;

/* Entry text */
EXT   CHAR    gbl_szGP_WIDTH[ 40 ]
#if defined( EXTGEN )
= "0.00"
#endif
;

/* Entry text */
EXT   CHAR    gbl_szGP_HEIGHT[ 40 ]
#if defined( EXTGEN )
= "0.00"
#endif
;

/* Entry text */
EXT   CHAR    gbl_szGP_HSCALE[ 40 ]
#if defined( EXTGEN )
= "1.00"
#endif
;

/* Entry text */
EXT   CHAR    gbl_szGP_VSCALE[ 40 ]
#if defined( EXTGEN )
= "1.00"
#endif
;

/* Id of currently selected radio button */
EXT   SHORT   gbl_sGP_FORSCREEN_to_GP_PRINT
#if defined( EXTGEN )
= GP_FORSCREEN  /* Initially, first radio button is selected */
#endif
;

/* State of checkbox */
EXT   SHORT   gbl_sGP_FAVORWHITE
#if defined( EXTGEN )
= 0  /* initially off (not checked) */
#endif
;

/* State of 3-state checkbox */
EXT   SHORT   gbl_sGP_FAVORBLACK
#if defined( EXTGEN )
= 0  /* initially off (not checked) */
#endif
;


/* For ease of updating, put additional definitions and declarations */
/* after this point.  That way, if you run Winpro/PM again, you can  */
/* just copy everything after this point into the new Examgbl.h      */




/*   E N D   O F   E X A M G B L . H   */
