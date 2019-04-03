/* file : Examinit.c


        Created: 21:55:45 Mon Jun 19 1989

        Description:  Initialization routines for ExamplPM
                      These routines are in a separate segment and may be
                      discarded after the applicatione is initialized.

        Skeleton by:  WINPRO/PM, a product from Louis J. Cutrona, Jr.
                      Skeleton.pm (Revision 2.5)  
*/


/* Activate standard window management definitions and typedefs */
#define  INCL_WIN       1

#include <os2.h>

#include "Examrc.h"
#include "Examgbl.h"


/* I N I T  S T R I N G S */  /* Get all text strings from the resource file */
BOOL InitStrings( hAB )
HAB  hAB;
{
   NPCH    npchMem;
   NPSZ    npsz;
   SHORT   cchRemaining;
   USHORT  i;
   SHORT   cch;

   npchMem = WinAllocMem(
      gbl_hheap,
      (USHORT) (cchRemaining = CCHSTRINGS)
      );
   if( ! npchMem )
      return( FALSE );

   npsz = npchMem ;
   for( i = IDS_FIRSTSTRING; i < IDS_FIRSTSTRING + CSTRINGS; i++ )
   {
        cch = 1 + WinLoadString( hAB, (HMODULE) 0,
            i, cchRemaining, (PSZ) npsz );
        gbl_pszStrings[ i - IDS_FIRSTSTRING ] = npsz;
        npsz += cch;
        cchRemaining -= cch;
   }
   WinReallocMem( gbl_hheap, npchMem,
      CCHSTRINGS, (USHORT) (CCHSTRINGS - cchRemaining) );
   return( TRUE );
}

/* Structure to be used when adding "About..." to system menu */
static MENUITEM menuitem[ 2 ] =
{
   MIT_END, MIS_SEPARATOR, 0, 0,     (ULONG) 0, (ULONG) 0,
   MIT_END, MIS_TEXT,      0, ABOUT, (ULONG) 0, (ULONG) 0
} ;

/*   E X A M P L  P  M   I N I T */  /* Procedure called when the application is loaded */
BOOL    ExamplPMInit()
{
   /* Variables needed for adding "About..." to the system menu */
   HWND     hSysMenu;
   SHORT    i;
   SHORT    idSysMenu;
   MENUITEM miSysMenu;
   ULONG    CtlData;

   /* Create the local heap */
   /* Initial size will be HEAPSIZE from .DEF file */
   /* Default size of increments if more space is needed is 512 bytes */
   if( ! ( gbl_hheap = WinCreateHeap( 0, 0, 0, 0, 0, HM_MOVEABLE ) ) )
      return FALSE ;

   /* Load strings from string table */
   if( ! InitStrings( gbl_hab ) )
      return FALSE ;

   /* Register window class */
   if( ! WinRegisterClass( gbl_hab,
           (PSZ) gbl_psz( IDS_NAME ),   /* Class name */
           (PFNWP) ExamplPMWndProc,      /* Window function for class */
           (ULONG) 0L,                  /* Class style bits */
           (USHORT) 0                   /* Count of extra bytes for each */
                                        /*  window instance in the class */
           )
     )
      return FALSE;

   /* Fill in additional style bits for frame window */     
   CtlData = FCF_STANDARD & ~FCF_TASKLIST ;

   gbl_hwndAppFrame = WinCreateStdWindow(
      HWND_DESKTOP,                 /* Parent window handle */
      WS_VISIBLE,                   /* Frame window style bits */
      (PVOID) &CtlData,             /* Pointer to more style info */
      (PSZ) gbl_psz( IDS_NAME ),    /* Client window class name */
      (PSZ) NULL,                   /* Caption text (NULL uses .EXE file name */
      0L,                           /* Client style bits */
      (HMODULE) 0,                  /* Resource module id: 0 means .EXE file */
      IDS_NAME,                     /* Menu, Accel, Icon Identifier */
      (HWND FAR *) &gbl_hwndApp     /* Handle for client window */
      );


   /* According to the documentation, we should be able to set the title */
   /* text by specifying a non-null caption text pointer in the above    */
   /* call to WinCreateStdWindow.  That used to work in the 1.05 SDK.    */
   /* In the 1.06 SDK, however, instead of replacing the caption, the    */
   /* result is to append the text to the default caption, which is the  */
   /* executable module name.  Anyway, this is what's needed as of 1.06. */

   WinSetWindowText( gbl_hwndAppFrame, (PSZ) gbl_psz( IDS_TITLE ) );

   /* Because we specifically did not specify FCF_TASKLIST in the frame  */
   /* window style bits, we have to add the application to the task list */
   /* ourselves.  Why do it ourselves?  Because if we had specified      */
   /* FCF_TASKLIST, the application would have been added to the task    */
   /* switch list under the name of the .EXE file, and that's ugly.      */
   /* When we add the application ourselves, we get to choose the name.  */
   /* Moreover, we get back a handle that will let us change the name in */
   /* the switch list whenever we want to.  For example, we might decide */
   /* to show status information in the task list.                       */
   {
      SWCNTRL swctl;
      PID pid;
      TID tid;

      WinQueryWindowProcess(gbl_hwndAppFrame, &pid, &tid);

      swctl.hwnd = gbl_hwndAppFrame;                  /* window handle      */
      swctl.hwndIcon = NULL;                          /* icon handle        */
      swctl.hprog = NULL;                             /* program handle     */
      swctl.idProcess = pid;                          /* process identifier */
      swctl.idSession = NULL;                         /* session identifier */
      swctl.uchVisibility = SWL_VISIBLE;              /* visibility         */
      swctl.fbJump = SWL_JUMPABLE;                    /* jump indicator     */
      strcpy( swctl.szSwtitle, gbl_psz( IDS_TITLE )   /* program name       */
      );

      gbl_hswitch = WinAddSwitchEntry( &swctl ) ;
   }

   /* The arrow cursor */
   gbl_curArrow = WinQuerySysPointer(
      HWND_DESKTOP,
      SPTR_ARROW,
      FALSE
      );

   /* The hourglass cursor */
   gbl_curWait = WinQuerySysPointer(
      HWND_DESKTOP,
      SPTR_WAIT,
      FALSE
      );

   /* The application's icon */
   gbl_hptrStd = WinLoadPointer(
      HWND_DESKTOP,
      NULL,
      IDS_NAME
      );


   /* Add separator and "About" to system menu */

   hSysMenu = WinWindowFromID( gbl_hwndAppFrame, FID_SYSMENU );

   idSysMenu = SHORT1FROMMR( WinSendMsg(
      hSysMenu,
      MM_ITEMIDFROMPOSITION,
      (MPARAM) 0,
      (MPARAM) 0
      ) );

   WinSendMsg( hSysMenu,
      MM_QUERYITEM,
      MPFROM2SHORT( idSysMenu, FALSE ),
      MPFROMP( &miSysMenu )
      );

   WinSendMsg( miSysMenu.hwndSubMenu,
      MM_INSERTITEM,
      MPFROMP( &menuitem[ 0 ] ),
      MPFROMSHORT( 0 )
      );

   WinSendMsg( miSysMenu.hwndSubMenu,
      MM_INSERTITEM,
      MPFROMP( &menuitem[ 1 ] ),
      MPFROMP( gbl_psz( IDS_ABOUT ) )
      );

   WinShowWindow( gbl_hwndApp, TRUE );
   WinUpdateWindow( gbl_hwndApp );

   return( TRUE );
}



/*   E N D   O F   E X A M I N I T . C   */
