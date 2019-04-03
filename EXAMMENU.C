/* file : Exammenu.c


        Created: 21:55:50 Mon Jun 19 1989


        Description:  Menu processing functions for ExamplPM


        Skeleton by:  WINPRO/PM, a product from Louis J. Cutrona, Jr.
                      Skeleton.pm (Revision 2.5)  

*/


/* Activate standard window management definitions and typedefs */
#define  INCL_WIN       1

#include <os2.h>

#include "Examrc.h"
#include "Examgbl.h"

/* ----------------- ExamplPM MENU DIALOGS & FUNCTIONS ------------------- */

/* Action bar item: ~File */
/* WM_COMMAND message: Pulldown item: ~New */

ULONG midFILENEWFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midFILENEWFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~File */
/* WM_COMMAND message: Pulldown item: ~Open... */

ULONG midFILEOPENFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   RetCode = WinDlgBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PFNWP)midFILEOPENDlgWndProc,
      (HMODULE) 0,
      midFILEOPEN,
      (PVOID) 0
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~File */
/* WM_COMMAND message: Pulldown item: ~Save */

ULONG midFILESAVEFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midFILESAVEFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~File */
/* WM_COMMAND message: Pulldown item: A~bout ExamplPM... */

ULONG ABOUTFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   RetCode = WinDlgBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PFNWP)ABOUTDlgWndProc,
      (HMODULE) 0,
      ABOUT,
      (PVOID) 0
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~Edit */
/* WM_COMMAND message: Pulldown item: ~Restore Image\tSh Esc */

/* WM_COMMAND message: Accelerator key */

ULONG midEDITRESTOREFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midEDITRESTOREFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~Edit */
/* WM_COMMAND message: Pulldown item: Cu~t Image\tDel */

/* WM_COMMAND message: Accelerator key */

ULONG midEDITCUTFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midEDITCUTFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~Edit */
/* WM_COMMAND message: Pulldown item: ~Copy Image\tF2 */

/* WM_COMMAND message: Accelerator key */

ULONG midEDITCOPYFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midEDITCOPYFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~Edit */
/* WM_COMMAND message: Pulldown item: ~Paste Image\tIns */

/* WM_COMMAND message: Accelerator key */

ULONG midEDITPASTEFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midEDITPASTEFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~Edit */
/* WM_COMMAND message: Pulldown item: C~lear */

ULONG midEDITCLEARFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midEDITCLEARFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~Create */
/* WM_COMMAND message: Pulldown item: ~Scan... */

ULONG midCREATESCANFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midCREATESCANFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: ~Create */
/* WM_COMMAND message: Pulldown item: ~Process... */

ULONG midCREATEPROCESSFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   RetCode = WinDlgBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PFNWP)midCREATEPROCESSDlgWndProc,
      (HMODULE) 0,
      midCREATEPROCESS,
      (PVOID) 0
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* Action bar item: E~xit */
/* WM_COMMAND message: Pulldown item: E~xit WINPRO/PM example...  F3 */

/* WM_COMMAND message: Accelerator key */

/* This function requests ExamplPM to terminate itself */

ULONG MID_EXITFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "MID_EXITFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;

   /* Request termination */
   /* If RetCode is TRUE, request was accepted */
   /* If RetCode is FALSE, termination request was denied */
   RetCode = (MRESULT) fExamplPMClose() ;
   return LONGFROMMR( RetCode ) ;
}


/* WM_HELP message: Action bar item: F1=Help */

/* WM_HELP message: Accelerator key */

ULONG midHELPFunction( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "midHELPFunction",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}


/* WM_COMMAND message: Accelerator key */

ULONG accelF10Function( PUSHORT pmsg )
{
   MRESULT   RetCode ;

   WinMessageBox( HWND_DESKTOP,
      gbl_hwndApp,
      (PSZ) "accelF10Function",     /* Message text */
      (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
      (USHORT) 0,                    /* ID for Help */
      MB_OK | MB_ICONASTERISK
      ) ;
   return LONGFROMMR( RetCode ) ;
}




/*   E N D   O F   E X A M M E N U . C   */
