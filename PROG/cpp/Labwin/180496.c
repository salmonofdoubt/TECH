#include <utility.h>

#include <gpib.h>
#include "hp34401a.h"
#include <ansi_c.h>
#include <dataacq.h>
#include <userint.h>
#include "afx.h"

#define ANZ	 369    /*Anzahl der Messungen 		    */
#define START	41		/*Startwert						*/
short
   		status,
   		phandle,
   		board;

   	int
   		panel,
   		ctrl,
   		HP1,
   		i;
	double
        hpvalue[ANZ],   /* Mit HP 34401 gemessene Werte */
	    advalue[ANZ],   /* Mit AT MIO gemessene Werte   */
	    compvalue[ANZ], /* Berechnete Werte				*/
	    dafailure[ANZ], /* Fehler des DA Wandlers		*/
	    adfailure[ANZ]; /* Fehler des AD Wandlers       */


void SetPrintAttributes (void);
void Init(void);



void main()
{
 Init();
 SetPrintAttributes();
 phandle = LoadPanel(0, "afx.uir", PANEL);
 status  = DisplayPanel(phandle);
 RunUserInterface ();
}

void SetPrintAttributes (void)
{
 SetPrintAttribute (ATTR_XOFFSET, VAL_USE_PRINTER_DEFAULT);
 SetPrintAttribute (ATTR_YOFFSET, VAL_USE_PRINTER_DEFAULT);
 SetPrintAttribute (ATTR_PAPER_HEIGHT, VAL_USE_PRINTER_DEFAULT);
 SetPrintAttribute (ATTR_PAPER_WIDTH, VAL_USE_PRINTER_DEFAULT);
 SetPrintAttribute (ATTR_COLOR_MODE, VAL_BW);
 SetPrintAttribute (ATTR_ORIENTATION, VAL_LANDSCAPE);
 SetPrintAttribute (ATTR_EJECT_AFTER, 0);
}

void Init(void)
{
 board=1;
 hp34401a_init (2, &HP1);
 hp34401a_conf (HP1, 1, 0, 1.0, 1);
 AI_Configure (1, -1, 0, 10, 1, 0);
 AO_Configure (1, 0, 1, 0, 10.0, 0);
 AO_Configure (1, 1, 1, 0, 10.0, 0);
}

/* Die Funktion Run ist entsprechend den Vorgaben im Umdruck zu vervollständigen*/

int  Run(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)


{


switch (event)
{

case EVENT_LEFT_CLICK :
DeleteGraphPlot (phandle, PANEL_HP, -1, VAL_IMMEDIATE_DRAW);
DeleteGraphPlot (phandle, PANEL_AT, -1, VAL_IMMEDIATE_DRAW);
SetInputMode (phandle, PANEL_RUN, 0);
SetInputMode (phandle, PANEL_QUIT, 0);
SetInputMode (phandle, PANEL_PRINT, 0);
ProcessDrawEvents ();
for (i=0;i<ANZ;i++)

{
AO_Write (1, 1, i+START);
hp34401a_single_meas (HP1, &hpvalue[i]);
SetCtrlVal (phandle, PANEL_UHP,hpvalue[i] );
AI_VRead (1, 0, 1, &advalue[i]);
SetCtrlVal (phandle, PANEL_UAT,advalue[i] );
SetCtrlVal (phandle, PANEL_DIGI,i+START);
SetCtrlVal (phandle, PANEL_NR_MESSUNG, i+1);
SetCtrlVal (phandle, PANEL_UAT,advalue[i] );
compvalue[i]=0.00244*(i+START);
dafailure[i]=(-hpvalue[i]+compvalue[i])*100/compvalue[i];
adfailure[i]=(-advalue[i]+hpvalue[i])*100/hpvalue[i];



}
PlotXY (phandle, PANEL_HP, &compvalue, &dafailure, i, VAL_DOUBLE,
		VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
		VAL_RED);

PlotXY (phandle, PANEL_AT, &hpvalue, &adfailure, i, VAL_DOUBLE,
		VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
		VAL_RED);

SetInputMode (phandle, PANEL_RUN, 1);
SetInputMode (phandle, PANEL_QUIT, 1);
SetInputMode (phandle, PANEL_PRINT, 1);






break;
}
return(0);
}

int  Print(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
 switch (event)
 {

case EVENT_COMMIT :
	   PrintCtrl (phandle, PANEL_HP, "", 0, 0);
	   SetPrintAttribute (ATTR_EJECT_AFTER, 1);
	   PrintCtrl (phandle, PANEL_AT, "", 0, 0);
	   SetPrintAttribute (ATTR_EJECT_AFTER, 0);
	   break;
 }
 return(0);
}

int  Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
 switch (event)
 {
  case EVENT_COMMIT:
	   QuitUserInterface (0);
	   break;
 }
 return(0);
}
