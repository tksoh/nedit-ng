/*******************************************************************************
*                                                                              *
* smartIndent.h -- Nirvana Editor Smart Indent Header File                     *
*                                                                              *
* Copyright 2003 The NEdit Developers                                          *
*                                                                              *
* This is free software; you can redistribute it and/or modify it under the    *
* terms of the GNU General Public License as published by the Free Software    *
* Foundation; either version 2 of the License, or (at your option) any later   *
* version. In addition, you may distribute versions of this program linked to  *
* Motif or Open Motif. See README for details.                                 *
*                                                                              *
* This software is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for    *
* more details.                                                                *
*                                                                              *
* You should have received a copy of the GNU General Public License along with *
* software; if not, write to the Free Software Foundation, Inc., 59 Temple     *
* Place, Suite 330, Boston, MA  02111-1307 USA                                 *
*                                                                              *
* Nirvana Text Editor                                                          *
* July 31, 2001                                                                *
*                                                                              *
*******************************************************************************/

#ifndef X_SMART_INDENT_H_
#define X_SMART_INDENT_H_

#include "nedit.h"
#include "preferences.h"
#include <X11/Intrinsic.h>

class QString;
class SmartIndent;

Boolean InSmartIndentMacros(Document *window);
int LMHasSmartIndentMacros(const char *languageMode);
int LoadSmartIndentCommonStringEx(view::string_view string);
int LoadSmartIndentStringEx(view::string_view string);
int SmartIndentMacrosAvailable(char *languageMode);
QString  WriteSmartIndentCommonStringEx(void);
QString WriteSmartIndentStringEx(void);
void BeginSmartIndent(Document *window, int warn);
void EditCommonSmartIndentMacro(void);
void EditSmartIndentMacros(Document *window);
void EndSmartIndent(Document *window);
void RenameSmartIndentMacros(const char *oldName, const char *newName);
void SmartIndentCB(Widget w, XtPointer clientData, XtPointer callData);
void UpdateLangModeMenuSmartIndent(void);

SmartIndent *copyIndentSpec(SmartIndent *is);
void freeIndentSpec(SmartIndent *is);
SmartIndent *findIndentSpec(const char *modeName);

extern char *CommonMacros;
extern const char DefaultCommonMacros[];

#define N_DEFAULT_INDENT_SPECS 4
extern int NSmartIndentSpecs;
extern SmartIndent DefaultIndentSpecs[N_DEFAULT_INDENT_SPECS];
extern SmartIndent *SmartIndentSpecs[MAX_LANGUAGE_MODES];
#endif 
