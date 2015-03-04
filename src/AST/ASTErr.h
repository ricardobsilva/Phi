#include "ErrorMsg/EMCore.h"

using namespace std;

extern int current_line_number;
static ErrorMessage error_messages;

inline void
ASTERR_showAllMsgAndExit1(void)
{
	error_messages.popAllAndExit1(cerr);
	return;
}

inline void
ASTERR_showAllMsg(void)
{
	error_messages.popInDefaultAction(cerr);
	return;
}

inline void
ASTERR_setLineNumber(void)
{
	error_messages.setTopLineNumber(current_line_number);
	return;
}

void
ASTERR_Undefined_Syntax_Error(const char *token) {
	error_messages.newMessage(new ErrorInfo(ErrorInfo::Error, true, ErrorInfo::Exit1,
							  "Undefined syntax error (near \"$(token)\")", token));
	return;
}

inline void
ASTERR_Static_Specifier_In_Delegate(void)
{
	error_messages.newMessage(new ErrorInfo(ErrorInfo::Warning, true, ErrorInfo::NoAct,
							  "Static Specifier in delegate (ignore)"));
	return;
}

inline void
ASTERR_Bit_Field_With_Non_Int_Type(void)
{
	error_messages.newMessage(new ErrorInfo(ErrorInfo::Warning, true, ErrorInfo::NoAct,
							  "Bitfield type with non-int type (ignore (as int))"));
	return;
}

inline void
ASTERR_Negative_Array_Size(void)
{
	error_messages.newMessage(new ErrorInfo(ErrorInfo::Error, true, ErrorInfo::Exit1,
							  "Negative array size"));
	return;
}

inline void
ASTERR_Missing_Semicolon(void)
{
	error_messages.newMessage(new ErrorInfo(ErrorInfo::Error, true, ErrorInfo::Exit1,
							  "Missing semicolon"));
	return;
}
