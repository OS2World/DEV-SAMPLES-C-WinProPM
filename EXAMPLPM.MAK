#--------------------------------------
#make file for ExamplPM
#--------------------------------------

#Compiler invocation and switches - Microsoft C 5.x
CC = cl -c -G2sw -W2 -Zpe

#Specify the OS|2 Presentation Manager SDK linker
LINK = link

#Specify the OS|2 Presentation Manager resource compiler
RC = rc


# Resource compiler
ExamplPM.res:   ExamplPM.rc Examrc.h examplpm.ico
    $(RC) -r ExamplPM.rc

# Main routines: WndProc, Command, etc.
Exammain.obj:   Exammain.c Examrc.h Examgbl.h
    $(CC) Exammain.c

# External global data elements
Examext.obj:    Examext.c Examrc.h Examgbl.h
    $(CC) Examext.c

# Initialization & window registration routines
Examinit.obj:   Examinit.c Examrc.h Examgbl.h
    $(CC) Examinit.c -NT _APPINIT

# Menu processing functions
Exammenu.obj:   Exammenu.c Examrc.h Examgbl.h
    $(CC) Exammenu.c -NT _APPDLGS;

# Dialog processing functions
Examdlg.obj:    Examdlg.c Examrc.h Examgbl.h
    $(CC) Examdlg.c -NT _APPDLGS;

ExamplPM.exe:	ExamplPM.mak Exammain.obj Examext.obj Exammenu.obj \
 Examinit.obj Examdlg.obj ExamplPM.res ExamplPM.def 
    $(LINK) @ExamplPM.lke
    $(RC) ExamplPM.res
