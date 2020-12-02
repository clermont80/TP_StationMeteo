//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#define __WIN__
#include "mySQL.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	long addr = OpenDevice(0);
	if(addr != -1)
	{
		Label1->Caption = L"Connexion OK";
		Timer1->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
long value = ReadAnalogChannel(2);
Label1->Caption = L"Connexion OK (" + UnicodeString(value) + L")";

float valtoread =  ((value/255)*60)-30;
Label2->Caption = valtoread;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{


	Label2->Visible= true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObjet *Sender) //on initialise la connexion 
{
	
	mySQL = mysql_init(NULL);

}

void __fastcall TForm1::Button2Click(TObjet *Sender)  //on ferme la connexion
{
	if(mySQL != NULL)
	{
		mysql_close(mySQL);
	}
	

}

void __fastcall TForm1::Button3Click(TObjet *Sender)  //on se connecte à la base
{
	if (!mysql_real_connect(mySQL, "127.0.0.1", "root", "root", "test", 0, NULL, 0)) // la connexion a échoué
	{
 
	} 
	else // la connexion a réussi
	{
 		connectbase = true;
	}

}

void __fastcall TForm1::Button4Click(TObjet *Sender)  //on se connecte à la base
{
	if (connectbase==true) //on peut faire notre insertion 
	{
		mysql_query(mySQL,"INSERT INTO TempTable (temperature) VALUES (valtoread))");
	} 
	

}