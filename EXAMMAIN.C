/* file : Exammain.c


        Created: 21:55:40 Mon Jun 19 1989

        Description:  Main routines for "ExamplPM"
                      Presentation Manager application

        Skeleton by:  WINPRO/PM, a product from Louis J. Cutrona, Jr.
                      Skeleton.pm (Revision 2.5)  

*/

/* Activate standard window management definitions and typedefs */
#define  INCL_WIN
#define  INCL_GPI
/* Activate definitions for ExitList processing */
#define  INCL_DOSPROCESS

#include <os2.h>

#include "Examrc.h"
#include "Examgbl.h"


/*   E X A M P L  P  M   C L E A N  U P  */  /* Exit list process */
VOID PASCAL FAR   ExamplPMCleanUp( USHORT usTermCode )
{
   /* This routine gets control after all other threads have been */
   /* terminated.  Do any final clean-up here.  Don't dawdle!     */

   /* ExamplPMCleanUp is invoked by a JMP not a CALL, so it must   */
   /* not issue a RETURN.  This is the only correct way to end it */
   DosExitList( EXLST_EXIT, 0L ) ;     /* Termination complete */
}



/* M A I N */  /* Main procedure for ExamplPM */
VOID cdecl main( argc, argv )
SHORT     argc;
char    **argv;
{
   QMSG     qmsg;

   /* Initialize anchor block */
   gbl_hab = WinInitialize( (USHORT) 0 );

   /* Create message queue of default size */
   gbl_hmqExamplPM = WinCreateMsgQueue( gbl_hab, 0 );

   if( ! ExamplPMInit() )
      DosExit( EXIT_PROCESS, 1 ) ;

   /* Specify the routine to call at application termination time */
   DosExitList( EXLST_ADD, ExamplPMCleanUp ) ;

   while( WinGetMsg( gbl_hab, (PQMSG) &qmsg, (HWND) 0, (USHORT) 0, (USHORT) 0) )
      WinDispatchMsg( gbl_hab, (PQMSG) &qmsg );

   WinDestroyWindow( gbl_hwndAppFrame ) ;
   WinDestroyMsgQueue( gbl_hmqExamplPM );
   WinTerminate( gbl_hab );
   DosExit( EXIT_PROCESS, 0 ) ;
}


/*  F  O K  T O  T E R M I N A T E   E X A M P L  P  M   */
BOOL  fOkToTerminateExamplPM()
{
   /* This routine responds to a request to terminate the application. */
   /* If termination is ok or we can make it ok by the time this       */
   /* function completes, we will return TRUE.  If, at the end of this */
   /* routine we have decided (probably after querying the user) that  */
   /* we don't want to terminate yet, then we will return FALSE.       */

   MRESULT  RetCode;

   RetCode = WinMessageBox( HWND_DESKTOP,
               gbl_hwndApp,
               (PSZ) "Terminate (from fOkToTerminateExamplPM)",
               (PSZ) gbl_psz( IDS_NAME ),     /* Caption */
               (USHORT) 0,                    /* ID for Help */
               MB_OKCANCEL | MB_ICONQUESTION
               );

   if( RetCode == DID_OK )
   {
      return TRUE;
   }
   else
      return FALSE;
}


/*  F   E X A M P L  P  M   C L O S E  */
BOOL  fExamplPMClose()
{
   /* A WM_CLOSE message was sent to the main window.  If it is  */
   /* ok to terminate the application, post a WM_QUIT message    */
   /* and return TRUE.  If we decide not to terminate, return    */
   /* FALSE.                                                     */
      
   /* In processing this message, we get a chance to prompt the  */
   /* user for confirmation if appropriate and then, if needed,  */
   /* do whatever needs to be done to terminate the application  */
   /* in an orderly fashion or simply continue processing.       */

   BOOL  RetCode;

   RetCode = fOkToTerminateExamplPM();

   if( RetCode )
      WinPostQueueMsg( gbl_hmqExamplPM, WM_QUIT, (MPARAM) 0, (MPARAM) 0 );
   
   return( RetCode );
}


/*   E X A M P L  P  M   P A I N T  */
void ExamplPMPaint( hWnd, hps )
HWND     hWnd;
HPS      hps;
{
   RECTL    rcl;

   GpiSavePS( hps );

   GpiCreateLogColorTable( hps, 0L, LCOLF_RGB, 0L, 0L, NULL );

   WinQueryWindowRect( hWnd, &rcl) ;

   WinFillRect( hps, &rcl,
      (COLOR) 0x808080L       /* Dark Grey */ 
      );

   GpiRestorePS( hps, -1L );
}


/*   E X A M P L  P  M   W N D  P R O C  */  /* Procedures which make up the window class */
MRESULT EXPENTRY ExamplPMWndProc( HWND hWnd, USHORT msg, MPARAM mp1, MPARAM mp2 )
{
   HPS      hps;     /* Handle to a presentation space */
   ULONG    RetCode;

   switch( msg )
   {
   case WM_CREATE:
      /* Put a call here to a routine to handle initialization */
      break;

   case WM_CLOSE:
      /* Message sent when user selects "Close" on the system menu. */
      /* Also sent within this application when user selects item   */
      /* midEXIT (by convention "Exit" on the leftmost pull-down    */
      /* menu.                                                      */

      /* If WinDefWindowProc gets this message, it will call the    */
      /* WinDestroyWindow function and we'll get a WM_DESTROY.      */

      /* For reasons known only to Microsoft, return FALSE if we    */
      /* are terminating; return TRUE if we are not!                */

      return( (MRESULT) ! fExamplPMClose() );
      break;

   case WM_PAINT:
      hps = WinBeginPaint( hWnd, (HPS) NULL, (PRECTL) NULL );
      ExamplPMPaint( hWnd, hps );
      WinEndPaint( hps );
      break;

   case WM_ERASEBACKGROUND:
      /* Tell frame window to erase with current system window color */
      return( TRUE );
      break;

   case WM_COMMAND:
      switch( COMMANDMSG( &msg )->cmd )
      {
      case midFILENEW:
         RetCode = midFILENEWFunction( (PUSHORT) &msg ) ;
         break ;
      case midFILEOPEN:
         RetCode = midFILEOPENFunction( (PUSHORT) &msg ) ;
         break ;
      case midFILESAVE:
         RetCode = midFILESAVEFunction( (PUSHORT) &msg ) ;
         break ;
      case ABOUT:
         RetCode = ABOUTFunction( (PUSHORT) &msg ) ;
         break ;
      case midEDITRESTORE:
         RetCode = midEDITRESTOREFunction( (PUSHORT) &msg ) ;
         break ;
      case midEDITCUT:
         RetCode = midEDITCUTFunction( (PUSHORT) &msg ) ;
         break ;
      case midEDITCOPY:
         RetCode = midEDITCOPYFunction( (PUSHORT) &msg ) ;
         break ;
      case midEDITPASTE:
         RetCode = midEDITPASTEFunction( (PUSHORT) &msg ) ;
         break ;
      case midEDITCLEAR:
         RetCode = midEDITCLEARFunction( (PUSHORT) &msg ) ;
         break ;
      case midCREATESCAN:
         RetCode = midCREATESCANFunction( (PUSHORT) &msg ) ;
         break ;
      case midCREATEPROCESS:
         RetCode = midCREATEPROCESSFunction( (PUSHORT) &msg ) ;
         break ;
      case MID_EXIT:
         RetCode = MID_EXITFunction( (PUSHORT) &msg ) ;
         break ;
      case accelF10:
         RetCode = accelF10Function( (PUSHORT) &msg ) ;
         break ;
      default:
         break;
      }
      break;

   case WM_HELP:
      switch( COMMANDMSG( &msg )->cmd )
      {
      case midHELP:
         RetCode = midHELPFunction( (PUSHORT) &msg ) ;
         break ;
      default:
         break;
      }
      break;

   case WM_SYSCOMMAND:
      switch( COMMANDMSG( &msg )->cmd )
      {
      default:
         break;
      }
      break;

   default:
      return WinDefWindowProc( hWnd, msg, mp1, mp2 );
      break;
   }
   return( (MRESULT) 0 );
}



/*   E N D   O F   E X A M M A I N . C   */
