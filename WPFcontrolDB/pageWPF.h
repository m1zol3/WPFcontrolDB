#pragma once
#include "stdafx.h"
 
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Navigation;
using namespace System::Windows::Documents;
using namespace System::Threading;
using namespace System::Windows::Controls;
using namespace System::Windows::Media;
 
public ref class  DBPageEventArgs : EventArgs
{
public:
   // DBPageEventArgs();
    //DBPageEventArgs(bool Okay);

    property bool Okay;

};
public ref class pageWPF : public Grid {
private:
    Label ^firstname, ^lastname, ^labelText, ^date, ^status, ^teamPool,  ^teamSnooker, ^myLabel, ^ID;
    Button ^okayButton, ^cancelButton;
    List myList;
public:
 
   
    pageWPF();
    pageWPF(int height, int width);
    ScrollViewer ^ myScroll;
    Button ^ myButton;
    ComboBox ^ myCombo;
    ComboBoxItem ^aktiv, ^passiv, ^gast, ehemaliger;
    Label ^ CreateLabel( String ^text);
    Label ^ CreateLabelID(int column, int row, String ^text);
    Button ^CreateButton(int column, int row, String ^text);
    ComboBox ^CreateCombo(int column, int row, String ^text);
    ComboBoxItem ^CreateItem(String ^text);
    ListView ^myListView;
    ListView ^CreateListView(int setHeigh, int setWidth);
    ScrollViewer ^CreatScroll(int setWidth, int setHeigh);
    
  

                     
};

