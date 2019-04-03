/* file : Examrc.h


        Created: 21:55:36 Mon Jun 19 1989

        Description:  Definitions of identifiers used in ExamplPM.rc
                      Declarations of menu functions and dialog functions

        Skeleton by:  WINPRO/PM a product from Louis J. Cutrona, Jr.
                      Skeleton.pm (Revision 2.5)

*/

/* ID assigned to first string */
#define  IDS_FIRSTSTRING 272

/* Count of String Identifiers */
#define  CSTRINGS        3

/* Total characters in strings (including null terminators) */
#define  CCHSTRINGS      36

/* ID's used in .RC file - alphabetical order */
/* Highest ID number assigned is 311 */
/* Next ID available is defined as NEXTID, so */
/* additional ID's can be assigned the value  */
/* NEXTID, NEXTID+1, NEXTID+2, etc.           */

#define  ABOUT                          279
#define  accelF10                       292
#define  DID_FIXEDTEXT                  295
#define  GP_DEFAULTS                    310
#define  GP_FAVORBLACK                  309
#define  GP_FAVORWHITE                  308
#define  GP_FORPRINTER                  306
#define  GP_FORSCREEN                   305
#define  GP_HEIGHT                      302
#define  GP_HSCALE                      303
#define  GP_LOFFSET                     299
#define  GP_PRINT                       307
#define  GP_SIFNAME                     298
#define  GP_TOFFSET                     300
#define  GP_VSCALE                      304
#define  GP_WIDTH                       301
#define  IDD_DIRLIST                    296
#define  IDD_FILEEDIT                   294
#define  IDD_FILELIST                   297
#define  IDD_PATH                       293
#define  IDS_ABOUT                      273
#define  IDS_NAME                       272
#define  IDS_TITLE                      274
#define  midCREATE                      286
#define  midCREATEPROCESS               288
#define  midCREATESCAN                  287
#define  midEDIT                        280
#define  midEDITCLEAR                   285
#define  midEDITCOPY                    283
#define  midEDITCUT                     282
#define  midEDITPASTE                   284
#define  midEDITRESTORE                 281
#define  midFILE                        275
#define  midFILENEW                     276
#define  midFILEOPEN                    277
#define  midFILESAVE                    278
#define  midHELP                        291
#define  midQUERYEXIT                   289
#define  MID_EXIT                       290
#define  PRINTERABORT                   311

/* The first available ID number (one greater than highest assigned) */
#define  NEXTID           312


/* Forward declarations of menu functions */
ULONG midFILENEWFunction( PUSHORT pmsg ) ;
ULONG midFILEOPENFunction( PUSHORT pmsg ) ;
ULONG midFILESAVEFunction( PUSHORT pmsg ) ;
ULONG ABOUTFunction( PUSHORT pmsg ) ;
ULONG midEDITRESTOREFunction( PUSHORT pmsg ) ;
ULONG midEDITCUTFunction( PUSHORT pmsg ) ;
ULONG midEDITCOPYFunction( PUSHORT pmsg ) ;
ULONG midEDITPASTEFunction( PUSHORT pmsg ) ;
ULONG midEDITCLEARFunction( PUSHORT pmsg ) ;
ULONG midCREATESCANFunction( PUSHORT pmsg ) ;
ULONG midCREATEPROCESSFunction( PUSHORT pmsg ) ;
ULONG MID_EXITFunction( PUSHORT pmsg ) ;
ULONG midHELPFunction( PUSHORT pmsg ) ;
ULONG accelF10Function( PUSHORT pmsg ) ;


/* Forward declarations of functions */

/* Routines in _TEXT segment */
MRESULT  EXPENTRY ExamplPMWndProc( HWND, USHORT, MPARAM, MPARAM );
BOOL     fExamplPMClose( void );

/* Routines in _APPINIT segment */
BOOL     InitStrings( HAB );
BOOL     ExamplPMInit();

/* Routines in _APPDLG segment */

/* Forward declarations of dialog functions */
MRESULT EXPENTRY ABOUTDlgWndProc( HWND, USHORT, MPARAM, MPARAM ) ;
MRESULT EXPENTRY midFILEOPENDlgWndProc( HWND, USHORT, MPARAM, MPARAM ) ;
MRESULT EXPENTRY midCREATEPROCESSDlgWndProc( HWND, USHORT, MPARAM, MPARAM ) ;
MRESULT EXPENTRY PRINTERABORTDlgWndProc( HWND, USHORT, MPARAM, MPARAM ) ;


/* For ease of updating, put additional definitions and declarations */
/* after this point.  That way, if you run Winpro/PM again, you can  */
/* just copy everything after this point into the new Examrc.h       */




/*   E N D   O F   E X A M R C . H   */
