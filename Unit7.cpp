//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
clear();
int SIZE = Edit12->Text.ToInt();
int nums[SIZE]; int sum=0;
int LowerLimit = Edit10->Text.ToInt(); int UpperLimit = Edit11->Text.ToInt();
int range = (UpperLimit - LowerLimit)+1;

random_gen ( nums, sum, SIZE, range, LowerLimit);    //Call to random number gen
Edit1->Text = ListBox1 -> Items -> Count;// Display # of elements
Edit2->Text = sum/SIZE;                  //Display mean
sort(nums, SIZE);                        // Call to Bubble Sort algo
populate_lists(nums, SIZE);				 // Find Median
Edit3 -> Text = nums[SIZE/2];            //TODO: add even number elements support & Float support
Edit7 -> Text  = range;                  //Find Range
mode(nums, SIZE);                        //Find Mode
}
//---------------------------------------------------------------------------



