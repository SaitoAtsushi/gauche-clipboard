/*
 * gauche_clipboard.c
 */
#include "gauche_clipboard.h"

void write_clipboard(const char* str)
{
    HGLOBAL hText;
    WCHAR *pText;

    int nc = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    if (nc == 0) {
        Scm_Error("Windows error %d on MultiByteToWideChar", GetLastError());
    }
    hText = GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE, 2*nc);
    pText = GlobalLock(hText);
    if(MultiByteToWideChar(CP_UTF8, 0, str, -1, pText, nc) == 0) {
        GlobalUnlock(hText);
        Scm_Error("Windows error %d on MultiByteToWideChar", GetLastError());
    }
    GlobalUnlock(hText);

    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_UNICODETEXT, hText);
    CloseClipboard();
}

ScmObj read_clipboard(void)
{
    HANDLE hText;
    char *pText;
    ScmObj result;

    OpenClipboard(NULL);

    hText = GetClipboardData(CF_TEXT);
    if(hText == NULL) result = SCM_FALSE;
    else {
        pText = GlobalLock(hText);
        result = SCM_MAKE_STR_COPYING(pText);
        GlobalUnlock(hText);
       }
    CloseClipboard();
    return result;
}

/*
 * Module initialization function.
 */
extern void Scm_Init_gauche_clipboardlib(ScmModule*);

void Scm_Init_gauche_clipboard(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(gauche_clipboard);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE("clipboard", TRUE));

    /* Register stub-generated procedures */
    Scm_Init_gauche_clipboardlib(mod);
}
