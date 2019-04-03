/* file : Examdlg.c


        Created: 21:55:51 Mon Jun 19 1989

        Description:  Dialog processing functions for ExamplPM

        Skeleton by:  WINPRO/PM, a product from Louis J. Cutrona, Jr.
                      Skeleton.pm (Revision 2.5)  

*/

/* Activate standard window management definitions and typedefs */
#define  INCL_WIN       1

#include <os2.h>

#include "Examrc.h"
#include "Examgbl.h"

/* ----------------- ExamplPM Dialog Window Procdeures ------------------- */




/* The dialog below is invoked in the following situations */

/* Action bar item: ~File */
/* WM_COMMAND message: Pulldown item: A~bout ExamplPM... */

MRESULT EXPENTRY ABOUTDlgWndProc( hDlg, msg, mp1, mp2 )
HWND      hDlg;
USHORT    msg;
MPARAM    mp1;
MPARAM    mp2;
{
   USHORT NotificationCode;
   PVOID  pControlData;

   gbl_hDlg = hDlg;

   NotificationCode = SHORT2FROMMP( mp1 ) ;
   pControlData = PVOIDFROMMP( mp2 ) ;

   switch( msg )
   {
   case WM_COMMAND:
   case WM_CONTROL:
      switch( SHORT1FROMMP( mp1 ) )
      {
      case DID_OK:

      /* DID_CANCEL is not specified for this dialog, but */
      /* code is included here to handle a message from   */
      /* the Esc key to terminate the dialog.  If this is */
      /* not correct, remove the case statement below.    */

      case DID_CANCEL:
         /* Return control id to routine that invoked */
         /* the dialog, so it knows how dialog ended  */
         WinDismissDlg( hDlg, SHORT1FROMMP( mp1 ) ) ;
         break;
      default:
         break;
      }  /* end of switch on control id from WM_COMMAND or WM_CONTROL msg */
      break;
   case WM_INITDLG:
      /* Dialog initialization code */

      return( FALSE ) ;    /* (FALSE means give us the focus ) */
      break;
   default:
      /* We did not process the message */
      return( WinDefDlgProc( hDlg, msg, mp1, mp2 ) ) ;
   }
   return 0L;
}


/* The dialog below is invoked in the following situations */

/* Action bar item: ~File */
/* WM_COMMAND message: Pulldown item: ~Open... */

MRESULT EXPENTRY midFILEOPENDlgWndProc( hDlg, msg, mp1, mp2 )
HWND      hDlg;
USHORT    msg;
MPARAM    mp1;
MPARAM    mp2;
{
   USHORT NotificationCode;
   PVOID  pControlData;

   gbl_hDlg = hDlg;

   NotificationCode = SHORT2FROMMP( mp1 ) ;
   pControlData = PVOIDFROMMP( mp2 ) ;

   switch( msg )
   {
   case WM_COMMAND:
   case WM_CONTROL:
      switch( SHORT1FROMMP( mp1 ) )
      {
      case IDD_PATH:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case IDD_FILEEDIT:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case IDD_DIRLIST:
         /* Your code to handle this LISTBOX control goes here */
         break;
      case IDD_FILELIST:
         /* Your code to handle this LISTBOX control goes here */
         break;
      case DID_OK:
         /* Copy current dialog control */
         /* settings data into globals  */
         WinQueryDlgItemText( hDlg, IDD_PATH,
            sizeof( gbl_szIDD_PATH ),
            (PSZ) gbl_szIDD_PATH ) ;
         WinQueryDlgItemText( hDlg, IDD_FILEEDIT,
            sizeof( gbl_szIDD_FILEEDIT ),
            (PSZ) gbl_szIDD_FILEEDIT ) ;
         /* Need to save state of LISTBOX IDD_DIRLIST?  Do it here */
         /* Need to save state of LISTBOX IDD_FILELIST?  Do it here */

         /* Fall through to DID_CANCEL for DID_OK */
      case DID_CANCEL:
         /* Return control id to routine that invoked */
         /* the dialog, so it knows how dialog ended  */
         WinDismissDlg( hDlg, SHORT1FROMMP( mp1 ) ) ;
         break;
      default:
         break;
      }  /* end of switch on control id from WM_COMMAND or WM_CONTROL msg */
      break;
   case WM_INITDLG:
      /* Dialog initialization code */

      /* Initialize controls from contents of globals */

      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, IDD_PATH,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szIDD_PATH ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, IDD_PATH,
         (PSZ) gbl_szIDD_PATH
         ) ;
      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, IDD_FILEEDIT,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szIDD_FILEEDIT ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, IDD_FILEEDIT,
         (PSZ) gbl_szIDD_FILEEDIT
         ) ;
      /* Initialize LISTBOX IDD_DIRLIST here */
      /* Initialize LISTBOX IDD_FILELIST here */

      return( FALSE ) ;    /* (FALSE means give us the focus ) */
      break;
   default:
      /* We did not process the message */
      return( WinDefDlgProc( hDlg, msg, mp1, mp2 ) ) ;
   }
   return 0L;
}


/* The dialog below is invoked in the following situations */

/* Action bar item: ~Create */
/* WM_COMMAND message: Pulldown item: ~Process... */

MRESULT EXPENTRY midCREATEPROCESSDlgWndProc( hDlg, msg, mp1, mp2 )
HWND      hDlg;
USHORT    msg;
MPARAM    mp1;
MPARAM    mp2;
{
   USHORT NotificationCode;
   PVOID  pControlData;

   gbl_hDlg = hDlg;

   NotificationCode = SHORT2FROMMP( mp1 ) ;
   pControlData = PVOIDFROMMP( mp2 ) ;

   switch( msg )
   {
   case WM_COMMAND:
   case WM_CONTROL:
      switch( SHORT1FROMMP( mp1 ) )
      {
      case GP_SIFNAME:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case GP_LOFFSET:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case GP_TOFFSET:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case GP_WIDTH:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case GP_HEIGHT:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case GP_HSCALE:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case GP_VSCALE:
         if( NotificationCode == EN_KILLFOCUS )
         /* User moved on to next control */
         {
            /* This is a nice place to do validation */
            /* of whatever the user entered.         */
         }
         break;
      case GP_FORSCREEN:
      case GP_FORPRINTER:
      case GP_PRINT:
         /* AUTORADIOBUTTON. Automatically checks itself    */
         /* when clicked and unchecks any other auto radio  */
         /* buttons in the same group.  If that's all you   */
         /* want to happen, you don't have to do anything   */
         /* here at all.                                    */
         break;
      case GP_FAVORWHITE:
         /* BS_AUTOCHECKBOX toggles itself when user clicks it */
         /* State has already changed at this point */
         break;
      case GP_FAVORBLACK:
         /* BS_AUTO3STATE cycles itself each time user clicks it */
         /* Sequence: unchecked, checked, greyed, unchecked, ... */
         /* State has already changed at this point */
         break;
      case GP_DEFAULTS:
         /* PUSHBUTTON was clicked or double clicked */
         break;
      case DID_OK:
         /* Copy current dialog control */
         /* settings data into globals  */
         WinQueryDlgItemText( hDlg, GP_SIFNAME,
            sizeof( gbl_szGP_SIFNAME ),
            (PSZ) gbl_szGP_SIFNAME ) ;
         WinQueryDlgItemText( hDlg, GP_LOFFSET,
            sizeof( gbl_szGP_LOFFSET ),
            (PSZ) gbl_szGP_LOFFSET ) ;
         WinQueryDlgItemText( hDlg, GP_TOFFSET,
            sizeof( gbl_szGP_TOFFSET ),
            (PSZ) gbl_szGP_TOFFSET ) ;
         WinQueryDlgItemText( hDlg, GP_WIDTH,
            sizeof( gbl_szGP_WIDTH ),
            (PSZ) gbl_szGP_WIDTH ) ;
         WinQueryDlgItemText( hDlg, GP_HEIGHT,
            sizeof( gbl_szGP_HEIGHT ),
            (PSZ) gbl_szGP_HEIGHT ) ;
         WinQueryDlgItemText( hDlg, GP_HSCALE,
            sizeof( gbl_szGP_HSCALE ),
            (PSZ) gbl_szGP_HSCALE ) ;
         WinQueryDlgItemText( hDlg, GP_VSCALE,
            sizeof( gbl_szGP_VSCALE ),
            (PSZ) gbl_szGP_VSCALE ) ;
         {
            SHORT i ;

            for( i = GP_FORSCREEN; i <= GP_PRINT; i++ )
            {
               if( (MRESULT) 1 == WinSendDlgItemMsg( hDlg, i,
                  BM_QUERYCHECK, NULL, NULL ) )
               {
                  gbl_sGP_FORSCREEN_to_GP_PRINT = i;
                  break;
               }
            }
         }
         gbl_sGP_FAVORWHITE =
            SHORT1FROMMR( WinSendDlgItemMsg( hDlg, GP_FAVORWHITE,
               BM_QUERYCHECK, NULL, NULL ) ) ;
         gbl_sGP_FAVORBLACK =
            SHORT1FROMMR( WinSendDlgItemMsg( hDlg, GP_FAVORBLACK,
               BM_QUERYCHECK, NULL, NULL ) ) ;

         /* Fall through to DID_CANCEL for DID_OK */
      case DID_CANCEL:
         /* Return control id to routine that invoked */
         /* the dialog, so it knows how dialog ended  */
         WinDismissDlg( hDlg, SHORT1FROMMP( mp1 ) ) ;
         break;
      default:
         break;
      }  /* end of switch on control id from WM_COMMAND or WM_CONTROL msg */
      break;
   case WM_INITDLG:
      /* Dialog initialization code */

      /* Initialize controls from contents of globals */

      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, GP_SIFNAME,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szGP_SIFNAME ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, GP_SIFNAME,
         (PSZ) gbl_szGP_SIFNAME
         ) ;
      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, GP_LOFFSET,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szGP_LOFFSET ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, GP_LOFFSET,
         (PSZ) gbl_szGP_LOFFSET
         ) ;
      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, GP_TOFFSET,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szGP_TOFFSET ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, GP_TOFFSET,
         (PSZ) gbl_szGP_TOFFSET
         ) ;
      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, GP_WIDTH,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szGP_WIDTH ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, GP_WIDTH,
         (PSZ) gbl_szGP_WIDTH
         ) ;
      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, GP_HEIGHT,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szGP_HEIGHT ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, GP_HEIGHT,
         (PSZ) gbl_szGP_HEIGHT
         ) ;
      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, GP_HSCALE,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szGP_HSCALE ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, GP_HSCALE,
         (PSZ) gbl_szGP_HSCALE
         ) ;
      /* Tell control how many characters it should hold */
      WinSendDlgItemMsg( hDlg, GP_VSCALE,
         EM_SETTEXTLIMIT,
         (MPARAM) sizeof( gbl_szGP_VSCALE ),
         0L
         ) ;
      /* Fill in current value from global */
      WinSetDlgItemText( hDlg, GP_VSCALE,
         (PSZ) gbl_szGP_VSCALE
         ) ;
      /* Activate currently selected radio button */
      {
         SHORT i ;

         for( i = GP_FORSCREEN; i <= GP_PRINT; i++ )
            WinSendDlgItemMsg( hDlg, i,
               BM_SETCHECK,
               (MPARAM) ( i == gbl_sGP_FORSCREEN_to_GP_PRINT ),
               NULL
               ) ;
      }
      WinSendDlgItemMsg( hDlg, GP_FAVORWHITE,
         BM_SETCHECK,
         (MPARAM) gbl_sGP_FAVORWHITE,
         NULL
         ) ;
      WinSendDlgItemMsg( hDlg, GP_FAVORBLACK,
         BM_SETCHECK,
         (MPARAM) gbl_sGP_FAVORBLACK,
         NULL
         ) ;

      return( FALSE ) ;    /* (FALSE means give us the focus ) */
      break;
   default:
      /* We did not process the message */
      return( WinDefDlgProc( hDlg, msg, mp1, mp2 ) ) ;
   }
   return 0L;
}


MRESULT EXPENTRY PRINTERABORTDlgWndProc( hDlg, msg, mp1, mp2 )
HWND      hDlg;
USHORT    msg;
MPARAM    mp1;
MPARAM    mp2;
{
   USHORT NotificationCode;
   PVOID  pControlData;

   gbl_hDlg = hDlg;

   NotificationCode = SHORT2FROMMP( mp1 ) ;
   pControlData = PVOIDFROMMP( mp2 ) ;

   switch( msg )
   {
   case WM_COMMAND:
   case WM_CONTROL:
      switch( SHORT1FROMMP( mp1 ) )
      {
      case DID_CANCEL:
         /* Return control id to routine that invoked */
         /* the dialog, so it knows how dialog ended  */
         WinDismissDlg( hDlg, SHORT1FROMMP( mp1 ) ) ;
         break;
      default:
         break;
      }  /* end of switch on control id from WM_COMMAND or WM_CONTROL msg */
      break;
   case WM_INITDLG:
      /* Dialog initialization code */

      return( FALSE ) ;    /* (FALSE means give us the focus ) */
      break;
   default:
      /* We did not process the message */
      return( WinDefDlgProc( hDlg, msg, mp1, mp2 ) ) ;
   }
   return 0L;
}



/*   E N D   O F   E X A M D L G . C   */
