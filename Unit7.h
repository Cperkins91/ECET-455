//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit7;
	TEdit *Edit10;
	TEdit *Edit11;
	TListBox *ListBox1;
	TEdit *Edit12;
	TLabel *Label10;
	TListBox *ListBox2;
	TListBox *ListBox3;
	TListBox *ListBox4;
	TListBox *ListBox5;
	TLabel *Label11;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
void clear(){
	ListBox1 -> Items -> Clear();                 // Clear the Lists:
	ListBox2 -> Items -> Clear();                 // This is in case the user clicks
	ListBox3 -> Items -> Clear();                 // the button more than once
	ListBox4 -> Items -> Clear();
    ListBox5 -> Items -> Clear();
}
void swap(int *a1, int *b1)
{
	int temp = *a1;
	*a1 = *b1;
	*b1 = temp;
}
void sort(int* nums, int SIZE) {
	bool swapped = true;
while (swapped){                            //Bubble Sort Loop
	swapped = false;
	for (int i = 0; i < SIZE-1; i++) {
		if (nums[i] > nums[i+1]) {
			swap(&nums[i],&nums[i+1]);
			swapped = true;
		}
	}
}
}
void random_gen (int* nums, int &sum, int SIZE, int range, int LowerLimit){
for (int i = 0; i < SIZE; i++) {               // Populate the list
	int v1 = rand() % range + LowerLimit;      //Random Gen with user defined range and size
	nums[i] = v1;
	sum += nums[i];                              // populate nums array
	ListBox1 -> Items -> Add(nums[i]);         // populate listbox
}

}
void mode (int* nums, int SIZE)
{
int ModeAmt = 0, ModeIndx = 0, temp = 0;
for (int i = 0; i < SIZE; i++) {            // Find Mode
	temp = 0;
		for (int j = 0; j < SIZE; j++) {
			if (nums[i] == nums[j]) {
			temp++;
			}
		}
	if (temp > ModeAmt) {
		ModeAmt = temp;
		ModeIndx = i;
	}
	if (i == (SIZE-1)) {
		Edit4 -> Text = nums[ModeIndx];
		Edit5 -> Text = ModeAmt;
	}
}
}
void populate_lists(int* nums, int SIZE)
{
	for (int i = 0; i < SIZE; i++) {                //Add sorted list to the ascending
		ListBox2 -> Items -> Add(nums[i]);          // and descending ListBoxes
		ListBox3 -> Items -> Insert(0, nums[i]);
		if (nums[i] % 2 == 0) { //check to see if even
			ListBox4 -> Items -> Add(nums[i]);
		}
		else {ListBox5 -> Items -> Add(nums[i]);}
	}
}

//}
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
