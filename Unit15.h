//---------------------------------------------------------------------------

#ifndef Unit15H
#define Unit15H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm15 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TEdit *Edit1;
	TTimer *Timer1;
	TButton *Button2;
	TButton *Button3;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TListBox *ListBox3;
	TListBox *ListBox4;
	TListBox *ListBox5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
	HANDLE hSerial;
public:		// User declarations
	///////////////////////////////////////////////////////////////////////////////////////////
	void readSerial(char *temp) {
		DWORD dwBytesRead = 0; // number of bytes read
		// try to recieve data, and handle any errors
		if (!ReadFile(hSerial, temp, 100, &dwBytesRead, NULL)) {
			Application->MessageBoxW(L"Error reading data",
				L"Serial Port Error'");
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	void startSerial() {
		// HANDLE hSerial;     // handle for serial port (like a file pointer)

		// open the port
		// note that the next two lines should be typed on one line only
		hSerial = CreateFile(L"COM4", GENERIC_READ | GENERIC_WRITE, 0, 0,
			OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

		// do error handling if we can't open the port:
		if (hSerial == INVALID_HANDLE_VALUE) {
			if (GetLastError() == ERROR_FILE_NOT_FOUND) {
				// Application->MessageBoxA(L"Serial port does not exist.  Uh oh!", L"Serial Port Error");
				return;
			}
			// Application->MessageBoxA(L"Some error occurred.  Uh oh!", L"Serial Port Error");
			return;
		}

		DCB dcbSerialParams = {0}; // parameters variable

		dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
		// workaround strange Windows bug

		// try to get the current serial port state
		if (!GetCommState(hSerial, &dcbSerialParams)) {
			// cout<<"Couldn't get serial port state.  Uh oh!"<<endl;
			return;
		}

		// customize values to our particular application:
		dcbSerialParams.BaudRate = CBR_9600;

		dcbSerialParams.ByteSize = 8;
		dcbSerialParams.StopBits = ONESTOPBIT;
		dcbSerialParams.Parity = NOPARITY;

		// set the values and handle any errors
		if (!SetCommState(hSerial, &dcbSerialParams)) {
			// Application->MessageBoxA(L"Error setting serial port state.  Uh oh!", L"Serial Port Error");
			return;
		}

		COMMTIMEOUTS timeouts = {0}; // timeout parameters variable

		// these values determine how long Windows will wait for input
		// (see PDF file for details)
		timeouts.ReadIntervalTimeout = 50;
		timeouts.ReadTotalTimeoutConstant = 50;
		timeouts.ReadTotalTimeoutMultiplier = 10;
		timeouts.WriteTotalTimeoutConstant = 50;
		timeouts.WriteTotalTimeoutMultiplier = 10;

		// set the values and handle any errors
		if (!SetCommTimeouts(hSerial, &timeouts)) {
			// Application->MessageBoxA(L"Error setting timeouts. Uh oh!", L"Serial Port Error");
			return;
		}
		return;
	}

	/////////////////////////////////////////////////////////////////////////////////////////
	void sendSerial(char value) {
		DWORD dwBytesSent = 0; // number of bytes sent

		// send value, and handle any errors (also fail if value didn't successfully send)
		if (!WriteFile(hSerial, &value, 1, &dwBytesSent, NULL) ||
			dwBytesSent != 1) {
			// Application->MessageBoxA(L"Error sending value", L"Serial Port Error");
			return;
		}

		// special handling for line returns:
		if (value == 13) { // if CR (user pressed enter)
			sendSerial(10); // send LF (move to next line)
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////////////
	__fastcall TForm15(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm15 *Form15;
//---------------------------------------------------------------------------
#endif
