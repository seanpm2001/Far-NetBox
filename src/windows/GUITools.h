//---------------------------------------------------------------------------
#ifndef GUIToolsH
#define GUIToolsH
//---------------------------------------------------------------------------
#include "boostdefines.hpp"

// from shlobj.h
#define CSIDL_DESKTOP                   0x0000        // <desktop>
#define CSIDL_SENDTO                    0x0009        // <user name>\SendTo
#define CSIDL_DESKTOPDIRECTORY          0x0010        // <user name>\Desktop
#define CSIDL_COMMON_DESKTOPDIRECTORY   0x0019        // All Users\Desktop
#define CSIDL_APPDATA                   0x001a        // <user name>\Application Data
#define CSIDL_PROGRAM_FILES             0x0026        // C:\Program Files
#define CSIDL_PERSONAL                  0x0005        // My Documents
//---------------------------------------------------------------------------
#include <FileMasks.H>
//---------------------------------------------------------------------------
class TSessionData;
//---------------------------------------------------------------------------
#ifndef _MSC_VER
typedef void __fastcall (__closure* TProcessMessagesEvent)();
#else
typedef fastdelegate::FastDelegate0<void> TProcessMessagesEvent;
typedef TProcessMessagesEvent::slot_type TProcessMessagesEvent;
#endif
//---------------------------------------------------------------------------
bool __fastcall FindFile(UnicodeString & Path);
bool __fastcall FileExistsEx(UnicodeString Path);
bool __fastcall ExecuteShell(const UnicodeString Path, const UnicodeString Params);
bool __fastcall ExecuteShell(const UnicodeString Path, const UnicodeString Params,
  HANDLE & Handle);
bool __fastcall ExecuteShellAndWait(HINSTANCE Handle, const UnicodeString Path,
  const UnicodeString Params, TProcessMessagesEvent ProcessMessages);
bool __fastcall ExecuteShellAndWait(HINSTANCE Handle, const UnicodeString Command,
  TProcessMessagesEvent ProcessMessages);
void __fastcall OpenSessionInPutty(const UnicodeString PuttyPath,
  TSessionData * SessionData, UnicodeString Password);
bool __fastcall SpecialFolderLocation(int PathID, UnicodeString & Path);
UnicodeString __fastcall ItemsFormatString(const UnicodeString SingleItemFormat,
  const UnicodeString MultiItemsFormat, int Count, const UnicodeString FirstItem);
UnicodeString __fastcall ItemsFormatString(const UnicodeString SingleItemFormat,
  const UnicodeString MultiItemsFormat, TStrings * Items);
UnicodeString __fastcall FileNameFormatString(const UnicodeString SingleFileFormat,
  const UnicodeString MultiFileFormat, TStrings * Files, bool Remote);
UnicodeString __fastcall UniqTempDir(const UnicodeString BaseDir,
  const UnicodeString Identity, bool Mask = false);
bool __fastcall DeleteDirectory(const UnicodeString DirName);
UnicodeString __fastcall FormatDateTimeSpan(const UnicodeString TimeFormat, TDateTime DateTime);

UnicodeString __fastcall FormatBytes(__int64 Bytes, bool UseOrders = true);
//---------------------------------------------------------------------------
class TLocalCustomCommand : public TFileCustomCommand
{
public:
  /* __fastcall */ TLocalCustomCommand();
  explicit /* __fastcall */ TLocalCustomCommand(const TCustomCommandData & Data, const UnicodeString & Path);
  explicit /* __fastcall */ TLocalCustomCommand(const TCustomCommandData & Data, const UnicodeString & Path,
    const UnicodeString & FileName, const UnicodeString & LocalFileName,
    const UnicodeString & FileList);
  virtual /* __fastcall */ ~TLocalCustomCommand() {}

  virtual bool __fastcall IsFileCommand(const UnicodeString & Command);
  bool __fastcall HasLocalFileName(const UnicodeString & Command);

protected:
  virtual int __fastcall PatternLen(int Index, wchar_t PatternCmd);
  virtual bool __fastcall PatternReplacement(int Index, const UnicodeString & Pattern,
    UnicodeString & Replacement, bool & Delimit);
  virtual void __fastcall DelimitReplacement(UnicodeString & Replacement, wchar_t Quote);

private:
  UnicodeString FLocalFileName;
};
//---------------------------------------------------------------------------
#endif
